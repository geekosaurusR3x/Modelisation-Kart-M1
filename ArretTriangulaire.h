/**
 * Classe ArretTriangulaire
 * ************************
 * ArretTriangulaire est une pièce triangulaire, à hauteur variable, permettant de fixer un axe dans un évidement borgne positionné perpendiculairement à la face triangulée.
 * Le repere local se trouve sur le même plan que la face du dessous, au centre de la pièce
 * Le repere de l'évidement se trouve sur le même plan que la pente, son Z pointant vers l'exterieur de la piece et son X et Y dans le plan de la pente
 * La position de ce repere se trouve au fond de l'évidement, en son centre
 *
 * 
 * Auteur :		SCHEIBEL Jean-Baptiste
 * Créé le :	9 avril 2012
 * Modifié le : 10 avril 2012
 * Version :	1
 */

#pragma once
#include "Piece.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"

class ArretTriangulaire : public Piece
{
	// Hauteur de la base se trouvant en dessous du triangle
	double _hauteurBase;

	// Angle de la pente du triangle à partir du haut de la base
	// Attention: Doit être exprimé en radian et non en degrée
	double _angleTriangle;

	// Longueur de la base
	double _longueur;

	// Largeur de la base
	double _largeur;

	// Diametre de l'evidement
	double _diametreEvidement;

	// Permet de définir un ecart depuis un des coté de la piece
	double _ecart;

	// Bordure Arriere du triangle
	double _bordure;

	// Permet de définir une hauteur maximal pour le triangle
	// En cas de dépasse, le triangle est rogné
	double _hauteurMax;

	// Définit le coté à prendre en compte pour l'ecart
	bool _ecartDepuisCoteGauche;

	// Pronfondeur de l'evidement 
	double _pronfondeurEvidement;

	// Pointeur sur la face à percer
	// Appeler BuildAll pour l'enregistrer
	FacesP _facePercee;

	// Permet de construire l'objet
	// Appelé une fois dans le constructeur
	virtual void buildAll();

	/**
	 * Permet de vérifier les arguments passés dans le constructeur 
	 * pour éviter une construction eronnée de l'arret triangulaire
	 */
	void verifierArguments() throw(exception);

public:

	/**
	 * Constructeur de ArretTriangulaire
	 * repere :					Repere local
	 * hauteurBase :			Hauteur de la base se trouvant en dessous du triangle
	 * angleTriangle :			Angle de la pente du triangle à partir du haut de la base
	 *							Doit être exprimé en radian
	 * longueur :				Longueur de la base
	 * largeur :				Largeur de la base (non inclus la bordure de la piece!)
	 * ecart :					Ecart depuis l'un des cotés de la piece
	 * ecartDepuisCoteGauche :	Vrai si l'ecart de l'évidement doit être calculé à partir du coté gauche
	 *							Respectivement Faux pour le coté droit
	 * bordure :				Bordure Arriere du triangle ( la largeur modélisé de la piece correspond à la largeur + la bordure)
	 * hauteurMax :				Permet de définit une hauteur maximal pour la pièce (base + hauteur du triangle compris!)
	 *							Attention : Si la pièce est rognée, la bordure physique (modélisé) du haut du triangle n'est plus celle donnée en paramètre!
	 *							Elle n'est cepandant pas modifié dans les propriétés de l'objet (Important)
	 *							Plus la pièce doit être rognée, moins la longueur de pente est importe et plus la bordure augmente
	 *							Remarque : Cela n'affecte pas la pente!
	 * pronfondeurEvidement	:	Profondeur de l'évidement de la pièce
	 * attributFace :			Attribut des faces de la piece
	 */
	ArretTriangulaire(	const Repere3D& repere				= Repere3D(), 
						const double hauteurBase			= 10,
						const double angleTriangle			= 1.42,
						const double longueur				= 10,
						const double largeur				= 7,
						const double diametreEvidement		= 5,
						const double ecart					= 5,
						const bool ecartDepuisCoteGauche	= false,
						const double bordure				= 5,
						const double hauteurMax				= 18,
						const double pronfondeurEvidement	= 4,
						AttributsFacesP *attributFace 		= &AttributsFaces(PMateriauVert))
						throw(exception);

	/**
	 * Destructeur de ArretTriangulaire
	 */
	virtual ~ArretTriangulaire();

	/**
	 * Permet de récupérer le repere 3D du trou borgne de la face triangulée
	 * Le repere est positionée au milieu et au fond du trou
	 * Le vecteur Z de ce repere pointe vers l'exterieur de la piece et est parallèle à l'axe du trou
	 */
	Repere3D getRepere3DEvidement();
};

