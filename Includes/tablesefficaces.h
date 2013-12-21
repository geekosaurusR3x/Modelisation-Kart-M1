//---------------------------------------------------------------------------
#ifndef TablesEfficacesH
#define TablesEfficacesH

#include <iostream>
using namespace std ;

#include "ConteneursDLL.h"
#include "Tableaux.h"


///////////////////////////////////////////////////////////////////////
//
// La classe TablesEfficaces implemente efficacement une table,
// associant des cl�s � des valeurs. Elle r�alise TRES efficacement :
// - l'insertion d'un couple (cl�,valeur)
// - la suppression d'un couple (cl�,valeur)
// - la recherche de la valeur associ�e � une cl�.
//
// Les valeur associ�es aux cl�s sont fournies sous la forme de pointeurs
// non typ�s, qui sont les adresses des valeurs associ�es aux cl�s. La classe
// TablesEfficaces ne fait strctement rien de ces pointeurs, si ce n'est de
// les m�moriser lors de l'insertion d'un couple et de les restituer lors
// de la recherche.
//
// Ce fichier contient les interfaces ET IMPLEMENTATIONS des classes
// NoeudsAVL, FeuillesAVL, NoeudsNTAVL (toutes 3 sans int�r�t pour
// l'utilisateur) et de la classe TablesEfficaces, qui est LA
// classe importante.
//
// Aucun service d'affichage de TablesEfficaces n'est propos�. Pour afficher, faut donc
// demander la construction du tableau des valeurs et l'afficher.
// Aucun service de construction par copie n'est propos�. Faut donc
// passer les TablesEfficaces par r�f�rence ou par adresse.
// Aucun service d'�galit� n'est propos�.
//
// Pour le d�tail des services disponibles, rechercher "Classe TablesEfficaces".
//
// La structure de donn�es sous-jacente est l'arbre � hauteurs �quilibr�es (AVL).
//
//
// La classe TypeCleTable DOIT offrir les services suivants :
//
// - constructeur par d�faut
// - constructeur par copie
// - operateur =
// - operateur < : friend bool operator < (const TypeCleTable &P1,const TypeCleTable &P2)
// - operateur > : friend bool operator > (const TypeCleTable &P1,const TypeCleTable &P2)
// - operateur == : friend bool operator == (const TypeCleTable &P1,const TypeCleTable &P2)
//
///////////////////////////////////////////////////////////////////////


#define ArbresAVL NoeudsAVL<TypeCleTable>*


////////////////////////////////////////////////////
//
// Classe NoeudsAVL, classe m�re de
//	- NoeudsNTAVL (Noeuds Non Terminaux d'AVL)
// - FeuillesAVL (Feuilles d'AVL)
//
////////////////////////////////////////////////////

template <class TypeCleTable> class CONTENEURS_DLL NoeudsAVL
{
public :
	NoeudsAVL (const TypeCleTable &c, void *val, int FactEq) ;
   virtual ~NoeudsAVL () ;

   virtual ArbresAVL	Inserer (const TypeCleTable &c, void *info, bool &Grandi, bool &Succes) = 0 ;
	// Ins�re la cl� c et l'info associ�e si la cl� ne figure pas d�j�
   // dans l'arbre.
	// Succes est vrai si l'insertion a �t� r�alis�e.
	// L'arbre restitu� utilise int�gralement la m�moire de l'arbre initial.
   // L'arbre initial ne peut plus �tre utilis� apr�s l'appel.

   virtual ArbresAVL	Supprimer (const TypeCleTable &c, bool &Diminue, bool &Succes, void *&val) = 0 ;
	// Supprime la cl� c si elle figure dans l'arbre. Dans ce cas, le
   // pointeur restitu� est celui qui �tait associ� � la cl�.
	// Succes est vrai si la suppresion a �t� r�alis�e.
	// L'arbre restitu� utilise int�gralement la m�moire de l'arbre initial.
   // L'arbre initial ne peut plus �tre utilis� apr�s l'appel.

   virtual void		Min (TypeCleTable &c, void *&val) = 0 ;
   virtual void		Max (TypeCleTable &c, void *&val) = 0 ;
   // Restituent la plus petite ou la plus grande cl� et le pointeur associ�

   virtual void 		RemplirTableau (	bool OuiPourLesCles, 
													Tableaux <TypeCleTable> &TC,
													bool OuiPourLesValeurs,
													Tableaux <void *> &TP) = 0 ;
   // Ajoute au(x) tableau(x) les cl�s de l'arbre dans l'ordre infix� ou les
   // valeurs qui leurs sont associ�es ou les deux.
	// Attention : il s'agit bien d'ajout !! Les tableaux ne perdent pas leur
	// �ventuel contenu.

   virtual ArbresAVL FilsGauche () = 0 ;
   virtual ArbresAVL FilsDroit () = 0 ;

   virtual ArbresAVL Dupliquer () = 0 ;
   // La duplication ne provoque pas celle des valeurs associ�es aux cl�s

   virtual bool		EstValide (int &h) = 0 ;

   virtual bool		EstDans (const TypeCleTable &c, void *&val) = 0 ;
   // Restitue vrai ssi la cl� c appara�t dans l'arbre. Dans ce cas,
   // le pointeur restitu� est celui qui est associ� � la cl�.

   virtual bool ModifierValeur( const TypeCleTable& c, void*& val ) =0 ;
	// Modifier la valeur associ�e � la cl� c. Si la cl� est absente, le r�sultat est faux.
	// Sinon le remplacement est effectu�.
	// ATTENTION: l'ancienne valeur n'est pas d�sallou�e. L'appelant doit s'en occuper.

	int			fe ;
   TypeCleTable		cle ;
   void			*valeur ;

private :
   NoeudsAVL (const NoeudsAVL <TypeCleTable> &) {}
	const NoeudsAVL <TypeCleTable> & operator = (const NoeudsAVL <TypeCleTable> &o) {return o;}
	friend bool CONTENEURS_DLL operator == (const NoeudsAVL <TypeCleTable> &o1, const NoeudsAVL <TypeCleTable> &o2) {return false ;}
	friend ostream & CONTENEURS_DLL operator << (ostream &s, const NoeudsAVL <TypeCleTable> &o) {return s;}
} ;


