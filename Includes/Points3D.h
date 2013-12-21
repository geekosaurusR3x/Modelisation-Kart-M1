//*****************************************************************************
// 
// Module	: Points3D
// 
// Fichier	: Points3D.h
// 
// Auteur	: Y. LANUEL							
// 
// Date creat.	: 18/05/96							
// 
// Commentaires	: Interface de la classe Points3D.
// 
// 
//*****************************************************************************
// Includes
// Classe Points3D
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//		Distance()
//		DistanceCarree()
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************


#ifndef __Points3D__h__
#define	__Points3D__h__	1



//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************
#include	<iostream> 
using namespace std ;


#include	"Vecteurs3D.h"
#include	"Matrices3D.h"
#include	"Matrices4D.h"

#include	"EnteteMathDLL.h"



//*****************************************************************************
//
// Classe Points3D
//
//*****************************************************************************
class MATH_DLL Points3D
{

public:


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	Points3D();
	Points3D(const Points3D&);
	~Points3D();


	Points3D(double, double, double);


//*****************************************************************************
//	Accesseurs
//*****************************************************************************
	inline double	X()	const;
	inline double	Y()	const;
	inline double	Z()	const;


	inline void	ModifX(double);
	inline void	ModifY(double);
	inline void	ModifZ(double);


//*****************************************************************************
//	Methodes
//*****************************************************************************
	double	Distance(const Points3D&)			const;
	double	DistanceCarree(const Points3D&)			const;
   
	bool		EstEgal (const Points3D & P2, double eps) const ;
	// Restitue vrai ssi les écarts entre les coordonnées sont tous les trois
	// inférieurs à eps en valeur absolue.


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	friend	ostream&  MATH_DLL operator << (ostream&, const Points3D&);
	friend	istream&  MATH_DLL operator >> (istream&, Points3D&);
	const	Points3D& operator =  (const Points3D&);


	friend	Points3D MATH_DLL operator * (const Points3D&, const Matrices3D&);
	friend	Points3D MATH_DLL operator * (const Matrices3D&, const Points3D&);
	friend	Points3D MATH_DLL operator * (const Points3D&, const Matrices4D&);
	friend	Points3D MATH_DLL operator * (const Matrices4D&, const Points3D&);

	friend  Points3D MATH_DLL operator * (double , const Points3D &) ;

	friend	Points3D MATH_DLL operator + (const Points3D&, const Points3D&);
	friend	Points3D MATH_DLL operator - (const Points3D&, const Points3D&);

	friend	Points3D MATH_DLL operator + (const Points3D&, const Vecteurs3D&);
	friend	Points3D MATH_DLL operator - (const Points3D&, const Vecteurs3D&);

	friend bool MATH_DLL 	  operator == (const Points3D& , const Points3D&) ;

	double operator [] (int i) const ;
	// Attention : i varie  de 0 à 2 !!

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	double	m[3];

};



#include	"Points3D.inl"



#endif	__Points3D__h__
