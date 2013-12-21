/**
 * Classe Goupille
 * ***************
 * D�finit la pi�ce "Goupille"
 * Le repere de la goupille est orient� selon l'axe de la goupille
 * Il est positionn� � l'intersection du corps et de la t�te de la goupille, au milieu
 * Le vecteur Z est parallele � l'axe du corps
 * Et le vecteur Y d�finit l'axe de la t�te
 * 
 * Auteur :		SCHEIBEL Jean-Baptiste
 * Cr�� le :	9 avril 2012
 * Modifi� le : 9 avril 2012
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
	// Appel� une fois dans le constructeur
	virtual void buildAll();

	/**
	 * Permet de v�rifier les arguments pass�s dans le constructeur 
	 * pour �viter une construction eronn�e de la piece
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
