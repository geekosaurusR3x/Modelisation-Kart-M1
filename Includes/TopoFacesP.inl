//*****************************************************************************
//
// Module	: TopoFacesP
//
// Fichier	: TopoFacesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct de la classe TopoFacesP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************



//---------------------------------------------------------------------------
inline void		TopoFacesP::AjouterContourInterieur (const ContoursP & C)
{
	TContours[TContours.Nb_Effectifs()] = C ;  // Ajout en queue
}

inline void		TopoFacesP::RetirerContourInterieur (const ContoursP & C)
{
	TContours.Supprimer (C) ;
}

//---------------------------------------------------------------------------
inline const int	TopoFacesP::NombreContoursInterieurs () 		const
{
	return TContours.Nb_Effectifs() - 1 ;
}

//---------------------------------------------------------------------------
inline const ContoursP	TopoFacesP::IemeContourInterieur (const int i) 	const
// le premier contour intérieur a le numéro 0 !!!!
{
	// Dans le tableau des contours, les CI commence en 1.
   if (TContours.Nb_Effectifs() <= 1) return ContourErreur ;

	return ((TopoFacesP&)*this).TContours[1+(i%(TContours.Nb_Effectifs()-1))] ;
}

//---------------------------------------------------------------------------
inline ContoursP *	TopoFacesP::PtrIemeContourInterieur (const int i)
{
	// Dans le tableau des contours, les CI commence en 1.
   if (TContours.Nb_Effectifs() <= 1) return &ContourErreur ;

	return &(TContours[1+(i%(TContours.Nb_Effectifs()-1))]) ;
}


//---------------------------------------------------------------------------
inline const ContoursP	TopoFacesP::ContourExterieur () 		const
{
	return ((TopoFacesP&)*this).TContours[0] ;
}

//---------------------------------------------------------------------------
inline ContoursP *	TopoFacesP::PtrContourExterieur ()
{
	return &(TContours[0]) ;
}

//---------------------------------------------------------------------------
inline const SolidesP	TopoFacesP::Solide ()				const
{
	return Sol ;
}

//---------------------------------------------------------------------------
inline SolidesP *	TopoFacesP::PtrSolide ()
{
	return (SolidesP *)&Sol ;
}

//---------------------------------------------------------------------------
inline void			TopoFacesP::ModifSolide (const SolidesP & S)
{
	Sol = S ;
}

//---------------------------------------------------------------------------
inline const int		TopoFacesP::NombreSommets () 			const
{
	return TableauSommets ().Nb_Effectifs() ;
}


//---------------------------------------------------------------------------
inline TopologiesBRep *	TopoFacesP::Dupliquer ()			const
{
	return new TopoFacesP(*this) ;
}
