//*****************************************************************************
//
// Module	: Tables
//
// Fichier	: Tables.h
//
// Auteur	: Wies Eric
//
// Date creat.	: Mon Sep  9 16:03:08 MET DST 1996
//
// Version	: 1.0
//
// Modifification : 02/07/99 Heschung Fred,
//						  - InsertionParcours
//
// Commentaires	: Interface de la classe Tables.
//			Gestion de tableaux generiques et dynamiques
//
//*****************************************************************************
// Includes
// Classe Tables
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************

#ifndef __Tables__h__
#define __Tables__h__

//*****************************************************************************
//
// Includes
//
//*****************************************************************************

#include	<iostream>
using namespace std ;
#include	"Conteneurs.h"



//*****************************************************************************
//
// Classe Tables
//
//*****************************************************************************

template <class X> class CONTENEURS_DLL Tables	: public Conteneurs<X>
{
public :


	//*****************************************************************************
	//	Constructeurs et destructeur
	//*****************************************************************************

	Tables (unsigned long Taille_Init = 0, unsigned long Pas_Agrandir = 10)
   : Conteneurs<X> (Taille_Init), pas_Agrandir (Pas_Agrandir), tab (NULL) // new X [Taille_Init])
	{
		if (Taille_Init > 0)
			tab = new X [Taille_Init];

		if (pas_Agrandir < 1)
			pas_Agrandir = 10;
	}

	Tables (const Tables<X> &T)
	: Conteneurs<X> (T), pas_Agrandir (T.pas_Agrandir),
	tab (NULL)
	{
		// delete [] tab ; Christian : j'enlève ce delete le 5-08-2000
	   if (nb_Elements > 0)	// Christian le 25 mars 204
			tab=new X[nb_Elements] ;

   	// Correction Christian le 05.08.2000 : je remplace le memcpy par une boucle
	   for (unsigned long i = 0 ; i < nb_Elements ; i++)
   		tab [i] = T.tab [i] ;
			// memcpy (tab,T.tab, nb_Elements*sizeof (X));
	}

	Tables (const Conteneurs<X> &CSource)
	: Conteneurs<X> (CSource), pas_Agrandir (10),tab (NULL)
	{
		// delete [] tab ; Christian : j'enlève ce delete le 5-08-2000
		if (nb_Elements > 0) {	// Christian le 17-07-2004
	   	tab=new X [nb_Elements] ;
			CSource.Tout_Parcourir (Placer_Element, (void *) this);
      }
	}

	virtual ~Tables ()
	{
		if (tab != NULL)
			delete [] tab;
	}


	//*****************************************************************************
	//	Accesseurs
	//*****************************************************************************

	unsigned long Pas_Agrandir () const;

	Tables<X>& Changer_Nb_Elements (unsigned long);
   // Change le nb de cases ALLOUEES à la valeur demandée.

	Tables<X>& Pas_Agrandir (unsigned long);


	//*****************************************************************************
	//	Methodes
	//*****************************************************************************

	bool Est_Dans (const X &) const;
	bool Est_Dans (const X &, unsigned long&) const;
   Conteneurs<X>& Detruit ();
   void Tout_Parcourir (	void (*Fonction) (X &, void *,unsigned long),
      							void *Donnee = NULL , unsigned long PosDebut=0 ) const;
	void Fusion (const Conteneurs<X> &,Conteneurs<X> &) const;


	//*****************************************************************************
	//	Surcharge des operateurs
	//*****************************************************************************

	const Tables<X>& operator = (const Tables<X> &);
	const Tables<X>& operator = (const Conteneurs<X> &);
	const Tables<X>& operator + (const Conteneurs<X> &);
	const Tables<X>& operator () (const Conteneurs<X> &);
	X& operator [] (unsigned long);
	const X& operator [] (unsigned long) const ;

   friend bool CONTENEURS_DLL  operator <= (const Tables<X> &, const Tables<X> &);
   friend bool CONTENEURS_DLL  operator == (const Tables<X> &, const Tables<X> &);

   friend ostream& CONTENEURS_DLL  operator << (ostream &, const Tables<X> &);


	private :

		static void Placer_Element (X &, void *,unsigned long);

		unsigned long	pas_Agrandir;

		X	*tab;
};


template <class X> unsigned long Tables<X>::Pas_Agrandir () const
{
	return pas_Agrandir;
}


template <class X> Tables<X>& Tables<X>::Pas_Agrandir (unsigned long Nouv_Pas)
{
	if (Nouv_Pas > 0)
		pas_Agrandir = Nouv_Pas;

	return *this;
}

template <class X> X& Tables<X>::operator [] (unsigned long Position)
{
	if (Position >= nb_Elements)
	{
		unsigned long	Nouv_Taille	= ((Position / pas_Agrandir) + 1) * pas_Agrandir;
		Changer_Nb_Elements (Nouv_Taille);
	}

	return tab  [Position];
}


template <class X> const X& Tables<X>::operator [] (unsigned long Position) const
{
	return tab  [Position];
}


