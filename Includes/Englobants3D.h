//*****************************************************************************
// 
// Module	: Englobants3D
// 
// Fichier	: Englobants3D.h
// 
// Auteur	: lanuel							
// 
// Date creat.	: Fri Jul 12 14:10:48 MET DST 1996
// 
// Commentaires	: Interface de la classe Englobants3D.
// 
// 
//*****************************************************************************
// Includes
// Classe Englobants3D
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************



#ifndef __Englobants3D__h__
#define	__Englobants3D__h__



//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************
#include	<iostream> 
using namespace std ;


#include	"Points3D.h"
#include	"Droites3D.h"
#include	"Englobants3D.h"
#include	"MacroMath.h"

#include	"EnteteMathDLL.h"


//*****************************************************************************
//
// Classe Englobants3D
//
//*****************************************************************************
class MATH_DLL Englobants3D
{

public:


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	Englobants3D();
	Englobants3D(const Englobants3D&);
	~Englobants3D();

	Englobants3D(const Points3D& PtBasGauche,
	             const Points3D& PtHautDroit);

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline 	const Points3D& 	BasGauche() 				const;
inline 	const Points3D& 	HautDroit() 				const;
inline 	void 			ModifBasGauche(const Points3D&);
inline 	void 			ModifHautDroit(const Points3D&);

//*****************************************************************************
//	Methodes
//*****************************************************************************
	bool	ExisteIntersection(const Droites3D&)			const;
	bool 	ExisteIntersection(const Englobants3D&) 		const;
	bool	Appartient(const Points3D&)				const;
	bool	Appartient(const Englobants3D&)				const;
   
	void  EngloberPoint (const Points3D &P) ;
	// Ajuste l'englobant sur le point

	void  EngloberCylindre (const Points3D &P1, const Points3D &P2, double R) ;
	// Ajuste l'englobant sur le cylindre

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const Englobants3D&	operator = (const Englobants3D&);

friend ostream&	MATH_DLL 	operator << (ostream&, const Englobants3D&);

friend	Englobants3D MATH_DLL 	operator *  (const Englobants3D&, const Englobants3D&);
friend	Englobants3D MATH_DLL 	operator +  (const Englobants3D&, const Englobants3D&);
friend	Englobants3D MATH_DLL 	operator -  (const Englobants3D&, const Englobants3D&);

friend	Englobants3D MATH_DLL 	operator +  (const Englobants3D&, const Vecteurs3D&);
friend	Englobants3D MATH_DLL 	operator /  (const Englobants3D&, int);

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	Points3D	pbg, phd;

};



#include	"Englobants3D.inl"



#endif	__Englobants3D__h__
