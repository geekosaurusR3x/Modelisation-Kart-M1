//*****************************************************************************
//
// Module	: RepSolidesP
//
// Fichier	: RepSolidesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 22/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct inline de la classe RepSolidesP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


//-------------------------------------------------------------
inline const GeoSolidesP &	RepSolidesP::Geometrie () const
{
	return (const GeoSolidesP &)GeometrieBRep () ;
}

//---------------------------------------------------------
inline GeoSolidesP *		RepSolidesP::PtrGeometrie ()
{
	return (GeoSolidesP *)PtrGeometrieBRep () ;
}

//-------------------------------------------------------------
inline const TopoSolidesP &	RepSolidesP::Topologie () const
{
	return (const TopoSolidesP &)TopologieBRep () ;
}

//----------------------------------------------------------
inline TopoSolidesP *		RepSolidesP::PtrTopologie ()
{
	return (TopoSolidesP *)PtrTopologieBRep () ;
}

inline const AttributsSolidesP	*RepSolidesP::Attribut () const
// Le pointeur restitu� est un const * pour interdire la modif 
// de l'attribut (on restitue l'adresse de l'attribut conserv�
// dans la face !
{
	return this->mPAttribut ;
}

inline void RepSolidesP::ModifAttribut (const AttributsSolidesP *PA)
// *PA est dupliqu� donc PA doit �tre lib�r� par l'appelant apr�s l'appel
{
	if (mPAttribut)
		delete mPAttribut ;

	mPAttribut = (PA) ? PA->Dupliquer () : NULL ;
}
