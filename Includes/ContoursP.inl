//*****************************************************************************
//
// Module	: ContoursP
//
// Fichier	: ContoursP.cc
//
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 10:36:36 MET 1997
//
// Version	:
//
// Commentaires	: Implementation de la classe ContoursP
//
//
//*****************************************************************************
// Includes
// Classe ContoursP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


inline Listes<AretesOrienteesP> ContoursP::ListeAretesOrientees () const
{
	return Representation ().Topologie ().ListeAretesOrientees () ;
}

//-----------------------------------------------------------------------------
inline const Tableaux<AretesOrienteesP>& ContoursP::TableauAretesOrientees () const
{
	return Representation ().Topologie ().TableauAretesOrientees () ;
}

//-----------------------------------------------------------------------------
inline Listes<AretesP> 	ContoursP::ListeAretes () 		const
{
	return Representation ().Topologie ().ListeAretes () ;
}


//-----------------------------------------------------------------------------
inline Tableaux<AretesP> 	ContoursP::TableauAretes () 		const
{
	return Representation ().Topologie ().TableauAretes () ;
}

//-----------------------------------------------------------------------------
inline int				ContoursP::NombreAretes () 		const
{
	return Representation ().Topologie ().NombreAretes () ;
}

//-----------------------------------------------------------------------------
inline const AretesP  		ContoursP::IemeArete (const int i) 	const
{
	return Representation ().Topologie ().IemeArete (i) ;
}

//-----------------------------------------------------------------------------
inline AretesP*			ContoursP::PtrIemeArete (const int i)
{
	return PtrRepresentation () -> PtrTopologie () -> PtrIemeArete (i) ;
}

//-----------------------------------------------------------------------------
inline int 			ContoursP::NombreAretesOrientees () 	const
{
	return Representation ().Topologie ().NombreAretesOrientees () ;
}

//-----------------------------------------------------------------------------
inline const AretesOrienteesP ContoursP::IemeAreteOrientee (const int i) const
{
	return Representation ().Topologie ().IemeAreteOrientee (i) ;
}

//-----------------------------------------------------------------------------
inline AretesOrienteesP *	ContoursP::PtrIemeAreteOrientee ( int i)
{
	return PtrRepresentation () -> PtrTopologie () -> PtrIemeAreteOrientee (i) ;
}

//-----------------------------------------------------------------------------
inline const FacesP & 		ContoursP::Face () 			const
{
	return Representation ().Topologie ().Face () ;
}

//-----------------------------------------------------------------------------
inline FacesP *	ContoursP::PtrFace ()
{
	return PtrRepresentation () -> PtrTopologie () -> PtrFace () ;
}

//-----------------------------------------------------------------------------
inline void		ContoursP::ModifFace (const FacesP& F)
{
	PtrRepresentation ()->PtrTopologie ()->ModifFace (F) ;
}


//-----------------------------------------------------------------------------
inline void		ContoursP::SortirAreteOrientee ( const AretesOrienteesP& AO )
{
	PtrRepresentation()->PtrTopologie()->SortirAreteOrientee(AO) ;
}


//-----------------------------------------------------------------------------
inline void ContoursP::ModifAreteSuivante ( const AretesOrienteesP& Pos , const AretesP& Suiv )
{
	PtrRepresentation()->PtrTopologie()->ModifAreteSuivante(Pos,Suiv) ;
}


//-----------------------------------------------------------------------------
inline void ContoursP::ModifAretePrecedente ( const AretesOrienteesP& Pos , const AretesP& Prec )
{
	PtrRepresentation()->PtrTopologie()->ModifAretePrecedente(Pos,Prec) ;
}