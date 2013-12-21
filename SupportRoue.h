/**
 * Classe SupportRoue
 * ******************
 * Permet d'utiliser la pi�ce "Support de Roue"
 * La roue comporte 3 rep�res sur 3 positions diff�rentes
 * Chaque rep�re repr�sente un point de pivot de la pi�ce
 * Le rep�re principal se situe au niveau de la fixation du chassis sur le support de roue
 * L'axe de ce pivot est le Z. La pi�ce se prolonge ensuite vers le support de roue sur l'axe X. 
 * Le rep�re de la fixation de la bielle est le m�me que celui de la fixation du chassis
 * Par contre le rep�re de la fixation de la roue est diff�rent. Son Z pointe vers la sortie d�bouchante � la roue, son X vers le bas de la pi�ce.
 * Chaque position de rep�re repr�sente le point de pivot sur une sortie d�bouchante.
 * La position du repere de la fixation du chassis se situe au niveau du haut de la base.
 * Celle de la bielle se situe au niveau du haut du support
 * Celle de la roue sur le m�me plan que la face arriere du support, en son milieu
 *
 * Auteur :		SCHEIBEL Jean-Baptiste
 * Cr�� le :	5 avril 2012
 * Modifi� le : 6 avril 2012
 * Version :	1.0
 */

#pragma once
#include "BibliothequeBRepP.h"
#include "Piece.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"

 class SupportRoue : public Piece{

	// La base est l'�l�ment triangulaire de la pi�ce
	// C'est la largeur de la face avant, partie qui sera en dessous du chassis
	double _largeurBaseFixationChassis;

	// C'est la largeur de la base compl�te.
	// C'est aussi la longueur du support
	// Le support est l'�l�ment qui supportera la roue
	double _largeurBaseSupport;

	// Hauteur de la base
	double _epaisseurBase;

	// Hauteur du support
	double _hauteurSupport;

	// C'est le diametre du trou d�bouchant de la base qui permettera de fixer 
	// le chassis sur la base de fa�on � faire pivoter le support de roue
	double _diametreFixationChassis;

	// C'est l'ecart entre le trou de fixation du chassis et la face avant de la base
	double _ecartFixationChassis;

	// C'est le diametre du trou de fixation de la roue sur le support
	double _diametreFixationRoue;

	// C'est le diametre du trou de fixation de la bielle
	double _diametreFixationBielle;

	// Ecart entre le trou de fixation de la bielle et la face de cot� du support point� par l'axe Z du rep�re de la bielle.
	double _ecartFicationBielle;

	// Longueur de la base. 
	// Cela ne comprent pas l'epaisseur du support
	double _longueurBase;

	// Epaisseur du support
	double _epaisseurSupport;

	// Vrai Si la bielle doit �tre construite du cot� gauche
	bool _gauche;

	// Permet de construire l'objet
	// Appel� une fois dans le constructeur
	virtual void buildAll();

	/**
	 * Permet de v�rifier les arguments pass�s dans le constructeur 
	 * pour �viter une construction eronn�e du support de roue
	 */
	void verifierArguments() throw(exception);

 public:
	 
	 /**
	  * Constructeur de roue
	  * repere:							Repere de base de l'objet. Son Z constitue l'axe de rotation de la fixation du chassis sur la base du support. 
	  *									Son X pointe vers la pi�ce
	  *									La Position du repere de base du support de roue se situe sur le m�me plan que la face du dessus de la base triangulaire du support, 
	  *									au centre du trou de la fixation du chassis sur la base du support.
	  * largeurBaseFixationChassis:		La base est l'�l�ment triangulaire de la pi�ce
	  *									C'est la largeur de la face avant, partie qui sera en dessous du chassis
	  * largeurBaseSupport:				C'est la largeur de la base compl�te.
      *									C'est aussi la longueur du support
	  *									Le support est l'�l�ment qui supportera la roue
	  * longueurBase:					Longueur de la base. Cela ne comprent pas l'epaisseur du support
	  * epaisseurBase:					Hauteur de la base
	  * epaisseurSupport:				Epaisseur du support
	  * hauteurSupport:					Hauteur du support
	  * diametreFixationChassis:		C'est le diametre du trou d�bouchant de la base qui permettera de fixer 
	  *									le chassis sur la base de fa�on � faire pivoter le support de roue
	  * ecartFixationChassis:			C'est l'ecart entre le trou de fixation du chassis et la face avant de la base
	  * diametreFixationRoue:			C'est le diametre du trou de fixation de la roue sur le support
	  * diametreFixationBielle:			C'est le diametre du trou de fixation de la bielle
	  * ecartFicationBielle:			Ecart entre le trou de fixation de la bielle et la face de cot� du support point� par l'axe Z du rep�re de la bielle.
	  * gauche:							Si la fixation de la bielle doit �tre positionn� du cot� gauche
	  * *attributFace:					Attribut de la face)
	  */
	 SupportRoue(const Repere3D& repere						= Repere3D(), 
				 const double largeurBaseFixationChassis	= 5,
				 const double largeurBaseSupport			= 20,
				 const double longueurBase					= 20,
				 const double epaisseurBase					= 5,
				 const double epaisseurSupport				= 5,
				 const double hauteurSupport				= 17,
				 const double diametreFixationChassis		= 3,
				 const double ecartFixationChassis			= 5,
				 const double diametreFixationRoue			= 7,
				 const double diametreFixationBielle		= 3,
				 const double ecartFicationBielle			= 5,
				 const bool gauche							= false,
				 AttributsFacesP *attributFace				= &AttributsFaces(PMateriauVert)) 
				 throw(exception);

	 ~SupportRoue();

	 /**
	  * Permet de r�cup�rer le repere de la fixation de la bielle sur le haut du support
	  * Identique � celui de la fixation au chassis
	  */
	 Repere3D getRepere3DFixationBielle() const;

	 /**
	  * Permet de r�cuperer le repere de la fixation de la roue sur la face arriere du support
	  */
	 Repere3D getRepere3DFixationInterieurRoue() const;

	 /**
	  * Permet de r�cuperer le repere de la fixation de la roue sur la face avant du support
	  */
	 Repere3D getRepere3DFixationExterieurRoue() const;

	 /**
	  * Permet de r�cup�rer le repere la fixation du chassis sur la base du suport. C'est le repere de r�f�rence de la piece.
	  */
	 Repere3D getRepere3DFixationChassis() const;
 };