////////////////////////////////////////////////////
//
// Classe FeuillesAVL
//
////////////////////////////////////////////////////

template <class TypeCleTable> class CONTENEURS_DLL FeuillesAVL : public NoeudsAVL <TypeCleTable>
{
public :
	FeuillesAVL (const TypeCleTable &c, void *val) ;
   ~FeuillesAVL () ;

   ArbresAVL	Inserer (const TypeCleTable &c, void *val, bool &Grandi, bool &Succes) ;
	// Ins�re la cl� c et l'info associ�e si la cl� ne figure pas d�j�
   // dans l'arbre.
	// Succes est vrai si l'insertion a �t� r�alis�e.
	// L'arbre restitu� utilise int�gralement la m�moire de l'arbre initial.
   // L'arbre initial ne peut plus �tre utilis� apr�s l'appel.

   ArbresAVL	Supprimer (const TypeCleTable &c, bool &Diminue, bool &Succes, void *&val) ;
	// Supprime la cl� c si elle figure dans l'arbre. Dans ce cas, le
   // pointeur restitu� est celui qui �tait associ� � la cl�.
	// Succes est vrai si la suppresion a �t� r�alis�e.
	// L'arbre restitu� utilise int�gralement la m�moire de l'arbre initial.
   // L'arbre initial ne peut plus �tre utilis� apr�s l'appel.

   void			Min (TypeCleTable &c, void *&val) ;
   void			Max (TypeCleTable &c, void *&val) ;
   // Restituent la plus petite ou la plus grande cl� et le pointeur associ�

   ArbresAVL 	FilsGauche () ;
   ArbresAVL 	FilsDroit () ;

   void 			RemplirTableau (	bool OuiPourLesCles, 
											Tableaux <TypeCleTable> &TC,
											bool OuiPourLesValeurs,
											Tableaux <void *> &TP) ;
   // Ajoute au(x) tableau(x) les cl�s de l'arbre dans l'ordre infix� ou les
   // valeurs qui leurs sont associ�es ou les deux.
	// Attention : il s'agit bien d'ajout !! Les tableaux ne perdent pas leur
	// �ventuel contenu.

   ArbresAVL 	Dupliquer () ;
   // La duplication ne provoque pas celle des valeurs associ�es aux cl�s

   bool			EstValide (int &h) ;

   bool			EstDans (const TypeCleTable &c, void *&val) ;
   // Restitue vrai ssi la cl� c appara�t dans l'arbre. Dans ce cas,
   // le pointeur restitu� est celui qui est associ� � la cl�.

   bool ModifierValeur( const TypeCleTable& c, void*& val ) ;
	// Modifier la valeur associ�e � la cl� c. Si la cl� est absente, le r�sultat est faux.
	// Sinon le remplacement est effectu�.
	// ATTENTION: l'ancienne valeur n'est pas d�sallou�e. L'appelant doit s'en occuper.
} ;


////////////////////////////////////////////////////
//
// Classe NoeudsNTAVL
//
////////////////////////////////////////////////////

template <class TypeCleTable> class CONTENEURS_DLL NoeudsNTAVL : public NoeudsAVL <TypeCleTable>
{
public :
	NoeudsNTAVL (const TypeCleTable &c, void *val, int FactEq, ArbresAVL FilsG, ArbresAVL FilsD) ;
   ~NoeudsNTAVL () ;

   ArbresAVL	Inserer (const TypeCleTable &c, void *val, bool &Grandi, bool &Succes) ;
	// Ins�re la cl� c et l'info associ�e si la cl� ne figure pas d�j�
   // dans l'arbre.
	// Succes est vrai si l'insertion a �t� r�alis�e.
	// L'arbre restitu� utilise int�gralement la m�moire de l'arbre initial.
   // L'arbre initial ne peut plus �tre utilis� apr�s l'appel.

   ArbresAVL	Supprimer (const TypeCleTable &c, bool &Diminue, bool &Succes, void *&val) ;
	// Supprime la cl� c si elle figure dans l'arbre. Dans ce cas, le
   // pointeur restitu� est celui qui �tait associ� � la cl�.
	// Succes est vrai si la suppresion a �t� r�alis�e.
	// L'arbre restitu� utilise int�gralement la m�moire de l'arbre initial.
   // L'arbre initial ne peut plus �tre utilis� apr�s l'appel.

   void			Min (TypeCleTable &c, void *&val) ;
   void			Max (TypeCleTable &c, void *&val) ;
   // Restituent la plus petite ou la plus grande cl� et le pointeur associ�

   ArbresAVL 	FilsGauche () ;
   ArbresAVL 	FilsDroit () ;

   void 			RemplirTableau (	bool OuiPourLesCles, 
											Tableaux <TypeCleTable> &TC,
											bool OuiPourLesValeurs,
											Tableaux <void *> &TP) ;
   // Ajoute au(x) tableau(x) les cl�s de l'arbre dans l'ordre infix� ou les
   // valeurs qui leurs sont associ�es ou les deux.
	// Attention : il s'agit bien d'ajout !! Les tableaux ne perdent pas leur
	// �ventuel contenu.

   ArbresAVL 	Dupliquer () ;
   // La duplication ne provoque pas celle des valeurs associ�es aux cl�s

   bool			EstValide (int &h) ;

   bool			EstDans (const TypeCleTable &c, void *&val) ;
   // Restitue vrai ssi la cl� c appara�t dans l'arbre. Dans ce cas,
   // le pointeur restitu� est celui qui est associ� � la cl�.

   bool ModifierValeur( const TypeCleTable& c, void*& val ) ;
	// Modifier la valeur associ�e � la cl� c. Si la cl� est absente, le r�sultat est faux.
	// Sinon le remplacement est effectu�.
	// ATTENTION: l'ancienne valeur n'est pas d�sallou�e. L'appelant doit s'en occuper.


private :
	ArbresAVL	fg ;
   ArbresAVL	fd ;

   ArbresAVL EquilibrageGaucheApresInsertion () ;
   ArbresAVL EquilibrageDroitApresInsertion () ;
   ArbresAVL EquilibrageGaucheApresSuppression (bool &Diminue) ;
   ArbresAVL EquilibrageDroitApresSuppression (bool &Diminue) ;
} ;


