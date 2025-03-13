#include "MissionData.h"


// Define the static variables
std::string MissionData::FPKFileName = "";
std::string MissionData::MissionCode = "";
std::string MissionData::Location = "";
std::string MissionData::MissionOptions = "";
std::string MissionData::Trig_innerZone = "";
std::string MissionData::Trig_outerZone = "";
std::string MissionData::Trig_hotZone = "";
std::string MissionData::MissionStartPoint = "";
std::string MissionData::LandingZones = "";

std::string MissionData::GetFPKFileName()		const{ return FPKFileName; }
std::string MissionData::GetMissionCode()		const{ return MissionCode; }
std::string MissionData::GetLocation()			const{ return Location; }
std::string MissionData::GetMissionOptions()	const{ return MissionOptions; }
std::string MissionData::GetTrigInnerZone()		const{ return Trig_innerZone; }
std::string MissionData::GetTrigOuterZone()		const{ return Trig_outerZone; }
std::string MissionData::GetTrigHotZone()		const{ return Trig_hotZone; }
std::string MissionData::GetMissionStartPoint() const{ return MissionStartPoint; }
std::string MissionData::GetLandingZones()		const{ return LandingZones; }