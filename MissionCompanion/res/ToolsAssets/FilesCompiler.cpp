#include <windows.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <thread>
#include <chrono>

void ConvertXmlTo(const std::string& xmlFilePath, const std::string& exePath, int timeoutSeconds) {
    std::filesystem::path xmlFile(xmlFilePath);
    std::filesystem::path outputDirectory = xmlFile.parent_path();

    if (!std::filesystem::exists(xmlFile)) {
        std::cerr << "Error: The XML file does not exist: " << xmlFilePath << std::endl;
        return;
    }

    if (!std::filesystem::exists(exePath)) {
        std::cerr << "Error: The executable file does not exist: " << exePath << std::endl;
        return;
    }

    // Construct the command
    std::string command = "\"" + exePath + "\" \"" + xmlFilePath + "\"";

    // Convert the command to a wide string
    std::wstring wideCommand(command.begin(), command.end());

    // Prepare the structures for CreateProcess
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi = { 0 };

    // Set the working directory for the process
    std::wstring workingDirectory = outputDirectory.wstring();

    // Create the process
    if (!CreateProcess(
        NULL,                   // No module name (use command line)
        &wideCommand[0],        // Command line
        NULL,                   // Process handle not inheritable
        NULL,                   // Thread handle not inheritable
        FALSE,                  // Set handle inheritance to FALSE
        CREATE_NO_WINDOW,       // Do not create a window
        NULL,                   // Use parent's environment block
        workingDirectory.c_str(), // Set the working directory
        &si,                    // Pointer to STARTUPINFO structure
        &pi                     // Pointer to PROCESS_INFORMATION structure
    )) {
        std::cerr << "Failed to execute the command. Error code: " << GetLastError() << std::endl;
        return;
    }

    // Wait for the process to complete
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Check the exit code of the process
    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);

    if (exitCode != 0) {
        std::cerr << "Error during conversion process. Exit code: " << exitCode << std::endl;
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return;
    }

    std::cout << "Conversion process completed successfully!" << std::endl;

    // Poll for a new file in the directory
    auto startTime = std::chrono::steady_clock::now();
    std::filesystem::path newestFile;

    while (true) {
        // Look for the newest file that is not the original XML file
        for (const auto& entry : std::filesystem::directory_iterator(outputDirectory)) {
            if (entry.is_regular_file() && entry.path() != xmlFile) {
                auto currentFileTime = std::filesystem::last_write_time(entry);
                if (newestFile.empty() || currentFileTime > std::filesystem::last_write_time(newestFile)) {
                    newestFile = entry.path();
                }
            }
        }

        if (!newestFile.empty()) {
            std::cout << "Generated file: " << newestFile << std::endl;

            // Delete the original XML file
            try {
                std::filesystem::remove(xmlFile);
                std::cout << "Deleted XML file: " << xmlFilePath << std::endl;
            }
            catch (const std::filesystem::filesystem_error& e) {
                std::cerr << "Failed to delete XML file: " << e.what() << std::endl;
            }
            break;
        }

        // Check for timeout
        if (std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::steady_clock::now() - startTime).count() >= timeoutSeconds) {
            std::cerr << "Timeout: Generated file was not detected within the expected time frame." << std::endl;
            break;
        }

        // Wait before retrying
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
