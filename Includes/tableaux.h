//*****************************************************************************
//
// Module	: Tableaux
//
// Fichier	: Tableaux.h
//
// Auteur	: Heschung Frédéric
//
// Date creat.	: 01/07/99
//
// Version	: 1.0
//
// Commentaires	: Interface de la classe Tableaux, dérive de la classe Tables
//			Gestion de tableaux generiques et dynamiques
//			Il faut avoir implémenté les operateurs "=" et "==" sur la classe X.
//
//*****************************************************************************
// Includes
// Classe Tableaux
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************

#ifndef __Tableaux__h__
#define __Tableaux__h__

//*****************************************************************************
//
// Includes
//
//*****************************************************************************

#include	<iostream>
using namespace std ;

#include "Conteneurs.h"
#include "Tables.h"

//*****************************************************************************
//
// Classe Tableaux
//
//*****************************************************************************

template <class X> class CONTENEURS_DLL  Tableaux	: public Tables<X>
{
	public :

	//*****************************************************************************
	//	Constructeurs et destructeur
   // Ils sont tous les 4 définis ci-dessous pour obliger le compilateur à
   // les compiler. En effet, les 3 sont indispensables même s'ils ne sont
   // pas appelés explicitement.
	//*****************************************************************************

	Tableaux (unsigned long Taille_Init = 0, unsigned long Pas_Agrandir = 10)
	: Tables<X>(Taille_Init,Pas_Agrandir) , nb_Effectifs(0)
   {
   }

	Tableaux (const Tableaux<X> &T )
	: Tables<X>(T) , nb_Effectifs(T.nb_Effectifs)
	{
   }

	Tableaux (const Conteneurs<X> &CSource )
	: Tables<X>(CSource.Nb_Elements(),1) , nb_Effectifs(0)
	{
		CSource.Tout_Parcourir(Placer_Element,(void*)this) ;
	}

	~Tableaux ()
   {
   }

//*****************************************************************************
//	Accesseurs
//*****************************************************************************

      unsigned long Nb_Effectifs () const ;

		Tableaux<X>& Changer_Nb_Elements (unsigned long Nb) ;
      // Si Nb est < au nb effectif d'éléments, ce dernier est réduit.
      // Si Nb est > au nb d'éléments ALLOUES, ce dernier augmente.
      // Sinon, rien ne se passe.

//*****************************************************************************
//	Methodes
//*****************************************************************************

		bool Est_Dans (const X &Elem) const;
      bool Est_Dans (const X &, unsigned long&) const ;
      void Supprimer (unsigned long) ;
      void Supprimer (const X&) ;
      void Inserer	(const X&,unsigned long) ;
      void Inversion () ;


		Conteneurs<X>& Detruit ();

		void Tout_Parcourir (void(*Fonction)(X &, void *,unsigned long) ,
      							void* Donnee=NULL , unsigned long PosDebut=0 ) const ;

		void Fusion (const Conteneurs<X>& CSource,Conteneurs<X>& CResultat ) const ;
		// Concatène this et CSource dans CResultat

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************

		const Tableaux<X>& operator = (const Tableaux<X> &);
		const Tableaux<X>& operator = (const Conteneurs<X> &);
		const Tableaux<X>& operator + (const Conteneurs<X> &);
		const Tableaux<X>& operator + (const Tableaux<X> &);

		const Tableaux<X>& operator () (const Conteneurs<X> &);
		X& operator [] (unsigned long Position);
		const X& operator [] (unsigned long Position) const;


		friend bool CONTENEURS_DLL  operator <= (const Tableaux<X> &, const Tableaux<X> &);
      friend bool CONTENEURS_DLL  operator == (const Tableaux<X> &, const Tableaux<X> &);

		friend ostream& CONTENEURS_DLL operator << (ostream &, const Tableaux<X> &);

//*****************************************************************************
//	Partie privee
//*****************************************************************************

	private :

		static void Placer_Element (X &, void *,unsigned long); // Ajout en queue ac allocation
      															 // d'un nouvel élt

		unsigned long nb_Effectifs ; // Correspond au nb d'élts effectivement
	// stockés CONSECUTIVEMENT ds le tableau
};


