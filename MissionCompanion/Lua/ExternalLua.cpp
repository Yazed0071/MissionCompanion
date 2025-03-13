#include "ExternalLua.h"
#include "LandingZone.h"
#include <MCLogger.h>
#include <regex>

std::string trigInnerZoneVector3Transform(const std::string& IsEnableOOB, const std::string& trigInnerZone)
{
    if (IsEnableOOB == "false") {
        return "nil";
    }

    std::string outputInnerZone;
    std::regex regex(R"(\{pos=\{([-?\d.]+),\s*([-?\d.]+),\s*([-?\d.]+)\},rotY=[-?\d.]+,\})"); // Regex for extracting coordinates
    std::smatch match;
    std::string transformed = trigInnerZone;
    bool firstLine = true;

    while (std::regex_search(transformed, match, regex)) {
        if (firstLine) {
            outputInnerZone += "Vector3(" + match[1].str() + ", " + match[2].str() + ", " + match[3].str() + "),\n";
            firstLine = false;
        }
        else {
            outputInnerZone += "                Vector3(" + match[1].str() + ", " + match[2].str() + ", " + match[3].str() + "),\n";
        }

        transformed = match.suffix().str();
    }

    return outputInnerZone;
}

std::string trigOuterZoneVector3Transform(const std::string& IsEnableOOB, const std::string& trigOuterZone)
{
    if (IsEnableOOB == "false") {
        return "nil";
    }

    std::string outputOuterZone;
    std::regex regex(R"(\{pos=\{([-?\d.]+),\s*([-?\d.]+),\s*([-?\d.]+)\},rotY=[-?\d.]+,\})"); // Regex for extracting coordinates
    std::smatch match;
    std::string transformed = trigOuterZone;
    bool firstLine = true;

    while (std::regex_search(transformed, match, regex)) {
        if (firstLine) {
            outputOuterZone += "    Vector3(" + match[1].str() + ", " + match[2].str() + ", " + match[3].str() + "),\n";
            firstLine = false;
        }
        else {
            outputOuterZone += "                    Vector3(" + match[1].str() + ", " + match[2].str() + ", " + match[3].str() + "),\n";
        }

        transformed = match.suffix().str();
    }

    return outputOuterZone;
}

std::string trigHotZoneVector3Transform(const std::string& IsEnableOOB, const std::string& trigHotZone)
{
    if (IsEnableOOB == "false") {
        return "nil";
    }

    std::string outputHotZone;
    std::regex regex(R"(\{pos=\{([-?\d.]+),\s*([-?\d.]+),\s*([-?\d.]+)\},rotY=[-?\d.]+,\})"); // Regex for extracting coordinates
    std::smatch match;
    std::string transformed = trigHotZone;
    bool firstLine = true;

    while (std::regex_search(transformed, match, regex)) {
        if (firstLine) {
            outputHotZone += "    Vector3(" + match[1].str() + ", " + match[2].str() + ", " + match[3].str() + "),\n";
            firstLine = false;
        }
        else {
            outputHotZone += "                    Vector3(" + match[1].str() + ", " + match[2].str() + ", " + match[3].str() + "),\n";
        }

        transformed = match.suffix().str();
    }

    return outputHotZone;
}

std::string MissionStartPointVector3Transform(const std::string& IsEnableOOB, const std::string& MissionStartPoint)
{
    std::regex regex(R"(\{pos=\{([-?\d.]+),\s*([-?\d.]+),\s*([-?\d.]+)\},rotY=[-?\d.]+,\})");
    std::smatch match;

    if (std::regex_search(MissionStartPoint, match, regex)) {
        return "Vector3(" + match[1].str() + ", " + match[2].str() + ", " + match[3].str() + ")";
    }

    return "nil"; // If no match is found, return "nil"
}

