#pragma once
#include <string>
#include "MissionData.h"
#include "MC.h"

std::string trigInnerZoneVector3Transform(const std::string& IsEnableOOB, const std::string& trigInnerZone);
std::string trigOuterZoneVector3Transform(const std::string& IsEnableOOB, const std::string& trigOuterZone);
std::string trigHotZoneVector3Transform(const std::string& IsEnableOOB, const std::string& trigHotZone);
std::string MissionStartPointVector3Transform(const std::string& IsEnableOOB, const std::string& MissionStartPoint);

void WriteExternalLuaFile(const MissionData& mission, MCFileManager& MCFileManager);