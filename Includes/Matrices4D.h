//*****************************************************************************
// 
// Module	: Matrices4D
// 
// Fichier	: Matrices4D.h
// 
// Auteur	: Y. LANUEL							
// 
// Date creat.	: 18/05/96							
// 
// Commentaires	: Interface de la classe Matrices4D.
// 
// 
//*****************************************************************************
// Includes
// Classe Matrices4D
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//		Transposee()
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************



#ifndef __Matrices4D__h__
#define	__Matrices4D__h__	1



//*****************************************************************************
// 
// 1. Includes
// 
//*****************************************************************************
#include	<iostream> 
using namespace std ;


#include	"EnteteMathDLL.h"

class	MATH_DLL Points3D;
class	MATH_DLL Vecteurs3D;
class	MATH_DLL Reperes3D;



//*****************************************************************************
//
// 2. Classe Matrices4D
//
//*****************************************************************************
class MATH_DLL Matrices4D
{

public:


//*****************************************************************************
//	2.1 Constructeurs et destructeur
//*****************************************************************************
	Matrices4D();
	Matrices4D(const Matrices4D&);
	~Matrices4D();

	Matrices4D(const Reperes3D&);


//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline 	double		M(int L, int C)	const;
inline	void			ModifM(int L, int C, double Val);


//*****************************************************************************
//	Methodes
//*****************************************************************************
	Matrices4D	Transposee()	const;

	void			DevenirTranslation (const Vecteurs3D&);
	void			DevenirRotationQuelconque (const Points3D&, const Vecteurs3D&, double);
	// Rotation de angle autour de la droite (A,V). c'est V qui indique le sens
	//	positif de rotation selon la regle du tire-bouchon

	void			Matrices4D::DevenirRotationOX (double teta) ;
	// Le sens positif de rotation est de Oy vers Oz.

	void			Matrices4D::DevenirRotationOX (double Cos, double Sin) ;
	// Parfois, on a plus facile de calculer le cos et le sin de l'angle que
	// l'angle lui-même, d'où cette deuxième syntaxe.
	// Le sens positif de rotation est de Oy vers Oz.

	void			Matrices4D::DevenirRotationOY (double teta) ;
	// Le sens positif de rotation est de Oz vers Ox.

	void			Matrices4D::DevenirRotationOY (double Cos, double Sin) ;
	// Parfois, on a plus facile de calculer le cos et le sin de l'angle que
	// l'angle lui-même, d'où cette deuxième syntaxe.
	// Le sens positif de rotation est de Oz vers Ox.

	void			Matrices4D::DevenirRotationOZ (double teta) ;
	// Le sens positif de rotation est de Ox vers Oy.

	void			Matrices4D::DevenirRotationOZ (double Cos, double Sin) ;
	// Parfois, on a plus facile de calculer le cos et le sin de l'angle que
	// l'angle lui-même, d'où cette deuxième syntaxe.
	// Le sens positif de rotation est de Ox vers Oy.

	void			DevenirHomothetieQuelconque (const Points3D&, double Ex, double Ey, double Ez) ;
	void			DevenirHomothetieOrigine (double Ex, double Ey, double Ez) ;

	void			DevenirChangementDeRepereMondeVersLocal (const Points3D &NO,
					const Vecteurs3D &NI,const Vecteurs3D &NJ,const Vecteurs3D &NK) ;
	// Construit la transformation qui amène le repère du monde sur le repère
	// (NO,NI,NJ,NK)
	// Les vecteurs doivent être normés et former un trièdre direct.

	void			DevenirChangementDeRepereLocalVersMonde (const Points3D &NO,
					const Vecteurs3D &NI,const Vecteurs3D &NJ,const Vecteurs3D &NK) ;
	// Construit la transformation qui amène le repère (NO,NI,NJ,NK) sur
	// le repère du monde
	// Les vecteurs doivent être normés et former un trièdre direct.

	void		DevenirChangementDeRepereLocalVersLocal (
				const Points3D &O1,
            const Vecteurs3D &I1,const Vecteurs3D &J1,const Vecteurs3D &K1,
            const Points3D &O2,
				const Vecteurs3D &I2,const Vecteurs3D &J2,const Vecteurs3D &K2) ;
	// Construit la transformation qui amène le repère (O1,I1,J1,K1) sur
	// le repère (O2,I2,J2,K2)
	// Les vecteurs doivent être normés et former des trièdres directs.

	//	void			DevenirPerspective();

   bool	MatriceInverse (Matrices4D	&Inv) const ;
   // Si la matrice est inversible, la fct restitue vrai et Inv contient
   //	la matrice inverse. Sinon, la fct restitue faux.


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
friend	ostream& MATH_DLL 	operator << (ostream&, const Matrices4D&) ;
friend 	bool MATH_DLL  		operator == (const Matrices4D & ,const Matrices4D &) ;
friend 	bool MATH_DLL  		operator != (const Matrices4D & ,const Matrices4D &) ;

const		Matrices4D& 			operator =  (const Matrices4D&);


friend	Points3D MATH_DLL  	operator * (const Points3D&, const Matrices4D&);
friend	Vecteurs3D MATH_DLL 	operator * (const Vecteurs3D&, const Matrices4D&);
friend	Matrices4D MATH_DLL 	operator * (const Matrices4D&,const Matrices4D&);


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	double	m[4][4];

	// Calcul du déterminant d'une matrice 3x3
   double   Determinant3x3 (	const double &, const double &, const double &,
										const double &, const double &, const double &,
                              const double &, const double &, const double &) const ;

};


#include	"Matrices4D.inl"


#endif	__Matrices4D__h__
