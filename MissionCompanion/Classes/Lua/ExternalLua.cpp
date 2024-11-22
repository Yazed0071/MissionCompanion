#include "ExternalLua.h"
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include <filesystem>
#include <iostream>
#include <fstream>

#define Log(Message) std::cout << Message << std::endl;

std::string toStdString(System::String^ managedString) {
    return msclr::interop::marshal_as<std::string>(managedString);
}

void generatefolder(std::string FPKFileName, std::string MissionCode) {
    char exePath[MAX_PATH];

    // Get the executable path
    if (GetModuleFileNameA(NULL, exePath, MAX_PATH) == 0) {
        Log("Failed to get executable path.");
        return;
    }

    std::string exeDir = exePath;
    size_t pos = exeDir.find_last_of("\\/");
    if (pos != std::string::npos) {
        exeDir = exeDir.substr(0, pos);
    }

    std::filesystem::path folderPathGameDir = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileName / "GameDir" / "missions";

    // External Lua path
    if (std::filesystem::create_directories(folderPathGameDir)) {
        Log("Folder created successfully.");
    }
    else if (std::filesystem::exists(folderPathGameDir)) {
        Log("Folder already exists.");
    }
    else {
        Log("Failed to create folder.");
    }

    std::filesystem::path folderPathAssetsFPK = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileName / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + MissionCode) / (FPKFileName + "_fpk");
    std::filesystem::path folderPathAssetsFPKD = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileName / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + MissionCode) / (FPKFileName + "_fpkd");

    // Packs path
    if (std::filesystem::create_directories(folderPathAssetsFPK) && std::filesystem::create_directories(folderPathAssetsFPKD)) {
        Log("Assets Folder created successfully.");
    }
    else if (std::filesystem::exists(folderPathGameDir)) {
        Log("Assets Folder already exists.");
    }
    else {
        Log("Failed to create folder.");
    }
}

void generateExternalLua(std::string FPKFileName, std::string MissionCode, std::string MissionMapLocation) {
    char exePath[MAX_PATH];
    std::string MapLocation;

    if (MissionMapLocation == "Afghanistan")
    {
        MapLocation = "AFGH";
    }
    else if (MissionMapLocation == "Africa")
    {
        MapLocation = "MAFR";
    }

    if (GetModuleFileNameA(NULL, exePath, MAX_PATH) == 0) {
        Log("Failed to get executable path.");
        return;
    }

    std::string exeDir = exePath;
    size_t pos = exeDir.find_last_of("\\/");
    if (pos != std::string::npos) {
        exeDir = exeDir.substr(0, pos);
    }

    // Construct the Lua file path
    std::filesystem::path luaFilePath = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileName / "GameDir" / "missions" / (MissionCode + "_" + MapLocation + ".lua");

    // Create and write the Lua file
    std::ofstream luaFile(luaFilePath.string());
    if (!luaFile.is_open()) {
        Log("Failed to create Lua file.");
        return;
    }


    std::string addMissionPackPath = "/Assets/tpp/pack/mission2/custom_story/" + ("s" + MissionCode) + "/" + (FPKFileName + ".fpk");



    // Write Lua content
    luaFile << "local this = {}\n";
    luaFile << "--generated by Mission Companion!\n";
    luaFile << "--Thank you for using it!\n";
    luaFile << "--Created by Yazed0071 and inspired by Side op companion https://www.nexusmods.com/metalgearsolidvtpp/mods/571 \n";
    luaFile << "    this.missionCode = " << MissionCode << "\n"; // No quotes for an integer
    luaFile << "    this.location = \"" << MapLocation << "\"\n";
    luaFile << "    this.hideMission=false\n";
    luaFile << "\n";
    luaFile << "    this.packs = function(missionCode)\n";
    luaFile << "        TppPackList.AddLocationCommonScriptPack(missionCode)\n";
    luaFile << "        TppPackList.AddLocationCommonMissionAreaPack(missionCode)\n";
    luaFile << "        TppPackList.AddLocationCommonMissionAreaPack(missionCode)\n";
    luaFile << "        TppPackList.AddMissionPack\""    << addMissionPackPath <<   "\"\n";
    luaFile << "    end\n";
    luaFile << "\n";
    luaFile << "\n";
    luaFile << "return this\n";

    luaFile.close();
    Log("Lua file generated successfully! ");
}

void generateMission(System::String^ FPKFileName, System::String^ MissionCode, System::String^ MissionMapLocation) {
    // Convert managed strings to std::string
    std::string FPKFileNameStr = toStdString(FPKFileName);
    std::string MissionCodeStr = toStdString(MissionCode);
    std::string MissionMapLocationStr = toStdString(MissionMapLocation);

    generatefolder(FPKFileNameStr, MissionCodeStr);
    generateExternalLua(FPKFileNameStr, MissionCodeStr, MissionMapLocationStr);
}
