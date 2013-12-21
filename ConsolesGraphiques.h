#pragma once

//////////////////////////////////////////////////////////////
//
// classe pour la réalisation d'une console Regain dans une
// application windows forms en C++/CLI
//
//////////////////////////////////////////////////////////////

#include "consoles.h"
#include <vcclr.h>		// Pour gcroot
#include "Form1.h"

//////////////////////////////////////////////////////////////
//
// La réalisation de la Console Graphique est insatisfaisante,
// en partie à cause de la difficulté de faire cohabiter des
// objets managés et des objets non managés :
// -	un textbox multilignes est placé dans l'interface et rendu invisible.
// -	la classe ConsolesGraphiques a une donnée membre (reçue par le constructeur) qui est 
//		une référence à l'interface. Cette donnée membre est déclarée comme suit :
//			gcroot<ApplicationRegainDeBase::Form1 ^>	mInterface ; // ==> #include <vcclr.h>
// -	les fonctions virtuelles d'affichage de la console graphique transforment le paramètre 
//		à afficher en une chaîne et l'affichent grâce à une fonction d'affichage d'une chaîne
//		dans le textbox, fournie par l'interface.
//
//////////////////////////////////////////////////////////////

class ConsolesGraphiques :
	public NSConsole::Consoles
{
public:
	ConsolesGraphiques(ApplicationRegainDeBase::Form1 ^);
	~ConsolesGraphiques(void);

	// Montrer ou cacher la console. 
	virtual void MontrerConsole () ;
	virtual void CacherConsole () ;

	// ATTENTION : ces fonctions doivent passer à la ligne !
	virtual void	Afficher (const int &) ;
	virtual void	Afficher (const long int &) ;
	virtual void	Afficher (const unsigned int &) ;
	virtual void	Afficher (const unsigned long &) ;
	virtual void	Afficher (const char &) ;
	virtual void	Afficher (const char *) ;
	virtual void	Afficher (const double &) ;
	virtual void	Afficher (const long double &) ;
	virtual void	Afficher (const float &) ;

private :
	gcroot<ApplicationRegainDeBase::Form1 ^>	mInterface ;
};

