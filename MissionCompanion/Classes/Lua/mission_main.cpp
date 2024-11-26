#include "mission_main.h"

#define Logstd(Message) std::cout << Message << std::endl;

void WriteMission_MainScrip()
{
    std::filesystem::path missionMainLuaFolderPath = std::filesystem::path(getExePath()) / "MissionCompanion_Build" / getFPKFileName() / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + getMissionCode()) / (getFPKFileName() + "_fpkd") / "Assets" / "tpp" / "script" / "mission";

    if (std::filesystem::create_directories(missionMainLuaFolderPath)) {
        Logstd("main mission path folder created successfully.");
    }
    else {
        Logstd("main mission path folder already exists or failed to create.");
    }


    std::filesystem::path missionMainLuaFile = std::filesystem::path(getExePath()) / "MissionCompanion_Build" / getFPKFileName() / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + getMissionCode()) / (getFPKFileName() + "_fpkd") / "Assets" / "tpp" / "script" / "mission" / "mission_main.lua";

    if (std::filesystem::exists(missionMainLuaFile)) {
        if (std::filesystem::remove(missionMainLuaFile)) {
            Logstd("Existing mission_main Lua File file deleted.");
        }
        else {
            Logstd("Failed to delete existing mission_main Lua File file.");
            return;
        }
    }

    std::ofstream writeMissionMainLuaFile(missionMainLuaFile.string());
    if (!writeMissionMainLuaFile.is_open()) {
        Logstd("Failed to create mission_main Lua File file.");
        return;
    }

    // Write Lua content
    writeMissionMainLuaFile << "local this = {}\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "local MainOnAllocate	= TppMain.OnAllocate\n";
    writeMissionMainLuaFile << "local MainOnInitialize	= TppMain.OnInitialize\n";
    writeMissionMainLuaFile << "local MainOnReload		= TppMain.OnReload\n";
    writeMissionMainLuaFile << "local MainOnUpdate 		= TppMain.OnUpdate\n";
    writeMissionMainLuaFile << "local MainOnChangeSVars	= TppMain.OnChangeSVars\n";
    writeMissionMainLuaFile << "local MainOnMessage		= TppMain.OnMessage\n";
    writeMissionMainLuaFile << "local MainOnTerminate	= TppMain.OnTerminate\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "this.OnAllocate = function(subScripts)\n";
    writeMissionMainLuaFile << "     return MainOnAllocate(subScripts)\n";
    writeMissionMainLuaFile << "end\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "this.OnInitialize = function(subScripts)\n";
    writeMissionMainLuaFile << "     return MainOnInitialize(subScripts)\n";
    writeMissionMainLuaFile << "end\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "this.OnReload = function(subScripts)\n";
    writeMissionMainLuaFile << "     return MainOnReload(subScripts)\n";
    writeMissionMainLuaFile << "end\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << " this.OnUpdate = function(subScripts)\n";
    writeMissionMainLuaFile << "     return MainOnUpdate(subScripts)\n";
    writeMissionMainLuaFile << "end\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "this.OnChangeSVars = function(subScripts, varName, key)\n";
    writeMissionMainLuaFile << "     return MainOnChangeSVars(subScripts, varName, key)\n";
    writeMissionMainLuaFile << "end\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "this.OnMessage = function(subScripts, sender, messageId, arg0, arg1, arg2, arg3)\n";
    writeMissionMainLuaFile << "     return MainOnMessage(subScripts, sender, messageId, arg0, arg1, arg2, arg3)\n";
    writeMissionMainLuaFile << "end\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "this.OnTerminate = function(subScripts)\n";
    writeMissionMainLuaFile << "     return MainOnTerminate(subScripts)\n";
    writeMissionMainLuaFile << "end\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "\n";
    writeMissionMainLuaFile << "return this";

    writeMissionMainLuaFile.close();

    #ifdef _DEBUG
    Logstd("mission_main lua file generated successfully: " + missionMainLuaFolderPath.string());
    #endif // _DEBUG
}