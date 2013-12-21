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
		
	- repere				(const Repere3D&)	: repère de l'axe épaulé goupillable.
													L'axe de l'axe épaulé goupillable suivra le 
													vecteur Z de ce repère

												  Origine se trouvant sur l'axe de l'axe épaulé goupillable. 
													Il se situe au centre de la face de jonction du 
													petit diamètre et du grand diamètre.
		
	- petitDiametre			(double)			: diamètre du petit diamètre
		
	- longueurPetitDiametre (double)			: longueur du petit diamètre de l'extrémité jusqu'au 
													plan de jonction avec le grand diamètre
		
	- grandDiametre			(double)			: diamètre du grand diamètre
		
	- longueurGrandDiametre	(double)			: longueur du grand diamètre de l'extrémité jusqu'au
													plan de jonction avec le petit diamètre
		
	- coteCarre				(double)			: cote du carre contenant le trou de goupille.
		
	- longueurCarre			(double)			: Longueur d'extrusion du carré supportant le trou de goupille
		
	- diametreTrouGoupille	(double)			: diamètre du trou de goupille
		
	- distancePercage		(double)			: distance depuis la face extreme du carré pour 
													positionner le trou de goupille
		
	- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe épaulé goupillable. 
													Représente la couleur de l'axe épaulé goupillable.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- "petitDiametre" et "grandDiametre" sont égaux.
- la diagonale du carré est supérieure au petit diamètre.
- Le positionnement du trou est inférieur au diamètre de percage

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
//	Getter de la référence sur la FacesP extreme du carré

	const FacesP& faceExtremiteCarre()const;

//_____________________________________________________________________________
//
//	Getter du repère se trouvant sur la face de jointure entre le petit diamètre
//	et le carré.
//	Le vecteur Z de ce repère pointe vers le carré. L'origine se trouve sur l'axe
//	de révolution.

	Repere3D getRepereJointureCarre()const;

//_____________________________________________________________________________
//
//	Getter du repère se trouvant la face de percage du trou de goupille
//	Le vecteur Z de ce repère pointe vers l'extérieur.
//	L'origine se trouve à l'intersection de la face de percage
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
//	Dimension du cote du carré qui sera percé pour recevoir la goupille

	double _coteCarre;

//_____________________________________________________________________________
//
//	Longueur d'extrusion du carré

	double _lgCarre;

//_____________________________________________________________________________
//
//	rayon du trou de goupille

	double _rayonPercage;

//_____________________________________________________________________________
//
//	distance entre le point de percage et la face extreme extérieur du carré de percage.
//	Distance suivant l'axe Z de la pièce.

	double _distPercage;

//_____________________________________________________________________________
//
//	pointeur sur la face extreme du carré de percage suivant l'axe Z de la pièce.

	const FacesP* _faceExtremeCarre;

//_____________________________________________________________________________
//
//	pointeur sur la face de percage du carré

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
//	Méthode de construction de AxeEpauleGoupillable
//	Elle fait suite à AxeEpaule::buildAll()
//	Cette méthode crée un Prisme qu'elle perce de part en part suivant l'axe Y du repère à _distPercage de sa face sommet
//	Ensuite elle le colle à l'extrémité de l'AxeEpaule originelle.

	virtual void buildAll();

//_____________________________________________________________________________
//
//	Méthode de contrôle des arguments passés pour la construction de l'axe épaulé goupillable
//	Elle fait suite à AxeEpaule::ControleValiditeArgConstruct()
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- "petitDiametre" et "grandDiametre" sont égaux.
- la diagonale du carré est supérieure au petit diamètre.
- Le positionnement du trou est inférieur au diamètre de percage

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

