//*******************************************************************
//
// Fichier	: Studios.inl
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Inline de la classe Studios
//
//*******************************************************************


#include	"Iterateurs.h"


inline	const Listes<Sources>&	Studios::ListeSources ()		const
{
	return _ListeSources;
}


inline	int	Studios::NbSources ()		const
{
	return _ListeSources.Nb_Elements();
}





inline	Couleurs*	Studios::PtrCouleurFond ()		const
{
	return _CouleurFond->Dupliquer () ;
}


inline	void	Studios::ModifCouleurFond (Couleurs* Coul)
// ATTENTION : un studio ne sachant pas à quelles vues, il
// appartient, l'utilisateur de cette fonction doit avertir la(les)
// vue(s) concernée(s) que son(leur) studio a changé !!!
{
	delete _CouleurFond ;
	_CouleurFond	= Coul->Dupliquer () ;
}


inline	double	Studios::CoefficientAmbiant ()		const
{
	return _CoefficientAmbiant;
}


inline	void	Studios::ModifCoefficientAmbiant (double Coef)
// ATTENTION : un studio ne sachant pas à quelles vues, il
// appartient, l'utilisateur de cette fonction doit avertir la(les)
// vue(s) concernée(s) que son(leur) studio a changé !!!
{
	_CoefficientAmbiant	= Coef;
}






