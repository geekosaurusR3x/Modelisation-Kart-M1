//*****************************************************************************
//
// Module	: TopoSolidesP
//
// Fichier	: TopoSolidesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des  fcts de la classe TopoSolidesP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************



//--------------------------------------------------
inline void 	TopoSolidesP::AjouterFace (FacesP & F)
{
	TFaces[TFaces.Nb_Effectifs()] = F ;  // Ajout en queue
}

//--------------------------------------------------
inline void 	TopoSolidesP::AjouterFaces ( const Listes<FacesP> & LF)
{
	TFaces = TFaces + LF ;
}

//--------------------------------------------------
inline void 	TopoSolidesP::AjouterFaces ( const Tableaux<FacesP> & TF)
{
	TFaces = TFaces + TF ;
}

//----------------------------------------
inline int	TopoSolidesP::NombreFaces () const
{
	return TFaces.Nb_Effectifs () ;
}


//--------------------------------------------------------
inline const FacesP 	TopoSolidesP::IemeFace (const int i) const
// premiere face a le numéro 0 !!
{
	// On prend le modulo pour boucler lorsque l'on veut parcourir
	return ((TopoSolidesP&)*this).  TFaces[i%TFaces.Nb_Effectifs()] ;
}

//--------------------------------------------------------
// premiere face a le numéro 0 !!
inline FacesP *	TopoSolidesP::PtrIemeFace (const int i)
{
	return & ( TFaces[i%TFaces.Nb_Effectifs()] ) ;
}

//-------------------------------------------------------
inline const Listes<FacesP>	TopoSolidesP::ListeFaces () const
// 1 copie
{
	return TFaces ;
}


//-------------------------------------------------------
inline const Tableaux<FacesP>&	TopoSolidesP::TableauFaces () const
{
	return TFaces ;
}

//-----------------------------------------
inline int	TopoSolidesP::NombreAretes () const
{
	return ListeAretes().Nb_Elements() ;
}

//------------------------------------------
inline int	TopoSolidesP::NombreSommets () const
{
	return ListeSommets ().Nb_Elements () ;
}

inline TopologiesBRep*	TopoSolidesP::Dupliquer()	const
{
	return new TopoSolidesP (*this) ;
}
