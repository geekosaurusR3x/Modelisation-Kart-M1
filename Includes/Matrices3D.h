//*****************************************************************************
// 
// Module	: Matrices3D
// 
// Fichier	: Matrices3D.h
// 
// Auteur	: Y. LANUEL							
// 
// Date creat.	: 18/05/96							
// 
// Commentaires	: Interface de la classe Matrices3D.
// 
// 
//*****************************************************************************
// Includes
// Classe Matrices3D
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//		Transposee()
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************



#ifndef __Matrices3D__h__
#define	__Matrices3D__h__	1



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



//*****************************************************************************
//
// 2. Classe Matrices3D
//
//*****************************************************************************
class MATH_DLL Matrices3D
{

public:


//*****************************************************************************
//	2.1 Constructeurs et destructeur
//*****************************************************************************
	Matrices3D();
	Matrices3D(const Matrices3D&);
	~Matrices3D();
	

	Matrices3D(const Vecteurs3D&, const Vecteurs3D&, const Vecteurs3D&);


//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline 	double		M(int L, int C)	const;
inline	void		ModifM(int L, int C, double Val);


//*****************************************************************************
//	Methodes
//*****************************************************************************
	Matrices3D	Transposee()	const;


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
friend	ostream& MATH_DLL 	operator << (ostream&, const Matrices3D&) ;
friend 	bool MATH_DLL  		operator == (const Matrices3D & ,const Matrices3D &) ;
friend 	bool MATH_DLL  		operator != (const Matrices3D & ,const Matrices3D &) ;

	const	Matrices3D& 	operator =  (const Matrices3D&);


friend	Points3D MATH_DLL  	operator * (const Points3D&, const Matrices3D&);
friend	Points3D MATH_DLL  	operator * (const Matrices3D&, const Points3D&);

friend	Vecteurs3D MATH_DLL 	operator * (const Vecteurs3D&, const Matrices3D&);
friend	Vecteurs3D MATH_DLL 	operator * (const Matrices3D&, const Vecteurs3D&);

friend	Matrices3D MATH_DLL 	operator * (const Matrices3D&,const Matrices3D&);


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	double	m[3][3];

};


#include	"Matrices3D.inl"


#endif	__Matrices3D__h__
