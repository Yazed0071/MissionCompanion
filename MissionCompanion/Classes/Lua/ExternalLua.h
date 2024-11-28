#ifndef EXTERNAL_LUA_H
#define EXTERNAL_LUA_H

#include <string>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <regex>

#include <MainForm.h>
#include <LandingZones.h>
#include <mission_main.h>



std::string getExePath();
std::string getFPKFileName();
std::filesystem::path getFPKFilePath();
std::filesystem::path getFPKDFilePath();
std::string getMissionCode();
std::string getMapLocation();

void deploymentLocation(System::String^ missionStartPointget);

void missionMapParams(System::String^ trig_innerZone, System::String^ trig_outerZone, System::String^ trig_hotZone);

void missionOptionsFlags(bool IsMissionHidden, bool IsEnableOOB, bool SkipMissionPreparationCheck, bool NoBuddyMenuCheck, bool NoVehicleMenuCheck, bool DisableSortieTimeCheck);

void generateMission(System::String^ FPKFileName, System::String^ MissionCode, System::String^ MissionMapLocation, System::String^ landingZones);

void generateFolder();

void generateExternalLua(System::String^ landingZones);
#endif // EXTERNAL_LUA_H