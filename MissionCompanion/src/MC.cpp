#include "MC.h"
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


string MCFileManager::GetExePath() const {
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    string fullPath(path);

    size_t pos = fullPath.find_last_of("\\/");
    std::string exeDir;
    if (pos == std::string::npos) {
        exeDir = fullPath;
    }
    else {
        exeDir = fullPath.substr(0, pos);
    }

    return exeDir;
}