#pragma once

#include "BibliothequeConsole.h"		// Pour l'afficheur d'erreurs
#include <windows.h>
#include <GL/gl.h>

#include "Conversions.h"
#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"
#include "TIDestructionsSolides.h"
#include "TIColorerSolide.h"
#include "TINormaleFace.h"
#include "TIDecodagesSolides.h"
#include "TIDecodagesFaces.h"
#include "TINormaleFace.h"
#include "BDLumiereAmbiante.h"
#include "BDCreationBoite.h"
#include "BDCreationSphere.h"
#include "BDCreationEllipsoide.h"
#include "BDCreationDodecaedre.h"
#include "BDCreationSpikyDode.h"

#include "OutilPercage.h"
#include "Bielle.h"
#include "SupportRoue.h"
#include "Chassis.h"
#include "Repere3D.h"
#include "AxeEpauleGoupillable.h"
#include "Volant.h"
#include "ArretTriangulaire.h"
#include "Siege.h"
#include "Goupille.h"
#include "AxePiedColonneDirection.h"
#include "PignonStandard.h"
#include "CremaillereStandard.h"
#include "AxeEpaule.h"

#include "karting.h"
#include "FenetreCinematique.h"
//////////////////////////////////////////////////////////////////////////////////////////
//
// Ce fichier définit deux classes : 
// - la classe Form1 qui est l'interface graphique du programme
// - la classe BDAcquisitionPoint qui est une boîte de dialogue pour l'acquisition d'un point
//
// Pour mémoire :
//	- les clôtures sont réalisées par des System::Windows::Forms::PictureBox ^
//	- les boîtes de dialogue pour l'acquisition d'un point héritent de System::Windows::Forms::Form
//  - la barre d'état et la console doivent être créées avec le concepteur d'interface et se nommer
//    BarreEtat (nom par défaut) et LaConsoleGraphique.
//
//////////////////////////////////////////////////////////////////////////////////////////


namespace ApplicationRegainDeBase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private : Karting * kart;
	private: System::Windows::Forms::Button^  button1;
			 FenetreCinematique ^Fen;
			 
	public:
		void AjouterUneLigneALaConsoleGraphique (char *msg)
		{
			LaConsoleGraphique->Visible = true ;
			String ^ch = gcnew String (msg) ;
			this->LaConsoleGraphique->AppendText (ch) ;
		}

		void MontrerLaConsoleGraphique ()
		{
			this->LaConsoleGraphique->Visible = true ;
		}

		void CacherLaConsoleGraphique ()
		{
			this->LaConsoleGraphique->Visible = false ;
		}

		void AfficherDansBarreEtat (char *Msg) 
		{
			BarreEtat->Items[0]->Text = gcnew System::String (Msg) ;
		}

		Form1(void)
		{
			InitializeComponent();

			/////////////////////////////////////////////////////////////////////
			//
			// INITIALISATIONS DE REGAIN, partie 2 (les parties 1 et 3 sont dans le main
			//
			/////////////////////////////////////////////////////////////////////

			// Pour chaque PictureBox (les PictureBox réalisent les clôtures dans 
			// cette version) :
			// - création dans le LGB d'un espace (au sens Regain)
			// - affectation du comportement Regain (menu contextuel et réactions aux événements)

			int NumeroEspace1 = this->CreerEspaceRegain (pictureBox1) ;	// Fonction privée de Form1
			int NumeroEspace2 = this->CreerEspaceRegain (pictureBox2) ; // Fonction privée de Form1

			FondEstNoir = true ;
			FiltreFacesArrieresActif = true ;
			ConsoleEstAffichee = false ;
			kart = NULL ;
			
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
				if(kart != NULL)
					delete kart;
			
			}
		}
	private: bool	FondEstNoir,				// Couleur de fond des fenêtres 3D
					FiltreFacesArrieresActif,	// Activation ou pas du filtre qui élimine les faces arrières
					ConsoleEstAffichee ;		// Pour savoir si la console est visible

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	
	private: System::Windows::Forms::ToolStripMenuItem^  fichierToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  nouveauToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viderChargerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  chargerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viderImportSTLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importSTLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sauverToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportSTLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  quitterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  supprimerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  solideToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  affichageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  debugToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  solidesSimplesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  test1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  test2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fondBlancNoirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colorerUnSolideToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lumiereAmbianteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cacherMontrerLesFacesArrieresToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  repereOnOffToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  consoleOnOffToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  normaleAUneFaceToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  decoderUnSolideToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  decoderUneFaceToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  boiteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sphereToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ellipsoïdeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dodécaèdreToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dodécaèdreÉpineuxToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::StatusStrip^  BarreEtat;
	private: System::Windows::Forms::TextBox^  LaConsoleGraphique;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
