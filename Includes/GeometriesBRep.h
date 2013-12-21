//*****************************************************************************
// 
// Module	: GeometriesBRep
// 
// Fichier	: GeometriesBRep.h
// 
// Auteur	: Lanuel Y.
// 
// Date creat.	: Tue Feb 18 13:36:34 MET 1997
// 
// Version	:
//
// Commentaires	: Interface de la classe GeometriesBRep.
// 	1. Racine de la hierarchie des representations geometriques
//	2. Classe abstraite
// 
//*****************************************************************************
// Includes
// Classe GeometriesBRep
//
//	Constructeurs et destructeur
//
//	Methodes
//		Dupliquer()
//
//	Surcharge des operateurs
//		operator =
//		operator <<
//
//	Partie privee
//		Affiche(ostream&)
//*****************************************************************************

#ifndef __GeometriesBRep__h__
#define	__GeometriesBRep__h__




//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************

#include	<iostream>
using namespace std ;
#include	"EnteteBRepPDLL.h"



//*****************************************************************************
//
// Classe GeometriesBRep
//
//*****************************************************************************


class BREPP_DLL GeometriesBRep
{

public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	GeometriesBRep () ;
	GeometriesBRep (const GeometriesBRep &) ;

virtual ~GeometriesBRep () ;


//*****************************************************************************
//	Methodes
//*****************************************************************************
	// La fonction Dupliquer permet de construire une copie d'une
	// representation geometrique sans en connaitre les details
virtual	GeometriesBRep*		Dupliquer()	const	= 0;


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
 	const GeometriesBRep& 	operator = (const GeometriesBRep &) ;
	bool 			operator== (const GeometriesBRep &) ;
friend 	ostream& BREPP_DLL	operator << (ostream &, const GeometriesBRep &);


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

	//********************************************
	// Cette methode virtuelle permet de ne sur-
	// charger qu'une seule fois l'operateur <<
	// dans la classe de base de la hierarchie
	//********************************************
virtual	void	Affiche(ostream&)	const;

};

#endif	__GeometriesBRep__h__
