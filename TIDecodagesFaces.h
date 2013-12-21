#ifndef TIDecodagesFacesH
#define TIDecodagesFacesH

#include <iostream>
#include "TraitementsInteractifs.h"

class TIDecodagesFaces : public TraitementsInteractifs
{
public :
	TIDecodagesFaces () ;
	~TIDecodagesFaces () ;
   void Traitement () ;
	void Interruption () ;

private :
	TIDecodagesFaces (const TIDecodagesFaces &) ;
	const 	TIDecodagesFaces&	operator = (const TIDecodagesFaces &) ;
	friend 	ostream& 			operator << (ostream &, const TIDecodagesFaces &) ;
	friend 	bool 					operator == (const TIDecodagesFaces&, const TIDecodagesFaces&);
};


#endif
