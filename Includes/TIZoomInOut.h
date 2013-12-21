#ifndef TIZoomInOutH
#define TIZoomInOutH

#include <iostream> 
using namespace std ;
#include "TraitementsInteractifs.h"
#include "LGB.h"

class TIZoomInOut : public TraitementsInteractifs
{
public :
	TIZoomInOut (int NumEsp) ;
	~TIZoomInOut () ;
   void Traitement () ;
	void Interruption () ;

private :
	TIZoomInOut (const TIZoomInOut &) ;
	const 	TIZoomInOut&	operator = (const TIZoomInOut &) ;
	friend 	ostream& 			operator << (ostream &, const TIZoomInOut &) ;
	friend 	bool 					operator == (const TIZoomInOut&, const TIZoomInOut&);

   int		Xprec, Yprec ;
   Espaces	&Espace ;
};


#endif
