#ifndef	_RepresentationsP_H_
#define	_RepresentationsP_H_

#include	"AttributsFacesP.h"
#include	"AttributsSolidesP.h"
#include	"BibliothequeBRep.h"
#include	"GeometriesP.h"
#include	"TopologiesP.h"
#include	"EnteteBRepPDLL.h"


//*****************************************************************************
// 
// Module	: RepSommetsP
// 
// Fichier	: RepSommetsP.h
// 
// Auteur	: regain
// 
// Date creat.	: Tue Feb 18 14:28:58 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe RepSommetsP.
//
//
//*****************************************************************************
// Classe RepSommetsP
//	Constructeurs particuliers
//		RepSommetsP(Point3D)
//	Methodes
//		Geometrie()	+ Ptr...
//		Topologie()	+ Ptr...
//	Surcharge des operateurs
//		operator =
//		operator <<
//*****************************************************************************



//*****************************************************************************
//
// Classe RepSommetsP
//
//*****************************************************************************
class BREPP_DLL RepSommetsP : public RepEntitesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	RepSommetsP () ;
	RepSommetsP (const RepSommetsP &) ;
	RepSommetsP (const Points3D &P) ;
	~RepSommetsP () ;

//*****************************************************************************
//	Methodes
//*****************************************************************************
inline const GeoSommetsP&		Geometrie () const ;
inline const TopoSommetsP&		Topologie () const ;
inline		GeoSommetsP* 		PtrGeometrie () ;
inline 		TopoSommetsP* 		PtrTopologie () ;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const RepSommetsP& operator = (const RepSommetsP &) ;
friend 	ostream& BREPP_DLL operator << (ostream &, const RepSommetsP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

};





//*****************************************************************************
//
// Module	: RepAretesP
//
// Fichier	: RepAretesP.h
//
// Auteur	: regain
//
// Date creat.	: Thu Feb 20 13:00:44 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe RepAretesP.
//
//
//*****************************************************************************
// Classe RepAretesP
//	Constructeurs particuliers
//		RepAretesP(SommetsP,SommetsP,Regularite)
//	Methodes
//		Geometrie()	+ Ptr...
//		Topologie()	+ Ptr...
//	Surcharge des operateurs
//		operator =
//		operator <<
//*****************************************************************************




//*****************************************************************************
//
// Classe RepAretesP
//
//*****************************************************************************

class BREPP_DLL RepAretesP	: public RepEntitesBRep
{

public :


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************

	RepAretesP () ;
	RepAretesP (const RepAretesP &) ;

	RepAretesP (const SommetsP& Origine, const SommetsP& Extremite, bool Cont) ;


	~RepAretesP () ;


//*****************************************************************************
//	Methodes
//*****************************************************************************
inline	const GeoAretesP&	Geometrie()		const;
inline	GeoAretesP*		PtrGeometrie();

inline	const TopoAretesP&	Topologie()		const;
inline	TopoAretesP*		PtrTopologie();

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const RepAretesP& 	operator = (const RepAretesP &) ;

friend	ostream& BREPP_DLL 	operator << (ostream &, const RepAretesP &);

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

};





//*****************************************************************************
//
// Module	: RepAretesOrienteesP
//
// Fichier	: RepAretesOrienteesP.h
// 
// Auteur	: regain
// 
// Date creat.	: Tue Feb 18 15:14:30 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe RepAretesOrienteesP.
// 
//
//*****************************************************************************
// Classe RepAretesOrienteesP
//	Constructeurs particuliers
//		RepAretesOrienteesP(Arete,sens)
//	Methodes
//		Geometrie()
//		Topologie()	+ Ptr...
//	Surcharge des operateurs
//		operator =
//		operator <<
//*****************************************************************************





//*****************************************************************************
//
// Classe RepAretesOrienteesP
//
//*****************************************************************************

class BREPP_DLL RepAretesOrienteesP : public RepEntitesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	RepAretesOrienteesP () ;
	RepAretesOrienteesP (const RepAretesOrienteesP &) ;

	RepAretesOrienteesP (const AretesP &, const bool &sens) ;

	~RepAretesOrienteesP () ;

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline 	const TopoAretesOrienteesP& 	Topologie () const ;
inline 	TopoAretesOrienteesP* 		PtrTopologie () ;

inline 	const GeoAretesOrienteesP& 	Geometrie () const ;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const RepAretesOrienteesP& operator = (const RepAretesOrienteesP &) ;

friend 	ostream& BREPP_DLL 	   operator << (ostream &, const RepAretesOrienteesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

};





//*****************************************************************************
//
// Module	: RepContoursP
//
// Fichier	: RepContoursP.h
//
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 14:33:03 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe RepContoursP.
//
//
//*****************************************************************************
// Classe RepContoursP
//	Constructeurs particuliers
//		RepContoursP(Liste d'aretes, Contour &)
//		RepContoursP(Liste d'aretes orientees, Contour &)
//		RepContoursP(Topologie*)
//	Methodes
//		Topologie()	+ Modif... + Ptr...
//	Surcharge des operateurs
//		operator =
//		operator <<
//*****************************************************************************


//*****************************************************************************
//
// Classe RepContoursP
//
//*****************************************************************************
class BREPP_DLL RepContoursP : public RepEntitesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	RepContoursP () ;
	RepContoursP (const RepContoursP &) ;

	RepContoursP (const TopoContoursP*) ;
	RepContoursP (const Listes<AretesP>& , ContoursP &) ;
  	RepContoursP (const Tableaux<AretesP>& , ContoursP &) ;
	RepContoursP (const Listes<AretesOrienteesP> &, ContoursP&) ;
	RepContoursP (const Tableaux<AretesOrienteesP> &, ContoursP&) ;

	~RepContoursP () ;

