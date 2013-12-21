//*****************************************************************************
// 
// Module	: Droites3D
// 
// Fichier	: Droites3D.h
// 
// Auteur	: Y. LANUEL							
// 
// Date creat.	: 18/05/96							
// 
// Commentaires	: Interface de la classe Droites3D.
// 
// 
//*****************************************************************************
// Includes
// Classe Vecteurs3D
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//		CalculPoint(t)
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************



#ifndef __Droites3D__h__
#define	__Droites3D__h__	1



//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************
#include	<iostream> 
using namespace std ;

#include	"Points3D.h"
#include	"Vecteurs3D.h"

#include	"EnteteMathDLL.h"



//*****************************************************************************
// 
// Classe Droites3D
// 
//*****************************************************************************
class MATH_DLL Droites3D
{

public:


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************

	Droites3D();
	Droites3D(const Droites3D&);
	~Droites3D();
	

	Droites3D(const Points3D&, const Vecteurs3D&);
	Droites3D(const Points3D&, const Points3D&);


//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline 	const Points3D&		Origine()	const;
inline 	const Vecteurs3D&	Direction()	const;


inline 	const Droites3D&	Origine(const Points3D&);
inline 	const Droites3D&	Direction(const Vecteurs3D&);


//*****************************************************************************
//	Methodes
//*****************************************************************************
	Points3D	CalculPoint(double T)		const;
	double 		CalculT (const Points3D&) 	const ;
   
	bool			Intersection (Droites3D &D, Points3D *I, bool *Superposees) ;
	// Restitue vrai ssi les droites se coupent EN UN SEUL POINT. Dans ce cas,
	// le point d'intersection est restitué dans I.
	// Dans le cas contraire, Superposees dit si les droites sont superposées
	// ou distinctes.


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
friend	ostream& MATH_DLL 	operator << (ostream&, const Droites3D&);
	const	Droites3D& 	operator =  (const Droites3D&);


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	Points3D	p;
	Vecteurs3D	v;

};



#include	"Droites3D.inl"



#endif	__Droites3D__h__
