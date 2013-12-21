//*****************************************************************************
//
// Module	: Listes
// 
// Fichier	: Listes.h
// 
// Auteur	: Wies Eric
// 
// Date creat.	: Tue Sep 10 14:10:37 MET DST 1996
// 
// Version	: 1.0
//
// Commentaires	: Interface de la classe Listes.
// 
// 
//*****************************************************************************
// Includes
// Classe Listes
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************

#ifndef __Listes__h__
#define	__Listes__h__

//*****************************************************************************
//
// Includes
//
//*****************************************************************************

#include	<iostream>
using namespace std ;

#include	"Conteneurs.h"
#include	"ElemListes.h"
#include	"Iterateurs.h"



template <class X> class CONTENEURS_DLL ElemListes;
template <class X> class CONTENEURS_DLL Iterateurs ;


//*****************************************************************************
//
// Classe Listes
//
//*****************************************************************************

template <class X> class CONTENEURS_DLL Listes	: public Conteneurs<X>
{
	public :


	//*****************************************************************************
	//	Constructeurs et destructeur
   // Ils sont tous les 4 définis ci-dessous pour obliger le compilateur à
   // les compiler. En effet, les 3 sont indispensables même s'ils ne sont
   // pas appelés explicitement.
	//*****************************************************************************

	Listes ()
   : Conteneurs<X> (), tete (NULL), queue (NULL), courant (NULL)
   {
   }

	Listes (const Listes<X> &L)
	: Conteneurs<X> (), tete (NULL), queue (NULL), courant (NULL)
	{
		ElemListes<X>	*Pisteur	= L.tete;

		while (Pisteur != NULL)
		{
			InsertionEnQueue (Pisteur -> Valeur ());

			if (Pisteur == L.courant)
				courant = queue;

			Pisteur = Pisteur -> Suivant ();
		}
	}

	Listes (const Conteneurs<X> &CSource)
	: Conteneurs<X> (), tete (NULL), queue (NULL), courant (NULL)
	{
		CSource.Tout_Parcourir (Placer_Element, (void *) this);
	}

	~Listes ()
	{
		while (! Est_Vide (tete))
			SuppressionEnTete ();
	}


	//*****************************************************************************
	//	Accesseurs
	//*****************************************************************************
	bool operator <= (const Listes<X> &) ;
	// Fonction d'inclusion
	// Cette fonction tient compte du nb d'occurence de chaque valeur.
	// Par exemple (1,1) est incluse dans (1,1,1) mais pas dans (1).

	bool operator == (const Listes<X> &) const;
	// deux listes sont égales si elles ont autant de fois les memes valeurs mais
	// pas forcement dans le meme ordre. (1,1,2) et (1,2,1) sont donc egales mais
	// (1,1,2) et (1,2,2) sont differentes


	const X& Tete () const;
	const X& Courant () const;
	const X& Queue () const;

	X*	PtrCourant();

   Listes<X>& Tete (const X &Nouv_Tete);
	Listes<X>& Courant (const X &Nouv_Courant);
	Listes<X>& Queue (const X &Nouv_Queue);

	//*****************************************************************************
	//	Methodes
	//*****************************************************************************

	bool Est_Vide () const;
	bool Est_Debut () const;
	bool Est_Fin () const;

	bool Est_Dans (const X &Elem) const;
	bool Est_Dans (const X & Elem, ElemListes<X> **Pisteur) const ;
  	bool Est_Dans (const X &,unsigned long&) const;

	Listes<X>& Debut ();
	Listes<X>& Fin ();

	bool Avance ();
	bool Recule ();
	
	// Pour placer le courant sur le maillon pointé par PM
	Listes<X>& PlacerCourant (ElemListes<X> *PM);
	
	Listes<X>& InsertionEnTete (const X &Elem);
	
	// Cette version restitue le pointeur sur le maillon créé
	Listes<X>& InsertionEnTete (const X &Elem, ElemListes<X> **PPM);

	Listes<X>& InsertionEnQueue (const X &Elem);
	Listes<X>& InsertionCourant (const X &Elem);

	Listes<X>& SuppressionEnTete ();
	Listes<X>& SuppressionEnQueue ();
	Listes<X>& SuppressionCourant ();
	
	// Supprime tous les maillons depuis celui pointé par P1 jusqu'à celui pointé par P2
	// (y compris ces 2 maillons)
	// ATTENTION : il faut être certain que *P2 vient APRES *P1 dans la liste
	Listes<X>& Suppression_De_A (ElemListes<X> *P1, ElemListes<X> *P2);
   	
	Listes<X> &Inversion ();

	Conteneurs<X>& Detruit ();

	void Tout_Parcourir (	void (* Fonction) (X &, void *,unsigned long) ,
							void *Donnee = NULL , unsigned long PosDebut=0 ) const;
	
	void Fusion (	const Conteneurs<X> &CSource,
   					Conteneurs<X> &CResultat) const;

	void Concatenation (Listes<X> &L2) ;
	// Ajoute les maillons de L2 en queue de *this SANS LES DUPLIQUER !!
	// L2 ne doit donc plus être utilisée après l'appel (elle est d'ailleurs
	// vidée)

	//*****************************************************************************
	//	Surcharge des operateurs
	//*****************************************************************************

	const Listes<X>& operator = (const Listes<X> &);
	const Listes<X>& operator = (const Conteneurs<X> &);
	/*
	retirée à cause d'une confusion avec Conteneurs::op + dans Visual
	*/
	const Listes<X> & operator + (const Conteneurs<X> &) ;
	const Listes<X>& operator () (const Conteneurs<X> &);
	X& operator [] (int Position);

	friend ostream& CONTENEURS_DLL operator << (ostream &, const Listes<X> &);

	//*****************************************************************************
	//	Partie privee
	//*****************************************************************************

	private :

		static void Placer_Element (X &, void *,unsigned long);
		static bool Est_Vide (ElemListes<X> *Tete);

		ElemListes<X>	*tete;
		ElemListes<X>	*queue;
		ElemListes<X>	*courant;

	friend class Iterateurs<X> ;
};


