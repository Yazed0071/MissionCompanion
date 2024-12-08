#include "InitFiles.h"
#include "FilesCompiler.h"
#include "Fox2Info.h"   
#include "Trap.h"
#include <filesystem>
#define Logstd(Message) std::cerr << Message << std::endl;

void DeleteFolder(const std::filesystem::path& folderPath) {
    if (!std::filesystem::exists(folderPath)) {
        std::cerr << "Folder does not exist: " << folderPath << std::endl;
        return;
    }

    try {
        std::filesystem::remove_all(folderPath);
        std::cout << "Folder deleted successfully: " << folderPath << std::endl;
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error deleting folder: " << e.what() << std::endl;
    }
}

void CopyAssets(const std::string& sourcePath, const std::string& destinationPath) {
    try {
        std::filesystem::path source(sourcePath);
        std::filesystem::path destination(destinationPath);

        // Check if the source exists
        if (!std::filesystem::exists(source)) {
            std::cerr << "Source path does not exist: " << sourcePath << std::endl;
            return;
        }

        // Handle if source is a file
        if (std::filesystem::is_regular_file(source)) {
            if (!std::filesystem::exists(destination.parent_path())) {
                std::filesystem::create_directories(destination.parent_path());
            }
            std::filesystem::copy(source, destination, std::filesystem::copy_options::overwrite_existing);
            std::cout << "File copied successfully: " << sourcePath << " to " << destinationPath << std::endl;
            return;
        }

        // Handle if source is a directory
        if (std::filesystem::is_directory(source)) {
            if (!std::filesystem::exists(destination)) {
                std::filesystem::create_directories(destination);
            }

            // Copy the contents of the directory
            for (const auto& entry : std::filesystem::directory_iterator(source)) {
                std::filesystem::path dest = destination / entry.path().filename();
                if (entry.is_directory()) {
                    std::filesystem::copy(entry.path(), dest, std::filesystem::copy_options::recursive);
                }
                else if (entry.is_regular_file()) {
                    std::filesystem::copy(entry.path(), dest, std::filesystem::copy_options::overwrite_existing);
                }
            }
            std::cout << "Directory copied successfully: " << sourcePath << " to " << destinationPath << std::endl;
        }
    }
    catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error copying assets: " << e.what() << std::endl;
    }
}


void InitMainFiles(std::string rawTrig_innerZone, std::string rawTrig_outerZone, std::string rawTrig_hotZone, std::string MapLocation)
{
    std::string ToolPath = getExePath() + "\\MissionCompanion\\res\\ToolsAssets\\";
    std::string XmlFPKDFilesPath = getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + ("s" + getMissionCode()) + "\\" + (getFPKFileName() + "_fpkd");
    std::string XmlFPKFilesPath = getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + ("s" + getMissionCode()) + "\\" + (getFPKFileName() + "_fpk");


    

    CopyAssets(getExePath() + "\\MissionCompanion\\res\\Assets\\Support_Heli_FPKD", getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + ("s" + getMissionCode()) + "\\" + (getFPKFileName() + "_fpkd"));
    CopyAssets(getExePath() + "\\MissionCompanion\\res\\Assets\\Support_Heli_FPK", getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + ("s" + getMissionCode()) + "\\" + (getFPKFileName() + "_fpk"));

    CopyAssets(getExePath() + "\\MissionCompanion\\res\\Assets\\Player_Instance_FPKD", getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + ("s" + getMissionCode()) + "\\" + (getFPKFileName() + "_fpkd"));

    CopyAssets(getExePath() + "\\MissionCompanion\\res\\Assets\\Common_Radio_FPK", getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + ("s" + getMissionCode()) + "\\" + (getFPKFileName() + "_fpk"));
    CopyAssets(getExePath() + "\\MissionCompanion\\res\\Assets\\Common_Radio_FPKD", getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + ("s" + getMissionCode()) + "\\" + (getFPKFileName() + "_fpkd"));

    if (MapLocation == "AFGH")
    {
        Logstd("Location for block gen is: " + MapLocation)
        CopyAssets(getExePath() + "\\MissionCompanion\\res\\Assets\\Location_FPKD\\AFGH", getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + ("s" + getMissionCode()) + "\\" + (getFPKFileName() + "_fpkd"));
    }
    else if (MapLocation == "MAFR")
    {
        Logstd("Location for block gen is: " + MapLocation)
        CopyAssets(getExePath() + "\\MissionCompanion\\res\\Assets\\Location_FPKD\\MAFR", getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + ("s" + getMissionCode()) + "\\" + (getFPKFileName() + "_fpkd"));
    }

    GenerateFox2Xml(getExePath() + "\\MissionCompanion_Build\\" + getFPKFileName() + "\\Assets\\tpp\\pack\\mission2\\custom_story\\" + ("s" + getMissionCode()) + "\\" + (getFPKFileName() + "_fpkd") + "\\Assets\\tpp\\level\\mission2\\story\\" + ("s" + getMissionCode()) + ".fox2.xml", std::filesystem::path(getExePath()) / "MissionCompanion_Build" / getFPKFileName() / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + getMissionCode()) / (getFPKFileName() + "_fpkd") / "Assets" / "tpp" / "level" / "mission2" / "story");
    
    ConvertXmlTo(XmlFPKDFilesPath + "\\Assets\\tpp\\level\\mission2\\story\\" + ("s" + getMissionCode()) + ".fox2.xml", ToolPath + "FoxTool\\FoxTool.exe");
}
