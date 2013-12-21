#ifndef ResultatsInteractions_H
#define ResultatsInteractions_H

#include <iostream> 
using namespace std ;
#include "bibliothequeBRepP.h"
#include "EnteteLGBDLL.h"

class LGB_DLL ResultatsInteractions
{
public :
	ResultatsInteractions () ;

	// les constructeurs par copie, affectation, comparaison, destructeur ... par d�faut
	// sont tr�s bien. Pas besoin de les red�finir.

	friend ostream & operator << (ostream &s, const ResultatsInteractions &o) ;

	Points3D	Point3D ;
	int			xclot,yclot ;
	bool		PointFutLu, PointFutValide, FaceFutDesignee, SolideFutDesigne, SourisFutBougee ;
	SolidesP	SolideDesigne ;
	FacesP		FaceDesignee ;
	int			NumeroEspace ;

private :
} ;


#endif