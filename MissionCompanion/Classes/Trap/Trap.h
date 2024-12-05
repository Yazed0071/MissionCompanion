#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>

void GenerateTrapXml(const std::string& trig_innerZone, const std::string& trig_outerZone, const std::string& trig_hotZone,
    const std::string& filePath, const std::filesystem::path& GenerateTrapXmlFolderPath);