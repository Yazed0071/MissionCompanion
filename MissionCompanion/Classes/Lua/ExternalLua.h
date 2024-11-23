#ifndef EXTERNAL_LUA_H
#define EXTERNAL_LUA_H

#include <string>

void deploymentLocation(System::String^ missionStartPointget, System::String^ heliLandPointget);

void missionMapParams(System::String^ trig_innerZone, System::String^ trig_outerZone, System::String^ trig_hotZone);

void missionOptionsFlags(bool IsMissionHidden, bool IsEnableOOB, bool SkipMissionPreparationCheck, bool NoBuddyMenuCheck, bool NoVehicleMenuCheck, bool DisableSortieTimeCheck);

void generateMission(System::String^ FPKFileName, System::String^ MissionCode, System::String^ MissionMapLocation);

void generateFolder(const std::string& FPKFileName, const std::string& MissionCode);

void generateExternalLua(const std::string& FPKFileName, const std::string& MissionCode, const std::string& MissionMapLocation);
#endif // EXTERNAL_LUA_H


