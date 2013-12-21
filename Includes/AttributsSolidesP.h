#pragma once

///////////////////////////////////////////////////////////////////////////////////////////
//
// Cette classe abstraite permet d'ajouter un attribut aux SolidesP.
// Mécanisme :
// - un SolidesP a une donnée membre de type (AttributsSolidesP *)
// - le constructeur de SolidesP reçoit un pointeur sur l'attribut.
// - c'est l'application qui utilise le BRep qui définit la classe "Attribut" (en la
//	 faisant hériter de AttributsSolidesP) et qui fournit un pointeur sur un tel
//	 attribut quand c'est utile.
// - de plus, à la mise en route de l'application, il faut appeler la méthode Initialiser
//	 pour que la fonction de lecture d'un attribut de solide dans un fichier Regain ait connaissance
//	 du type réel de l'attribut dérivé.
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
	// Fonction que l'application doit appeler avec l'attribut dérivé de
	// AttributsSolidesP qui sert d'attribut par défaut pour les solides et qui indique à
	// Lire le type réel des attributs de solides manipulés dans l'application.
	// L'objet dérivé est dupliqué par la fonction donc il peut être détruit
	// aussitôt après l'appel.


	static void Terminer () ;
	// Fonction que l'application doit appeler quand elle se termine, pour libérer
	// l'attribut de solide conservé dans cette unité comme modèle d'attribut.

	static  AttributsSolidesP		*Lire (std::istream &F)  ;
	// La fonction pour lire un attribut depuis un fichier
	
	virtual void						Ecrire (std::ostream &) const = 0 ;
	// Ecrit sans passer à la ligne

	static AttributsSolidesP * AttributParDefaut () ;
	// Restitue un pointeur sur l'attribut par défaut des solides
};

