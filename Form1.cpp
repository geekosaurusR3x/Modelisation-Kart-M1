// Fonctions appelées dans la gestion de l'interface (Form1.h)

#include "stdafx.h"
#include "BibliothequeConsole.h"
#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"		// Pour AttributsFaces et AttributsSolides
#include "Form1.h"

////////////////////////////////////////////////////////////////////////////////////
//
// OUTILS POUR affecter un menu contextuel Regain à une clôture et pour créer un espace
//
////////////////////////////////////////////////////////////////////////////////////

System::Void  ApplicationRegainDeBase::Form1::PreparerPictureBoxPourRegain (System::Windows::Forms::PictureBox ^PB, int NumeroEspace)
// Affecte à PB le menu contextuel de Regain et les réactions aux événements. L'entier passé en paramètre
// sert à indicer les noms des composant créés (le menu contextuel, ses options, le nom de la PB ...).
{
	// Il faut un container pour les menus contextuels. Comme il n'est plus alloué automatiquement
	// du fait que les menus contextuels ne sont pas construit avec l'interface mais par
	// programme, il faut le contruire par programme.
	if ( ! this->components)
		this->components = (gcnew System::ComponentModel::Container());
			
	// Création du menu contextuel et de ses options (dont les séparateurs)
	System::Windows::Forms::ContextMenuStrip	^MonContextMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
	System::Windows::Forms::ToolStripMenuItem	^OptionTurnAround = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionZoom = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionLookElsewhere = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionForwardsBackwards = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionTargetSolid = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionTargetFace = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionIAmLost = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionDisplayAllObjects = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionWireframeMode = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionShadedMode = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionCancelCurrentAction = (gcnew System::Windows::Forms::ToolStripMenuItem());
	System::Windows::Forms::ToolStripMenuItem	^OptionSnapshot = (gcnew System::Windows::Forms::ToolStripMenuItem());
		
	// Annonce d'une modification de l'interface (pas indispensable mais ça optimise)
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(PB))->BeginInit();
	MonContextMenu->SuspendLayout();
	this->SuspendLayout();

	// PictureBox : couleur de fond et fonctions de réaction aux événements Regain (clic gauche et mouvement souris)
	PB->BackColor = System::Drawing::Color::Black;
	//PB->Location = System::Drawing::Point(3, 101);
	//PB->Size = System::Drawing::Size(317, 218);
	PB->Click += gcnew System::EventHandler(this, &Form1::pictureBoxRegain_Click);
	PB->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBoxRegain_MouseMove);
	PB->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBoxRegain_Paint);
			
	// Ajout des options au menu contextuel et autres param
	MonContextMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) 
									{OptionTurnAround,
									 OptionZoom,
									 OptionLookElsewhere,
									 OptionForwardsBackwards,
									 OptionTargetSolid,
									 OptionTargetFace,
									 OptionIAmLost,
									 OptionDisplayAllObjects,
									 OptionWireframeMode,
									 OptionShadedMode,
									 OptionCancelCurrentAction,
									 OptionSnapshot});
	MonContextMenu->Name->Format ("MonContextMenuStrip{0}", NumeroEspace) ;
	MonContextMenu->Size = System::Drawing::Size(143, 26);

	// Association du menu contextuel à la PictureBox
	PB->ContextMenuStrip = MonContextMenu ;
	
	// Description des options du menu contextuel
	OptionTurnAround->Name = System::String::Format ("OptionTurnAround_{0}", NumeroEspace);
	OptionTurnAround->Size = System::Drawing::Size(142, 22);
	OptionTurnAround->Text = L"Turn Around";
	OptionTurnAround->Click += gcnew System::EventHandler(this, &Form1::OptionTurnAround_Click);

	OptionZoom->Name = System::String::Format ("OptionZoom_{0}", NumeroEspace) ;
	OptionZoom->Size = System::Drawing::Size(142, 22);
	OptionZoom->Text = L"Zoom in/out";
	OptionZoom->Click += gcnew System::EventHandler(this, &Form1::OptionZoom_Click);

	OptionLookElsewhere->Name = System::String::Format ("OptionLookElsewhere_{0}", NumeroEspace) ;
	OptionLookElsewhere->Size = System::Drawing::Size(142, 22);
	OptionLookElsewhere->Text = L"Look elsewhere";
	OptionLookElsewhere->Click += gcnew System::EventHandler(this, &Form1::OptionLookElsewhere_Click);
	
	OptionForwardsBackwards->Name = System::String::Format ("OptionForwardsBackWards_{0}", NumeroEspace) ;
	OptionForwardsBackwards->Size = System::Drawing::Size(142, 22);
	OptionForwardsBackwards->Text = L"Forwards/backwards";
	OptionForwardsBackwards->Click += gcnew System::EventHandler(this, &Form1::OptionForwardsBackWards_Click);
	
	OptionTargetSolid->Name = System::String::Format ("OptionTargetSolid_{0}", NumeroEspace) ;
	OptionTargetSolid->Size = System::Drawing::Size(142, 22);
	OptionTargetSolid->Text = L"Focus on a solid";
	OptionTargetSolid->Click += gcnew System::EventHandler(this, &Form1::OptionTargetSolid_Click);
	
	OptionTargetFace->Name = System::String::Format ("OptionTargetFace_{0}", NumeroEspace) ;
	OptionTargetFace->Size = System::Drawing::Size(142, 22);
	OptionTargetFace->Text = L"Focus on a face";
	OptionTargetFace->Click += gcnew System::EventHandler(this, &Form1::OptionTargetFace_Click);
	
	OptionIAmLost->Name = System::String::Format ("OptionIAmLost_{0}", NumeroEspace) ;
	OptionIAmLost->Size = System::Drawing::Size(142, 22);
	OptionIAmLost->Text = L"I am lost";
	OptionIAmLost->Click += gcnew System::EventHandler(this, &Form1::OptionIAmLost_Click);
	
	OptionDisplayAllObjects->Name = System::String::Format ("OptionDisplayAllObjects_{0}", NumeroEspace) ;
	OptionDisplayAllObjects->Size = System::Drawing::Size(142, 22);
	OptionDisplayAllObjects->Text = L"Display all objects";
	OptionDisplayAllObjects->Click += gcnew System::EventHandler(this, &Form1::OptionDisplayAllObjects_Click);
	
	OptionWireframeMode->Name = System::String::Format ("OptionWireframeMode_{0}", NumeroEspace) ;
	OptionWireframeMode->Size = System::Drawing::Size(142, 22);
	OptionWireframeMode->Text = L"Wireframe mode";
	OptionWireframeMode->Click += gcnew System::EventHandler(this, &Form1::OptionWireframeMode_Click);
	
	OptionShadedMode->Name = System::String::Format ("OptionShadedMode_{0}", NumeroEspace) ;
	OptionShadedMode->Size = System::Drawing::Size(142, 22);
	OptionShadedMode->Text = L"Shaded mode";
	OptionShadedMode->Click += gcnew System::EventHandler(this, &Form1::OptionShadedMode_Click);
	
	OptionCancelCurrentAction->Name = System::String::Format ("OptionCancelCurrentAction_{0}", NumeroEspace) ;
	OptionCancelCurrentAction->Size = System::Drawing::Size(142, 22);
	OptionCancelCurrentAction->Text = L"Cancel current action";
	OptionCancelCurrentAction->Click += gcnew System::EventHandler(this, &Form1::OptionCancelCurrentAction_Click);
	
	OptionSnapshot->Name = System::String::Format ("OptionSnapshot_{0}", NumeroEspace) ;
	OptionSnapshot->Size = System::Drawing::Size(142, 22);
	OptionSnapshot->Text = L"Snapshot";
	OptionSnapshot->Click += gcnew System::EventHandler(this, &Form1::OptionSnapshot_Click);

	// Fin des modifs de l'interface
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(PB))->EndInit();
	MonContextMenu->ResumeLayout(false);
	this->ResumeLayout(false);
	this->PerformLayout();
}