////////////////////////////////////////////////////
//
// Classe TablesEfficaces
//
////////////////////////////////////////////////////

template <class TypeCleTable> class CONTENEURS_DLL TablesEfficaces
{
public :
	TablesEfficaces () ;
	~ TablesEfficaces () ;

   bool	EstVide () ;

   void	Vider () ;
	// Retire du conteneur toutes les cl�s qu'il contient. Les pointeurs
   // associ�s aux cl�s ne sont pas d�sallou�s

   bool	Inserer (const TypeCleTable &c, void *val) ;
	// Ins�re la cl� c et l'info associ�e si la cl� ne figure pas d�j�
   // dans la table.
   // Le r�sultat est vrai ssi l'insertion a �t� possible, c'est � dire
   // que c n'�tait pas d�j� dans l'arbre.
   // Le pointeur est l'adresse d'un quelconque objet que l'on souhaite
   // associer � la cl�.

   bool	Supprimer (const TypeCleTable &c, void *&val) ;
	// Supprime la cl� c si elle figure dans la table. Dans ce cas, le
   // r�sultat est vrai et le pointeur restitu� est celui qui �tait
   // associ� � la cl�.

   void 	EnTableau (	bool OuiPourLesCles, 
							Tableaux <TypeCleTable> &TC,
							bool OuiPourLesValeurs,
							Tableaux <void *> &TP) const ;
   // Initialise le tableau TC avec les cl�s contenues dans le conteneur
   // par ordre croissant et TP avec les pointeurs associ�s � chaque cl�.
   // TP [i] est le pointeur associ� � la cl� TC [i]
	// Le pr�c�dent contenu des tableaux est perdu.
	// TC n'est initialis� que si le premier bool�en est vrai, TP que si le 
	// deuxi�me l'est.

   void	Min (TypeCleTable &c, void *&val) ;
   void	Max (TypeCleTable &c, void *&val) ;
   // Restituent la plus petite ou la plus grande cl� et le pointeur associ�

   int	NombreElements () const ;

   bool	EstDans (const TypeCleTable &c, void *&val) ;
   // Restitue vrai ssi la cl� c appara�t dans l'arbre. Dans ce cas,
   // le pointeur restitu� est celui qui est associ� � la cl�.

	const TablesEfficaces & operator = (const TablesEfficaces &o) ;
   // L'affectation ne provoque pas la duplication des valeurs associ�es
   // aux cl�s : les pointeurs sont r�-utilis�s tels quels.

	bool ModifierValeur( const TypeCleTable& c, void*& val ) ;
	// Modifier la valeur associ�e � la cl� c. Si la cl� est absente, le r�sultat est faux.
	// Sinon le remplacement est effectu�.
	// ATTENTION: l'ancienne valeur n'est pas d�sallou�e. L'appelant doit s'en occuper.


private :
	TablesEfficaces (const TablesEfficaces &o) {}
	friend bool CONTENEURS_DLL operator == (const TablesEfficaces &o1, const TablesEfficaces &o2) {return false ;}
	friend ostream & CONTENEURS_DLL operator << (ostream &s, const TablesEfficaces &o) {return s;}
   bool	EstValide () ;

	ArbresAVL		a ;
   unsigned long	nombreElements ;
} ;


////////////////////////////////////////////////////
//
// Implementation de la classe NoeudsAVL
//
////////////////////////////////////////////////////

template <class TypeCleTable>
NoeudsAVL <TypeCleTable>::NoeudsAVL (const TypeCleTable &c, void *val, int FactEq)
:	fe (FactEq), cle (c), valeur (val)
{
}


template <class TypeCleTable> NoeudsAVL <TypeCleTable>::~NoeudsAVL ()
{
}


////////////////////////////////////////////////////
//
// Implementation de la classe FeuillesAVL
//
////////////////////////////////////////////////////

template <class TypeCleTable> FeuillesAVL <TypeCleTable>::FeuillesAVL (const TypeCleTable &c, void *val)
:	NoeudsAVL <TypeCleTable> (c,val,0)
{
}


template <class TypeCleTable> FeuillesAVL <TypeCleTable>::~FeuillesAVL ()
{
}


template <class TypeCleTable> ArbresAVL	FeuillesAVL <TypeCleTable>::Inserer (const TypeCleTable &c, void *val, bool &Grandi, bool &Succes)
// Ins�re la cl� c et l'info associ�e si la cl� ne figure pas d�j�
// dans l'arbre.
// Succes est vrai si l'insertion a �t� r�alis�e.
// L'arbre restitu� utilise int�gralement la m�moire de l'arbre initial.
// L'arbre initial ne peut plus �tre utilis� apr�s l'appel.
{
	if (c == cle)
   {
   	Grandi = false ;
      Succes = false ;
      return this ;
   }
   else
   {
	   Grandi = Succes = true ;

		if (c < cle)
	   {
   		ArbresAVL	r = new NoeudsNTAVL<TypeCleTable> (cle,valeur,1,this,NULL) ;

      	cle = c ;
         valeur = val ;
	      return r ;
   	}
	   else
   	{
   		ArbresAVL	r = new NoeudsNTAVL<TypeCleTable> (cle,valeur,-1,NULL,this) ;

      	cle = c ;
         valeur = val ;
   	   return r ;
	   }
   }
}


template <class TypeCleTable> ArbresAVL	FeuillesAVL <TypeCleTable>::Supprimer (const TypeCleTable &c, bool &Diminue, bool &Succes, void *&val)
// Supprime la cl� c si elle figure dans l'arbre. Dans ce cas, le
// pointeur restitu� est celui qui �tait associ� � la cl�.
// Succes est vrai si la suppresion a �t� r�alis�e.
// L'arbre restitu� utilise int�gralement la m�moire de l'arbre initial.
// L'arbre initial ne peut plus �tre utilis� apr�s l'appel.
{
	if (c == cle)
   {
   	val = valeur ;
   	delete this ;
      Diminue = Succes = true ;
      return NULL ;
   }
   else
   {
		Diminue = Succes = false ;
      val = NULL ;
      return this ;
   }
}


