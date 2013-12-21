#pragma once

///////////////////////////////////////////////////////////////////////////////////////////
//
// Cette classe abstraite permet d'ajouter un attribut aux SolidesP.
// M�canisme :
// - un SolidesP a une donn�e membre de type (AttributsSolidesP *)
// - le constructeur de SolidesP re�oit un pointeur sur l'attribut.
// - c'est l'application qui utilise le BRep qui d�finit la classe "Attribut" (en la
//	 faisant h�riter de AttributsSolidesP) et qui fournit un pointeur sur un tel
//	 attribut quand c'est utile.
// - de plus, � la mise en route de l'application, il faut appeler la m�thode Initialiser
//	 pour que la fonction de lecture d'un attribut de solide dans un fichier Regain ait connaissance
//	 du type r�el de l'attribut d�riv�.
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include	"EnteteBRepPDLL.h"


class AttributsSolidesP
{
public:
	AttributsSolidesP(void);
	AttributsSolidesP (const AttributsSolidesP &) ;

	virtual								~AttributsSolidesP(void);
	
	virtual AttributsSolidesP		* Dupliquer () const = 0 ;
	
	virtual AttributsSolidesP		*LireV (std::istream &) = 0 ;

	static void InitialiserAttributParDefaut (AttributsSolidesP *PA) ;
	// Fonction que l'application doit appeler avec l'attribut d�riv� de
	// AttributsSolidesP qui sert d'attribut par d�faut pour les solides et qui indique �
	// Lire le type r�el des attributs de solides manipul�s dans l'application.
	// L'objet d�riv� est dupliqu� par la fonction donc il peut �tre d�truit
	// aussit�t apr�s l'appel.


	static void Terminer () ;
	// Fonction que l'application doit appeler quand elle se termine, pour lib�rer
	// l'attribut de solide conserv� dans cette unit� comme mod�le d'attribut.

	static  AttributsSolidesP		*Lire (std::istream &F)  ;
	// La fonction pour lire un attribut depuis un fichier
	
	virtual void						Ecrire (std::ostream &) const = 0 ;
	// Ecrit sans passer � la ligne

	static AttributsSolidesP * AttributParDefaut () ;
	// Restitue un pointeur sur l'attribut par d�faut des solides
};

