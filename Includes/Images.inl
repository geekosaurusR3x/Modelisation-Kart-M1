//*******************************************************************
//
// Fichier	: Images.inl
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Inline de la classe Images
//
//*******************************************************************



inline	int	Images::Largeur ()		const
{
	return _Largeur;
}


inline	int	Images::Hauteur ()		const
{
	return _Hauteur;
}


inline	const Pixels&	Images::Pixel (int x, int y)		const
{
	return	tab[y][x];
}


inline	void	Images::ModifPixel (int x, int y, const Pixels& P)
{
	tab[y][x]	= P;
}






