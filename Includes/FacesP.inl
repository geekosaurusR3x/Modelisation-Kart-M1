//*****************************************************************************
//
// Module	: FacesP
//
// Fichier	: FacesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct inline de la classe FacesP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


//-----------------------------------------------------------------------------
inline const ContoursP FacesP::IemeContourInterieur (const int i) 	const
{
	return Representation ().Topologie ().IemeContourInterieur (i) ;
}

//-----------------------------------------------------------------------------
inline ContoursP *	FacesP::PtrIemeContourInterieur (const int i)
{
	return PtrRepresentation () -> PtrTopologie () -> PtrIemeContourInterieur (i) ;
}

//-----------------------------------------------------------------------------
inline const ContoursP FacesP::ContourExterieur () 			const
{
	return Representation ().Topologie ().ContourExterieur () ;
}

//-----------------------------------------------------------------------------
inline ContoursP *	FacesP::PtrContourExterieur ()
{
	return PtrRepresentation () -> PtrTopologie () -> PtrContourExterieur () ;
}

//-----------------------------------------------------------------------------
inline const Listes<ContoursP> FacesP::ListeContoursInterieurs ()		const
{
	return Representation ().Topologie ().ListeContoursInterieurs () ;
}


//-----------------------------------------------------------------------------
inline const Tableaux<ContoursP>	FacesP::TableauContoursInterieurs ()		const
{
	return Representation ().Topologie ().TableauContoursInterieurs () ;
}

//-----------------------------------------------------------------------------
inline const int	FacesP::NombreContoursInterieurs () 		const
{
	return Representation ().Topologie ().NombreContoursInterieurs () ;
}

//-----------------------------------------------------------------------------
inline Plans3D *		FacesP::PtrPlan ()
{
	return PtrRepresentation () -> PtrGeometrie () -> PtrPlan () ;
}


//-----------------------------------------------------------------------------
inline const SolidesP 		FacesP::Solide ()			const
{
	return Representation ().Topologie ().Solide () ;
}

//-----------------------------------------------------------------------------
inline SolidesP *		FacesP::PtrSolide ()
{
	return PtrRepresentation () -> PtrTopologie () -> PtrSolide () ;
}

//-----------------------------------------------------------------------------
inline Englobants3D *	FacesP::PtrEnglobant ()
{
	return PtrRepresentation () -> PtrGeometrie () -> PtrEnglobant () ;
}


//-----------------------------------------------------------------------------
inline void			FacesP::ModifSolide (const SolidesP & S)
{
	PtrRepresentation ()->PtrTopologie ()->ModifSolide (S) ;
}

//-----------------------------------------------------------------------------
inline void			FacesP::ModifEnglobant (const Englobants3D & E)
{
	PtrRepresentation ()->PtrGeometrie ()->ModifEnglobant (E) ;
}

//-----------------------------------------------------------------------------
inline void			FacesP::ModifPlan (const Plans3D & P)
{
	PtrRepresentation ()->PtrGeometrie ()->ModifPlan (P) ;
}

//-----------------------------------------------------------------------------
inline void			FacesP::ModifVecteurNormal (const Vecteurs3D & N)
{
	PtrRepresentation ()->PtrGeometrie ()->ModifVecteurNormal (N) ;
}

//-----------------------------------------------------------------------------
inline Listes<SommetsP>			FacesP::ListeSommets ()			const
{
	return Representation ().Topologie ().ListeSommets () ;
}

//-----------------------------------------------------------------------------
inline Tableaux<SommetsP>			FacesP::TableauSommets ()			const
{
	return Representation ().Topologie ().TableauSommets () ;
}


//-----------------------------------------------------------------------------
inline const int			FacesP::NombreSommets () 		const
{
	return Representation ().Topologie ().NombreSommets () ;
}

//-----------------------------------------------------------------------------
inline const SommetsP		FacesP::IemeSommet (int i) 	const
{
	return Representation ().Topologie ().IemeSommet (i) ;
}

inline const AttributsFacesP	*FacesP::Attribut () const
// Le pointeur restitué est un const * pour interdire la modif 
// de l'attribut (on restitue l'adresse de l'attribut conservé
// dans la face !
{
	return Representation ().Attribut () ;
}

inline void FacesP::ModifAttribut (const AttributsFacesP *PA)
// *PA est dupliqué donc PA doit être libéré par l'appelant après l'appel
{
	PtrRepresentation ()->ModifAttribut (PA) ;
}
