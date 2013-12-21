#ifndef TITargetAtASolidH
#define TITargetAtASolidH

#include <iostream> 
using namespace std ;
#include "TraitementsInteractifs.h"
#include "LGB.h"

class TITargetAtASolid : public TraitementsInteractifs
{
public :
	TITargetAtASolid (int numEsp) ;
	~TITargetAtASolid () ;
   void Traitement () ;
	void Interruption () ;

private :
	TITargetAtASolid (const TITargetAtASolid &) ;
	const 	TITargetAtASolid&	operator = (const TITargetAtASolid &) ;
	friend 	ostream& 			operator << (ostream &, const TITargetAtASolid &) ;
	friend 	bool 					operator == (const TITargetAtASolid&, const TITargetAtASolid&);

   int		Xprec, Yprec ;
   Espaces	&Espace ;
};


#endif
