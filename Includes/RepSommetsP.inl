//*****************************************************************************
//
// Module	: RepSommetsP
//
// Fichier	: RepSommetsP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fcts inline de la classe RepSommetsP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************



//*****************************************************************************
//
// Includes
//
//*****************************************************************************



inline const GeoSommetsP& RepSommetsP::Geometrie () const
{	return (const GeoSommetsP&) GeometrieBRep () ;
}


inline const TopoSommetsP& RepSommetsP::Topologie () const
{	return (const TopoSommetsP&) TopologieBRep () ;
}


inline GeoSommetsP* RepSommetsP::PtrGeometrie ()
{	return (GeoSommetsP*) PtrGeometrieBRep () ;
}


inline TopoSommetsP* RepSommetsP::PtrTopologie ()
{	return (TopoSommetsP*) PtrTopologieBRep () ;
}


