//*****************************************************************************
//
// Module	: TypeCle
// 
// Fichier	: TypeCle.h
// 
// Auteur	: Lanuel Y.
// 
// Date creat.	: Tue Feb 18 13:36:34 MET 1997
// 
// Version	:
//
// Commentaires	: Declaration du TypeCle
//
//		VOIR PLUS BAS DES COMMENTAIRES SUR LES ENTREES / SORTIES
//
// 	Le TypeCle est simplement un long double dont la partie d�cimale
//		est nulle. Il y a donc 18 chiffres disponibles pour la partie enti�re.
//
//		Cette derni�re est constitu�e, pour sa partie basse, du nombre de
//		secondes qui se sont �coul�es entre le 1-1-2000 � 0 H 00 et l'instant
//		o� la session en cours demande une premi�re cl�. Cette partie basse est
//		sur 10 chiffres, ce qui suffit pour 68 ans.
//
//		La partie haute est un entier qui cro�t � partir de 1. Imaginons par
//		exemple que la premi�re cl� soit demand�e 120 960 000 secondes apr�s
//		le d�but de 2000. Cette premi�re cl� sera 10 120 960 000, les suivantes
//		20 120 960 000, 30 120 960 000 etc. Ce num�ro qui va croissant peut
//		aller jusque 99 999 999. La plus grande cl� possible de la session
//		est donc 99 999 999 010 120 960 000.
//		Au del� (on a atteint les 18 chiffres), on calcule � nouveau le nb de
//		secondes �coul�es depuis le d�but de 2000	et on change la partie basse
//		en ce nombre. La partie haute recommence � 1.
//		Par exemple, si l'on �puise les 99 999 999 premi�res cl�s au bout de
//		10000 secondes dans une m�me session, la prochaine cl� allou�e sera
//		10 120 970 000.
//
//		Pour que deux cl�s soient �gales, il faut donc que les sessions
//		pendant lesquelles elles ont �t� cr��es aient commenc� � la m�me
//		seconde. C'est suffisamment improbable pour qu'on tol�re le risque.
//		Par ailleurs, lors de la fusion de 2 fichiers, on peut constater
//		cet �tat de chose et y rem�dier.
//
//*****************************************************************************

#ifndef __TypeCle__h__
#define __TypeCle__h__

//#include	"EnteteBRepPDLL.h"
//#include <system.hpp>
#include	<iostream>
using namespace std ;
//#include	<fstream.h>
//#include <string>
using namespace std ;

#define CLEVIDE 0


typedef	long double TypeCle;


// Calcul de la prochaine cl� disponible
// Ca prend en moyenne 7/100 000 000 seconde pour obtenir une cl�.
extern TypeCle		ProchaineCle () ;

// Transformation d'une cl� en cha�ne de caract�res Builder
//void				TypeCleEnChaine (TypeCle c,string &s) ;

// Transformation d'une cl� en cha�ne de caract�res C avec \0 terminal.
// LA CHAINE EST ALLOUEE PAR LA FONCTION MAIS DOIT ETRE LIBEREE
// PAR L'APPELANT !!
void				TypeCleEnChaine (TypeCle c,char *&ch) ;

// Transformation d'une cha�ne de caract�res C avec \0 terminal en cl�.
void				ChaineEnTypeCle (char *ch,TypeCle &c) ;

// Transformation d'une AnsiString en cl�.
//void				ChaineEnTypeCle (string s,TypeCle &c) ;

// ATTENTION : UTILISER EXCLUSIVEMENT CES QUATRE FONCTIONS POUR LA LECTURE
// 				ECRITURE DE CLES !!!
 
// Ecrit/Lit la cl� dans le flux sans passer � la ligne
// Attention � faire suivre la cl� d'un s�parateur si on
// en �crit plusieurs � la file !!
ostream&			operator << (ostream& f, TypeCle cle) ;
istream&			operator >> (istream& f, TypeCle &cle) ;

// Ecrit/Lit la cl� dans le fichier sans passer � la ligne
// Attention � faire suivre la cl� d'un s�parateur si on
// en �crit plusieurs � la file !!
void 				EcrireCleFichier (FILE *f, TypeCle &Cle) ;
void 				LireCleFichier (FILE *f, TypeCle &Cle) ;

// Fonction � appeler en fin d'ex�cution, quand aucune cl� ne sera plus
// demand�e
void TerminerGestionDesCles () ;

#endif __TypeCle__h__
