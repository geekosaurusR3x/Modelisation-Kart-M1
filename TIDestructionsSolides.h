#ifndef TIDestructionsSolidesH
#define TIDestructionsSolidesH

#include <iostream>
#include "TraitementsInteractifs.h"

class TIDestructionsSolides : public TraitementsInteractifs
{
public :
	TIDestructionsSolides () ;
	~TIDestructionsSolides () ;
   void Traitement () ;
	void Interruption () ;

private :
	TIDestructionsSolides (const TIDestructionsSolides &) ;
	const 	TIDestructionsSolides&	operator = (const TIDestructionsSolides &) ;
	friend 	ostream& 			operator << (ostream &, const TIDestructionsSolides &) ;
	friend 	bool 					operator == (const TIDestructionsSolides&, const TIDestructionsSolides&);
};


#endif
