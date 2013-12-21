//*******************************************************************
//
// Fichier	: AlgosVisu.h
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Interface de la classe AlgosVisu
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_AlgosVisu_h_
#define	_AlgosVisu_h_



#include	<iostream>
using namespace std ;

#include	"EnteteVisualiseurDLL.h"
class VISUALISEUR_DLL		Vues;


class VISUALISEUR_DLL AlgosVisu
 {
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	AlgosVisu();
	~AlgosVisu();

//*******************************************************************
//	Accesseurs
//*******************************************************************
inline	Vues*		PtrVue ();
inline	const Vues&	Vue ()				const;
inline	void		ModifVue (Vues* V);

//*******************************************************************
//	Methodes
//*******************************************************************
virtual	void		CalculerImage ()		= 0;

//*******************************************************************
//	Partie privee
//*******************************************************************
protected:

	Vues	*_Vue;

//-------------------------------------------------------------------
// Méthodes déclarées privées pour en interdire l'utilisation
//-------------------------------------------------------------------
	AlgosVisu(const AlgosVisu&);
	const AlgosVisu&	operator = (const AlgosVisu&);

friend	ostream& VISUALISEUR_DLL	operator<< (ostream&, const AlgosVisu&);
};


#include	"AlgosVisu.inl"

#endif