template <class X> const X& Listes<X>::Tete () const
{
	return tete -> Valeur ();
}


template <class X> const X& Listes<X>::Courant () const
{
	return courant -> Valeur ();
}


template <class X> const X& Listes<X>::Queue () const
{
	return queue -> Valeur ();
}


template <class X> X* Listes<X>::PtrCourant ()
{
	return courant -> PtrValeur ();
}


template <class X> Listes<X>& Listes<X>::Tete (const X& Nouv_Tete)
{
	if (! Est_Vide (tete))
		tete -> Valeur (Nouv_Tete);

	return *this;
}


template <class X> Listes<X>& Listes<X>::Courant (const X& Nouv_Courant)
{
	if (! Est_Vide (courant))
		courant -> Valeur (Nouv_Courant);

	return *this;
}


template <class X> Listes<X>& Listes<X>::Queue (const X& Nouv_Queue)
{
	if (! Est_Vide (queue))
		queue -> Valeur (Nouv_Queue);

	return *this;
}


template <class X> bool Listes<X>::Est_Vide () const
{
	return this->nb_Elements == 0;
}


template <class X> bool Listes<X>::Est_Debut () const
{
	return tete == courant;
}


template <class X> bool Listes<X>::Est_Fin () const
{
	return courant == queue;
}


template <class X> bool Listes<X>::operator == (const Listes<X> & L2) const
// deux listes sont égales si elles ont autant de fois les memes valeurs mais
// pas forcement dans le meme ordre. (1,1,2) et (1,2,1) sont donc egales mais
// (1,1,2) et (1,2,2) sont differentes
{
	// methode : on detruit dans L2 les valeurs de L1 que l'on y retrouve.
   // Quand L1 est epuisee, L2 doit etre vide.

	// filtre sur le nombre d'éléments
	bool		Inclus	= ((Conteneurs<X> &) (*this) <= (Conteneurs<X> &) L2);
   if (! Inclus) return false ;

   Listes<X> 		CopieL2 = L2 ;
	Iterateurs<X>	Pisteur	(*this) ;
   ElemListes<X>	*ElementADetruire ;


	// teste l'inclusion des elements de L1 dans CopieL2
	while (! Pisteur.Fin () && Inclus)
	{
		ElementADetruire	= CopieL2.tete;
		bool	Trouve	= false;

		while ((! Trouve) && (! Est_Vide (ElementADetruire)))
			if (ElementADetruire -> Valeur () == Pisteur.Valeur())
				Trouve = true;
			else
				ElementADetruire = ElementADetruire -> Suivant ();

		Inclus	= Trouve ; //CopieL2.Est_Dans(Pisteur.Valeur(),&ElementADetruire);

      if (Inclus)
      {	CopieL2.courant = ElementADetruire ;
      	CopieL2.SuppressionCourant () ;
      }

      Pisteur.Avance ();
   }

	return Inclus;
}


