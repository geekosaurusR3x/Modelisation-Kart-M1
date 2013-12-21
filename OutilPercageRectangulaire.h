/**
 * Classe OutilPercageRectangulaire
 * ********************************
 * Outil de forme rectangulaire
 * La perceuse peut en utilisant cet outil creuser des trous de forme rectangulaire
 *
 * Auteurs : SCHEIBEL Jean-Baptiste
 * Créé le : 4 avril 2012
 * Modifié le : 5 avril 2012
 * Version : 1
 */

#pragma once
#include "BibliothequeBRepP.h"
#include "Piece.h"
#include "OutilPercage.h"

class OutilPercageRectangulaire : public OutilPercage{

private:

	// Largeur du rectangle
	double _largeur;

	// Longueur du rectangle
	double _longueur;

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
	 * Constructeur de OutilPercageRectangulaire
	 * avecBaseHaut : Si la base supérieur doit être débouchante
	 * avecBaseBas : Si la base inférieur doit être débouchante
	 * largeur : largeur de l'outil
	 * longueur : longueur de l'outil
	 * hauteur : Hauteur de l'outil
	 */
	OutilPercageRectangulaire(bool avecBaseHaut, bool avecBaseBas, double largeur, double longueur,double hauteur);

	/**
	 *  Destructeur de OutilPercageRectangulaire
	 */
	virtual ~OutilPercageRectangulaire();
};

