/**
 * Classe OutilPercage
 * *******************
 * L'outil est utilisé par la perceuse pour percer des pièces
 * L'outil est le patron exact du trous formé dans la pièce par la perceuse
 * Par défaut, le trous dans la pièce réalisé par l'outil est non débouchant
 * Il faudra préalablement modifier l'état d'affichage des faces débouchantes avant le percage
 * En cas de percage sur 2 faces avec la perceuse, il n'est pas necessaire de modifier cet état car les 2 faces doivent déboucher
 * Dans le cas contraire, la perceuse a besoin de connaitre quel face doit être débouchante
 *
 * Auteurs : SCHEIBEL Jean-Baptiste
 * Créé le : 3 avril 2012
 * Modifié le : 4 avril 2012
 * Version : 1
 */

#pragma once
#include "BibliothequeBRepP.h"
#include "Piece.h"

class OutilPercage : public Piece{

protected:

	// Nombre de facettes de l'outil
	int _nombreFacettes;

	// Permet de savoir quel base de l'outil est débouchante
	// Par défaut, les bases ne sont pas débouchante
	bool _avecBaseHaut, _avecBaseBas;

	virtual void buildSommets(Tableaux<SommetsP>& sommetsBaseBas, Tableaux<SommetsP>& sommetsBaseHaut) = 0;

public:

	/**
	 * Constructeur de OutilPercage
	 * avecBaseHaut : Si la base supérieur doit être débouchante
	 * avecBaseBas : Si la base inférieur doit être débouchante
	 */
	OutilPercage(bool avecBaseHaut, bool avecBaseBas, int nombreFacettes);

	/**
	 *  Destructeur de OutilPercage
	 */
	virtual ~OutilPercage();


	/**
	 * Permet de construire physiquement l'outil
	 */
	virtual void buildAll();

	/**
	 * Permet de retourner le contour de percage
	 * Le contour de percage est le contour de l'outil par défaut utilisé
	 * Si la base inférieur est affiché, alors le contour de percage sera le contour exterieur (inverment pour la base supérieur)
	 * Remarque : L'outil doit avoir été forcément construit en mode inversé
	 */
	const ContoursP getContourDePercage();

	/**
	 * Permet de retourner le contour de base supérieur
	 * Remarque : même si la face supérieur n'est pas affiché, le contour a été généré
	 */
	ContoursP getContourBaseHaut();

	/**
	 * Permet de retourner le contour de base inférieur
	 * Remarque : même si la face inférieur n'est pas affiché, le contour a été généré
	 */
	ContoursP getContourBaseBas();

	/**
	 * Permet se savoir si la base inférieur est débouchante (Retourne faux dans ce cas)
	 */
	bool avecBaseBas() const;

	/**
	 * Permet se savoir si la base supérieur est débouchante (Retourne vrai dans ce cas)
	 */
	bool avecBaseHaut() const;

	/**
	 * Permet de récupérer les face de l'outil en fonction des bases à afficher
	 * Retourne les faces paramétrés de l'outil
	 */
	Tableaux<FacesP> faceOutils();
	
};

