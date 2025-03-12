#ifndef MISSIONDATA_H
#define MISSIONDATA_H

#include <string>

class MissionData
{
public:
    // Mission details
    std::string FPKFileName;
    std::string MissionCode;
    std::string Location;
    std::string MissionOptions;

    // Trig zones
    std::string Trig_innerZone;
    std::string Trig_outerZone;
    std::string Trig_hotZone;

    // Mission Start Point & Landing Zones
    std::string MissionStartPoint;
    std::string LandingZones;

    // Constructor
    MissionData();
};

#endif // MISSIONDATA_H
