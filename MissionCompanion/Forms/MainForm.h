#pragma once

#include <iostream>
#include <cctype>
#include <string>
#include "ExternalLua.h"

namespace MissionCompanion {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
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
















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
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
			this->SuspendLayout();
			// 
			// labelFPKFileName
			// 
			this->labelFPKFileName->AutoSize = true;
			this->labelFPKFileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelFPKFileName->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelFPKFileName->Location = System::Drawing::Point(11, 13);
			this->labelFPKFileName->Name = L"labelFPKFileName";
			this->labelFPKFileName->Size = System::Drawing::Size(112, 18);
			this->labelFPKFileName->TabIndex = 0;
			this->labelFPKFileName->Text = L".FPK FileName:";
			// 
			// labelMissionCode
			// 
			this->labelMissionCode->AutoSize = true;
			this->labelMissionCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMissionCode->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->labelMissionCode->Location = System::Drawing::Point(23, 55);
			this->labelMissionCode->Name = L"labelMissionCode";
			this->labelMissionCode->Size = System::Drawing::Size(100, 18);
			this->labelMissionCode->TabIndex = 1;
			this->labelMissionCode->Text = L"MissionCode:";
			// 
			// textBoxFPKFileName
			// 
			this->textBoxFPKFileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxFPKFileName->ForeColor = System::Drawing::Color::Gray;
			this->textBoxFPKFileName->Location = System::Drawing::Point(130, 10);
			this->textBoxFPKFileName->Name = L"textBoxFPKFileName";
			this->textBoxFPKFileName->Size = System::Drawing::Size(175, 24);
			this->textBoxFPKFileName->TabIndex = 2;
			this->textBoxFPKFileName->Text = L"FPK_Name_Example";
			this->textBoxFPKFileName->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxFPKFileName_TextChanged);
			// 
			// textBoxMissionCode
			// 
			this->textBoxMissionCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBoxMissionCode->ForeColor = System::Drawing::Color::Gray;
			this->textBoxMissionCode->Location = System::Drawing::Point(130, 56);
			this->textBoxMissionCode->Name = L"textBoxMissionCode";
			this->textBoxMissionCode->Size = System::Drawing::Size(92, 24);
			this->textBoxMissionCode->TabIndex = 3;
			this->textBoxMissionCode->Text = L"13000";
			this->textBoxMissionCode->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxMissionCode_TextChanged);
			// 
			// buttonNextTo
			// 
			this->buttonNextTo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonNextTo->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->buttonNextTo->Location = System::Drawing::Point(1002, 583);
			this->buttonNextTo->Name = L"buttonNextTo";
			this->buttonNextTo->Size = System::Drawing::Size(109, 37);
			this->buttonNextTo->TabIndex = 4;
			this->buttonNextTo->Text = L"Next";
			this->buttonNextTo->UseVisualStyleBackColor = true;
			this->buttonNextTo->Click += gcnew System::EventHandler(this, &MainForm::buttonNextTo_Click);
			// 
			// labelErrorFPKFileName
			// 
			this->labelErrorFPKFileName->AutoSize = true;
			this->labelErrorFPKFileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelErrorFPKFileName->Location = System::Drawing::Point(311, 13);
			this->labelErrorFPKFileName->Name = L"labelErrorFPKFileName";
			this->labelErrorFPKFileName->Size = System::Drawing::Size(0, 18);
			this->labelErrorFPKFileName->TabIndex = 5;
			// 
			// labelErrorMissionCode
			// 
			this->labelErrorMissionCode->AutoSize = true;
			this->labelErrorMissionCode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelErrorMissionCode->ForeColor = System::Drawing::Color::Red;
			this->labelErrorMissionCode->Location = System::Drawing::Point(228, 59);
			this->labelErrorMissionCode->Name = L"labelErrorMissionCode";
			this->labelErrorMissionCode->Size = System::Drawing::Size(0, 18);
			this->labelErrorMissionCode->TabIndex = 6;
			// 
			// labelMapLocation
			// 
			this->labelMapLocation->AutoSize = true;
			this->labelMapLocation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelMapLocation->ForeColor = System::Drawing::Color::Black;
			this->labelMapLocation->Location = System::Drawing::Point(54, 99);
			this->labelMapLocation->Name = L"labelMapLocation";
			this->labelMapLocation->Size = System::Drawing::Size(69, 18);
			this->labelMapLocation->TabIndex = 7;
			this->labelMapLocation->Text = L"Location:";
			this->labelMapLocation->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// labelErrorMapLocation
			// 
			this->labelErrorMapLocation->AutoSize = true;
			this->labelErrorMapLocation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelErrorMapLocation->ForeColor = System::Drawing::Color::Red;
			this->labelErrorMapLocation->Location = System::Drawing::Point(257, 103);
			this->labelErrorMapLocation->Name = L"labelErrorMapLocation";
			this->labelErrorMapLocation->Size = System::Drawing::Size(0, 18);
			this->labelErrorMapLocation->TabIndex = 9;
			// 
			// comboBoxLocation
			// 
			this->comboBoxLocation->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxLocation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBoxLocation->FormattingEnabled = true;
			this->comboBoxLocation->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Afghanistan", L"Africa" });
			this->comboBoxLocation->Location = System::Drawing::Point(130, 100);
			this->comboBoxLocation->Name = L"comboBoxLocation";
			this->comboBoxLocation->Size = System::Drawing::Size(121, 26);
			this->comboBoxLocation->TabIndex = 8;
			this->comboBoxLocation->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxLocation_SelectedIndexChanged);
			// 
			// labelMissionOptions
			// 
			this->labelMissionOptions->AutoSize = true;
			this->labelMissionOptions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelMissionOptions->ForeColor = System::Drawing::Color::Black;
			this->labelMissionOptions->Location = System::Drawing::Point(6, 143);
			this->labelMissionOptions->Name = L"labelMissionOptions";
			this->labelMissionOptions->Size = System::Drawing::Size(117, 18);
			this->labelMissionOptions->TabIndex = 11;
			this->labelMissionOptions->Text = L"Mission options:";
			// 
			// MissionOptionList
			// 
			this->MissionOptionList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MissionOptionList->FormattingEnabled = true;
			this->MissionOptionList->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Hide Mission",
				L"out of bounds system (innerZone, outerZone, hotZone)",
				L"No sortie prep",
				L"No buddy select in the sortie",
				L"No vehicle select in the sortie",
				L"Only ASAP as deployment time option"
			});
			this->MissionOptionList->Location = System::Drawing::Point(130, 143);
			this->MissionOptionList->Name = L"MissionOptionList";
			this->MissionOptionList->Size = System::Drawing::Size(338, 100);
			this->MissionOptionList->TabIndex = 12;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1143, 641);
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
			this->Name = L"MainForm";
			this->Text = L"Mission Companion";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		#pragma endregion
		public :bool IsMissionHidden()
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
					this->labelErrorFPKFileName->Text = L"FPK name cannot contain spaces";
					return false;
				}
				if (this->textBoxFPKFileName->Text->Trim()->Length > 16)
				{
					this->labelErrorFPKFileName->Text = L"FPK name cannot exceed 16 characters";
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

				if (isFPKValid && isMissionCode && isMapLocation)
				{
					MissionOptionsFlags(IsMissionHidden(), IsEnableOOB(), SkipMissionPreparetion(), NoBuddyMenuFromMissionPreparetion(), NoVehicleMenuFromMissionPreparetion(), DisableSelectSortieTimeFromMissionPreparetion());
					generateMission(this->textBoxFPKFileName->Text, this->textBoxMissionCode->Text, this->comboBoxLocation->Text);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show(L"Please address all errors!", L"Error");
				}
			}
		//when the form is loaded
		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			
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
				this->labelErrorFPKFileName->Text = L"FPK name cannot contain spaces";
			}
			else if (this->textBoxFPKFileName->Text->Trim()->Length > 16)
			{
				this->labelErrorFPKFileName->Text = L"FPK name cannot exceed 16 characters";
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
			if (System::String::IsNullOrWhiteSpace(this->comboBoxLocation->Text))
			{
				this->labelErrorMapLocation->Text = L"This field cannot be empty";
			}
			else
			{
				this->labelErrorMapLocation->Text = L"";
			}
		}
	};
}
