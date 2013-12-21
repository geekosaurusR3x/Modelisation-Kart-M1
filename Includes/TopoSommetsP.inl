//*****************************************************************************
//
// Module	: TopoSommetsP
//
// Fichier	: TopoSommetsP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fonctions inline de la classe TopoSommetsP
//
//
//*****************************************************************************
//	Accesseurs
//	Methodes
//*****************************************************************************


#include "DebugBRepP.h"

inline bool TopoSommetsP::AJour () const
{
	return aJour ;
}


// Cette fois-ci, il n'y a pas de copie, c'est un accesseur.
// Attention à la mise à jour.
inline const Tableaux<AretesOrienteesP>& TopoSommetsP::TableauAretesOrienteesIncidentes ()
{
	// Si le tableau des arêtes incidentes n'est pas à jour ...
	if ( !aJour )
   	((TopoSommetsP&)*this).MettreAJourTableAretesOrientees() ;

	return tabAretesOrientees ;
}


//*****************************************************************************
//*****************************************************************************
inline void TopoSommetsP::RetirerAreteOrientee (AretesOrienteesP &AO)
{
	unsigned long pos ;

	if ( tabAretesOrientees.Est_Dans(AO,pos) )
   {
		nombreAretesIncidentes-- ;
   	tabAretesOrientees.Supprimer(pos) ;
	   aJour=false ;
   }
   else
   	ErreurModele ("On retire d'un sommet une arete orientee qui n'existe pas") ;
}

inline TopologiesBRep*	TopoSommetsP::Dupliquer () const
{
	if ( !aJour )
   	((TopoSommetsP&)*this).MettreAJourTableAretesOrientees() ;

	return new TopoSommetsP (*this) ;
}

inline const int TopoSommetsP::NombreAretes () const
{
	return nombreAretesIncidentes ;
}

inline const int TopoSommetsP::NombreAretesOrientees () const
{
	return nombreAretesIncidentes ;
}

