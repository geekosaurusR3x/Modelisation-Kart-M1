#ifndef TIDecodagesSolidesH
#define TIDecodagesSolidesH

#include <iostream>
#include "TraitementsInteractifs.h"

class TIDecodagesSolides : public TraitementsInteractifs
{
public :
	TIDecodagesSolides () ;
	~TIDecodagesSolides () ;
   void Traitement () ;
	void Interruption () ;

private :
	TIDecodagesSolides (const TIDecodagesSolides &) ;
	const 	TIDecodagesSolides&	operator = (const TIDecodagesSolides &) ;
	friend 	ostream& 			operator << (ostream &, const TIDecodagesSolides &) ;
	friend 	bool 					operator == (const TIDecodagesSolides&, const TIDecodagesSolides&);
};


#endif