template <class X> bool Listes<X>::Est_Dans (const X & Elem) const
{
	ElemListes<X>	*Pisteur	= tete;
	bool		Trouve		= false;

	while ((! Trouve) && (! Est_Vide (Pisteur)))
        {
		if ( Pisteur->Valeur () == Elem)
			Trouve = true;
		else
			Pisteur = Pisteur -> Suivant ();
        }

	return Trouve;
}


template <class X> bool Listes<X>::Est_Dans (const X & Elem, ElemListes<X> **Pisteur) const
{
			*Pisteur	= tete;
	bool		Trouve	= false;

	while ((! Trouve) && (! Est_Vide (*Pisteur)))
	{
                if ((*Pisteur)->Valeur () == Elem)
			Trouve = true;
		else
			*Pisteur = (*Pisteur) -> Suivant ();
        }

	return Trouve;
}


template <class X> bool Listes<X>::Est_Dans (const X & Elem, unsigned long& Pos) const
{
	ElemListes<X>	*Pisteur	= tete;
	bool		Trouve		= false;
   	Pos=0 ;

	while ((! Trouve) && (! Est_Vide (Pisteur)))
        {
		if (Pisteur->Valeur () == Elem)
			Trouve = true;
		else
      		{
			Pisteur = Pisteur -> Suivant (); Pos++ ;
      		}
        }

	return Trouve;
}


template <class X> Listes<X>& Listes<X>::Debut ()
{
	courant = tete;

	return *this;
}


template <class X> Listes<X>& Listes<X>::Fin ()
{
	courant = queue;

	return *this;
}


template <class X> bool Listes<X>::Avance ()
{
	if (! Est_Fin ())
	{
		courant = courant -> Suivant ();
		return true;
	}
	else
		return false;
}


template <class X> bool Listes<X>::Recule ()
{
	if (! Est_Debut ())
	{
		courant = courant -> Precedent ();
		return true;
	}
	else
		return false;
}

// Pour placer le courant sur le maillon pointé par PM
template <class X> Listes<X>& Listes<X>::PlacerCourant (ElemListes<X> *PM)
{
	courant = PM ;
	return *this ;
}

template <class X> Listes<X>& Listes<X>::InsertionEnTete (const X& Elem)
{
	ElemListes<X>	*Nouv_Tete	= new ElemListes<X>;

	Nouv_Tete -> Valeur (Elem);
	Nouv_Tete -> Suivant (tete);

	if (! Est_Vide (tete))
		tete -> Precedent (Nouv_Tete);

	tete = Nouv_Tete;

	if (this->nb_Elements == 0)
	{
		queue = tete;
		courant = tete;
	}

	this->nb_Elements ++;

	return *this;
}

// Cette version restitue un pointeur sur le maillon créé
template <class X> Listes<X>& Listes<X>::InsertionEnTete (const X &Elem, ElemListes<X> **PPM)
{
	InsertionEnTete (Elem) ;
	*PPM = tete ;
	return *this ;
}

template <class X> Listes<X>& Listes<X>::InsertionEnQueue (const X& Elem)
{
	ElemListes<X>	*Nouv_Queue	= new ElemListes<X>;

	Nouv_Queue -> Valeur (Elem);
	Nouv_Queue -> Precedent (queue);

	if (! Est_Vide (queue))
		queue -> Suivant (Nouv_Queue);

	queue = Nouv_Queue;

	if (nb_Elements == 0)
	{
		tete = queue;
		courant = queue;
	}

	nb_Elements ++;

	return *this;
}


template <class X> Listes<X>& Listes<X>::InsertionCourant (const X& Elem)
{
	if (Est_Debut ())
		InsertionEnTete (Elem);
       	else
	{
		ElemListes<X>	*Nouv_Cour	= new ElemListes<X>;

		Nouv_Cour -> Valeur (Elem);
		Nouv_Cour -> Suivant (courant);
		Nouv_Cour -> Precedent (courant -> Precedent ());

		courant -> Precedent (Nouv_Cour);
		Nouv_Cour -> Precedent () -> Suivant (Nouv_Cour);

		nb_Elements ++;
	}

	return *this;
}


