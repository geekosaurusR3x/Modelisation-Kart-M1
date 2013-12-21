//*****************************************************************************
// 
// Module	: Rectangles
// 
// Fichier	: Rectangles.h
// 
// Auteur	: M. Krajecki							
// 
// Date creat.	: Mon Aug  5 14:33:12 MET DST 1996
// 
// Commentaires	: Interface de la classe Rectangles.
// 
// 
//*****************************************************************************
// Includes
// Classe Rectangles
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************



#ifndef __Rectangles__h__
#define	__Rectangles__h__



//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************
#include	<iostream>
using namespace std ;


#include	"EnteteMathDLL.h"

//*****************************************************************************
//
// Classe Rectangles
//
//*****************************************************************************
class MATH_DLL Rectangles
{

public:


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************

	Rectangles();
	Rectangles(double, double, double, double);
	Rectangles(const Rectangles&);
	~Rectangles();


//*****************************************************************************
//	Accesseurs
//*****************************************************************************

	inline double			Xmin()	const;
	inline double			Ymin()	const;
	inline double			Xmax()	const;
	inline double			Ymax()	const;

	inline const Rectangles& 	Xmin(double);
	inline const Rectangles& 	Ymin(double);
	inline const Rectangles& 	Xmax(double);
	inline const Rectangles& 	Ymax(double);

//*****************************************************************************
//	Methodes
//*****************************************************************************

	Rectangles	Recadrer(const Rectangles&)	const;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const Rectangles&		operator = (const Rectangles&);
	friend ostream& MATH_DLL 	operator << (ostream&, const Rectangles&);


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	double	xmin,
				ymin,
				xmax,
				ymax;

};



#include	"Rectangles.inl"
#endif	__Rectangles__h__