template <class X> Tables<X>& Tables<X>::Changer_Nb_Elements (unsigned long Max_Elem)
{
	if ( nb_Elements != Max_Elem )
   {
		if (Max_Elem > 0)
		{
#ifdef DEBUG_TABLES
static unsigned long NbAppel=0 ;
NbAppel++ ;
Console<<"NbReallocations="<<(double)NbAppel<<"\n" ;
#endif DEBUG_TABLES

			X	*Tab_Temp	= new X [Max_Elem];
			unsigned long	Nb_ElemCopies;

			if (nb_Elements < Max_Elem)
				Nb_ElemCopies = nb_Elements;
			else
				Nb_ElemCopies = Max_Elem;

			if ( tab != NULL )
			{
  				for ( unsigned long i=0 ; i<Nb_ElemCopies ; i++)
            	Tab_Temp[i]=tab[i] ;

				delete [] tab;
         }

			tab = Tab_Temp;

		}
      else
      {
			if ( tab != NULL )
				delete [] tab;

         tab = NULL ;
      }

		nb_Elements = Max_Elem;
	}

	return *this;
}


template <class X> void Tables<X>::Tout_Parcourir (
	void (* Fonction) (X &, void *,unsigned long),
   void *Donnee , unsigned long PosDebut ) const
{
	for (unsigned long i = 0; i < nb_Elements; i ++)
		Fonction (tab [i], Donnee,i+PosDebut);
}


template <class X> void Tables<X>::Placer_Element (X &Elem, void *Donnee, unsigned long i )
// ATT. : il faut que le ième elt de tableau soit alloué
{
	Tables<X>	*T		= (Tables<X> *) Donnee;
	T -> tab [i] = Elem;
}


template <class X> bool Tables<X>::Est_Dans (const X &Elem) const
{
	unsigned long	Pos	= 0;
	bool	Trouve	= false;

	while ((! Trouve) && (Pos < nb_Elements))
		if (tab [Pos] == Elem)
			Trouve = true;
		else
			Pos ++;

	return Trouve;
}

template <class X> bool Tables<X>::Est_Dans (const X &Elem , unsigned long& Pos ) const
{
	Pos	= 0;
	bool	Trouve	= false;

	while ((! Trouve) && (Pos < nb_Elements))
		if (tab [Pos] == Elem)
			Trouve = true;
		else
			Pos ++;

	return Trouve;
}


template <class X> Conteneurs<X>& Tables<X>::Detruit ()
{
	if ( tab!=NULL )
   {
		// Christian le 05.08.2000 : je mets delete [] au lieu de delete
	   delete [] tab ;
      tab=NULL ;
   }
	nb_Elements=0 ;

	return *this;
}

template <class X> void Tables<X>::Fusion (
	const Conteneurs<X> &CSource, Conteneurs<X> &CResultat) const
{
	if ((Conteneurs<X> *) this != &CResultat)
		Tout_Parcourir (Placer_Element, (void *) &CResultat);

	if (&CSource  != &CResultat)
		CSource.Tout_Parcourir (Placer_Element, (void *) &CResultat);
}


template <class X> ostream& operator << (ostream &s, const Tables<X> &T)
{
	s << "Tables (Herite de : " << (Conteneurs<X> &) T;
	s << ", Pas_Agrandir : " << T.pas_Agrandir << ")";
   for ( unsigned long i=0 ; i<T.nb_Elements ; i++ )
   {
   	s<<((Tables<X>&)T)[i]<<"	" ;
   }

	return s;
}


template <class X> const Tables<X>& Tables<X>::operator = (const Tables<X> &O)
{
	if (&O != this)
	{
		delete [] tab;

		Conteneurs<X>::operator = (O);

      if (nb_Elements > 0) {	// Christian le 17-07-2004
			tab = new X [nb_Elements];

   	   for (unsigned long i = 0 ; i < nb_Elements ; i++)
      		tab [i] = O.tab [i] ;
      }
      else
      	tab = NULL ;
	}

	return *this;
}


template <class X> const Tables<X>& Tables<X>::operator = (const Conteneurs<X> &CSource)
{
	if (&CSource != this)
	{
		Conteneurs<X>::operator = (CSource);

		delete [] tab;
		pas_Agrandir = 10;
      nb_Elements=CSource.Nb_Elements() ;

		if (nb_Elements > 0) {	// Christian le 17-07-2004
			tab = new X [nb_Elements];

			CSource.Tout_Parcourir (Placer_Element, (void *) this);
      }
      else
      	tab = NULL ;
	}

	return *this;
}


template <class X> const Tables<X>& Tables<X>::operator () (
	const Conteneurs<X> &CSource)
{
	if (&CSource != this)
	{
		if (tab != NULL)
			delete [] tab;

		tab = NULL;

		pas_Agrandir = 10;

		Conteneurs<X>::operator () (CSource);

		CSource.Tout_Parcourir (Placer_Element, (void *) this);
	}

	return *this;
}


template <class X> const Tables<X>& Tables<X>::operator + (
	const Conteneurs<X> &CSource)
{
	CSource.Tout_Parcourir (Placer_Element, (void *) this);

	return *this;
}


template <class X> bool operator <= (const Tables<X> &T1, const Tables<X> &T2)
{
	bool	Trouve	= ((Conteneurs<X> &) T1 <= (Conteneurs<X> &) T2);
	unsigned long	i	= 0;

	while ((i < T1.Nb_Elements ()) && (Trouve))
	{
		Trouve = T2.Est_Dans (T1 [i]);
		i ++;
	}

	return Trouve;
}


template <class X> bool operator == (const Tables<X> &T1, const Tables<X> &T2)
{
	bool	Trouve	= ((Conteneurs<X> &) T1 == (Conteneurs<X> &) T2);
	unsigned long	i	= 0;

	while ((i < T1.Nb_Elements ()) && (Trouve))
	{
		Trouve = T2.Est_Dans (T1 [i]);
		i ++;
	}

	return Trouve;
}

#endif	__Tables__h__
