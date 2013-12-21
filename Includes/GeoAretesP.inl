//*****************************************************************************
//
// Module	: GeoAretesP
//
// Fichier	: GeoAretesP.inl
//
// Auteur	: Dartigues, Heschung
//
// Date creat.	: 15/06/99
//
// Version	:
//
// Commentaires	: Fonctions inlines de la classe GeoAretesP.
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//*****************************************************************************



//*****************************************************************************
//
// Includes
//
//*****************************************************************************



//*****************************************************************************
//
// Accesseurs
//
//*****************************************************************************
inline bool			GeoAretesP::EstAJour()	const
{
	return ajour ;
}


inline void			GeoAretesP::MettreAJour()
{
	ajour = True ;
}


inline void			GeoAretesP::PlusAJour()
{
	ajour = False ;
}


inline const Droites3D&	GeoAretesP::Droite3D()	const
{
	return D ;
}


inline void	GeoAretesP::ModifDroite3D(const Droites3D &Dr)
{
	D = Dr ;
}


