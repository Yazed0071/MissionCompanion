#include "Fox2Info.h"
#include "ExternalLua.h"

#define Logstd(Message) std::cout << Message << std::endl

void Fox2Container(std::filesystem::path NewFox2XmlPath)
{
    std::filesystem::path Fox2FolderPath = std::filesystem::path(getExePath()) / "MissionCompanion_Build" / getFPKFileName() / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + getMissionCode()) / (getFPKFileName() + "_fpkd") / "Assets" / "tpp" / "script" / "mission";

    if (std::filesystem::create_directories(Fox2FolderPath)) {
        Logstd("Fox2 path folder created successfully.");
    }
    else {
        Logstd("Fox2 path folder already exists or failed to create.");
    }

    
    std::filesystem::path Fox2File = NewFox2XmlPath;

    if (std::filesystem::exists(Fox2File)) {
        if (std::filesystem::remove(Fox2File)) {
            Logstd("Existing Fox2 File file deleted.");
        }
        else {
            Logstd("Failed to delete existing Fox2 file.");
            return;
        }
    }

    std::ofstream writeFox2File(Fox2File.string());
    if (!writeFox2File.is_open()) {
        Logstd("Failed to create Fox2 file.");
        return;
    }

    // Write Fox2 file content
    writeFox2File << "<?xml version=\"1.0\" encoding=\"utf - 8\"?>\n";
    writeFox2File << "<fox formatVersion=\"2\" fileVersion=\"0\" originalVersion=\"Tue Nov 26 03:15 : 33 UTC + 03 : 00 1984\">\n";
    writeFox2File << "  <classes>\n";
    writeFox2File << "      <class name=\"Entity\" super=\"\" version=\"2\" />\n";
    writeFox2File << "      <class name=\"Data\" super=\"Entity\" version=\"2\" />\n";
    writeFox2File << "      " << "CLASEES LIST" << "\n";
    writeFox2File << "  </classes>\n";
    writeFox2File << "  <entities>\n";
    writeFox2File << "      " << "ENTITIES LIST" << "\n";
    writeFox2File << "  </entities>\n";
    writeFox2File << "</fox>\n";
    

    writeFox2File.close();

    #ifdef _DEBUG
    Logstd("Fox2 file generated successfully at : " + Fox2FolderPath.string());
    #endif // _DEBUG
}