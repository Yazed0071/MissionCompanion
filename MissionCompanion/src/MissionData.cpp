#include "MissionData.h"
#include "MainForm.h"
using namespace std;

// Define the static variables
string MissionData::FPKFileName = "";
string MissionData::MissionCode = "";
string MissionData::Location = "";
string MissionData::MissionOptions = "";
string MissionData::Trig_innerZone = "";
string MissionData::Trig_outerZone = "";
string MissionData::Trig_hotZone = "";
string MissionData::MissionStartPoint = "";
string MissionData::LandingZones = "";

string MissionData::GetFPKFileName()		const{ return FPKFileName; }
string MissionData::GetMissionCode()		const{ return MissionCode; }
string MissionData::GetLocation()			const{ return Location; }
string MissionData::GetLocationRealName(string location) const
{
    if (location == "Afghanistan")
    {
        location = "AFGH";
    }
    else if (location == "Africa")
    {
        location = "MAFR";
    }
    return location;
}



string MissionData::GetMissionOptions()	const{ return MissionOptions; }
string MissionData::IsMissionHide() const
{
    MissionCompanion::MainForm^ mainFormInstance = (MissionCompanion::MainForm^)Application::OpenForms["MainForm"];
    if (mainFormInstance->IsMissionHidden())
    {
        return "true";
    }
    else
    {
        return "false";
    }
}
string MissionData::IsEnableOOB() const
{
    MissionCompanion::MainForm^ mainFormInstance = (MissionCompanion::MainForm^)Application::OpenForms["MainForm"];
    if (mainFormInstance->IsEnableOOB())
    {
        return "true";
    }
    else
    {
        return "false";
    }
}
string MissionData::IsNoSortiePrep() const
{
    MissionCompanion::MainForm^ mainFormInstance = (MissionCompanion::MainForm^)Application::OpenForms["MainForm"];
    if (mainFormInstance->SkipMissionPreparetion())
    {
        return "true";
    }
    else
    {
        return "false";
    }
}
string MissionData::IsNoBuddySelectInSortie() const
{
    MissionCompanion::MainForm^ mainFormInstance = (MissionCompanion::MainForm^)Application::OpenForms["MainForm"];
    if (mainFormInstance->NoBuddyMenuFromMissionPreparetion())
    {
        return "true";
    }
    else
    {
        return "false";
    }
}
string MissionData::IsNoVehicleSelectInSortie() const
{
    MissionCompanion::MainForm^ mainFormInstance = (MissionCompanion::MainForm^)Application::OpenForms["MainForm"];
    if (mainFormInstance->NoVehicleMenuFromMissionPreparetion())
    {
        return "true";
    }
    else
    {
        return "false";
    }
}
string MissionData::IsOnlyASAPInSortie() const
{
    MissionCompanion::MainForm^ mainFormInstance = (MissionCompanion::MainForm^)Application::OpenForms["MainForm"];
    if (mainFormInstance->DisableSelectSortieTimeFromMissionPreparetion())
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

string MissionData::GetTrigInnerZone()		const{ return Trig_innerZone; }
string MissionData::GetTrigOuterZone()		const{ return Trig_outerZone; }
string MissionData::GetTrigHotZone()		const{ return Trig_hotZone; }
string MissionData::GetMissionStartPoint() const{ return MissionStartPoint; }
string MissionData::GetLandingZones()		const{ return LandingZones; }