
//*****************************************************************************
// 
// Module	: Spectres
// 
// Fichier	: Spectres.h
// 
// Auteur	: lanuel							
// 
// Date creat.	: Tue Jul  9 16:49:32 MET DST 1996
// 
// Commentaires	: Interface de la classe Spectres.
// 
// 
//*****************************************************************************
// Includes
// Classe Spectres
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie protegee
//	Partie privee
//*****************************************************************************



#ifndef __Spectres__h__
#define __Spectres__h__



//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************
#include	"BibliothequeMathematique.h"

#include	"EnteteVisualiseurDLL.h"

#include	<iostream>
using namespace std ;


class	VISUALISEUR_DLL Couleurs;



#define	MIN_SPECTRE	380
#define	MAX_SPECTRE	780
#define	DIM_SPECTRE	MAX_SPECTRE-MIN_SPECTRE+1

//*****************************************************************************
//
// Classe Spectres
// 
//*****************************************************************************
class VISUALISEUR_DLL Spectres	: public Couleurs
{

public:


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************

	Spectres();
	Spectres(const Spectres&);
	~Spectres();
	

	Spectres(const char*);
        Spectres(double* Tab);



//*****************************************************************************
//	Accesseurs
//*****************************************************************************
static	void	Chemin(const char*);


//*****************************************************************************
//	Methodes
//*****************************************************************************
	double		Aire()			const;

	Vecteurs3D	ComposantesXYZ()	const;
	Vecteurs3D	ComposantesRGB()	const;

	Couleurs*	Allocation()		const;
	Couleurs*	Dupliquer()		const;

	void		Filtre();

	double		ReflectanceMoyenne()	const;



//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
friend	ostream&  VISUALISEUR_DLL 	operator << (ostream&, const Spectres&);
friend	istream&  VISUALISEUR_DLL 	operator >> (istream&, Spectres&);
	
	const	Couleurs& operator =  (const Couleurs&);
	const 	Couleurs& operator *= (double);
	const 	Couleurs& operator += (const Couleurs&);
	const 	Couleurs& operator *= (const Couleurs&);
	
friend	const Spectres&  VISUALISEUR_DLL 	operator +  (const Spectres&, const Spectres&);
friend	const Spectres&  VISUALISEUR_DLL 	operator *  (const Spectres&, const Spectres&);

friend	const Spectres&  VISUALISEUR_DLL 	operator *  (double, const Spectres&);



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

	double	val[DIM_SPECTRE];

static	char	chemin[200];

};



extern	VISUALISEUR_DLL Spectres	X_tristim;
extern	VISUALISEUR_DLL Spectres	Y_tristim;
extern	VISUALISEUR_DLL Spectres	Z_tristim;



#include	"Spectres.inl"



#endif	__Spectres__h__
