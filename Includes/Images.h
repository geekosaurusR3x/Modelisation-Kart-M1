//*******************************************************************
//
// Fichier	: Images.h
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Interface de la classe Images
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_Images_h_
#define	_Images_h_


#include	"Pixels.h"

#include	<iostream>
using namespace std ;
#include	"EnteteVisualiseurDLL.h"


class VISUALISEUR_DLL Images
 {
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	Images();
	Images(const Images&);

	Images (int Largeur, int Hauteur);

	~Images();

//*******************************************************************
//	Accesseurs
//*******************************************************************
inline	int		Largeur ()				const;
inline	int		Hauteur ()				const;

inline	const Pixels&	Pixel (int x, int y)			const;
inline	void		ModifPixel (int x, int y, const Pixels& P);

//*******************************************************************
//	Methodes
//*******************************************************************
void		Sauvegarder (const char* NomFichier)		const;
void		Charger (const char* NomFichier);

//*******************************************************************
//	Operateurs
//*******************************************************************
	const Images&	operator = (const Images&);

friend	ostream& VISUALISEUR_DLL	operator<< (ostream&, const Images&);

//*******************************************************************
//	Partie privee
//*******************************************************************
private:

	int	_Largeur;
	int	_Hauteur;
	Pixels	**tab;

};


#include	"Images.inl"

#endif

