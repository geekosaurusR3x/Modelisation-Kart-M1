#include "stdafx.h"

void CStringEnChar (const CString &Source, char **Dest)
// *Dest est allouée dans la fonction.
// ATTENTION DE PENSER A libérer Dest quand elle est devenue
// inutile : 
//		char * Ch ;
//		CStringEnChar (..., &Ch) ;
//		...
//		delete [] Ch ;
{
	int	i ;

	*Dest = new char [1+Source.GetLength ()] ;

	for (i = 0 ; (*Dest) [i] = (char) (Source [i]) ; i++) ;
}

void CharEnCString (const char *Source, CString *PCh) 
{
	*PCh = CString (Source) ;
	*PCh = Source ;
}