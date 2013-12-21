//*****************************************************************************
//
// Module	: GeoSommetsP
//
// Fichier	: GeoSommetsP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct inline de la classe GeoSommetsP
//
//
//*****************************************************************************
// Includes
// Classe GeoSommetsP
//	Accesseurs
//*****************************************************************************






//*****************************************************************************
//	Accessseurs
//*****************************************************************************


inline const Points3D& GeoSommetsP::Point3D () const
{	return point3D ;
}

inline void GeoSommetsP::ModifPoint3D (const Points3D &P)
{	point3D = P ;
}