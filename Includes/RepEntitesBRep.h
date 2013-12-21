//*****************************************************************************
//
// Module	: RepEntitesBRep
//
// Fichier	: RepEntitesBRep.h
//
// Auteur	: Lanuel Y.
//
// Date creat.	: Tue Feb 18 12:04:47 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe RepEntitesBRep.
//	1. Cette classe contient la cle unique d'une entite du BRep
//	2. Cette classe regroupe les informations topologiques et geometriques
// 	d'une entite du Brep.
//	3. Racine de la hierarchie des Representations physiques du modeleur
//
//*****************************************************************************
// Includes
// Classe RepEntitesBRep
//
//	Constructeurs et destructeur
//		RepEntitesBRep (const GeometriesBRep*, const TopologiesBRep*);
//
//	Accesseurs
//		Cle()
//		GeometrieBRep()
//		PtrGeometrieBRep()
//		TopologieBRep()
//		PtrTopologieBRep()
//
//	Surcharge des operateurs
//		operator =
//		operator <<
//
//	Partie protegee
//*****************************************************************************

#ifndef __RepEntitesBRep__h__
#define	__RepEntitesBRep__h__




//*****************************************************************************
//
// Includes
//
//*****************************************************************************


#include	<iostream>
using namespace std ;

#include	"TypeCle.h"
#include	"GeometriesBRep.h"
#include	"TopologiesBRep.h"
#include	"EnteteBRepPDLL.h"


//*****************************************************************************
//
// Classe RepEntitesBRep
//
//*****************************************************************************

class BREPP_DLL RepEntitesBRep
{

public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************

	RepEntitesBRep () ;
	RepEntitesBRep (const RepEntitesBRep &) ;

//************************************************************************
// Les pointeurs ne sont pas dupliques. Ils doivent etre alloués par l'appelant
// mais non desalloués par l'appelant car ils sont utilisés tels quels
//************************************************************************
	RepEntitesBRep (const GeometriesBRep*, const TopologiesBRep*);

virtual ~RepEntitesBRep () ;

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline const		TypeCle		Cle()						const;
inline void			ModifCle(TypeCle);


bool			EstSolidesP () 						const ;
bool			EstFacesP ()      	  		      const ;
bool			EstContoursP ()				      const ;
bool	 		EstAreteOrienteesP ()		      const ;
bool	 		EstAretesP ()					      const ;
bool	 		EstSommetsP ()					      const ;

inline const GeometriesBRep&	GeometrieBRep()		const;
inline GeometriesBRep*		PtrGeometrieBRep();

inline const TopologiesBRep&	TopologieBRep()		const;
inline TopologiesBRep*		PtrTopologieBRep();


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const RepEntitesBRep& 	operator = (const RepEntitesBRep &) ;
friend 	bool BREPP_DLL		operator== (const RepEntitesBRep & , const RepEntitesBRep &) ;
friend 	ostream& BREPP_DLL	operator << (ostream &, const RepEntitesBRep &);

//*****************************************************************************
//	Partie protegee
//*****************************************************************************
protected :

	TypeCle	cle;
	GeometriesBRep	*geometrie;
	TopologiesBRep	*topologie;

};

#include "RepEntiteBRep.inl"

#endif	__RepEntitesBRep__h__
