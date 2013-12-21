//*****************************************************************************
//
// Module	: RepContoursP
//
// Fichier	: RepContoursP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct inline de la classe RepContoursP
//
//
//*****************************************************************************
// Includes
// Classe RepContoursP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************


//-----------------------------------------------------------------------------
inline const TopoContoursP &	RepContoursP::Topologie () 		const
{
	return (const TopoContoursP &)TopologieBRep () ;
}

//-----------------------------------------------------------------------------
inline TopoContoursP *		RepContoursP::PtrTopologie ()
{
	return (TopoContoursP *)PtrTopologieBRep () ;
}

//-----------------------------------------------------------------------------
inline void		RepContoursP::ModifTopologie (TopoContoursP *PTC)
{
	// YANN ; Juste ?
	// Comment on detruit l'ancienne topologie
	delete topologie ;
	topologie = PTC ;
}