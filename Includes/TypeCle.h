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
// 	Le TypeCle est simplement un long double dont la partie décimale
//		est nulle. Il y a donc 18 chiffres disponibles pour la partie entière.
//
//		Cette dernière est constituée, pour sa partie basse, du nombre de
//		secondes qui se sont écoulées entre le 1-1-2000 à 0 H 00 et l'instant
//		où la session en cours demande une première clé. Cette partie basse est
//		sur 10 chiffres, ce qui suffit pour 68 ans.
//
//		La partie haute est un entier qui croît à partir de 1. Imaginons par
//		exemple que la première clé soit demandée 120 960 000 secondes après
//		le début de 2000. Cette première clé sera 10 120 960 000, les suivantes
//		20 120 960 000, 30 120 960 000 etc. Ce numéro qui va croissant peut
//		aller jusque 99 999 999. La plus grande clé possible de la session
//		est donc 99 999 999 010 120 960 000.
//		Au delà (on a atteint les 18 chiffres), on calcule à nouveau le nb de
//		secondes écoulées depuis le début de 2000	et on change la partie basse
//		en ce nombre. La partie haute recommence à 1.
//		Par exemple, si l'on épuise les 99 999 999 premières clés au bout de
//		10000 secondes dans une même session, la prochaine clé allouée sera
//		10 120 970 000.
//
//		Pour que deux clés soient égales, il faut donc que les sessions
//		pendant lesquelles elles ont été créées aient commencé à la même
//		seconde. C'est suffisamment improbable pour qu'on tolère le risque.
//		Par ailleurs, lors de la fusion de 2 fichiers, on peut constater
//		cet état de chose et y remédier.
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


// Calcul de la prochaine clé disponible
// Ca prend en moyenne 7/100 000 000 seconde pour obtenir une clé.
extern TypeCle		ProchaineCle () ;

// Transformation d'une clé en chaîne de caractères Builder
//void				TypeCleEnChaine (TypeCle c,string &s) ;

// Transformation d'une clé en chaîne de caractères C avec \0 terminal.
// LA CHAINE EST ALLOUEE PAR LA FONCTION MAIS DOIT ETRE LIBEREE
// PAR L'APPELANT !!
void				TypeCleEnChaine (TypeCle c,char *&ch) ;

// Transformation d'une chaîne de caractères C avec \0 terminal en clé.
void				ChaineEnTypeCle (char *ch,TypeCle &c) ;

// Transformation d'une AnsiString en clé.
//void				ChaineEnTypeCle (string s,TypeCle &c) ;

// ATTENTION : UTILISER EXCLUSIVEMENT CES QUATRE FONCTIONS POUR LA LECTURE
// 				ECRITURE DE CLES !!!
 
// Ecrit/Lit la clé dans le flux sans passer à la ligne
// Attention à faire suivre la clé d'un séparateur si on
// en écrit plusieurs à la file !!
ostream&			operator << (ostream& f, TypeCle cle) ;
istream&			operator >> (istream& f, TypeCle &cle) ;

// Ecrit/Lit la clé dans le fichier sans passer à la ligne
// Attention à faire suivre la clé d'un séparateur si on
// en écrit plusieurs à la file !!
void 				EcrireCleFichier (FILE *f, TypeCle &Cle) ;
void 				LireCleFichier (FILE *f, TypeCle &Cle) ;

// Fonction à appeler en fin d'exécution, quand aucune clé ne sera plus
// demandée
void TerminerGestionDesCles () ;

#endif __TypeCle__h__
