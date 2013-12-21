//*****************************************************************************
//
// Module	: SommetsP
//
// Fichier	: SommetsP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/06/99
//
// Version	:
//
// Commentaires	: Implementation des fonctions inline de la classe SommetsP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//*****************************************************************************


//*****************************************************************************
// Includes
//*****************************************************************************


#include "DebugBRepP.h"


//*****************************************************************************
//	Methodes
//*****************************************************************************
inline const Points3D& SommetsP::Point3D () const
{
	return Representation ().Geometrie ().Point3D () ;
}

inline void SommetsP::IntegrerNouvelleAreteOrientee (const AretesOrienteesP &A)
{
	if ( A.Origine()==(*this) )
		PtrRepresentation ()->PtrTopologie ()->IntegrerNouvelleAreteOrientee (A) ;
   else
   	ErreurModele ("Pb dans SommetsP::IntegrerNouvelleAreteOrientee") ;
}

inline void SommetsP::RetirerAreteOrientee (AretesOrienteesP &AO)
{	PtrRepresentation ()->PtrTopologie ()->RetirerAreteOrientee (AO) ;

}


inline const int SommetsP::NombreAretes () const
{	return Representation ().Topologie ().NombreAretes () ;
}

inline const int SommetsP::NombreAretesOrientees () const
{	return Representation ().Topologie ().NombreAretesOrientees () ;
}


// Si la topologie est à jour, l'accès est direct, sinon il y a 1 parcours
inline const AretesP SommetsP::IemeArete (int i) const
{
	TopoSommetsP	TS = Representation ().Topologie () ;

	return TS.IemeArete (i) ;
}


// Si la topologie est à jour, l'accès est directe, sinon il y a 1 parcours
inline const AretesOrienteesP	SommetsP::IemeAreteOrientee (int i) const
{
	return Representation().Topologie ().IemeAreteOrientee (i) ;
}


inline const RepSommetsP& SommetsP::Representation () const
{
	if (!EstInitialise())
		ErreurModele ("Attention : dans SommetsP::Representation () le sommet n'est pas initialise") ;

	return (const RepSommetsP &) RepresentationBRep () ;
}


inline RepSommetsP* SommetsP::PtrRepresentation ()
{
	if (!EstInitialise())
		ErreurModele ("Attention : dons SommetsP::PtrRepresentation () le sommet n'est pas initialise") ;

	return (RepSommetsP *) PtrRepresentationBRep () ;
}