// Restituent la plus petite ou la plus grande cl� et le pointeur associ�
template <class TypeCleTable> void	FeuillesAVL <TypeCleTable>::Min (TypeCleTable &c, void *&val)
{
	c = cle ; val = valeur ;
}


// Restituent la plus petite ou la plus grande cl� et le pointeur associ�
template <class TypeCleTable> void FeuillesAVL <TypeCleTable>::Max (TypeCleTable &c, void *&val)
{
	c = cle ; val = valeur ;
}


template <class TypeCleTable> ArbresAVL FeuillesAVL <TypeCleTable>::FilsGauche ()
{
	return NULL ;
}


template <class TypeCleTable> ArbresAVL FeuillesAVL <TypeCleTable>::FilsDroit ()
{
	return NULL ;
}


template <class TypeCleTable> 
void FeuillesAVL <TypeCleTable>::RemplirTableau (	bool OuiPourLesCles, 
																	Tableaux <TypeCleTable> &TC,
																	bool OuiPourLesValeurs,
																	Tableaux <void *> &TP)
   
// Ajoute au(x) tableau(x) les cl�s de l'arbre dans l'ordre infix� ou les
// valeurs qui leurs sont associ�es ou les deux.
// Attention : il s'agit bien d'ajout !! Les tableaux ne perdent pas leur
// �ventuel contenu.
{
	if (OuiPourLesCles)
		TC [TC.Nb_Effectifs ()] = cle ;
	if (OuiPourLesValeurs)
		TP [TP.Nb_Effectifs ()] = valeur ;
}


template <class TypeCleTable> ArbresAVL FeuillesAVL <TypeCleTable>::Dupliquer ()
// La duplication ne provoque pas celle des valeurs associ�es aux cl�s
{
	return new FeuillesAVL <TypeCleTable> (cle,valeur) ;
}


template <class TypeCleTable> bool	FeuillesAVL <TypeCleTable> :: EstValide (int &h)
{
	h = 1 ;
	return fe == 0 ;
}


template <class TypeCleTable> bool			FeuillesAVL <TypeCleTable> :: EstDans (const TypeCleTable &c, void *&val)
{
	if (c == cle)
   {
   	val = valeur ;
      return true ;
   }
   else
   {
   	val = NULL ;
		return false ;
   }
}


template <class TypeCleTable> bool FeuillesAVL <TypeCleTable> :: ModifierValeur( const TypeCleTable& c, void*& val )
	// Modifier la valeur associ�e � la cl� c. Si la cl� est absente, le r�sultat est faux.
	// Sinon le remplacement est effectu�.
	// ATTENTION: l'ancienne valeur n'est pas d�sallou�e. L'appelant doit s'en occuper.
{
	if (c == cle)
   {
   	valeur = val ;
      return true ;
   }
   else
   {
	 return false ;
   }
}

////////////////////////////////////////////////////
//
// Implementation de la classe NoeudsNTAVL
//
////////////////////////////////////////////////////

template <class TypeCleTable> NoeudsNTAVL <TypeCleTable>::NoeudsNTAVL (const TypeCleTable &c, void *val, int FactEq, ArbresAVL FilsG, ArbresAVL FilsD)
:	NoeudsAVL <TypeCleTable> (c,val,FactEq), fg (FilsG), fd (FilsD)
{
}


template <class TypeCleTable> NoeudsNTAVL <TypeCleTable>::~NoeudsNTAVL ()
{
	delete fg ;
   delete fd ;
}


template <class TypeCleTable> ArbresAVL	NoeudsNTAVL <TypeCleTable>::Inserer (const TypeCleTable &c, void *val, bool &Grandi, bool &Succes)
// Ins�re la cl� c et l'info associ�e si la cl� ne figure pas d�j�
// dans l'arbre.
// Succes est vrai si l'insertion a �t� r�alis�e.
// L'arbre restitu� utilise int�gralement la m�moire de l'arbre initial.
// L'arbre initial ne peut plus �tre utilis� apr�s l'appel.
{
	if (c < cle)
   {
   	if (fg == NULL)
      {
      	// FD ne peut �tre nul aussi sinon, on serait sur une feuille
         // ==> FE = -1 avant insertion et passe � 0 apr�s
      	fg = new FeuillesAVL <TypeCleTable> (c,val) ;
         fe = 0 ;
         Grandi = false ;
         Succes = true ;
         return this ;
      }
      else
	   {
   		fg = fg->Inserer (c,val,Grandi,Succes) ;
         if (Grandi)
         	switch (fe)
            {
            case -1 : Grandi = false ;
            			 fe = 0 ;
            			 return this ;
            			 break ;
            case 0  : // Grandi = true ;
							 fe = 1 ;
                      return this ;
            			 break ;
            case +1 : {
            			 ArbresAVL AE = EquilibrageGaucheApresInsertion () ;
            			 Grandi = false ;
                      return AE ;
                      }
            			 break ;
            default : return NULL ;
            			 break ;
            }
         else
         	return this ;
	   }
   }
   else if (c > cle)
   {
   	if (fd == NULL)
      {
      	// FG ne peut �tre nul aussi sinon, on serait sur une feuille
         // ==> FE = 1 avant insertion et passe � 0 apr�s
      	fd = new FeuillesAVL <TypeCleTable> (c,val) ;
         fe = 0 ;
         Grandi = false ;
         Succes = true ;
         return this ;
      }
      else
	   {
   		fd = fd->Inserer (c,val,Grandi,Succes) ;
         if (Grandi)
         	switch (fe)
            {
            case +1 : Grandi = false ;
            			 fe = 0 ;
            			 return this ;
            			 break ;
            case 0  : // Grandi = true ;
							 fe = -1 ;
                      return this ;
            			 break ;
            case -1 : {
            			 ArbresAVL AE = EquilibrageDroitApresInsertion () ;
            			 Grandi = false ;
                      return AE ;
                      }
            			 break ;
            default : return NULL ;
            			 break ;
            }
         else
         	return this ;
	   }
   }
   else
   {
   	Grandi = Succes = false ;
   	return this ;
   }
}


