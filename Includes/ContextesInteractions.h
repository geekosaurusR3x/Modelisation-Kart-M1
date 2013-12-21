#ifndef ContextesInteractions_h
#define ContextesInteractions_h


#include <iostream> 
using namespace std ;
#include "TraitementsInteractifs.h"

class LGB_DLL ContextesInteractions
{
public :
	ContextesInteractions () ;
	~ ContextesInteractions () ;

   bool							AttenteAcquisitionPointReel,
   								AttenteAcquisitionPointEcran,
   								AttenteDesignationFace,
								AttenteDesignationSolide,
								AttenteMouvementSouris ;

   TraitementsInteractifs		*Traitement ;
   char 						*MessageBarreEtat ;
   int							NumeroBoiteDialogueAckPoint ;
								// Chaque bo�te de dialogue pour l'acquisition d'un point est identifi�e
								// par un entier. -1 signifie qu'il n'y pas de bo�te dans cette
								// interaction.
								// C'est le LGB qui a la responsabilit� de construire et d�truire les bo�tes.

	const ContextesInteractions& operator = (const ContextesInteractions &O) ;

private :
	ContextesInteractions (const ContextesInteractions &o) ;
	friend bool operator == (const ContextesInteractions &o1, const ContextesInteractions &o2) ;
	friend ostream & operator << (ostream &s, const ContextesInteractions &o) ;
} ;


#endif