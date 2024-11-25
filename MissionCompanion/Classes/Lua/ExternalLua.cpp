#include "ExternalLua.h"


#define Logstd(Message) std::cout << Message << std::endl;

// Utility to convert System::String^ to std::string
std::string toStdString(System::String^ managedString) {
    return msclr::interop::marshal_as<std::string>(managedString);
}

// Globals for Mission Options and Zones
std::string MapLocation;
std::string isMissionHidden = "this.hideMission = false";
std::string isEnableOOB = "this.enableOOB = false --Enable out of bounds system (innerZone, outerZone, hotZone)";
std::string trig_innerZone = "nil";
std::string trig_outerZone = "nil";
std::string trig_hotZone = "nil";
std::string outputInnerZone;
std::string outputOuterZone;
std::string outputHotZone;

std::string missionStartPoint;
std::string outPutmissionStartPoint;

std::string SkipMissionPreparation = "false";
std::string NoBuddyMenuFromMissionPreparation = "false";
std::string NoVehicleMenuFromMissionPreparation = "false";
std::string DisableSelectSortieTimeFromMissionPreparation = "false";


bool IsEnableOOBVector = false;

// Create necessary folders
void generateFolder(const std::string& FPKFileName, const std::string& MissionCode) {
    char exePath[MAX_PATH];
    if (GetModuleFileNameA(NULL, exePath, MAX_PATH) == 0) {
        Logstd("Failed to get executable path.");
        return;
    }

    std::string exeDir = exePath;
    exeDir = exeDir.substr(0, exeDir.find_last_of("\\/"));

    std::filesystem::path gameDirPath = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileName / "GameDir" / "missions";
    std::filesystem::path assetsFPKPath = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileName / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + MissionCode) / (FPKFileName + "_fpk");
    std::filesystem::path assetsFPKDPath = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileName / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + MissionCode) / (FPKFileName + "_fpkd") / "Assets" / "tpp" / "level" / "mission2" / "story" / ("s" + MissionCode);

    if (std::filesystem::create_directories(gameDirPath)) {
        Logstd("GameDir folder created successfully.");
    }
    else {
        Logstd("GameDir folder already exists or failed to create.");
    }

    if (std::filesystem::create_directories(assetsFPKPath) && std::filesystem::create_directories(assetsFPKDPath)) {
        Logstd("Assets folders created successfully.");
    }
    else {
        Logstd("Assets folders already exist or failed to create.");
    }
}

void deploymentLocation(System::String^ missionStartPointget)
{

    outPutmissionStartPoint = "";
    // Regular expression to extract `pos={...}` values
    std::regex regex(R"(\{pos=\{([^}]+)\})");
    std::smatch match;

    // Lambda to transform each zone
    auto StartPoint = [&regex, &match](const std::string& zoneStr, std::string& output) {
        std::string transformed = zoneStr;
        while (std::regex_search(transformed, match, regex)) {
            output += "            point = Vector3(" + match[1].str() + "),";
            transformed = match.suffix().str(); // Process remaining string
        }
    };

    StartPoint(toStdString(missionStartPointget), outPutmissionStartPoint);

    Logstd("missionStartPoint:\n" + outPutmissionStartPoint);
}

// Handle mission map zones
void missionMapParams(System::String^ trigInnerZone, System::String^ trigOuterZone, System::String^ trigHotZone) {
    outputInnerZone = "";
    outputOuterZone = "";
    outputHotZone = "";
    if (!IsEnableOOBVector) {
        outputInnerZone = "                    nil";
        outputOuterZone = "                    nil";
        outputHotZone = "                    nil";
        return;
    }

    // Regular expression to extract `pos={...}` values
    std::regex regex(R"(\{pos=\{([^}]+)\})");
    std::smatch match;

    // Lambda to transform each zone
    auto transformZone = [&regex, &match](const std::string& zoneStr, std::string& output) {
        std::string transformed = zoneStr;
        while (std::regex_search(transformed, match, regex)) {
            output += "                    Vector3(" + match[1].str() + "),\n";
            transformed = match.suffix().str(); // Process remaining string
        }
        };

    // Process each zone string
    transformZone(toStdString(trigInnerZone), outputInnerZone);
    transformZone(toStdString(trigOuterZone), outputOuterZone);
    transformZone(toStdString(trigHotZone), outputHotZone);

    // Logstd results
    Logstd("Inner Zone:\n" + outputInnerZone);
    Logstd("Outer Zone:\n" + outputOuterZone);
    Logstd("Hot Zone:\n" + outputHotZone);
}

