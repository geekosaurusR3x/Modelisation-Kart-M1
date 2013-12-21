/*
Cr�ation :				Christophe ELSENSOHN 
Date de cr�ation :		10/04/2012
Version :				1
Modifi� par:			Christophe ELSENSOHN
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
												L'origine se trouve sur la face inf�rieure (Vecteur Normal = -Z fourni)
												sur l'axe de rotation

	- module			(double)			:	Ratio du pas � la dent
												//ATTENTION POUR QUE LE PIGNON ET LA CREMAILLERE PUISSENT
												//TRAVAILLER ENSEMBLE, IL FAUT QUE LEURS MODULES SOIENT
												//IDENTIQUES

	- diametreTravail	(double)			:	diam�tre "primitif" du pignon.
												//ATTENTION
												//L'AXE DU PIGNON DOIT SE TROUVER A L'ALTITUDE DU PRIMITIF
												//DE LA CREMAILLERE + DIAMETRE PRIMITIF DU PIGNON

	- longueur			(double)			:	Longueur du pignon suivant son axe Z.

	_ PtAF		(AttributFacesP*)			:	couleur des faces.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- le rapport Diam�tre primitif / module n'est pas entier 
		EXPLICATIONS: diam�tre Primitif = module * Nombre de dents. Un nombre de dents � virgule, vous avez d�j� vu �a.
		
- le carr� d'entrainement est plus grand que le diam�tre de fond de denture( = diam�tre primitif - 2.5*_module)

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
//	Getter de la Droites3D du pignon repr�sentant son axe de rotation

	Droites3D getAxe() const;

//_____________________________________________________________________________
//
//	Getter de la dimension du diam�tre primitif

	double getDiametrePrimitif() const;

//_____________________________________________________________________________
//
//	Getter de la longueur du pignon

	double getLongueur()const;

//_____________________________________________________________________________
//
//	Getter du diam�tre de tete du pignon

	double getDiametreTete() const;

//_____________________________________________________________________________
//
//	Getter du diam�tre de pied du pignon

	double getDiametrePied() const;

//_____________________________________________________________________________
//
//	Getter du nombre de dents

	double getNombreDents() const;

//_____________________________________________________________________________
//
//	Getter de la dimension du carr� d'entrainement

	double getCoteCarre() const;

//_____________________________________________________________________________
//
//	Getter du module

	double getModule() const;

//_____________________________________________________________________________
//
//	Getter du rep�re de la face inf�rieure (cot� Z- repere local)
//	Rep�re passant par une dent

	Repere3D getRepereFaceInf() const;

//_____________________________________________________________________________
//
//	Getter du rep�re de la face sup�rieure (cot� Z+ repere local)
//	Rep�re passant par une dent

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
//	diam�tre primitif du pignon. (diam�tre de travail)

	double _dPrimitif;

//_____________________________________________________________________________
//
//	longueur du pignon

	double _longueur;

//_____________________________________________________________________________
//
//	cot� du carr� d'encastrement

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
//	M�thode de construction du Pignon
//	Cette m�thode cr�e 3 points (Points critiques de la denture)
//	Puis elle cr�e leurs mirroirs par rapport � l'axe centrale de la denture
//	Ensuite elle les reproduit � intervalle r�gulier pour obtenir toutes les dents
//	Cette liste de points est finalement extrud�e suivant l'axe Z fourni � la construction

	virtual void buildAll();

//_____________________________________________________________________________
//
//	M�thode de contr�le des arguments pass�s pour la construction du pignon
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- le rapport Diam�tre primitif / module n'est pas entier 
		EXPLICATIONS: diam�tre Primitif = module * Nombre de dents. Un nombre de dents � virgule, vous avez d�j� vu �a.
		
- le carr� d'entrainement est plus grand que le diam�tre de fond de denture( = diam�tre primitif - 2.5*_module)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/	
	virtual void ControleValiditeArgConstruct() throw(exception);
};