int ApplicationRegainDeBase::Form1::CreerEspaceRegain (System::Windows::Forms::PictureBox ^PB)
// Fonction de création d'un Espace Regain à partir dune PictureBox fournies en paramètre (c'est la clôture), 
// d'une vue par défaut et d'un algo de visu par défaut
// Association du menu contextuel à la clôture.
{
		HDC	Hdc ;
		int NumEsp = -1 ;
		
		//VERSION 1
		Hdc = GetDC((HWND) PB->Handle.ToPointer());
		if ( ! Hdc)
			AfficheurErreurs::AfficherErreur ("Echec de l'obtention du HDC de PB", true) ;
		else {
			NumEsp = LogicielsGraphiquesBase::Defaut ()->AjouterEspace (	Hdc,
																			(int) (PB->ClientRectangle.Left), (int) (PB->ClientRectangle.Top),
																			(int) (PB->ClientRectangle.Width), (int) (PB->ClientRectangle.Height),
																			(Vues *) NULL, (ZBuffer *) NULL
																		) ;

			PreparerPictureBoxPourRegain (PB,NumEsp) ;
		}

		return NumEsp ;

		// ERREUR : faut libérer le Hdc en fin d'exécution, avec ReleaseDC ()
		// ERREUR : faut libérer hBitmap avec : DeleteObject( hBitmap );
}

