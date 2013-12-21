//---------------------------------------------------------------------------
#ifndef DebugBRepPH
#define DebugBRepPH
//---------------------------------------------------------------------------

#include "EnteteBRepPDLL.h"		// pour BREP_DLL
#include <iostream>
using namespace std ;				// pour ostream
#include "TypeCle.h"
#include "ExceptionRegain.h"


// affichages pour le debug
void BREPP_DLL DebugTabul (int n, ostream &  f, bool SurFichier, bool SurConsole) ;
void BREPP_DLL DebugEntier (int n, ostream &  f, bool SurFichier, bool SurConsole) ;
void BREPP_DLL DebugCle (TypeCle c, ostream &  f, bool SurFichier, bool SurConsole) ;
void BREPP_DLL DebugReel (double n, ostream &  f, bool SurFichier, bool SurConsole) ;
void BREPP_DLL DebugChaine (char *ch, ostream &  f, bool SurFichier, bool SurConsole) ;
void BREPP_DLL DebugCaractere (char c, ostream &  f, bool SurFichier, bool SurConsole) ;
void BREPP_DLL DebugNL (ostream &  f, bool SurFichier, bool SurConsole) ;

// Fonction � adapter au compilateur : elle affiche un message d'erreur qui
// ne peut �tre manqu� par l'op�rateur et fait planter le programme si le
// bool�en est vrai.
// Le message n'est pas affich� que s'il y a eu une demande explicite de ne
// pas afficher les messages ET si le prgm ne va pas planter
void ErreurModele (char *msg, bool FautArreter=true) ;


#endif
 