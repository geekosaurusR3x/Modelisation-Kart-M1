#ifndef TIColorerSolideH
#define TIColorerSolideH

#include <iostream>
#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"

class TIColorerSolide : public TraitementsInteractifs
{
public :
	TIColorerSolide (const AttributsFaces AF) ;
	~TIColorerSolide () ;
	void Traitement () ;
	void Interruption () ;

private :
	TIColorerSolide (const TIColorerSolide &) ;
	const 	TIColorerSolide&	operator = (const TIColorerSolide &) ;
	friend 	std::ostream& 			operator << (std::ostream &, const TIColorerSolide &) ;
	friend 	bool 					operator == (const TIColorerSolide&, const TIColorerSolide&);

	const AttributsFaces mAF;
};


#endif
