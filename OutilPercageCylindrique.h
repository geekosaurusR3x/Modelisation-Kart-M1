/**
 * Classe OutilPercageCylindrique
 * *******************************
 * Outil de forme cylindrique
 * La perceuse peut en utilisant cet outil creuser des trous de forme triangluaire, carr� ou cylindrique
 * Voir le constructeur pour modifier cet �tat
 * Pour les formes rectangulaire, voir OutilPercageRectangulaire
 *
 * Auteurs : SCHEIBEL Jean-Baptiste
 * Cr�� le : 3 avril 2012
 * Modifi� le : 5 avril 2012
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
	 * sommetsBaseBas : Sommets de la base inf�rieur de l'outil
	 * sommetsBasHaut : Sommets de la base sup�rieur de l'outil
	 */
	virtual void buildSommets(Tableaux<SommetsP>& sommetsBaseBas, Tableaux<SommetsP>& sommetsBaseHaut);

public:

	/**
	 * Constructeur de OutilPercageCylindrique
	 * avecBaseHaut : Si la base sup�rieur doit �tre d�bouchante
	 * avecBaseBas : Si la base inf�rieur doit �tre d�bouchante
	 * nombreFacettes : Nombre de facettes de l'outils (3 = triangle, 4 = carr�, >4 = cylindre)
	 * rayon : Rayon de l'outil
	 * hauteur : Hauteur de l'outil
	 */
	OutilPercageCylindrique(bool avecBaseHaut, bool avecBaseBas, int nombreFacettes, double rayon, double hauteur);

	/**
	 *  Destructeur de OutilPercageCylindrique
	 */
	virtual ~OutilPercageCylindrique();
};

