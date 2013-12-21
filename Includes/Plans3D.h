//*****************************************************************************
// 
// Module	: Plans3D
//
// Fichier	: Plans3D.h
//
// Auteur	: Y. LANUEL, M. KRAJECKI				
//
// Date creat.	: 30/06/96
//
// Commentaires	: Interface de la classe Plans3D.
//
//
//*****************************************************************************
// Includes
// Classe Plans3D
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//		Intersection
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************



#ifndef __Plans3D__h__
#define	__Plans3D__h__	1

//*****************************************************************************
//
// Includes
//
//*****************************************************************************
#include	<iostream> 
using namespace std ;


#include	"Matrices3D.h"
#include	"Vecteurs3D.h"
#include	"Points3D.h"
#include	"Droites3D.h"

#include	"EnteteMathDLL.h"

//*****************************************************************************
//
// Classe Plans3D
//
//*****************************************************************************
class MATH_DLL Plans3D
{

public:


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	Plans3D();
	Plans3D(const Plans3D&);
	~Plans3D();


	Plans3D(double, double, double, double);
	Plans3D(const Points3D&, const Points3D&, const Points3D&);


//*****************************************************************************
//	Accesseurs
//*****************************************************************************
	inline double		A()		const;
	inline double		B()		const;
	inline double		C()		const;
	inline double		D()		const;
	inline const Vecteurs3D	Normale()	const;


	inline const Plans3D& 		A(double);
	inline const Plans3D&		B(double);
	inline const Plans3D&		C(double);
	inline const Plans3D&		D(double);


//*****************************************************************************
//	Methodes
//*****************************************************************************

	void			Intersection(const Droites3D&, Points3D& , bool&)			const;
	// Intersection Plan / droite
	// B est vrai ssi D coupe this en un point et P est alors ce point
	// Dans le cas contraire, cette fonction ne précise pas si D est sur le
	// plan ou strictement parallèle. La fonction suivante le fait.

   void			Intersection(const Droites3D& D, Points3D& P, bool& B, bool &SurPlan)	const ;
	// Intersection Plan / droite
	// B est vrai ssi D coupe this en UN POINT et P est alors ce point
	// Dans le cas contraire, SurPlan précise si la droite est sur le
	// plan ou strictement parallèle.

	void			Intersection (const Points3D & , const Points3D & , Points3D& , int &) 	const ;
	// Intersection du plan *this avec le segment [Po,Pe]
	// res = 0 -> pas d'intersection (bien que la droite puisse couper le plan)
	// res = 1 -> intersection = Po
	// res = 2 -> intersection = Pe
	// res = 3 -> intersection = le segment
	// res = 4 -> intersection franche

   double		Puissance(const Points3D&)											const;
   // Restitue la valeur de a.x + b.y + c.z + d.
   // Le signe de cette quantité est quelconque.
   // Elle ne correspond à la distance au plan que si a²+b²+c² = 1 et il
   // faut alors prendre la valeur absolue.
   // Sinon, on peut obtenir la distance au plan en divisant la valeur
   // absolue du résultat de Puissance par sqrt (a²+b²+c²)

	double 		Distance (const Points3D & Pt);
   // Distance au plan
   
//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
friend	ostream&  MATH_DLL 	operator << (ostream&, const Plans3D&);
friend	bool	  MATH_DLL	operator == (const Plans3D & , const Plans3D &) ;
	const	Plans3D& 	operator =  (const Plans3D&);


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	double	a,b,c,d;

};



#include	"Plans3D.inl"



#endif	__Plans3D__h__