////////////////////////////////////////////////////////////////////////////////////
//
// REACTIONS AUX EVENEMENTS CLIC, MOUSEMOVE et PAINT dans une fenêtre regain
//
////////////////////////////////////////////////////////////////////////////////////

System::Void ApplicationRegainDeBase::Form1::pictureBoxRegain_Click (System::Object^  sender, System::EventArgs^  e) 
{
	// ^e est de la classe de base des arguments d'événements. Il faut le caster
	// en un argument d'événement souris.
	System::Windows::Forms::MouseEventArgs ^DonneesEvenement = dynamic_cast <System::Windows::Forms::MouseEventArgs ^> (e) ;

	if (nullptr != DonneesEvenement)
		LogicielsGraphiquesBase::Defaut ()
		->GestionClickSourisCloture (	DonneesEvenement->X,
										DonneesEvenement->Y,
										(System::Windows::Forms::MouseButtons::Left==DonneesEvenement->Button)?0:1,
										NumeroPictureBox ((System::Windows::Forms::PictureBox ^) sender)) ;
	else
		AfficheurErreurs::AfficherErreur ("Echec dynamic_cast dans ApplicationRegainDeBase::Form1::pictureBoxRegain_Click", false) ;
}

System::Void ApplicationRegainDeBase::Form1::pictureBoxRegain_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  DonneesEvenement) 
{
			 if (nullptr != DonneesEvenement)
				 LogicielsGraphiquesBase::Defaut ()
				 ->GestionMouvementSourisCloture (	DonneesEvenement->X,
													DonneesEvenement->Y,
													NumeroPictureBox ((System::Windows::Forms::PictureBox ^) sender)) ;
			 else
				 AfficheurErreurs::AfficherErreur ("Echec dynamic_cast dans Form1::pictureBoxRegain_MouseMove", false) ;
}

System::Void ApplicationRegainDeBase::Form1::pictureBoxRegain_Paint (System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	if (nullptr != (System::Windows::Forms::PictureBox ^) sender) {
		//(*NSConsole::Console) << "Paint dans la cloture " << NumeroPictureBox ((System::Windows::Forms::PictureBox ^) sender) ;
		LogicielsGraphiquesBase::Defaut ()->Rafraichir (NumeroPictureBox ((System::Windows::Forms::PictureBox ^) sender)) ;
	}
	else
		AfficheurErreurs::AfficherErreur ("Echec dynamic_cast dans ApplicationRegainDeBase::Form1::pictureBoxRegain_Paint", false) ;
}


////////////////////////////////////////////////////////////////////////////////////
//
// REACTIONS AUX menus contextuels d'une fenêtre regain
//
////////////////////////////////////////////////////////////////////////////////////

System::Void ApplicationRegainDeBase::Form1::OptionTurnAround_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	// Instanciation et déclenchement du traitement interactif de TurnAround
	TITurnAround	*TITR = new TITurnAround (NumCloture) ;
	TITR->Traitement () ;
}

System::Void ApplicationRegainDeBase::Form1::OptionZoom_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	// Instanciation et déclenchement du traitement interactif de Zoom
	TIZoomInOut	*TI = new TIZoomInOut (NumCloture) ;
	TI->Traitement () ;
}

System::Void ApplicationRegainDeBase::Form1::OptionLookElsewhere_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	// Instanciation et déclenchement du traitement interactif de Zoom
	TILookElseWhere	*TILEW = new TILookElseWhere (NumCloture) ;
	TILEW->Traitement () ;
}

System::Void ApplicationRegainDeBase::Form1::OptionForwardsBackWards_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	// Instanciation et déclenchement du traitement interactif de Zoom
	TIForwardsBackwards	*TIFB = new TIForwardsBackwards (NumCloture) ;
	TIFB->Traitement () ;
}

