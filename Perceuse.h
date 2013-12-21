/**
 * Classe Perceuse
 * ***************
 * La perceuse permet de percer des �videments, d�bouchant ou borgne, dans une pi�ce � l'aide d'outil de percage
 * Elle permet de percer � une position et une face donn�e de la pi�ce.
 * Un rep�re peut �tre param�tr� pour connaitre l'orientation de percage
 * 
 * Recommandation 
 * **************
 * L'outil doit �tre param�tr� en fonction de la m�thode utilis�e par la perceuse
 * Par exemple, elle ne peut pas percer un trou d�bouchant si les 2 bases de l'outils sont visible.
 * Si l'erreur "Contour manquant" de regain se l�ve, il se peut que les faces � percer et d�bouchantes ne soient pas en phase avec les bases de l'outil
 * Il faut alors intervertir les bases � afficher de l'outil
 *   
 * Auteurs : SCHEIBEL Jean-Baptiste
 * Cr�� le : 3 avril 2012
 * Modifi� le : 9 avril 2012
 * Version : 1
 */

#pragma once
#include "OutilPercage.h"

class Perceuse
{
public:

	/**
	 * Permet de percer de fa�on � traverser l'objet � percer
	 * repere: Repere de percage.
	 *		   L'origine du repere doit �tre sur le m�me plan que la face � percer
	 *		   Le vecteur Z du repere doit pointer vers l'objet et non pas vers l'exterieur (inverse de la normale de la face � percer)
	 * solide : Le solide � percer.
	 *			Ses faces seront automatiquement modifi�s
	 * faceDebouchante : La face d�bouchante de l'objet
	 * faceAPercer : La face a percer
	 * outil : L'outil avec lequel il faut percer
	 */
	static void percer(const Repere3D& repere, SolidesP& solide, FacesP& faceDebouchante, FacesP& faceAPercer, OutilPercage* outil) throw(exception);

	/**
	 * Permet de percer de fa�on � traverser l'objet � percer.
	 * Ici, le repere est g�n�r� automatiquement en fonction de la face � percer
	 * solide : Le solide � percer.
	 *			Ses faces seront automatiquement modifi�s
	 * faceDebouchante : La face d�bouchante de l'objet
	 * faceAPercer : La face a percer
	 * outil : L'outil avec lequel il faut percer
	 */
	static void percer(const Points3D& position, SolidesP& solide, FacesP& faceDebouchante, FacesP& faceAPercer, OutilPercage* outil) throw(exception);
	
	/**
	 * Permet de percer sur une face. L'outil de percage ne doit pas traverser le solide
	 * repere: Repere de percage.
	 *		   L'origine du repere doit �tre sur le m�me plan que la face � percer
	 *		   Le vecteur Z du repere doit pointer vers l'objet et non pas vers l'exterieur (inverse de la normale de la face � percer)
	 * solide : Le solide � percer.
	 *			Ses faces seront automatiquement modifi�s
	 * faceAPercer : La face a percer
	 * outil : L'outil avec lequel il faut percer
	 *		   L'outil doit �tre param�trer en fonction de la base d�bouchante.
	 * 		   Seulement une face d�bouchante doit �tre param�tr�e.
	 */
	static void percer(const Repere3D& repere, SolidesP& solide, FacesP& faceAPercer, OutilPercage* outil) throw(exception);

	/**
	 * Permet de percer sur une face. L'outil de percage ne doit pas traverser le solide
	 * Ici, le repere est g�n�r� automatiquement en fonction de la face � percer
	 * repere: Repere de percage.
	 *		   L'origine du repere doit �tre sur le m�me plan que la face � percer
	 *		   Le vecteur Z du repere doit pointer vers l'objet et non pas vers l'exterieur (inverse de la normale de la face � percer)
	 * solide : Le solide � percer.
	 *			Ses faces seront automatiquement modifi�s
	 * faceAPercer : La face a percer
	 * outil : L'outil avec lequel il faut percer
	 *		   Remarque : L'outil doit �tre param�trer en fonction de la base d�bouchante.
	 * 		   Seulement une base d�bouchante doit �tre param�trer. 
	 * 		   Si 2 faces sont d�bouchantes, la m�thode en choisira une arbitrairement
	 */
	static void percer(const Points3D& position, SolidesP& solide, FacesP& faceAPercer, OutilPercage* outil) throw(exception);

	/**
	 * Permet de r�cup�rer le repere 3D en fonction de la face � percer
	 * Le repere Z pointe dans la piece � perser, les 2 autres sont dans le m�me plan que cette face
	 * position : La position du point de percage
	 * faceAPercer : La face � percer
	 * Retourne le repere de percage
	 */
	static Repere3D getRepereDePercageDepuisFace(const Points3D& position, FacesP& faceAPercer);
};

