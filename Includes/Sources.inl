//*******************************************************************
//
// Fichier	: Sources.inl
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Inline de la classe Sources
//
//*******************************************************************



inline	const Points3D&	Sources::Position ()		const
{
	return _Position;
}


inline	void	Sources::ModifPosition (const Points3D& P)
{
	_Position	= P;
}


inline	Couleurs*	Sources::PtrCouleur ()		const
{
	return _Couleur;
}


inline	const Couleurs&	Sources::Couleur ()		const
{
	return *_Couleur;
}


inline	void	Sources::ModifCouleur (Couleurs* Coul)
{
	_Couleur	= Coul;
}


inline	double	Sources::Intensite ()		const
{
	return _Intensite;
}


inline	void	Sources::ModifIntensite (double I)
{
	_Intensite	= I;
}






