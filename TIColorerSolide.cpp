//---------------------------------------------------------------------------
#include "stdafx.h"

#include "TIColorerSolide.h"
#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"


TIColorerSolide::TIColorerSolide (const AttributsFaces AF)
	: TraitementsInteractifs ()
	, mAF (AF)
{
}


void TIColorerSolide::Traitement ()
{
	switch (phase)
	{
	case 0 :	{
				phase++ ;
				EnsemblesOptionsDialogue	EOD ;
				EnsemblesMenus				EM ;

				EOD.AjouterOption (LGBDesignationSolide) ;
				LogicielsGraphiquesBase::Defaut ()->FixerContexteProchaineInteraction ("Montrer le solide à colorer",
																						EOD,
																						EM,
																						this) ;
				}
				break ;
	case 1 :	{
				SolidesP		Solide = LogicielsGraphiquesBase::Defaut ()->ResultatsInteraction.SolideDesigne ;
				unsigned long	i,
								N = Solide.NombreFaces () ;

				for (i = 0 ; i < N ; i++)
					((FacesP) Solide.IemeFace (i)).ModifAttribut (&mAF) ;

				LogicielsGraphiquesBase::Defaut ()->EffacerSolide (Solide,-1) ;
				LogicielsGraphiquesBase::Defaut ()->AfficherSolide (Solide,-1,false) ;

				delete this ;
				}
				break ;
	}
}


void TIColorerSolide::Interruption ()
{
	// rien à faire : pas de mémoire allouée dynamiquement, ni dans phase 0
   // ni dans phase 1 ;
}


TIColorerSolide::~TIColorerSolide ()
{
}

TIColorerSolide::TIColorerSolide (const TIColorerSolide &TID)
:	TraitementsInteractifs (TID)
,	mAF (TID.mAF)
{
}

const TIColorerSolide&	TIColorerSolide::operator = (const TIColorerSolide &O)
{
	if (&O != this)
	{
		(TraitementsInteractifs &)(*this) = O;
	}

	return *this;
}

ostream& 	operator << (ostream & os, const TIColorerSolide &TID)
{
	os << "Phase=" << TID.phase << " dans traitement interactif TIColorerSolide\n" ;
   return os ;
}

bool 	operator == (const TIColorerSolide&, const TIColorerSolide&)
{
	return false ;
}


