#include "stdafx.h"
#include "TIDecodagesFaces.h"
#include "BibliothequeLGB.h"
#include <fstream>
using namespace std ;

TIDecodagesFaces::TIDecodagesFaces ()
	: TraitementsInteractifs ()
{
}

void TIDecodagesFaces::Traitement ()
{
	switch (phase)
   {
   case 0 : {phase++ ;
   			EnsemblesOptionsDialogue	EOD ;
            EnsemblesMenus					EM ;

            EOD.AjouterOption (LGBDesignationFace) ;
   			LogicielsGraphiquesBase::Defaut ()->FixerContexteProchaineInteraction ("Montrer la face à décoder",
            													EOD,
                                          			EM,
                                          			this) ;
            }
            break ;
   case 1 :
				{
            FacesP	Face = LogicielsGraphiquesBase::Defaut ()->ResultatsInteraction.FaceDesignee ;
            ofstream f ("DecodageFace.txt") ;
            Face.Decode (0,f,true,true) ;
            f.close () ;
            delete this ;
            }
            break ;
   }
}


void TIDecodagesFaces::Interruption ()
{
	// rien à faire : pas de mémoire allouée dynamiquement, ni dans phase 0
   // ni dans phase 1 ;
}


TIDecodagesFaces::~TIDecodagesFaces ()
{
}




TIDecodagesFaces::TIDecodagesFaces (const TIDecodagesFaces &TID)
:	TraitementsInteractifs (TID)
{
}

const TIDecodagesFaces&	TIDecodagesFaces::operator = (const TIDecodagesFaces &O)
{
	if (&O != this)
	{
		(TraitementsInteractifs &)(*this) = O;
	}

	return *this;
}

ostream& 	operator << (ostream & os, const TIDecodagesFaces &TID)
{
	os << "Phase=" << TID.phase << " dans traitement interactif TIDecodage\n" ;
   return os ;
}

bool 	operator == (const TIDecodagesFaces&, const TIDecodagesFaces&)
{
	return false ;
}


