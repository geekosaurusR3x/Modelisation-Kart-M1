#ifndef TILookElseWhereH
#define TILookElseWhereH

#include <iostream> 
using namespace std ;
#include "TraitementsInteractifs.h"
#include "LGB.h"

class TILookElseWhere : public TraitementsInteractifs
{
public :
	TILookElseWhere (int numEsp) ;
	~TILookElseWhere () ;
   void Traitement () ;
	void Interruption () ;

private :
	TILookElseWhere (const TILookElseWhere &) ;
	const 	TILookElseWhere&	operator = (const TILookElseWhere &) ;
	friend 	ostream& 			operator << (ostream &, const TILookElseWhere &) ;
	friend 	bool 					operator == (const TILookElseWhere&, const TILookElseWhere&);

   int		Xprec, Yprec ;
   Espaces	&Espace ;
};


#endif