System::Void ApplicationRegainDeBase::Form1::OptionTargetSolid_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	// Instanciation et déclenchement du traitement interactif de Zoom
	TITargetAtASolid	*TIFB = new TITargetAtASolid (NumCloture) ;
	TIFB->Traitement () ;
}

System::Void ApplicationRegainDeBase::Form1::OptionTargetFace_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	// Instanciation et déclenchement du traitement interactif de Zoom
	TITargetAtAFace	*TI = new TITargetAtAFace (NumCloture) ;
	TI->Traitement () ;
}

System::Void ApplicationRegainDeBase::Form1::OptionIAmLost_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	LogicielsGraphiquesBase::Defaut ()->InitialView (LogicielsGraphiquesBase::Defaut ()->IemeEspace (NumCloture)) ;
}

System::Void ApplicationRegainDeBase::Form1::OptionDisplayAllObjects_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	LogicielsGraphiquesBase::Defaut()->CadrageSurScene (NumCloture) ;
	LogicielsGraphiquesBase::Defaut()->AfficherTousLesSolidesEtFacesIsolees (NumCloture,true) ;
}

System::Void ApplicationRegainDeBase::Form1::OptionWireframeMode_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	LogicielsGraphiquesBase::Defaut ()->ModeFilDeFer (NumCloture) ;
}

System::Void ApplicationRegainDeBase::Form1::OptionShadedMode_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	LogicielsGraphiquesBase::Defaut ()->ModeEclaire (NumCloture) ;
}

System::Void ApplicationRegainDeBase::Form1::OptionCancelCurrentAction_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	// Interruption de l'action interactive en cours
	LogicielsGraphiquesBase::Defaut()->InterruptionTraitementInteractif () ;
}

HBITMAP capturehdc(HDC Hdc,int Largeur,int Hauteur) 
// Construction d'un bitmap qui capture une partie rectangulaire d'un device
{
	HDC			hdcCompatible = CreateCompatibleDC(Hdc);
	HBITMAP		hbm = CreateCompatibleBitmap(Hdc,Largeur, Hauteur);
 
	if (hbm == 0)
		return 0;
 
	if (!SelectObject(hdcCompatible, hbm))
		return 0;
 
	if (!BitBlt(hdcCompatible,0,0,Largeur, Hauteur,	Hdc, 0,0,SRCCOPY))
		return 0;

	DeleteDC (hdcCompatible) ;
 
	return hbm;
}

System::Void ApplicationRegainDeBase::Form1::OptionSnapshot_Click(System::Object^  sender, System::EventArgs^  e)
{
	// Pour retrouver l'option de menu qui a déclenché cette fonction :
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem ^> (sender) ;

	// Pour retrouver le menu contextuel :
	System::Windows::Forms::ContextMenuStrip	^MenuContextuel = dynamic_cast <System::Windows::Forms::ContextMenuStrip ^> (Option->Owner) ;

	// Pour retrouver le PictureBox
	System::Windows::Forms::PictureBox		^PB = dynamic_cast <System::Windows::Forms::PictureBox ^> (MenuContextuel->SourceControl) ;
	
	HBITMAP Hdc = capturehdc (GetDC((HWND) PB->Handle.ToPointer()),PB->Width,PB->Height) ;
	System::Drawing::Bitmap ^BM = System::Drawing::Bitmap::FromHbitmap  ((IntPtr)Hdc) ;
	BM->Save ("ScreenShot.bmp") ;

	delete (BM) ;
	DeleteObject (Hdc) ;
}

int ApplicationRegainDeBase::Form1::NumeroPictureBox (System::Windows::Forms::PictureBox ^PB)
// Restitue le numéro de la PictureBox reçue en paramètre (1 pour la première, puis 2 ...)
{
	// On get le menu contextuel
	System::Windows::Forms::ContextMenuStrip	^MenuCont = PB->ContextMenuStrip ;
				
	// Première option du menu contextuel
	System::Windows::Forms::ToolStripMenuItem	^Option = dynamic_cast <System::Windows::Forms::ToolStripMenuItem	^> (MenuCont->Items [0]) ;
				
	// On construit la chaîne qui commence après le _ dans le nom de l'option et on convertit la chaîne extraite en un entier
	System::Int32	NumCloture = Convert::ToInt32 (Option->Name->Substring (1+Option->Name->IndexOf ('_'))) ;

	return NumCloture ;
}
