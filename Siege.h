/**
 * Classe Siege
 * ************
 * Définit la pièce "Siege"
 * Le repere du siege est définit sur le même plan que la face inférieur de l'assise
 * Z pointe vers le haut du siège et X vers l'exterieur de la chaise (devant le dossier)
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

class Siege : public Prisme
{
	// Largeur de l'assise 
	double _largeurAssise;

	// Longueur de l'assise
	double _longueurAssise;

	// L'epaisseur de l'assise
	double _epaisseurAssise;

	// Hauteur du dossier
	double _hauteurDossier;

	// Epaisseur du dossier
	double _epaisseurDossier;

	// Permet de construire l'objet
	// Appelé une fois dans le constructeur
	virtual void buildAll();

	/**
	 * Permet de vérifier les arguments passés dans le constructeur 
	 * pour éviter une construction eronnée de siege
	 */
	void verifierArguments() throw(exception);

public:
	/**
	 * Constructeur de siege
	 * repere :				Repere local de la piece
	 * largeurAssise :		Largeur de l'assise
	 * longueurAssise :		Longueur de l'assise
	 * EpaisseurAssise :	Epaisseur de l'assise
	 * HauteurDossier :		Hauteur du dosser.
	 *						Le dossier est poser sur l'assise
	 * epaisseurDossier :	Epaisseur du dossier
	 * attributFace :		Attribut des faces
	 */
	Siege(	const Repere3D& repere			= Repere3D(), 
			const double largeurAssise		= 25,
			const double longueurAssise		= 30,
			const double epaisseurAssise	= 15,
			const double hauteurDossier		= 15,
			const double epaisseurDossier	= 5,
			AttributsFacesP *attributFace 	= &AttributsFaces(PMateriauJaune))
			throw(exception);
};

