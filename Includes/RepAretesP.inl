//*****************************************************************************
//
// Module	: RepAretesP
//
// Fichier	: RepAretesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct inline de la classe RepAretesP
//
//
//*****************************************************************************
// Includes
// Classe RepAretesP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


inline const GeoAretesP&	RepAretesP::Geometrie()	const
{
	return (const GeoAretesP&)(*geometrie);
}


inline GeoAretesP*		RepAretesP::PtrGeometrie()
{
	return (GeoAretesP*)geometrie;
}


inline const TopoAretesP&	RepAretesP::Topologie()	const
{
	return (const TopoAretesP&)(*topologie);
}


inline TopoAretesP*		RepAretesP::PtrTopologie()
{
	return (TopoAretesP*)topologie;
}