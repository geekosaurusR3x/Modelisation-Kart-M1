#pragma once
#include "karting.h"
namespace ApplicationRegainDeBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de FenetreCinematique
	/// </summary>
	public ref class FenetreCinematique : public System::Windows::Forms::Form
	{
	private : Karting * kart;
			  int valeurPrec;
	public:
		FenetreCinematique(Karting * LeKart)
		{
			InitializeComponent();
		 this->trackBar1->Enabled = false;
				 this->numericUpDown1->Enabled = true;
				 this->numericUpDown2->Enabled = true;
				 this->numericUpDown3->Enabled = true;
				 kart = LeKart;
				 valeurPrec = 0;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~FenetreCinematique()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label4;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(77, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Angle Minimum";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(77, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Angle Maximum";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(77, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Pas";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(219, 20);
			this->numericUpDown1->Maximum =0;
			this->numericUpDown1->Minimum =-540;
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 3;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(219, 59);
			this->numericUpDown2->Maximum = 540;
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 4;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(219, 97);
			this->numericUpDown3->Minimum = 1;
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 20);
			this->numericUpDown3->TabIndex = 5;
			this->numericUpDown3->Value = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(207, 133);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Valider";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FenetreCinematique::button1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(12, 206);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(557, 45);
			this->trackBar1->TabIndex = 7;
			this->trackBar1->TickFrequency = 2;
			this->trackBar1->Value = 5;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &FenetreCinematique::trackBar1_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(253, 180);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"0";
			// 
			// FenetreCinematique
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(581, 263);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"FenetreCinematique";
			this->Text = L"FenetreCinematique";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 // on desactive les choix et on configure la barre
				this->trackBar1->Enabled = true;
				this->numericUpDown1->Enabled = false;
				this->numericUpDown2->Enabled = false;
				this->numericUpDown3->Enabled = false;
				this->button1->Enabled = false;
				this->trackBar1->SetRange( (int)this->numericUpDown1->Value,(int)this->numericUpDown2->Value);
				
				this->trackBar1->TickFrequency = (int)this->numericUpDown3->Value;
				this->label4->Text = L"0";
				this->trackBar1->Value = 0;
			 }
private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->label4->Text =this->trackBar1->Value.ToString();
			
				kart->Mouvements(((int)this->trackBar1->Value)-this->valeurPrec);
				
			 this->valeurPrec = (int)this->trackBar1->Value;
			kart->rafraichirKarting();
		 }
};
}