private: System::Windows::Forms::ToolStripMenuItem^  test3ToolStripMenuItem;




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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fichierToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nouveauToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viderChargerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chargerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viderImportSTLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importSTLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sauverToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportSTLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->supprimerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->solideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->affichageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fondBlancNoirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorerUnSolideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lumiereAmbianteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cacherMontrerLesFacesArrieresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->repereOnOffToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->debugToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->consoleOnOffToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->normaleAUneFaceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->decoderUnSolideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->decoderUneFaceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->solidesSimplesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->boiteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sphereToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ellipsoïdeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dodécaèdreToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dodécaèdreÉpineuxToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->test1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->test2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->test3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->BarreEtat = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->LaConsoleGraphique = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->BarreEtat->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->fichierToolStripMenuItem, 
				this->supprimerToolStripMenuItem, this->affichageToolStripMenuItem, this->debugToolStripMenuItem, this->solidesSimplesToolStripMenuItem, 
				this->testsToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(748, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fichierToolStripMenuItem
			// 
			this->fichierToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->nouveauToolStripMenuItem, 
				this->viderChargerToolStripMenuItem, this->chargerToolStripMenuItem, this->viderImportSTLToolStripMenuItem, this->importSTLToolStripMenuItem, 
				this->sauverToolStripMenuItem, this->exportSTLToolStripMenuItem, this->quitterToolStripMenuItem});
			this->fichierToolStripMenuItem->Name = L"fichierToolStripMenuItem";
			this->fichierToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->fichierToolStripMenuItem->Text = L"Fichier";
			// 
			// nouveauToolStripMenuItem
			// 
			this->nouveauToolStripMenuItem->Name = L"nouveauToolStripMenuItem";
			this->nouveauToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->nouveauToolStripMenuItem->Text = L"Nouveau";
			this->nouveauToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::nouveauToolStripMenuItem_Click);
			// 
			// viderChargerToolStripMenuItem
			// 
			this->viderChargerToolStripMenuItem->Name = L"viderChargerToolStripMenuItem";
			this->viderChargerToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->viderChargerToolStripMenuItem->Text = L"Vider+Charger";
			this->viderChargerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::viderChargerToolStripMenuItem_Click);
			// 
			// chargerToolStripMenuItem
			// 
			this->chargerToolStripMenuItem->Name = L"chargerToolStripMenuItem";
			this->chargerToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->chargerToolStripMenuItem->Text = L"Charger";
			this->chargerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::chargerToolStripMenuItem_Click);
			// 
			// viderImportSTLToolStripMenuItem
			// 
			this->viderImportSTLToolStripMenuItem->Name = L"viderImportSTLToolStripMenuItem";
			this->viderImportSTLToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->viderImportSTLToolStripMenuItem->Text = L"Vider+Import STL";
			this->viderImportSTLToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::viderImportSTLToolStripMenuItem_Click);
			// 
			// importSTLToolStripMenuItem
			// 
			this->importSTLToolStripMenuItem->Name = L"importSTLToolStripMenuItem";
			this->importSTLToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->importSTLToolStripMenuItem->Text = L"Import STL";
			this->importSTLToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::importSTLToolStripMenuItem_Click);
			// 
			// sauverToolStripMenuItem
			// 
			this->sauverToolStripMenuItem->Name = L"sauverToolStripMenuItem";
			this->sauverToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->sauverToolStripMenuItem->Text = L"Sauver";
			this->sauverToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sauverToolStripMenuItem_Click);
			// 
			// exportSTLToolStripMenuItem
			// 
			this->exportSTLToolStripMenuItem->Name = L"exportSTLToolStripMenuItem";
			this->exportSTLToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->exportSTLToolStripMenuItem->Text = L"Export STL";
			this->exportSTLToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exportSTLToolStripMenuItem_Click);
			// 
			// quitterToolStripMenuItem
			// 
			this->quitterToolStripMenuItem->Name = L"quitterToolStripMenuItem";
			this->quitterToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->quitterToolStripMenuItem->Text = L"Quitter";
			this->quitterToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::quitterToolStripMenuItem_Click);
			// 
			// supprimerToolStripMenuItem
			// 
			this->supprimerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->solideToolStripMenuItem});
			this->supprimerToolStripMenuItem->Name = L"supprimerToolStripMenuItem";
			this->supprimerToolStripMenuItem->Size = System::Drawing::Size(74, 20);
			this->supprimerToolStripMenuItem->Text = L"Supprimer";
			// 
			// solideToolStripMenuItem
			// 
			this->solideToolStripMenuItem->Name = L"solideToolStripMenuItem";
			this->solideToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->solideToolStripMenuItem->Text = L"Supprimer un solide";
			this->solideToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::supprimerUnSolideToolStripMenuItem_Click);
			// 
			// affichageToolStripMenuItem
			// 
			this->affichageToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->fondBlancNoirToolStripMenuItem, 
				this->colorerUnSolideToolStripMenuItem, this->lumiereAmbianteToolStripMenuItem, this->cacherMontrerLesFacesArrieresToolStripMenuItem, 
				this->repereOnOffToolStripMenuItem});
			this->affichageToolStripMenuItem->Name = L"affichageToolStripMenuItem";
			this->affichageToolStripMenuItem->Size = System::Drawing::Size(70, 20);
			this->affichageToolStripMenuItem->Text = L"Affichage";
			// 
			// fondBlancNoirToolStripMenuItem
			// 
			this->fondBlancNoirToolStripMenuItem->Name = L"fondBlancNoirToolStripMenuItem";
			this->fondBlancNoirToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->fondBlancNoirToolStripMenuItem->Text = L"Fond blanc / noir";
			this->fondBlancNoirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fondBlancNoirToolStripMenuItem_Click);
			// 
			// colorerUnSolideToolStripMenuItem
			// 
			this->colorerUnSolideToolStripMenuItem->Name = L"colorerUnSolideToolStripMenuItem";
			this->colorerUnSolideToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->colorerUnSolideToolStripMenuItem->Text = L"Colorer un solide";
			this->colorerUnSolideToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::colorerUnSolideToolStripMenuItem_Click);
			// 
			// lumiereAmbianteToolStripMenuItem
			// 
			this->lumiereAmbianteToolStripMenuItem->Name = L"lumiereAmbianteToolStripMenuItem";
			this->lumiereAmbianteToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->lumiereAmbianteToolStripMenuItem->Text = L"Lumière ambiante";
			this->lumiereAmbianteToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::lumiereAmbianteToolStripMenuItem_Click);
			// 
			// cacherMontrerLesFacesArrieresToolStripMenuItem
			// 
			this->cacherMontrerLesFacesArrieresToolStripMenuItem->Name = L"cacherMontrerLesFacesArrieresToolStripMenuItem";
			this->cacherMontrerLesFacesArrieresToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->cacherMontrerLesFacesArrieresToolStripMenuItem->Text = L"Filtre faces arrières on/off";
			this->cacherMontrerLesFacesArrieresToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::cacherMontrerLesFacesArrieresToolStripMenuItem_Click);
			// 
			// repereOnOffToolStripMenuItem
			// 
			this->repereOnOffToolStripMenuItem->Enabled = false;
			this->repereOnOffToolStripMenuItem->Name = L"repereOnOffToolStripMenuItem";
			this->repereOnOffToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->repereOnOffToolStripMenuItem->Text = L"Repère on / off";
			this->repereOnOffToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::repereOnOffToolStripMenuItem_Click);
			// 
			// debugToolStripMenuItem
			// 
			this->debugToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->consoleOnOffToolStripMenuItem, 
				this->normaleAUneFaceToolStripMenuItem, this->decoderUnSolideToolStripMenuItem, this->decoderUneFaceToolStripMenuItem});
			this->debugToolStripMenuItem->Name = L"debugToolStripMenuItem";
			this->debugToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->debugToolStripMenuItem->Text = L"Debug";
			// 
			// consoleOnOffToolStripMenuItem
			// 
			this->consoleOnOffToolStripMenuItem->Name = L"consoleOnOffToolStripMenuItem";
			this->consoleOnOffToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->consoleOnOffToolStripMenuItem->Text = L"Console on / off";
			this->consoleOnOffToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::consoleOnOffToolStripMenuItem_Click);
			// 
			// normaleAUneFaceToolStripMenuItem
			// 
			this->normaleAUneFaceToolStripMenuItem->Name = L"normaleAUneFaceToolStripMenuItem";
			this->normaleAUneFaceToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->normaleAUneFaceToolStripMenuItem->Text = L"Normale à une face";
			this->normaleAUneFaceToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::normaleAUneFaceToolStripMenuItem_Click);
			// 
			// decoderUnSolideToolStripMenuItem
			// 
			this->decoderUnSolideToolStripMenuItem->Name = L"decoderUnSolideToolStripMenuItem";
			this->decoderUnSolideToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->decoderUnSolideToolStripMenuItem->Text = L"Décoder un solide";
			this->decoderUnSolideToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::decoderUnSolideToolStripMenuItem_Click);
			// 
			// decoderUneFaceToolStripMenuItem
			// 
			this->decoderUneFaceToolStripMenuItem->Name = L"decoderUneFaceToolStripMenuItem";
			this->decoderUneFaceToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->decoderUneFaceToolStripMenuItem->Text = L"Décoder une face";
			this->decoderUneFaceToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::decoderUneFaceToolStripMenuItem_Click);
			// 
			// solidesSimplesToolStripMenuItem
			// 
			this->solidesSimplesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->boiteToolStripMenuItem, 
				this->sphereToolStripMenuItem, this->ellipsoïdeToolStripMenuItem, this->dodécaèdreToolStripMenuItem, this->dodécaèdreÉpineuxToolStripMenuItem});
			this->solidesSimplesToolStripMenuItem->Name = L"solidesSimplesToolStripMenuItem";
			this->solidesSimplesToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			this->solidesSimplesToolStripMenuItem->Text = L"Solides simples";
			// 
			// boiteToolStripMenuItem
			// 
			this->boiteToolStripMenuItem->Name = L"boiteToolStripMenuItem";
			this->boiteToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->boiteToolStripMenuItem->Text = L"Boîte";
			this->boiteToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::boiteToolStripMenuItem_Click);
			// 
			// sphereToolStripMenuItem
			// 
			this->sphereToolStripMenuItem->Name = L"sphereToolStripMenuItem";
			this->sphereToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->sphereToolStripMenuItem->Text = L"Sphère";
			this->sphereToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sphereToolStripMenuItem_Click);
			// 
			// ellipsoïdeToolStripMenuItem
			// 
			this->ellipsoïdeToolStripMenuItem->Name = L"ellipsoïdeToolStripMenuItem";
			this->ellipsoïdeToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->ellipsoïdeToolStripMenuItem->Text = L"Ellipsoïde";
			this->ellipsoïdeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ellipsoïdeToolStripMenuItem_Click);
			// 
			// dodécaèdreToolStripMenuItem
			// 
			this->dodécaèdreToolStripMenuItem->Name = L"dodécaèdreToolStripMenuItem";
			this->dodécaèdreToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->dodécaèdreToolStripMenuItem->Text = L"Dodécaèdre";
			this->dodécaèdreToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::dodécaèdreToolStripMenuItem_Click);
			// 
			// dodécaèdreÉpineuxToolStripMenuItem
			// 
			this->dodécaèdreÉpineuxToolStripMenuItem->Name = L"dodécaèdreÉpineuxToolStripMenuItem";
			this->dodécaèdreÉpineuxToolStripMenuItem->Size = System::Drawing::Size(181, 22);
			this->dodécaèdreÉpineuxToolStripMenuItem->Text = L"Dodécaèdre épineux";
			this->dodécaèdreÉpineuxToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::dodécaèdreÉpineuxToolStripMenuItem_Click);
			// 
			// testsToolStripMenuItem
			// 
			this->testsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->test1ToolStripMenuItem, 
				this->test2ToolStripMenuItem, this->test3ToolStripMenuItem});
			this->testsToolStripMenuItem->Name = L"testsToolStripMenuItem";
			this->testsToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->testsToolStripMenuItem->Text = L"Tests";
			// 
			// test1ToolStripMenuItem
			// 
			this->test1ToolStripMenuItem->Name = L"test1ToolStripMenuItem";
			this->test1ToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->test1ToolStripMenuItem->Text = L"Test1";
			this->test1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::test1ToolStripMenuItem_Click);
			// 
			// test2ToolStripMenuItem
			// 
			this->test2ToolStripMenuItem->Name = L"test2ToolStripMenuItem";
			this->test2ToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->test2ToolStripMenuItem->Text = L"Test2";
			// 
			// test3ToolStripMenuItem
			// 
			this->test3ToolStripMenuItem->Name = L"test3ToolStripMenuItem";
			this->test3ToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->test3ToolStripMenuItem->Text = L"Karting";
			this->test3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::test3ToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(359, 363);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(365, 27);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(370, 363);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// BarreEtat
			// 
			this->BarreEtat->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->BarreEtat->Location = System::Drawing::Point(0, 489);
			this->BarreEtat->Name = L"BarreEtat";
			this->BarreEtat->Size = System::Drawing::Size(748, 22);
			this->BarreEtat->TabIndex = 3;
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(0, 17);
			// 
			// LaConsoleGraphique
			// 
			this->LaConsoleGraphique->AcceptsReturn = true;
			this->LaConsoleGraphique->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->LaConsoleGraphique->Location = System::Drawing::Point(0, 396);
			this->LaConsoleGraphique->Multiline = true;
			this->LaConsoleGraphique->Name = L"LaConsoleGraphique";
			this->LaConsoleGraphique->Size = System::Drawing::Size(748, 93);
			this->LaConsoleGraphique->TabIndex = 4;
			this->LaConsoleGraphique->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(313, 408);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Animer";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			button1->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 511);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->LaConsoleGraphique);
			this->Controls->Add(this->BarreEtat);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Location = System::Drawing::Point(297, 158);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Application Regain";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->BarreEtat->ResumeLayout(false);
			this->BarreEtat->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private :
	System::Void  PreparerPictureBoxPourRegain (System::Windows::Forms::PictureBox ^PB, int NumeroEspace) ;
	// Affecte à PB le menu contextuel de Regain et les réactions aux événements. L'entier passé en paramètre
	// sert à indicer les noms composant créés (le menu contextuel, ses options ...).

	int CreerEspaceRegain (System::Windows::Forms::PictureBox ^PB) ;
	// Fonction de création d'un Espace Regain à partir dune PictureBox fournies en paramètre (c'est la clôture), 
	// d'une vue par défaut et d'un algo de visu par défaut
	// Association du menu contextuel à la clôture.

	int NumeroPictureBox (System::Windows::Forms::PictureBox ^PB) ;
	// Restitue le numéro de la PictureBox reçue en paramètre (1 pour la première, puis 2 ...)

	System::Void pictureBoxRegain_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void pictureBoxRegain_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  DonneesEvenement) ;
	System::Void pictureBoxRegain_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) ;
	System::Void OptionTurnAround_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionZoom_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionLookElsewhere_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionForwardsBackWards_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionTargetSolid_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionTargetFace_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionIAmLost_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionDisplayAllObjects_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionWireframeMode_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionShadedMode_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionCancelCurrentAction_Click(System::Object^  sender, System::EventArgs^  e) ;
	System::Void OptionSnapshot_Click(System::Object^  sender, System::EventArgs^  e) ;

