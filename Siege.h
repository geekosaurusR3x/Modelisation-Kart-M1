/**
 * Classe Siege
 * ************
 * D�finit la pi�ce "Siege"
 * Le repere du siege est d�finit sur le m�me plan que la face inf�rieur de l'assise
 * Z pointe vers le haut du si�ge et X vers l'exterieur de la chaise (devant le dossier)
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
	// Appel� une fois dans le constructeur
	virtual void buildAll();

	/**
	 * Permet de v�rifier les arguments pass�s dans le constructeur 
	 * pour �viter une construction eronn�e de siege
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

