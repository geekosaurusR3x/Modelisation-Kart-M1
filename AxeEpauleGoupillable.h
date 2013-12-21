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
#include "AxeEpaule.h"
class AxeEpauleGoupillable:public AxeEpaule
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
//	Constructeur d'instance de AxeEpauleGoupillable

	AxeEpauleGoupillable(const Repere3D& repere=Repere3D(), double petitDiametre=10,
		double longueurPetitDiametre=20, double grandDiametre=14,
		double longueurGrandDiametre=5,double coteCarre=6,
		double longueurCarre=8,double diametreTrouGoupille=4,
		double distancePercage=4,AttributsFacesP *PtAF=new AttributsFaces(PMateriauBleu))
		throw(exception);
/*
PARAMETRES
		
	- repere				(const Repere3D&)	: rep�re de l'axe �paul� goupillable.
													L'axe de l'axe �paul� goupillable suivra le 
													vecteur Z de ce rep�re

												  Origine se trouvant sur l'axe de l'axe �paul� goupillable. 
													Il se situe au centre de la face de jonction du 
													petit diam�tre et du grand diam�tre.
		
	- petitDiametre			(double)			: diam�tre du petit diam�tre
		
	- longueurPetitDiametre (double)			: longueur du petit diam�tre de l'extr�mit� jusqu'au 
													plan de jonction avec le grand diam�tre
		
	- grandDiametre			(double)			: diam�tre du grand diam�tre
		
	- longueurGrandDiametre	(double)			: longueur du grand diam�tre de l'extr�mit� jusqu'au
													plan de jonction avec le petit diam�tre
		
	- coteCarre				(double)			: cote du carre contenant le trou de goupille.
		
	- longueurCarre			(double)			: Longueur d'extrusion du carr� supportant le trou de goupille
		
	- diametreTrouGoupille	(double)			: diam�tre du trou de goupille
		
	- distancePercage		(double)			: distance depuis la face extreme du carr� pour 
													positionner le trou de goupille
		
	- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe �paul� goupillable. 
													Repr�sente la couleur de l'axe �paul� goupillable.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- "petitDiametre" et "grandDiametre" sont �gaux.
- la diagonale du carr� est sup�rieure au petit diam�tre.
- Le positionnement du trou est inf�rieur au diam�tre de percage

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
	
//_____________________________________________________________________________
//
//	Constructeur par recopie de AxeEpauleGoupillable

	AxeEpauleGoupillable(const AxeEpauleGoupillable& axeEpauleGoupillable);

//_____________________________________________________________________________
//
//	Destructeur de AxeEpauleGoupillable

	virtual ~AxeEpauleGoupillable(void);


//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP extreme du carr�

	const FacesP& faceExtremiteCarre()const;

//_____________________________________________________________________________
//
//	Getter du rep�re se trouvant sur la face de jointure entre le petit diam�tre
//	et le carr�.
//	Le vecteur Z de ce rep�re pointe vers le carr�. L'origine se trouve sur l'axe
//	de r�volution.

	Repere3D getRepereJointureCarre()const;

//_____________________________________________________________________________
//
//	Getter du rep�re se trouvant la face de percage du trou de goupille
//	Le vecteur Z de ce rep�re pointe vers l'ext�rieur.
//	L'origine se trouve � l'intersection de la face de percage
//	et de l'axe de percage du trou

	Repere3D getReperePercage()const;


//#############################################################################
//								DOMAINE PROTECTED
//#############################################################################
protected:
	
//*****************************************************************************
//							DONNEES MEMBRES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Dimension du cote du carr� qui sera perc� pour recevoir la goupille

	double _coteCarre;

//_____________________________________________________________________________
//
//	Longueur d'extrusion du carr�

	double _lgCarre;

//_____________________________________________________________________________
//
//	rayon du trou de goupille

	double _rayonPercage;

//_____________________________________________________________________________
//
//	distance entre le point de percage et la face extreme ext�rieur du carr� de percage.
//	Distance suivant l'axe Z de la pi�ce.

	double _distPercage;

//_____________________________________________________________________________
//
//	pointeur sur la face extreme du carr� de percage suivant l'axe Z de la pi�ce.

	const FacesP* _faceExtremeCarre;

//_____________________________________________________________________________
//
//	pointeur sur la face de percage du carr�

	const FacesP* _facePercage;

//#############################################################################
//								DOMAINE PRIVE
//#############################################################################
private:

//*****************************************************************************
//									METHODES
//*****************************************************************************
	
//_____________________________________________________________________________
//
//	M�thode de construction de AxeEpauleGoupillable
//	Elle fait suite � AxeEpaule::buildAll()
//	Cette m�thode cr�e un Prisme qu'elle perce de part en part suivant l'axe Y du rep�re � _distPercage de sa face sommet
//	Ensuite elle le colle � l'extr�mit� de l'AxeEpaule originelle.

	virtual void buildAll();

//_____________________________________________________________________________
//
//	M�thode de contr�le des arguments pass�s pour la construction de l'axe �paul� goupillable
//	Elle fait suite � AxeEpaule::ControleValiditeArgConstruct()
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- "petitDiametre" et "grandDiametre" sont �gaux.
- la diagonale du carr� est sup�rieure au petit diam�tre.
- Le positionnement du trou est inf�rieur au diam�tre de percage

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
	virtual void ControleValiditeArgConstruct() throw (exception);


//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter du point de percage pour le trou de goupille

	Points3D getPointPercage()const;
};

