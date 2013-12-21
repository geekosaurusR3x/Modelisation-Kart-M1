#pragma once
#include "BibliothequeLGB.h"

namespace ApplicationRegainDeBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Ces variables devraient être des membres de la classe mais c'est refusé par le compilateur
	// car elle sont non managées, à l'inverse de BDCreationEllipsoide qui DOIT l'être car elle hérite
	// de System::Windows::Forms::Form --> en désespoir de cause, je les mets là.
	extern AttributsFaces		AFEllipsoide ;
	extern AttributsSolides		ASEllipsoide ;
	extern SolidesP				LaEllipsoideConstruite ;
	extern const Materiaux		*PMatEllipsoide ;	// Rappel : on manipule les matériaux au travers de pointeurs

	/// <summary>
	/// Description résumée de BDCreationEllipsoide
	/// </summary>
	public ref class BDCreationEllipsoide : public System::Windows::Forms::Form
	{
	public:
		BDCreationEllipsoide(void)
		{
			InitializeComponent();

			//TODO: ajoutez ici le code du constructeur
			PMatEllipsoide = PMateriauJaune ;
			AFEllipsoide = AttributsFaces	(PMatEllipsoide) ;
			LaEllipsoideConstruite = Ellipsoides (	Points3D (0,0,0),
													*IMonde, *JMonde, 
													40,30,20,
													&ASEllipsoide, &AFEllipsoide) ;
			LogicielsGraphiquesBase::Defaut ()->AfficherSolide (LaEllipsoideConstruite) ;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~BDCreationEllipsoide()
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
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBoxXCentre;
	private: System::Windows::Forms::TextBox^  textBoxYCentre;
	private: System::Windows::Forms::TextBox^  textBoxZCentre;
	private: System::Windows::Forms::TextBox^  textBoxRX;
	private: System::Windows::Forms::TextBox^  textBoxRY;
	private: System::Windows::Forms::TextBox^  textBoxRZ;
	private: System::Windows::Forms::Button^  buttonChangerCouleur;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonAnnuler;

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

//#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxXCentre = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYCentre = (gcnew System::Windows::Forms::TextBox());
			this->textBoxZCentre = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRX = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRZ = (gcnew System::Windows::Forms::TextBox());
			this->buttonChangerCouleur = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonAnnuler = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"X centre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Y centre";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 52);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Z centre";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 75);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Rayon en X";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 98);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Rayon en Y";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 121);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(63, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Rayon en Z";
			// textBoxXCentre
			// 
			this->textBoxXCentre->Location = System::Drawing::Point(86, 3);
			this->textBoxXCentre->Name = L"textBoxXCentre";
			this->textBoxXCentre->Size = System::Drawing::Size(57, 20);
			this->textBoxXCentre->TabIndex = 1;
			this->textBoxXCentre->Text = L"0";
			this->textBoxXCentre->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &BDCreationEllipsoide::textBoxXCentre_KeyUp);
			// 
			// textBoxYCentre
			// 
			this->textBoxYCentre->Location = System::Drawing::Point(86, 26);
			this->textBoxYCentre->Name = L"textBoxYCentre";
			this->textBoxYCentre->Size = System::Drawing::Size(57, 20);
			this->textBoxYCentre->TabIndex = 1;
			this->textBoxYCentre->Text = L"0";
			this->textBoxYCentre->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &BDCreationEllipsoide::textBoxXCentre_KeyUp);
			// 
			// textBoxZCentre
			// 
			this->textBoxZCentre->Location = System::Drawing::Point(86, 49);
			this->textBoxZCentre->Name = L"textBoxZCentre";
			this->textBoxZCentre->Size = System::Drawing::Size(57, 20);
			this->textBoxZCentre->TabIndex = 1;
			this->textBoxZCentre->Text = L"0";
			this->textBoxZCentre->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &BDCreationEllipsoide::textBoxXCentre_KeyUp);
			// 
			// textBoxRayonX
			// 
			this->textBoxRX->Location = System::Drawing::Point(86, 73);
			this->textBoxRX->Name = L"textBoxRX";
			this->textBoxRX->Size = System::Drawing::Size(57, 20);
			this->textBoxRX->TabIndex = 1;
			this->textBoxRX->Text = L"40";
			this->textBoxRX->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &BDCreationEllipsoide::textBoxXCentre_KeyUp);
			// 
			// textBoxRayonY
			// 
			this->textBoxRY->Location = System::Drawing::Point(86, 96);
			this->textBoxRY->Name = L"textBoxRY";
			this->textBoxRY->Size = System::Drawing::Size(57, 20);
			this->textBoxRY->TabIndex = 1;
			this->textBoxRY->Text = L"30";
			this->textBoxRY->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &BDCreationEllipsoide::textBoxXCentre_KeyUp);
			// 
			// textBoxRayonZ
			// 
			this->textBoxRZ->Location = System::Drawing::Point(86, 119);
			this->textBoxRZ->Name = L"textBoxRZ";
			this->textBoxRZ->Size = System::Drawing::Size(57, 20);
			this->textBoxRZ->TabIndex = 1;
			this->textBoxRZ->Text = L"20";
			this->textBoxRZ->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &BDCreationEllipsoide::textBoxXCentre_KeyUp);
			// 
			// buttonChangerCouleur
			// 
			this->buttonChangerCouleur->Location = System::Drawing::Point(12, 149);
			this->buttonChangerCouleur->Name = L"buttonChangerCouleur";
			this->buttonChangerCouleur->Size = System::Drawing::Size(130, 29);
			this->buttonChangerCouleur->TabIndex = 2;
			this->buttonChangerCouleur->Text = L"Changer la couleur";
			this->buttonChangerCouleur->UseVisualStyleBackColor = true;
			this->buttonChangerCouleur->Click += gcnew System::EventHandler(this, &BDCreationEllipsoide::buttonChangerCouleur_Click);
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(168, 12);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(112, 127);
			this->buttonOK->TabIndex = 3;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &BDCreationEllipsoide::buttonOK_Click);
			// 
			// buttonAnnuler
			// 
			this->buttonAnnuler->Location = System::Drawing::Point(168, 149);
			this->buttonAnnuler->Name = L"buttonAnnuler";
			this->buttonAnnuler->Size = System::Drawing::Size(111, 28);
			this->buttonAnnuler->TabIndex = 4;
			this->buttonAnnuler->Text = L"Annuler";
			this->buttonAnnuler->UseVisualStyleBackColor = true;
			this->buttonAnnuler->Click += gcnew System::EventHandler(this, &BDCreationEllipsoide::buttonAnnuler_Click);
			// 
			// BDCreationEllipsoide
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(289, 189);
			this->Controls->Add(this->buttonAnnuler);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonChangerCouleur);
			this->Controls->Add(this->textBoxRX);
			this->Controls->Add(this->textBoxRY);
			this->Controls->Add(this->textBoxRZ);
			this->Controls->Add(this->textBoxZCentre);
			this->Controls->Add(this->textBoxYCentre);
			this->Controls->Add(this->textBoxXCentre);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"BDCreationEllipsoide";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Création d\'un Ellipsoide";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
