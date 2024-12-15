#include "LandingZones.h"
#include "RouteInfo.h"
#include <msxml.h>
#include <tinyxml2.h>
#include <filesystem>
#include <ExternalLua.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <FilesCompiler.h>

#define Logstd(Message) std::cout << Message << std::endl;


void FilterRoutes() {
    using namespace tinyxml2;

    // Determine input XML based on location
    std::string XmlPath;
    if (getMapLocation() == "Afghanistan") {
        XmlPath = getExePath() + "\\MissionCompanion\\res\\Assets\\routes\\afgh\\Combined\\f30010.frt.xml";
    }
    else if (getMapLocation() == "Africa") {
        XmlPath = getExePath() + "\\MissionCompanion\\res\\Assets\\routes\\mafr\\Combined\\f30020.frt.xml";
    }
    else {
        Logstd("Error: Unknown map location.");
        return;
    }

    const std::string outputXmlPath = getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() +
        "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + "s" + getMissionCode() +
        "\\" + getFPKFileName() + "_fpk\\Assets\\tpp\\pack\\mission2\\s" + getMissionCode() + ".frt.xml";

    // Create output folder if necessary
    const std::filesystem::path outputFolder = std::filesystem::path(outputXmlPath).parent_path();
    if (!std::filesystem::exists(outputFolder) && !std::filesystem::create_directories(outputFolder)) {
        Logstd("Error creating output folder: " + outputFolder.string());
        return;
    }

    // Load input XML
    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(XmlPath.c_str()) != XML_SUCCESS) {
        Logstd("Error: Failed to load input XML file: " + XmlPath);
        return;
    }

    // Prepare new document
    tinyxml2::XMLDocument newDoc;
    XMLDeclaration* decl = newDoc.NewDeclaration("xml version=\"1.0\" encoding=\"utf-8\"");
    newDoc.InsertFirstChild(decl);
    XMLElement* routeSet = newDoc.NewElement("routeSet");
    newDoc.InsertEndChild(routeSet);

    // Filter routes
    XMLElement* root = doc.FirstChildElement("routeSet");
    if (!root) {
        Logstd("Error: Missing <routeSet> in input XML.");
        return;
    }

    bool anyMatchFound = false;

    for (XMLElement* route = root->FirstChildElement("route"); route; route = route->NextSiblingElement("route")) {
        const char* id = route->Attribute("id");
        if (!id) continue;

        // Check if any user input matches a substring of the route ID
        for (const auto& checkedLZ : getCheckedLZsVector()) {
            if (std::string(id).find(checkedLZ) != std::string::npos) {
                routeSet->InsertEndChild(route->DeepClone(&newDoc));
                Logstd("Match found for route ID: " + std::string(id));
                anyMatchFound = true;
                break; // Break inner loop; move to next route
            }
        }
    }

    if (!anyMatchFound) {
        Logstd("No matches found for any route IDs.");
    }

    // Save output XML
    if (newDoc.SaveFile(outputXmlPath.c_str()) == XML_SUCCESS) {
        Logstd("Filtered routes saved to: " + outputXmlPath);
    }
    else {
        Logstd("Error saving filtered routes to: " + outputXmlPath);
    }

    ConvertXmlTo(outputXmlPath, getExePath() + "\\MissionCompanion\\res\\ToolsAssets\\RouteSetTool\\RouteSetTool.exe");
}