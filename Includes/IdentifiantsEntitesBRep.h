//*****************************************************************************
// 
// Module	: IdentifiantsEntitesBRep
// 
// Fichier	: IdentifiantsEntitesBRep.h
// 
// Auteur	: Lanuel Y.
// 
// Date creat.	: Tue Feb 18 11:42:23 MET 1997
// 
// Version	:
//
// Commentaires	: Interface de la classe IdentifiantsEntitesBRep.
//
// Herite de 	: Identifiants
// 
//*****************************************************************************
// Includes
// Classe IdentifiantsEntitesBRep
//
//	Constructeurs et destructeur
//		IdentifiantsEntitesBRep (const RepEntitesBRep*) ;
//
//	Accesseurs
//		Cle()
//
//	Surcharge des operateurs
//		operator =
//		operator <<
//
//	Partie protegee
//		RepresentationBRep()
//		PtrRepresentationBRep()
//*****************************************************************************

#ifndef __IdentifiantsEntitesBRep__h__
#define	__IdentifiantsEntitesBRep__h__


//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************

#include	"Identifiants.h"
#include	"RepEntitesBRep.h"
#include	"EnteteBRepPDLL.h"

#include	<iostream>
using namespace std ;


//*****************************************************************************
//
// Classe IdentifiantsEntitesBRep
//
//*****************************************************************************

class BREPP_DLL IdentifiantsEntitesBRep	: public Identifiants
{

public :

//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	IdentifiantsEntitesBRep () ;
	IdentifiantsEntitesBRep (const IdentifiantsEntitesBRep &) ;

	IdentifiantsEntitesBRep (const RepEntitesBRep*) ;

	~IdentifiantsEntitesBRep () ;
virtual void Detruire (void) ;
virtual void Vider(void) ;

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
	// La fonction Cle renvoie la cle se trouvant dans la representation
	// physique de l'entite BRep.
inline const TypeCle		Cle()			const;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const IdentifiantsEntitesBRep&	operator = (const IdentifiantsEntitesBRep &) ;

friend 	ostream& BREPP_DLL 		operator << (ostream &, const IdentifiantsEntitesBRep &) ;



//*****************************************************************************
//	Partie protegee
//*****************************************************************************
protected :

	// Fonction protegee pour consulter la representation d'une entite
	// du BRep (realise un transtypage de Identifiants::objet)
inline const RepEntitesBRep&	RepresentationBRep()	const;

	// Fonction protegee pour acceder en modification a la representation
	// d'une entite du BRep (realise un transtypage de Identifiants::objet)
inline RepEntitesBRep*		PtrRepresentationBRep() ;

};

#include "IdentifiantsEntitesBRep.inl"

#endif	__IdentifiantsEntitesBRep__h__
