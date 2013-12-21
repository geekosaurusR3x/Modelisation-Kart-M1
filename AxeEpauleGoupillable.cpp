/*
Création :				Christophe ELSENSOHN 
Date de création :		05/04/2012
Version :				0
Modifié par:			null
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
		- repere				(const Repere3D&)	: repère de l'axe épaulé goupillable.
														L'axe de l'axe épaulé goupillable 
														suivra le vecteur Z de ce repère

													origine se trouvant sur l'axe de l'axe
														épaulé goupillable. 
														Il se situe au centre de la face de
														jonction du petit diamètre et du grand diamètre.
		
		- petitDiametre			(double)			: diamètre du petit diamètre
		
		- longueurPetitDiametre (double)			: longueur du petit diamètre de l'extrémité
														jusqu'au plan de jonction avec le grand diamètre
		
		- grandDiametre			(double)			: diamètre du grand diamètre
		
		- longueurGrandDiametre	(double)			: longueur du grand diamètre de l'extrémité 
														jusqu'au plan de jonction avec le petit diamètre
		
		- coteCarre				(double)			: cote du carre contenant le trou de goupille.
		
		- longueurCarre			(double)			: Longueur d'extrusion du carré supportant le trou de goupille
		
		- diametreTrouGoupille	(double)			: diamètre du trou de goupille
		
		- distancePercage		(double)			: distance depuis la face extreme du carré pour 
														positionner le trou de goupille
		
		- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe épaulé goupillable.
														Représente la couleur de l'axe épaulé goupillable.

	#RECOMMANDATIONS
		Faire attention à ce que "petitDiametre" et "grandDiametre" soient différents.
		Dans le cas contraire, une Exception sera levée.

		Faire attention à ce que la diagonale du carré soit inférieure au petit diamètre.
		Dans le cas contraire, une Exception sera levée.
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
	//Rien à désallouer
}

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************
 
//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP extreme du carré

const FacesP& AxeEpauleGoupillable::faceExtremiteCarre() const
{
	return *_faceExtremeCarre;
}


//_____________________________________________________________________________
//
//	Getter du repère se trouvant la face de percage du trou de goupille
//	Le vecteur Z de ce repère pointe vers l'extérieur.
//	L'origine se trouve à l'intersection de la face de percage
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
//	Méthode de construction de AxeEpauleGoupillable
//	Elle fait suite à AxeEpaule::buildAll()
//	Cette méthode crée un Prisme qu'elle perce de part 
//	en part suivant l'axe Y du repère à _distPercage de sa face sommet
//	Ensuite elle le colle à l'extrémité de l'AxeEpaule originelle.

void AxeEpauleGoupillable::buildAll(){
	//Récupération du Vecteur Z du repère
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

	//Recupération de la face du Prisme à coller
	FacesP facePrismeAColler=prisme.faceBase();

	//Nombre de faces du Prisme percé
	int nbFacePrisme=prisme.NombreFaces();

	//On colle le prisme percé sur l'axeEpaule pour
	//obtenir notre AxeEpauleGoupillable
	bool res=Coller(prisme,faceAxeEpauleAColler,facePrismeAColler);	

	//Récupération du pointeur sur la face Extremum
	unsigned int N = NombreFaces () ;
	_faceExtremeCarre=&(TableauFaces()[N-1]);

	//Récupération du pointeur sur la face de percage
	_facePercage=&(TableauFaces()[N-2]);
	FacesP f=*_facePercage;
	f.ModifAttribut(&AttributsFaces(PMateriauJaune));
}

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

void AxeEpauleGoupillable::ControleValiditeArgConstruct()
{
	Vecteurs3D v(_coteCarre,_coteCarre,0);
	double norme=v.Norme();
	if(norme>=_petitRayon*2){
		throw exception("les cotés du carré sont plus grand que le diamètre du petit rayon. Rien ne pourra être monté sur cet axe Epaulé.");
	}

	if(_distPercage<=_rayonPercage){
		throw exception("Le positionnement du percage n'est pas cohérent. Le trou résultant déborderait de la pièce.");
	}

	if(_coteCarre<=_rayonPercage){
		throw exception("Le diamètre de percage est plus grand que le coté du carré dans lequel il doit être percé.");
	}

	if(_distPercage>(_lgCarre-_rayonPercage)){
		throw exception("Le positionnement du percage n'est pas cohérent. Le trou résultant sera dans le petit cylindre.");
	}
}
