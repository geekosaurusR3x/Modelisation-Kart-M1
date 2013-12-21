//*****************************************************************************
//
// Module	: TopoContoursP
//
// Fichier	: TopoContoursP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct inline de la classe TopoContoursP
//
//
//*****************************************************************************
// Includes
// Classe TopoContoursP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


//-----------------------------------------------------------------------------
inline void TopoContoursP::SortirAreteOrientee(const AretesOrienteesP& AO )
// Permet la mise à jour du tableau des aretes orientees lors d'un
// SortirDuContour des classes TopoAretesOrienteesP et TopoAretesP.
{
	tabAretesOrientees.Supprimer(AO) ;
}


//-----------------------------------------------------------------------------
inline int 			TopoContoursP::NombreAretes () 			const
{
	return tabAretesOrientees.Nb_Effectifs() ;
}

//-----------------------------------------------------------------------------
inline Listes<AretesOrienteesP> TopoContoursP::ListeAretesOrientees () 	const
// 1 parcours
{
	return tabAretesOrientees ;
}


//-----------------------------------------------------------------------------
inline const Tableaux<AretesOrienteesP>& TopoContoursP::TableauAretesOrientees () const
{
	return tabAretesOrientees ;
}

//-----------------------------------------------------------------------------
inline int	TopoContoursP::NombreAretesOrientees () 	const
{
	return tabAretesOrientees.Nb_Effectifs() ;
}

//-----------------------------------------------------------------------------
inline const FacesP & 		TopoContoursP::Face () 				const
{
	return face ;
}

//-----------------------------------------------------------------------------
inline FacesP *		TopoContoursP::PtrFace ()
{
	return &face ;
}

//-----------------------------------------------------------------------------
inline void 		TopoContoursP::ModifFace (const FacesP& F)
{
	face = F ;
}

//-----------------------------------------------------------------------------
inline const Vecteurs3D  	TopoContoursP::VecteurNormal () 		const
{
	return face.VecteurNormal () ;
}

inline TopologiesBRep*	TopoContoursP::Dupliquer()	const
{
	return new TopoContoursP (*this) ;
}

