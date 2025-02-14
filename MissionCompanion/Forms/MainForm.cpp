#include "MainForm.h"
#include "ConsoleManager.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
    // Enable console only in Debug mode
    #ifdef _DEBUG 
       ConsoleManager::InitializeConsole();
    #endif

    // Windows Forms application initialization
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MissionCompanion::MainForm());

    #ifdef _DEBUG
        ConsoleManager::CloseConsole();
    #endif
}
