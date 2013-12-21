/*
Création :				Christophe ELSENSOHN 
Date de création :		10/04/2012
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

class AxePiedColonneDirection:public Piece
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
//	Constructeur d'instance de AxePiedColonneDirection 

		AxePiedColonneDirection(const Repere3D& repere=Repere3D(),
			double diametre=5, double longueurDiametre=10,double coteCarre=2,
			double longueurCarre=5,AttributsFacesP *PtAF=&AttributsFaces(PMateriauVert))
			throw(exception);
/*
#PARAMETRES
		- repere				(const Repere3D&)	: repère de l'axe.
														L'axe de l'axe de révolution
														origine se trouvant sur l'axe de l'axe 
														Il se situe au centre de la face cylindrique.
		
		- Diametre				(double)			: diamètre
		
		- longueurDiametre		(double)			: longueur du cylindre 
		
		- coteCarre				(double)			: cote du carré.
		
		- longueurCarre			(double)			: Longueur d'extrusion du carré
		
		- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe épaulé goupillable.
														Représente la couleur de l'axe épaulé goupillable.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- la diagonale du carré est supérieure au diamètre.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

//_____________________________________________________________________________
//
//	Constructeur par recopie de AxePiedColonneDirection

		AxePiedColonneDirection(const AxePiedColonneDirection& axePiedColonneDirection);

//_____________________________________________________________________________
//
//	Destructeur de AxePiedColonneDirection

	virtual ~AxePiedColonneDirection(void);


//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter du repere sur la face carrée

	Repere3D getRepere3DOppose();

//_____________________________________________________________________________
//
//	Getter du repere sur la jointure

	Repere3D getRepere3DJointure();

//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP cylindrique du diamètre

	const FacesP& faceInferieur()const;


//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP de jonction entre le diamètre et le carré

	const FacesP& faceJonction()const;


//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP carré extreme

	const FacesP& faceCarre()const;
	
//_____________________________________________________________________________
//
//	Getter de la Droites3D de l'Axe.
//	Droites3D composé de l'axe Z du repère et du Points3D se trouvant sur la face opposé au carré

	Droites3D getAxe() const;


//#############################################################################
//								DOMAINE PROTECTED
//#############################################################################
protected:

//*****************************************************************************
//							DONNEES MEMBRES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Rayon du diamètre

	double _rayon;

//_____________________________________________________________________________
//
//	Longueur de la partie cylindrique

	double _lgDiametre;

//_____________________________________________________________________________
//
//	moitié du coté du carré

	double _demiCoteCarre;

//_____________________________________________________________________________
//
//	longueur d'extrusion du carré

	double _lgCarre;

//_____________________________________________________________________________
//
//	Pointeur sur la face cylindrique opposé au carré

	const FacesP* _faceInf;

//_____________________________________________________________________________
//
//	Pointeur sur la face de jonction cylindre carré

	const FacesP* _faceJonction;

//_____________________________________________________________________________
//
//	/Pointeur sur la face Extreme Carre

	const FacesP* _faceCarre;

//#############################################################################
//								DOMAINE PRIVE
//#############################################################################
private:

//*****************************************************************************
//									METHODES
//*****************************************************************************
	
//_____________________________________________________________________________
//
//	Méthode de construction de AxePiedColonneDirection
	
	virtual void buildAll();

//_____________________________________________________________________________
//
//	Méthode de controle des arguments passés pour la construction
	
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- la diagonale du carré est supérieure au diamètre.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
	virtual void ControleValiditeArgConstruct() throw (exception);
	
};

