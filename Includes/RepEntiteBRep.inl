//*****************************************************************************
//
// Module	: RepEntitesBRep
//
// Fichier	: RepEntitesBRep.h
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 31/08/99
//
// Version	:
//
// Commentaires	: Fonctions inline  de la classe RepEntitesBRep.



inline const TypeCle	RepEntitesBRep::Cle()		const
{
	return cle;
}


inline void		RepEntitesBRep::ModifCle(TypeCle C)
{
	cle	= C;
}



inline const GeometriesBRep&	RepEntitesBRep::GeometrieBRep()		const
{
	return *geometrie;
}


inline GeometriesBRep*		RepEntitesBRep::PtrGeometrieBRep()
{
	return geometrie;
}


inline const TopologiesBRep&	RepEntitesBRep::TopologieBRep()		const
{
	return *topologie;
}


inline TopologiesBRep*		RepEntitesBRep::PtrTopologieBRep()
{
	return topologie;
}
