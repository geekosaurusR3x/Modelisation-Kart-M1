/*
Création :				Christophe ELSENSOHN 
Date de création :		05/04/2012
Version :				0
Modifié par:			null
Date de modification:	null
*/
#pragma once

#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"
#include "Piece.h"


class Prisme:public Piece
{
	
//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################
public:

//*****************************************************************************
//						CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************
	
//_____________________________________________________________________________
//
//	Constructeur d'instance de Prisme 

	Prisme(const Repere3D& repere=Repere3D(),
		double longeur=60, double largeur=2, double hauteur=2,
		AttributsFacesP *PtAF=&AttributsFaces(PMateriauVert));
/*
PARAMETRES

	- position	(constPoints3D&)	: point se trouvant sur la face dont le vecteur normal est opposé à l'axe Z du repère fourni.
									Ce point se trouve à l'intersection des diagonales du rectangle largeur*hauteur.

	- repere	(const Repere3D&)	:	La longueur suivra l'axe Z de ce repère.
										La largeur  suivra l'axe X de ce repère.
										La hauteur  suivra l'axe Y de ce repère.

	- longueur	(double)			: dimension du Prisme suivant l'axe Z du repère.

	- largeur	(double)			: dimension du Prisme suivant l'axe X du repère.

	- hauteur	(double)			: dimension du Prisme suivant l'axe Y du repère.

	_ PtAF		(AttributFacesP*)	: couleur des faces.
*/
	
	
//_____________________________________________________________________________
//
//	Constructeur par recopie de Prisme

	Prisme(const Prisme& prisme);

//_____________________________________________________________________________
//
//	Destructeur de Prisme

	virtual ~Prisme(void);

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter de la Droites3D du prisme

	Droites3D getAxe() const;

//_____________________________________________________________________________
//
//	Getter de la longueur du Prisme

	double getLongueur()const;

//_____________________________________________________________________________
//
//	Getter de la largeur du Prisme

	double getLargeur() const;

//_____________________________________________________________________________
//
//	Getter de la hauteur du Prisme

	double getHauteur()const;

//_____________________________________________________________________________
//
//	Getter du Vecteurs3D de la direction du Prisme

	const Vecteurs3D getDirection()const;

//_____________________________________________________________________________
//
//	Getter du vecteurs3D de l'autre extremité

	const Repere3D getRepere3DOppose() const;
	
//_____________________________________________________________________________
//
//	Getter de la facesP de base du Prisme.
//	La base du prisme est la face contenant le Points3D position
//	dont le vecteur normal est le vecteur opposé au  vecteur Z du repere
//	fourni lors de la construction

	const FacesP& faceBase()const;

//_____________________________________________________________________________
//
//	Méthode renvoyant la face opposé à la base génératrice du prisme

	const FacesP& faceSommet()const;

//_____________________________________________________________________________
//
//	Getter du tableau des pointeurs vers les faces
//	des flans du prisme.

	Tableaux<const FacesP*> flans()const;


//#############################################################################
//								DOMAINE PROTECTED
//#############################################################################
protected:

//*****************************************************************************
//							DONNEES MEMBRES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Rayon du petit diamètre/Longueur du Prisme suivant
//	l'axe Z du Repere fourni à la construction

	double _longueur;

//_____________________________________________________________________________
//
//	Largeur du Prisme suivant l'axe X du Repere3D fourni à la construction

	double _largeur;

//_____________________________________________________________________________
//
//	Hauteur du Prisme suivant l'axe Y du Repere3D fourni à la construction

	double _hauteur;

//_____________________________________________________________________________
//
//	Pointeur vers la face dont le vecteur normal est opposé à l'axe Z du repère fourni.
//	Cette face contient le Points3D position fourni à la construction

	const FacesP* _base;
	
//_____________________________________________________________________________
//
//	Pointeur vers la face opposée de la face _base

	const FacesP* _sommet;

//_____________________________________________________________________________
//
//	Tableaux contenant les pointeurs vers les faces3D représentant les flans du Prisme

	Tableaux<const FacesP*> _flans;



//#############################################################################
//								DOMAINE PRIVE
//#############################################################################
private:

//*****************************************************************************
//									METHODES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Méthode de construction du Prisme
//	Le Prisme ainsi construit aura :
//		- la Longueur suivant Z du repère
//		- la Largeur  suivant X du repère
//		- la Hauteur  suivant Y du repère

	virtual void buildAll();	
};

