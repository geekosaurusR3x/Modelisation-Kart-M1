#pragma once

#include "BibliothequeLGB.h"

namespace ApplicationRegainDeBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de BDLumiereAmbiante
	/// </summary>
	public ref class BDLumiereAmbiante : public System::Windows::Forms::Form
	{
	public:
		BDLumiereAmbiante(int ValeurInitiale)
		{
			InitializeComponent();

			//
			//TODO: ajoutez ici le code du constructeur
			//
			this->numericUpDown1->Value = ValeurInitiale ;
			this->numericUpDown1->Minimum = 0 ;
			this->numericUpDown1->Maximum = 100 ;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~BDLumiereAmbiante()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	protected: 
	private: System::Windows::Forms::Button^  BoutonOKAmbiant;

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
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->BoutonOKAmbiant = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(7, 16);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(67, 20);
			this->numericUpDown1->TabIndex = 0;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &BDLumiereAmbiante::numericUpDown1_ValueChanged);
			this->numericUpDown1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &BDLumiereAmbiante::numericUpDown1_KeyUp);
			// 
			// BoutonOKAmbiant
			// 
			this->BoutonOKAmbiant->Location = System::Drawing::Point(97, 7);
			this->BoutonOKAmbiant->Name = L"BoutonOKAmbiant";
			this->BoutonOKAmbiant->Size = System::Drawing::Size(88, 35);
			this->BoutonOKAmbiant->TabIndex = 1;
			this->BoutonOKAmbiant->Text = L"OK";
			this->BoutonOKAmbiant->UseVisualStyleBackColor = true;
			this->BoutonOKAmbiant->Click += gcnew System::EventHandler(this, &BDLumiereAmbiante::BoutonOKAmbiant_Click);
			// 
			// BDLumiereAmbiante
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(214, 68);
			this->ControlBox = false;
			this->Controls->Add(this->BoutonOKAmbiant);
			this->Controls->Add(this->numericUpDown1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"BDLumiereAmbiante";
			this->Text = L"Réglage de la lumière ambiante";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BoutonOKAmbiant_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close () ;
			 }
	private: 

	// Reaction à une modif de la valeur à l'aide des ascenseur
	System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		int P = (int) this->numericUpDown1->Value ;

		if (P < 0)
			P = 0 ;
		else if (P > 100)
			P = 100 ;

		for (int i = 0 ; i < LogicielsGraphiquesBase ::Defaut ()->NombreEspaces () ; i++) {
			Studios S = LogicielsGraphiquesBase ::Defaut ()->ConsulterStudio (i) ;
			S.ModifCoefficientAmbiant (P / 100.) ;
			LogicielsGraphiquesBase ::Defaut ()->ModifierStudio (i,S) ;
		}

		LogicielsGraphiquesBase ::Defaut ()->Raffraichir () ;
	}

private: 
	// Réaction à une modif de la valeur à l'aide du clavier. Il faut bien utiliser KeyUp car, dans KeyDown, 
	// la valeur n'est pas encore modifiée (et il y avait aussi un pb avec KeyPressed mais je ne sais plus
	// lequel).
	System::Void numericUpDown1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		//System::Windows::Forms::KeyEventArgs^ Arg = dynamic_cast <System::Windows::Forms::KeyEventArgs^> (e) ;
		numericUpDown1_ValueChanged (sender,e) ;
	}
};
}
