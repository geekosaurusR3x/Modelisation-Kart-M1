//*******************************************************************
//
// Fichier	: Sources.h
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Interface de la classe Sources
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_Sources_h_
#define	_Sources_h_


#include	"BibliothequeMateriaux.h"
#include	"BibliothequeMathematique.h"

#include	<iostream>
using namespace std ;
#include	"EnteteVisualiseurDLL.h"


class VISUALISEUR_DLL Sources
 {
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	Sources();
	Sources(const Sources&);

	Sources (const Points3D&, Couleurs* Coul, double I);

	~Sources();

//*******************************************************************
//	Accesseurs
//*******************************************************************
inline	const Points3D&	Position ()				const;
inline	void		ModifPosition (const Points3D& P);

inline	const Couleurs&	Couleur ()				const;
inline	Couleurs*	PtrCouleur ()				const;
inline	void		ModifCouleur (Couleurs* Coul);

inline	double		Intensite ()				const;
inline	void		ModifIntensite (double I);



//*******************************************************************
//	Operateurs
//*******************************************************************
	const Sources&	operator = (const Sources&);

friend	bool VISUALISEUR_DLL		operator== (const Sources& S1, const Sources& S2);
friend	bool VISUALISEUR_DLL		operator!= (const Sources& S1, const Sources& S2);

friend	ostream& VISUALISEUR_DLL	operator<< (ostream&, const Sources&);

//*******************************************************************
//	Partie privee
//*******************************************************************
private:

	Couleurs*	_Couleur;
	Points3D	_Position;
	double		_Intensite;

};


#include	"Sources.inl"

#endif

