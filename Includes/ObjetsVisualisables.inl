//*******************************************************************
//
// Fichier	: ObjetsVisualisables.inl
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Inline de la classe ObjetsVisualisables
//
//*******************************************************************



inline	const Materiaux *	ObjetsVisualisables::Materiau ()		const
{
	return _PMateriau;
}


inline	void	ObjetsVisualisables::ModifMateriau (const Materiaux * PM)
{
	_PMateriau		= PM ;
}


inline	const Englobants3D&	ObjetsVisualisables::Englobant ()		const
{
	return _Englobant;
}


inline	void	ObjetsVisualisables::ModifEnglobant (const Englobants3D& E)
{
	_Englobant	= E;
}