template <class X> Listes<X>& Listes<X>::SuppressionEnTete ()
{
	if (Est_Debut ())
		Avance ();

	ElemListes<X>	*Anc_Tete	= tete;

	tete = tete -> Suivant ();

	if (! Est_Vide (tete))
		tete -> Precedent (NULL);

	delete Anc_Tete;

	nb_Elements --;

	if (nb_Elements == 0)
	{
		queue = NULL;
		courant = NULL;
	}

	return *this;
}


template <class X> Listes<X>& Listes<X>::SuppressionEnQueue ()
{
	if (Est_Fin ())
		Recule ();

	ElemListes<X>	*Anc_Queue	= queue;

	queue = queue -> Precedent ();
	
	if (! Est_Vide (queue))
		queue -> Suivant (NULL);

	delete Anc_Queue;

	this->nb_Elements --;

	if (this->nb_Elements == 0)
	{
		tete = NULL;
		courant = NULL;
	}

	return *this;
}


template <class X> Listes<X>& Listes<X>::SuppressionCourant ()
{
	if (Est_Debut ())
		SuppressionEnTete ();
	else
	if (Est_Fin ())
		SuppressionEnQueue ();
	else
	{
		ElemListes<X>	*Anc_Courant	= courant;

		Avance ();

		Anc_Courant -> Precedent () -> Suivant (courant);
		courant -> Precedent (Anc_Courant -> Precedent ());

		delete Anc_Courant;

		this->nb_Elements --;
	}

	return *this;
}

// Supprime tous les maillons depuis celui pointé par P1 jusqu'à celui pointé par P2
// (y compris ces 2 maillons).
// ATTENTION : il faut être certain que *P2 vient APRES *P1 dans la liste
template <class X> 
Listes<X>& Listes<X>::Suppression_De_A (ElemListes<X> *P1, ElemListes<X> *P2)
{
	PlacerCourant (P1) ;
	
	while (courant != P2)
		SuppressionCourant () ;
	
	SuppressionCourant () ;

	return *this ;
}

template <class X> void Listes<X>::Tout_Parcourir (
	void (* Fonction) (X &, void *,unsigned long),
   void *Donnee , unsigned long PosDebut) const
{
	ElemListes<X>	*Pisteur	= tete;
   unsigned long i=PosDebut ;

	while (! Est_Vide (Pisteur))
	{
		Fonction (Pisteur -> valeur, Donnee,i++);
		Pisteur = Pisteur -> Suivant ();
	}
}


template <class X> void Listes<X>::Placer_Element(X &Elem, void *Donnee,unsigned long)
{
	Listes<X>	*L	= (Listes<X> *) Donnee;

	L -> InsertionEnQueue (Elem);
}


template <class X> Conteneurs<X>& Listes<X>::Detruit ()
{
	while (tete != NULL)
		SuppressionEnTete ();

	Conteneurs<X>::Detruit ();

	return *this;
}


template <class X> bool Listes<X>::Est_Vide (ElemListes<X> *Tete)
{
	return (Tete == NULL);
}


template <class X> void Listes<X>::Fusion (
	const Conteneurs<X> &CSource, Conteneurs<X> &CResultat) const
{
	if ((Conteneurs<X> *) this != &CResultat)
		Tout_Parcourir (Placer_Element, (void *) &CResultat);

	if (&CSource  != &CResultat)
		CSource.Tout_Parcourir (Placer_Element, (void *) &CResultat);
}

template <class X> 
void Listes<X>::Concatenation (Listes<X> &L2)
// Ajoute les maillons de L2 en queue de *this SANS LES DUPLIQUER !!
// L2 ne doit donc plus être utilisée après l'appel (elle est d'ailleurs
// vidée)
{
	if (L2.nb_Elements == 0)
		return ;

	else if (this->nb_Elements == 0) {
		tete = L2.tete ; courant = L2.courant ; queue = L2.queue ; this->nb_Elements = L2.nb_Elements ;
	}

	else {
		queue -> Suivant (L2.tete);
		L2.tete->Precedent (queue) ;
		courant = tete ;
		queue = L2.queue ;

		this->nb_Elements += L2.nb_Elements ;

		L2.tete = L2.courant = L2.queue = NULL ;
		L2.nb_Elements = 0 ;
	}
}

