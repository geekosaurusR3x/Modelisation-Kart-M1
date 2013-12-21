//*****************************************************************************
// 
// Module	: Conteneurs
// 
// Fichier	: Conteneurs.h
// 
// Auteur	: Wies Eric
// 
// Date creat.	: Fri Sep 27 16:52:09 MET DST 1996
// 
// Version	: 1.0
//
// Commentaires	: Interface de la classe Conteneurs.
// 
// 
//*****************************************************************************
// Includes
// Classe Conteneurs
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************

#ifndef __Conteneurs__h__
#define	__Conteneurs__h__

//*****************************************************************************
//
// Includes
//
//*****************************************************************************

#include	<iostream>
using namespace std ;

#include "ConteneursDLL.h"

//*****************************************************************************
//
// Classe Conteneurs
//
//*****************************************************************************

template <class X> class CONTENEURS_DLL  Conteneurs
{
public :

	//*****************************************************************************
	//	Constructeurs et destructeur
	//*****************************************************************************

	Conteneurs ()
	: nb_Elements (0)
	{
	}

	Conteneurs (const Conteneurs<X> &C)
	: nb_Elements (C.nb_Elements)
	{
	}

	Conteneurs (unsigned long Nb_Elem)
	: nb_Elements (Nb_Elem)
	{
	}

	virtual ~Conteneurs ()
   {
   }


	//*****************************************************************************
	//	Accesseurs
	//*****************************************************************************

	unsigned long Nb_Elements () const;


	//*****************************************************************************
	//	Methodes
	//*****************************************************************************

	bool Est_Vide () const;
	virtual void Fusion (	const Conteneurs<X> &CSource,
									Conteneurs<X> &CResultat) const;
   virtual bool Est_Dans (const X &Elem) const		= 0;
   virtual bool Est_Dans ( const X&, unsigned long&) const	= 0 ;
	virtual Conteneurs<X>& Detruit ();
	virtual void Tout_Parcourir (
	void (* Fonction) (	X &, void *,unsigned long),
								void *Donnee = NULL ,
                        unsigned long PosDebut=0 ) const		= 0;

	//*****************************************************************************
	//	Surcharge des operateurs
	//*****************************************************************************

	const Conteneurs<X>& operator = (const Conteneurs<X> &);
	const Conteneurs<X>& operator () (const Conteneurs<X> &);
	/*virtual*/ const Conteneurs<X>& operator + (const Conteneurs<X> &);
	bool operator <= (const Conteneurs<X> &);
	bool operator == (const Conteneurs<X> &);

	friend ostream& CONTENEURS_DLL operator << (ostream &, const Conteneurs<X> &);


protected :

		unsigned long	nb_Elements;
};



template <class X> unsigned long Conteneurs<X>::Nb_Elements () const
{
	return nb_Elements;
}


template <class X> bool Conteneurs<X>::Est_Vide () const
{
	return (nb_Elements == 0);
}

template <class X> Conteneurs<X>& Conteneurs<X>::Detruit ()
{
	nb_Elements = 0;

	return *this;
}


template <class X> void Conteneurs<X>::Fusion (
	const Conteneurs<X> &, Conteneurs<X> &) const
{
}


template <class X> ostream& operator << (ostream &s, const Conteneurs<X> &C)
{
	s << "Conteneurs (Nb_Elements : " << C.nb_Elements << ")";

	return s;
}


template <class X> const Conteneurs<X>& Conteneurs<X>::operator = (
	const Conteneurs<X> &O)
{
	if (&O != this)
		nb_Elements = O.nb_Elements;

	return *this;
}


template <class X> const Conteneurs<X>& Conteneurs<X>::operator () (
	const Conteneurs<X> &CSource)
{
	if (&CSource != this)
		nb_Elements = CSource.nb_Elements;


	return *this;
}


template <class X> const Conteneurs<X>& Conteneurs<X>::operator + (
	const Conteneurs<X> &CSource)
{
	nb_Elements += CSource.nb_Elements;

	return *this;
}


template <class X> bool Conteneurs<X>::operator <= (const Conteneurs<X> &C2)
{
	return this->nb_Elements <= C2.nb_Elements;
}


template <class X> bool Conteneurs<X>::operator == (const Conteneurs<X> &C2)
{
	return this->nb_Elements == C2.nb_Elements;
}


#endif	__Conteneurs__h__
