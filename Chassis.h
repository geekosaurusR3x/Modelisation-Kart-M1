/**
 * Classe Chassis
 * **************
 * Permet d'utiliser la pièce "Chassis"
 * Chaques evidements du chassis comprend un repère dans sa propre orientation.
 * Tous les évidements de positionnement (pour la colonne de direction, support de cremaillere, fourche, siege) ont le même repère (uniquement l'orientation des vecteurs) que le repère de référence
 * La position est unique à chaque évidement, centré en leurs milieux.
 * La repere de référence est positionné sur l'axe des roues arrieres, au milieu du chassis
 * Son vecteur X pointe vers l'avant du chassis, Y vers le coté gauche du chassis, parallele à l'axe de rotation de la roue arriere
 * En ce qui concerne l'axe arriere des roues, le vecteur Z de son repere pointe vers l'extérieur du chassis.
 *
 * Auteur :		SCHEIBEL Jean-Baptiste
 * Créé le :	6 avril 2012
 * Modifié le : 9 avril 2012
 * Version :	1
 */

#pragma once
#include "Piece.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"

class Chassis : public Piece
{
	// Longueur du chassis avant sans les chanfreins
	double _longueurChassisAvant;

	// Longueur du chassis arriere sans les chanfreins
	double _longueurChassisArriere;

	// Largeur total du chassis
	double _largeurChassis;

	// Pronfondeur de retraississement du chassis à l'avant pour fixer les roues
	// Les chanfreins sont calculés en fonction de cette pronfondeur à 45°
	double _profondeurRoueAvant;

	// Ecart entre la face arriere du chassis et l'axe de la roue arriere
	double _ecartRoueArriere;

	// Largeur de l'evidement de la fourche
	double _largeurEvidementFourche;

	// Longueur de l'evidement de la fourche
	double _longeurEvidementFourche;

	// Ecart entre la fourche et le siege
	double _ecartFourcheSiege;

	// Largeur de l'evidement du siege
	double _largeurEvidementSiege;

	// Longueur de l'evidement du siege
	double _longueurEvidementSiege;

	// Ecart entre la face de degagement et le pivot de support de roue
	double _ecartPivotSupportRoue;

	// Diametre du pivot de support de roue avant
	double _diametrePivotSupportRoue;

	// Largeur de l'evidement du support de cremaillere
	double _largeurEvidementSupportCremaillere;

	// Longueur de l'evidement du support de cremaillere
	double _longeurEvidementSupportCremaillere;

	// Ecart entre le support de cremaillere et l'arrive de la colonne de direction
	double _ecartSupportsCremaillereArriveColonneDirection;

	// Pronfondeur de tous les evidements du chassis
	// ne doit pas être supérieur à la pronfondeur du chassis
	double _profondeurTousEvidements;

	// Pronfondeur du chassis
	double _profondeurChassis;

	// Diametre de l'axe de la roue arriere
	double _diametreAxeRoueArriere;

	// Largeur de l'arret de l'axe de la roue arriere
	// Ne doit pas etre supérieur au diametre sinon la roue ne pourra rentré
	double _largeurArretRoueArriere;

	// Longueur de l'axe de la roue arriere
	double _longueurAxeRoueArriere;

	// diametre du trous de percage pour la goupille sur l'arret des axes arrieres
	double _diametrePercageGoupilleArret;

	// Largeur de l'evidement de l'arrive de la colonne de direction
	double _largeurEvidementArriveColonneDirection;

	// Longueur de l'evidement de l'arrive de la colonne de direction
	double _longueurEvidementArriveColonneDirection;

	// Ecart entre le support de cremaillere et la fourche
	double _ecartSupportCremaillereFourche;

	// Ecart entre l'arrivé de la colonne de direction et la face avant du chassis
	double _ecartArriveColonnesDirectionFaceAvant;

	// Permet de construire l'objet
	// Appelé une fois dans le constructeur
	virtual void buildAll();

	/**
	 * Permet de vérifier les arguments passés dans le constructeur 
	 * pour éviter une construction eronnée du chassis
	 */
	void verifierArguments() throw(exception);

public:

	/**
	 * repere :											Repere du chassis. Par défaut, le repere du chassis se trouve sur l'axe des roue arriere, 
	 *													X pointant vers l'avant du chassis, Y parallele à l'axe des roues
	 * longueurChassisAvant :							Longueur du chassis avant sans les chanfreins
	 * longueurChassisArriere :							Longueur du chassis arriere sans les chanfreins
	 * largeurChassis :									Largeur total du chassis
	 * profondeurRoueAvant :							Pronfondeur de retraississement du chassis à l'avant pour fixer les roues
	 *													Les chanfreins sont calculés en fonction de cette pronfondeur à 45°
	 *													Attention : La pronfondeur reservé aux roues avant doit être au minimum 4 fois plus petite que la largeur du chassis
	 * ecartRoueArriere :								Ecart entre la face arriere du chassis et l'axe de la roue arriere
	 * largeurEvidementFourche :						Diametre du pivot de support de roue avant
	 * longeurEvidementFourche :						Longueur de l'evidement de la fourche
	 * ecartFourcheSiege :								Ecart entre la fourche et le siege
	 * largeurEvidementSiege :							Largeur de l'evidement du siege
	 * longueurEvidementSiege :							Longueur de l'evidement du siege
	 * ecartPivotSupportRoue :							Ecart entre la face de degagement et le pivot de support de roue
	 * diametrePivotSupportRoue :						Diametre du pivot de support de roue avant
	 * largeurEvidementSupportCremaillere :				Largeur de l'evidement du support de cremaillere
	 * longeurEvidementSupportCremaillere :				Longueur de l'evidement du support de cremaillere
	 * ecartSupportsCremaillereArriveColonneDirection :	Ecart entre le support de cremaillere et l'arrive de la colonne de direction
	 * profondeurTousEvidements :						Pronfondeur de tous les evidements du chassis. ne doit pas être supérieur à la pronfondeur du chassis
	 * profondeurChassis :								Pronfondeur du chassis
	 * diametreAxeRoueArriere :							Diametre de l'axe de la roue arriere
	 * largeurArretRoueArriere :						Largeur de l'arret de l'axe de la roue arriere. Ne doit pas etre supérieur au diametre sinon la roue ne pourra rentré
	 * longueurAxeRoueArriere :							Longueur de l'axe de la roue arriere
	 * diametrePercageGoupilleArret :					diametre du trous de percage pour la goupille sur l'arret des axes arrieres
	 * largeurEvidementArriveColonneDirection :			Largeur de l'evidement de l'arrive de la colonne de direction
	 * longueurEvidementArriveColonneDirection :		Longueur de l'evidement de l'arrive de la colonne de direction
	 * ecartSupportCremaillereFourche :					Ecart entre le support de cremaillere et la fourche
	 * ecartArriveColonnesDirectionFaceAvant :			Ecart entre l'arrivé de la colonne de direction et la face avant du chassis
	 * attributFace :									Attribut des faces de l'objets
	 */
	Chassis(const Repere3D& repere										= Repere3D(), 
			const double longueurChassisAvant							= 50, 
			const double longueurChassisArriere							= 55, 
			const double largeurChassis									= 80, 
			const double profondeurRoueAvant							= 10, 
			const double ecartRoueArriere								= 20, 
			const double largeurEvidementFourche						= 5,
			const double longeurEvidementFourche						= 10,
			const double ecartFourcheSiege								= 20,
			const double largeurEvidementSiege							= 25,
			const double longueurEvidementSiege							= 30,
			const double ecartPivotSupportRoue							= 5,
			const double diametrePivotSupportRoue						= 3,
			const double largeurEvidementSupportCremaillere				= 4,
			const double longeurEvidementSupportCremaillere				= 6,
			const double ecartSupportsCremaillereArriveColonneDirection	= 9,
			const double profondeurTousEvidements						= 5,
			const double profondeurChassis								= 10,
			const double diametreAxeRoueArriere							= 7,
			const double largeurArretRoueArriere						= 5,
			const double longueurAxeRoueArriere							= 3,
			const double diametrePercageGoupilleArret					= 1,
			const double largeurEvidementArriveColonneDirection			= 7,
			const double longueurEvidementArriveColonneDirection		= 10,
			const double ecartSupportCremaillereFourche					= 27,
			const double ecartArriveColonnesDirectionFaceAvant			= 5,
			AttributsFacesP *attributFace								= &AttributsFaces(PMateriauVert)) 
			throw(exception);

	/**
	 * Permet de récuperer le repere 3D de l'évidement de la cremaillere centrale
	 * Le repere est positionné sur le plan de l'évidement, au milieu de l'évidement
	 */
	Repere3D getRepere3DFixationSupportCremaillereCentral() const;

	/**
	 * Permet de récupérer le repere 3D de l'évidement d'une des 2 cremailleres situés de coté
	 * Le repere est positionné sur le plan de l'évidement, au milieu de l'évidement
	 * gauche : Vrai pour récupérer le repere gauche du chassis, sachant que le coté gauche est pointé par l'axe Y du repere. 
	 *			(Respectivement Faux pour récupérer le repere de droite)
	 */
	Repere3D getRepere3DFixationSupportCremaillere(bool gauche) const;

	/**
	 * Permet de récupérer le repere de la fixation de l'arrivé de la colonne de direction du le chassis
	 * Le repere est le même que le repere de référence
	 * Il est positionné sur le même plan que l'évidement en son centre
	 */
	Repere3D getRepere3DFixationArriveeColonneDirection() const;

	/**
	 * Permet de récupérer le repere situé au milieu de l'évidement de la fixation de la fourche, au milieu de son évidement
	 */
	Repere3D getRepere3DFixationFourche() const;

	/**
	 * Permet de récupérer le repere de l'axe de la roue arriere
	 * L'orientation du repere change en fonction du repere de la roue gauche ou droite
	 * Le vecteur Z pointe vers l'extérieur du chassis, vers la roue
	 * gauche : Vrai pour récupérer le repere de l'axe de la roue gauche, (Faux pour le repere de l'axe de la roue droite)
	 */
	Repere3D getRepere3DFixationRoueArriere(bool gauche) const;

	/**
	 * Permet de récupérer le repere de l'évidement du siege
	 * Il est positionné sur le même plan que l'évidement, en son milieu. Il est orienté de la même façon que le repere de référence
	 */
	Repere3D getRepere3DFixationSiege() const;

	/**
	 * Permet de récupérer les reperes des fixations des supports de roues avants
	 * Le repere est identique au repere de référence. Le vecteur Z étant sur l'axe de pivot.
	 * gauche : Vrai pour récupérer le repere du pivot gauche, Faux pour le repere du pivot droit.
	 */
	Repere3D getPosition3DFixationRoueAvant(bool gauche) const;
};


	
