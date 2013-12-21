#ifndef TITargetAtAFaceH
#define TITargetAtAFaceH

#include <iostream> 
using namespace std ;
#include "TraitementsInteractifs.h"
#include "LGB.h"

class TITargetAtAFace : public TraitementsInteractifs
{
public :
	TITargetAtAFace (int numEsp) ;
	~TITargetAtAFace () ;
   void Traitement () ;
	void Interruption () ;

private :
	TITargetAtAFace (const TITargetAtAFace &) ;
	const 	TITargetAtAFace&	operator = (const TITargetAtAFace &) ;
	friend 	ostream& 			operator << (ostream &, const TITargetAtAFace &) ;
	friend 	bool 					operator == (const TITargetAtAFace&, const TITargetAtAFace&);

   int		Xprec, Yprec ;
   Espaces	&Espace ;
};


#endif