private :
	array<System::Windows::Forms::Form ^>	^TabBD ;
	static int								NombreBdAcqpoint = 0 ;

public :
	int AjouterBDAcqPoint (System::Windows::Forms::Form ^F)
	{
		static	int Pos = 0 ;

		if (NombreBdAcqpoint == 0)
			Pos = 0 ;

		if (Pos > 1000)
			AfficheurErreurs::AfficherErreur ("ATTENTION : il y a plus de 1000 boites de dialogue d'acquisition de points",false) ;

		TabBD->SetValue (F,Pos) ;

		Pos++ ; NombreBdAcqpoint++ ;

		return Pos - 1 ;
	}

	void CacherEtDetruireBDAcqPoint (int NumeroBD)
	{
		CacherBDAcqPoint (NumeroBD) ;
		TabBD->SetValue (nullptr,NumeroBD) ;
		NombreBdAcqpoint -- ;
	}

	void MontrerBDAcqPoint (int NumeroBD)
	{
		(dynamic_cast <System::Windows::Forms::Form ^> (TabBD->GetValue (NumeroBD)))->Show () ;
	}

	void CacherBDAcqPoint (int NumeroBD)
	{
		(dynamic_cast <System::Windows::Forms::Form ^> (TabBD->GetValue (NumeroBD)))->Hide () ;
	}

