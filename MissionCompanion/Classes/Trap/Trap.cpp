#include "Trap.h"
#include "ExternalLua.h"
#include <tinyxml2.h>
#include <regex>
#include <sstream>
#include <filesystem>
#include <iostream>

#define Logstd(Message) std::cout << Message << std::endl;

std::vector<std::tuple<float, float, float>> parseZonePoints(const std::string& zoneOutput) {
    std::vector<std::tuple<float, float, float>> points;
    std::regex pointRegex(R"(\{pos=\{([-+]?\d*\.?\d+),([-+]?\d*\.?\d+),([-+]?\d*\.?\d+)\})");
    std::smatch match;

    std::string remaining = zoneOutput;
    while (std::regex_search(remaining, match, pointRegex)) {
        float x = std::stof(match[1].str());
        float y = std::stof(match[2].str());
        float z = std::stof(match[3].str());
        points.emplace_back(x, y, z);
        remaining = match.suffix().str(); // Move to the next part of the string
    }

    return points;
}

void GenerateTrapXml(const std::string& trig_innerZone, const std::string& trig_outerZone, const std::string& trig_hotZone,
    const std::string& filePath, const std::filesystem::path& GenerateTrapXmlFolderPath) {
    if (std::filesystem::create_directories(GenerateTrapXmlFolderPath)) {
        Logstd("GenerateTrapXmlFolderPath path folder created successfully.");
    }
    else {
        Logstd("GenerateTrapXmlFolderPath path folder already exists or failed to create.");
    }

    using namespace tinyxml2;

    tinyxml2::XMLDocument trapDoc;

    XMLDeclaration* trapDecl = trapDoc.NewDeclaration("xml version=\"1.0\" encoding=\"utf-8\"");
    trapDoc.InsertFirstChild(trapDecl);

    XMLElement* trap = trapDoc.NewElement("trap");
    trap->SetAttribute("dataSet", "0");
    trapDoc.InsertEndChild(trap);

    auto addPoints = [&trapDoc](XMLElement* parent, const std::vector<std::tuple<float, float, float>>& points) {
        XMLElement* shape = trapDoc.NewElement("shape");
        shape->SetAttribute("yMinimum", "-174.7202");
        shape->SetAttribute("yMaximum", "1174.72");
        parent->InsertEndChild(shape);

        XMLElement* pointsElement = trapDoc.NewElement("points");
        shape->InsertEndChild(pointsElement);

        for (const auto& [x, y, z] : points) {
            XMLElement* point = trapDoc.NewElement("point");
            point->SetAttribute("x", x);
            point->SetAttribute("y", y);
            point->SetAttribute("z", z);
            point->SetAttribute("w", 0);
            pointsElement->InsertEndChild(point);
        }
        };

    auto addZoneEntry = [&trapDoc, &addPoints](XMLElement* trap, const std::string& name, const std::string& type,
        const std::string& tags, const std::vector<std::tuple<float, float, float>>& points) {
            XMLElement* entry = trapDoc.NewElement("entry");
            entry->SetAttribute("name", name.c_str());
            entry->SetAttribute("type", type.c_str());
            trap->InsertEndChild(entry);

            XMLElement* tagsElement = trapDoc.NewElement("tags");
            entry->InsertEndChild(tagsElement);

            std::istringstream tagStream(tags);
            std::string tagId;
            while (std::getline(tagStream, tagId, ',')) {
                XMLElement* tag = trapDoc.NewElement("tag");
                tag->SetAttribute("tagId", tagId.c_str());
                tagsElement->InsertEndChild(tag);
            }

            addPoints(entry, points);
        };

    addZoneEntry(trap, "trig_innerZone", "27", "12,25", parseZonePoints(trig_innerZone));
    addZoneEntry(trap, "trig_outerZone", "27", "13,25", parseZonePoints(trig_outerZone));
    addZoneEntry(trap, "trig_hotZone", "27", "14,25", parseZonePoints(trig_hotZone));

    if (trapDoc.SaveFile(filePath.c_str()) == XML_SUCCESS) {
        std::cout << "Trap XML file successfully generated: " << filePath << std::endl;
    }
    else {
        std::cerr << "Error generating XML file: " << filePath << std::endl;
    }
}
