//*****************************************************************************
// 
// Module	: Vecteurs3D
// 
// Fichier	: Vecteurs3D.h
// 
// Auteur	: Y. LANUEL	, MINICH
// 
// Date creat.	: 18/05/96							
// 
// Commentaires	: Interface de la classe Vecteurs3D.
// 
// 
//*****************************************************************************
// Includes
// Classe Vecteurs3D
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//		Norme()
//		NormeCarree()
//		VecteurNorme()
//		VecteurReflechi(N)
//		VecteurTransmis(N,ni,nt)
//		VecteurH(N)
//		VecteurHt(T,ni,nt)
//	Surcharge des operateurs
//		Operations Vecteurs/Vecteurs
//		Operations Vecteurs/double
//		Operations Vecteurs/Matrices
//		Operations Vecteurs/Points
//	Partie privee
//
//*****************************************************************************
//*****************************************************************************



#ifndef __Vecteurs3D__h__
#define	__Vecteurs3D__h__	1



//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************
#include	<iostream> 
using namespace std ;


#include	"Points3D.h"
#include	"Matrices3D.h"
#include	"Matrices4D.h"

#include	"EnteteMathDLL.h"


//*****************************************************************************
//
// Classe Vecteurs3D
//
//*****************************************************************************
class MATH_DLL Vecteurs3D
{

public:


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	Vecteurs3D();
	Vecteurs3D(const Vecteurs3D&);
	~Vecteurs3D();
	
	Vecteurs3D(double, double, double);
	Vecteurs3D(const Points3D&, const Points3D&);


//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline 	double	X()	const;
inline 	double	Y()	const;
inline 	double	Z()	const;


	inline	void	ModifX(double);
	inline	void	ModifY(double);
	inline	void	ModifZ(double);


//*****************************************************************************
//	Methodes
//*****************************************************************************


	double		Norme()					const;

	double		NormeCarree()			const;

	Vecteurs3D	VecteurNorme()				const;

	double		EstColineaire (const Vecteurs3D &V) const ;
	// retourne faux (0) si les vecteurs ne sont pas colin�aires.
	// Sinon,
	// 	si l'un au moins des vecteurs est nul, le r�sultat est 1 par convention.
	// 	sinon le r�sultat est k tel que *this = k.V.
	// k peut donc �tre n�gatif
	// La colin�arit� est test�e en tenant compte d'une tol�rance : on teste
	// donc une quasi-colin�arit�.
   // MIEUX VAUT UTILISER LA VERSION QUI SUIT

	double EstColineaire (const Vecteurs3D &V, double AngleEnDegres) const ;
	// retourne faux (0) si les vecteurs ne sont pas colin�aires.
	// Sinon,
	// 	si l'un au moins des vecteurs est nul, le r�sultat est 1 par convention.
	// 	sinon le r�sultat est k tel que *this = k.V.
	// k peut donc �tre n�gatif
	// La colin�arit� est test�e en tenant compte d'une tol�rance : on teste
	// donc une quasi-colin�arit�. Le deuxi�me param�tre est l'angle EN DEGRES
	// en de�� duquel il faut consid�rer que les vecteurs sont colin�aires.
	// Cette version a l'avantage de ne pas d�pendre des dimensions de l'espace
	// dans lequel on travaille, � l'inverse de la pr�c�dente qui se fonde sur
	// un principe diff�rent et sur des epsilons fig�s.
	// Apr�s essai, il semble que 0.5 ou 0.25 degr�s donnent de bons r�sultats.

   Vecteurs3D	VecteurPerpendiculaireNorme () const;
   // Restitue un vecteur norm� perpendiculaire � *this.
	// Si *this est nul, le r�sultat est I (1,0,0)

   
//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	friend	ostream&    MATH_DLL operator << (ostream&, const Vecteurs3D&);

	const	Vecteurs3D& operator =  (const Vecteurs3D&);

	const	Vecteurs3D& operator +=	(const Vecteurs3D&);
	const	Vecteurs3D& operator -=	(const Vecteurs3D&);
	const	Vecteurs3D& operator *=	(double);
	const	Vecteurs3D& operator /=	(double);

	double operator [] (int i) const ;
	// Attention : i varie  de 0 � 2 !!

friend	bool		MATH_DLL operator == (const Vecteurs3D&, const Vecteurs3D&);
friend	bool		MATH_DLL operator != (const Vecteurs3D&, const Vecteurs3D&);


//*****************************************************************************
//		Operations Vecteurs/Vecteurs
//*****************************************************************************
friend	Vecteurs3D   MATH_DLL operator - (const Vecteurs3D&);

friend	double	   MATH_DLL operator * (const Vecteurs3D&, 	// Prod. Scal.
					const Vecteurs3D&);

friend	Vecteurs3D MATH_DLL operator + (const Vecteurs3D&,
					const Vecteurs3D&);

friend	Vecteurs3D MATH_DLL operator - (const Vecteurs3D&,
					const Vecteurs3D&);

friend	Vecteurs3D MATH_DLL operator & (const Vecteurs3D&, 	// Prod. Vect.
							const Vecteurs3D&);


//*****************************************************************************
//		Operations Vecteurs/double
//*****************************************************************************
	friend	Vecteurs3D MATH_DLL operator * (double,
										const Vecteurs3D&);

	friend	Vecteurs3D MATH_DLL operator / (const Vecteurs3D&,
										double);


//*****************************************************************************
//		Operations Vecteurs/Matrices
//*****************************************************************************
	friend	Vecteurs3D MATH_DLL operator * (const Vecteurs3D&, const Matrices3D&);
	friend	Vecteurs3D MATH_DLL operator * (const Matrices3D&, const Vecteurs3D&);
	friend	Vecteurs3D MATH_DLL operator * (const Vecteurs3D&, const Matrices4D&);

//*****************************************************************************
//		Operations Vecteurs/Points
//*****************************************************************************
	friend	Points3D   MATH_DLL operator + (const Points3D&, const Vecteurs3D&);
	friend	Points3D   MATH_DLL operator - (const Points3D&, const Vecteurs3D&);

//*****************************************************************************
//	Partie privee
//*****************************************************************************
public:

	double	m[3];



	Vecteurs3D	VecteurReflechi(
					const Vecteurs3D& N)	const;

	Vecteurs3D	VecteurTransmis(
					const Vecteurs3D& N,
					double ni,
					double nt	)	const;

	Vecteurs3D	VecteurH(
					const Vecteurs3D& L)	const;


	Vecteurs3D	VecteurHt(
					const Vecteurs3D& T,
				 	double ni,
				  	double nt	)	const;
};

extern MATH_DLL Vecteurs3D	*IMonde ;
extern MATH_DLL Vecteurs3D	*JMonde ;
extern MATH_DLL Vecteurs3D	*KMonde ;


#include	"Vecteurs3D.inl"



#endif	__Vecteurs3D__h__
