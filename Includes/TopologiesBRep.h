//*****************************************************************************
// 
// Module	: TopologiesBRep
// 
// Fichier	: TopologiesBRep.h
// 
// Auteur	: Lanuel Y.
// 
// Date creat.	: Tue Feb 18 13:38:16 MET 1997
// 
// Version	:
//
// Commentaires	: Interface de la classe TopologiesBRep.
// 	1. Racine de la hierarchie des representations topologiques
//	2. Classe abstraite
// 
// 
//*****************************************************************************
// Includes
// Classe TopologiesBRep
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

#ifndef __TopologiesBRep__h__
#define __TopologiesBRep__h__




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
// Classe TopologiesBRep
//
//*****************************************************************************

class BREPP_DLL TopologiesBRep
{

public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	TopologiesBRep () ;
	TopologiesBRep (const TopologiesBRep &) ;

virtual ~TopologiesBRep () ;


//*****************************************************************************
//	Methodes
//*****************************************************************************
	// La fonction Dupliquer permet de construire une copie d'une
	// representation topologique sans en connaitre les details
virtual	TopologiesBRep*		Dupliquer()	const	= 0;


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const TopologiesBRep& 	operator = (const TopologiesBRep &) ;
	bool 			operator== (const TopologiesBRep &) ;
friend 	ostream& BREPP_DLL	operator << (ostream &, const TopologiesBRep &);


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



#endif	__TopologiesBRep__h__
