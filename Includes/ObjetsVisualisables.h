//*******************************************************************
//
// Fichier	: ObjetsVisualisables.h
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Interface de la classe ObjetsVisualisables
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_ObjetsVisualisables_h_
#define	_ObjetsVisualisables_h_


#include	"BibliothequeMateriaux.h"
#include	"BibliothequeMathematique.h"

#include	<iostream>
using namespace std ;
#include	"EnteteVisualiseurDLL.h"


class VISUALISEUR_DLL ObjetsVisualisables
 {
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	ObjetsVisualisables();
	virtual	~ObjetsVisualisables();

//*******************************************************************
//	Accesseurs
//*******************************************************************
inline	const Materiaux *	Materiau ()		const;
inline	void				ModifMateriau (const Materiaux * PM);

inline	const Englobants3D&		Englobant ()		const;
inline	void					ModifEnglobant (const Englobants3D& E);



//*******************************************************************
//	Partie privee
//*******************************************************************
private:

	Englobants3D		_Englobant;
	const Materiaux		*_PMateriau;

//-------------------------------------------------------------------
// Méthodes déclarées privées pour en interdire l'utilisation
//-------------------------------------------------------------------
	ObjetsVisualisables(const ObjetsVisualisables&);
	const ObjetsVisualisables&	operator = (const ObjetsVisualisables&);
friend	ostream& VISUALISEUR_DLL	operator<< (ostream&, const ObjetsVisualisables&);
};


#include	"ObjetsVisualisables.inl"

#endif

