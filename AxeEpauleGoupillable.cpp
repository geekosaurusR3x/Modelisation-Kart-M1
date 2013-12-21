/*
Cr�ation :				Christophe ELSENSOHN 
Date de cr�ation :		05/04/2012
Version :				0
Modifi� par:			null
Date de modification:	null
*/
#include "StdAfx.h"
#include "AxeEpauleGoupillable.h"
#include "Prisme.h"
#include "OutilPercageCylindrique.h"
#include "Perceuse.h"

//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################

//*****************************************************************************
//						CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Constructeur d'instance de AxeEpauleGoupillable 

/*
#PARAMETRES
		- repere				(const Repere3D&)	: rep�re de l'axe �paul� goupillable.
														L'axe de l'axe �paul� goupillable 
														suivra le vecteur Z de ce rep�re

													origine se trouvant sur l'axe de l'axe
														�paul� goupillable. 
														Il se situe au centre de la face de
														jonction du petit diam�tre et du grand diam�tre.
		
		- petitDiametre			(double)			: diam�tre du petit diam�tre
		
		- longueurPetitDiametre (double)			: longueur du petit diam�tre de l'extr�mit�
														jusqu'au plan de jonction avec le grand diam�tre
		
		- grandDiametre			(double)			: diam�tre du grand diam�tre
		
		- longueurGrandDiametre	(double)			: longueur du grand diam�tre de l'extr�mit� 
														jusqu'au plan de jonction avec le petit diam�tre
		
		- coteCarre				(double)			: cote du carre contenant le trou de goupille.
		
		- longueurCarre			(double)			: Longueur d'extrusion du carr� supportant le trou de goupille
		
		- diametreTrouGoupille	(double)			: diam�tre du trou de goupille
		
		- distancePercage		(double)			: distance depuis la face extreme du carr� pour 
														positionner le trou de goupille
		
		- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe �paul� goupillable.
														Repr�sente la couleur de l'axe �paul� goupillable.

	#RECOMMANDATIONS
		Faire attention � ce que "petitDiametre" et "grandDiametre" soient diff�rents.
		Dans le cas contraire, une Exception sera lev�e.

		Faire attention � ce que la diagonale du carr� soit inf�rieure au petit diam�tre.
		Dans le cas contraire, une Exception sera lev�e.
*/
AxeEpauleGoupillable::AxeEpauleGoupillable(const Repere3D& repere, double petitDiametre,
						double longueurPetitDiametre, double grandDiametre, double longueurGrandDiametre,
						double coteCarre, double longueurCarre, double diametreTrouGoupille,double distancePercage,AttributsFacesP *PtAF)
							:AxeEpaule(repere,petitDiametre,longueurPetitDiametre,grandDiametre,longueurGrandDiametre,PtAF),
							_coteCarre(coteCarre),_lgCarre(longueurCarre),_rayonPercage(diametreTrouGoupille/2),_distPercage(distancePercage)
{
	ControleValiditeArgConstruct();
	buildAll();
}


//_____________________________________________________________________________
//
//	Constructeur par recopie de AxeEpauleGoupillable

AxeEpauleGoupillable::AxeEpauleGoupillable(const AxeEpauleGoupillable& axeEpauleGoupillable):
						AxeEpaule(axeEpauleGoupillable),_coteCarre(axeEpauleGoupillable._coteCarre),
						_lgCarre(axeEpauleGoupillable._lgCarre),_rayonPercage(axeEpauleGoupillable._rayonPercage),_distPercage(axeEpauleGoupillable._distPercage)
{
	buildAll();
}

//_____________________________________________________________________________
//
//	Destructeur de AxeEpauleGoupillable

AxeEpauleGoupillable::~AxeEpauleGoupillable()
{
	//Rien � d�sallouer
}

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************
 
//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP extreme du carr�

const FacesP& AxeEpauleGoupillable::faceExtremiteCarre() const
{
	return *_faceExtremeCarre;
}


//_____________________________________________________________________________
//
//	Getter du rep�re se trouvant la face de percage du trou de goupille
//	Le vecteur Z de ce rep�re pointe vers l'ext�rieur.
//	L'origine se trouve � l'intersection de la face de percage
//	et de l'axe de percage du trou

	Repere3D AxeEpauleGoupillable::getReperePercage()const
	{
		Vecteurs3D vPercage=_facePercage->VecteurNormal();
		Vecteurs3D y = _repere.Y();
		Vecteurs3D x = y&vPercage;
	
		return Repere3D(getPointPercage(),x,y,vPercage);
	}

