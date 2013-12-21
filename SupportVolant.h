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


class SupportVolant:public Piece
{
public:
	
//*****************************************************************************
//				CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************
	
/*----------------------------------------------------------------
		Constructeur d'instance de Prisme 
//----------------------------------------------------------------*/
	/*Prisme(const Repere3D& repere=Repere3D(),
		double longeur=60, double largeur=2, double hauteur=2,
		AttributsFacesP *PtAF=&AttributsFaces(PMateriauVert));*/


	SupportVolant(const Repere3D& repere=Repere3D(),double hauteur=100,double largeur=60, double epaisseur=20,
		double profondeurCavit1=15,double profondeurCavit2 = 25,double largeurCavit=10,double hauteurTrous=25,double ecartementTrous=30,double diametreTrous=5,
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
	
	
//----------------------------------------------------------------
//	Constructeur par recopie de Prisme
	SupportVolant(const SupportVolant& prisme);

//----------------------------------------------------------------
//	Destructeur de Prisme
	virtual ~SupportVolant(void);

/*****************************************************************************
						GETTERS ET SETTERS
/*****************************************************************************/

//----------------------------------------------------------------
	//Getter de la hauteur du Prisme
	double getHauteur()const;

//----------------------------------------------------------------
	//Getter de la longueur du Prisme
	double getLargeur()const;

//----------------------------------------------------------------
	//Getter de la largeur du Prisme
	double getEpaisseur() const;

//----------------------------------------------------------------
	//Getter de la hauteur du Prisme
	double getProfondeurCavit1()const;

//----------------------------------------------------------------
	//Getter de la hauteur du Prisme
	double getProfondeurCavit2()const;


//----------------------------------------------------------------
	//Getter de la hauteur du Prisme
	double getLargeurCavit()const;

//----------------------------------------------------------------
	//Getter du Vecteurs3D de la direction du Prisme
	const Vecteurs3D getDirection()const;

	// Getter du vecteurs3D de l'autre extremité
	const Repere3D getRepere3DOppose() const;
	
/*----------------------------------------------------------------
	Getter de la facesP de base du Prisme.
	La base du prisme est la face contenant le Points3D position
	dont le vecteur normal est le vecteur opposé au  vecteur Z du repere
	fourni lors de la construction*/
	const FacesP& faceBase()const;

//----------------------------------------------------------------
	//Méthode renvoyant la face opposé à la base génératrice du prisme
	const FacesP& faceSommet()const;

/*----------------------------------------------------------------
	//Getter du tableau des pointeurs vers les faces
	des flans du prisme.*/
	Tableaux<const FacesP*> flans()const;

//----------------------------------------------------------------
	//Getter de la Droites3D du Prisme
	const Droites3D& getAxe() const;

/*----------------------------------------------------------------
					METHODES PUBLIQUES
-----------------------------------------------------------------*/

protected:
//*****************************************************************************
//						DOMAINE PROTECTED
//*****************************************************************************

/*----------------------------------------------------------------
					DONNEES MEMBRES
----------------------------------------------------------------*/
//----------------------------------------------------------------
	//hauteur du support (axe Z)
	double _hauteur;

//----------------------------------------------------------------
	//Largeur du support (Axe X)
	double _largeur;

//----------------------------------------------------------------
	//épaisseur du support (Axe Y)
	double _epaisseur;

//----------------------------------------------------------------
	//profondeur de la cavité se situant sur la face Y == 0
	double _profondeurCavit1;

//----------------------------------------------------------------
	//profondeur de la cavité se situant sur la face Y == _epaisseur
	double _profondeurCavit2;

//----------------------------------------------------------------
	//largeur de la cavité
	double _largeurCavit;

//----------------------------------------------------------------
	//Hauteur des point de percage à partir de la base
	double _hauteurTrous;

//----------------------------------------------------------------
	//diametre des trous
	double _diametreTrous;

//----------------------------------------------------------------
	//ecartement des trous entre eux (la distance du centre est de _ecartementTrous/2)
	double _ecartementTrous;





//----------------------------------------------------------------
	//Droites3D du . Droite composé du Points3D position avec le vecteur Z du repere.
	Droites3D _axe;


private:
//*****************************************************************************
//						DOMAINE PRIVE
//*****************************************************************************
/*----------------------------------------------------------------
					METHODES
-----------------------------------------------------------------*/
	
	virtual void buildAll();	
/*	Méthode de construction du Support Vollant
	Le Support ainsi construit aura :
	    - la Hauteur  suivant  Z du repère
		- la Largeur  suivant  X du repère
		- la Epaisseur suivant Y du repère
		
*/
};

