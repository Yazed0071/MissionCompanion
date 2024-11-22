#include "ExternalLua.h"
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include <filesystem>
#include <iostream>


std::string toStdString(System::String^ managedString) {
	return msclr::interop::marshal_as<std::string>(managedString);
}

void createFilePath(System::String^ FPKFileName, System::String^ MissionCode) {
    // Convert managed strings to std::string
    std::string FPKFileNameStr = toStdString(FPKFileName);
    std::string MissionCodeStr = toStdString(MissionCode);
    char exePath[MAX_PATH];

    // Get the executable path
    if (GetModuleFileNameA(NULL, exePath, MAX_PATH) == 0) {
        System::Windows::Forms::MessageBox::Show(L"Failed to get executable path.", L"Message");
        return;
    }

    // Extract the directory of the executable
    std::string exeDir = exePath;
    size_t pos = exeDir.find_last_of("\\/");
    if (pos != std::string::npos) {
        exeDir = exeDir.substr(0, pos);
    }

    // Construct the folder path using filesystem
    std::filesystem::path folderPathGameDir = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileNameStr / "GameDir" / "missions";

    // ExternalLua
    if (std::filesystem::create_directories(folderPathGameDir)) {
        System::Windows::Forms::MessageBox::Show(L"Folder created successfully.", L"Message");
    }
    else if (std::filesystem::exists(folderPathGameDir)) {
        System::Windows::Forms::MessageBox::Show(L"Folder already exists.", L"Message");
    }
    else {
        System::Windows::Forms::MessageBox::Show(L"Failed to create folder.", L"Message");
        std::cerr << "Failed to create folder: " << folderPathGameDir << std::endl;
    }

    std::filesystem::path folderPathAssetsFPK = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileNameStr / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + MissionCodeStr) / (FPKFileNameStr + "_fpk");
    std::filesystem::path folderPathAssetsFPKD = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileNameStr / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + MissionCodeStr) / (FPKFileNameStr + "_fpkd");

    // Packs
    if (std::filesystem::create_directories(folderPathAssetsFPK) && std::filesystem::create_directories(folderPathAssetsFPKD)) {
        System::Windows::Forms::MessageBox::Show(L"Assets Folder created successfully.", L"Message");
    }
    else if (std::filesystem::exists(folderPathGameDir)) {
        System::Windows::Forms::MessageBox::Show(L"Assets Folder already exists.", L"Message");
    }
    else {
        System::Windows::Forms::MessageBox::Show(L"Failed to create Assets folder.", L"Message");
        std::cerr << "Failed to create folder: " << folderPathGameDir << std::endl;
    }
}

void DefineLocalThis()
{
	/*std::string fpkfolder = FPKFileNameStr + "_fpk";
	std::string fpkdfolder = FPKFileNameStr + "_fpkd";
	std::string folderPathAssets = exeDir + "\\MissionCompanion_Build\\" + FPKFileNameStr + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + "s" + MissionCodeStr + "\\" + fpkfolder;
	if (CreateDirectoryA(folderPathAssets.c_str(), NULL)) {
		System::Windows::Forms::MessageBox::Show(L"Folder created successfully.", L"Message");
	}
	else {
		DWORD error = GetLastError();
		if (error == ERROR_ALREADY_EXISTS) {
			System::Windows::Forms::MessageBox::Show(L"Folder already exists.", L"Message");
		}
		else {
			System::Windows::Forms::MessageBox::Show(L"Failed to create folder.", L"Message");
		}
	}*/
}	