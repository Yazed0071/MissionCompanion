#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <filesystem>

std::filesystem::path GetNewestFile(const std::filesystem::path& directory, const std::filesystem::path& excludeFile);
void ConvertXmlTo(const std::string& xmlFilePath, const std::string& exePath);

#endif // FILEPROCESSOR_H
