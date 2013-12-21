/**
 * Classe Perceuse
 * ***************
 * La perceuse permet de percer des évidements, débouchant ou borgne, dans une pièce à l'aide d'outil de percage
 * Elle permet de percer à une position et une face donnée de la pièce.
 * Un repère peut être paramétré pour connaitre l'orientation de percage
 * 
 * Recommandation 
 * **************
 * L'outil doit être paramétré en fonction de la méthode utilisée par la perceuse
 * Par exemple, elle ne peut pas percer un trou débouchant si les 2 bases de l'outils sont visible.
 * Si l'erreur "Contour manquant" de regain se lève, il se peut que les faces à percer et débouchantes ne soient pas en phase avec les bases de l'outil
 * Il faut alors intervertir les bases à afficher de l'outil
 *   
 * Auteurs : SCHEIBEL Jean-Baptiste
 * Créé le : 3 avril 2012
 * Modifié le : 9 avril 2012
 * Version : 1
 */

#pragma once
#include "OutilPercage.h"

class Perceuse
{
public:

	/**
	 * Permet de percer de façon à traverser l'objet à percer
	 * repere: Repere de percage.
	 *		   L'origine du repere doit être sur le même plan que la face à percer
	 *		   Le vecteur Z du repere doit pointer vers l'objet et non pas vers l'exterieur (inverse de la normale de la face à percer)
	 * solide : Le solide à percer.
	 *			Ses faces seront automatiquement modifiés
	 * faceDebouchante : La face débouchante de l'objet
	 * faceAPercer : La face a percer
	 * outil : L'outil avec lequel il faut percer
	 */
	static void percer(const Repere3D& repere, SolidesP& solide, FacesP& faceDebouchante, FacesP& faceAPercer, OutilPercage* outil) throw(exception);

	/**
	 * Permet de percer de façon à traverser l'objet à percer.
	 * Ici, le repere est généré automatiquement en fonction de la face à percer
	 * solide : Le solide à percer.
	 *			Ses faces seront automatiquement modifiés
	 * faceDebouchante : La face débouchante de l'objet
	 * faceAPercer : La face a percer
	 * outil : L'outil avec lequel il faut percer
	 */
	static void percer(const Points3D& position, SolidesP& solide, FacesP& faceDebouchante, FacesP& faceAPercer, OutilPercage* outil) throw(exception);
	
	/**
	 * Permet de percer sur une face. L'outil de percage ne doit pas traverser le solide
	 * repere: Repere de percage.
	 *		   L'origine du repere doit être sur le même plan que la face à percer
	 *		   Le vecteur Z du repere doit pointer vers l'objet et non pas vers l'exterieur (inverse de la normale de la face à percer)
	 * solide : Le solide à percer.
	 *			Ses faces seront automatiquement modifiés
	 * faceAPercer : La face a percer
	 * outil : L'outil avec lequel il faut percer
	 *		   L'outil doit être paramétrer en fonction de la base débouchante.
	 * 		   Seulement une face débouchante doit être paramétrée.
	 */
	static void percer(const Repere3D& repere, SolidesP& solide, FacesP& faceAPercer, OutilPercage* outil) throw(exception);

	/**
	 * Permet de percer sur une face. L'outil de percage ne doit pas traverser le solide
	 * Ici, le repere est généré automatiquement en fonction de la face à percer
	 * repere: Repere de percage.
	 *		   L'origine du repere doit être sur le même plan que la face à percer
	 *		   Le vecteur Z du repere doit pointer vers l'objet et non pas vers l'exterieur (inverse de la normale de la face à percer)
	 * solide : Le solide à percer.
	 *			Ses faces seront automatiquement modifiés
	 * faceAPercer : La face a percer
	 * outil : L'outil avec lequel il faut percer
	 *		   Remarque : L'outil doit être paramétrer en fonction de la base débouchante.
	 * 		   Seulement une base débouchante doit être paramétrer. 
	 * 		   Si 2 faces sont débouchantes, la méthode en choisira une arbitrairement
	 */
	static void percer(const Points3D& position, SolidesP& solide, FacesP& faceAPercer, OutilPercage* outil) throw(exception);

	/**
	 * Permet de récupérer le repere 3D en fonction de la face à percer
	 * Le repere Z pointe dans la piece à perser, les 2 autres sont dans le même plan que cette face
	 * position : La position du point de percage
	 * faceAPercer : La face à percer
	 * Retourne le repere de percage
	 */
	static Repere3D getRepereDePercageDepuisFace(const Points3D& position, FacesP& faceAPercer);
};