template <class TypeCleTable> ArbresAVL NoeudsNTAVL <TypeCleTable>::EquilibrageGaucheApresInsertion ()
{
	// Puisqu'il y a besoin d'un �quilibrage, le fe du fils gauche ne peut
   // �tre nul ==> il vaut 1 ou -1
	if (fg->fe == 1)
   {
   	// L'insertion a eu lieu "sous" le fils gauche du fils gauche.
      NoeudsNTAVL <TypeCleTable>		*NR = (NoeudsNTAVL <TypeCleTable> *) fg ;
      NR->fe = 0 ;
      // Si le fd de this est vide, alors le fd du fg l'est aussi et le fils droit
      // de l'arbre reconstruit sera UNE FEUILLE --> 1 cas particulier
      if (fd == NULL)
      {
      	NR->fd = new FeuillesAVL <TypeCleTable> (cle,valeur) ;
		fg = NULL ;
		delete this ;
      }
      else
      {
	      fg = NR->fd ;
   	   fe = 0 ;
      	NR->fd = this ;
      }
      return NR ;
   }
   else
   {
   	NoeudsNTAVL <TypeCleTable>	*FG = (NoeudsNTAVL <TypeCleTable> *) fg ;
   	// L'insertion a eu lieu "sous" le fils droit du fils gauche ==> faut
      // voir si le fils gauche �tait r�duit � une feuille avant insertion
   	if (FG->fd->fe == 0)
      {
      	// Le fils gauche �tait une feuille et a maintenant la nouvelle
         // cle comme fils droit
			fd = new FeuillesAVL <TypeCleTable> (cle,valeur) ;
			cle = FG->fd->cle ;
         valeur = FG->fd->valeur ;
         fe = 0 ;
         FG->fd->cle = fg->cle ;
         FG->fd->valeur = fg->valeur ;
         fg = FG->fd ;
         FG->fd = NULL ;
         delete FG ;
         return this ;
      }
      else
      {
      	// Le fils gauche avait un fils droit non vide et �quilibr�. Ce
         // fils droit est maintenant d�s�quilibr� du c�t� o� a eu lieu
         // l'insertion
         NoeudsNTAVL <TypeCleTable>		*FGD = (NoeudsNTAVL <TypeCleTable> *) FG->fd ;

         fg = FGD->fd ;
         FGD->fd = this ;
         FG->fd = FGD->fg ;
         FGD->fg = FG ;

         if (FGD->fe == 1)	// l'insertion a eu lieu sous le fg du fd du fg
         {
         	FGD->fg->fe = 0 ; FGD->fd->fe = -1 ;
         }
         else
         {
         	FGD->fg->fe = 1 ; FGD->fd->fe = 0 ;
         }
         FGD->fe = 0 ;

         return FGD ;
      }
   }
}


template <class TypeCleTable> ArbresAVL NoeudsNTAVL <TypeCleTable>::EquilibrageDroitApresInsertion ()
{
	// Puisqu'il y a besoin d'un �quilibrage, le fe du fils droit ne peut
   // �tre nul ==> il vaut 1 ou -1
	if (fd->fe == -1)
   {
   	// L'insertion a eu lieu "sous" le fils droit du fils droit

      NoeudsNTAVL <TypeCleTable>		*NR = (NoeudsNTAVL <TypeCleTable> *) fd ;
      NR->fe = 0 ;

      // Si le fg de this est vide, alors le fg du fd l'est aussi et le fils gauche
      // de l'arbre reconstruit sera UNE FEUILLE --> 1 cas particulier
      if (fg == NULL)
      {
      	NR->fg = new FeuillesAVL <TypeCleTable> (cle,valeur) ;
		fd = NULL ;
		delete this ;
      }
      else
      {
	      fd = NR->fg ;
   	   fe = 0 ;
      	NR->fg = this ;
      }
      return NR ;
   }
   else
   {
   	NoeudsNTAVL <TypeCleTable>	*FD = (NoeudsNTAVL <TypeCleTable> *) fd ;
   	// L'insertion a eu lieu "sous" le fils gauche du fils droit ==> faut
      // voir si le fils droit �tait r�duit � une feuille avant insertion
   	if (FD->fg->fe == 0)
      {
      	// Le fils droit �tait une feuille et a maintenant la nouvelle
         // cle comme fils gauche
			fg = new FeuillesAVL <TypeCleTable> (cle,valeur) ;
			cle = FD->fg->cle ;
			valeur = FD->fg->valeur ;
         fe = 0 ;
         FD->fg->cle = fd->cle ;
         FD->fg->valeur = fd->valeur ;
         fd = FD->fg ;
         FD->fg = NULL ;
         delete FD ;
         return this ;
      }
      else
      {
      	// Le fils droit avait un fils gauche non vide et �quilibr�. Ce
         // fils gauche est maintenant d�s�quilibr� du c�t� o� a eu lieu
         // l'insertion
         NoeudsNTAVL <TypeCleTable>		*FDG = (NoeudsNTAVL <TypeCleTable> *) FD->fg ;

         fd = FDG->fg ;
         FDG->fg = this ;
         FD->fg = FDG->fd ;
         FDG->fd = FD ;

         if (FDG->fe == 1)	// l'insertion a eu lieu sous le fg du fg du fd
         {
         	FDG->fg->fe = 0 ; FDG->fd->fe = -1 ;
         }
         else
         {
         	FDG->fg->fe = 1 ; FDG->fd->fe = 0 ;
         }
         FDG->fe = 0 ;

         return FDG ;
      }
   }
}