private: 

	System::Void nouveauToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		LogicielsGraphiquesBase::Defaut ()->ToutEffacer () ;
		ModelesP::Defaut ()->Vider () ;
	}

private: 
	System::Void viderChargerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		LogicielsGraphiquesBase::Defaut ()->ToutEffacer () ;
		ModelesP::Defaut ()->Vider () ;
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		openFileDialog->DefaultExt = "reg" ;
		openFileDialog->Filter = "Regain files (*.reg)|*.reg|Text files (*.txt)|*.txt";
      
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *NomFichier = SystemStringVersCharEtoile (openFileDialog->FileName) ;
			//Paint () ;
			if (strlen (NomFichier) > 0) {
				ModelesP::Defaut ()->Chargement (NomFichier,true /* Remplacement */) ;
				LogicielsGraphiquesBase::Defaut ()->AfficherTousLesSolidesEtFacesIsolees () ;
				LogicielsGraphiquesBase::Defaut ()->CadrageSurScene () ;
			}

			delete [] NomFichier ;
		}
	}

private: System::Void chargerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		openFileDialog->DefaultExt = "reg" ;
		openFileDialog->Filter = "Regain files (*.reg)|*.reg|Text files (*.txt)|*.txt";
      
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *NomFichier = SystemStringVersCharEtoile (openFileDialog->FileName) ;

			if (strlen (NomFichier) > 0) {
				ModelesP::Defaut ()->Chargement (NomFichier,false /* Remplacement */) ;
				LogicielsGraphiquesBase::Defaut ()->AfficherTousLesSolidesEtFacesIsolees () ;
				LogicielsGraphiquesBase::Defaut ()->CadrageSurScene () ;
			}

			delete [] NomFichier ;
		}
	}