std::string TrimString(const std::string& str) {
    size_t first = str.find_first_not_of(" \n\r\t");
    if (first == std::string::npos) return "";  // If all spaces, return empty string
    size_t last = str.find_last_not_of(" \n\r\t");
    return str.substr(first, last - first + 1);
}

void WriteExternalLuaFile(const MissionData& mission, MCFileManager& MCFileManager)
{
    Logger::Info("Writing Lua file...");
    Logger::Info("FPK Name: %s", mission.GetFPKFileName().c_str());
    Logger::Info("Mission Code: %s", mission.GetMissionCode().c_str());
    Logger::Info("Location: %s", mission.GetLocation().c_str());
    Logger::Info("MissionOptions: %s", mission.GetMissionOptions().c_str());
    Logger::Info("Trig_innerZone: %s", mission.GetTrigInnerZone().c_str());
    Logger::Info("Trig_outerZone: %s", mission.GetTrigOuterZone().c_str());
    Logger::Info("Trig_hotZone: %s", mission.GetTrigHotZone().c_str());
    Logger::Info("MissionStartPoint: %s", mission.GetMissionStartPoint().c_str());
    Logger::Info("LandingZones: %s", mission.GetLandingZones().c_str());

    Logger::Debug("Exe At: %s", MCFileManager.GetExePath().c_str());

    std::string externalLuaPath = "\\Mission_Build\\" + mission.GetFPKFileName() + "\\GameDir\\mod\\missions";
    std::string fpkPath  = "\\Mission_Build\\" + mission.GetFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + "s" + mission.GetMissionCode() + "\\" + mission.GetFPKFileName() + "\\_fpk";
    std::string fpkdPath = "\\Mission_Build\\" + mission.GetFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + "s" + mission.GetMissionCode() + "\\" + mission.GetFPKFileName() + "\\_fpkd";
    MCFileManager.CreateFolder(externalLuaPath);
    MCFileManager.CreateFolder(fpkPath);
    MCFileManager.CreateFolder(fpkdPath);

    std::string externalLuaFilePath = MCFileManager.GetExePath() + externalLuaPath + "\\s"+ mission.GetMissionCode() + ".lua";
    std::ofstream luaFile(externalLuaFilePath);

    std::string addMissionPackPath = "/Assets/tpp/pack/mission2/custom_story/" + ("s" + mission.GetMissionCode()) + "/" + (mission.GetFPKFileName() + ".fpk");
    if (luaFile.is_open()) {
        luaFile << "local this = {}\n";
        luaFile << "--generated by Mission Companion!\n";
        luaFile << "--Thank you for using it!\n";
        luaFile << "--Created by Yazed0071 and heavily inspired from Side op companion https://www.nexusmods.com/metalgearsolidvtpp/mods/571 \n";
        luaFile << "    this.missionCode = " + mission.GetMissionCode() + "\n";
        luaFile << "    this.location = \"" + mission.GetLocationRealName(mission.GetLocation()) + "\"\n";
        luaFile << "    this.hideMission = " + mission.IsMissionHide() + "\n";
        luaFile << "\n";
        luaFile << "    this.packs = function(missionCode)\n";
        luaFile << "        --Common packs:\n";
        luaFile << "        TppPackList.AddLocationCommonScriptPack(missionCode)\n";
        luaFile << "        TppPackList.AddLocationCommonMissionAreaPack(missionCode)\n";
        luaFile << "\n";
        luaFile << "\n";
        luaFile << "        --Mission pack (has to be last):\n";
        luaFile << "        TppPackList.AddMissionPack\"" + addMissionPackPath + "\"\n";
        luaFile << "    end\n";
        luaFile << "\n";
        luaFile << "\n";
        luaFile << "this.enableOOB =" + mission.IsEnableOOB() + "\n";
        luaFile << "this.missionMapParams={\n";
        luaFile << "    --Normal mission area zones as they appear on the iDroid\n";
        luaFile << "    --The actual in-game check traps are in .trap files. (can be unpacked using TrapTool https://github.com/kapuragu/TrapTool)\n";
        luaFile << "    missionArea2 = {\n";
        luaFile << "        --Leaving the innerZone will only warn the player that they're leaving\n";
        luaFile << "        {\n";
        luaFile << "            name=\"trig_innerZone\",\n";
        luaFile << "            --.trap only:\n";
        luaFile << "            --minY=-213.1406,maxY=1299.037,\n";
        luaFile << "            vertices =\n";
        luaFile << "            {\n";
        luaFile << "                " + trigInnerZoneVector3Transform(mission.IsEnableOOB(), mission.GetTrigInnerZone()) +"\n" ;
        luaFile << "            }\n";
        luaFile << "        },\n";
        luaFile << "        --Leaving the outerZone will actually trigger the mission clear/abort\n";
        luaFile << "        --Commented out as it will be be displayed alongside the innerZone otherwise\n";
        luaFile << "        --[[\n";
        luaFile << "        {\n";
        luaFile << "	        name=\"trig_outerZone\",\n";
        luaFile << "            --.trap only:\n";
        luaFile << "		    --minY=-213.1406,maxY=1299.037,\n";
        luaFile << "            vertices =\n";
        luaFile << "            { \n";
        luaFile << "                " + trigOuterZoneVector3Transform(mission.IsEnableOOB(), mission.GetTrigOuterZone()) + "\n";
        luaFile << "            } \n";
        luaFile << "	    },\n";
        luaFile << "		]]\n";
        luaFile << "    },\n";
        luaFile << "	--Hot zone as it appears on the iDroid\n";
        luaFile << "    safetyArea2 = {\n";
        luaFile << "	    {\n";
        luaFile << "		    name=\"trig_hotZone\",\n";
        luaFile << "			--.trap only:\n";
        luaFile << "			--minY=-213.1406,maxY=1299.037,\n";
        luaFile << "			vertices =\n";
        luaFile << "				{\n";
        luaFile << "                " + trigHotZoneVector3Transform(mission.IsEnableOOB(), mission.GetTrigHotZone()) + "\n";
        luaFile << "				},\n";
        luaFile << "			},\n";
        luaFile << "	},\n";
        luaFile << "    missionStartPoint = {\n";
        luaFile << "        " + MissionStartPointVector3Transform(mission.IsEnableOOB(), mission.GetMissionStartPoint()) + "\n";
        luaFile << "	},\n";
        luaFile << "    heliLandPoint = {\n";
        luaFile << "        " + GetListLandingZone(TrimString(mission.GetLandingZones().c_str())) +"\n";  
        luaFile << "	},\n";
        luaFile << "    -- Sortie/mission prep screen feature flags\n";
        luaFile << "    heliSpaceFlags = {\n";
        luaFile << "        SkipMissionPreparetion = " + mission.IsNoSortiePrep() + ",   --No sortie prep, like vanilla Mother Base.\n";
        luaFile << "        NoBuddyMenuFromMissionPreparetion = " + mission.IsNoBuddySelectInSortie() + ",    -- No buddy select in the sortie\n";
        luaFile << "   	    NoVehicleMenuFromMissionPreparetion = " + mission.IsNoVehicleSelectInSortie() + ",    -- No vehicle select in the sortie\n";
        luaFile << "        DisableSelectSortieTimeFromMissionPreparetion = " + mission.IsOnlyASAPInSortie() + ",    -- Only ASAP as deployment time option\n";
        luaFile << "    },\n";
        luaFile << "}\n";
        luaFile << "\n";
        luaFile << "return this";

        luaFile.close();
        Logger::Info("Landing Zones Before Processing:\n%s", mission.GetLandingZones().c_str());
        Logger::Info("Lua file written successfully: %s", externalLuaFilePath.c_str());

        Logger::Info("Selected Landing Zones:\n%s", mission.GetLandingZones());
    }
    else {
        Logger::Critical("Failed to create Lua file!");
    } 
}