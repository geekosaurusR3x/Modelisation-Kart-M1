#pragma once
#include <stdlib.h>		// Pour NULL

/******************************************************
La classe AfficheurErreurs permet d'afficher une erreur sans que la nature de l'application
(console ou graphique) soit connue :
- l'application cr�e une classe qui h�rite de AfficheurErreurs
- cette classe d�finit la m�thode AfficherErreur (un printf, une boite de dialogue ...)
- l'application initialise l'afficheur d'erreur en appelant Initialiser avec l'adresse d'un objet de cette nouvelle classe
*******************************************************/
class AfficheurErreurs
{
public:
	AfficheurErreurs(void) ;
	void Initialiser (AfficheurErreurs *PE) ;
	virtual void AfficherUneErreur (const char *Msg, bool Fatale) ;
	static void AfficherErreur (const char *Msg, bool Fatale) ;

public:
	virtual ~AfficheurErreurs(void) {} ;
};
