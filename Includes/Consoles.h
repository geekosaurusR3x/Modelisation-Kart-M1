//////////////////////////////////////////////////////////////////////////////
//
// FONCTIONNEMENT DE LA CONSOLE
//
// Quand une application utilise les biblioth�ques Regain, elle doit d�finir une classe
// qui h�rite de la classe Console et qui rend les services �nonc�s plus bas (fonctions virtuelles).
//
// Il est alors possible, dans l'appli, de proc�der � des affichages avec :
// (*NSConsole::Console) << "Hello " << i << nom ;
//
// La console peut, par exemple, �tre "cout" dans une application texte ou un "memo"
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
	// La premi�re console cr��e (parmi les classes filles) devient la console par d�faut.
	// Si d'autres consoles sont cr��es ensuite et qu'elles doivent devenir la console
	// par d�faut, il faut le demander explicitement avec Consoles::InitialiserConsoleGlobale
	Consoles () ;

	virtual ~Consoles () ;

	void	Decalage () ;
	// Decale le curseur vers la droite d'un nombre de tabulations �gal au d�calage actuel

	void	AugmenterDecalage () ;
	// Augmente la valeur du d�calage de un

	void	DiminuerDecalage () ;
	// R�duit la valeur du d�calage de un

	// Montrer ou cacher la console. La r�alisation de ces fonctions dans les classes filles
	// peut �tre vide, par exemple si la console est un flux.
	virtual void MontrerConsole () = 0 ;
	virtual void CacherConsole () = 0 ;

public: // �a devrait �tre "protected" 
	void	InitialiserConsoleGlobale (Consoles *) ;

	// Les classes filles DOIVENT d�finir ces m�thodes.
	// ATTENTION : elles doivent passer � la ligne !
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

// La console d�clar�e ci-dessous est LA console globale. 
// Lorsqu'une classe fille existera, il faudra l'instancier et faire
// pointer Console sur l'instance. Pour cela, passer l'adresse de
// l'instance de la classe fille � la fonction InitialiserConsoleGlobale.

extern CONSOLE_DLL NSConsole::Consoles	*Console ;
}

// Affichage de divers types avec passage � la ligne
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
