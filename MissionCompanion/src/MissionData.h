#ifndef MISSIONDATA_H
#define MISSIONDATA_H

#include <string>

class MissionData
{
public:
    // Mission details
    static std::string FPKFileName;
    static std::string MissionCode;
    static std::string Location;
    static std::string MissionOptions;

    // Trig zones
    static std::string Trig_innerZone;
    static std::string Trig_outerZone;
    static std::string Trig_hotZone;

    // Mission Start Point & Landing Zones
    static std::string MissionStartPoint;
    static std::string LandingZones;

    std::string GetFPKFileName()const;
    std::string GetMissionCode()const;
    std::string GetLocation()const;
    std::string GetLocationRealName(std::string location)const;
    std::string GetMissionOptions()const;
    std::string IsMissionHide()const;
    std::string IsEnableOOB()const;
    std::string IsNoSortiePrep()const;
    std::string IsNoBuddySelectInSortie()const;
    std::string IsNoVehicleSelectInSortie()const;
    std::string IsOnlyASAPInSortie()const;
    std::string GetTrigInnerZone()const;
    std::string GetTrigOuterZone()const;
    std::string GetTrigHotZone()const;
    std::string GetMissionStartPoint()const;
    std::string GetLandingZones()const;
};

#endif // MISSIONDATA_H
