//////////////////////////////////////////////////////////////////////////////
//
// FONCTIONNEMENT DE LA CONSOLE
//
// Quand une application utilise les bibliothèques Regain, elle doit définir une classe
// qui hérite de la classe Console et qui rend les services énoncés plus bas (fonctions virtuelles).
//
// Il est alors possible, dans l'appli, de procéder à des affichages avec :
// (*NSConsole::Console) << "Hello " << i << nom ;
//
// La console peut, par exemple, être "cout" dans une application texte ou un "memo"
// dans une application graphique.
//
///////////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
#ifndef ConsolesH
#define ConsolesH
//---------------------------------------------------------------------------

#include "EnteteConsoleDLL.h"

namespace NSConsole {

class CONSOLE_DLL Consoles
{
public:
	// La première console créée (parmi les classes filles) devient la console par défaut.
	// Si d'autres consoles sont créées ensuite et qu'elles doivent devenir la console
	// par défaut, il faut le demander explicitement avec Consoles::InitialiserConsoleGlobale
	Consoles () ;

	virtual ~Consoles () ;

	void	Decalage () ;
	// Decale le curseur vers la droite d'un nombre de tabulations égal au décalage actuel

	void	AugmenterDecalage () ;
	// Augmente la valeur du décalage de un

	void	DiminuerDecalage () ;
	// Réduit la valeur du décalage de un

	// Montrer ou cacher la console. La réalisation de ces fonctions dans les classes filles
	// peut être vide, par exemple si la console est un flux.
	virtual void MontrerConsole () = 0 ;
	virtual void CacherConsole () = 0 ;

public: // ça devrait être "protected" 
	void	InitialiserConsoleGlobale (Consoles *) ;

	// Les classes filles DOIVENT définir ces méthodes.
	// ATTENTION : elles doivent passer à la ligne !
	virtual void	Afficher (const int &) = 0 ;
	virtual void	Afficher (const long int &) = 0 ;
	virtual void	Afficher (const unsigned int &) = 0 ;
	virtual void	Afficher (const unsigned long &) = 0 ;
	virtual void	Afficher (const char &) = 0 ;
	virtual void	Afficher (const char *) = 0 ;
	virtual void	Afficher (const double &) = 0 ;
	virtual void	Afficher (const long double &) = 0 ;
	virtual void	Afficher (const float &) = 0 ;

protected:
	Consoles (const Consoles &) ;

	int				Decal ;

} ;

// La console déclarée ci-dessous est LA console globale. 
// Lorsqu'une classe fille existera, il faudra l'instancier et faire
// pointer Console sur l'instance. Pour cela, passer l'adresse de
// l'instance de la classe fille à la fonction InitialiserConsoleGlobale.

extern CONSOLE_DLL NSConsole::Consoles	*Console ;
}

// Affichage de divers types avec passage à la ligne
NSConsole::Consoles& CONSOLE_DLL operator << (NSConsole::Consoles &s, const int &) ;
NSConsole::Consoles& CONSOLE_DLL operator << (NSConsole::Consoles &s, const long int &) ;
NSConsole::Consoles& CONSOLE_DLL operator << (NSConsole::Consoles &s, const unsigned int &) ;
NSConsole::Consoles& CONSOLE_DLL operator << (NSConsole::Consoles &s, const unsigned long &) ;
NSConsole::Consoles& CONSOLE_DLL operator << (NSConsole::Consoles &s, const char &) ;
NSConsole::Consoles& CONSOLE_DLL operator << (NSConsole::Consoles &s, const char *) ;
NSConsole::Consoles& CONSOLE_DLL operator << (NSConsole::Consoles &s, const double &) ;
NSConsole::Consoles& CONSOLE_DLL operator << (NSConsole::Consoles &s, const long double &) ;
NSConsole::Consoles& CONSOLE_DLL operator << (NSConsole::Consoles &s, const float &) ;

#endif
