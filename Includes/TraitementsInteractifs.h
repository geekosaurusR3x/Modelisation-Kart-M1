#ifndef __TraitementsInteractifs_h__
#define __TraitementsInteractifs_h__

#include	<iostream> 
using namespace std ;
#include "EnteteLGBDLL.h"

class LGB_DLL TraitementsInteractifs
{
public :
	TraitementsInteractifs () ;
	virtual ~TraitementsInteractifs () ;
   virtual void Traitement () = 0 ;
	virtual void Interruption () = 0 ;
	const	TraitementsInteractifs&	operator = (const TraitementsInteractifs &) ;

protected :
	TraitementsInteractifs (const TraitementsInteractifs &) ;
	friend	ostream& operator << (ostream &, const TraitementsInteractifs &) ;
	friend	bool 		operator == (const TraitementsInteractifs&, const TraitementsInteractifs&);

   int	phase ;

private :
};


#endif