template <class X>
bool operator== ( const Tableaux<X>& T1 , const Tableaux<X>& T2 )
{
	return T1.nb_Effectifs==T2.nb_Effectifs && (Tables<X>&)T1==(Tables<X>&)T2 ;
}


template <class X>
unsigned long Tableaux<X>::Nb_Effectifs () const
{
	return nb_Effectifs ;
}

template <class X>
Tableaux<X>& Tableaux<X>::Changer_Nb_Elements ( unsigned long Nb )
{

	if ( Nb < nb_Effectifs )
   	nb_Effectifs=Nb ;
   else if (Nb > this->nb_Elements )
	   Tables<X>::Changer_Nb_Elements(Nb) ;
   return *this ;
}


template <class X>
void Tableaux<X>::Supprimer ( const X& Elem )
{
	unsigned long pos ;
	if ( Est_Dans(Elem,pos) )
   	Supprimer(pos) ;
}


template <class X>
void Tableaux<X>::Placer_Element (X &Elem, void *Donnee, unsigned long i)
// Ajoute un élt à la fin du tableau et l'initialise avec Elem
{
	Tableaux<X>	*T		= (Tableaux<X> *) Donnee;
	T->operator[](i) = Elem;
}


template <class X>
Conteneurs<X>& Tableaux<X>::Detruit ()
{
	nb_Effectifs=0 ;
	Tables<X>::Detruit() ;
   return (*this) ;
}


template <class X>
const Tableaux<X>& Tableaux<X>::operator = (const Tableaux<X>& T )
{
	if ( &T!=this )
   {
 		Tables<X>::operator=(T) ;
   	nb_Effectifs=T.nb_Effectifs ;
   }
   return *this ;
}


template <class X>
const Tableaux<X>& Tableaux<X>::operator = ( const Conteneurs<X>& CSource )
{
	if (&CSource != this)
	{
		Conteneurs<X>::operator=(CSource) ;
		Changer_Nb_Elements(CSource.Nb_Elements()) ;
		CSource.Tout_Parcourir(Placer_Element, (void *) this);
	}
	return *this;
}


template <class X>
X& Tableaux<X>::operator [] (unsigned long Position)
// On suppose que si un accès au nb ième elements +1 est fait par cette fonction,
// c'est qu'il s'agit d'un ajout, càd que cette fonction est appelée en LValue.
// Sinon, le nb_Effectifs est erroné
{
	if (Position == nb_Effectifs)
	{
   	if ( nb_Effectifs==Nb_Elements() )
      		Changer_Nb_Elements(Nb_Elements()+Pas_Agrandir());
		nb_Effectifs++ ;
	}
   return Tables<X>::operator[](Position) ;
}


template <class X>
const X& Tableaux<X>::operator [] (unsigned long Position) const
// Seuls les accès aux éléments existants sont autorisés
{
   return Tables<X>::operator[](Position) ;
}


template <class X>
void Tableaux<X>::Tout_Parcourir (
								void (* Fonction) (X &, void *,unsigned long),
                        void *Donnee , unsigned long PosDebut ) const
// Parcourt tout le tableau et applique à chaque élt la fonction "Fonction"
{
	unsigned long nb=nb_Effectifs ;
	for (unsigned long i = 0; i < nb; i++)
		Fonction ( ( (Tableaux<X>&)(*this) )[i] , Donnee,i+PosDebut);
}


template <class X>
bool Tableaux<X>::Est_Dans (const X &Elem) const
{
	unsigned long	Pos	= 0;
	bool	Trouve	= false;

	while ( !Trouve && Pos<nb_Effectifs )
   {
		if ( ( (Tableaux<X>&)(*this) )[Pos]==Elem )
			Trouve = true;
		else
			Pos ++;
   }

	return Trouve;
}


template <class X>
bool Tableaux<X>::Est_Dans ( const X& Elem, unsigned long& Pos ) const
{
	bool Trouve=false ;
	Pos=0 ;

   while ( !Trouve && Pos<nb_Effectifs )
   {
   	if ( ( (Tableaux<X>&)(*this) )[Pos]==Elem )
	      Trouve=true ;
      else Pos++ ;
   }

   return Trouve ;
}


