#include "StdAfx.h"
#include "ConsolesGraphiques.h"
#include <stdio.h>	// Pour sprintf
#include <string.h>	// Pour strcpy ...


ConsolesGraphiques::ConsolesGraphiques(ApplicationRegainDeBase::Form1 ^IP)
	: NSConsole::Consoles ()
	, mInterface (IP)
{
}

ConsolesGraphiques::~ConsolesGraphiques(void)
{
}

// Montrer ou cacher la console.
void ConsolesGraphiques::MontrerConsole ()
{
	mInterface->MontrerLaConsoleGraphique () ;
}

void ConsolesGraphiques::CacherConsole ()
{
	mInterface->CacherLaConsoleGraphique () ;
}

// ATTENTION : ces fonctions doivent passer à la ligne !
void	ConsolesGraphiques::Afficher (const int &d)
{
	char Tab [20] ;
	sprintf (Tab,"%d\n",d) ;
	mInterface->AjouterUneLigneALaConsoleGraphique (Tab) ;
}

void	ConsolesGraphiques::Afficher (const long int &d)
{
	char Tab [20] ;
	sprintf (Tab,"%ld\n",d) ;
	mInterface->AjouterUneLigneALaConsoleGraphique (Tab) ;
}

void	ConsolesGraphiques::Afficher (const unsigned int &d)
{
	char Tab [20] ;
	sprintf (Tab,"%u\n",d) ;
	mInterface->AjouterUneLigneALaConsoleGraphique (Tab) ;
}

void	ConsolesGraphiques::Afficher (const unsigned long &d)
{
	char Tab [20] ;
	sprintf (Tab,"%lu\n",d) ;
	mInterface->AjouterUneLigneALaConsoleGraphique (Tab) ;
}

void	ConsolesGraphiques::Afficher (const char &c)
{
	char Tab [20] ;
	Tab [0] = c ; Tab [1] = '\n' ; Tab [2] = '\0' ;
	mInterface->AjouterUneLigneALaConsoleGraphique (Tab) ;
}

void	ConsolesGraphiques::Afficher (const char *Msg)
{
	char *Tab = new char [strlen (Msg)+2] ;
	strcpy (Tab,Msg) ;
	int	L = strlen (Msg) ;
	Tab [L] = '\n' ;
	Tab [L+1] = '\0' ;
	mInterface->AjouterUneLigneALaConsoleGraphique (Tab) ;

	delete [] Tab ;
}

void	ConsolesGraphiques::Afficher (const double &d)
{
	char Tab [20] ;
	sprintf (Tab,"%1.8lf\n",d) ;
	mInterface->AjouterUneLigneALaConsoleGraphique (Tab) ;
}

void	ConsolesGraphiques::Afficher (const long double &d)
{
	char Tab [40] ;
	sprintf (Tab,"%18.8Lf\n",d) ;
	mInterface->AjouterUneLigneALaConsoleGraphique (Tab) ;
}

void	ConsolesGraphiques::Afficher (const float &d)
{
	char Tab [20] ;
	sprintf (Tab,"%1.8f\n",d) ;
	mInterface->AjouterUneLigneALaConsoleGraphique (Tab) ;
}

