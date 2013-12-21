//*****************************************************************************
// 
// Module	: CouleursRGB
// 
// Fichier	: CouleursRGB.h
// 
// Auteur	: lanuel							
// 
// Date creat.	: Tue Jul  9 16:42:21 MET DST 1996
// 
// Commentaires	: Interface de la classe CouleursRGB.
// 
// 
//*****************************************************************************
// Includes
// Classe CouleursRGB
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//		CouleursRGB
//	Surcharge des operateurs
//	Partie protegee
//	Partie privee
//*****************************************************************************



#ifndef __CouleursRGB__h__
#define __CouleursRGB__h__



//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************
#include	"BibliothequeMathematique.h"
#include	"Couleurs.h"

#include	"EnteteVisualiseurDLL.h"

#include	<iostream>
using namespace std ;


//*****************************************************************************
//
// Classe CouleursRGB
// 
//*****************************************************************************
class VISUALISEUR_DLL CouleursRGB	: public Couleurs
{
public:
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	CouleursRGB();
	CouleursRGB(const CouleursRGB&);
	~CouleursRGB();


	CouleursRGB(const Vecteurs3D&);
	CouleursRGB(double, double, double);


//*****************************************************************************
//	Accesseurs
//*****************************************************************************
	inline double		R()		const;
	inline double		G()		const;
	inline double		B()		const;


	inline const CouleursRGB&	R(double);
	inline const CouleursRGB&	G(double);
	inline const CouleursRGB&	B(double);


//*****************************************************************************
//	Methodes
//*****************************************************************************
	Vecteurs3D	ComposantesRGB()	const;

	Couleurs*	Allocation()		const;
	Couleurs*	Dupliquer()		const;
	void		Filtre();

	double		ReflectanceMoyenne()	const;


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const Couleurs&	operator =  (const Couleurs&);
	const Couleurs& operator *= (double);
	const Couleurs& operator += (const Couleurs&);
	const Couleurs& operator *= (const Couleurs&);

friend	const CouleursRGB&  VISUALISEUR_DLL operator +  (const CouleursRGB&, const CouleursRGB&);
friend	const CouleursRGB&  VISUALISEUR_DLL operator *  (const CouleursRGB&, const CouleursRGB&);
friend	const CouleursRGB&  VISUALISEUR_DLL operator *  (double, const CouleursRGB&);

friend	ostream& VISUALISEUR_DLL		operator << (ostream&, const CouleursRGB&);



//*****************************************************************************
//	Partie protegee
//*****************************************************************************
protected:
	ostream&	Aff(ostream&)		const;

	const Couleurs&	Add(const Couleurs&)	const;
	const Couleurs&	Mult(const Couleurs&)	const;

	const Couleurs&	Mult(double)		const;
	const Couleurs& DoubleMoins(double)	const;


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	double	val[3];

};



#include	"RGB.inl"



#endif	__CouleursRGB__h__
