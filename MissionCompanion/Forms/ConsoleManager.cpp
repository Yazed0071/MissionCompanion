#include <Windows.h>
#include <iostream>
#include "ConsoleManager.h"

// Only include console functionality in Debug mode
#ifdef _DEBUG

void ConsoleManager::InitializeConsole() {
    if (AllocConsole()) {
        FILE* fp;
        freopen_s(&fp, "CONOUT$", "w", stdout);
        freopen_s(&fp, "CONOUT$", "w", stderr);
        freopen_s(&fp, "CONIN$", "r", stdin);
        std::cout << "Console initialized successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to initialize console!" << std::endl;
    }
}

void ConsoleManager::CloseConsole() {
    FreeConsole();
}

#else

void ConsoleManager::InitializeConsole() {
    // Do nothing in Release mode
}

void ConsoleManager::CloseConsole() {
    // Do nothing in Release mode
}

#endif // _DEBUG