// Set mission options based on user input
void missionOptionsFlags(bool IsMissionHidden, bool IsEnableOOB, bool SkipMissionPreparationCheck, bool NoBuddyMenuCheck, bool NoVehicleMenuCheck, bool DisableSortieTimeCheck) {
    isMissionHidden = IsMissionHidden ? "this.hideMission = true" : "this.hideMission = false";
    isEnableOOB = IsEnableOOB ? "this.enableOOB = true --Enable out of bounds system (innerZone, outerZone, hotZone)" : "this.enableOOB = false";
    IsEnableOOBVector = IsEnableOOB;

    SkipMissionPreparation = SkipMissionPreparationCheck ? "true" : "false";
    NoBuddyMenuFromMissionPreparation = NoBuddyMenuCheck ? "true" : "false";
    NoVehicleMenuFromMissionPreparation = NoVehicleMenuCheck ? "true" : "false";
    DisableSelectSortieTimeFromMissionPreparation = DisableSortieTimeCheck ? "true" : "false";
}

// Generate the Lua file
void generateExternalLua(const std::string& FPKFileName, const std::string& MissionCode, const std::string& MissionMapLocation, System::String^ landingZones) {
    MapLocation = (MissionMapLocation == "Afghanistan") ? "AFGH"  : (MissionMapLocation == "Africa")  ? "MAFR"  : "";
    if (MapLocation.empty()) {
        Logstd("Invalid MissionMapLocation.");
        return;
    }

    char exePath[MAX_PATH];
    if (GetModuleFileNameA(NULL, exePath, MAX_PATH) == 0) {
        Logstd("Failed to get executable path.");
        return;
    }

    std::string exeDir = exePath;
    exeDir = exeDir.substr(0, exeDir.find_last_of("\\/"));
    std::filesystem::path luaFilePath = std::filesystem::path(exeDir) / "MissionCompanion_Build" / FPKFileName / "GameDir" / "missions" / (MissionCode + "_" + MapLocation + ".lua");

    if (std::filesystem::exists(luaFilePath)) {
        if (std::filesystem::remove(luaFilePath)) {
            Logstd("Existing Lua file deleted.");
        }
        else {
            Logstd("Failed to delete existing Lua file.");
            return;
        }
    }

    std::ofstream luaFile(luaFilePath.string());
    if (!luaFile.is_open()) {
        Logstd("Failed to create Lua file.");
        return;
    }
    
    

    std::string LandingZonesStr = toStdString(landingZones);
    std::string addMissionPackPath = "/Assets/tpp/pack/mission2/custom_story/" + ("s" + MissionCode) + "/" + (FPKFileName + ".fpk");
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
    luaFile << "        TppPackList.AddMissionPack\"" << addMissionPackPath << "\"\n";
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
    luaFile << "" << outputInnerZone << "\n"; // vertices
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
    luaFile << "" << outputOuterZone << "\n"; // vertices
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
    luaFile << "" << outputHotZone << "\n"; // vertices;
    luaFile << "				},\n";
    luaFile << "			},\n";
    luaFile << "		},\n";
    luaFile << "        missionStartPoint = {\n";
    luaFile << "" << outPutmissionStartPoint << "\n"; // vertices;
    luaFile << "		},\n";
    luaFile << "        heliLandPoint = {\n";
    luaFile << "    		" << GetListLandingZone(LandingZonesStr) << "\n"; // vertices;
    luaFile << "		},\n";
    luaFile << "        -- Sortie/mission prep screen feature flags\n";
    luaFile << "        heliSpaceFlags = {\n";
    luaFile << "    		SkipMissionPreparetion = " << SkipMissionPreparation << ",   --No sortie prep, like vanilla Mother Base.\n";
    luaFile << "    		NoBuddyMenuFromMissionPreparetion = " << NoBuddyMenuFromMissionPreparation << ",    -- No buddy select in the sortie\n";
    luaFile << "   			NoVehicleMenuFromMissionPreparetion = " << NoVehicleMenuFromMissionPreparation << ",    -- No vehicle select in the sortie\n";
    luaFile << "    		DisableSelectSortieTimeFromMissionPreparetion = " << DisableSelectSortieTimeFromMissionPreparation << ",    -- Only ASAP as deployment time option\n";
    luaFile << "  		},\n";
    luaFile << "    }\n";
    luaFile << "\n";
    luaFile << "\n";
    luaFile << "return this\n";

    luaFile.close();
    #ifdef _DEBUG
        Logstd("Lua file generated successfully: " + luaFilePath.string());
    #endif // _DEBUG

    System::Windows::Forms::MessageBox::Show(L"Build completed!", L"Message");
}

// Main function to generate mission
void generateMission(System::String^ FPKFileName, System::String^ MissionCode, System::String^ MissionMapLocation, System::String^ landingZones) {
    std::string FPKFileNameStr = toStdString(FPKFileName);
    std::string MissionCodeStr = toStdString(MissionCode);
    std::string MissionMapLocationStr = toStdString(MissionMapLocation);
    
    generateFolder(FPKFileNameStr, MissionCodeStr);
    generateExternalLua(FPKFileNameStr, MissionCodeStr, MissionMapLocationStr, landingZones);
}
