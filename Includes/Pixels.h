//*******************************************************************
//
// Fichier	: Pixels.h
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Interface de la classe Pixels
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_Pixels_h_
#define	_Pixels_h_


#include	"BibliothequeMathematique.h"

#include	<iostream>
using namespace std ;
#include	"EnteteVisualiseurDLL.h"


class VISUALISEUR_DLL Pixels
 {
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	Pixels();
	Pixels(const Pixels&);

	Pixels (double r, double g, double b);
	Pixels (const Vecteurs3D& Vecteur);

	~Pixels();

//*******************************************************************
//	Accesseurs
//*******************************************************************
inline	double		R ()		const;
inline	double		G ()		const;
inline	double		B ()		const;

//*******************************************************************
//	Operateurs
//*******************************************************************
	const Pixels&	operator = (const Pixels&);

friend	ostream& VISUALISEUR_DLL	operator<< (ostream&, const Pixels&);

//*******************************************************************
//	Partie privee
//*******************************************************************
private:

	unsigned char	_R;
	unsigned char	_G;
	unsigned char	_B;

};


#include	"Pixels.inl"

#endif