template <class TypeCleTable> ArbresAVL	NoeudsNTAVL <TypeCleTable>::Supprimer (const TypeCleTable &c, bool &Diminue, bool &Succes, void *&val)
// Supprime la cl� c si elle figure dans l'arbre. Dans ce cas, le
// pointeur restitu� est celui qui �tait associ� � la cl�.
// Succes est vrai si la suppresion a �t� r�alis�e.
// L'arbre restitu� utilise int�gralement la m�moire de l'arbre initial.
// L'arbre initial ne peut plus �tre utilis� apr�s l'appel.
{
	if (c < cle)	// Suppression � gauche
   	if (fg)
	   {
   		fg = fg->Supprimer (c,Diminue,Succes,val) ;

			// 1er cas : il n'y a pas de fils droit et le fils gauche dispara�t
         // --> le noeud devient une feuille
      	if ((fg == NULL) && (fe == 1))
	      {
   	   	// Le noeud courant redevient une feuille car il a perdu son unique fils
      		FeuillesAVL <TypeCleTable>	*f = new FeuillesAVL <TypeCleTable> (cle,valeur) ;
         	Diminue = true ;
	         delete this ;
   	      return f ;
      	}

         // Deuxi�me cas : le fils droit existe et le fils gauche diminue.
	      else if (Diminue)
	         switch (fe)
            {
            case 1 : fe = 0 ; // Diminue reste vrai
							return this ;
            			break ;
            case 0 : fe = -1 ;
            			Diminue = false ;
							return this ;
                     break ;
            default:	// des�quilibre
            			ArbresAVL	AE = EquilibrageGaucheApresSuppression (Diminue) ;
                     return AE ;
            }
         else
         	return this ;
      }
      else
      {
      	Diminue = Succes = false ;
         return this ;
      }

   else if (c > cle)	// Suppression � droite
   	if (fd)
	   {
   		fd = fd->Supprimer (c,Diminue,Succes,val) ;

			// 1er cas : il n'y a pas de fils gauche et le fils droit dispara�t
         // --> le noeud devient une feuille
      	if ((fd == NULL) && (fe == -1))
	      {
   	   	// Le noeud courant redevient une feuille car il a perdu son unique fils
      		FeuillesAVL <TypeCleTable>	*f = new FeuillesAVL <TypeCleTable> (cle,valeur) ;
         	Diminue = true ;
	         delete this ;
   	      return f ;
      	}

         // Deuxi�me cas : le fils gauche existe et le fils droit diminue.
	      else if (Diminue)
	         switch (fe)
            {
            case -1: fe = 0 ; // Diminue reste vrai
							return this ;
            			break ;
            case 0 : fe = 1 ;
            			Diminue = false ;
							return this ;
                     break ;
            default:	// des�quilibre
            			ArbresAVL	AE = EquilibrageDroitApresSuppression (Diminue) ;
                     return AE ;
            }
         else
         	return this ;
      }
      else
      {
      	Diminue = Succes = false ;
         return this ;
      }

   else	// Suppression de la racine. Il y a au moins un fils car
   		// on n'est pas dans une feuille
		if (fe >= 0)
	   {
      	val = valeur ;

			// remplace la racine par le max du fg et l'y supprime
			fg->Max (cle,valeur) ;
			fg = fg->Supprimer (cle,Diminue,Succes,valeur) ;

      	if ((fg == NULL) && (fe == 1))
	      {
   	   	// Le noeud courant redevient une feuille car il a perdu son unique fils
      		FeuillesAVL <TypeCleTable>	*f = new FeuillesAVL <TypeCleTable> (cle,valeur) ;
            // Diminue et Succes sont d�j� vrais
	         delete this ;
   	      return f ;
      	}
         else
         {
         	if (Diminue)
				{
   	         fe-- ;
      	   	if (fe == -1)
						Diminue = false ;
            	// else Diminue reste vrai
	         }

   	      // Succes reste true
      	   return this ;
         }
   	}
      else
	   {
      	val = valeur ;

			// remplace la racine par le min du fd et l'y supprime
			fd->Min (cle,valeur) ;
			fd = fd->Supprimer (cle,Diminue,Succes,valeur) ;

      	if ((fd == NULL) && (fe == -1))
	      {
   	   	// Le noeud courant redevient une feuille car il a perdu son unique fils
      		FeuillesAVL <TypeCleTable>	*f = new FeuillesAVL <TypeCleTable> (cle,valeur) ;
            // Diminue et Succes sont d�j� vrais
	         delete this ;
   	      return f ;
      	}
         else
         {
	         if (Diminue)
   	         fe = 0 ;
      	      // Diminue reste vrai

	         // Succes reste true
   	      return this ;
         }
   	}
}


template <class TypeCleTable> ArbresAVL NoeudsNTAVL <TypeCleTable>::FilsGauche ()
{
	return fg ;
}


template <class TypeCleTable> ArbresAVL NoeudsNTAVL <TypeCleTable>::FilsDroit ()
{
	return fd ;
}


// Restitue la plus grande cl� et le pointeur associ�
template <class TypeCleTable> void NoeudsNTAVL <TypeCleTable>::Max (TypeCleTable &c, void *&val)
{
	ArbresAVL	a = this ;

   while (a->FilsDroit () != NULL)
   	a = a->FilsDroit () ;

	c = a->cle ;
	val = a->valeur ;
}


// Restitue la plus petite cl� et le pointeur associ�
template <class TypeCleTable> void NoeudsNTAVL <TypeCleTable>::Min (TypeCleTable &c, void *&val)
{
	ArbresAVL	a = this ;

   while (a->FilsGauche () != NULL)
   	a = a->FilsGauche () ;

	c = a->cle ;
	val = a->valeur ;
}


template <class TypeCleTable> ArbresAVL NoeudsNTAVL <TypeCleTable>::EquilibrageGaucheApresSuppression (bool &Diminue)
// Le fils droit est de 2 plus haut que le gauche
{
	NoeudsNTAVL <TypeCleTable>	*FD = (NoeudsNTAVL <TypeCleTable> *) fd,
   						*FDG = (NoeudsNTAVL <TypeCleTable> *) FD->fg ;

   if (FD->fe <= 0)
   {
   	// Il se peut que le fg de l'arbre reconstruit soit une feuille
      // ==> un cas particulier
      if (FDG == NULL)
      {
      	FD->fg = new FeuillesAVL <TypeCleTable> (cle,valeur) ;
         fd = NULL ;
         delete this ;
         FD->fe = 0 ;
         Diminue = true ;
      }
      else
      {
	   	this->fd = FDG ;
   	   FD->fg = this ;

   	   if (FD->fe == -1)
	      {
				fe = 0 ; FD->fe = 0 ; Diminue = true ;
	      }
   	   else
      	{
				fe = -1 ; FD->fe = 1 ; Diminue = false ;
	      }
      }

      return FD ;
   }
   else
   	// Il se peut que les fils de l'arbre reconstruit soient des feuilles
      // --> un cas particulier
      if (fg == NULL)
      {
      	ArbresAVL r = new NoeudsNTAVL <TypeCleTable> (	FDG->cle,FDG->valeur,0,
         												new FeuillesAVL <TypeCleTable> (cle,valeur),
         												new FeuillesAVL <TypeCleTable> (fd->cle,fd->valeur)) ;
         delete this ;
         Diminue = true ;
         return r ;
      }
      else
      {
			fd = FDG->fg ;
      	FD->fg = FDG->fd ;
	      FDG->fg = this ;
   	   FDG->fd = FD ;

	      switch (FDG->fe)
   	   {
      	case -1 : FDG->fg->fe = 1 ; FDG->fd->fe = 0 ;
         			 break ;
	      case  0 : FDG->fg->fe = 0 ; FDG->fd->fe = 0 ;
         			 break ;
   	   default : FDG->fg->fe = 0 ; FDG->fd->fe = -1 ;
         			 break ;
      	}

	      Diminue = true ; FDG->fe = 0 ;
      	return FDG ;
   	}
}