template <class X>
void Tableaux<X>::Supprimer ( unsigned long position )
{
	if ( position<nb_Effectifs )
	{
   	for ( unsigned long i=position ; i<nb_Effectifs-1 ; i++ )
   	(*this)[i]=(*this)[i+1] ;

		nb_Effectifs-- ;
   }
}


template <class X>
void Tableaux<X>::Inserer ( const X& Elem , unsigned long pos )
{
//	if ((pos == nb_Effectifs) && (nb_Effectifs == Nb_Elements()))
	if (nb_Effectifs == Nb_Elements())
   	Changer_Nb_Elements(Nb_Elements()+Pas_Agrandir());
      // Ceci est obligatoire ICI. Sinon, la realloc est faite
      // dans (*this)[i] (ci-dessous). Dans ce cas, le termes de
      // droite de l'affectation fait référence à un
      // élément qui disparaît au moment où le terme de gauche
      // provoque la réallocation.

	unsigned long nb=nb_Effectifs ;
	for ( unsigned long i=nb ; i>pos ; i-- )
   {
   	(*this)[i]=(*this)[i-1] ;
   } // nb_Effectifs est incrémenté ds []
   (*this)[pos]=Elem ;
}


template <class X>
void Tableaux<X>::Inversion ()
{
	X aux ;
	for ( unsigned long i=0 ; i<nb_Effectifs/2 ; i++ )
   {
   	aux=(*this)[i] ;
   	(*this)[i]=(*this)[nb_Effectifs-i-1] ;
      (*this)[nb_Effectifs-i-1]=aux ;
   }
}


template <class X>
void Tableaux<X>::Fusion (const Conteneurs<X> &CSource,Conteneurs<X> &CResultat) const
// Concatène this et CSource dans CResultat
{
	// Dommage de ne pouvoir dimensionner le Conteneurs résultat  à la somme
   // des tailles de Nb_Effectifs () et CSource.Nb_Effectifs ()

	if ((Conteneurs<X> *) this != &CResultat)
		Tout_Parcourir (Placer_Element, (void *) &CResultat);

	if (&CSource  != &CResultat)
		// MODIF C. Minich le 7.12.99 : ajout du troisieme parametre ci-dessous
		CSource.Tout_Parcourir (Placer_Element, (void *) &CResultat,((Tableaux<X> &) CResultat).nb_Effectifs);
}


template <class X>
const Tableaux<X>& Tableaux<X>::operator () ( const Conteneurs<X> & CSource )
{
	if (&CSource != this)
	{
		Tables<X>::Detruit() ;
		Conteneurs<X>::operator () (CSource);
		CSource.Tout_Parcourir (Placer_Element, (void *) this);
	}
	return *this;
}


template <class X>
const Tableaux<X>& Tableaux<X>::operator + (const Conteneurs<X>& CSource)
{
	CSource.Tout_Parcourir (Placer_Element, (void *) this,nb_Effectifs);

	return *this;
}


template <class X>
const Tableaux<X>& Tableaux<X>::operator + (const Tableaux<X>& CSource)
{
	Changer_Nb_Elements (Nb_Effectifs ()+CSource.Nb_Effectifs ()) ;
	CSource.Tout_Parcourir (Placer_Element, (void *) this,nb_Effectifs);

	return *this;
}


template <class X>
bool operator<= ( const Tableaux<X>& T1 , const Tableaux<X>& T2 )
{
	bool	Trouve	= ((Conteneurs<X> &) T1 <= (Conteneurs<X> &) T2);
	unsigned long	i	= 0;

	while ( i < T1.Nb_Effectifs() && Trouve )
	{
		Trouve = T2.Est_Dans(T1[i]) ;
		i ++;
	}

	return Trouve;
}


template <class X> ostream& operator << (ostream &s, const Tableaux<X> &T)
{
	s<<"Taille : "<<T.Nb_Elements()<<" , "<<"Nb_Effectifs : "<<T.nb_Effectifs ;
   s<<"\n" ;
	for ( unsigned long i=0 ; i<T.Nb_Effectifs() ; i++ )
   {
   	s<< ((Tables<X>&)T) [i] <<"	" ;
	}

	return s;
}


#endif	__Tableaux__h__