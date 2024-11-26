#ifndef AUTOMATEDFILEPROCESSOR_H
#define AUTOMATEDFILEPROCESSOR_H

#include <filesystem>
#include <ExternalLua.h>

static void ProcessFile(std::string& fileName, std::string& fileExtension, const std::filesystem::path& inputFilePath, const std::filesystem::path& externalExePath, const std::filesystem::path& outputDir);
void Fox2Container(std::filesystem::path& agr0);


#endif // AUTOMATEDFILEPROCESSOR_H
