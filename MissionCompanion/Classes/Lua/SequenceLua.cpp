#include "SequenceLua.h"
#include <ExternalLua.h>
#include "LandingZones.h"

#define Logstd(Message) std::cout << Message << std::endl;


//TODO: MAKE THIS MORE CUSTOM
void WriteMission_SequenceLua()
{
    std::filesystem::path sequenceLuaFolderPath = std::filesystem::path(getExePath()) / "MissionCompanion_Build" / getFPKFileName() / "Assets" / "tpp" / "pack" / "mission2" / "custom_story" / ("s" + getMissionCode()) / (getFPKFileName() + "_fpkd") / "Assets" / "tpp" / "level" / "mission2" / "story";

    if (std::filesystem::create_directories(sequenceLuaFolderPath)) {
        Logstd("main mission path folder created successfully.");
    }
    else {
        Logstd("main mission path folder already exists or failed to create.");
    }


    std::filesystem::path sequenceLuaFile = getFPKDFilePath() / "Assets" / "tpp" / "level" / "mission2" / "story" / ("s" + getMissionCode() + "_sequence.lua");

    if (std::filesystem::exists(sequenceLuaFile)) {
        if (std::filesystem::remove(sequenceLuaFile)) {
            Logstd("Existing mission_main Lua File file deleted.");
        }
        else {
            Logstd("Failed to delete existing mission_main Lua File file.");
            return;
        }
    }

    std::ofstream writeSequenceLuaFile(sequenceLuaFile.string());
    if (!writeSequenceLuaFile.is_open()) {
        Logstd("Failed to create mission_main Lua File file.");
        return;
    }

    // Write Lua content
    writeSequenceLuaFile << "local this = {}\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "--TppMission.OnAllocate\n";
    writeSequenceLuaFile << "--Leaving by heli will clear the mission\n";
    writeSequenceLuaFile << "this.ENABLE_DEFAULT_HELI_MISSION_CLEAR = true\n";
    writeSequenceLuaFile << "--At least one sequence has to be defined here\n";
    writeSequenceLuaFile << "local seq={\n";
    writeSequenceLuaFile << "	{\n";
    writeSequenceLuaFile << "		--Main Game - before executing the mission completion requirement\n";
    writeSequenceLuaFile << "		Seq_Game_MainGame = {\n";
    writeSequenceLuaFile << "			--Sequences are string-associated arrays of possible functions. See TppSequence for more.\n";
    writeSequenceLuaFile << "			--The self argument allows you to access any additional arbitrary table values in the current sequence.\n";
    writeSequenceLuaFile << "			--The seeminlgy unused sequenceName (own name) argument returns the string name of the current seqeuence with TppSequence.GetSequenceNameWithIndex(svars.seq_sequence). \n";
    writeSequenceLuaFile << "			--Messages(self,sequenceName) - return a StrCode32Table of messages.\n";
    writeSequenceLuaFile << "			--OnEnter(self,sequenceName) - executes upon entry into the sequence.\n";
    writeSequenceLuaFile << "			--OnUpdate(self,sequenceName) - executes repeatedly while in the sequence.\n";
    writeSequenceLuaFile << "			--OnLeave(self,sequenceName) - executes when leaving the sequence.\n";
    writeSequenceLuaFile << "			OnEnter=function(self,sequenceName)\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "			end,\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "			OnUpdate=function(self,sequenceName)\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "			end,\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "			OnLeave=function(self,sequenceName)\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "			end,\n";
    writeSequenceLuaFile << "		}\n";
    writeSequenceLuaFile << "	},\n";
    writeSequenceLuaFile << "	{\n";
    writeSequenceLuaFile << "		--Travel between sequences with TppSequence.SetNextSequence(\"Seq_Game_Escape\")\n";
    writeSequenceLuaFile << "		--Escape - after having executed the mission completion requirement, in this state, leaving will successfully clear the mission\n";
    writeSequenceLuaFile << "		Seq_Game_Escape = {\n";
    writeSequenceLuaFile << "		    OnEnter=function(self,sequenceName)\n";
    writeSequenceLuaFile << "				--Objectives have been completed, escaping the mission area will now consitute a mission clear. Hot zone appears as well.\n";
    writeSequenceLuaFile << "				TppMission.CanMissionClear()\n";
    writeSequenceLuaFile << "			end,\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "			OnUpdate=function(self,sequenceName)\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "			end,\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "			OnLeave=function(self,sequenceName)\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "			end,\n";
    writeSequenceLuaFile << "		}\n";
    writeSequenceLuaFile << "	},\n";
    writeSequenceLuaFile << "}\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "this.missionStartPosition = {\n";
    writeSequenceLuaFile << "   orderBoxList = {\n";
    writeSequenceLuaFile << "       --Order box names, i.e. \"box_s12000_00\",\n";
    writeSequenceLuaFile << "        \n";
    writeSequenceLuaFile << "   },\n";
    writeSequenceLuaFile << "   helicopterRouteList = {\n";
    writeSequenceLuaFile << "       --Drop point route names, need to be here when order boxes are\n";    
    writeSequenceLuaFile << "       \n" + getUsedHeliRoutes();
    writeSequenceLuaFile << "   },\n";
    writeSequenceLuaFile << " }\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "--No caller, so it must be global.\n";
    writeSequenceLuaFile << "function this.OnLoad()\n";
    writeSequenceLuaFile << "	local sequenceNames = {}\n";
    writeSequenceLuaFile << "	local sequences = {}\n";
    writeSequenceLuaFile << "	for index, seqTable in ipairs(seq) do\n";
    writeSequenceLuaFile << "		for seqName, sequenceTable in pairs(seqTable) do\n";
    writeSequenceLuaFile << "			sequenceNames[index]=seqName\n";
    writeSequenceLuaFile << "			sequences[seqName]=sequenceTable\n";
    writeSequenceLuaFile << "		end\n";
    writeSequenceLuaFile << "	end\n";
    writeSequenceLuaFile << "	--Register sequence names in order, first sequence will be the starting one\n";
    writeSequenceLuaFile << "	TppSequence.RegisterSequences(sequenceNames)\n";
    writeSequenceLuaFile << "	--Register sequence tables\n";
    writeSequenceLuaFile << "	TppSequence.RegisterSequenceTable(sequences)\n";
    writeSequenceLuaFile << "end\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "\n";
    writeSequenceLuaFile << "return this";

    writeSequenceLuaFile.close();

    #ifdef _DEBUG
    Logstd("Sequence Lua file generated successfully: " + sequenceLuaFolderPath.string());
    #endif // _DEBUG
}