template <class TypeCleTable> ArbresAVL NoeudsNTAVL <TypeCleTable>::EquilibrageDroitApresSuppression (bool &Diminue)
// Le fils gauche est de 2 plus haut que le droit
{
	NoeudsNTAVL <TypeCleTable>	*FG = (NoeudsNTAVL <TypeCleTable> *) fg,
   						*FGD = (NoeudsNTAVL <TypeCleTable> *) FG->fd ;

   if (FG->fe >= 0)
   {
   	// Il se peut que le fd de l'arbre reconstruit soit une feuille
      // ==> un cas particulier
      if (FGD == NULL)
      {
      	FG->fd = new FeuillesAVL <TypeCleTable> (cle,valeur) ;
         fg = NULL ;
         delete this ;
         FG->fe = 0 ;
         Diminue = true ;
      }
      else
      {
	   	this->fg = FGD ;
   	   FG->fd = this ;

      	if (FG->fe == 1)
	      {
				fe = 0 ; FG->fe = 0 ; Diminue = true ;
      	}
	      else
   	   {
				fe = 1 ; FG->fe = -1 ; Diminue = false ;
	      }
   	}

      return FG ;
   }
   else
   	// Il se peut que les fils de l'arbre reconstruit soient des feuilles
      // --> un cas particulier
      if (fd == NULL)
      {
      	ArbresAVL r = new NoeudsNTAVL <TypeCleTable> (	FGD->cle,FGD->valeur,0,
         												new FeuillesAVL <TypeCleTable> (fg->cle,fg->valeur),
         												new FeuillesAVL <TypeCleTable> (cle,valeur)) ;
         delete this ;
         Diminue = true ;
         return r ;
      }
      else
      {
			fg = FGD->fd ;
   	   FG->fd = FGD->fg ;
      	FGD->fg = FG ;
	      FGD->fd = this ;

   	   switch (FGD->fe)
      	{
	      case -1 : FGD->fg->fe = 1 ; FGD->fd->fe = 0 ;
         			 break ;
   	   case  0 : FGD->fg->fe = 0 ; FGD->fd->fe = 0 ;
         			 break ;
      	default : FGD->fg->fe = 0 ; FGD->fd->fe = -1 ;
         			 break ;
	      }

   	   Diminue = true ; FGD->fe = 0 ;
	      return FGD ;
      }
}


template <class TypeCleTable> 
void NoeudsNTAVL <TypeCleTable>::RemplirTableau (	bool OuiPourLesCles, 
																	Tableaux <TypeCleTable> &TC,
																	bool OuiPourLesValeurs,
																	Tableaux <void *> &TP)
   
// Ajoute au(x) tableau(x) les cl�s de l'arbre dans l'ordre infix� ou les
// valeurs qui leurs sont associ�es ou les deux.
// Attention : il s'agit bien d'ajout !! Les tableaux ne perdent pas leur
// �ventuel contenu.
{
	if (fg)
   	fg->RemplirTableau (OuiPourLesCles,TC,OuiPourLesValeurs,TP) ;

	if (OuiPourLesCles)
		TC [TC.Nb_Effectifs ()] = cle ;

	if (OuiPourLesValeurs)
		TP [TP.Nb_Effectifs ()] = valeur ;

	if (fd)
   	fd->RemplirTableau (OuiPourLesCles,TC,OuiPourLesValeurs,TP) ;
}


template <class TypeCleTable> ArbresAVL NoeudsNTAVL <TypeCleTable>::Dupliquer ()
// La duplication ne provoque pas celle des valeurs associ�es aux cl�s
{
	return new NoeudsNTAVL <TypeCleTable> (cle,valeur,fe,
   									 (fg)?fg->Dupliquer ():NULL,
                           	 (fd)?fd->Dupliquer ():NULL) ;
}


template <class TypeCleTable> bool	NoeudsNTAVL  <TypeCleTable>:: EstValide (int &h)
{
	int	h1,h2 ;

	if (fg)
   	if (fd)
      {
      	if (fg->EstValide (h1) && fd->EstValide (h2) && (fe == h1-h2))
         {
         	h = 1+((h1>h2)?h1:h2) ;
            return true ;
         }
         else
         	return false ;
      }
      else
      {
      	h = 2 ;
      	if (fg->EstValide (h1) && (h1 == 1) && (fe == 1))
         	return true ;
         else
         	return false ;
      }
   else
   	if (fd)
      {
      	h = 2 ;
      	if (fd->EstValide (h2) && (h2 == 1) && (fe == -1))
         	return true ;
         else
         	return false ;
      }
      else
      	return false ;
}


template <class TypeCleTable> bool			NoeudsNTAVL <TypeCleTable> :: EstDans (const TypeCleTable &c, void *&val)
{
	if (cle == c)
   {
   	val = valeur ;
   	return true ;
   }
   else if (c < cle)
   	if (fg)
      	return fg->EstDans (c,val) ;
      else
      	return false ;
   else
   	if (fd)
      	return fd->EstDans (c,val) ;
      else
      	return false ;
}


