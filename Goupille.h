/**
 * Classe Goupille
 * ***************
 * Définit la pièce "Goupille"
 * Le repere de la goupille est orienté selon l'axe de la goupille
 * Il est positionné à l'intersection du corps et de la tête de la goupille, au milieu
 * Le vecteur Z est parallele à l'axe du corps
 * Et le vecteur Y définit l'axe de la tête
 * 
 * Auteur :		SCHEIBEL Jean-Baptiste
 * Créé le :	9 avril 2012
 * Modifié le : 9 avril 2012
 * Version :	1
 */

#pragma once
#include "Prisme.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"

class Goupille : public Prisme
{
	double _hauteur;
	double _diametre;
	double _longueurTete;

	// Permet de construire l'objet
	// Appelé une fois dans le constructeur
	virtual void buildAll();

	/**
	 * Permet de vérifier les arguments passés dans le constructeur 
	 * pour éviter une construction eronnée de la piece
	 */
	void verifierArguments() throw(exception);

public:

	Goupille(	const Repere3D& repere			= Repere3D(), 
				const double hauteur			= 10,
				const double diametre			= 3,
				const double longueurTete		= 5,
				AttributsFacesP *attributFace	= &AttributsFaces(PMateriauVert))
				throw(exception);

	virtual ~Goupille();
};
