#pragma once

//////////////////////////////////////////////////////////////
//
// classe pour la r�alisation d'une console Regain dans une
// application windows forms en C++/CLI
//
//////////////////////////////////////////////////////////////

#include "consoles.h"
#include <vcclr.h>		// Pour gcroot
#include "Form1.h"

//////////////////////////////////////////////////////////////
//
// La r�alisation de la Console Graphique est insatisfaisante,
// en partie � cause de la difficult� de faire cohabiter des
// objets manag�s et des objets non manag�s :
// -	un textbox multilignes est plac� dans l'interface et rendu invisible.
// -	la classe ConsolesGraphiques a une donn�e membre (re�ue par le constructeur) qui est 
//		une r�f�rence � l'interface. Cette donn�e membre est d�clar�e comme suit :
//			gcroot<ApplicationRegainDeBase::Form1 ^>	mInterface ; // ==> #include <vcclr.h>
// -	les fonctions virtuelles d'affichage de la console graphique transforment le param�tre 
//		� afficher en une cha�ne et l'affichent gr�ce � une fonction d'affichage d'une cha�ne
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

	// ATTENTION : ces fonctions doivent passer � la ligne !
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

