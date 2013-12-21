#pragma once

///////////////////////////////////////////////////////////////////////////////////////////
//
// Cette classe abstraite permet d'ajouter un attribut aux FacesP.
// M�canisme :
// - les FacesP ont une donn�e membre de type (AttributsFacesP *)
// - quand un attribut doit �tre affect� � une entit�, le constructeur de l'entit� re�oit un
//	 pointeur sur l'attribut.
// - c'est l'application qui utilise le BRep qui d�finit la classe "Attribut" (en la
//	 faisant h�riter de AttributsFacesP) et qui fournit un pointeur sur un tel
//	 attribut quand c'est utile.
// - de plus, � la mise en route de l'application, il faut appeler la m�thode Initialiser
//	 pour que la fonction de lecture d'un attribut dans un fichier Regain ait connaissance
//	 du type r�el de l'attribut d�riv�.
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include	"EnteteBRepPDLL.h"


class AttributsFacesP
{
public:
	AttributsFacesP(void);
	AttributsFacesP (const AttributsFacesP &) ;

	virtual								~AttributsFacesP(void);
	
	virtual AttributsFacesP		* Dupliquer () const = 0 ;
	
	virtual AttributsFacesP		*LireV (std::istream &) = 0 ;

	static void InitialiserAttributParDefaut (AttributsFacesP *PA) ;
	// Fonction que l'application doit appeler avec l'attribut d�riv� de
	// AttributsFacesP qui sert d'attribut par d�faut pour les faces et qui indique �
	// Lire le type r�el des attributs de faces manipul�s dans l'application.
	// L'objet d�riv� est dupliqu� par la fonction donc il peut �tre d�truit
	// aussit�t apr�s l'appel.

	static void Terminer () ;
	// Fonction que l'application doit appeler quand elle se termine, pour lib�rer
	// l'attribut de face conserv� dans cette unit� comme mod�le d'attribut.

	static  AttributsFacesP		*Lire (std::istream &F)  ;
	// La fonction pour lire un attribut depuis un fichier
	
	virtual void						Ecrire (std::ostream &) const = 0 ;
	// Ecrit sans passer � la ligne

	static AttributsFacesP * AttributParDefaut () ;
	// Restitue un pointeur sur l'attribut par d�faut des faces
};

