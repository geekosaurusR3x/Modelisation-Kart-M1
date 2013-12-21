/**
 * Classe OutilPercage
 * *******************
 * L'outil est utilis� par la perceuse pour percer des pi�ces
 * L'outil est le patron exact du trous form� dans la pi�ce par la perceuse
 * Par d�faut, le trous dans la pi�ce r�alis� par l'outil est non d�bouchant
 * Il faudra pr�alablement modifier l'�tat d'affichage des faces d�bouchantes avant le percage
 * En cas de percage sur 2 faces avec la perceuse, il n'est pas necessaire de modifier cet �tat car les 2 faces doivent d�boucher
 * Dans le cas contraire, la perceuse a besoin de connaitre quel face doit �tre d�bouchante
 *
 * Auteurs : SCHEIBEL Jean-Baptiste
 * Cr�� le : 3 avril 2012
 * Modifi� le : 4 avril 2012
 * Version : 1
 */

#pragma once
#include "BibliothequeBRepP.h"
#include "Piece.h"

class OutilPercage : public Piece{

protected:

	// Nombre de facettes de l'outil
	int _nombreFacettes;

	// Permet de savoir quel base de l'outil est d�bouchante
	// Par d�faut, les bases ne sont pas d�bouchante
	bool _avecBaseHaut, _avecBaseBas;

	virtual void buildSommets(Tableaux<SommetsP>& sommetsBaseBas, Tableaux<SommetsP>& sommetsBaseHaut) = 0;

public:

	/**
	 * Constructeur de OutilPercage
	 * avecBaseHaut : Si la base sup�rieur doit �tre d�bouchante
	 * avecBaseBas : Si la base inf�rieur doit �tre d�bouchante
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
	 * Le contour de percage est le contour de l'outil par d�faut utilis�
	 * Si la base inf�rieur est affich�, alors le contour de percage sera le contour exterieur (inverment pour la base sup�rieur)
	 * Remarque : L'outil doit avoir �t� forc�ment construit en mode invers�
	 */
	const ContoursP getContourDePercage();

	/**
	 * Permet de retourner le contour de base sup�rieur
	 * Remarque : m�me si la face sup�rieur n'est pas affich�, le contour a �t� g�n�r�
	 */
	ContoursP getContourBaseHaut();

	/**
	 * Permet de retourner le contour de base inf�rieur
	 * Remarque : m�me si la face inf�rieur n'est pas affich�, le contour a �t� g�n�r�
	 */
	ContoursP getContourBaseBas();

	/**
	 * Permet se savoir si la base inf�rieur est d�bouchante (Retourne faux dans ce cas)
	 */
	bool avecBaseBas() const;

	/**
	 * Permet se savoir si la base sup�rieur est d�bouchante (Retourne vrai dans ce cas)
	 */
	bool avecBaseHaut() const;

	/**
	 * Permet de r�cup�rer les face de l'outil en fonction des bases � afficher
	 * Retourne les faces param�tr�s de l'outil
	 */
	Tableaux<FacesP> faceOutils();
	
};

