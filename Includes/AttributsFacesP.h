#pragma once

///////////////////////////////////////////////////////////////////////////////////////////
//
// Cette classe abstraite permet d'ajouter un attribut aux FacesP.
// Mécanisme :
// - les FacesP ont une donnée membre de type (AttributsFacesP *)
// - quand un attribut doit être affecté à une entité, le constructeur de l'entité reçoit un
//	 pointeur sur l'attribut.
// - c'est l'application qui utilise le BRep qui définit la classe "Attribut" (en la
//	 faisant hériter de AttributsFacesP) et qui fournit un pointeur sur un tel
//	 attribut quand c'est utile.
// - de plus, à la mise en route de l'application, il faut appeler la méthode Initialiser
//	 pour que la fonction de lecture d'un attribut dans un fichier Regain ait connaissance
//	 du type réel de l'attribut dérivé.
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
	// Fonction que l'application doit appeler avec l'attribut dérivé de
	// AttributsFacesP qui sert d'attribut par défaut pour les faces et qui indique à
	// Lire le type réel des attributs de faces manipulés dans l'application.
	// L'objet dérivé est dupliqué par la fonction donc il peut être détruit
	// aussitôt après l'appel.

	static void Terminer () ;
	// Fonction que l'application doit appeler quand elle se termine, pour libérer
	// l'attribut de face conservé dans cette unité comme modèle d'attribut.

	static  AttributsFacesP		*Lire (std::istream &F)  ;
	// La fonction pour lire un attribut depuis un fichier
	
	virtual void						Ecrire (std::ostream &) const = 0 ;
	// Ecrit sans passer à la ligne

	static AttributsFacesP * AttributParDefaut () ;
	// Restitue un pointeur sur l'attribut par défaut des faces
};