template <class TypeCleTable> bool NoeudsNTAVL <TypeCleTable> :: ModifierValeur( const TypeCleTable& c, void*& val )
	// Modifier la valeur associ�e � la cl� c. Si la cl� est absente, le r�sultat est faux.
	// Sinon le remplacement est effectu�.
	// ATTENTION: l'ancienne valeur n'est pas d�sallou�e. L'appelant doit s'en occuper.
{
	if (cle == c)
   {
   	valeur=val ;
   	return true ;
   }
   else if (c < cle)
   	if (fg)
      	return fg->ModifierValeur (c,val) ;
      else
      	return false ;
   else
   	if (fd)
      	return fd->ModifierValeur (c,val) ;
      else
      	return false ;
}

////////////////////////////////////////////////////
//
// Implementation de la classe TablesEfficaces
//
////////////////////////////////////////////////////

template <class TypeCleTable> TablesEfficaces <TypeCleTable> :: TablesEfficaces ()
:	a (NULL), nombreElements (0)
{
}


template <class TypeCleTable> TablesEfficaces <TypeCleTable> :: ~TablesEfficaces ()
{
	if (a)
   	delete a ;
   nombreElements = 0 ;
   a = NULL ;
}


template <class TypeCleTable> void TablesEfficaces <TypeCleTable> :: Vider ()
// Retire du conteneur toutes les cl�s qu'il contient. Les pointeurs
// associ�s aux cl�s ne sont pas d�sallou�s
{
	if (a)
   	delete a ;
   nombreElements = 0 ;
   a = NULL ;
}


template <class TypeCleTable> bool	TablesEfficaces <TypeCleTable> :: EstVide ()
{
	return a == NULL ;
}


template <class TypeCleTable> bool	TablesEfficaces <TypeCleTable> :: Inserer (const TypeCleTable &c, void *val)
// Ins�re la cl� c et l'info associ�e si la cl� ne figure pas d�j�
// dans la table.
// Le r�sultat est vrai ssi l'insertion a �t� possible, c'est � dire
// que c n'�tait pas d�j� dans l'arbre.
// Le pointeur est l'adresse d'un quelconque objet que l'on souhaite
// associer � la cl�.
{
	if (a)
   {
   	bool	Grandi, Succes ;

   	a = a->Inserer (c,val,Grandi,Succes) ;

      if (Succes)
      {
      	nombreElements++ ;
         return true ;
      }
      else
      	return false ;
   }
   else
   {
   	a = new FeuillesAVL <TypeCleTable> (c,val) ;
      nombreElements++ ;
      return true ;
   }
}


template <class TypeCleTable> bool	TablesEfficaces <TypeCleTable>::Supprimer (const TypeCleTable &c, void *&val)
// Supprime la cl� c si elle figure dans la table. Dans ce cas, le
// r�sultat est vrai et le pointeur restitu� est celui qui �tait
// associ� � la cl�.
{
	if (a)
   {
   	bool	Diminue, Succes ;

   	a = a->Supprimer (c,Diminue,Succes,val) ;

      if (Succes)
      	nombreElements -- ;

      return Succes ;
   }
   else
   {
   	val = NULL ;
   	return false ;
   }
}


template <class TypeCleTable> 
void	TablesEfficaces <TypeCleTable> :: EnTableau (bool OuiPourLesCles, 
																	Tableaux <TypeCleTable> &TC,
																	bool OuiPourLesValeurs,
																	Tableaux <void *> &TP) const
// Initialise le tableau TC avec les cl�s contenues dans le conteneur
// par ordre croissant et TP avec les pointeurs associ�s � chaque cl�.
// TP [i] est le pointeur associ� � la cl� TC [i]
// Le pr�c�dent contenu des tableaux est perdu.
// TC n'est initialis� que si le premier bool�en est vrai, TP que si le 
// deuxi�me l'est.
{
	if (OuiPourLesCles)
	{
		TC.Changer_Nb_Elements (0) ; // vide sans d�sallouer

		if (TC.Nb_Elements () < nombreElements)
   		TC.Changer_Nb_Elements (nombreElements) ;
	}

	if (OuiPourLesValeurs)
	{
		TP.Changer_Nb_Elements (0) ; // vide sans d�sallouer

		if (TP.Nb_Elements () < nombreElements)
   		TP.Changer_Nb_Elements (nombreElements) ;
	}

   if (a)
   	a->RemplirTableau (OuiPourLesCles,TC,OuiPourLesValeurs,TP) ;
}


template <class TypeCleTable> 
int	TablesEfficaces <TypeCleTable> :: NombreElements () const
{
	return nombreElements ;
}


template <class TypeCleTable> 
const TablesEfficaces <TypeCleTable> & TablesEfficaces <TypeCleTable> :: operator = (const TablesEfficaces &o)
// L'affectation ne provoque pas la duplication des valeurs associ�es
// aux cl�s : les pointeurs sont r�-utilis�s tels quels.
{
	if (this != &o)
   {
   	if (o.a)
      	a = (o.a)->Dupliquer () ;
      else
      	a = NULL ;

      nombreElements = o.nombreElements ;
   }

   return *this ;
}


template <class TypeCleTable> bool	TablesEfficaces <TypeCleTable> :: EstValide ()
{
	int	h ;
	if (a==NULL)
   	return true ;
   else
   	return a->EstValide (h) ;
}


template <class TypeCleTable> bool			TablesEfficaces <TypeCleTable> :: EstDans (const TypeCleTable &c, void *&val)
{
	if (a)
   	return a->EstDans (c,val) ;
   else
   {
   	val = NULL ;
   	return false ;
   }
}


template <class TypeCleTable>
void	TablesEfficaces <TypeCleTable>::Min (TypeCleTable &c, void *&val)
{
	if (a)
   	a->Min (c,val) ;
}


template <class TypeCleTable>
void	TablesEfficaces <TypeCleTable>::Max (TypeCleTable &c, void *&val)
{
	if (a)
   	a->Max (c,val) ;
}


template <class TypeCleTable> bool TablesEfficaces <TypeCleTable> :: ModifierValeur( const TypeCleTable& c, void*& val )
	// Modifier la valeur associ�e � la cl� c. Si la cl� est absente, le r�sultat est faux.
	// Sinon le remplacement est effectu�.
	// ATTENTION: l'ancienne valeur n'est pas d�sallou�e. L'appelant doit s'en occuper.
{
	if (a)
   {
      return a->ModifierValeur(c,val) ;
   }
   else
   {
	 return false ;
   }
}

#endif
