/**
 * Classe Piece
 * ************
 * La classe piece est la classe parente de toutes les pièces qui peuvent être modélisées.
 * C'est une amélioration de la classe SolidesP de Regain.
 * Elle contient un Repere 3D local à l'objet permettant de le situer dans l'espace et de connaître son orientation
 * Elle permet d'executer plusieurs action : Rotation sur un axe local de l'objet, deplacement dans l'espace, transposer sur un nouveau repere de l'espace
 *
 * Recommandation: 
 * ***************
 * Il est très important de n'utiliser que les méthodes de transformation, translation, rotation de la classe pièce et non pas les primitives de la bibliothèque Regain!
 * En cas d'utilisation d'une méthode non recommandée, les données de la pièce risque de ne plus être cohérent.
 * Il est donc essentiel de faire appel à l'équipe modélisation en cas de possible méthode manquante!
 *
 * Auteur :		SCHEIBEL Jean-Baptiste
 * Créé le :	4 avril 2012
 * Modifié le : 9 avril 2012
 * Version :	1
 */
#pragma once
#include "BibliothequeBRepP.h"
#include "BibliothequeMathematique.h"
#include "AttributsFacesP.h"
#include "Repere3D.h"

class Piece : public SolidesP
{
protected:
	// Repere 3D local de l'objet
	Repere3D _repere;

	// Attributs des faces qui leurs seront appliqués
	AttributsFacesP *_attributFace;

	/**
	 * Permet de construire une pièce
	 * Méthode à implémenter pour chaque pièce héritant de cette classe
	 */
	virtual void buildAll() = 0;

	/**
	 * Permet de construire une face à partir d'un tableau de sommets
	 * Les sommets dans le tableau doivent être ordonnées dans le sens de construction
	 * Retourne la face construite
	 */
	FacesP ConstuireFacesDepuisSommets(Tableaux<SommetsP> sommets);


public:

	virtual Repere3D getRepere3D()const;

	/**
	 * Constructeur de Piece
	 * repere : Repere local de la piece
	 * attributFace : Attribut des faces
	 */
	Piece(const Repere3D& repere, AttributsFacesP* attributFace);

	/**
	 * Destructeur de Piece
	 */
	virtual ~Piece();
	
	/**
	 * Permet d'executer une rotation de sur teta l'axe local X de l'objet
	 * teta : Angle de rotation. Doit être exprimé en radian
	 */
	virtual void rotationSurX(double teta);

	/**
	 * Permet d'executer une rotation de sur teta l'axe local Y de l'objet
	 * teta : Angle de rotation. Doit être exprimé en radian
	 */
	virtual void rotationSurY(double teta);

	/**
	 * Permet d'executer une rotation de sur teta l'axe local Z de l'objet
	 * teta : Angle de rotation. Doit être exprimé en radian
	 */
	virtual void rotationSurZ(double teta);

	/**
	 * Permet de déplacer le repere local vers une nouvelle position.
	 * Seul la position du repere change. l'orientation du repere reste la même!
	 * nouvellePosition : Nouvelle position du repere local dans l'espace
	 */
	void deplacerVers(const Points3D& nouvellePosition);

	/**
	 * Permet de transposer le repere local vers un nouveau repere de l'espace
	 * Modifie la position du repere et son orientation avec les données du nouveau repere
	 * repere : Nouveau repere local de la piece
	 */
	void transposerVers(Repere3D repere);
	

};