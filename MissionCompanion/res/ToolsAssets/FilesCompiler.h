#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <filesystem>

void ConvertXmlTo(const std::string& xmlFilePath, const std::string& exePath, int timeoutSeconds = 3);

#endif // FILEPROCESSOR_H
