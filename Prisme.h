/*
Cr�ation :				Christophe ELSENSOHN 
Date de cr�ation :		05/04/2012
Version :				0
Modifi� par:			null
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

	- position	(constPoints3D&)	: point se trouvant sur la face dont le vecteur normal est oppos� � l'axe Z du rep�re fourni.
									Ce point se trouve � l'intersection des diagonales du rectangle largeur*hauteur.

	- repere	(const Repere3D&)	:	La longueur suivra l'axe Z de ce rep�re.
										La largeur  suivra l'axe X de ce rep�re.
										La hauteur  suivra l'axe Y de ce rep�re.

	- longueur	(double)			: dimension du Prisme suivant l'axe Z du rep�re.

	- largeur	(double)			: dimension du Prisme suivant l'axe X du rep�re.

	- hauteur	(double)			: dimension du Prisme suivant l'axe Y du rep�re.

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
//	Getter du vecteurs3D de l'autre extremit�

	const Repere3D getRepere3DOppose() const;
	
//_____________________________________________________________________________
//
//	Getter de la facesP de base du Prisme.
//	La base du prisme est la face contenant le Points3D position
//	dont le vecteur normal est le vecteur oppos� au  vecteur Z du repere
//	fourni lors de la construction

	const FacesP& faceBase()const;

//_____________________________________________________________________________
//
//	M�thode renvoyant la face oppos� � la base g�n�ratrice du prisme

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
//	Rayon du petit diam�tre/Longueur du Prisme suivant
//	l'axe Z du Repere fourni � la construction

	double _longueur;

//_____________________________________________________________________________
//
//	Largeur du Prisme suivant l'axe X du Repere3D fourni � la construction

	double _largeur;

//_____________________________________________________________________________
//
//	Hauteur du Prisme suivant l'axe Y du Repere3D fourni � la construction

	double _hauteur;

//_____________________________________________________________________________
//
//	Pointeur vers la face dont le vecteur normal est oppos� � l'axe Z du rep�re fourni.
//	Cette face contient le Points3D position fourni � la construction

	const FacesP* _base;
	
//_____________________________________________________________________________
//
//	Pointeur vers la face oppos�e de la face _base

	const FacesP* _sommet;

//_____________________________________________________________________________
//
//	Tableaux contenant les pointeurs vers les faces3D repr�sentant les flans du Prisme

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
//	M�thode de construction du Prisme
//	Le Prisme ainsi construit aura :
//		- la Longueur suivant Z du rep�re
//		- la Largeur  suivant X du rep�re
//		- la Hauteur  suivant Y du rep�re

	virtual void buildAll();	
};

