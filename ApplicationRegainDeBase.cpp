// ApplicationRegainDeBase.cpp : fichier projet principal.

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
	// Activation des effets visuels de Windows XP avant la création de tout contrôle
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	/////////////////////////////////////////////////////////////////////
	//
	// INITIALISATIONS DE REGAIN, partie 1 ; la partie 3 est un peu
	// plus bas et la partie 2 est dans Form1.h (Form1::Form1)
	//
	/////////////////////////////////////////////////////////////////////

	// Afficheur d'erreur. Il est créé ici car il doit exister pendant toute l'exécution
	AfficheurErreursGraphique	AEG ;
	
	// Initialisation de la taille de l'espace 3D de travail
	ModelesP::Defaut ()->ModifTailleEspaceUtilisateur (Points3D (-1000,-1000,-1000), Points3D (1000,1000,1000)) ;

	// Initialisation du LGB
	LGBCLI::Demarrer () ;

	/////////////////////////////////////////////////////////////////////
	//
	// Interface du programme. CE N'EST PAS UNE INITIALISATION REGAIN. Elle
	// est placée ici plutôt que dans l'appel à Application::Run car l'interface
	// est utile à l'initialisation de la console graphique.
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
	// dans la barre d'état.
	LGBCLI::MemoriserLaFiche (Interface) ;
	
	// S'il y a un argument à la ligne de commande, c'est qu'il y a un fichier à charger :
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

	// Créer la fenêtre principale et l'exécuter
	Application::Run(Interface);

	// Libération de la mémoire occupée par le LGB et le BRep
	LGBCLI::Arreter () ;
	ModelesP::Defaut ()->Vider () ;	
	delete ModelesP::Defaut();

	return 0;
}