private:
	System::Void viderImportSTLToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		LogicielsGraphiquesBase::Defaut ()->ToutEffacer () ;
		ModelesP::Defaut ()->Vider () ;
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		openFileDialog->DefaultExt = "stl" ;
		openFileDialog->Filter = "STL files (*.stl)|*.stl|Text files (*.txt)|*.txt";
      
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *NomFichier = SystemStringVersCharEtoile (openFileDialog->FileName) ;

			if (strlen (NomFichier) > 0) {
				Listes<SolidesP>		LSol ;
				LoadSTLFormat (NomFichier,true,LSol) ;

				if (LSol.Nb_Elements () > 0) {
					LSol.Debut () ;
					do {
						LogicielsGraphiquesBase::Defaut ()->AfficherSolide (LSol.Courant (), -1, false) ;
					} while (LSol.Avance ()) ;
				}

				LogicielsGraphiquesBase::Defaut ()->CadrageSurScene () ;
			}

			delete [] NomFichier ;
		}
	}

private: System::Void importSTLToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
		openFileDialog->DefaultExt = "stl" ;
		openFileDialog->Filter = "STL files (*.stl)|*.stl|Text files (*.txt)|*.txt";
      
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *NomFichier = SystemStringVersCharEtoile (openFileDialog->FileName) ;

			if (strlen (NomFichier) > 0) {
				Listes<SolidesP>		LSol ;
				LoadSTLFormat (NomFichier,true,LSol) ;

				if (LSol.Nb_Elements () > 0) {
					LSol.Debut () ;
					do {
						LogicielsGraphiquesBase::Defaut ()->AfficherSolide (LSol.Courant (), -1, false) ;
					} while (LSol.Avance ()) ;
				}

				LogicielsGraphiquesBase::Defaut ()->CadrageSurScene () ;
			}

			delete [] NomFichier ;
		}
	}

private: 
	System::Void sauverToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog^ openFileDialog = gcnew SaveFileDialog;
		openFileDialog->DefaultExt = "reg" ;
		openFileDialog->Filter = "Regain files (*.reg)|*.reg|Text files (*.txt)|*.txt";
      
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *NomFichier = SystemStringVersCharEtoile (openFileDialog->FileName) ;

			if (strlen (NomFichier) > 0) {
				ModelesP::Defaut ()->Sauvegarde (NomFichier) ;
			}

			delete [] NomFichier ;
		}
	}

private: 
	System::Void exportSTLToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog^ openFileDialog = gcnew SaveFileDialog;
		openFileDialog->DefaultExt = "stl" ;
		openFileDialog->Filter = "STL files (*.stl)|*.stl|Text files (*.txt)|*.txt";
      
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char *NomFichier = SystemStringVersCharEtoile (openFileDialog->FileName) ;

			if (strlen (NomFichier) > 0) {
				Listes<SolidesP>		LSol = ModelesP::Defaut ()->ListeSolides () ;
				SaveSTLFormat (NomFichier, LSol);
			}

			delete [] NomFichier ;
		}
	}

