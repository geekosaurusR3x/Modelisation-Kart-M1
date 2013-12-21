#pragma once

//////////////////////////////////////////////////////////////////////////////////
//
//			CLASSE LGB pour l'environnement Windows forms / CLI
//
// Cette classe hérite de LogicielsGraphiquesBase et définit les fonctions 
// virtuelles pures de LogicielsGraphiquesBase à l'aide de ressources spécifiques
// à Windows forms / CLI.
//
// En cas de changement d'environnement, seule cette classe doit être adaptée.
//
//////////////////////////////////////////////////////////////////////////////////


#include "BibliothequeLGB.h"

class LGBCLI : public LogicielsGraphiquesBase {
public :
	virtual void AfficherMessageBarreEtat (char *Msg)
	// Affiche le message dans la barre d'état instanciée par l'application
	// et connue par une classe dérivée.
	{
		mInterface->AfficherDansBarreEtat (Msg) ;
	}

	static void Demarrer () {
		LGBCLI * LGB = new LGBCLI ;
		LogicielsGraphiquesBase::InitialiserUniqueLGB (LGB) ;
	}

	static void Arreter ()
	// Fait le ménage quand le LGB devient inutile, en fin d'application
	{
		delete LogicielsGraphiquesBase::Defaut () ;
	}

	static void MemoriserLaFiche (ApplicationRegainDeBase::Form1 ^F)
	{
		((LGBCLI *) LogicielsGraphiquesBase::Defaut ())->mInterface = F ;
	}

	int ConstruireEtMontrerBDAcqPoint (const char *Msg)
	{
		// C'est 1 peu étonnant que cette fonction ait des instructions et les trois suivantes pas.
		// C'est parce que la classe ApplicationRegainDeBase::BDAcquisitionPoint n'est pas connue
		// de la classe ApplicationRegainDeBase::Form1 (j'ai pas trouvée comment faire une déclaration
		// d'une classe managée).
		int		NumeroBD ;
		
		ApplicationRegainDeBase::BDAcquisitionPoint ^BD = gcnew ApplicationRegainDeBase::BDAcquisitionPoint (Msg) ;
		NumeroBD = mInterface->AjouterBDAcqPoint (BD) ;
		BD->Show () ;

		return NumeroBD ;
	}

	void CacherEtDetruireBDAcqPoint (int NumeroBD)
	{
		mInterface->CacherEtDetruireBDAcqPoint (NumeroBD) ;
	}

	void MontrerBDAcqPoint (int NumeroBD)
	{
		mInterface->MontrerBDAcqPoint (NumeroBD) ;
	}

	void CacherBDAcqPoint (int NumeroBD)
	{
		mInterface->CacherBDAcqPoint (NumeroBD) ;
	}


private :
	LGBCLI () 
	{}

	LGBCLI (const LGBCLI &)
	{}

	~LGBCLI ()
	{
		// Je ne sais pas s'il faut libérer mInterface. 
		// Si c'est le cas, il faut aussi libérer la console graphique.
	}

	gcroot<ApplicationRegainDeBase::Form1 ^>	mInterface ;
} ;
