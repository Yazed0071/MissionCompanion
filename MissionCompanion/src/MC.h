#pragma once

#include <string>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;

#include <fstream>

class MCTextField
{
public:
    static void SetText(TextBox^ textBox, String^ newText);
    static std::string GetText(TextBox^ textBox);
    static std::string GetText(ComboBox^ comboBox);
};

class MCFileManager
{
public:
    std::string GetExePath();
    bool CreateFolder(const std::string& folderPath);
    bool CheckAndDeleteFolder(const std::string& folderPath);
};
