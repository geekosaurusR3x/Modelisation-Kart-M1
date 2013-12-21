#ifndef TINormaleFaceH
#define TINormaleFaceH

#include <iostream>
#include "TraitementsInteractifs.h"

class TINormaleFace : public TraitementsInteractifs
{
public :
	TINormaleFace () ;
	~TINormaleFace () ;
   void Traitement () ;
	void Interruption () ;

private :
	TINormaleFace (const TINormaleFace &) ;
	const 	TINormaleFace&	operator = (const TINormaleFace &) ;
	friend 	ostream& 			operator << (ostream &, const TINormaleFace &) ;
	friend 	bool 					operator == (const TINormaleFace&, const TINormaleFace&);
};


#endif
