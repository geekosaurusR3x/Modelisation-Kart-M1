/**
 * Classe ArretTriangulaire
 * ************************
 * ArretTriangulaire est une pi�ce triangulaire, � hauteur variable, permettant de fixer un axe dans un �videment borgne positionn� perpendiculairement � la face triangul�e.
 * Le repere local se trouve sur le m�me plan que la face du dessous, au centre de la pi�ce
 * Le repere de l'�videment se trouve sur le m�me plan que la pente, son Z pointant vers l'exterieur de la piece et son X et Y dans le plan de la pente
 * La position de ce repere se trouve au fond de l'�videment, en son centre
 *
 * 
 * Auteur :		SCHEIBEL Jean-Baptiste
 * Cr�� le :	9 avril 2012
 * Modifi� le : 10 avril 2012
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

	// Angle de la pente du triangle � partir du haut de la base
	// Attention: Doit �tre exprim� en radian et non en degr�e
	double _angleTriangle;

	// Longueur de la base
	double _longueur;

	// Largeur de la base
	double _largeur;

	// Diametre de l'evidement
	double _diametreEvidement;

	// Permet de d�finir un ecart depuis un des cot� de la piece
	double _ecart;

	// Bordure Arriere du triangle
	double _bordure;

	// Permet de d�finir une hauteur maximal pour le triangle
	// En cas de d�passe, le triangle est rogn�
	double _hauteurMax;

	// D�finit le cot� � prendre en compte pour l'ecart
	bool _ecartDepuisCoteGauche;

	// Pronfondeur de l'evidement 
	double _pronfondeurEvidement;

	// Pointeur sur la face � percer
	// Appeler BuildAll pour l'enregistrer
	FacesP _facePercee;

	// Permet de construire l'objet
	// Appel� une fois dans le constructeur
	virtual void buildAll();

	/**
	 * Permet de v�rifier les arguments pass�s dans le constructeur 
	 * pour �viter une construction eronn�e de l'arret triangulaire
	 */
	void verifierArguments() throw(exception);

public:

	/**
	 * Constructeur de ArretTriangulaire
	 * repere :					Repere local
	 * hauteurBase :			Hauteur de la base se trouvant en dessous du triangle
	 * angleTriangle :			Angle de la pente du triangle � partir du haut de la base
	 *							Doit �tre exprim� en radian
	 * longueur :				Longueur de la base
	 * largeur :				Largeur de la base (non inclus la bordure de la piece!)
	 * ecart :					Ecart depuis l'un des cot�s de la piece
	 * ecartDepuisCoteGauche :	Vrai si l'ecart de l'�videment doit �tre calcul� � partir du cot� gauche
	 *							Respectivement Faux pour le cot� droit
	 * bordure :				Bordure Arriere du triangle ( la largeur mod�lis� de la piece correspond � la largeur + la bordure)
	 * hauteurMax :				Permet de d�finit une hauteur maximal pour la pi�ce (base + hauteur du triangle compris!)
	 *							Attention : Si la pi�ce est rogn�e, la bordure physique (mod�lis�) du haut du triangle n'est plus celle donn�e en param�tre!
	 *							Elle n'est cepandant pas modifi� dans les propri�t�s de l'objet (Important)
	 *							Plus la pi�ce doit �tre rogn�e, moins la longueur de pente est importe et plus la bordure augmente
	 *							Remarque : Cela n'affecte pas la pente!
	 * pronfondeurEvidement	:	Profondeur de l'�videment de la pi�ce
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
	 * Permet de r�cup�rer le repere 3D du trou borgne de la face triangul�e
	 * Le repere est position�e au milieu et au fond du trou
	 * Le vecteur Z de ce repere pointe vers l'exterieur de la piece et est parall�le � l'axe du trou
	 */
	Repere3D getRepere3DEvidement();
};

