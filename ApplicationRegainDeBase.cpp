// ApplicationRegainDeBase.cpp�: fichier projet principal.

#include "stdafx.h"
#include "Form1.h"

#include "AfficheurErreursGraphique.h"
#include "ConsolesGraphiques.h"
#include "BibliothequeBRepP.h"
#include "LGBCLI.h"

using namespace ApplicationRegainDeBase;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Activation des effets visuels de Windows�XP avant la cr�ation de tout contr�le
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	/////////////////////////////////////////////////////////////////////
	//
	// INITIALISATIONS DE REGAIN, partie 1 ; la partie 3 est un peu
	// plus bas et la partie 2 est dans Form1.h (Form1::Form1)
	//
	/////////////////////////////////////////////////////////////////////

	// Afficheur d'erreur. Il est cr�� ici car il doit exister pendant toute l'ex�cution
	AfficheurErreursGraphique	AEG ;
	
	// Initialisation de la taille de l'espace 3D de travail
	ModelesP::Defaut ()->ModifTailleEspaceUtilisateur (Points3D (-1000,-1000,-1000), Points3D (1000,1000,1000)) ;

	// Initialisation du LGB
	LGBCLI::Demarrer () ;

	/////////////////////////////////////////////////////////////////////
	//
	// Interface du programme. CE N'EST PAS UNE INITIALISATION REGAIN. Elle
	// est plac�e ici plut�t que dans l'appel � Application::Run car l'interface
	// est utile � l'initialisation de la console graphique.
	// ATTENTION : la construction de la fiche (Form1) doit venir APRES celle
	// du LGB car elle appelle LogicielsGraphiquesBase::AjouterEspace
	//
	/////////////////////////////////////////////////////////////////////
	Form1 ^Interface = gcnew Form1() ;

	/////////////////////////////////////////////////////////////////////
	//
	// INITIALISATIONS DE REGAIN, partie 3 ; la partie 2 est dans 
	// Form1.h (Form1::Form1)
	//
	/////////////////////////////////////////////////////////////////////

	// La console pour le mode graphique (APRES l'instanciation de Form1).
	ConsolesGraphiques	CG (Interface) ;
	CG.InitialiserConsoleGlobale (&CG) ;

	// On informe le LGB de la fiche car c'est la fiche qui fournit un service d'affichage
	// dans la barre d'�tat.
	LGBCLI::MemoriserLaFiche (Interface) ;
	
	// S'il y a un argument � la ligne de commande, c'est qu'il y a un fichier � charger :
	// on le charge et on l'affiche
	if (args->Length > 0) {
		char *NomFichier = SystemStringVersCharEtoile (args [0]) ;

		if (strlen (NomFichier) > 0) {
			ModelesP::Defaut ()->Chargement (NomFichier,false /* Remplacement */) ;
			LogicielsGraphiquesBase::Defaut ()->AfficherTousLesSolidesEtFacesIsolees () ;
			LogicielsGraphiquesBase::Defaut ()->CadrageSurScene () ;
		}

		delete [] NomFichier ;
	}

	// Cr�er la fen�tre principale et l'ex�cuter
	Application::Run(Interface);

	// Lib�ration de la m�moire occup�e par le LGB et le BRep
	LGBCLI::Arreter () ;
	ModelesP::Defaut ()->Vider () ;	
	delete ModelesP::Defaut();

	return 0;
}
