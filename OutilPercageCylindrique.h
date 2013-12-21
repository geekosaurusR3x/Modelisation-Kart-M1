/**
 * Classe OutilPercageCylindrique
 * *******************************
 * Outil de forme cylindrique
 * La perceuse peut en utilisant cet outil creuser des trous de forme triangluaire, carré ou cylindrique
 * Voir le constructeur pour modifier cet état
 * Pour les formes rectangulaire, voir OutilPercageRectangulaire
 *
 * Auteurs : SCHEIBEL Jean-Baptiste
 * Créé le : 3 avril 2012
 * Modifié le : 5 avril 2012
 * Version : 1
 */

#pragma once
#include "BibliothequeBRepP.h"
#include "Piece.h"
#include "OutilPercage.h"

class OutilPercageCylindrique : public OutilPercage{

private:

	// Rayon de l'outil
	double _rayon;

	// Hauteur de l'outil
	double _hauteur;

	/**
	 * Permet de construire la topologie de l'outil de percage
	 * sommetsBaseBas : Sommets de la base inférieur de l'outil
	 * sommetsBasHaut : Sommets de la base supérieur de l'outil
	 */
	virtual void buildSommets(Tableaux<SommetsP>& sommetsBaseBas, Tableaux<SommetsP>& sommetsBaseHaut);

public:

	/**
	 * Constructeur de OutilPercageCylindrique
	 * avecBaseHaut : Si la base supérieur doit être débouchante
	 * avecBaseBas : Si la base inférieur doit être débouchante
	 * nombreFacettes : Nombre de facettes de l'outils (3 = triangle, 4 = carré, >4 = cylindre)
	 * rayon : Rayon de l'outil
	 * hauteur : Hauteur de l'outil
	 */
	OutilPercageCylindrique(bool avecBaseHaut, bool avecBaseBas, int nombreFacettes, double rayon, double hauteur);

	/**
	 *  Destructeur de OutilPercageCylindrique
	 */
	virtual ~OutilPercageCylindrique();
};

