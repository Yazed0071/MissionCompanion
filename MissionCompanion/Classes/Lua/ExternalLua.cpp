#include "ExternalLua.h"
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include <filesystem>
#include <iostream>
#include <fstream>
#include "MainForm.h"

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

std::string MapLocation;
std::string isMissionHidden = "this.hideMission = false";
std::string isEnableOOB = "this.enableOOB = false --Enable out of bounds system (innerZone, outerZone, hotZone)";
std::string trig_innerZone = "nil";
std::string trig_outerZone = "nil";
std::string trig_hotZone = "nil";
std::string SkipMissionPreparetio = "false";
std::string NoBuddyMenuFromMissionPreparetion = "false";
std::string NoVehicleMenuFromMissionPreparetion = "false";
std::string DisableSelectSortieTimeFromMissionPreparetion = "false";

void generateExternalLua(std::string FPKFileName, std::string MissionCode, std::string MissionMapLocation)
{
    char exePath[MAX_PATH];

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

    #ifdef _DEBUG
        Log("==============================================================================================================");
        Log("==============================================================================================================");
        Log("this.missionCode = " << MissionCode);
        Log("this.location = " + MapLocation);
        Log(isMissionHidden);
        Log("TppPackList.AddMissionPack\"" << addMissionPackPath << "\"");
        Log(isEnableOOB);
        Log(trig_innerZone);
        Log(trig_outerZone);
        Log("SkipMissionPreparetion = " << SkipMissionPreparetio);
        Log("NoBuddyMenuFromMissionPreparetion = " << NoBuddyMenuFromMissionPreparetion);
        Log("NoVehicleMenuFromMissionPreparetion = " << NoVehicleMenuFromMissionPreparetion);
        Log("DisableSelectSortieTimeFromMissionPreparetion = " << DisableSelectSortieTimeFromMissionPreparetion);
        Log("==============================================================================================================");
        Log("==============================================================================================================");
    #endif // _DEBUG

    
    // Write Lua content
    luaFile << "local this = {}\n";
    luaFile << "--generated by Mission Companion!\n";
    luaFile << "--Thank you for using it!\n";
    luaFile << "--Created by Yazed0071 and inspired by Side op companion https://www.nexusmods.com/metalgearsolidvtpp/mods/571 \n";
    luaFile << "    this.missionCode = " << MissionCode << "\n"; // No quotes for an integer
    luaFile << "    this.location = \"" << MapLocation << "\"\n";
    luaFile << "    " << isMissionHidden << "\n";
    luaFile << "\n";
    luaFile << "    this.packs = function(missionCode)\n";
    luaFile << "        TppPackList.AddLocationCommonScriptPack(missionCode)\n";
    luaFile << "        TppPackList.AddLocationCommonMissionAreaPack(missionCode)\n";
    luaFile << "        TppPackList.AddLocationCommonMissionAreaPack(missionCode)\n";
    luaFile << "        TppPackList.AddMissionPack\""    << addMissionPackPath <<   "\"\n";
    luaFile << "    end\n";
    luaFile << "\n";
    luaFile << "\n";
    luaFile << "    " << isEnableOOB << "\n";
    luaFile << "    this.missionMapParams={\n";
    luaFile << "        --Normal mission area zones as they appear on the iDroid\n";
    luaFile << "        --The actual in-game check traps are in .trap files.\n";
    luaFile << "        missionArea2 = {\n";
    luaFile << "            --Leaving the innerZone will only warn the player that they're leaving\n";
    luaFile << "            {\n";
    luaFile << "                name=\"trig_innerZone\",\n";
    luaFile << "                --.trap only:\n";
    luaFile << "                --minY=-104.595,maxY=1299.037,\n";
    luaFile << "                vertices =\n";
    luaFile << "                {\n";
    luaFile << "                    " << trig_innerZone << "\n"; // vertices
    luaFile << "                }\n";
    luaFile << "            }\n";
    luaFile << "            --Leaving the outerZone will actually trigger the mission clear/abort\n";
    luaFile << "            --Commented out as it will be be displayed alongside the innerZone otherwise\n";
    luaFile << "            --[[\n";
    luaFile << "            {\n";
    luaFile << "				name=\"trig_outerZone\",\n";
    luaFile << "            	--.trap only:\n";
    luaFile << "				--minY=-213.1406,maxY=1299.037,\n";
    luaFile << "                vertices =\n";
    luaFile << "                { \n";
    luaFile << "                    " << trig_outerZone << "\n"; // vertices
    luaFile << "                } \n";
    luaFile << "			},\n";
    luaFile << "			]]\n";
    luaFile << "        },\n";
    luaFile << "		--Hot zone as it appears on the iDroid\n";
    luaFile << "        safetyArea2 = {\n";
    luaFile << "			{\n";
    luaFile << "				name=\"trig_hotZone\",\n";
    luaFile << "				--.trap only:\n";
    luaFile << "				--minY=-104.595,maxY=1299.037,\n";
    luaFile << "				vertices =\n";
    luaFile << "				{\n";
    luaFile << "				    " << trig_outerZone << "\n"; // vertices;
    luaFile << "				},\n";
    luaFile << "			},\n";
    luaFile << "		},\n";
    luaFile << "        missionStartPoint = {\n";
    luaFile << "	        " << trig_outerZone << "\n"; // vertices;
    luaFile << "		},\n";
    luaFile << "        heliLandPoint = {-- Sortie/mission prep screen feature flags\n";
    luaFile << "	        " << trig_outerZone << "\n"; // vertices;
    luaFile << "		},\n";
    luaFile << "        heliSpaceFlags = {\n";
    luaFile << "    		SkipMissionPreparetion = " << SkipMissionPreparetio << ",   --No sortie prep, like vanilla Mother Base.\n";
    luaFile << "    		NoBuddyMenuFromMissionPreparetion = " << NoBuddyMenuFromMissionPreparetion << ",    -- No buddy select in the sortie\n";
    luaFile << "   			NoVehicleMenuFromMissionPreparetion = " << NoVehicleMenuFromMissionPreparetion << ",    -- No vehicle select in the sortie\n";
    luaFile << "    		DisableSelectSortieTimeFromMissionPreparetion = " << DisableSelectSortieTimeFromMissionPreparetion << ",    -- Only ASAP as deployment time option\n";
    luaFile << "  		},\n";
    luaFile << "    }\n";
    luaFile << "\n";
    luaFile << "\n";
    luaFile << "return this\n";

    luaFile.close();
    Log("Lua file generated successfully! ");
}

