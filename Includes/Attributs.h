#pragma once
#include "attributsFacesP.h"
#include "attributsSolidesP.h"
#include "Materiaux.h"
//#include "bibliothequeVisualiseur.h"

///////////////////////////////////////////////////////////////////////////
//
// Attributs pour une face du BRep (et, plus bas, pour un SolidesP) : 
// - un attribut de face contient le matériau de la face
// - un attribut de solide est vide (l'attribut de solide n'est pas exploité)
//
///////////////////////////////////////////////////////////////////////////

class AttributsFaces :
	public AttributsFacesP
{
public:
	AttributsFaces(void)
	: AttributsFacesP ()
	, mPMateriau (NULL)
	{}

	AttributsFaces(const Materiaux *PM)
		: AttributsFacesP ()
		, mPMateriau (PM)
	{}

	AttributsFaces(const AttributsFaces &AF)
		: AttributsFacesP ()
		, mPMateriau (AF.mPMateriau)
	{}

	~AttributsFaces(void) {}
	
	AttributsFacesP		* Dupliquer () const
	{	return new AttributsFaces (mPMateriau) ;
	}
	
	AttributsFacesP		*LireV (std::istream &F)
	{
		Materiaux m ;
		F >> m ;
		return new AttributsFaces (Materiaux::CreerMateriau (m)) ;
	}

	void						Ecrire (std::ostream &F) const
	// Ecrit sans passer à la ligne
	{
		F << *mPMateriau ;
	}

	const Materiaux * GetMateriau () const
	{
		return mPMateriau ;
	}

private:
	const Materiaux		*mPMateriau ;	// Pointeur sur un Materiaux constant
};



/////////////////////////////////////////////////////////////////////////////
//
// CLASSE NON EXPLOITEE DANS CETTE VERSION : LES SOLIDES N'ONT PAS D'ATTRIBUT
//
/////////////////////////////////////////////////////////////////////////////

class AttributsSolides :	public AttributsSolidesP
{
public:
	AttributsSolides(void)
		: AttributsSolidesP ()
	{}

	~AttributsSolides(void) 
	{}
	
	AttributsSolides		* Dupliquer () const
	{	return new AttributsSolides () ;
	}
	
	AttributsSolides		*LireV (std::istream &F)
	{
		return NULL ; //new AttributsSolides () ;
	}

	void		Ecrire (std::ostream &F) const
	// Ecrit sans passer à la ligne
	{}

private :
} ;

