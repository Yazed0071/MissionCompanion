#include "MC.h"

void MCTextField::SetText(TextBox^ textBox, String^ newText)
{
    if (textBox != nullptr)
    {
        textBox->Text = newText;
    }
}

std::string MCTextField::GetText(TextBox^ textBox)
{
    if (textBox != nullptr)
    {
        return msclr::interop::marshal_as<std::string>(textBox->Text);
    }
    return "";
}

