#include "ExternalLua.h"
#include <tinyxml2.h>

#define Logstd(Message) std::cout << Message << std::endl;


// Helper function for generating address in hex format
std::string GenerateHexAddress(uint32_t address) {
    std::ostringstream stream;
    stream << "0x" << std::uppercase << std::hex << address;
    return stream.str();
}

// Function to generate the XML dynamically
void GenerateFox2Xml(const std::string& filePath, std::filesystem::path GenerateFox2XmlFolderPath) {

    if (std::filesystem::create_directories(GenerateFox2XmlFolderPath)) {
        Logstd("GenerateFox2XmlFolderPath path folder created successfully.");
    }
    else {
        Logstd("GenerateFox2XmlFolderPath path folder already exists or failed to create.");
    }

    using namespace tinyxml2;

    tinyxml2::XMLDocument doc;

    XMLDeclaration* decl = doc.NewDeclaration("xml version=\"1.0\" encoding=\"utf-8\"");
    doc.InsertFirstChild(decl);

    XMLElement* fox = doc.NewElement("fox");
    fox->SetAttribute("formatVersion", "2");
    fox->SetAttribute("fileVersion", "0");
    fox->SetAttribute("originalVersion", "Sun Dec 01 11:16:01 UTC+03:00 2024");
    doc.InsertEndChild(fox);

    XMLElement* classes = doc.NewElement("classes");
    fox->InsertEndChild(classes);

    std::vector<std::tuple<std::string, std::string, int>> classList = {
        {"Entity", "", 2},
        {"Data", "Entity", 2},
        {"DataSet", "", 0},
        {"TppSimpleMissionData", "", 1},
        {"TexturePackLoadConditioner", "", 0}
    };

    for (const auto& [name, super, version] : classList) {
        XMLElement* classElement = doc.NewElement("class");
        classElement->SetAttribute("name", name.c_str());
        classElement->SetAttribute("super", super.c_str());
        classElement->SetAttribute("version", version);
        classes->InsertEndChild(classElement);
    }

    // <entities> section
    XMLElement* entities = doc.NewElement("entities");
    fox->InsertEndChild(entities);

    // DataSet Entity
    XMLElement* dataSetEntity = doc.NewElement("entity");
    dataSetEntity->SetAttribute("class", "DataSet");
    dataSetEntity->SetAttribute("classVersion", "0");
    dataSetEntity->SetAttribute("addr", "0x04D8FF20");
    dataSetEntity->SetAttribute("unknown1", "232");
    dataSetEntity->SetAttribute("unknown2", "1989014");
    entities->InsertEndChild(dataSetEntity);

    // DataSet staticProperties
    XMLElement* staticProperties = doc.NewElement("staticProperties");
    dataSetEntity->InsertEndChild(staticProperties);

    // <property name="name">
    XMLElement* nameProperty = doc.NewElement("property");
    nameProperty->SetAttribute("name", "name");
    nameProperty->SetAttribute("type", "String");
    nameProperty->SetAttribute("container", "StaticArray");
    nameProperty->SetAttribute("arraySize", "1");
    staticProperties->InsertEndChild(nameProperty);

    XMLElement* nameValue = doc.NewElement("value");
    nameProperty->InsertEndChild(nameValue);

    XMLElement* dataSetProperty = doc.NewElement("property");
    dataSetProperty->SetAttribute("name", "dataSet");
    dataSetProperty->SetAttribute("type", "EntityHandle");
    dataSetProperty->SetAttribute("container", "StaticArray");
    dataSetProperty->SetAttribute("arraySize", "1");
    staticProperties->InsertEndChild(dataSetProperty);

    XMLElement* dataSetValue = doc.NewElement("value");
    dataSetValue->SetText("0x00000000");
    dataSetProperty->InsertEndChild(dataSetValue);

    XMLElement* dataListProperty = doc.NewElement("property");
    dataListProperty->SetAttribute("name", "dataList");
    dataListProperty->SetAttribute("type", "EntityPtr");
    dataListProperty->SetAttribute("container", "StringMap");
    dataListProperty->SetAttribute("arraySize", "2");
    staticProperties->InsertEndChild(dataListProperty);

    XMLElement* missionDataValue = doc.NewElement("value");
    missionDataValue->SetAttribute("key", "mission_data");
    missionDataValue->SetText("0x053506A0");
    dataListProperty->InsertEndChild(missionDataValue);

    XMLElement* texturePackValue = doc.NewElement("value");
    texturePackValue->SetAttribute("key", "TexturePackLoadConditioner0000");
    texturePackValue->SetText("0x0535F5F0");
    dataListProperty->InsertEndChild(texturePackValue);

    dataSetEntity->InsertEndChild(doc.NewElement("dynamicProperties"));

    // TppSimpleMissionData Entity
    XMLElement* missionDataEntity = doc.NewElement("entity");
    missionDataEntity->SetAttribute("class", "TppSimpleMissionData");
    missionDataEntity->SetAttribute("classVersion", "1");
    missionDataEntity->SetAttribute("addr", "0x053506A0");
    missionDataEntity->SetAttribute("unknown1", "136");
    missionDataEntity->SetAttribute("unknown2", "1989016");
    entities->InsertEndChild(missionDataEntity);

    XMLElement* missionDataProperties = doc.NewElement("staticProperties");
    missionDataEntity->InsertEndChild(missionDataProperties);

    XMLElement* missionNameProperty = doc.NewElement("property");
    missionNameProperty->SetAttribute("name", "name");
    missionNameProperty->SetAttribute("type", "String");
    missionNameProperty->SetAttribute("container", "StaticArray");
    missionNameProperty->SetAttribute("arraySize", "1");
    missionDataProperties->InsertEndChild(missionNameProperty);

    XMLElement* missionNameValue = doc.NewElement("value");
    nameValue->SetText("mission_data");
    missionNameProperty->InsertEndChild(missionNameValue);

    XMLElement* missionDataSetProperty = doc.NewElement("property");
    missionDataSetProperty->SetAttribute("name", "dataSet");
    missionDataSetProperty->SetAttribute("type", "EntityHandle");
    missionDataSetProperty->SetAttribute("container", "StaticArray");
    missionDataSetProperty->SetAttribute("arraySize", "1");
    missionDataProperties->InsertEndChild(missionDataSetProperty);

    XMLElement* missionDataSetValue = doc.NewElement("value");
    missionDataSetValue->SetText("0x04D8FF20");
    missionDataSetProperty->InsertEndChild(missionDataSetValue);

    XMLElement* scriptProperty = doc.NewElement("property");
    scriptProperty->SetAttribute("name", "script");
    scriptProperty->SetAttribute("type", "FilePtr");
    scriptProperty->SetAttribute("container", "StaticArray");
    scriptProperty->SetAttribute("arraySize", "1");
    missionDataProperties->InsertEndChild(scriptProperty);

    XMLElement* scriptValue = doc.NewElement("value");
    scriptValue->SetText("/Assets/tpp/script/mission/mission_main.lua");
    scriptProperty->InsertEndChild(scriptValue);

    XMLElement* subScriptsProperty = doc.NewElement("property");
    subScriptsProperty->SetAttribute("name", "subScripts");
    subScriptsProperty->SetAttribute("type", "FilePtr");
    subScriptsProperty->SetAttribute("container", "StringMap");
    subScriptsProperty->SetAttribute("arraySize", "7");
    missionDataProperties->InsertEndChild(subScriptsProperty);

    std::vector<std::pair<std::string, std::string>> subScripts = {
        {"sequence", "/Assets/tpp/level/mission2/story/" + ("s" + getMissionCode() + "_sequence.lua")},
        {"enemy", "/Assets/tpp/level/mission2/story/" + ("s" + getMissionCode() + "_enemy.lua")},
        {"radio", "/Assets/tpp/level/mission2/story/" + ("s" + getMissionCode() + "_radio.lua")},
        {"demo", "/Assets/tpp/level/mission2/story/" + ("s" + getMissionCode() + "_demo.lua")},
        {"telop", "/Assets/tpp/level/mission2/story/" + ("s" + getMissionCode() + "_telop.lua")},
        {"sound", "/Assets/tpp/level/mission2/story/" + ("s" + getMissionCode() + "_sound.lua")},
        {"score", "/Assets/tpp/level/mission2/story/" + ("s" + getMissionCode() + "_score.lua")}
    };

    for (const auto& [key, value] : subScripts) {
        XMLElement* subScript = doc.NewElement("value");
        subScript->SetAttribute("key", key.c_str());
        subScript->SetText(value.c_str());
        subScriptsProperty->InsertEndChild(subScript);
    }

    missionDataEntity->InsertEndChild(doc.NewElement("dynamicProperties"));

    // TexturePackLoadConditioner Entity
    XMLElement* texturePackEntity = doc.NewElement("entity");
    texturePackEntity->SetAttribute("class", "TexturePackLoadConditioner");
    texturePackEntity->SetAttribute("classVersion", "0");
    texturePackEntity->SetAttribute("addr", "0x0535F5F0");
    texturePackEntity->SetAttribute("unknown1", "72");
    texturePackEntity->SetAttribute("unknown2", "0");
    entities->InsertEndChild(texturePackEntity);

    XMLElement* texturePackProperties = doc.NewElement("staticProperties");
    texturePackEntity->InsertEndChild(texturePackProperties);

    XMLElement* texturePackNameProperty = doc.NewElement("property");
    texturePackNameProperty->SetAttribute("name", "name");
    texturePackNameProperty->SetAttribute("type", "String");
    texturePackNameProperty->SetAttribute("container", "StaticArray");
    texturePackNameProperty->SetAttribute("arraySize", "1");
    texturePackProperties->InsertEndChild(texturePackNameProperty);

    XMLElement* texturePackNameValue = doc.NewElement("value");
    texturePackNameValue->SetText("TexturePackLoadConditioner0000");
    texturePackNameProperty->InsertEndChild(texturePackNameValue);

    XMLElement* texturePackDataSetProperty = doc.NewElement("property");
    texturePackDataSetProperty->SetAttribute("name", "dataSet");
    texturePackDataSetProperty->SetAttribute("type", "EntityHandle");
    texturePackDataSetProperty->SetAttribute("container", "StaticArray");
    texturePackDataSetProperty->SetAttribute("arraySize", "1");
    texturePackProperties->InsertEndChild(texturePackDataSetProperty);

    XMLElement* texturePackDataSetValue = doc.NewElement("value");
    texturePackDataSetValue->SetText("0x04D8FF20");
    texturePackDataSetProperty->InsertEndChild(texturePackDataSetValue);


    XMLElement* texturePackPathProperty = doc.NewElement("property");
    texturePackPathProperty->SetAttribute("name", "texturePackPath");
    texturePackPathProperty->SetAttribute("type", "Path");
    texturePackPathProperty->SetAttribute("container", "StaticArray");
    texturePackPathProperty->SetAttribute("arraySize", "1");
    texturePackProperties->InsertEndChild(texturePackPathProperty);
    texturePackPathProperty->InsertEndChild(doc.NewElement("value"));

    texturePackEntity->InsertEndChild(doc.NewElement("dynamicProperties"));

    // Save the XML to file
    if (doc.SaveFile(filePath.c_str()) == XML_SUCCESS) {
        std::cout << "XML file successfully generated: " << filePath << std::endl;
    }
    else {
        std::cerr << "Error generating XML file.    " << filePath << std::endl;
    }
}