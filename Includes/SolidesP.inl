//*****************************************************************************
//
// Module	: SolidesP
//
// Fichier	: SolidesP.inl
//
// Auteur	: Heschung
//
// Date creat.	: 22/07/99
//
// Version	:
//
// Commentaires	: Implementation des fcts inline de la classe SolidesP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


//-----------------------------------------------------------------------------
inline void SolidesP::GeometriePlusAJour ()
{
	PtrRepresentation () -> PtrGeometrie () -> PlusAJour () ;
}


//-----------------------------------------------------------------------------
inline int SolidesP::NombreFaces () const
{
	return Representation ().Topologie ().NombreFaces () ;
}

//-----------------------------------------------------------------------------
inline const FacesP 	SolidesP::IemeFace (const int i) const
{
	return Representation ().Topologie ().IemeFace (i) ;
}

//-----------------------------------------------------------------------------
inline FacesP *		SolidesP::PtrIemeFace (const int i)
{
	return PtrRepresentation () -> PtrTopologie () -> PtrIemeFace (i) ;
}

//-----------------------------------------------------------------------------
inline const Listes<FacesP>		SolidesP::ListeFaces () const
{
	return Representation ().Topologie ().ListeFaces () ;
}

//-----------------------------------------------------------------------------
inline const Tableaux<FacesP> &	SolidesP::TableauFaces () const
{
	return Representation ().Topologie ().TableauFaces () ;
}

//-----------------------------------------------------------------------------
inline Englobants3D *	SolidesP::PtrEnglobant ()
{
	return PtrRepresentation () -> PtrGeometrie () -> PtrEnglobant () ;

}

//-----------------------------------------------------------------------------
inline void		SolidesP::ModifEnglobant (const Englobants3D & E)
{
	PtrRepresentation () -> PtrGeometrie () -> ModifEnglobant (E) ;
}


//-----------------------------------------------------------------------------
inline const Listes<AretesP> 	SolidesP::ListeAretes () const
{
	return Representation ().Topologie ().ListeAretes () ;
}

//-----------------------------------------------------------------------------
inline const Tableaux<AretesP> 	SolidesP::TableauAretes () const
{
	return Representation ().Topologie ().TableauAretes () ;
}



//-----------------------------------------------------------------------------
inline int 	SolidesP::NombreAretes () const
{
	return Representation ().Topologie ().NombreAretes () ;
}

//-----------------------------------------------------------------------------
inline const AretesP 	SolidesP::IemeArete (const int i) const
{
	return Representation ().Topologie ().IemeArete (i) ;
}

//-----------------------------------------------------------------------------
inline const Listes<SommetsP> 	SolidesP::ListeSommets () const
{
	return Representation ().Topologie ().ListeSommets () ;
}


//-----------------------------------------------------------------------------
inline const Tableaux<SommetsP> 	SolidesP::TableauSommets () const
{
	return Representation ().Topologie ().TableauSommets () ;
}



//-----------------------------------------------------------------------------
inline int SolidesP::NombreSommets () const
{
	return Representation ().Topologie ().NombreSommets () ;
}

//-----------------------------------------------------------------------------
inline const SommetsP 		SolidesP::IemeSommet (const int i) const
{
	return Representation ().Topologie ().IemeSommet (i) ;
}

inline const AttributsSolidesP	*SolidesP::Attribut () const
// Le pointeur restitué est un const * pour interdire la modif 
// de l'attribut (on restitue l'adresse de l'attribut conservé
// dans la face !
{
	return Representation ().Attribut () ;
}

inline void SolidesP::ModifAttribut (const AttributsSolidesP *PA)
// *PA est dupliqué donc PA doit être libéré par l'appelant après l'appel
{
	PtrRepresentation ()->ModifAttribut (PA) ;
}
