//*****************************************************************************
//
// Module	: RepAretesOrienteesP
//
// Fichier	: RepAretesOrienteesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fcts inline de la classe RepAretesOrienteesP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


//-----------------------------------------------------------------------------
inline const TopoAretesOrienteesP &RepAretesOrienteesP::Topologie () 	const
{
	return (const TopoAretesOrienteesP &)TopologieBRep () ;
}




//-----------------------------------------------------------------------------
inline TopoAretesOrienteesP *		RepAretesOrienteesP::PtrTopologie ()
{
	return (TopoAretesOrienteesP *)PtrTopologieBRep () ;
}



//-----------------------------------------------------------------------------
inline const GeoAretesOrienteesP& RepAretesOrienteesP::Geometrie () const
{
	return (const GeoAretesOrienteesP &) GeometrieBRep () ;
}
