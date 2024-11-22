#ifndef EXTERNAL_LUA_H
#define EXTERNAL_LUA_H

#include <string>






void generateMission(System::String^ FPKFileName, System::String^ MissionCode, System::String^ MissionMapLocation);

void generatefolder(std::string FPKFileName, std::string MissionCode);

void generateExternalLua(std::string FPKFileName, std::string MissionCode, std::string MissionMapLocation);
#endif // EXTERNAL_LUA_H


