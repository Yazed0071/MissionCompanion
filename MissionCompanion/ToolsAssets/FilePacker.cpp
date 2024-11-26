#include "FilePacker.h"
#include <iostream>
#include <filesystem>
#include <process.h> // For _spawnl

void ProcessFile(std::string& fileName, std::string& fileExtension, const std::filesystem::path& inputFilePath, const std::filesystem::path& externalExePath, const std::filesystem::path& outputDir) {
    if (!std::filesystem::exists(inputFilePath)) {
        std::cerr << "Input file does not exist: " << inputFilePath << std::endl;
        return;
    }

    if (!std::filesystem::exists(externalExePath)) {
        std::cerr << "External executable does not exist: " << externalExePath << std::endl;
        return;
    }

    std::filesystem::path outputFilePath = outputDir / (fileName + fileExtension);

    // Spawn the external executable
    int result = _spawnl(_P_WAIT, externalExePath.string().c_str(), externalExePath.string().c_str(), inputFilePath.string().c_str(), outputFilePath.string().c_str(), NULL);
    if (result == -1) {
        std::cerr << "Failed to run external executable: " << strerror(errno) << std::endl;
        return;
    }

    // Ensure the output directory exists
    std::filesystem::create_directories(outputDir);

    std::filesystem::path destination = outputDir / outputFilePath.filename();
    std::filesystem::rename(outputFilePath, destination);
    std::cout << "Processed file moved to: " << destination << std::endl;
}


#define Logstd(Message) std::cout << Message << std::endl;
void Fox2Container(std::filesystem::path& agr0)
{
    //std::filesystem::path(getExePath()) / "MissionCompanion_Build" / getFPKFileName() / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + getMissionCode()) / (getFPKFileName() + "_fpkd") / "Assets" / "tpp" / "level" / "mission2" / "story";
    std::filesystem::path createFox2FolderPath = agr0;
    std::filesystem::path foxToolExePath = std::filesystem::path(getExePath()) / "MissionCompanion_Build" / "ToolsAssets" / "Tools" / "FoxTool" / "FoxTool.exe";

    if (std::filesystem::create_directories(createFox2FolderPath)) {
        Logstd("main mission path folder created successfully.");
    }
    else {
        Logstd("main mission path folder already exists or failed to create.");
    }


    std::filesystem::path createFox2File = std::filesystem::path(getExePath()) / "MissionCompanion_Build" / getFPKFileName() / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + getMissionCode()) / (getFPKFileName() + "_fpkd") / "Assets" / "tpp" / "level" / "mission2" / "story" / "s13999.fox2.xml";

    if (std::filesystem::exists(createFox2File)) {
        if (std::filesystem::remove(createFox2File)) {
            Logstd("Existing mission_main Lua File file deleted.");
        }
        else {
            Logstd("Failed to delete existing mission_main Lua File file.");
            return;
        }
    }

    std::ofstream writeFox2File(createFox2File.string());
    if (!writeFox2File.is_open()) {
        Logstd("Failed to create mission_main Lua File file.");
        return;
    }

    // Write Lua content
    writeFox2File << "<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n";
    writeFox2File << "<fox formatVersion=\"2\" fileVersion=\"0\" originalVersion=\"Tue Nov 26 03:07 : 18 UTC + 03 : 00 2024\">\n";
    writeFox2File << "  <classes>\n";
    writeFox2File << "    <class name=\"Entity\" super="" version=\"2\" />\n";
    writeFox2File << "    <class name=\"Data\" super=\"Entity\" version=\"2\" />\n";
    writeFox2File << "  </classes>\n";
    writeFox2File << "  <entities />\n";
    writeFox2File << "</fox>";

    writeFox2File.close();
    //ProcessFile(createFox2File, foxToolExePath, createFox2FolderPath);
    #ifdef _DEBUG
    Logstd("main Fox2 lua file generated successfully at: " + createFox2FolderPath.string());
    #endif // _DEBUG
}