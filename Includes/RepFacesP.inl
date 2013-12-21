//*****************************************************************************
//
// Module	: RepFacesP
//
// Fichier	: RepFacesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fcts inline de la classe RepFacesP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


//-----------------------------------------------------------------------------
inline const GeoFacesP &	RepFacesP::Geometrie () 				const
{
	return (const GeoFacesP &)GeometrieBRep () ;
}

//-----------------------------------------------------------------------------
inline GeoFacesP *		RepFacesP::PtrGeometrie ()
{
	return (GeoFacesP *)PtrGeometrieBRep () ;
}

//-----------------------------------------------------------------------------
inline const TopoFacesP &	RepFacesP::Topologie () 				const
{
	return (const TopoFacesP &)TopologieBRep () ;
}

//-----------------------------------------------------------------------------
inline TopoFacesP *		RepFacesP::PtrTopologie ()
{
	return (TopoFacesP *)PtrTopologieBRep () ;
}

inline const AttributsFacesP	*RepFacesP::Attribut () const
// Le pointeur restitu� est un const * pour interdire la modif 
// de l'attribut (on restitue l'adresse de l'attribut conserv�
// dans la face !
{
	return this->mPAttribut ;
}

inline void RepFacesP::ModifAttribut (const AttributsFacesP *PA)
// *PA est dupliqu� donc PA doit �tre lib�r� par l'appelant apr�s l'appel
{
	if (mPAttribut)
		delete mPAttribut ;

	mPAttribut = (PA) ? PA->Dupliquer () : NULL ;
}