//#pragma endregion
	private: 
	System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			Close () ;
		}
	
	private: 
	void MettreAJour ()
	// consulte les valeurs dans la boîte de dialogue et, si elles sont valides, remplace la
	// Ellipsoide actuelle par une nouvelle Ellipsoide, avec ces paramètres
	{
		bool	ToutVaBien = true ;
		double	XC, YC, ZC,
				RX, RY, RZ ;
		try {
			XC = Convert::ToDouble (textBoxXCentre->Text),
			YC = Convert::ToDouble (textBoxYCentre->Text),
			ZC = Convert::ToDouble (textBoxZCentre->Text),
			RX = Convert::ToDouble (textBoxRX->Text) ;
			RY = Convert::ToDouble (textBoxRY->Text) ;
			RZ = Convert::ToDouble (textBoxRZ->Text) ;
		}
		catch (System::Exception ^) {
			ToutVaBien = false ;
		}

		if (LaEllipsoideConstruite.EstInitialise ()) {
			LogicielsGraphiquesBase::Defaut ()->EffacerSolide (LaEllipsoideConstruite) ;
			LaEllipsoideConstruite.Detruire () ;
		}
		if (ToutVaBien) {
			LaEllipsoideConstruite = Ellipsoides (	Points3D (XC, YC, ZC), 
													*IMonde, *JMonde, 
													RX, RY, RZ, 
													&ASEllipsoide, &AFEllipsoide) ;
			LogicielsGraphiquesBase::Defaut ()->AfficherSolide (LaEllipsoideConstruite) ;
		}
	}
	
	private: 
	System::Void buttonAnnuler_Click(System::Object^  sender, System::EventArgs^  e) {
		if (LaEllipsoideConstruite.EstInitialise ()) {
			LogicielsGraphiquesBase::Defaut ()->EffacerSolide (LaEllipsoideConstruite) ;
			LaEllipsoideConstruite.Detruire () ;
		}
		Close () ;
	}

	private: 
	System::Void textBoxXCentre_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		MettreAJour () ;
	}

	private: 
	System::Void buttonChangerCouleur_Click(System::Object^  sender, System::EventArgs^  e) {
		// Création de la boîte de dialogue pour le choix d'une couleur
		System::Windows::Forms::ColorDialog	^CD = gcnew System::Windows::Forms::ColorDialog () ;

		// Affichage de la boîte et test de la manière dont elle a été fermée.
		if (CD->ShowDialog () == ::System::Windows::Forms::DialogResult::OK) {
			// La boîte a été fermée avec OK
			int R = (int) CD->Color.R,	// La composante (entre 0 et 255) de rouge
				V = (int) CD->Color.G,
				B = (int) CD->Color.B ;

			CouleursRGB Couleur (R / 255., V / 255., B / 255.) ;
			const Materiaux *PM = Materiaux::CreerMateriau (&Couleur) ;
			AFEllipsoide = AttributsFaces	(PM) ;
		
			MettreAJour () ;
		}
	}

};
}
