#include "MC.h"
#include <MCLogger.h>
#include <filesystem>
using namespace std;
void MCTextField::SetText(TextBox^ textBox, String^ newText)
{
    if (textBox != nullptr)
    {
        textBox->Text = newText;
    }
}

string MCTextField::GetText(TextBox^ textBox)
{
    if (textBox != nullptr)
    {
        return msclr::interop::marshal_as<string>(textBox->Text);
    }
    return "";
}
string MCTextField::GetText(ComboBox^ comboBox) {
    return msclr::interop::marshal_as<string>(comboBox->Text);
}

string MCFileManager::GetExePath() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string path(buffer);
    size_t pos = path.find_last_of("\\/");
    return (pos == std::string::npos) ? path : path.substr(0, pos);
}

bool MCFileManager::CreateFolder(const std::string& folderPath) {
    std::string fullFolderPath = GetExePath() + "\\" + folderPath;

    if (std::filesystem::exists(fullFolderPath)) {
        return true;
    }

    return std::filesystem::create_directories(fullFolderPath);
}



bool MCFileManager::CheckAndDeleteFolder(const string& folderPath) {
    std::string fullFolderPath = GetExePath() + "\\" + folderPath;
    if (filesystem::exists(fullFolderPath)) {
        Logger::Info("Folder found: %s. Attempting to delete...", fullFolderPath.c_str());

        try {
            filesystem::remove_all(fullFolderPath);
            Logger::Info("Successfully deleted folder: %s", fullFolderPath.c_str());
            return true;
        }
        catch (const filesystem::filesystem_error& e) {
            Logger::Error("Failed to delete folder: %s. Error: %s", fullFolderPath.c_str(), e.what());
            return false;
        }
    }
    else {
        Logger::Info("Folder does not exist: %s", fullFolderPath.c_str());
        return false;
    }
}