#pragma once
#include <string>
#include <filesystem>
void InitMainFiles(std::string rawTrig_innerZone, std::string rawTrig_outerZone, std::string rawTrig_hotZone, std::string MapLocation);

void CopyAssets(const std::string& sourcePath, const std::string& destinationPath);

void DeleteFolder(const std::filesystem::path& folderPath);