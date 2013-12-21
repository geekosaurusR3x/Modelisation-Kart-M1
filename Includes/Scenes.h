//*******************************************************************
//
// Fichier	: Scenes.h
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Interface de la classe Scenes
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_Scenes_h_
#define	_Scenes_h_

#include	"EnteteVisualiseurDLL.h"
#include	"ObjetsVisualisables.h"
#include	"BibliothequeMathematique.h"

#include	"Listes.h"
#include	"Iterateurs.h"

#include	<iostream>
using namespace std ;


class VISUALISEUR_DLL Scenes
 {
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	Scenes();
	Scenes(const Scenes&);
	~Scenes();

//*******************************************************************
//	Accesseurs
//*******************************************************************
inline	const Listes<ObjetsVisualisables*>&		ListeObjets ()		const;
inline	 Listes<ObjetsVisualisables*>&		ListeObjets ()		;

	void	Ajouter (ObjetsVisualisables* Obj, ElemListes <ObjetsVisualisables*> **PPM);
	// Ajoute Obj en tête de la scène. *PPM est l'adresse du maillon
	// qui contient Obj.

	void	Supprimer (ObjetsVisualisables* Obj);

//*******************************************************************
//	Methodes
//*******************************************************************
Englobants3D		Englobant ()				const;

//*******************************************************************
//	Operateurs
//*******************************************************************
	const Scenes&	operator = (const Scenes&);

//*******************************************************************
//	Partie privee
//*******************************************************************
private:

	Listes<ObjetsVisualisables*>	_ListeObjets;

//-------------------------------------------------------------------
// Méthodes déclarées privées pour en interdire l'utilisation
//-------------------------------------------------------------------
friend	ostream&  VISUALISEUR_DLL	operator<< (ostream&, const Scenes&);

};


#include	"Scenes.inl"

#endif

