#pragma once

#include <iostream>
#include <cctype>
#include <string>
#include <cliext/vector>
#include <regex>
#include <msclr/marshal_cppstd.h>


#include "ExternalLua.h"
#include "LandingZones.h"



#ifndef LOG_MACRO
#define LOG_MACRO
#define Log(Message) Console::WriteLine(Message);
#endif




namespace MissionCompanion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Text;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelFPKFileName;
	protected:
	private: System::Windows::Forms::Label^ labelMissionCode;
	private: System::Windows::Forms::TextBox^ textBoxFPKFileName;
	private: System::Windows::Forms::TextBox^ textBoxMissionCode;
	private: System::Windows::Forms::Button^ buttonNextTo;
	private: System::Windows::Forms::Label^ labelErrorFPKFileName;
	private: System::Windows::Forms::Label^ labelErrorMissionCode;
	private: System::Windows::Forms::Label^ labelMapLocation;
	private: System::Windows::Forms::Label^ labelErrorMapLocation;



	private: System::Windows::Forms::ComboBox^ comboBoxLocation;
	private: System::Windows::Forms::Label^ labelMissionOptions;

	private: System::Windows::Forms::CheckedListBox^ MissionOptionList;
	private: System::Windows::Forms::TextBox^ textBoxTrig_innerZone;
	private: System::Windows::Forms::Label^ labelTrig_innerZone;
	private: System::Windows::Forms::Label^ labelTrig_outerZone;
	private: System::Windows::Forms::TextBox^ textBoxTrig_outerZone;


	private: System::Windows::Forms::Label^ labelTrig_hotZone;
	private: System::Windows::Forms::TextBox^ textBoxTrig_hotZone;


	private: System::Windows::Forms::Label^ labelMissionStartPoint;
	private: System::Windows::Forms::TextBox^ textBoxMissionStartPoint;
	private: System::Windows::Forms::PictureBox^ pictureBoxMap;
	private: System::Windows::Forms::CheckBox^ lz_drp_citadelSouth_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_sovietBase_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_sovietBase_E0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_sovietBase_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_sovietSouth_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_powerPlant_E0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_powerPlant_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_waterway_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_tent_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_tent_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_tent_E0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_remnantsNorth_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_remnantsNorth_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_remnants_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_field_W0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_remnants_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_fieldWest_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_field_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_ruins_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_field_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_ruinsNorth_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_commFacility_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_commFacility_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_commFacility_W0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_village_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_slopedTown_E0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_slopedTown_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_slopedTown_W0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_enemyBase_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_enemyBase_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_enemyBase_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_village_W0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_slopedTownEast_E0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_bridge_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_fort_E0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_fort_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_fort_W0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_cliffTown_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_cliffTown_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_cliffTown_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_cliffTownWest_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_flowStation_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_flowStation_E0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_swamp_W0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_outland_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_swamp_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_swampEast_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_swamp_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_swamp_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_pfCampNorth_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_savannahEast_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_pfCamp_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_pfCamp_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_pfCamp_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_hillSouth_W0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_hillWest_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_hill_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_hill_E0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_hill_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_factoryWest_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_factory_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_lab_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_lab_W0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_labWest_W0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_diamond_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_diamond_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_diamondWest_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_diamondSouth_W0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_diamondSouth_S0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_banana_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_savannahWest_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_bananaSouth_N0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_savannah_I0000;
	private: System::Windows::Forms::CheckBox^ lz_drp_savannahEast_N0000;































	private: System::ComponentModel::IContainer^ components;





















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->labelFPKFileName = (gcnew System::Windows::Forms::Label());
			this->labelMissionCode = (gcnew System::Windows::Forms::Label());
			this->textBoxFPKFileName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMissionCode = (gcnew System::Windows::Forms::TextBox());
			this->buttonNextTo = (gcnew System::Windows::Forms::Button());
			this->labelErrorFPKFileName = (gcnew System::Windows::Forms::Label());
			this->labelErrorMissionCode = (gcnew System::Windows::Forms::Label());
			this->labelMapLocation = (gcnew System::Windows::Forms::Label());
			this->labelErrorMapLocation = (gcnew System::Windows::Forms::Label());
			this->comboBoxLocation = (gcnew System::Windows::Forms::ComboBox());
			this->labelMissionOptions = (gcnew System::Windows::Forms::Label());
			this->MissionOptionList = (gcnew System::Windows::Forms::CheckedListBox());
			this->textBoxTrig_innerZone = (gcnew System::Windows::Forms::TextBox());
			this->labelTrig_innerZone = (gcnew System::Windows::Forms::Label());
			this->labelTrig_outerZone = (gcnew System::Windows::Forms::Label());
			this->textBoxTrig_outerZone = (gcnew System::Windows::Forms::TextBox());
			this->labelTrig_hotZone = (gcnew System::Windows::Forms::Label());
			this->textBoxTrig_hotZone = (gcnew System::Windows::Forms::TextBox());
			this->labelMissionStartPoint = (gcnew System::Windows::Forms::Label());
			this->textBoxMissionStartPoint = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxMap = (gcnew System::Windows::Forms::PictureBox());
			this->lz_drp_citadelSouth_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_sovietBase_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_sovietBase_E0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_sovietBase_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_sovietSouth_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_powerPlant_E0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_powerPlant_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_waterway_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_tent_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_tent_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_tent_E0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_remnantsNorth_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_remnantsNorth_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_remnants_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_field_W0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_remnants_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_fieldWest_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_field_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_ruins_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_field_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_ruinsNorth_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_commFacility_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_commFacility_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_commFacility_W0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_village_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_slopedTown_E0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_slopedTown_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_slopedTown_W0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_enemyBase_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_enemyBase_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_enemyBase_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_village_W0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_slopedTownEast_E0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_bridge_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_fort_E0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_fort_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_fort_W0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_cliffTown_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_cliffTown_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_cliffTown_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_cliffTownWest_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_flowStation_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_flowStation_E0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_swamp_W0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_outland_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_swamp_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_swampEast_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_swamp_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_swamp_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_pfCampNorth_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_savannahEast_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_pfCamp_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_pfCamp_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_pfCamp_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_hillSouth_W0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_hillWest_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_hill_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_hill_E0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_hill_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_factoryWest_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_factory_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_lab_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_lab_W0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_labWest_W0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_diamond_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_diamond_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_diamondWest_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_diamondSouth_W0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_diamondSouth_S0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_banana_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_savannahWest_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_bananaSouth_N0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_savannah_I0000 = (gcnew System::Windows::Forms::CheckBox());
			this->lz_drp_savannahEast_N0000 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMap))->BeginInit();
			this->SuspendLayout();
			// 
			// labelFPKFileName
			// 
			this->labelFPKFileName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelFPKFileName->AutoSize = true;
			this->labelFPKFileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelFPKFileName->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelFPKFileName->Location = System::Drawing::Point(6, 8);
			this->labelFPKFileName->Name = L"labelFPKFileName";
			this->labelFPKFileName->Size = System::Drawing::Size(143, 24);
			this->labelFPKFileName->TabIndex = 0;
			this->labelFPKFileName->Text = L".FPK FileName:";
			// 
			// labelMissionCode
			// 
			this->labelMissionCode->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelMissionCode->AutoSize = true;
			this->labelMissionCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelMissionCode->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelMissionCode->Location = System::Drawing::Point(24, 45);
			this->labelMissionCode->Name = L"labelMissionCode";
			this->labelMissionCode->Size = System::Drawing::Size(125, 24);
			this->labelMissionCode->TabIndex = 1;
			this->labelMissionCode->Text = L"MissionCode:";
			// 
			// textBoxFPKFileName
			// 
			this->textBoxFPKFileName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBoxFPKFileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxFPKFileName->ForeColor = System::Drawing::Color::Gray;
			this->textBoxFPKFileName->Location = System::Drawing::Point(155, 9);
			this->textBoxFPKFileName->Name = L"textBoxFPKFileName";
			this->textBoxFPKFileName->Size = System::Drawing::Size(173, 26);
			this->textBoxFPKFileName->TabIndex = 2;
			this->textBoxFPKFileName->Text = L"FPK_Name_Example";
			this->textBoxFPKFileName->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxFPKFileName_TextChanged);
			// 
			// textBoxMissionCode
			// 
			this->textBoxMissionCode->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBoxMissionCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxMissionCode->ForeColor = System::Drawing::Color::Gray;
			this->textBoxMissionCode->Location = System::Drawing::Point(155, 45);
			this->textBoxMissionCode->Name = L"textBoxMissionCode";
			this->textBoxMissionCode->Size = System::Drawing::Size(66, 26);
			this->textBoxMissionCode->TabIndex = 3;
			this->textBoxMissionCode->Text = L"13000";
			this->textBoxMissionCode->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxMissionCode_TextChanged);
			// 
			// buttonNextTo
			// 
			this->buttonNextTo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonNextTo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonNextTo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->buttonNextTo->Location = System::Drawing::Point(1183, 820);
			this->buttonNextTo->Name = L"buttonNextTo";
			this->buttonNextTo->Size = System::Drawing::Size(154, 66);
			this->buttonNextTo->TabIndex = 4;
			this->buttonNextTo->Text = L"Next";
			this->buttonNextTo->UseVisualStyleBackColor = true;
			this->buttonNextTo->Click += gcnew System::EventHandler(this, &MainForm::buttonNextTo_Click);
			// 
			// labelErrorFPKFileName
			// 
			this->labelErrorFPKFileName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelErrorFPKFileName->AutoSize = true;
			this->labelErrorFPKFileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelErrorFPKFileName->Location = System::Drawing::Point(334, 15);
			this->labelErrorFPKFileName->Name = L"labelErrorFPKFileName";
			this->labelErrorFPKFileName->Size = System::Drawing::Size(0, 17);
			this->labelErrorFPKFileName->TabIndex = 5;
			// 
			// labelErrorMissionCode
			// 
			this->labelErrorMissionCode->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelErrorMissionCode->AutoSize = true;
			this->labelErrorMissionCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelErrorMissionCode->ForeColor = System::Drawing::Color::Red;
			this->labelErrorMissionCode->Location = System::Drawing::Point(227, 51);
			this->labelErrorMissionCode->Name = L"labelErrorMissionCode";
			this->labelErrorMissionCode->Size = System::Drawing::Size(0, 17);
			this->labelErrorMissionCode->TabIndex = 6;
			// 
			// labelMapLocation
			// 
			this->labelMapLocation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelMapLocation->AutoSize = true;
			this->labelMapLocation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelMapLocation->ForeColor = System::Drawing::Color::Black;
			this->labelMapLocation->Location = System::Drawing::Point(63, 87);
			this->labelMapLocation->Name = L"labelMapLocation";
			this->labelMapLocation->Size = System::Drawing::Size(86, 24);
			this->labelMapLocation->TabIndex = 7;
			this->labelMapLocation->Text = L"Location:";
			this->labelMapLocation->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// labelErrorMapLocation
			// 
			this->labelErrorMapLocation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelErrorMapLocation->AutoSize = true;
			this->labelErrorMapLocation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelErrorMapLocation->ForeColor = System::Drawing::Color::Red;
			this->labelErrorMapLocation->Location = System::Drawing::Point(282, 94);
			this->labelErrorMapLocation->Name = L"labelErrorMapLocation";
			this->labelErrorMapLocation->Size = System::Drawing::Size(0, 17);
			this->labelErrorMapLocation->TabIndex = 9;
			// 
			// comboBoxLocation
			// 
			this->comboBoxLocation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->comboBoxLocation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxLocation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxLocation->FormattingEnabled = true;
			this->comboBoxLocation->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Afghanistan", L"Africa" });
			this->comboBoxLocation->Location = System::Drawing::Point(155, 88);
			this->comboBoxLocation->Name = L"comboBoxLocation";
			this->comboBoxLocation->Size = System::Drawing::Size(121, 26);
			this->comboBoxLocation->TabIndex = 8;
			this->comboBoxLocation->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxLocation_SelectedIndexChanged);
			// 
			// labelMissionOptions
			// 
			this->labelMissionOptions->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelMissionOptions->AutoSize = true;
			this->labelMissionOptions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelMissionOptions->ForeColor = System::Drawing::Color::Black;
			this->labelMissionOptions->Location = System::Drawing::Point(7, 118);
			this->labelMissionOptions->Name = L"labelMissionOptions";
			this->labelMissionOptions->Size = System::Drawing::Size(145, 24);
			this->labelMissionOptions->TabIndex = 11;
			this->labelMissionOptions->Text = L"Mission options:";
			// 
			// MissionOptionList
			// 
			this->MissionOptionList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->MissionOptionList->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MissionOptionList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MissionOptionList->FormattingEnabled = true;
			this->MissionOptionList->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Hide Mission", L"out of bounds system (innerZone, outerZone, hotZone)",
					L"No sortie prep", L"No buddy select in the sortie", L"No vehicle select in the sortie", L"Only ASAP as deployment time option"
			});
			this->MissionOptionList->Location = System::Drawing::Point(155, 122);
			this->MissionOptionList->MaximumSize = System::Drawing::Size(410, 97);
			this->MissionOptionList->MinimumSize = System::Drawing::Size(410, 97);
			this->MissionOptionList->Name = L"MissionOptionList";
			this->MissionOptionList->Size = System::Drawing::Size(410, 97);
			this->MissionOptionList->TabIndex = 12;
			// 
			// textBoxTrig_innerZone
			// 
			this->textBoxTrig_innerZone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBoxTrig_innerZone->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxTrig_innerZone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxTrig_innerZone->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->textBoxTrig_innerZone->Location = System::Drawing::Point(10, 344);
			this->textBoxTrig_innerZone->MaximumSize = System::Drawing::Size(540, 150);
			this->textBoxTrig_innerZone->MinimumSize = System::Drawing::Size(540, 150);
			this->textBoxTrig_innerZone->Multiline = true;
			this->textBoxTrig_innerZone->Name = L"textBoxTrig_innerZone";
			this->textBoxTrig_innerZone->Size = System::Drawing::Size(540, 150);
			this->textBoxTrig_innerZone->TabIndex = 13;
			// 
			// labelTrig_innerZone
			// 
			this->labelTrig_innerZone->AutoSize = true;
			this->labelTrig_innerZone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTrig_innerZone->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelTrig_innerZone->Location = System::Drawing::Point(6, 317);
			this->labelTrig_innerZone->Name = L"labelTrig_innerZone";
			this->labelTrig_innerZone->Size = System::Drawing::Size(461, 24);
			this->labelTrig_innerZone->TabIndex = 14;
			this->labelTrig_innerZone->Text = L"Trig_innerZone: {pos={X, Y, Z},rotY=Y-Axis Rotation,},";
			// 
			// labelTrig_outerZone
			// 
			this->labelTrig_outerZone->AutoSize = true;
			this->labelTrig_outerZone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTrig_outerZone->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelTrig_outerZone->Location = System::Drawing::Point(6, 497);
			this->labelTrig_outerZone->Name = L"labelTrig_outerZone";
			this->labelTrig_outerZone->Size = System::Drawing::Size(461, 24);
			this->labelTrig_outerZone->TabIndex = 16;
			this->labelTrig_outerZone->Text = L"Trig_outerZone: {pos={X, Y, Z},rotY=Y-Axis Rotation,},";
			// 
			// textBoxTrig_outerZone
			// 
			this->textBoxTrig_outerZone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBoxTrig_outerZone->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxTrig_outerZone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxTrig_outerZone->Location = System::Drawing::Point(7, 524);
			this->textBoxTrig_outerZone->MaximumSize = System::Drawing::Size(540, 150);
			this->textBoxTrig_outerZone->MinimumSize = System::Drawing::Size(540, 150);
			this->textBoxTrig_outerZone->Multiline = true;
			this->textBoxTrig_outerZone->Name = L"textBoxTrig_outerZone";
			this->textBoxTrig_outerZone->Size = System::Drawing::Size(540, 150);
			this->textBoxTrig_outerZone->TabIndex = 15;
			// 
			// labelTrig_hotZone
			// 
			this->labelTrig_hotZone->AutoSize = true;
			this->labelTrig_hotZone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTrig_hotZone->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelTrig_hotZone->Location = System::Drawing::Point(6, 677);
			this->labelTrig_hotZone->Name = L"labelTrig_hotZone";
			this->labelTrig_hotZone->Size = System::Drawing::Size(444, 24);
			this->labelTrig_hotZone->TabIndex = 18;
			this->labelTrig_hotZone->Text = L"Trig_hotZone: {pos={X, Y, Z},rotY=Y-Axis Rotation,},";
			// 
			// textBoxTrig_hotZone
			// 
			this->textBoxTrig_hotZone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBoxTrig_hotZone->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxTrig_hotZone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxTrig_hotZone->Location = System::Drawing::Point(7, 704);
			this->textBoxTrig_hotZone->MaximumSize = System::Drawing::Size(540, 150);
			this->textBoxTrig_hotZone->MinimumSize = System::Drawing::Size(540, 150);
			this->textBoxTrig_hotZone->Multiline = true;
			this->textBoxTrig_hotZone->Name = L"textBoxTrig_hotZone";
			this->textBoxTrig_hotZone->Size = System::Drawing::Size(540, 150);
			this->textBoxTrig_hotZone->TabIndex = 17;
			// 
			// labelMissionStartPoint
			// 
			this->labelMissionStartPoint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->labelMissionStartPoint->AutoSize = true;
			this->labelMissionStartPoint->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelMissionStartPoint->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelMissionStartPoint->Location = System::Drawing::Point(3, 252);
			this->labelMissionStartPoint->Name = L"labelMissionStartPoint";
			this->labelMissionStartPoint->Size = System::Drawing::Size(472, 24);
			this->labelMissionStartPoint->TabIndex = 22;
			this->labelMissionStartPoint->Text = L"missionStartPoint: {pos={X, Y, Z},rotY=Y-Axis Rotation,},";
			// 
			// textBoxMissionStartPoint
			// 
			this->textBoxMissionStartPoint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->textBoxMissionStartPoint->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxMissionStartPoint->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBoxMissionStartPoint->Location = System::Drawing::Point(10, 279);
			this->textBoxMissionStartPoint->Name = L"textBoxMissionStartPoint";
			this->textBoxMissionStartPoint->Size = System::Drawing::Size(454, 26);
			this->textBoxMissionStartPoint->TabIndex = 21;
			// 
			// pictureBoxMap
			// 
			this->pictureBoxMap->Location = System::Drawing::Point(571, 9);
			this->pictureBoxMap->Name = L"pictureBoxMap";
			this->pictureBoxMap->Size = System::Drawing::Size(766, 805);
			this->pictureBoxMap->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxMap->TabIndex = 23;
			this->pictureBoxMap->TabStop = false;
			// 
			// lz_drp_citadelSouth_S0000
			// 
			this->lz_drp_citadelSouth_S0000->AutoSize = true;
			this->lz_drp_citadelSouth_S0000->ForeColor = System::Drawing::Color::Black;
			this->lz_drp_citadelSouth_S0000->Location = System::Drawing::Point(910, 95);
			this->lz_drp_citadelSouth_S0000->Name = L"lz_drp_citadelSouth_S0000";
			this->lz_drp_citadelSouth_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_citadelSouth_S0000->TabIndex = 24;
			this->lz_drp_citadelSouth_S0000->UseVisualStyleBackColor = true;
			this->lz_drp_citadelSouth_S0000->Visible = false;
			// 
			// lz_drp_sovietBase_N0000
			// 
			this->lz_drp_sovietBase_N0000->AutoSize = true;
			this->lz_drp_sovietBase_N0000->ForeColor = System::Drawing::Color::Black;
			this->lz_drp_sovietBase_N0000->Location = System::Drawing::Point(865, 128);
			this->lz_drp_sovietBase_N0000->Name = L"lz_drp_sovietBase_N0000";
			this->lz_drp_sovietBase_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_sovietBase_N0000->TabIndex = 25;
			this->lz_drp_sovietBase_N0000->UseVisualStyleBackColor = true;
			this->lz_drp_sovietBase_N0000->Visible = false;
			// 
			// lz_drp_sovietBase_E0000
			// 
			this->lz_drp_sovietBase_E0000->AutoSize = true;
			this->lz_drp_sovietBase_E0000->ForeColor = System::Drawing::Color::Black;
			this->lz_drp_sovietBase_E0000->Location = System::Drawing::Point(781, 95);
			this->lz_drp_sovietBase_E0000->Name = L"lz_drp_sovietBase_E0000";
			this->lz_drp_sovietBase_E0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_sovietBase_E0000->TabIndex = 26;
			this->lz_drp_sovietBase_E0000->UseVisualStyleBackColor = true;
			this->lz_drp_sovietBase_E0000->Visible = false;
			// 
			// lz_drp_sovietBase_S0000
			// 
			this->lz_drp_sovietBase_S0000->AutoSize = true;
			this->lz_drp_sovietBase_S0000->Location = System::Drawing::Point(792, 162);
			this->lz_drp_sovietBase_S0000->Name = L"lz_drp_sovietBase_S0000";
			this->lz_drp_sovietBase_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_sovietBase_S0000->TabIndex = 27;
			this->lz_drp_sovietBase_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_sovietSouth_S0000
			// 
			this->lz_drp_sovietSouth_S0000->AutoSize = true;
			this->lz_drp_sovietSouth_S0000->Location = System::Drawing::Point(832, 260);
			this->lz_drp_sovietSouth_S0000->Name = L"lz_drp_sovietSouth_S0000";
			this->lz_drp_sovietSouth_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_sovietSouth_S0000->TabIndex = 28;
			this->lz_drp_sovietSouth_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_powerPlant_E0000
			// 
			this->lz_drp_powerPlant_E0000->AutoSize = true;
			this->lz_drp_powerPlant_E0000->Location = System::Drawing::Point(933, 243);
			this->lz_drp_powerPlant_E0000->Name = L"lz_drp_powerPlant_E0000";
			this->lz_drp_powerPlant_E0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_powerPlant_E0000->TabIndex = 29;
			this->lz_drp_powerPlant_E0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_powerPlant_S0000
			// 
			this->lz_drp_powerPlant_S0000->AutoSize = true;
			this->lz_drp_powerPlant_S0000->Location = System::Drawing::Point(887, 308);
			this->lz_drp_powerPlant_S0000->Name = L"lz_drp_powerPlant_S0000";
			this->lz_drp_powerPlant_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_powerPlant_S0000->TabIndex = 30;
			this->lz_drp_powerPlant_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_waterway_I0000
			// 
			this->lz_drp_waterway_I0000->AutoSize = true;
			this->lz_drp_waterway_I0000->Location = System::Drawing::Point(731, 262);
			this->lz_drp_waterway_I0000->Name = L"lz_drp_waterway_I0000";
			this->lz_drp_waterway_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_waterway_I0000->TabIndex = 31;
			this->lz_drp_waterway_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_tent_N0000
			// 
			this->lz_drp_tent_N0000->AutoSize = true;
			this->lz_drp_tent_N0000->Location = System::Drawing::Point(631, 344);
			this->lz_drp_tent_N0000->Name = L"lz_drp_tent_N0000";
			this->lz_drp_tent_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_tent_N0000->TabIndex = 32;
			this->lz_drp_tent_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_tent_I0000
			// 
			this->lz_drp_tent_I0000->AutoSize = true;
			this->lz_drp_tent_I0000->Location = System::Drawing::Point(631, 378);
			this->lz_drp_tent_I0000->Name = L"lz_drp_tent_I0000";
			this->lz_drp_tent_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_tent_I0000->TabIndex = 33;
			this->lz_drp_tent_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_tent_E0000
			// 
			this->lz_drp_tent_E0000->AutoSize = true;
			this->lz_drp_tent_E0000->Location = System::Drawing::Point(657, 414);
			this->lz_drp_tent_E0000->Name = L"lz_drp_tent_E0000";
			this->lz_drp_tent_E0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_tent_E0000->TabIndex = 34;
			this->lz_drp_tent_E0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_remnantsNorth_S0000
			// 
			this->lz_drp_remnantsNorth_S0000->AutoSize = true;
			this->lz_drp_remnantsNorth_S0000->Location = System::Drawing::Point(631, 460);
			this->lz_drp_remnantsNorth_S0000->Name = L"lz_drp_remnantsNorth_S0000";
			this->lz_drp_remnantsNorth_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_remnantsNorth_S0000->TabIndex = 35;
			this->lz_drp_remnantsNorth_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_remnantsNorth_N0000
			// 
			this->lz_drp_remnantsNorth_N0000->AutoSize = true;
			this->lz_drp_remnantsNorth_N0000->Location = System::Drawing::Point(648, 524);
			this->lz_drp_remnantsNorth_N0000->Name = L"lz_drp_remnantsNorth_N0000";
			this->lz_drp_remnantsNorth_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_remnantsNorth_N0000->TabIndex = 36;
			this->lz_drp_remnantsNorth_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_remnants_I0000
			// 
			this->lz_drp_remnants_I0000->AutoSize = true;
			this->lz_drp_remnants_I0000->Location = System::Drawing::Point(631, 556);
			this->lz_drp_remnants_I0000->Name = L"lz_drp_remnants_I0000";
			this->lz_drp_remnants_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_remnants_I0000->TabIndex = 37;
			this->lz_drp_remnants_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_field_W0000
			// 
			this->lz_drp_field_W0000->AutoSize = true;
			this->lz_drp_field_W0000->Location = System::Drawing::Point(678, 582);
			this->lz_drp_field_W0000->Name = L"lz_drp_field_W0000";
			this->lz_drp_field_W0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_field_W0000->TabIndex = 38;
			this->lz_drp_field_W0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_remnants_S0000
			// 
			this->lz_drp_remnants_S0000->AutoSize = true;
			this->lz_drp_remnants_S0000->Location = System::Drawing::Point(648, 604);
			this->lz_drp_remnants_S0000->Name = L"lz_drp_remnants_S0000";
			this->lz_drp_remnants_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_remnants_S0000->TabIndex = 39;
			this->lz_drp_remnants_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_fieldWest_S0000
			// 
			this->lz_drp_fieldWest_S0000->AutoSize = true;
			this->lz_drp_fieldWest_S0000->Location = System::Drawing::Point(657, 704);
			this->lz_drp_fieldWest_S0000->Name = L"lz_drp_fieldWest_S0000";
			this->lz_drp_fieldWest_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_fieldWest_S0000->TabIndex = 40;
			this->lz_drp_fieldWest_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_field_I0000
			// 
			this->lz_drp_field_I0000->AutoSize = true;
			this->lz_drp_field_I0000->Location = System::Drawing::Point(701, 704);
			this->lz_drp_field_I0000->Name = L"lz_drp_field_I0000";
			this->lz_drp_field_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_field_I0000->TabIndex = 41;
			this->lz_drp_field_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_ruins_S0000
			// 
			this->lz_drp_ruins_S0000->AutoSize = true;
			this->lz_drp_ruins_S0000->Location = System::Drawing::Point(814, 757);
			this->lz_drp_ruins_S0000->Name = L"lz_drp_ruins_S0000";
			this->lz_drp_ruins_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_ruins_S0000->TabIndex = 42;
			this->lz_drp_ruins_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_field_N0000
			// 
			this->lz_drp_field_N0000->AutoSize = true;
			this->lz_drp_field_N0000->Location = System::Drawing::Point(792, 687);
			this->lz_drp_field_N0000->Name = L"lz_drp_field_N0000";
			this->lz_drp_field_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_field_N0000->TabIndex = 43;
			this->lz_drp_field_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_ruinsNorth_S0000
			// 
			this->lz_drp_ruinsNorth_S0000->AutoSize = true;
			this->lz_drp_ruinsNorth_S0000->Location = System::Drawing::Point(856, 704);
			this->lz_drp_ruinsNorth_S0000->Name = L"lz_drp_ruinsNorth_S0000";
			this->lz_drp_ruinsNorth_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_ruinsNorth_S0000->TabIndex = 44;
			this->lz_drp_ruinsNorth_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_commFacility_S0000
			// 
			this->lz_drp_commFacility_S0000->AutoSize = true;
			this->lz_drp_commFacility_S0000->Location = System::Drawing::Point(967, 677);
			this->lz_drp_commFacility_S0000->Name = L"lz_drp_commFacility_S0000";
			this->lz_drp_commFacility_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_commFacility_S0000->TabIndex = 45;
			this->lz_drp_commFacility_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_commFacility_I0000
			// 
			this->lz_drp_commFacility_I0000->AutoSize = true;
			this->lz_drp_commFacility_I0000->Location = System::Drawing::Point(955, 621);
			this->lz_drp_commFacility_I0000->Name = L"lz_drp_commFacility_I0000";
			this->lz_drp_commFacility_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_commFacility_I0000->TabIndex = 46;
			this->lz_drp_commFacility_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_commFacility_W0000
			// 
			this->lz_drp_commFacility_W0000->AutoSize = true;
			this->lz_drp_commFacility_W0000->Location = System::Drawing::Point(910, 604);
			this->lz_drp_commFacility_W0000->Name = L"lz_drp_commFacility_W0000";
			this->lz_drp_commFacility_W0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_commFacility_W0000->TabIndex = 47;
			this->lz_drp_commFacility_W0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_village_N0000
			// 
			this->lz_drp_village_N0000->AutoSize = true;
			this->lz_drp_village_N0000->Location = System::Drawing::Point(832, 604);
			this->lz_drp_village_N0000->Name = L"lz_drp_village_N0000";
			this->lz_drp_village_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_village_N0000->TabIndex = 59;
			this->lz_drp_village_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_slopedTown_E0000
			// 
			this->lz_drp_slopedTown_E0000->AutoSize = true;
			this->lz_drp_slopedTown_E0000->Location = System::Drawing::Point(910, 556);
			this->lz_drp_slopedTown_E0000->Name = L"lz_drp_slopedTown_E0000";
			this->lz_drp_slopedTown_E0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_slopedTown_E0000->TabIndex = 49;
			this->lz_drp_slopedTown_E0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_slopedTown_I0000
			// 
			this->lz_drp_slopedTown_I0000->AutoSize = true;
			this->lz_drp_slopedTown_I0000->Location = System::Drawing::Point(897, 524);
			this->lz_drp_slopedTown_I0000->Name = L"lz_drp_slopedTown_I0000";
			this->lz_drp_slopedTown_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_slopedTown_I0000->TabIndex = 50;
			this->lz_drp_slopedTown_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_slopedTown_W0000
			// 
			this->lz_drp_slopedTown_W0000->AutoSize = true;
			this->lz_drp_slopedTown_W0000->Location = System::Drawing::Point(856, 480);
			this->lz_drp_slopedTown_W0000->Name = L"lz_drp_slopedTown_W0000";
			this->lz_drp_slopedTown_W0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_slopedTown_W0000->TabIndex = 51;
			this->lz_drp_slopedTown_W0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_enemyBase_N0000
			// 
			this->lz_drp_enemyBase_N0000->AutoSize = true;
			this->lz_drp_enemyBase_N0000->Location = System::Drawing::Point(814, 451);
			this->lz_drp_enemyBase_N0000->Name = L"lz_drp_enemyBase_N0000";
			this->lz_drp_enemyBase_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_enemyBase_N0000->TabIndex = 52;
			this->lz_drp_enemyBase_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_enemyBase_I0000
			// 
			this->lz_drp_enemyBase_I0000->AutoSize = true;
			this->lz_drp_enemyBase_I0000->Location = System::Drawing::Point(771, 442);
			this->lz_drp_enemyBase_I0000->Name = L"lz_drp_enemyBase_I0000";
			this->lz_drp_enemyBase_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_enemyBase_I0000->TabIndex = 53;
			this->lz_drp_enemyBase_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_enemyBase_S0000
			// 
			this->lz_drp_enemyBase_S0000->AutoSize = true;
			this->lz_drp_enemyBase_S0000->Location = System::Drawing::Point(755, 480);
			this->lz_drp_enemyBase_S0000->Name = L"lz_drp_enemyBase_S0000";
			this->lz_drp_enemyBase_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_enemyBase_S0000->TabIndex = 54;
			this->lz_drp_enemyBase_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_village_W0000
			// 
			this->lz_drp_village_W0000->AutoSize = true;
			this->lz_drp_village_W0000->Location = System::Drawing::Point(781, 543);
			this->lz_drp_village_W0000->Name = L"lz_drp_village_W0000";
			this->lz_drp_village_W0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_village_W0000->TabIndex = 55;
			this->lz_drp_village_W0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_slopedTownEast_E0000
			// 
			this->lz_drp_slopedTownEast_E0000->AutoSize = true;
			this->lz_drp_slopedTownEast_E0000->Location = System::Drawing::Point(967, 571);
			this->lz_drp_slopedTownEast_E0000->Name = L"lz_drp_slopedTownEast_E0000";
			this->lz_drp_slopedTownEast_E0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_slopedTownEast_E0000->TabIndex = 56;
			this->lz_drp_slopedTownEast_E0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_bridge_S0000
			// 
			this->lz_drp_bridge_S0000->AutoSize = true;
			this->lz_drp_bridge_S0000->Location = System::Drawing::Point(1026, 643);
			this->lz_drp_bridge_S0000->Name = L"lz_drp_bridge_S0000";
			this->lz_drp_bridge_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_bridge_S0000->TabIndex = 57;
			this->lz_drp_bridge_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_fort_E0000
			// 
			this->lz_drp_fort_E0000->AutoSize = true;
			this->lz_drp_fort_E0000->Location = System::Drawing::Point(1157, 591);
			this->lz_drp_fort_E0000->Name = L"lz_drp_fort_E0000";
			this->lz_drp_fort_E0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_fort_E0000->TabIndex = 58;
			this->lz_drp_fort_E0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_fort_I0000
			// 
			this->lz_drp_fort_I0000->AutoSize = true;
			this->lz_drp_fort_I0000->Location = System::Drawing::Point(1211, 505);
			this->lz_drp_fort_I0000->Name = L"lz_drp_fort_I0000";
			this->lz_drp_fort_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_fort_I0000->TabIndex = 59;
			this->lz_drp_fort_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_fort_W0000
			// 
			this->lz_drp_fort_W0000->AutoSize = true;
			this->lz_drp_fort_W0000->Location = System::Drawing::Point(1137, 480);
			this->lz_drp_fort_W0000->Name = L"lz_drp_fort_W0000";
			this->lz_drp_fort_W0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_fort_W0000->TabIndex = 60;
			this->lz_drp_fort_W0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_cliffTown_N0000
			// 
			this->lz_drp_cliffTown_N0000->AutoSize = true;
			this->lz_drp_cliffTown_N0000->Location = System::Drawing::Point(1060, 401);
			this->lz_drp_cliffTown_N0000->Name = L"lz_drp_cliffTown_N0000";
			this->lz_drp_cliffTown_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_cliffTown_N0000->TabIndex = 61;
			this->lz_drp_cliffTown_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_cliffTown_I0000
			// 
			this->lz_drp_cliffTown_I0000->AutoSize = true;
			this->lz_drp_cliffTown_I0000->Location = System::Drawing::Point(1035, 431);
			this->lz_drp_cliffTown_I0000->Name = L"lz_drp_cliffTown_I0000";
			this->lz_drp_cliffTown_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_cliffTown_I0000->TabIndex = 62;
			this->lz_drp_cliffTown_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_cliffTown_S0000
			// 
			this->lz_drp_cliffTown_S0000->AutoSize = true;
			this->lz_drp_cliffTown_S0000->Location = System::Drawing::Point(967, 431);
			this->lz_drp_cliffTown_S0000->Name = L"lz_drp_cliffTown_S0000";
			this->lz_drp_cliffTown_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_cliffTown_S0000->TabIndex = 63;
			this->lz_drp_cliffTown_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_cliffTownWest_S0000
			// 
			this->lz_drp_cliffTownWest_S0000->AutoSize = true;
			this->lz_drp_cliffTownWest_S0000->Location = System::Drawing::Point(942, 378);
			this->lz_drp_cliffTownWest_S0000->Name = L"lz_drp_cliffTownWest_S0000";
			this->lz_drp_cliffTownWest_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_cliffTownWest_S0000->TabIndex = 64;
			this->lz_drp_cliffTownWest_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_flowStation_I0000
			// 
			this->lz_drp_flowStation_I0000->AutoSize = true;
			this->lz_drp_flowStation_I0000->Location = System::Drawing::Point(693, 150);
			this->lz_drp_flowStation_I0000->Name = L"lz_drp_flowStation_I0000";
			this->lz_drp_flowStation_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_flowStation_I0000->TabIndex = 49;
			this->lz_drp_flowStation_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_flowStation_E0000
			// 
			this->lz_drp_flowStation_E0000->AutoSize = true;
			this->lz_drp_flowStation_E0000->Location = System::Drawing::Point(752, 179);
			this->lz_drp_flowStation_E0000->Name = L"lz_drp_flowStation_E0000";
			this->lz_drp_flowStation_E0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_flowStation_E0000->TabIndex = 50;
			this->lz_drp_flowStation_E0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_swamp_W0000
			// 
			this->lz_drp_swamp_W0000->AutoSize = true;
			this->lz_drp_swamp_W0000->Location = System::Drawing::Point(683, 243);
			this->lz_drp_swamp_W0000->Name = L"lz_drp_swamp_W0000";
			this->lz_drp_swamp_W0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_swamp_W0000->TabIndex = 51;
			this->lz_drp_swamp_W0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_outland_S0000
			// 
			this->lz_drp_outland_S0000->AutoSize = true;
			this->lz_drp_outland_S0000->Location = System::Drawing::Point(597, 390);
			this->lz_drp_outland_S0000->Name = L"lz_drp_outland_S0000";
			this->lz_drp_outland_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_outland_S0000->TabIndex = 52;
			this->lz_drp_outland_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_swamp_N0000
			// 
			this->lz_drp_swamp_N0000->AutoSize = true;
			this->lz_drp_swamp_N0000->Location = System::Drawing::Point(798, 232);
			this->lz_drp_swamp_N0000->Name = L"lz_drp_swamp_N0000";
			this->lz_drp_swamp_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_swamp_N0000->TabIndex = 53;
			this->lz_drp_swamp_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_swampEast_N0000
			// 
			this->lz_drp_swampEast_N0000->AutoSize = true;
			this->lz_drp_swampEast_N0000->Location = System::Drawing::Point(822, 286);
			this->lz_drp_swampEast_N0000->Name = L"lz_drp_swampEast_N0000";
			this->lz_drp_swampEast_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_swampEast_N0000->TabIndex = 54;
			this->lz_drp_swampEast_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_swamp_I0000
			// 
			this->lz_drp_swamp_I0000->AutoSize = true;
			this->lz_drp_swamp_I0000->Location = System::Drawing::Point(752, 300);
			this->lz_drp_swamp_I0000->Name = L"lz_drp_swamp_I0000";
			this->lz_drp_swamp_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_swamp_I0000->TabIndex = 55;
			this->lz_drp_swamp_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_swamp_S0000
			// 
			this->lz_drp_swamp_S0000->AutoSize = true;
			this->lz_drp_swamp_S0000->Location = System::Drawing::Point(717, 300);
			this->lz_drp_swamp_S0000->Name = L"lz_drp_swamp_S0000";
			this->lz_drp_swamp_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_swamp_S0000->TabIndex = 56;
			this->lz_drp_swamp_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_pfCampNorth_S0000
			// 
			this->lz_drp_pfCampNorth_S0000->AutoSize = true;
			this->lz_drp_pfCampNorth_S0000->Location = System::Drawing::Point(798, 400);
			this->lz_drp_pfCampNorth_S0000->Name = L"lz_drp_pfCampNorth_S0000";
			this->lz_drp_pfCampNorth_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_pfCampNorth_S0000->TabIndex = 57;
			this->lz_drp_pfCampNorth_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_savannahEast_S0000
			// 
			this->lz_drp_savannahEast_S0000->AutoSize = true;
			this->lz_drp_savannahEast_S0000->Location = System::Drawing::Point(855, 441);
			this->lz_drp_savannahEast_S0000->Name = L"lz_drp_savannahEast_S0000";
			this->lz_drp_savannahEast_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_savannahEast_S0000->TabIndex = 58;
			this->lz_drp_savannahEast_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_pfCamp_N0000
			// 
			this->lz_drp_pfCamp_N0000->AutoSize = true;
			this->lz_drp_pfCamp_N0000->Location = System::Drawing::Point(813, 480);
			this->lz_drp_pfCamp_N0000->Name = L"lz_drp_pfCamp_N0000";
			this->lz_drp_pfCamp_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_pfCamp_N0000->TabIndex = 60;
			this->lz_drp_pfCamp_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_pfCamp_I0000
			// 
			this->lz_drp_pfCamp_I0000->AutoSize = true;
			this->lz_drp_pfCamp_I0000->Location = System::Drawing::Point(739, 497);
			this->lz_drp_pfCamp_I0000->Name = L"lz_drp_pfCamp_I0000";
			this->lz_drp_pfCamp_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_pfCamp_I0000->TabIndex = 61;
			this->lz_drp_pfCamp_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_pfCamp_S0000
			// 
			this->lz_drp_pfCamp_S0000->AutoSize = true;
			this->lz_drp_pfCamp_S0000->Location = System::Drawing::Point(717, 568);
			this->lz_drp_pfCamp_S0000->Name = L"lz_drp_pfCamp_S0000";
			this->lz_drp_pfCamp_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_pfCamp_S0000->TabIndex = 62;
			this->lz_drp_pfCamp_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_hillSouth_W0000
			// 
			this->lz_drp_hillSouth_W0000->AutoSize = true;
			this->lz_drp_hillSouth_W0000->Location = System::Drawing::Point(785, 627);
			this->lz_drp_hillSouth_W0000->Name = L"lz_drp_hillSouth_W0000";
			this->lz_drp_hillSouth_W0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_hillSouth_W0000->TabIndex = 63;
			this->lz_drp_hillSouth_W0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_hillWest_S0000
			// 
			this->lz_drp_hillWest_S0000->AutoSize = true;
			this->lz_drp_hillWest_S0000->Location = System::Drawing::Point(901, 541);
			this->lz_drp_hillWest_S0000->Name = L"lz_drp_hillWest_S0000";
			this->lz_drp_hillWest_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_hillWest_S0000->TabIndex = 64;
			this->lz_drp_hillWest_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_hill_I0000
			// 
			this->lz_drp_hill_I0000->AutoSize = true;
			this->lz_drp_hill_I0000->Location = System::Drawing::Point(952, 568);
			this->lz_drp_hill_I0000->Name = L"lz_drp_hill_I0000";
			this->lz_drp_hill_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_hill_I0000->TabIndex = 65;
			this->lz_drp_hill_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_hill_E0000
			// 
			this->lz_drp_hill_E0000->AutoSize = true;
			this->lz_drp_hill_E0000->Location = System::Drawing::Point(994, 577);
			this->lz_drp_hill_E0000->Name = L"lz_drp_hill_E0000";
			this->lz_drp_hill_E0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_hill_E0000->TabIndex = 66;
			this->lz_drp_hill_E0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_hill_N0000
			// 
			this->lz_drp_hill_N0000->AutoSize = true;
			this->lz_drp_hill_N0000->Location = System::Drawing::Point(961, 507);
			this->lz_drp_hill_N0000->Name = L"lz_drp_hill_N0000";
			this->lz_drp_hill_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_hill_N0000->TabIndex = 67;
			this->lz_drp_hill_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_factoryWest_S0000
			// 
			this->lz_drp_factoryWest_S0000->AutoSize = true;
			this->lz_drp_factoryWest_S0000->Location = System::Drawing::Point(1050, 480);
			this->lz_drp_factoryWest_S0000->Name = L"lz_drp_factoryWest_S0000";
			this->lz_drp_factoryWest_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_factoryWest_S0000->TabIndex = 68;
			this->lz_drp_factoryWest_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_factory_N0000
			// 
			this->lz_drp_factory_N0000->AutoSize = true;
			this->lz_drp_factory_N0000->Location = System::Drawing::Point(1142, 420);
			this->lz_drp_factory_N0000->Name = L"lz_drp_factory_N0000";
			this->lz_drp_factory_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_factory_N0000->TabIndex = 69;
			this->lz_drp_factory_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_lab_S0000
			// 
			this->lz_drp_lab_S0000->AutoSize = true;
			this->lz_drp_lab_S0000->Location = System::Drawing::Point(1215, 365);
			this->lz_drp_lab_S0000->Name = L"lz_drp_lab_S0000";
			this->lz_drp_lab_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_lab_S0000->TabIndex = 70;
			this->lz_drp_lab_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_lab_W0000
			// 
			this->lz_drp_lab_W0000->AutoSize = true;
			this->lz_drp_lab_W0000->Location = System::Drawing::Point(1264, 279);
			this->lz_drp_lab_W0000->Name = L"lz_drp_lab_W0000";
			this->lz_drp_lab_W0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_lab_W0000->TabIndex = 71;
			this->lz_drp_lab_W0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_labWest_W0000
			// 
			this->lz_drp_labWest_W0000->AutoSize = true;
			this->lz_drp_labWest_W0000->Location = System::Drawing::Point(1183, 252);
			this->lz_drp_labWest_W0000->Name = L"lz_drp_labWest_W0000";
			this->lz_drp_labWest_W0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_labWest_W0000->TabIndex = 72;
			this->lz_drp_labWest_W0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_diamond_N0000
			// 
			this->lz_drp_diamond_N0000->AutoSize = true;
			this->lz_drp_diamond_N0000->Location = System::Drawing::Point(1050, 220);
			this->lz_drp_diamond_N0000->Name = L"lz_drp_diamond_N0000";
			this->lz_drp_diamond_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_diamond_N0000->TabIndex = 73;
			this->lz_drp_diamond_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_diamond_I0000
			// 
			this->lz_drp_diamond_I0000->AutoSize = true;
			this->lz_drp_diamond_I0000->Location = System::Drawing::Point(1071, 279);
			this->lz_drp_diamond_I0000->Name = L"lz_drp_diamond_I0000";
			this->lz_drp_diamond_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_diamond_I0000->TabIndex = 74;
			this->lz_drp_diamond_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_diamondWest_S0000
			// 
			this->lz_drp_diamondWest_S0000->AutoSize = true;
			this->lz_drp_diamondWest_S0000->Location = System::Drawing::Point(961, 286);
			this->lz_drp_diamondWest_S0000->Name = L"lz_drp_diamondWest_S0000";
			this->lz_drp_diamondWest_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_diamondWest_S0000->TabIndex = 75;
			this->lz_drp_diamondWest_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_diamondSouth_W0000
			// 
			this->lz_drp_diamondSouth_W0000->AutoSize = true;
			this->lz_drp_diamondSouth_W0000->Location = System::Drawing::Point(979, 327);
			this->lz_drp_diamondSouth_W0000->Name = L"lz_drp_diamondSouth_W0000";
			this->lz_drp_diamondSouth_W0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_diamondSouth_W0000->TabIndex = 76;
			this->lz_drp_diamondSouth_W0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_diamondSouth_S0000
			// 
			this->lz_drp_diamondSouth_S0000->AutoSize = true;
			this->lz_drp_diamondSouth_S0000->Location = System::Drawing::Point(1003, 409);
			this->lz_drp_diamondSouth_S0000->Name = L"lz_drp_diamondSouth_S0000";
			this->lz_drp_diamondSouth_S0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_diamondSouth_S0000->TabIndex = 77;
			this->lz_drp_diamondSouth_S0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_banana_I0000
			// 
			this->lz_drp_banana_I0000->AutoSize = true;
			this->lz_drp_banana_I0000->Location = System::Drawing::Point(923, 190);
			this->lz_drp_banana_I0000->Name = L"lz_drp_banana_I0000";
			this->lz_drp_banana_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_banana_I0000->TabIndex = 78;
			this->lz_drp_banana_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_savannahWest_N0000
			// 
			this->lz_drp_savannahWest_N0000->AutoSize = true;
			this->lz_drp_savannahWest_N0000->Location = System::Drawing::Point(901, 262);
			this->lz_drp_savannahWest_N0000->Name = L"lz_drp_savannahWest_N0000";
			this->lz_drp_savannahWest_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_savannahWest_N0000->TabIndex = 79;
			this->lz_drp_savannahWest_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_bananaSouth_N0000
			// 
			this->lz_drp_bananaSouth_N0000->AutoSize = true;
			this->lz_drp_bananaSouth_N0000->Location = System::Drawing::Point(844, 220);
			this->lz_drp_bananaSouth_N0000->Name = L"lz_drp_bananaSouth_N0000";
			this->lz_drp_bananaSouth_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_bananaSouth_N0000->TabIndex = 80;
			this->lz_drp_bananaSouth_N0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_savannah_I0000
			// 
			this->lz_drp_savannah_I0000->AutoSize = true;
			this->lz_drp_savannah_I0000->Location = System::Drawing::Point(901, 365);
			this->lz_drp_savannah_I0000->Name = L"lz_drp_savannah_I0000";
			this->lz_drp_savannah_I0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_savannah_I0000->TabIndex = 81;
			this->lz_drp_savannah_I0000->UseVisualStyleBackColor = true;
			// 
			// lz_drp_savannahEast_N0000
			// 
			this->lz_drp_savannahEast_N0000->AutoSize = true;
			this->lz_drp_savannahEast_N0000->Location = System::Drawing::Point(911, 400);
			this->lz_drp_savannahEast_N0000->Name = L"lz_drp_savannahEast_N0000";
			this->lz_drp_savannahEast_N0000->Size = System::Drawing::Size(15, 14);
			this->lz_drp_savannahEast_N0000->TabIndex = 82;
			this->lz_drp_savannahEast_N0000->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1349, 898);
			this->Controls->Add(this->lz_drp_cliffTownWest_S0000);
			this->Controls->Add(this->lz_drp_cliffTown_S0000);
			this->Controls->Add(this->lz_drp_cliffTown_I0000);
			this->Controls->Add(this->lz_drp_cliffTown_N0000);
			this->Controls->Add(this->lz_drp_fort_W0000);
			this->Controls->Add(this->lz_drp_fort_I0000);
			this->Controls->Add(this->lz_drp_fort_E0000);
			this->Controls->Add(this->lz_drp_bridge_S0000);
			this->Controls->Add(this->lz_drp_slopedTownEast_E0000);
			this->Controls->Add(this->lz_drp_village_W0000);
			this->Controls->Add(this->lz_drp_enemyBase_S0000);
			this->Controls->Add(this->lz_drp_enemyBase_I0000);
			this->Controls->Add(this->lz_drp_enemyBase_N0000);
			this->Controls->Add(this->lz_drp_slopedTown_W0000);
			this->Controls->Add(this->lz_drp_slopedTown_I0000);
			this->Controls->Add(this->lz_drp_slopedTown_E0000);
			this->Controls->Add(this->lz_drp_commFacility_W0000);
			this->Controls->Add(this->lz_drp_commFacility_I0000);
			this->Controls->Add(this->lz_drp_commFacility_S0000);
			this->Controls->Add(this->lz_drp_ruinsNorth_S0000);
			this->Controls->Add(this->lz_drp_field_N0000);
			this->Controls->Add(this->lz_drp_ruins_S0000);
			this->Controls->Add(this->lz_drp_field_I0000);
			this->Controls->Add(this->lz_drp_fieldWest_S0000);
			this->Controls->Add(this->lz_drp_remnants_S0000);
			this->Controls->Add(this->lz_drp_field_W0000);
			this->Controls->Add(this->lz_drp_remnants_I0000);
			this->Controls->Add(this->lz_drp_remnantsNorth_N0000);
			this->Controls->Add(this->lz_drp_remnantsNorth_S0000);
			this->Controls->Add(this->lz_drp_tent_E0000);
			this->Controls->Add(this->lz_drp_tent_I0000);
			this->Controls->Add(this->lz_drp_tent_N0000);
			this->Controls->Add(this->lz_drp_waterway_I0000);
			this->Controls->Add(this->lz_drp_powerPlant_S0000);
			this->Controls->Add(this->lz_drp_powerPlant_E0000);
			this->Controls->Add(this->lz_drp_sovietSouth_S0000);
			this->Controls->Add(this->lz_drp_sovietBase_S0000);
			this->Controls->Add(this->lz_drp_sovietBase_E0000);
			this->Controls->Add(this->lz_drp_sovietBase_N0000);
			this->Controls->Add(this->lz_drp_citadelSouth_S0000);
			this->Controls->Add(this->lz_drp_savannahEast_N0000);
			this->Controls->Add(this->lz_drp_savannah_I0000);
			this->Controls->Add(this->lz_drp_bananaSouth_N0000);
			this->Controls->Add(this->lz_drp_savannahWest_N0000);
			this->Controls->Add(this->lz_drp_banana_I0000);
			this->Controls->Add(this->lz_drp_diamondSouth_S0000);
			this->Controls->Add(this->lz_drp_diamondSouth_W0000);
			this->Controls->Add(this->lz_drp_diamondWest_S0000);
			this->Controls->Add(this->lz_drp_diamond_I0000);
			this->Controls->Add(this->lz_drp_diamond_N0000);
			this->Controls->Add(this->lz_drp_labWest_W0000);
			this->Controls->Add(this->lz_drp_lab_W0000);
			this->Controls->Add(this->lz_drp_lab_S0000);
			this->Controls->Add(this->lz_drp_factory_N0000);
			this->Controls->Add(this->lz_drp_factoryWest_S0000);
			this->Controls->Add(this->lz_drp_hill_N0000);
			this->Controls->Add(this->lz_drp_hill_E0000);
			this->Controls->Add(this->lz_drp_hill_I0000);
			this->Controls->Add(this->lz_drp_hillWest_S0000);
			this->Controls->Add(this->lz_drp_hillSouth_W0000);
			this->Controls->Add(this->lz_drp_pfCamp_S0000);
			this->Controls->Add(this->lz_drp_pfCamp_I0000);
			this->Controls->Add(this->lz_drp_pfCamp_N0000);
			this->Controls->Add(this->lz_drp_savannahEast_S0000);
			this->Controls->Add(this->lz_drp_pfCampNorth_S0000);
			this->Controls->Add(this->lz_drp_swamp_S0000);
			this->Controls->Add(this->lz_drp_swamp_I0000);
			this->Controls->Add(this->lz_drp_swampEast_N0000);
			this->Controls->Add(this->lz_drp_swamp_N0000);
			this->Controls->Add(this->lz_drp_outland_S0000);
			this->Controls->Add(this->lz_drp_swamp_W0000);
			this->Controls->Add(this->lz_drp_flowStation_E0000);
			this->Controls->Add(this->lz_drp_flowStation_I0000);
			this->Controls->Add(this->lz_drp_village_N0000);
			this->Controls->Add(this->pictureBoxMap);
			this->Controls->Add(this->labelMissionStartPoint);
			this->Controls->Add(this->textBoxMissionStartPoint);
			this->Controls->Add(this->labelTrig_hotZone);
			this->Controls->Add(this->textBoxTrig_hotZone);
			this->Controls->Add(this->labelTrig_outerZone);
			this->Controls->Add(this->textBoxTrig_outerZone);
			this->Controls->Add(this->labelTrig_innerZone);
			this->Controls->Add(this->textBoxTrig_innerZone);
			this->Controls->Add(this->MissionOptionList);
			this->Controls->Add(this->labelMissionOptions);
			this->Controls->Add(this->labelErrorMapLocation);
			this->Controls->Add(this->comboBoxLocation);
			this->Controls->Add(this->labelMapLocation);
			this->Controls->Add(this->labelErrorMissionCode);
			this->Controls->Add(this->labelErrorFPKFileName);
			this->Controls->Add(this->buttonNextTo);
			this->Controls->Add(this->textBoxMissionCode);
			this->Controls->Add(this->textBoxFPKFileName);
			this->Controls->Add(this->labelMissionCode);
			this->Controls->Add(this->labelFPKFileName);
			this->ForeColor = System::Drawing::Color::Red;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1365, 937);
			this->MinimumSize = System::Drawing::Size(16, 930);
			this->Name = L"MainForm";
			this->Text = L"Mission Companion";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMap))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		#pragma endregion
		List<CheckBox^>^ landingZoneCheckBoxes;

		void InitializeLandingZones() {
			landingZoneCheckBoxes = gcnew List<CheckBox^>();

			// Add each CheckBox to the list
			landingZoneCheckBoxes->Add(this->lz_drp_citadelSouth_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_sovietBase_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_sovietBase_E0000);
			landingZoneCheckBoxes->Add(this->lz_drp_sovietBase_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_sovietSouth_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_powerPlant_E0000);
			landingZoneCheckBoxes->Add(this->lz_drp_powerPlant_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_waterway_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_tent_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_tent_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_tent_E0000);
			landingZoneCheckBoxes->Add(this->lz_drp_remnantsNorth_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_remnantsNorth_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_remnants_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_field_W0000);
			landingZoneCheckBoxes->Add(this->lz_drp_remnants_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_fieldWest_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_field_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_ruins_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_field_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_ruinsNorth_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_commFacility_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_commFacility_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_commFacility_W0000);
			landingZoneCheckBoxes->Add(this->lz_drp_village_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_slopedTown_E0000);
			landingZoneCheckBoxes->Add(this->lz_drp_slopedTown_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_slopedTown_W0000);
			landingZoneCheckBoxes->Add(this->lz_drp_enemyBase_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_enemyBase_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_enemyBase_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_village_W0000);
			landingZoneCheckBoxes->Add(this->lz_drp_slopedTownEast_E0000);
			landingZoneCheckBoxes->Add(this->lz_drp_bridge_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_fort_E0000);
			landingZoneCheckBoxes->Add(this->lz_drp_fort_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_fort_W0000);
			landingZoneCheckBoxes->Add(this->lz_drp_cliffTown_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_cliffTown_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_cliffTown_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_cliffTownWest_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_flowStation_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_flowStation_E0000);
			landingZoneCheckBoxes->Add(this->lz_drp_swamp_W0000);
			landingZoneCheckBoxes->Add(this->lz_drp_outland_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_swampEast_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_swamp_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_swamp_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_savannahEast_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_pfCamp_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_pfCamp_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_pfCamp_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_hillSouth_W0000);
			landingZoneCheckBoxes->Add(this->lz_drp_hillWest_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_hill_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_hill_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_factoryWest_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_factory_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_lab_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_lab_W0000);
			landingZoneCheckBoxes->Add(this->lz_drp_labWest_W0000);
			landingZoneCheckBoxes->Add(this->lz_drp_diamond_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_diamond_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_diamondWest_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_diamondSouth_W0000);
			landingZoneCheckBoxes->Add(this->lz_drp_diamondSouth_S0000);
			landingZoneCheckBoxes->Add(this->lz_drp_banana_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_bananaSouth_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_savannah_I0000);
			landingZoneCheckBoxes->Add(this->lz_drp_savannahEast_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_hill_E0000);
			landingZoneCheckBoxes->Add(this->lz_drp_savannahWest_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_swamp_N0000);
			landingZoneCheckBoxes->Add(this->lz_drp_pfCampNorth_S0000);
		}

		//Add checked Landing Zones to a list

	private:List<String^>^ GetCheckedLandingZones()
	{
		List<String^>^ checkedLZs = gcnew List<String^>();

		for each (CheckBox ^ lz in landingZoneCheckBoxes)
		{
			if (lz->Checked)
			{
				checkedLZs->Add(lz->Name);
			}
		}

		return checkedLZs;
	}

		   //Hide all landing zones checkboxes 
		   void HideAllLandingZoneCheckBox()
		   {
			   for each (CheckBox ^ lz in landingZoneCheckBoxes)
			   {
				   lz->Checked = false;
			   }
			   for each (CheckBox ^ lz in landingZoneCheckBoxes)
			   {
				   lz->Visible = false;
			   }
		   }

	public:bool IsMissionHidden()
	{
		if (this->MissionOptionList->GetItemChecked(0)) {
			return true;
		}
		return false;
	}
		  bool IsEnableOOB()
		  {
			  if (this->MissionOptionList->GetItemChecked(1)) {
				  return true;
			  }
			  return false;
		  }
		  bool SkipMissionPreparetion()
		  {
			  if (this->MissionOptionList->GetItemChecked(2)) {
				  return true;
			  }
			  return false;
		  }
		  bool NoBuddyMenuFromMissionPreparetion()
		  {
			  if (this->MissionOptionList->GetItemChecked(3)) {
				  return true;
			  }
			  return false;
		  }
		  bool NoVehicleMenuFromMissionPreparetion()
		  {
			  if (this->MissionOptionList->GetItemChecked(4)) {
				  return true;
			  }
			  return false;
		  }
		  bool DisableSelectSortieTimeFromMissionPreparetion()
		  {
			  if (this->MissionOptionList->GetItemChecked(5)) {
				  return true;
			  }
			  return false;
		  }
	private:
		bool ValidateFPKFileName()
		{
			if (System::String::IsNullOrWhiteSpace(this->textBoxFPKFileName->Text))
			{
				this->labelErrorFPKFileName->Text = L"FPK name cannot be empty";
				return false;
			}
			if (this->textBoxFPKFileName->Text->Contains(" "))
			{
				this->labelErrorFPKFileName->Text = L"Cannot contain spaces";
				return false;
			}
			if (this->textBoxFPKFileName->Text->Trim()->Length > 16)
			{
				this->labelErrorFPKFileName->Text = L"16 Characters is the max";
				this->textBoxFPKFileName->Text = this->textBoxFPKFileName->Text->Substring(0, 16);
				this->textBoxFPKFileName->SelectionStart = this->textBoxFPKFileName->Text->Length;
				return false;
			}
			if (!System::Text::RegularExpressions::Regex::IsMatch(this->textBoxFPKFileName->Text->Trim(), "^[a-zA-Z-_0-9]+$"))
			{
				this->labelErrorFPKFileName->Text = L"Symbols are not allowed";
				return false;
			}

			this->labelErrorFPKFileName->Text = L"";
			return true;
		}
		bool ValidatetextBoxMissionCode()
		{
			if (System::String::IsNullOrWhiteSpace(this->textBoxMissionCode->Text) || !System::Text::RegularExpressions::Regex::IsMatch(this->textBoxMissionCode->Text->Trim(), "^[0-9]+$"))
			{
				this->labelErrorMissionCode->Text =
					System::String::IsNullOrWhiteSpace(this->textBoxMissionCode->Text)
					? L"MissionCode cannot be empty"
					: L"Only numericals are allowed";
				return false;
			}
			if (System::Convert::ToInt32(this->textBoxMissionCode->Text) < 13000 || System::Convert::ToInt32(this->textBoxMissionCode->Text) > 13999)
			{
				this->labelErrorMissionCode->Text = L"Mission code can only be between 13000 and 13999";
				return false;
			}
			if (this->textBoxMissionCode->Text->Contains(" "))
			{
				this->labelErrorMissionCode->Text = L"Mission code cannot contain spaces";
				return false;
			}
			this->labelErrorMissionCode->Text = L"";
			return true;
		}
		bool ValidatecomboBoxLocation()
		{
			if (System::String::IsNullOrWhiteSpace(this->comboBoxLocation->Text))
			{
				this->labelErrorMapLocation->Text = L"This field cannot be empty";
				return false;
			}
			this->labelErrorMapLocation->Text = L"";
			return true;
		}

		System::Void buttonNextTo_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->labelErrorFPKFileName->Text = L"";
			this->labelErrorMissionCode->Text = L"";
			this->labelErrorMapLocation->Text = L"";

			bool isFPKValid = ValidateFPKFileName();
			bool isMissionCode = ValidatetextBoxMissionCode();
			bool isMapLocation = ValidatecomboBoxLocation();
			void deploymentLocation(System::String ^ missionStartPointget);
			void missionMapParams(System::String ^ trig_innerZone, System::String ^ trig_outerZone, System::String ^ trig_hotZone);
			void missionOptionsFlags(bool IsMissionHidden, bool IsEnableOOB, bool SkipMissionPreparationCheck, bool NoBuddyMenuCheck, bool NoVehicleMenuCheck, bool DisableSortieTimeCheck);
			void generateMission(System::String ^ FPKFileName, System::String ^ MissionCode, System::String ^ MissionMapLocation, System::String ^ landingZones);
			if (isFPKValid && isMissionCode && isMapLocation)
			{


				deploymentLocation(this->textBoxMissionStartPoint->Text);
				missionOptionsFlags(IsMissionHidden(), IsEnableOOB(), SkipMissionPreparetion(), NoBuddyMenuFromMissionPreparetion(), NoVehicleMenuFromMissionPreparetion(), DisableSelectSortieTimeFromMissionPreparetion());
				missionMapParams(this->textBoxTrig_innerZone->Text, this->textBoxTrig_outerZone->Text, this->textBoxTrig_hotZone->Text);
				generateMission(this->textBoxFPKFileName->Text, this->textBoxMissionCode->Text, this->comboBoxLocation->Text, gcnew System::String(TurnLandingZonesToString().c_str()));

			}
			else
			{
				System::Windows::Forms::MessageBox::Show(L"Please address all errors!", L"Error");
			}
		}
		std::string TurnLandingZonesToString()
		{
			List<String^>^ checkedLZs = GetCheckedLandingZones();
			#ifdef _DEBUG
			for each (String ^ lz in checkedLZs) {
				Log("Checked LZ: " + lz);
			}
			#endif
			StringBuilder^ sb = gcnew StringBuilder();

			for each (String ^ lz in checkedLZs)
			{
				sb->Append(lz)->Append("\n");
			}

			if (sb->Length > 0)
			{
				//sb->Remove(sb->Length - 2, 2);
			}

			System::String^ managedString = sb->ToString();
			std::string landingZonesStr = msclr::interop::marshal_as<std::string>(managedString);
			std::string formattedLandingZones = landingZonesStr;

			return formattedLandingZones;
		}
		//when the form is loaded
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		InitializeLandingZones();
		this->MissionOptionList->SetItemChecked(1, true); // enables the out of bound system by default
		HideAllLandingZoneCheckBox();
	}

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void treeView1_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {}

	private: System::Void textBoxFPKFileName_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->textBoxFPKFileName->ForeColor = System::Drawing::Color::Black;
		if (System::String::IsNullOrWhiteSpace(this->textBoxFPKFileName->Text))
		{
			this->labelErrorFPKFileName->Text = L"FPK name cannot be empty";
		}
		else if (this->textBoxFPKFileName->Text->Contains(" "))
		{
			this->labelErrorFPKFileName->Text = L"cannot contain spaces";
		}
		else if (this->textBoxFPKFileName->Text->Trim()->Length > 16)
		{
			this->labelErrorFPKFileName->Text = L"cannot exceed 16 characters";
			this->textBoxFPKFileName->Text = this->textBoxFPKFileName->Text->Substring(0, 16);
			this->textBoxFPKFileName->SelectionStart = this->textBoxFPKFileName->Text->Length;
		}
		else if (!System::Text::RegularExpressions::Regex::IsMatch(this->textBoxFPKFileName->Text->Trim(), "^[a-zA-Z-_0-9]+$"))
		{
			this->labelErrorFPKFileName->Text = L"Symbols are not allowed";
		}
		else
		{
			// Clear the error message if the input is valid
			this->labelErrorFPKFileName->Text = L"";
		}
	}
	private: System::Void textBoxMissionCode_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->textBoxMissionCode->ForeColor = System::Drawing::Color::Black;
		if (System::String::IsNullOrWhiteSpace(this->textBoxMissionCode->Text) || !System::Text::RegularExpressions::Regex::IsMatch(this->textBoxMissionCode->Text->Trim(), "^[0-9]+$"))
		{
			this->labelErrorMissionCode->Text =
				System::String::IsNullOrWhiteSpace(this->textBoxMissionCode->Text)
				? L"MissionCode cannot be empty"
				: L"Only numericals are allowed";

		}
		else if (System::Convert::ToInt32(this->textBoxMissionCode->Text) < 13000 || System::Convert::ToInt32(this->textBoxMissionCode->Text) > 13999)
		{
			this->labelErrorMissionCode->Text = L"Mission code can only be between 13000 and 13999";
		}
		else if (this->textBoxMissionCode->Text->Contains(" "))
		{
			this->labelErrorMissionCode->Text = L"Mission code cannot contain spaces";
		}
		else
		{
			this->labelErrorMissionCode->Text = L"";
		}
	}
	private: System::Void comboBoxLocation_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{

		if (this->comboBoxLocation->Text == "Afghanistan")
		{
			Log("Afghanistan!");
			HideAllLandingZoneCheckBox();

			this->pictureBoxMap->Image = System::Drawing::Image::FromFile("MissionCompanion\\res\\img\\AfghMap.PNG");
			this->lz_drp_citadelSouth_S0000->Visible = true;
			this->lz_drp_sovietBase_E0000->Visible = true;
			this->lz_drp_sovietBase_N0000->Visible = true;
			this->lz_drp_sovietBase_S0000->Visible = true;
			this->lz_drp_sovietSouth_S0000->Visible = true;
			this->lz_drp_powerPlant_E0000->Visible = true;
			this->lz_drp_powerPlant_S0000->Visible = true;
			this->lz_drp_waterway_I0000->Visible = true;
			this->lz_drp_tent_N0000->Visible = true;
			this->lz_drp_tent_I0000->Visible = true;
			this->lz_drp_tent_E0000->Visible = true;
			this->lz_drp_remnantsNorth_S0000->Visible = true;
			this->lz_drp_remnantsNorth_N0000->Visible = true;
			this->lz_drp_remnants_I0000->Visible = true;
			this->lz_drp_field_W0000->Visible = true;
			this->lz_drp_remnants_S0000->Visible = true;
			this->lz_drp_fieldWest_S0000->Visible = true;
			this->lz_drp_field_I0000->Visible = true;
			this->lz_drp_ruins_S0000->Visible = true;
			this->lz_drp_field_N0000->Visible = true;
			this->lz_drp_ruinsNorth_S0000->Visible = true;
			this->lz_drp_commFacility_S0000->Visible = true;
			this->lz_drp_commFacility_I0000->Visible = true;
			this->lz_drp_commFacility_W0000->Visible = true;
			this->lz_drp_village_N0000->Visible = true;
			this->lz_drp_slopedTown_E0000->Visible = true;
			this->lz_drp_slopedTown_I0000->Visible = true;
			this->lz_drp_slopedTown_W0000->Visible = true;
			this->lz_drp_enemyBase_N0000->Visible = true;
			this->lz_drp_enemyBase_I0000->Visible = true;
			this->lz_drp_enemyBase_S0000->Visible = true;
			this->lz_drp_village_W0000->Visible = true;
			this->lz_drp_slopedTownEast_E0000->Visible = true;
			this->lz_drp_bridge_S0000->Visible = true;
			this->lz_drp_fort_E0000->Visible = true;
			this->lz_drp_fort_I0000->Visible = true;
			this->lz_drp_fort_W0000->Visible = true;
			this->lz_drp_cliffTown_N0000->Visible = true;
			this->lz_drp_cliffTown_I0000->Visible = true;
			this->lz_drp_cliffTown_S0000->Visible = true;
			this->lz_drp_cliffTownWest_S0000->Visible = true;
		}
		else if (this->comboBoxLocation->Text == "Africa")
		{
			Log("Africa!");
			HideAllLandingZoneCheckBox();
			this->pictureBoxMap->Image = System::Drawing::Image::FromFile("MissionCompanion\\res\\img\\MafrMap.PNG");
			this->lz_drp_flowStation_I0000->Visible = true;
			this->lz_drp_flowStation_E0000->Visible = true;
			this->lz_drp_swamp_W0000->Visible = true;
			this->lz_drp_outland_S0000->Visible = true;
			this->lz_drp_swamp_N0000->Visible = true;
			this->lz_drp_swampEast_N0000->Visible = true;
			this->lz_drp_swamp_S0000->Visible = true;
			this->lz_drp_pfCampNorth_S0000->Visible = true;
			this->lz_drp_savannahEast_S0000->Visible = true;
			this->lz_drp_pfCamp_N0000->Visible = true;
			this->lz_drp_pfCamp_I0000->Visible = true;
			this->lz_drp_hillSouth_W0000->Visible = true;
			this->lz_drp_hillWest_S0000->Visible = true;
			this->lz_drp_hill_I0000->Visible = true;
			this->lz_drp_hill_E0000->Visible = true;
			this->lz_drp_hill_N0000->Visible = true;
			this->lz_drp_factoryWest_S0000->Visible = true;
			this->lz_drp_factory_N0000->Visible = true;
			this->lz_drp_lab_S0000->Visible = true;
			this->lz_drp_lab_W0000->Visible = true;
			this->lz_drp_labWest_W0000->Visible = true;
			this->lz_drp_diamond_N0000->Visible = true;
			this->lz_drp_diamond_I0000->Visible = true;
			this->lz_drp_diamondWest_S0000->Visible = true;
			this->lz_drp_diamondSouth_W0000->Visible = true;
			this->lz_drp_diamondSouth_S0000->Visible = true;
			this->lz_drp_banana_I0000->Visible = true;
			this->lz_drp_savannahWest_N0000->Visible = true;
			this->lz_drp_bananaSouth_N0000->Visible = true;
			this->lz_drp_savannah_I0000->Visible = true;
			this->lz_drp_savannahEast_N0000->Visible = true;
			this->lz_drp_pfCamp_S0000->Visible = true;
		}


		if (System::String::IsNullOrWhiteSpace(this->comboBoxLocation->Text))
		{
			this->labelErrorMapLocation->Text = L"This field cannot be empty";
		}
		else
		{
			this->labelErrorMapLocation->Text = L"";
		}

		List<String^>^ stringList = gcnew List<String^>();
	}
	};
}