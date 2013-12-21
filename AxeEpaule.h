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

class AxeEpaule: public Piece
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
//					Constructeur d'instance de AxeEpaule 

	AxeEpaule(const Repere3D& repere=Repere3D(),
			double petitDiametre=5, double longueurPetitDiametre=10, double grandDiametre=8,
			double longueurGrandDiametre=4,AttributsFacesP *PtAF=new AttributsFaces(PMateriauVert))throw(exception);
/*
PARAMETRES

	- position				(const Points3D&)	: point se trouvant sur l'axe de l'axe épaulé. 
													Il se situe au centre de la face de jonction 
													du petit diamètre et du grand diamètre.

	- repere				(const Repere3D&)	: repère de l'axe épaulé.
													L'axe de l'axe épaulé suivra le vecteur Z de
													ce repère

	- petitDiametre			(double)			: diamètre du petit diamètre

	- longueurPetitDiametre (double)			: longueur du petit diamètre de l'extrémité 
													jusqu'au plan de jonction avec le grand diamètre

	- grandDiametre			(double)			: diamètre du grand diamètre

	- longueurGrandDiametre	(double)			: longueur du grand diamètre de l'extrémité 
													jusqu'au plan de jonction avec le petit diamètre

	- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe épaulé.
													Représente la couleur de l'axe épaulé.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- "petitDiametre" et "grandDiametre" sont égaux.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/


//_____________________________________________________________________________
//
//					Constructeur par recopie de AxeEpaule 

	AxeEpaule(const AxeEpaule& axeEpaule);


//_____________________________________________________________________________
//
//					Destructeur de AxeEpaule 

	virtual ~AxeEpaule();
	

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************
	
//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP de forme Disque extrème du petit diamètre

	const FacesP& faceJointure()const;
	
//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP de forme Disque extrème du petit diamètre

	const FacesP& faceExtremitePetitDiam()const;

//_____________________________________________________________________________
//
//	Getter de la Droites3D de l'AxeEpaule.
//	Droites3D composé de l'axe Z du repère et du Points3D position

	Droites3D getAxe() const;

//_____________________________________________________________________________
//
//	Getter du Repere de la face de Jointure
//	L'axe Z du repère est orienté vers le Grand diamètre. Son origine se trouve sur 
//	l'axe la pièce au niveau du plan de jointure "grand diamètre" - "petit diamètre"

	Repere3D getRepereJointure()const;

//_____________________________________________________________________________
//
//	Getter du repère se trouvant sur la face circulaire extrème du grand diamètre
//	L'axe Z du repère est orienté vers l'extérieur.
//	Son origine se trouve sur l'axe la pièce au niveau de la face circulaire extreme du grand diamètre

	Repere3D getRepereFaceGrandDiametre() const;

//_____________________________________________________________________________
//
//	Getter du repère se trouvant sur la face circulaire extrème du petit diamètre
//	L'axe Z du repère est orienté vers l'extérieur.
//	Son origine se trouve sur l'axe la pièce au niveau de la face circulaire extreme du petit diamètre

	Repere3D getRepereFacePetitDiametre() const;


//#############################################################################
//								DOMAINE PROTECTED
//#############################################################################
protected:

//*****************************************************************************
//							DONNEES MEMBRES
//*****************************************************************************
//_____________________________________________________________________________
//
//	Rayon du petit diamètre

	double _petitRayon;

//_____________________________________________________________________________
//
//	Longueur du petit diamètre

	double _lgPetitDiam;

//_____________________________________________________________________________
//
//	Rayon du grand diamètre

	double _grdRayon;

//_____________________________________________________________________________
//
//	Longueur du grand diamètre

	double _lgGrdDiam;

//_____________________________________________________________________________
//
//	Pointeur sur la face disque du petit diamètre

	const FacesP* _faceDisquePetitDiam;

//_____________________________________________________________________________
//
//	Pointeur sur la face de jointure des 2 diamètres

	const FacesP* _faceJointure;


//#############################################################################
//								DOMAINE PRIVE
//#############################################################################
private:

//*****************************************************************************
//									METHODES
//*****************************************************************************
	
//_____________________________________________________________________________
//
//	Méthode de construction de AxeEpaule
//	Cette méthode crée 2 Cylindres: 1 pour le chapeau (grand diamètre) et un pour l'axe (petit diamètre).
//	Puis elle colle l'axe sur le chapeau.

	virtual void buildAll();

//_____________________________________________________________________________
//
//	Méthode de contrôle des arguments passés pour la construction de l'axe épaulé
//	Si le grand diamètre est plus petit que le petit diamètre, 
//	les valeurs sont inversées comme suit:
//
//	petitRayon --> grandRayon
//	grandRayon --> petitRayon
//	longueurPetitDiamètre --> longeurGrandDiamètre
//	longeurGrandDiamètre --> longueurPetitDiamètre 

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- "petitDiametre" et "grandDiametre" sont égaux.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
	virtual void ControleValiditeArgConstruct() throw (exception);
};

