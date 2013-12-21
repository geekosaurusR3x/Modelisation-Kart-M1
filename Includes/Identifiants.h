//*****************************************************************************
// 
// Module	: Identifiants
// 
// Fichier	: Identifiants.h
// 
// Auteur	: Lanuel Y.
// 
// Date creat.	: Tue Feb 18 10:26:45 MET 1997
// 
// Version	:
//
// Commentaires	: Interface de la classe Identifiants.
//	1. Racine de la hierarchie des identifiants d'une application.
// 	2. Classe abstraite
// 
//*****************************************************************************
// Includes
// Classe Identifiants
//
//	Constructeurs et destructeur
//		Identifiants (void *) ;
//
//	Accesseurs
//		Cle()
//		EstInitialise()
//		ModifObjet(void*)
//
//	Surcharge des operateurs
//		operator =
//		operator <<
//		operator ==
//		operator !=
//
//	Partie protegee
//*****************************************************************************

#ifndef __Identifiants__h__
#define	__Identifiants__h__

//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************


#include	"TypeCle.h"
#include	"EnteteBRepPDLL.h"

#include	<stdlib.h>
#include	<iostream>
using namespace std ;

//*****************************************************************************
//
// Classe Identifiants
//
//*****************************************************************************

class BREPP_DLL Identifiants
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	Identifiants () ;
	Identifiants (const Identifiants &) ;

	Identifiants (void *) ;

virtual ~Identifiants () ;
virtual void Detruire (void) = 0 ; // libération de l'objet identifié
virtual void Vider (void) = 0 ; // Libération non récursive de l'objet identifié

//*****************************************************************************
//	Accesseurs
//*****************************************************************************

	// La fonction Cle est virtuelle. Tout objet identifiant possede une
	// cle mais ne sachant ou elle se trouve, cette methode ne peut etre
	// implementee. Il faut deriver cette classe
virtual	const TypeCle	Cle()			const ;

	// Un identifiant peut exister sans que l'objet existe (Il le sera sans
	// doute plus tard). La fonction EstInitialise renvoie Vrai si l'objet
	// existe, Faux sinon
inline bool	 	EstInitialise () 	const ;

	// La procedure ModifObjet permet de modifier l'objet identifie.
	// Normalement, cette operation est realisee uniquement sur un
	// identifiant non initialise.
inline void		ModifObjet(void*);

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const Identifiants&	operator = (const Identifiants &) ;
friend 	ostream& BREPP_DLL	operator << (ostream &, const Identifiants &) ;

friend 	bool BREPP_DLL		operator == (const Identifiants&, const Identifiants&);
friend	bool BREPP_DLL		operator != (const Identifiants&, const Identifiants&);
friend	bool BREPP_DLL		operator < (const Identifiants&, const Identifiants&);
friend	bool BREPP_DLL		operator > (const Identifiants&, const Identifiants&);


//*****************************************************************************
//	Partie protegee
//*****************************************************************************
protected :

	void	*objet;

};

#include "Identifiant.inl"

#endif	__Identifiants__h__
