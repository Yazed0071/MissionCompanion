#include "ExternalLua.h"
#include <MCLogger.h>


void WriteExternalLuaFile(const MissionData& mission, MCFileManager& MCFileManager)
{
    Logger::Info("Writing Lua file...");
    Logger::Info("FPK Name: %s", mission.GetFPKFileName().c_str());
    Logger::Info("Mission Code: %s", mission.GetMissionCode().c_str());
    Logger::Info("Location: %s", mission.GetLocation().c_str());

    Logger::Debug("Exe At: %s", MCFileManager.GetExePath().c_str());
}