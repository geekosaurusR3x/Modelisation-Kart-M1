/*
Création :				Christophe ELSENSOHN 
Date de création :		10/04/2012
Version :				1
Modifié par:			Christophe ELSENSOHN
Date de modification:	15/04/2012
*/
#pragma once
#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"
#include "Piece.h"
class PignonStandard:public Piece
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
//	Constructeur d'instance de PignonStandard 

	PignonStandard(const Repere3D& repere=Repere3D(),double module=1,
					double diametreTravail=1*6,double longueur=10,
					double coteCarre=2,AttributsFacesP *PtAF=&AttributsFaces(PMateriauBlanc)
				)throw(exception);
	
/*
PARAMETRES

	- repere			(const Repere3D&)	:	Repere du Pignon.
												Le vecteur Z fourni donnera le vecteur d'axe du pignon
												L'origine se trouve sur la face inférieure (Vecteur Normal = -Z fourni)
												sur l'axe de rotation

	- module			(double)			:	Ratio du pas à la dent
												//ATTENTION POUR QUE LE PIGNON ET LA CREMAILLERE PUISSENT
												//TRAVAILLER ENSEMBLE, IL FAUT QUE LEURS MODULES SOIENT
												//IDENTIQUES

	- diametreTravail	(double)			:	diamètre "primitif" du pignon.
												//ATTENTION
												//L'AXE DU PIGNON DOIT SE TROUVER A L'ALTITUDE DU PRIMITIF
												//DE LA CREMAILLERE + DIAMETRE PRIMITIF DU PIGNON

	- longueur			(double)			:	Longueur du pignon suivant son axe Z.

	_ PtAF		(AttributFacesP*)			:	couleur des faces.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- le rapport Diamètre primitif / module n'est pas entier 
		EXPLICATIONS: diamètre Primitif = module * Nombre de dents. Un nombre de dents à virgule, vous avez déjà vu ça.
		
- le carré d'entrainement est plus grand que le diamètre de fond de denture( = diamètre primitif - 2.5*_module)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
	

//_____________________________________________________________________________
//
//	Constructeur par recopie de PignonStandard

	PignonStandard(const PignonStandard& pignonStandard);


//_____________________________________________________________________________
//
//	Destructeur de PignonStandard

	virtual ~PignonStandard(void);

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter de la Droites3D du pignon représentant son axe de rotation

	Droites3D getAxe() const;

//_____________________________________________________________________________
//
//	Getter de la dimension du diamètre primitif

	double getDiametrePrimitif() const;

//_____________________________________________________________________________
//
//	Getter de la longueur du pignon

	double getLongueur()const;

//_____________________________________________________________________________
//
//	Getter du diamètre de tete du pignon

	double getDiametreTete() const;

//_____________________________________________________________________________
//
//	Getter du diamètre de pied du pignon

	double getDiametrePied() const;

//_____________________________________________________________________________
//
//	Getter du nombre de dents

	double getNombreDents() const;

//_____________________________________________________________________________
//
//	Getter de la dimension du carré d'entrainement

	double getCoteCarre() const;

//_____________________________________________________________________________
//
//	Getter du module

	double getModule() const;

//_____________________________________________________________________________
//
//	Getter du repère de la face inférieure (coté Z- repere local)
//	Repère passant par une dent

	Repere3D getRepereFaceInf() const;

//_____________________________________________________________________________
//
//	Getter du repère de la face supérieure (coté Z+ repere local)
//	Repère passant par une dent

	Repere3D getRepereFaceSup() const;


//#############################################################################
//								DOMAINE PROTECTED
//#############################################################################
protected:

//*****************************************************************************
//							DONNEES MEMBRES
//*****************************************************************************

//_____________________________________________________________________________
//
//	module du pignon

	double _module;

//_____________________________________________________________________________
//
//	diamètre primitif du pignon. (diamètre de travail)

	double _dPrimitif;

//_____________________________________________________________________________
//
//	longueur du pignon

	double _longueur;

//_____________________________________________________________________________
//
//	coté du carré d'encastrement

	double _coteCarre;

//_____________________________________________________________________________
//
//	Nombre de dents du pignon

	unsigned int _nbDents;


//#############################################################################
//								DOMAINE PRIVE
//#############################################################################
private:

//*****************************************************************************
//									METHODES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Méthode de construction du Pignon
//	Cette méthode crée 3 points (Points critiques de la denture)
//	Puis elle crée leurs mirroirs par rapport à l'axe centrale de la denture
//	Ensuite elle les reproduit à intervalle régulier pour obtenir toutes les dents
//	Cette liste de points est finalement extrudée suivant l'axe Z fourni à la construction

	virtual void buildAll();

//_____________________________________________________________________________
//
//	Méthode de contrôle des arguments passés pour la construction du pignon
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- le rapport Diamètre primitif / module n'est pas entier 
		EXPLICATIONS: diamètre Primitif = module * Nombre de dents. Un nombre de dents à virgule, vous avez déjà vu ça.
		
- le carré d'entrainement est plus grand que le diamètre de fond de denture( = diamètre primitif - 2.5*_module)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/	
	virtual void ControleValiditeArgConstruct() throw(exception);
};

