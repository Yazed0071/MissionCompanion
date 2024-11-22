#include "MainForm.h"
#include "ConsoleManager.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
    #ifdef _DEBUG
    // Enable console only in Debug mode
    ConsoleManager::InitializeConsole();
    #endif

    // Windows Forms application initialization
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MissionCompanion::MainForm());

    #ifdef _DEBUG
    // Close console only in Debug mode
    ConsoleManager::CloseConsole();
    #endif
}