private: 
	System::Void quitterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close () ;
	 }

private: 
	System::Void supprimerUnSolideToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		TIDestructionsSolides	*TIDS = new TIDestructionsSolides () ;
		TIDS->Traitement () ;
	}

private: 
	System::Void fondBlancNoirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		FondEstNoir = ! FondEstNoir ;

		CouleursRGB *Coul ;
		if (FondEstNoir)
			Coul = PCouleurNoir ;
		else
			Coul = PCouleurBlanc ;

		LogicielsGraphiquesBase::Defaut ()->ModifierCouleurDeFond (Coul,-1) ;
		LogicielsGraphiquesBase::Defaut ()->AfficherTousLesSolidesEtFacesIsolees () ;
	}
private: 
	System::Void colorerUnSolideToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
			AttributsFaces	AF(PM) ;
		
			// Attention : il est important que TIColorerSolide::TIColorerSolide
			// crée une copie de AF (donc le param ne doit pas être une
			// référence) car AF est détruit à la fin de ce bloc, donc avant la
			// fin du traitement interactif
			TIColorerSolide	*TICS = new TIColorerSolide (AF) ;
			TICS->Traitement () ;
		}
	}

private: 
	System::Void lumiereAmbianteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		// Réglage des paramètres du slider pour le réglage de la lumière ambiante
		int	AmbiantActuel = (int)(100*LogicielsGraphiquesBase ::Defaut ()->ConsulterStudio (0).CoefficientAmbiant ()) ;
		ApplicationRegainDeBase::BDLumiereAmbiante	^BD = gcnew ApplicationRegainDeBase::BDLumiereAmbiante (AmbiantActuel) ;

		BD->ShowDialog () ;
	}


private: 
	System::Void cacherMontrerLesFacesArrieresToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		FiltreFacesArrieresActif = ! FiltreFacesArrieresActif ;
		if (FiltreFacesArrieresActif)
			LogicielsGraphiquesBase::Defaut ()->ActiverExploitationFacesArrieres (-1) ;
		else
			LogicielsGraphiquesBase::Defaut ()->DesactiverExploitationFacesArrieres (-1) ;

		LogicielsGraphiquesBase::Defaut ()->Raffraichir () ;
	}

private: 
	System::Void repereOnOffToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}

private: 
	System::Void consoleOnOffToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		ConsoleEstAffichee = ! ConsoleEstAffichee ;

		if (ConsoleEstAffichee)
			NSConsole::Console->MontrerConsole () ;
		else
			NSConsole::Console->CacherConsole () ;
	}

private: 
	System::Void normaleAUneFaceToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		TINormaleFace	*TINF = new TINormaleFace () ;
		TINF->Traitement () ;
	}

private: 
	System::Void decoderUnSolideToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		TIDecodagesSolides	*TIDS = new TIDecodagesSolides () ;
		TIDS->Traitement () ;
	}

private: 
	System::Void decoderUneFaceToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		TIDecodagesFaces	*TIDF = new TIDecodagesFaces () ;
		TIDF->Traitement () ;
	}

private: 
	System::Void boiteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		BDCreationBoite	^BD = gcnew BDCreationBoite () ;
		BD->ShowDialog () ;
	}

private: 
	System::Void sphereToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		BDCreationSphere	^BD = gcnew BDCreationSphere () ;
		BD->ShowDialog () ;
	}

private: 
	System::Void ellipsoïdeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		BDCreationEllipsoide	^BD = gcnew BDCreationEllipsoide () ;
		BD->ShowDialog () ;
	}

private: 
	System::Void dodécaèdreToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		BDCreationDodecaedre	^BD = gcnew BDCreationDodecaedre () ;
		BD->ShowDialog () ;
	}

private: 
	System::Void dodécaèdreÉpineuxToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		BDCreationSpikyDode	^BD = gcnew BDCreationSpikyDode () ;
		BD->ShowDialog () ;
	}

private: 
	System::Void test1ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		char	chaine [100] ;
		int		i = 17 ;
		double	v = 100 ;
		sprintf (chaine,"Dans test2, i vaut %d et v vaut %lf",i,v) ;
		AfficheurErreurs::AfficherErreur (chaine,false) ;
	}

private: 
	System::Void test2ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
	}

