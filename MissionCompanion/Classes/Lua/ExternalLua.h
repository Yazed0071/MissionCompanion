#ifndef EXTERNAL_LUA_H
#define EXTERNAL_LUA_H

#include <string>



void MissionOptionsFlags(bool IsMissionHidden, bool IsEnableOOB, bool SkipMissionPreparetionCheck, bool NoBuddyMenuFromMissionPreparetionCheck, bool NoVehicleMenuFromMissionPreparetionCheck, bool DisableSelectSortieTimeFromMissionPreparetionCheck);

void generateMission(System::String^ FPKFileName, System::String^ MissionCode, System::String^ MissionMapLocation);

void generatefolder(std::string FPKFileName, std::string MissionCode);

void generateExternalLua(std::string FPKFileName, std::string MissionCode, std::string MissionMapLocation);
#endif // EXTERNAL_LUA_H


