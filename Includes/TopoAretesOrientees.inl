//*****************************************************************************
//
// Module	: TopoAretesOrienteesP
//
// Fichier	: TopoAretesOrienteesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 22/07/99
//
// Version	:
//
// Commentaires	: Implementation des fcts inline de la classe TopoAretesOrienteesP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


inline const SommetsP		TopoAretesOrienteesP::Origine()		const
{
	return (Sens() ? Arete().Sommet1() : Arete().Sommet2());
}



inline SommetsP*		TopoAretesOrienteesP::PtrOrigine()
{
	return (Sens() ? PtrArete()->PtrSommet1() : PtrArete()->PtrSommet2() );
}



inline const SommetsP	TopoAretesOrienteesP::Extremite()		const
{
	return (!Sens() ? Arete().Sommet1() : Arete().Sommet2());
}



inline const AretesP&	TopoAretesOrienteesP::Arete()			const
{
	return arete;
}



inline AretesP *	TopoAretesOrienteesP::PtrArete ()
{
	return &arete ;
}




inline const ContoursP	TopoAretesOrienteesP::Contour()		const
{
	return (Sens() ? Arete().Contour1() : Arete().Contour2());
}

inline bool		TopoAretesOrienteesP::Sens()			const
{
	return sens;
}

inline TopologiesBRep*	TopoAretesOrienteesP::Dupliquer()	const
{
	return new TopoAretesOrienteesP (*this) ;
}