private: 
	System::Void test3ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		try{
		/*Chassis chassis;

		Siege siege;
		siege.transposerVers(chassis.getRepere3DFixationSiege());

		ArretTriangulaire arret;
		arret.transposerVers(chassis.getRepere3DFixationArriveeColonneDirection());

		AxePiedColonneDirection axePiedColonneDirection;
		axePiedColonneDirection.transposerVers(arret.getRepere3DEvidement());
		
		Prisme axe;
		axe.transposerVers(axePiedColonneDirection.getRepere3DOppose());

		PignonStandard pignon;
		pignon.transposerVers(axePiedColonneDirection.getRepere3DJointure());
		pignon.rotationSurZ(PI/4);

		Volant volant;
		volant.transposerVers(axe.getRepere3DOppose());

		SupportRoue supportRoueGauche;
		supportRoueGauche.transposerVers(chassis.getPosition3DFixationRoueAvant(true));
		supportRoueGauche.rotationSurZ(PI/2 + PI/5);

		SupportRoue supportRoueDroite = SupportRoue(Repere3D(),5,20,20,5,5,15,3,5,7,3,5,true,&AttributsFaces(PMateriauVert));
		supportRoueDroite.transposerVers(chassis.getPosition3DFixationRoueAvant(false));
		supportRoueDroite.rotationSurZ(-PI/2 + PI/5);

		// CODE TEMPORAIRE : ****
		// TODO : Faire le support et recuperer le repere de celui-ci!
	    Repere3D rep(chassis.getRepere3DFixationSupportCremaillereCentral());
		rep.ModifOrigine(rep.Origine() + 11 * rep.Z() + 3.25 * rep.X() + 7 * rep.Y());
		CremaillereStandard cremaillere;//(rep);
		cremaillere.rotationSurY(-1.42);
		cremaillere.rotationSurX(PI);
		// ****

		Bielle bielleGauche, bielleDroite;
		bielleGauche.transposerVers(supportRoueGauche.getRepere3DFixationBielle());
		bielleGauche.rotationSurZAlesage1(-2*PI/3 - PI/5);

		bielleDroite.transposerVers(supportRoueDroite.getRepere3DFixationBielle());
		bielleDroite.rotationSurZAlesage1(2*PI/3 + PI/5);

		LogicielsGraphiquesBase::Defaut()->AfficherSolide(chassis,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(siege,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(arret,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(axe,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(supportRoueGauche,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(supportRoueDroite,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(bielleGauche,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(bielleDroite,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(volant,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(axePiedColonneDirection,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(pignon,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(cremaillere,-1);*/
			LogicielsGraphiquesBase::Defaut()->ToutEffacer();
			if(kart == NULL)
			{	kart = new Karting();
					Fen = gcnew FenetreCinematique(kart);
				this->kart->DessinerKarting();
				button1->Visible = true;
			}
			else
			{
				Fen->Hide();
				delete Fen;
				Fen = gcnew FenetreCinematique(kart);
				
					this->kart->DessinerKarting();
				button1->Visible = true;
				
			}
	}catch(exception e){
		int o=2;
	}

	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 
				
				delete Fen;
				Fen = gcnew FenetreCinematique(kart);
				 Fen->Show();
			 
			 

		 }
};


