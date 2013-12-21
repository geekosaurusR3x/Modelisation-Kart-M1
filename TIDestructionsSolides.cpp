#include "stdafx.h"
#include "TIDestructionsSolides.h"
#include "BibliothequeLGB.h"

TIDestructionsSolides::TIDestructionsSolides ()
	: TraitementsInteractifs ()
{
}

void TIDestructionsSolides::Traitement ()
{
	switch (phase)
	{
	case 0 :	{phase++ ;
				EnsemblesOptionsDialogue	EOD ;
				EnsemblesMenus					EM ;

				EOD.AjouterOption (LGBDesignationSolide) ;
				LogicielsGraphiquesBase::Defaut ()->FixerContexteProchaineInteraction ("Montrer le solide à détruire",
																						EOD,
																						EM,
																						this) ;
				}
				break ;
	case 1 :
				SolidesP	Solide = LogicielsGraphiquesBase::Defaut ()->ResultatsInteraction.SolideDesigne ;
				/*
				extern bool RepereEstAffiche ;
				extern SolidesP Repere ;
				if (Solide == Repere)
				RepereEstAffiche = false ;
				*/

				Solide.Detruire () ;
				LogicielsGraphiquesBase::Defaut ()->AfficherTousLesSolidesEtFacesIsolees () ;

				delete this ;
				break ;
	}
}


void TIDestructionsSolides::Interruption ()
{
	// rien à faire : pas de mémoire allouée dynamiquement, ni dans phase 0
   // ni dans phase 1 ;
}


TIDestructionsSolides::~TIDestructionsSolides ()
{
}




TIDestructionsSolides::TIDestructionsSolides (const TIDestructionsSolides &TID)
:	TraitementsInteractifs (TID)
{
}

const TIDestructionsSolides&	TIDestructionsSolides::operator = (const TIDestructionsSolides &O)
{
	if (&O != this)
	{
		(TraitementsInteractifs &)(*this) = O;
	}

	return *this;
}

ostream& 	operator << (ostream & os, const TIDestructionsSolides &TID)
{
	os << "Phase=" << TID.phase << " dans traitement interactif TIDecodage\n" ;
   return os ;
}

bool 	operator == (const TIDestructionsSolides&, const TIDestructionsSolides&)
{
	return false ;
}


