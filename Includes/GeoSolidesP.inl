//*****************************************************************************
//
// Module	: GeoSolidesP
//
// Fichier	: GeoSolidesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Fonctions inlines de la classe GeoSolidesP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//*****************************************************************************



//*****************************************************************************
//
// Includes
//
//*****************************************************************************



//*****************************************************************************
//	Accesseurs
//*****************************************************************************


//-----------------------------------------------------
inline const Englobants3D &	GeoSolidesP::Englobant () const
{
	return E ;
}

//-----------------------------------------------------
inline Englobants3D *		GeoSolidesP::PtrEnglobant ()
{
	return (Englobants3D*)&E ;
}

//-----------------------------------------------------------
inline void	GeoSolidesP::ModifEnglobant (const Englobants3D & En)
{
	ajour = true ;
	E = En ;
}

//------------------------------------
inline bool	GeoSolidesP::EstAJour () const
{
	return ajour ;
}

//-------------------------------
inline void	GeoSolidesP::PlusAJour ()
{
	ajour = false ;
}

//-------------------------------
inline void	GeoSolidesP::MettreAJour ()
{
	ajour = true ;
}

