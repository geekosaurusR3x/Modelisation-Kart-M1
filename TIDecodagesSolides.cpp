#include "stdafx.h"
#include "TIDecodagesSolides.h"
#include "BibliothequeLGB.h"
#include <fstream>
using namespace std ;

TIDecodagesSolides::TIDecodagesSolides ()
	: TraitementsInteractifs ()
{
}

void TIDecodagesSolides::Traitement ()
{
	switch (phase)
   {
   case 0 : {phase++ ;
   			EnsemblesOptionsDialogue	EOD ;
            EnsemblesMenus				EM ;

            EOD.AjouterOption (LGBDesignationSolide) ;
   			LogicielsGraphiquesBase::Defaut ()->FixerContexteProchaineInteraction ("Montrer le solide à décoder",
            													EOD,
                                          			EM,
                                          			this) ;
            }
            break ;
   case 1 :
				{
            if (LogicielsGraphiquesBase::Defaut ()->ResultatsInteraction.SolideFutDesigne)
            {
            SolidesP	Solide = LogicielsGraphiquesBase::Defaut ()->ResultatsInteraction.SolideDesigne ;
            ofstream f ("DecodageSolide.txt") ;
            Solide.Decode (0,f,true,false) ;
            f.close () ;
            }
            }
            delete this ;
            break ;
   }
}


void TIDecodagesSolides::Interruption ()
{
	// rien à faire : pas de mémoire allouée dynamiquement, ni dans phase 0
   // ni dans phase 1 ;
}


TIDecodagesSolides::~TIDecodagesSolides ()
{
}




TIDecodagesSolides::TIDecodagesSolides (const TIDecodagesSolides &TID)
:	TraitementsInteractifs (TID)
{
}

const TIDecodagesSolides&	TIDecodagesSolides::operator = (const TIDecodagesSolides &O)
{
	if (&O != this)
	{
		(TraitementsInteractifs &)(*this) = O;
	}

	return *this;
}

ostream& 	operator << (ostream & os, const TIDecodagesSolides &TID)
{
	os << "Phase=" << TID.phase << " dans traitement interactif TIDecodage\n" ;
   return os ;
}

bool 	operator == (const TIDecodagesSolides&, const TIDecodagesSolides&)
{
	return false ;
}


