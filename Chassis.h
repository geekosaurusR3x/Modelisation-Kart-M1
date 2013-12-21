/**
 * Classe Chassis
 * **************
 * Permet d'utiliser la pi�ce "Chassis"
 * Chaques evidements du chassis comprend un rep�re dans sa propre orientation.
 * Tous les �videments de positionnement (pour la colonne de direction, support de cremaillere, fourche, siege) ont le m�me rep�re (uniquement l'orientation des vecteurs) que le rep�re de r�f�rence
 * La position est unique � chaque �videment, centr� en leurs milieux.
 * La repere de r�f�rence est positionn� sur l'axe des roues arrieres, au milieu du chassis
 * Son vecteur X pointe vers l'avant du chassis, Y vers le cot� gauche du chassis, parallele � l'axe de rotation de la roue arriere
 * En ce qui concerne l'axe arriere des roues, le vecteur Z de son repere pointe vers l'ext�rieur du chassis.
 *
 * Auteur :		SCHEIBEL Jean-Baptiste
 * Cr�� le :	6 avril 2012
 * Modifi� le : 9 avril 2012
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

	// Pronfondeur de retraississement du chassis � l'avant pour fixer les roues
	// Les chanfreins sont calcul�s en fonction de cette pronfondeur � 45�
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
	// ne doit pas �tre sup�rieur � la pronfondeur du chassis
	double _profondeurTousEvidements;

	// Pronfondeur du chassis
	double _profondeurChassis;

	// Diametre de l'axe de la roue arriere
	double _diametreAxeRoueArriere;

	// Largeur de l'arret de l'axe de la roue arriere
	// Ne doit pas etre sup�rieur au diametre sinon la roue ne pourra rentr�
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

	// Ecart entre l'arriv� de la colonne de direction et la face avant du chassis
	double _ecartArriveColonnesDirectionFaceAvant;

	// Permet de construire l'objet
	// Appel� une fois dans le constructeur
	virtual void buildAll();

	/**
	 * Permet de v�rifier les arguments pass�s dans le constructeur 
	 * pour �viter une construction eronn�e du chassis
	 */
	void verifierArguments() throw(exception);

public:

	/**
	 * repere :											Repere du chassis. Par d�faut, le repere du chassis se trouve sur l'axe des roue arriere, 
	 *													X pointant vers l'avant du chassis, Y parallele � l'axe des roues
	 * longueurChassisAvant :							Longueur du chassis avant sans les chanfreins
	 * longueurChassisArriere :							Longueur du chassis arriere sans les chanfreins
	 * largeurChassis :									Largeur total du chassis
	 * profondeurRoueAvant :							Pronfondeur de retraississement du chassis � l'avant pour fixer les roues
	 *													Les chanfreins sont calcul�s en fonction de cette pronfondeur � 45�
	 *													Attention : La pronfondeur reserv� aux roues avant doit �tre au minimum 4 fois plus petite que la largeur du chassis
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
	 * profondeurTousEvidements :						Pronfondeur de tous les evidements du chassis. ne doit pas �tre sup�rieur � la pronfondeur du chassis
	 * profondeurChassis :								Pronfondeur du chassis
	 * diametreAxeRoueArriere :							Diametre de l'axe de la roue arriere
	 * largeurArretRoueArriere :						Largeur de l'arret de l'axe de la roue arriere. Ne doit pas etre sup�rieur au diametre sinon la roue ne pourra rentr�
	 * longueurAxeRoueArriere :							Longueur de l'axe de la roue arriere
	 * diametrePercageGoupilleArret :					diametre du trous de percage pour la goupille sur l'arret des axes arrieres
	 * largeurEvidementArriveColonneDirection :			Largeur de l'evidement de l'arrive de la colonne de direction
	 * longueurEvidementArriveColonneDirection :		Longueur de l'evidement de l'arrive de la colonne de direction
	 * ecartSupportCremaillereFourche :					Ecart entre le support de cremaillere et la fourche
	 * ecartArriveColonnesDirectionFaceAvant :			Ecart entre l'arriv� de la colonne de direction et la face avant du chassis
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
	 * Permet de r�cuperer le repere 3D de l'�videment de la cremaillere centrale
	 * Le repere est positionn� sur le plan de l'�videment, au milieu de l'�videment
	 */
	Repere3D getRepere3DFixationSupportCremaillereCentral() const;

	/**
	 * Permet de r�cup�rer le repere 3D de l'�videment d'une des 2 cremailleres situ�s de cot�
	 * Le repere est positionn� sur le plan de l'�videment, au milieu de l'�videment
	 * gauche : Vrai pour r�cup�rer le repere gauche du chassis, sachant que le cot� gauche est point� par l'axe Y du repere. 
	 *			(Respectivement Faux pour r�cup�rer le repere de droite)
	 */
	Repere3D getRepere3DFixationSupportCremaillere(bool gauche) const;

	/**
	 * Permet de r�cup�rer le repere de la fixation de l'arriv� de la colonne de direction du le chassis
	 * Le repere est le m�me que le repere de r�f�rence
	 * Il est positionn� sur le m�me plan que l'�videment en son centre
	 */
	Repere3D getRepere3DFixationArriveeColonneDirection() const;

	/**
	 * Permet de r�cup�rer le repere situ� au milieu de l'�videment de la fixation de la fourche, au milieu de son �videment
	 */
	Repere3D getRepere3DFixationFourche() const;

	/**
	 * Permet de r�cup�rer le repere de l'axe de la roue arriere
	 * L'orientation du repere change en fonction du repere de la roue gauche ou droite
	 * Le vecteur Z pointe vers l'ext�rieur du chassis, vers la roue
	 * gauche : Vrai pour r�cup�rer le repere de l'axe de la roue gauche, (Faux pour le repere de l'axe de la roue droite)
	 */
	Repere3D getRepere3DFixationRoueArriere(bool gauche) const;

	/**
	 * Permet de r�cup�rer le repere de l'�videment du siege
	 * Il est positionn� sur le m�me plan que l'�videment, en son milieu. Il est orient� de la m�me fa�on que le repere de r�f�rence
	 */
	Repere3D getRepere3DFixationSiege() const;

	/**
	 * Permet de r�cup�rer les reperes des fixations des supports de roues avants
	 * Le repere est identique au repere de r�f�rence. Le vecteur Z �tant sur l'axe de pivot.
	 * gauche : Vrai pour r�cup�rer le repere du pivot gauche, Faux pour le repere du pivot droit.
	 */
	Repere3D getPosition3DFixationRoueAvant(bool gauche) const;
};


	
