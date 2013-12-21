//*****************************************************************************
// 
// Module	: Reperes3D
// 
// Fichier	: Reperes3D.h
// 
// Auteur	: Y. LANUEL							
// 
// Date creat.	: 18/05/96							
// 
// Commentaires	: Interface de la classe Reperes3D.
// 
// 
//*****************************************************************************
// Includes
// Classe Reperes3D
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//		RepereVersMonde(Point)
//		RepereVersMonde(Vecteur)
//		MondeVersRepere(Point)
//		MondeVersRepere(Vecteur)
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************



#ifndef __Reperes3D__h__
#define	__Reperes3D__h__	1



//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************
#include	<iostream> 
using namespace std ;


#include	"Points3D.h"
#include	"Vecteurs3D.h"
#include	"Matrices3D.h"
#include	"MacroMath.h"


#include	"EnteteMathDLL.h"




//*****************************************************************************
//
// Classe Reperes3D
//
//*****************************************************************************
class MATH_DLL Reperes3D
{

public:


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	Reperes3D();
	Reperes3D(const Reperes3D&);
	~Reperes3D();


	Reperes3D( const Points3D& O,	const Vecteurs3D& I,
					const Vecteurs3D& J,
					const Vecteurs3D& K);

	Reperes3D( const Points3D& O,	const Vecteurs3D& K);


//*****************************************************************************
//	Accesseurs
//*****************************************************************************
	inline	const Points3D&		Origine()									const;
	inline	const Points3D&		OrigineInverse()							const;
	inline	const Matrices3D&		Base()										const;
	inline	const Matrices3D&		BaseInverse()								const;

	inline	void			ModifOrigine(const Points3D&);
	inline	void			ModifOrigineInverse(const Points3D&);
	inline	void			ModifBase(const Matrices3D&);
	inline	void			ModifBaseInverse(const Matrices3D&);



//*****************************************************************************
//	Methodes
//*****************************************************************************
	Points3D		RepereVersMonde(const Points3D&)								const;
	Vecteurs3D	RepereVersMonde(const Vecteurs3D&)							const;

	Points3D		MondeVersRepere(const Points3D&)								const;
	Vecteurs3D	MondeVersRepere(const Vecteurs3D&)							const;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
friend	ostream& MATH_DLL 	operator << (ostream&, const Reperes3D&);

friend  bool	   MATH_DLL 	operator == (const Reperes3D & , const Reperes3D &) ;
friend  bool	   MATH_DLL 	operator != (const Reperes3D & , const Reperes3D &) ;

	const	Reperes3D&  	operator =  (const Reperes3D&);


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	Matrices3D	matricePassage;
	Points3D	origine;

	Matrices3D	matriceInverse;
	Points3D	origineInverse;
};


#include	"Reperes3D.inl"


#endif	__Reperes3D__h__
