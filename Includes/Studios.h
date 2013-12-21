//*******************************************************************
//
// Fichier	: Studios.h
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Interface de la classe Studios
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_Studios_h_
#define	_Studios_h_

#include	"EnteteVisualiseurDLL.h"

#include	"Sources.h"
#include	"BibliothequeMateriaux.h"
#include	"BibliothequeMathematique.h"

#include	"Listes.h"
#include	"Iterateurs.h"

#include	<iostream>
using namespace std ;


class VISUALISEUR_DLL Studios
 { 
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	Studios();
	Studios(const Studios&);
	~Studios();

//*******************************************************************
//	Accesseurs
//*******************************************************************
inline	const Listes<Sources>&		ListeSources ()			const;
inline	int				NbSources ()			const;
const Sources&	Source (int Num)		const;

void				ModifSource (int Num, const Sources& NouvSource);
// ATTENTION : un studio ne sachant pas à quelles vues, il
// appartient, l'utilisateur de cette fonction doit avertir la(les)
// vue(s) concernée(s) que son(leur) studio a changé !!!

inline	Couleurs*	PtrCouleurFond ()				const;
// restitue une copie de la couleur de fond

inline	void		ModifCouleurFond (Couleurs* Coul);
// libère l'ancienne couleur de fond
// ATTENTION : un studio ne sachant pas à quelles vues, il
// appartient, l'utilisateur de cette fonction doit avertir la(les)
// vue(s) concernée(s) que son(leur) studio a changé !!!

inline	double		CoefficientAmbiant ()				const;
inline	void		ModifCoefficientAmbiant (double Coef);
// ATTENTION : un studio ne sachant pas à quelles vues, il
// appartient, l'utilisateur de cette fonction doit avertir la(les)
// vue(s) concernée(s) que son(leur) studio a changé !!!

void		Ajouter (const Sources& S);
// ATTENTION : un studio ne sachant pas à quelles vues, il
// appartient, l'utilisateur de cette fonction doit avertir la(les)
// vue(s) concernée(s) que son(leur) studio a changé !!!

void		Supprimer (const Sources& S);
// ATTENTION : un studio ne sachant pas à quelles vues, il
// appartient, l'utilisateur de cette fonction doit avertir la(les)
// vue(s) concernée(s) que son(leur) studio a changé !!!



//*******************************************************************
//	Operateurs
//*******************************************************************
	const Studios&	operator = (const Studios&);

friend	ostream& VISUALISEUR_DLL	operator<< (ostream&, const Studios&);

//*******************************************************************
//	Partie privee
//*******************************************************************
private:

	Couleurs*	_CouleurFond;
	double	_CoefficientAmbiant;
	Listes<Sources>	_ListeSources;

};


#include	"Studios.inl"

#endif

