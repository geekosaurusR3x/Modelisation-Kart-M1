//*****************************************************************************
// 
// Module	: ElemListes
// 
// Fichier	: ElemListes.h
// 
// Auteur	: Wies Eric
// 
// Date creat.	: Tue Sep 10 14:34:50 MET DST 1996
// 
// Version	: 1.0
//
// Commentaires	: Interface de la classe ElemListes.
// 
// 
//*****************************************************************************
// Includes
// Classe ElemListes
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************

#ifndef __ElemListes__h__
#define __ElemListes__h__

//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************

#include	<iostream>
using namespace std ;
#include "ConteneursDLL.h"


template <class X> class CONTENEURS_DLL  Listes;

//*****************************************************************************
//
// Classe ElemListes
//
//*****************************************************************************

template <class X> class CONTENEURS_DLL  ElemListes
{
	public :

	ElemListes ()
   : precedent (NULL), suivant (NULL)
   {
   }
	ElemListes (const ElemListes<X> &EL)
   : valeur (EL.valeur), precedent (EL.precedent), suivant (EL.suivant)
   {
   }
	~ElemListes ()
   {
   }


	//*****************************************************************************
	//	Accesseurs
	//*****************************************************************************

	const X& 	Valeur () const;
	ElemListes<X>* 	Suivant () const;
	ElemListes<X>* 	Precedent () const;

                X*	PtrValeur();

	ElemListes<X>& 	Valeur (const X& Nouv_Valeur);
	ElemListes<X>& 	Suivant (ElemListes<X>* Nouv_Suivant);
	ElemListes<X>& 	Precedent (ElemListes<X>* Nouv_Precedent);


	//*****************************************************************************
	//	Surcharge des operateurs
	//*****************************************************************************

	const ElemListes<X>& operator = (const ElemListes<X> &);

	friend ostream& CONTENEURS_DLL  operator << (ostream &, const ElemListes &);


	private :

		friend class  Listes<X>;

		X		valeur;

		ElemListes<X>	*precedent;
		ElemListes<X>	*suivant;
};


template <class X>
const X& ElemListes<X>::Valeur () const
{
	return valeur;
}


template <class X>
ElemListes<X>* ElemListes<X>::Precedent () const
{
	return precedent;
}


template <class X>
ElemListes<X>* ElemListes<X>::Suivant () const
{
	return suivant;
}


template <class X>
X* ElemListes<X>::PtrValeur ()
{
	return &valeur;
}


template <class X>
ElemListes<X>& ElemListes<X>::Valeur (const X& Nouv_Valeur)
{
	valeur = Nouv_Valeur;

	return *this;
}


template <class X> 
ElemListes<X>& ElemListes<X>::Precedent (
	ElemListes<X>* Nouv_Precedent)
{
	precedent = Nouv_Precedent;

	return *this;
}


template <class X> 
ElemListes<X>& ElemListes<X>::Suivant (
	ElemListes<X>* Nouv_Suivant)
{
	suivant = Nouv_Suivant;

	return *this;
}


template <class X> ostream& operator << (ostream &s, const ElemListes<X> &EL)
{
	s << "ElemListes (Valeur : " << EL.valeur << ")" << endl;

	return s;
}


template <class X> const ElemListes<X>& ElemListes<X>::operator = (const ElemListes<X> &O)
{
	if (&O != this)
	{
		valeur = O.valeur;
		suivant = O.suivant;
		precedent = O.precedent; 
	}
	
	return *this;
}

#endif	__ElemListes__h__



