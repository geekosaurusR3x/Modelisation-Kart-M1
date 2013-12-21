#ifndef TITurnAroundH
#define TITurnAroundH

#include <iostream> 
using namespace std ;
#include "TraitementsInteractifs.h"
//#include "LGB.h"

class Espaces ;

class TITurnAround : public TraitementsInteractifs
{
public :
	TITurnAround (int) ;
	~TITurnAround () ;
   void Traitement () ;
	void Interruption () ;

private :
	TITurnAround (const TITurnAround &) ;
	const 	TITurnAround&	operator = (const TITurnAround &) ;
	friend 	ostream& 			operator << (ostream &, const TITurnAround &) ;
	friend 	bool 					operator == (const TITurnAround&, const TITurnAround&);

   int		Xprec, Yprec ;
   Espaces	&Espace ;
};


#endif
