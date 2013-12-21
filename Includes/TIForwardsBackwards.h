#ifndef TIForwardsBackwardsH
#define TIForwardsBackwardsH

#include <iostream> 
using namespace std ;
#include "TraitementsInteractifs.h"
#include "LGB.h"

class TIForwardsBackwards : public TraitementsInteractifs
{
public :
	TIForwardsBackwards (int numEsp) ;
	~TIForwardsBackwards () ;
   void Traitement () ;
	void Interruption () ;

private :
	TIForwardsBackwards (const TIForwardsBackwards &) ;
	const 	TIForwardsBackwards&	operator = (const TIForwardsBackwards &) ;
	friend 	ostream& 			operator << (ostream &, const TIForwardsBackwards &) ;
	friend 	bool 					operator == (const TIForwardsBackwards&, const TIForwardsBackwards&);

   int		Xprec, Yprec ;
   Espaces	&Espace ;
};


#endif