template <class X> Listes<X> &Listes<X>::Inversion ()
{
	ElemListes<X>	*Pisteur	= queue;
	ElemListes<X>	*Temp;
	ElemListes<X>	*AncTete	= tete;
	ElemListes<X>	*AncQueue	= queue;

	while (Pisteur != NULL)
	{
		Temp = Pisteur -> Suivant ();

		Pisteur -> Suivant (Pisteur -> Precedent ());
		Pisteur -> Precedent (Temp);

		Pisteur = Pisteur -> Suivant ();
	}

	tete = AncQueue;
	queue = AncTete;

	return *this;
}


template <class X> ostream& operator << (ostream & s, const Listes<X> &L)
{
	s << "Listes (Herite de : " << (Conteneurs<X> &) L << ")";
   ElemListes<X> *P=L.tete ;

   while ( P!=NULL )
   {
    	s<<P->Valeur()<<"	" ;
   	P=P->Suivant() ;
   }

	return s ;
}


template <class X> bool Listes<X>::operator <= (const Listes<X> & L2)
// Cette fonction tient compte du nb d'occurence de chaque valeur.
// Par exemple (1,1) est incluse dans (1,1,1) mais pas dans (1).
{
	bool Inclus = ((Conteneurs<X> &) (*this) <= (Conteneurs<X> &) L2);
        if (! Inclus) return false ;

	Iterateurs<X>	Pisteur	(*this) ;
        Listes <X>	CopieL2 = L2 ;
        ElemListes<X>	*ElementADetruire ;

	while (! Pisteur.Fin () && Inclus)
	{
		Inclus	= CopieL2.Est_Dans(Pisteur.Valeur(),&ElementADetruire);

                if (Inclus)
                {	CopieL2.courant = ElementADetruire ;
                	CopieL2.SuppressionCourant () ;
                }

		Pisteur.Avance ();
	}

	return Inclus;
}


template <class X> const Listes<X>& Listes<X>::operator = (const Listes<X> &O)
{
	if (&O != this)
	{
		Detruit ();

		ElemListes<X>	*Pisteur	= O.tete;

		while (! Est_Vide (Pisteur))
		{
			InsertionEnQueue (Pisteur -> Valeur ());

			if (Pisteur == O.courant)
				courant = queue;

			Pisteur = Pisteur -> Suivant ();
		}
	}

	return *this;
}

template <class X>
const Listes<X> & Listes<X>::operator+ (const Conteneurs<X> & L1)
{
	L1.Tout_Parcourir (Placer_Element, (void *) this);

//	ElemListes<X>	*PisteurL1	= L1.tete ;
//	while (PisteurL1 != NULL)
//	{
//		InsertionEnQueue (PisteurL1 -> Valeur ());
//		PisteurL1 = PisteurL1 -> Suivant ();
//	}
	return *this ;
}


template <class X> const Listes<X>& Listes<X>::operator = (const Conteneurs<X> &CSource)
{
	if (&CSource != this)
	{
		Detruit ();

		CSource.Tout_Parcourir (Placer_Element, (void *) this);
	}
	return *this;
}


template <class X> const Listes<X>& Listes<X>::operator () (const Conteneurs<X> &CSource)
{
	if (&CSource != this)
	{
		Detruit ();

		Conteneurs<X>::operator () (CSource);

		CSource.Tout_Parcourir (Placer_Element, (void *) this);
	}
	return *this;
}


template <class X> X& Listes<X>::operator [] (int Position)
{
	ElemListes<X>	*Pisteur	= tete;
	int		Pos		= 0;

	while (Pos < Position)
	{
		if (Est_Vide (Pisteur))
		{
			InsertionEnQueue (X ());
			Pisteur = queue;
		}

		Pisteur = Pisteur -> Suivant ();
		Pos ++;
	}

	if (Pisteur == NULL)
	{
		InsertionEnQueue (X ());
		Pisteur = queue;
	}

	return Pisteur -> valeur;
}

#endif	__Listes__h__