//*****************************************************************************
//	Methodes
//*****************************************************************************
inline 	const TopoContoursP &	Topologie () 				const ;
inline 	void			ModifTopologie (TopoContoursP *PTC) ;
inline 	TopoContoursP *		PtrTopologie () 		;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const RepContoursP& operator = (const RepContoursP &) ;

friend 	ostream& BREPP_DLL operator << (ostream &, const RepContoursP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

};





//*****************************************************************************
//
// Module	: RepFacesP
//
// Fichier	: RepFacesP.h
//
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 14:30:55 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe RepFacesP.
//
//
//*****************************************************************************
// Classe RepFacesP
//	ATTENTION : la représentation d'une FacesP contient un pointeur vers un attibut,
//				NULL à défaut.

//	Constructeurs particuliers
//		RepFacesP(Contour exterieur)
//		RepFacesP(Liste de contours)
//	Methodes
//		Geometrie()	+ Ptr...
//		Topologie()	+ Ptr...
//	Surcharge des operateurs
//		operator =
//		operator <<
//*****************************************************************************


//*****************************************************************************
//
// Classe RepFacesP
//
//*****************************************************************************

class BREPP_DLL RepFacesP : public RepEntitesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	RepFacesP () ;
	RepFacesP (const RepFacesP &) ;

	RepFacesP (const ContoursP &, const AttributsFacesP *PA = NULL) ;
	// l'attribut, s'il existe, est dupliqué donc PA peut être libéré par l'appelant

	RepFacesP (const Listes<ContoursP> &, const AttributsFacesP *PA = NULL) ;
	// l'attribut, s'il existe, est dupliqué donc PA peut être libéré par l'appelant

	RepFacesP (const Tableaux<ContoursP> &, const AttributsFacesP *PA = NULL) ;   
	// l'attribut, s'il existe, est dupliqué donc PA peut être libéré par l'appelant


	~RepFacesP () ;

//*****************************************************************************
//	Methodes
//*****************************************************************************
	inline const GeoFacesP &	Geometrie () 			const ;
	inline GeoFacesP *		PtrGeometrie () 		;

	inline const TopoFacesP &	Topologie () 			const ;
	inline TopoFacesP *		PtrTopologie () 		;

	inline const AttributsFacesP	*Attribut () const ;
	// Le pointeur restitué est un const * pour interdire la modif 
	// de l'attribut (on restitue l'adresse de l'attribut conservé
	// dans la face !

	inline void							ModifAttribut (const AttributsFacesP *PA) ;
	// *PA est dupliqué donc PA doit être libéré par l'appelant après l'appel

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const RepFacesP& 	operator = (const RepFacesP &) ;

friend 	ostream& BREPP_DLL 	operator << (ostream &, const RepFacesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :
	AttributsFacesP	*mPAttribut ;	

	void MiseAJourEnglobant () ;
};





//*****************************************************************************
//
// Module	: RepSolidesP
//
// Fichier	: RepSolidesP.h
//
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 14:20:48 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe RepSolidesP.
//
//
//*****************************************************************************
// Classe RepSolidesP
//	Constructeurs particuliers
//		RepSolidesP(Liste de faces)
//		RepSolidesP(Geometrie*, Topologie*)
//	Methodes
//		Geometrie()	+ Ptr...
//		Topologie()	+ Ptr...
//		MiseAJourEnglobant()
//	Surcharge des operateurs
//		operator =
//		operator <<
//*****************************************************************************


//*****************************************************************************
//
// Classe RepSolidesP
//
//*****************************************************************************

class BREPP_DLL RepSolidesP : public RepEntitesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	RepSolidesP () ;
	RepSolidesP (const RepSolidesP &) ;

	RepSolidesP (const GeoSolidesP*, const TopoSolidesP*, const AttributsSolidesP *PA = NULL) ;
	// l'attribut, s'il existe, est dupliqué donc PA peut être libéré par l'appelant

	RepSolidesP (const Listes<FacesP> &, const AttributsSolidesP *PA = NULL) ;
	// l'attribut, s'il existe, est dupliqué donc PA peut être libéré par l'appelant

	RepSolidesP (const Tableaux<FacesP> &, const AttributsSolidesP *PA = NULL) ;
	// l'attribut, s'il existe, est dupliqué donc PA peut être libéré par l'appelant

	~RepSolidesP () ;

//*****************************************************************************
//	Methodes
//*****************************************************************************
	inline const GeoSolidesP &	Geometrie () 			const ;
	inline GeoSolidesP *		PtrGeometrie () 		;
	inline const TopoSolidesP &	Topologie () 			const ;
	inline TopoSolidesP *		PtrTopologie () 		;
	void 				MiseAJourEnglobant () 		;

	inline const AttributsSolidesP	*Attribut () const ;
	// Le pointeur restitué est un const * pour interdire la modif 
	// de l'attribut (on restitue l'adresse de l'attribut conservé
	// dans la face !

	inline void							ModifAttribut (const AttributsSolidesP *PA) ;
	// *PA est dupliqué donc PA doit être libéré par l'appelant après l'appel

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const RepSolidesP& 	operator = (const RepSolidesP &) ;

friend 	ostream& BREPP_DLL	operator << (ostream &, const RepSolidesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :
	AttributsSolidesP	*mPAttribut ;	

};

#include "RepSommetsP.inl"
#include "RepAretesP.inl"
#include "RepAretesOrientees.inl"
#include "RepContoursP.inl"
#include "RepFacesP.inl"
#include "RepSolides.inl"



#endif _RepresentationsP_H_
