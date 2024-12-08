#include <windows.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <thread>
#include <chrono>

// Utility for logging
#define Log(Message) std::cout << Message << std::endl;

void ConvertXmlTo(const std::string& xmlFilePath, const std::string& exePath, int timeoutSeconds) {
    std::filesystem::path xmlFile(xmlFilePath);
    std::filesystem::path outputDirectory = xmlFile.parent_path();

    if (!std::filesystem::exists(xmlFile)) {
        Log("Error: The XML file does not exist: " + xmlFilePath);
        return;
    }

    if (!std::filesystem::exists(exePath)) {
        Log("Error: The executable file does not exist: " + exePath);
        return;
    }

    // Construct the command
    std::string command = "\"" + exePath + "\" \"" + xmlFilePath + "\"";
    Log("Executing command: " + command);

    // Convert the command to a wide string
    std::wstring wideCommand(command.begin(), command.end());

    // Prepare the structures for CreateProcess
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi = { 0 };

    if (!CreateProcess(
        NULL,                   // No module name (use command line)
        &wideCommand[0],        // Command line
        NULL,                   // Process handle not inheritable
        NULL,                   // Thread handle not inheritable
        FALSE,                  // Set handle inheritance to FALSE
        CREATE_NO_WINDOW,       // Do not create a window
        NULL,                   // Use parent's environment block
        outputDirectory.c_str(),// Working directory
        &si,                    // Pointer to STARTUPINFO structure
        &pi                     // Pointer to PROCESS_INFORMATION structure
    )) {
        Log("Failed to execute the command. Error code: " + std::to_string(GetLastError()));
        return;
    }

    // Wait for the process to complete
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Check the exit code of the process
    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);

    if (exitCode != 0) {
        Log("Error during conversion process. Exit code: " + std::to_string(exitCode));
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return;
    }

    Log("Conversion process completed successfully!");

    // Poll for a new file in the directory
    auto startTime = std::chrono::steady_clock::now();
    std::filesystem::path generatedFile;

    while (std::chrono::steady_clock::now() - startTime < std::chrono::seconds(timeoutSeconds)) {
        for (const auto& entry : std::filesystem::directory_iterator(outputDirectory)) {
            if (entry.is_regular_file() && entry.path() != xmlFile) {
                generatedFile = entry.path();
                break;
            }
        }
        if (!generatedFile.empty()) break;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    if (generatedFile.empty()) {
        Log("Timeout: Generated file was not detected within the expected time frame.");
    }
    else {
        Log("Generated file: " + generatedFile.string());
    }

    // Attempt to delete the original XML file
    try {
        std::filesystem::remove(xmlFile);
        Log("Deleted XML file: " + xmlFilePath);
    }
    catch (const std::filesystem::filesystem_error& e) {
        Log("Failed to delete XML file: " + std::string(e.what()));
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
