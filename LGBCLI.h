#pragma once

//////////////////////////////////////////////////////////////////////////////////
//
//			CLASSE LGB pour l'environnement Windows forms / CLI
//
// Cette classe h�rite de LogicielsGraphiquesBase et d�finit les fonctions 
// virtuelles pures de LogicielsGraphiquesBase � l'aide de ressources sp�cifiques
// � Windows forms / CLI.
//
// En cas de changement d'environnement, seule cette classe doit �tre adapt�e.
//
//////////////////////////////////////////////////////////////////////////////////


#include "BibliothequeLGB.h"

class LGBCLI : public LogicielsGraphiquesBase {
public :
	virtual void AfficherMessageBarreEtat (char *Msg)
	// Affiche le message dans la barre d'�tat instanci�e par l'application
	// et connue par une classe d�riv�e.
	{
		mInterface->AfficherDansBarreEtat (Msg) ;
	}

	static void Demarrer () {
		LGBCLI * LGB = new LGBCLI ;
		LogicielsGraphiquesBase::InitialiserUniqueLGB (LGB) ;
	}

	static void Arreter ()
	// Fait le m�nage quand le LGB devient inutile, en fin d'application
	{
		delete LogicielsGraphiquesBase::Defaut () ;
	}

	static void MemoriserLaFiche (ApplicationRegainDeBase::Form1 ^F)
	{
		((LGBCLI *) LogicielsGraphiquesBase::Defaut ())->mInterface = F ;
	}

	int ConstruireEtMontrerBDAcqPoint (const char *Msg)
	{
		// C'est 1 peu �tonnant que cette fonction ait des instructions et les trois suivantes pas.
		// C'est parce que la classe ApplicationRegainDeBase::BDAcquisitionPoint n'est pas connue
		// de la classe ApplicationRegainDeBase::Form1 (j'ai pas trouv�e comment faire une d�claration
		// d'une classe manag�e).
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
		// Je ne sais pas s'il faut lib�rer mInterface. 
		// Si c'est le cas, il faut aussi lib�rer la console graphique.
	}

	gcroot<ApplicationRegainDeBase::Form1 ^>	mInterface ;
} ;