//_____________________________________________________________________________
//
//	Getter du point de percage pour le trou de goupille

	Points3D AxeEpauleGoupillable::getPointPercage()const
	{
		return _repere.Origine()+(_lgPetitDiam+_lgCarre-_distPercage)*_repere.Z()+(_coteCarre/2)*_repere.X();
	}

//#############################################################################
//								DOMAINE PRIVE
//#############################################################################

//*****************************************************************************
//									METHODES
//*****************************************************************************


//_____________________________________________________________________________
//
//	M�thode de construction de AxeEpauleGoupillable
//	Elle fait suite � AxeEpaule::buildAll()
//	Cette m�thode cr�e un Prisme qu'elle perce de part 
//	en part suivant l'axe Y du rep�re � _distPercage de sa face sommet
//	Ensuite elle le colle � l'extr�mit� de l'AxeEpaule originelle.

void AxeEpauleGoupillable::buildAll(){
	//R�cup�ration du Vecteur Z du rep�re
	Vecteurs3D z=_repere.Z();
	Vecteurs3D x=_repere.X();

	FacesP faceAxeEpauleAColler=*_faceDisquePetitDiam;

	Repere3D rep(_repere);
	rep.ModifOrigine(_repere.Origine()+_lgPetitDiam*z);
	Prisme prisme(rep,_lgCarre,_coteCarre,_coteCarre,_attributFace);

	Tableaux<const FacesP*> tabPtr=prisme.flans();
	unsigned int i=1;
	FacesP flanAPercer=*(tabPtr[i]);
	FacesP flanDebouchant=*(tabPtr[i+2]);
	Points3D pointPercage=getPointPercage();//_repere.Origine()+(_lgPetitDiam+_lgCarre-_distPercage)*z+(_coteCarre/2)*x;
	
	//Nombre de faces pour le trou
	unsigned int nbFacesTrous=65;

	// Outil de percage
	OutilPercageCylindrique outil1 = OutilPercageCylindrique(false, false, nbFacesTrous, _rayonPercage, _coteCarre);

	// Percage
	Perceuse::percer(pointPercage, *this, flanAPercer, flanDebouchant, &outil1);

	//Recup�ration de la face du Prisme � coller
	FacesP facePrismeAColler=prisme.faceBase();

	//Nombre de faces du Prisme perc�
	int nbFacePrisme=prisme.NombreFaces();

	//On colle le prisme perc� sur l'axeEpaule pour
	//obtenir notre AxeEpauleGoupillable
	bool res=Coller(prisme,faceAxeEpauleAColler,facePrismeAColler);	

	//R�cup�ration du pointeur sur la face Extremum
	unsigned int N = NombreFaces () ;
	_faceExtremeCarre=&(TableauFaces()[N-1]);

	//R�cup�ration du pointeur sur la face de percage
	_facePercage=&(TableauFaces()[N-2]);
	FacesP f=*_facePercage;
	f.ModifAttribut(&AttributsFaces(PMateriauJaune));
}

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

void AxeEpauleGoupillable::ControleValiditeArgConstruct()
{
	Vecteurs3D v(_coteCarre,_coteCarre,0);
	double norme=v.Norme();
	if(norme>=_petitRayon*2){
		throw exception("les cot�s du carr� sont plus grand que le diam�tre du petit rayon. Rien ne pourra �tre mont� sur cet axe Epaul�.");
	}

	if(_distPercage<=_rayonPercage){
		throw exception("Le positionnement du percage n'est pas coh�rent. Le trou r�sultant d�borderait de la pi�ce.");
	}

	if(_coteCarre<=_rayonPercage){
		throw exception("Le diam�tre de percage est plus grand que le cot� du carr� dans lequel il doit �tre perc�.");
	}

	if(_distPercage>(_lgCarre-_rayonPercage)){
		throw exception("Le positionnement du percage n'est pas coh�rent. Le trou r�sultant sera dans le petit cylindre.");
	}
}
