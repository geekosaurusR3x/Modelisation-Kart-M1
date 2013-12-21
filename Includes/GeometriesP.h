//*****************************************************************************
//
// Module	: GeometriesP
//
// Fichier	: GeometriesP.h
//
// Auteur	: Regain ?
//
// Date creat.	: ?
//
// Version	:
//
// Commentaires	: Interface des classes GeoSommetsP , GeoAretes ,
//						  GeoAretesOrientees , Geo...
//
//
//*****************************************************************************


#ifndef __GeometriesP__h__
#define	__GeometriesP__h__

#include	<iostream>
using namespace std ;

#include	"BibliothequeMathematique.h"
#include	"EnteteBRepPDLL.h"

//#include	"BibliothequeBRep.h"
#include "GeometriesBRep.h"




//*****************************************************************************
//
// Classe GeoSommetsP
//
//*****************************************************************************

class BREPP_DLL GeoSommetsP : public GeometriesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	GeoSommetsP () ;
	GeoSommetsP (const GeoSommetsP &GeoSom) ;

	GeoSommetsP (const Points3D &P) ;

	~GeoSommetsP () ;

//*****************************************************************************
//	Methodes
//*****************************************************************************
inline 		const 	Points3D& Point3D () 					const ;
inline		void		ModifPoint3D (const Points3D &P) 			;
		GeometriesBRep*	Dupliquer()						const;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
		const GeoSommetsP& operator = (const GeoSommetsP &) ;

		friend 	ostream& BREPP_DLL operator << (ostream &, const GeoSommetsP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :
	Points3D		point3D ;
};






//*****************************************************************************
//
// Module	: GeoAretesP
//
// Fichier	: GeoAretesP.h
//
// Auteur	: regain
//
// Date creat.	: Fri Feb 21 08:52:43 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe GeoAretesP.
//
//
//*****************************************************************************
// Includes
// Classe GeoAretesP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************


//*****************************************************************************
//
// Classe GeoAretesP
//
//*****************************************************************************
class BREPP_DLL GeoAretesP	: public GeometriesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	GeoAretesP	() ;
	GeoAretesP	(const GeoAretesP &) ;

	GeoAretesP	(const Droites3D&) ;

	~GeoAretesP	() ;

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline 	bool			EstAJour()				const;
inline 	void			MettreAJour();
inline  	void			PlusAJour();

inline  	const Droites3D&	Droite3D()				const;
inline  	void			ModifDroite3D(const Droites3D&);

 	GeometriesBRep*		Dupliquer()				const ;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const GeoAretesP& operator = (const GeoAretesP &) ;

friend ostream& BREPP_DLL operator << (ostream & , const GeoAretesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

	Droites3D	D;
	bool		ajour;

	void	Affiche(ostream&)	const;
};

//#include "GeoAretesP.inl"



//*****************************************************************************
//
// Module	: GeoAretesOrienteesP
//
// Fichier	:
//
// Auteur	: regain
//
// Date creat.	: Fri Feb 21 08:52:43 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe GeoAretesOrienteesP
//
//
//*****************************************************************************
// Includes
// Classe GeoAretesOrienteesP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


class BREPP_DLL GeoAretesOrienteesP	: public GeometriesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	GeoAretesOrienteesP () ;
	GeoAretesOrienteesP (const GeoAretesOrienteesP &GAO) ;
	~GeoAretesOrienteesP () ;

//*****************************************************************************
//	Methodes
//*****************************************************************************
	void			Affiche (ostream& s)	const ;
	GeometriesBRep*		Dupliquer()		const ;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const GeoAretesOrienteesP& operator = (const GeoAretesOrienteesP &O) ;
} ;

//#include "GeoAretesOrienteesP.inl"




//*****************************************************************************
//
// Module	: GeoFacesP
//
// Fichier	: GeoFacesP.h
//
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 15:39:22 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe GeoFacesP.
//
//
//*****************************************************************************
// Includes
// Classe GeoFacesP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************



//*****************************************************************************
//
// Classe GeoFacesP
//
//*****************************************************************************

class BREPP_DLL GeoFacesP : public GeometriesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	GeoFacesP () ;
	GeoFacesP (const GeoFacesP &) ;
	~GeoFacesP () ;

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
	inline const Vecteurs3D& 	VecteurNormal ()		const ;
	inline const Plans3D &		Plan ()					const ;
	inline Plans3D *		PtrPlan ()				;
	inline const Englobants3D &	Englobant ()				const ;
	inline Englobants3D *		PtrEnglobant ()				;
	inline void			ModifEnglobant (const Englobants3D &) 	;
	inline void			ModifPlan (const Plans3D &)		;
   inline void 		ModifVecteurNormal ( const Vecteurs3D& ) ;
	inline bool			EstAJour ()				const ;
	inline void			MettreAJour ()				;
	inline void			PlusAJour ()				;

//*****************************************************************************
//	Methodes
//*****************************************************************************
	GeometriesBRep*		Dupliquer()				const;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const GeoFacesP& operator = (const GeoFacesP &) ;

friend 	ostream& BREPP_DLL operator << (ostream &, const GeoFacesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :


	Englobants3D E ;
	Plans3D P ;
   Vecteurs3D normale ;
	bool ajour ;

};






//*****************************************************************************
//
// Module	: GeoSolidesP
//
// Fichier	: GeoSolidesP.h
//
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 14:54:52 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe GeoSolidesP.
//
//
//*****************************************************************************
// Includes
// Classe GeoSolidesP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************

//*****************************************************************************
//
// Classe GeoSolidesP
//
//*****************************************************************************

class BREPP_DLL GeoSolidesP : public GeometriesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	GeoSolidesP () ;
	GeoSolidesP (const GeoSolidesP &) ;
	~GeoSolidesP () ;

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
	GeometriesBRep *	Dupliquer ()				const ;
inline 	const Englobants3D &	Englobant () 				const ;
inline 	Englobants3D *		PtrEnglobant ()				;
inline 	void			ModifEnglobant (const Englobants3D &) 	;
inline 	bool			EstAJour ()				const ;
inline 	void			PlusAJour ()				;
inline 	void			MettreAJour ()				;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const GeoSolidesP& operator = (const GeoSolidesP &) ;

friend 	ostream& BREPP_DLL operator << (ostream &, const GeoSolidesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :
	Englobants3D E ;
	bool ajour ;
};

#include "GeoSommetsP.inl"
#include "GeoAretesP.inl"
//#include "GeoAretesOrienteesP.inl"
#include "GeoFacesP.inl"
#include "GeoSolidesP.inl"


#endif	__GeometriesP__h__