void MissionOptionsFlags(bool IsMissionHidden, bool IsEnableOOB, bool SkipMissionPreparetionCheck, bool NoBuddyMenuFromMissionPreparetionCheck, bool NoVehicleMenuFromMissionPreparetionCheck, bool DisableSelectSortieTimeFromMissionPreparetionCheck)
{
 
    if (IsMissionHidden)
    {
        isMissionHidden = "this.hideMission = true";
    }
    else
    {
        isMissionHidden = "this.hideMission = false";
    }
    if (IsEnableOOB)
    {
        isEnableOOB = "this.enableOOB = true --Enable out of bounds system (innerZone, outerZone, hotZone)";
        trig_innerZone = "nil";
        trig_outerZone = "nil";
        trig_hotZone = "nil";
    }
    else
    {
        isEnableOOB = "this.enableOOB = false --Enable out of bounds system (innerZone, outerZone, hotZone)";
        trig_innerZone = "nil";
        trig_outerZone = "nil";
        trig_hotZone = "nil";
    }
    if (SkipMissionPreparetionCheck)
    {
        SkipMissionPreparetio = "true";
    }
    else
    {
        SkipMissionPreparetio = "false";
    }
    if (NoBuddyMenuFromMissionPreparetionCheck)
    {
        NoBuddyMenuFromMissionPreparetion = "true";
    }
    else 
    {
        NoBuddyMenuFromMissionPreparetion = "false";
    }
    if (NoVehicleMenuFromMissionPreparetionCheck)
    {
        NoVehicleMenuFromMissionPreparetion = "true";
    }
    else
    {
        NoVehicleMenuFromMissionPreparetion = "false";
    }
    if (DisableSelectSortieTimeFromMissionPreparetionCheck)
    {
        DisableSelectSortieTimeFromMissionPreparetion = "true";
    }
    else
    {
        DisableSelectSortieTimeFromMissionPreparetion = "false";
    }
}

void generateMission(System::String^ FPKFileName, System::String^ MissionCode, System::String^ MissionMapLocation) {
    // Convert managed strings to std::string
    std::string FPKFileNameStr = toStdString(FPKFileName);
    std::string MissionCodeStr = toStdString(MissionCode);
    std::string MissionMapLocationStr = toStdString(MissionMapLocation);

    generatefolder(FPKFileNameStr, MissionCodeStr);
    generateExternalLua(FPKFileNameStr, MissionCodeStr, MissionMapLocationStr);
}