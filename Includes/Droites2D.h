//
// Module	: Droites2D
//
// Fichier	: Droites2D.h
//
// Auteur	: Regain (Estelle)
//
// Date creat.	: May 14 1997
//
// Version	: 1.0
//
// Commentaires	: Interface de la classe Droites2D
//
// 1. Constructeurs et Destructeur
// 2. Accesseurs
// 3. Modifications
// 4. Méthodes
// 5. Operateurs
//

#ifndef droite2D_hh
#define droite2D_hh


#include	"Points3D.h"
#include 	"Vecteurs3D.h"

#include	"EnteteMathDLL.h"

class 	MATH_DLL Droites2D
{
public :
// 1. Constructeurs et Destructeur
	Droites2D () ;
	Droites2D (const Points3D & , const Points3D &) ;
	Droites2D (const Points3D & , const Vecteurs3D &) ;
	Droites2D (const Droites2D &) ;
	~Droites2D () ;

// 2. Accesseurs
inline 	const Points3D & 	Point   () const ;
inline 	const Vecteurs3D &	Vecteur () const ;

// 3. Modifications
inline 	void			ModifPoint (const Points3D &) ;
inline 	void			ModifVecteur (const Vecteurs3D &) ;

// 4. Méthodes
	double		Calc2D (const Points3D &) const ;
inline 	double		Lambda	(const Points3D &) const ;
	double		CalcHorizontal (const Points3D &) const ;
inline 	void		Cartesienne (double & , double & , double &) const ;
	bool		Intersecter (const Droites2D & , Points3D &) const ;
   double	Distance (const Points3D &) const ;

// 5. Operateurs
	const Droites2D &	 operator = (const Droites2D &) ;
friend 	ostream &	MATH_DLL operator << (ostream & , const Droites2D &) ;

private :
	Points3D point ;
	Vecteurs3D vecteur ;


} ;
#include "droite2D.inl"

#endif /* droite_hh */
