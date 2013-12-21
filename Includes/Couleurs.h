//*****************************************************************************
// 
// Module	: Couleurs
// 
// Fichier	: Couleurs.h
// 
// Auteur	: lanuel							
// 
// Date creat.	: Tue Jul  9 16:36:46 MET DST 1996
// 
// Commentaires	: Interface de la classe Couleurs.
// 
// 
//*****************************************************************************
// Includes
// Classe Couleurs
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//		ComposantesRGB()	: Renvoie un vecteur contenant les
//					trois composantes RGB
//		Allocation()		: Constructeur par defaut virtuel
//		Filtre()		: Ramene a 0 les lg d'onde < 0
//	Surcharge des operateurs
//	Partie protegee
//	Partie privee
//*****************************************************************************



#ifndef __Couleurs__h__
#define __Couleurs__h__



//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************
#include	"BibliothequeMathematique.h"

#include	"EnteteVisualiseurDLL.h"

#include	<iostream>
using namespace std ;


//*****************************************************************************
// 
// Classe Couleurs
// 
//*****************************************************************************
class VISUALISEUR_DLL Couleurs
{

public:


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************

	Couleurs();
	Couleurs(const Couleurs&);
virtual ~Couleurs();


//*****************************************************************************
//	Accesseurs
//*****************************************************************************


//*****************************************************************************
//	Methodes
//*****************************************************************************
virtual	Vecteurs3D	ComposantesRGB()	const	= 0;

virtual	Couleurs*	Allocation()		const	= 0;
virtual	Couleurs*	Dupliquer()		const	= 0;
virtual void		Filtre()			= 0;

virtual double		ReflectanceMoyenne()	const	= 0;


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
virtual const Couleurs& operator =  (const Couleurs&)	= 0;
virtual const Couleurs& operator *= (double)		= 0;
virtual const Couleurs& operator += (const Couleurs&)	= 0;
virtual const Couleurs& operator *= (const Couleurs&)	= 0;

friend	const Couleurs&  VISUALISEUR_DLL operator +  (const Couleurs&, const Couleurs&);
friend	const Couleurs&  VISUALISEUR_DLL operator *  (const Couleurs&, const Couleurs&);

friend	const Couleurs&  VISUALISEUR_DLL operator *  (double, const Couleurs&);
friend	const Couleurs&  VISUALISEUR_DLL operator *  (const Couleurs&, double);
friend	const Couleurs&  VISUALISEUR_DLL operator -  (double, const Couleurs&);

friend	ostream&	VISUALISEUR_DLL operator << (ostream&, const Couleurs&);



//*****************************************************************************
//	Partie protegee
//*****************************************************************************
protected:

virtual	ostream&	Aff(ostream&)				const	= 0;

virtual	const Couleurs&	Add(const Couleurs&)			const 	= 0;
virtual	const Couleurs&	Mult(const Couleurs&)			const	= 0;

virtual	const Couleurs&	Mult(double)				const	= 0;
virtual	const Couleurs&	DoubleMoins(double)			const	= 0;


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

};



#include	"Couleurs.inl"



#endif	__Couleurs__h__
