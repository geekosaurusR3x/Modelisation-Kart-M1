//*****************************************************************************
//
// Module	: Iterateurs
//
// Fichier	: Iterateurs.h
//
// Auteur	: lanuel
//
// Date creat.	: Fri Aug 16 21:03:42 GMT+0100 1996
//
// Commentaires	: Interface de la classe Iterateurs.
//
//
//*****************************************************************************
// Classe Iterateurs
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************



#ifndef __Iterateurs__h__
#define	__Iterateurs__h__



#include	<iostream>
using namespace std ;
#include	<stdlib.h>

#include	"Listes.h"
#include	"ElemListes.h"



//*****************************************************************************
//
// Classe Iterateurs
//
//*****************************************************************************
template <class T>
class CONTENEURS_DLL  Iterateurs
{

public:


	//*****************************************************************************
	//	Constructeurs et destructeur
   // Ils sont tous les 4 définis ci-dessous pour obliger le compilateur à
   // les compiler. En effet, les 3 sont indispensables même s'ils ne sont
   // pas appelés explicitement.
	//*****************************************************************************

	Iterateurs()
   : courant(NULL), tete(NULL), queue(NULL)
   {
   }

	Iterateurs(const Iterateurs<T> &I)
   : courant(I.courant), tete(I.tete), queue(I.queue)
   {
   }

	~Iterateurs()
   {
   }

	Iterateurs(const Listes<T>&L)
   : courant(L.tete), tete(L.tete), queue(L.queue)
   {
   }


//*****************************************************************************
//	Accesseurs
//*****************************************************************************
	inline	const T	&		Valeur()		const;
	inline	T*			PtrValeur();
	inline	const Iterateurs<T>&	Valeur(const T &);


//*****************************************************************************
//	Methodes
//*****************************************************************************
	inline	void		InitDebut();
	inline	void		InitFin();
	inline	void		Avance();
	inline	void		Recule();
	inline	bool		Debut()				const;
	inline	bool		Fin()				const;


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const Iterateurs<T>&	operator = (const Iterateurs<T>&);


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	ElemListes<T>	*courant, *tete, *queue;

};


template <class T>
inline	const T &	Iterateurs<T>::Valeur()	const
{
	return courant->Valeur();
}


template <class T>
inline	T*	Iterateurs<T>::PtrValeur()
{
	return courant->PtrValeur();
}


template <class T>
inline	const Iterateurs<T>&	Iterateurs<T>::Valeur(const T & a)
{
	courant->Valeur(a);
	return *this;
}


template <class T>
inline	void		Iterateurs<T>::InitDebut()
{
	courant	= tete;
}


template <class T>
inline	void		Iterateurs<T>::InitFin()
{
	courant	= queue;
}


template <class T>
inline	void		Iterateurs<T>::Avance()
{
	courant	= courant->Suivant();
}


template <class T>
inline	void		Iterateurs<T>::Recule()
{
	courant	= courant->Precedent();
}


template <class T>
inline	bool		Iterateurs<T>::Debut()		const
{
	return courant==NULL;
}


template <class T>
inline	bool		Iterateurs<T>::Fin()			const
{
	return courant==NULL;
}

template <class T>
const Iterateurs<T>& Iterateurs<T>::operator = (const Iterateurs<T>& O)
{
	if (&O != this)
	{
		courant	= O.courant;
		tete	= O.tete;
		queue	= O.queue;
	}
	
	return *this;
}

#endif	__Iterateurs__h__
