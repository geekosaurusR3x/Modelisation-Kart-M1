/**
 * Classe Bielle
 * *************
 * Permet d'utiliser la pièce "Bielle"
 * Cette piece comporte 2 repères transposés en 2 positions
 * Le 1er repère correspond au 1er alésage de la bielle (respectivement pour le 2ème repère)
 * Une fois construit, la bielle peut être soumise à diveses rotations
 * Son seul degré de liberté consiste en la rotation de la bielle autour de l'axe Z d'un de ses 2 alesages
 * 
 * Auteurs : ELSENSOHN Christophe / SCHEIBEL Jean-Baptiste
 * Créé le :	4 avril 2012
 * Modifié le : 5 avril 2012
 */

#pragma once
#include "BibliothequeBRepP.h"
#include "Piece.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"

 class Bielle : public Piece{

	// Diametre du 1er alesage 
	double _diametreAlesage1;

	// Ecart entre les 2 aces
	double _entreAxe;

	// Diametre du 2eme alesage
	double _diametreAlesage2; 

	// Epaisseur de la bielle
	double _epaisseur;

	// Largeur de la bielle
	double _largeur;

	// Permet de construire l'objet
	// Appelé une fois dans le constructeur
	virtual void buildAll();

	/**
	 * Permet de vérifier les arguments passés dans le constructeur 
	 * pour éviter une construction eronnée de la bielle
	 */
	void verifierArguments() throw(exception);

 public:
	 /**
	  * Constructeur de la bielle
	  * Le solide est physiquement est créé
	  *
	  * repere : Repere du 1er alesage. La bielle est construit selon l'axe X de ce repère. La position de la bielle est le centre du 1er alesage
	  * diametreAlesage1 : Diametre du 1er alésage
	  * entreAxe : Ecart entre les 2 alésages
	  * epaisseur : Epaisseur de la bielle
	  * largeur : Largeur de la bielle
	  * attributFace : Attribut des faces de la bielle
	  */
	 Bielle(const Repere3D& repere			= Repere3D(), 
			const double diametreAlesage1	= 3,
			const double entreAxe			= 20, 
			const double diametreAlesage2	= 3, 
			const double epaisseur			= 4,
			const double largeur			= 8,
			AttributsFacesP *attributFace 	= &AttributsFaces(PMateriauVert))
			throw(exception);

	 ~Bielle();

	 /**
	  * Permet de retourner le repère 3D du 1er alésage de la bielle
	  */
	 Repere3D getRepere3DAlesage1() const;

	 /**
	  * Permet de retourner le repère 3D du 2eme alésage de la bielle
	  */
	 Repere3D getRepere3DAlesage2() const;

	 /** 
	  * Permet d'éxécuter une rotation de la bielle autour de l'axe Z du 1er alesage
	  */
	 void rotationSurZAlesage1(double teta);

	 /**
	  * Permet d'éxécuter une rotation de la bielle autour de l'axe Z du 2eme alésage
	  */
	 void rotationSurZAlesage2(double teta);


 };