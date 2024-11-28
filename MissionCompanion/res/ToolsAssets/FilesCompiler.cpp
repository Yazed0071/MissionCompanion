#include <windows.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <thread>
#include <chrono>


//TODO: doesn't work well with .frt files


// Function to get the newest file in the directory (excluding the XML file itself)
std::filesystem::path GetNewestFile(const std::filesystem::path& directory, const std::filesystem::path& excludeFile) {
    std::filesystem::path newestFile;
    std::filesystem::file_time_type newestTime;

    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path() != excludeFile) {
            auto currentFileTime = std::filesystem::last_write_time(entry);
            if (newestFile.empty() || currentFileTime > newestTime) {
                newestFile = entry.path();
                newestTime = currentFileTime;
            }
        }
    }

    return newestFile;
}

void ConvertXmlTo(const std::string& xmlFilePath, const std::string& exePath) {
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

    // Create the process
    if (!CreateProcess(
        NULL,                   // No module name (use command line)
        &wideCommand[0],        // Command line
        NULL,                   // Process handle not inheritable
        NULL,                   // Thread handle not inheritable
        FALSE,                  // Set handle inheritance to FALSE
        CREATE_NO_WINDOW,       // Do not create a window
        NULL,                   // Use parent's environment block
        NULL,                   // Use parent's starting directory
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

    if (exitCode == 0) {
        std::cout << "Conversion process completed successfully!" << std::endl;

        // Wait for the new file to be created (polling with a timeout)
        const int maxRetries = 100; // Adjust the retry limit as needed
        const int retryDelayMs = 100; // Delay between retries (milliseconds)
        int retries = 0;

        std::filesystem::path newestFile;

        while (retries < maxRetries) {
            newestFile = GetNewestFile(outputDirectory, xmlFile);
            if (!newestFile.empty() && newestFile.extension() != ".xml") {
                std::cout << "Generated file: " << newestFile << std::endl;

                // Delete the .xml file
                try {
                    std::filesystem::remove(xmlFile);
                    std::cout << "Deleted XML file: " << xmlFilePath << std::endl;
                }
                catch (const std::filesystem::filesystem_error& e) {
                    std::cerr << "Failed to delete XML file: " << e.what() << std::endl;
                }

                break;
            }

            // Wait before retrying
            std::this_thread::sleep_for(std::chrono::milliseconds(retryDelayMs));
            retries++;
        }

        if (retries == maxRetries) {
            std::cerr << "Timeout: Generated file was not detected within the expected time frame." << std::endl;
        }

    }
    else {
        std::cerr << "Error during conversion process. Exit code: " << exitCode << std::endl;
    }

    // Close process and thread handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}