//////////////////////////////////////////////////////////////////////////////////////////
//
// Classe BDAcquisitionPoint
//
//////////////////////////////////////////////////////////////////////////////////////////
public ref class BDAcquisitionPoint : public System::Windows::Forms::Form
{
	// A priori, c'est pour les ContextMenus : private: System::ComponentModel::IContainer^	components;
private: 
	System::Windows::Forms::Button^			BoutonValider;
	System::Windows::Forms::Button^			BoutonAnnulerInteraction;
	System::Windows::Forms::TextBox^		TextBoxX;
	System::Windows::Forms::TextBox^		TextBoxY;
	System::Windows::Forms::TextBox^		TextBoxZ;
	System::Windows::Forms::Label^			LabelX;
	System::Windows::Forms::Label^			LabelY;
	System::Windows::Forms::Label^			LabelZ;

public:
	BDAcquisitionPoint(const char *Msg)
	{
		static	int	LargeurTextBox = 84,
					EcartHorizontal = 2,
					EcartVertical = 2 ;

		// Création des composants de la boîte
		this->BoutonValider = (gcnew System::Windows::Forms::Button());
		this->BoutonAnnulerInteraction = (gcnew System::Windows::Forms::Button());
		this->LabelX = (gcnew System::Windows::Forms::Label());
		this->LabelY = (gcnew System::Windows::Forms::Label());
		this->LabelZ = (gcnew System::Windows::Forms::Label());
		this->TextBoxX = (gcnew System::Windows::Forms::TextBox());
		this->TextBoxY = (gcnew System::Windows::Forms::TextBox());
		this->TextBoxZ = (gcnew System::Windows::Forms::TextBox());
		
		this->SuspendLayout();
		
		// LabelX
		this->LabelX->Text = L"X";
		this->LabelX->Name = L"LabelX";
		this->LabelX->AutoSize = true ;
		//this->LabelX->Size = System::Drawing::Size(14, 13);
		this->LabelX->TabStop = false;
		this->LabelX->Location = System::Drawing::Point((LargeurTextBox-14)/2, EcartVertical);
		
		// LabelY
		this->LabelY->Text = L"Y";
		this->LabelY->Name = L"LabelY";
		this->LabelY->AutoSize = true ;
		//this->LabelY->Size = System::Drawing::Size(14, 13);
		this->LabelY->TabStop = false;
		this->LabelY->Location = System::Drawing::Point((LargeurTextBox-14)/2+LargeurTextBox+EcartHorizontal, EcartVertical);

		// LabelZ
		this->LabelZ->Text = L"Z";
		this->LabelZ->Name = L"LabelZ";
		this->LabelZ->AutoSize = true ;
		//this->LabelZ->Size = System::Drawing::Size(14, 13);
		this->LabelZ->TabStop = false;
		this->LabelZ->Location = System::Drawing::Point((LargeurTextBox-14)/2+2*LargeurTextBox+2*EcartHorizontal, EcartVertical);

		// TextBoxX
		this->TextBoxX->AcceptsReturn = false;
		this->TextBoxX->AcceptsTab = false;
		this->TextBoxX->Location = System::Drawing::Point(0,2*EcartVertical+13) ;
		this->TextBoxX->Multiline = false;
		this->TextBoxX->Name = L"TextBoxX";
		this->TextBoxX->ScrollBars = System::Windows::Forms::ScrollBars::None;
		this->TextBoxX->Size = System::Drawing::Size(LargeurTextBox, 20);
		this->TextBoxX->TabIndex = 0;
		this->TextBoxX->Visible = true;

		// TextBoxY
		this->TextBoxY->AcceptsReturn = false;
		this->TextBoxY->AcceptsTab = false;
		this->TextBoxY->Location = System::Drawing::Point(LargeurTextBox+EcartHorizontal,2*EcartVertical+13);
		this->TextBoxY->Multiline = false;
		this->TextBoxY->Name = L"TextBoxY";
		this->TextBoxY->ScrollBars = System::Windows::Forms::ScrollBars::None;
		this->TextBoxY->Size = System::Drawing::Size(LargeurTextBox, 20);
		this->TextBoxY->TabIndex = 1;
		this->TextBoxY->Visible = true;

		// TextBoxZ
		this->TextBoxZ->AcceptsReturn = false;
		this->TextBoxZ->AcceptsTab = false;
		this->TextBoxZ->Location = System::Drawing::Point(2*LargeurTextBox+2*EcartHorizontal,2*EcartVertical+13);
		this->TextBoxZ->Multiline = false;
		this->TextBoxZ->Name = L"TextBoxZ";
		this->TextBoxZ->ScrollBars = System::Windows::Forms::ScrollBars::None;
		this->TextBoxZ->Size = System::Drawing::Size(LargeurTextBox, 20);
		this->TextBoxZ->TabIndex = 2;
		this->TextBoxZ->Visible = true;

		// BoutonValider
		int		LargeurFiche = 3*LargeurTextBox+2*EcartHorizontal,
				LargeurBouton = (LargeurFiche - EcartHorizontal) / 2 ;

		this->BoutonValider->Location = System::Drawing::Point(0, 3*EcartVertical+13+20);
		this->BoutonValider->Name = L"Valider";
		this->BoutonValider->Size = System::Drawing::Size(LargeurBouton, 29);
		this->BoutonValider->TabIndex = 3;
		this->BoutonValider->Text = L"Valider X,Y,Z";
		this->BoutonValider->UseVisualStyleBackColor = true;
		this->BoutonValider->Click += gcnew System::EventHandler(this, &BDAcquisitionPoint::BoutonValider_Click);

		// BoutonAnnulerInteraction
		this->BoutonAnnulerInteraction->Location = System::Drawing::Point((LargeurFiche+EcartHorizontal)/2, 3*EcartVertical+13+20);
		this->BoutonAnnulerInteraction->Name = L"AnnulerInteraction";
		this->BoutonAnnulerInteraction->Size = System::Drawing::Size(LargeurBouton, 29);
		this->BoutonAnnulerInteraction->TabIndex = 4;
		this->BoutonAnnulerInteraction->Text = L"Annuler l'interaction";
		this->BoutonAnnulerInteraction->UseVisualStyleBackColor = true;
		this->BoutonAnnulerInteraction->Click += gcnew System::EventHandler(this, &BDAcquisitionPoint::BoutonAnnulerInteraction_Click);

		// La boîte
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(LargeurFiche, 4*EcartVertical+13+20+29);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow ;
		this->Controls->Add(this->LabelX);
		this->Controls->Add(this->LabelY);
		this->Controls->Add(this->LabelZ);
		this->Controls->Add(this->BoutonValider);
		this->Controls->Add(this->BoutonAnnulerInteraction);
		this->Controls->Add(this->TextBoxX);
		this->Controls->Add(this->TextBoxY);
		this->Controls->Add(this->TextBoxZ);

		this->Name = L"BDAcquisitionPoint";
		this->Text = gcnew System::String (Msg) ; // L"Acquisition d'un point";
		this->ResumeLayout(false);
		this->PerformLayout();
	}

protected:
	/// <summary>
	/// Nettoyage des ressources utilisées.
	/// </summary>
	~BDAcquisitionPoint()
	{
		/*if (components)
		{
			delete components;
		}
		*/
	}

private: 
	System::Void BoutonValider_Click(System::Object^  sender, System::EventArgs^  e) {
			 (*NSConsole::Console) << "Clic sur Bouton Valider" ;
			 try {
				 double	x, y, z ;

				 x = System::Convert::ToDouble (this->TextBoxX->Text) ;
				 y = System::Convert::ToDouble (this->TextBoxY->Text) ;
				 z = System::Convert::ToDouble (this->TextBoxZ->Text) ;
				 (*NSConsole::Console) << "On quitte la BD Point" ;
			 }
			 catch (System::Exception ^)
			 {
				 (*NSConsole::Console) << "Données invalides" ;
			 }
		 }

	System::Void BoutonAnnulerInteraction_Click(System::Object^  sender, System::EventArgs^  e) {
			 (*NSConsole::Console) << "Clic sur Bouton AnnulerInteraction" ;
		 }
};

}

