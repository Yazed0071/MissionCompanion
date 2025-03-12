#pragma once

#include <string>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Text;

class MCTextField
{
public:
    static void SetText(TextBox^ textBox, String^ newText);
    static std::string GetText(TextBox^ textBox);
    static std::string GetText(ComboBox^ comboBox);
};
