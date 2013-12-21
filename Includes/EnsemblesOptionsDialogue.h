#ifndef EnsemblesOptionsDialogue_h
#define EnsemblesOptionsDialogue_h

#include <iostream> 
using namespace std ;
#include "EnteteLGBDLL.h"

// Attention : dans l'énumération qui suit, la constante LGBOptionFactice
// doit RESTER LA DERNIERE !!
typedef enum {	LGBAcquisitionPointReel,
					LGBAcquisitionPointEcran,
               LGBDesignationFace,
               LGBDesignationSolide,
               LGBMouvementSouris,
               LGBOptionFactice			// Cette constante doit RESTER LA DERNIERE DE L'ENUMERATION !!
				 } LGB_DLL LGBTypeOptionDialogue ;

class LGB_DLL EnsemblesOptionsDialogue
{
public :
	EnsemblesOptionsDialogue () ;

	void AjouterOption (LGBTypeOptionDialogue OD) ;
	bool OptionAppartient (LGBTypeOptionDialogue OD) const ;
	void Vider () ;


	EnsemblesOptionsDialogue (const EnsemblesOptionsDialogue &o) ;
	~ EnsemblesOptionsDialogue () ;
	const EnsemblesOptionsDialogue & operator = (const EnsemblesOptionsDialogue &o) ;
	friend ostream & operator << (ostream &s, const EnsemblesOptionsDialogue &o) ;

private :
	friend bool operator == (const EnsemblesOptionsDialogue &o1, const EnsemblesOptionsDialogue &o2) ;

	bool	TableauOptions [LGBOptionFactice] ;
   // un booléen pour chaque constante du type typeOptionDialogue.
   // Le booléen est vrai ssi la cste correspondante est dans l'ensemble.
} ;


#endif