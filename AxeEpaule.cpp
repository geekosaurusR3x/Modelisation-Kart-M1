/*
Création :				Christophe ELSENSOHN 
Date de création :		05/04/2012
Version :				0
Modifié par:			null
Date de modification:	null
*/
#include "StdAfx.h"
#include "AxeEpaule.h"
#include "AttributsSolidesP.h"
#include "primitives.h"

//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################

//*****************************************************************************
//						CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Constructeur d'instance de AxeEpaule 

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

AxeEpaule::AxeEpaule( const Repere3D& repere,
					double petitDiametre, double longueurPetitDiametre,
					double grandDiametre,	double longueurGrandDiametre,
						AttributsFacesP *PtAF)
					:
					Piece(repere,PtAF), _petitRayon(petitDiametre/2),
					_lgPetitDiam(longueurPetitDiametre), _grdRayon(grandDiametre/2), 
					_lgGrdDiam(longueurGrandDiametre)
{

	//Vérification des arguments fournis pour la construction
	ControleValiditeArgConstruct();

	//Construction de l'objet
	buildAll();
}

//_____________________________________________________________________________
//
//	Constructeur par recopie de AxeEpaule

AxeEpaule::AxeEpaule(const AxeEpaule& axeEpaule)
					:Piece(axeEpaule),
					_petitRayon(axeEpaule._grdRayon),
					_lgPetitDiam(axeEpaule._lgPetitDiam),
					_grdRayon(axeEpaule._grdRayon),
					_lgGrdDiam(axeEpaule._lgGrdDiam),
					_faceJointure(axeEpaule._faceJointure)
{
	buildAll();
}

//_____________________________________________________________________________
//
//	Destructeur de AxeEpaule

AxeEpaule::~AxeEpaule()
{
	//Rien à désallouer
}

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP de jointure entre les 2 diamètres

const FacesP& AxeEpaule::faceJointure()const{
	return *_faceJointure;
}

//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP de  forme Disque extrème du petit diamètre

const FacesP& AxeEpaule::faceExtremitePetitDiam()const
{
	return *_faceDisquePetitDiam;
}

//_____________________________________________________________________________
//
//	Getter de la Droites3D de l'AxeEpaule.
//	Droites3D composé de l'axe Z du repère et du Points3D position

Droites3D AxeEpaule::getAxe() const
{
	return Droites3D(_repere.Origine(),_repere.Z());
}

//_____________________________________________________________________________
//
//	Getter du Repere de la face de Jointure
//	L'axe Z du repère est orienté vers le Grand diamètre. Son origine se trouve sur 
//	l'axe la pièce au niveau du plan de jointure "grand diamètre" - "petit diamètre"

Repere3D AxeEpaule::getRepereJointure()const
{
	//return Piece::getRepere3D();
	return Repere3D(_repere.Origine(),-_repere.X(),_repere.Y(),-_repere.Z());
		
}

//_____________________________________________________________________________
//
//	Getter du repère se trouvant sur la face circulaire extrème du grand diamètre
//	L'axe Z du repère est orienté vers l'extérieur.
//	Son origine se trouve sur l'axe la pièce au niveau de la face circulaire extreme du grand diamètre

Repere3D AxeEpaule::getRepereFaceGrandDiametre() const
{
	return Repere3D(_repere.Origine()-_lgGrdDiam*_repere.Z(),_repere.X(),_repere.Y(),_repere.Z());
}

//_____________________________________________________________________________
//
//	Getter du repère se trouvant sur la face circulaire extrème du petit diamètre
//	L'axe Z du repère est orienté vers l'extérieur.
//	Son origine se trouve sur l'axe la pièce au niveau de la face circulaire extreme du petit diamètre

Repere3D AxeEpaule::getRepereFacePetitDiametre() const
{
	return Repere3D(_repere.Origine()+_lgPetitDiam*_repere.Z(),_repere.X(),-_repere.Y(),-_repere.Z());
}


//#############################################################################
//								DOMAINE PRIVE
//#############################################################################

//*****************************************************************************
//									METHODES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Méthode de construction de AxeEpaule
//	Cette méthode crée 2 Cylindres: 
//	- 1 pour le chapeau (grand diamètre)
//	- 1 pour l'axe		(petit diamètre).

//	Puis elle colle l'axe sur le chapeau.

void AxeEpaule::buildAll()
{

	//Récupération du vecteur de "rotation" de l'axe épaulé
	Vecteurs3D& direction=_repere.Z();
	//Création du cylindre qui sera le chapeau de notre instance
	Cylindres chapeau(_repere.Origine(),_repere.Origine()-_lgGrdDiam*direction, _grdRayon, NULL, _attributFace);


	//On ajoute les faces du chapeau à notre collection de FacesP
	AjouterFaces ( chapeau.TableauFaces());

	//Création du cylindre qui sera l'"axe" de notre instance
	Cylindres axe(_repere.Origine(),_repere.Origine()+_lgPetitDiam*direction,_petitRayon, NULL, _attributFace);
	
	//Récupération d'une référence sur la face à coller de axe pour le collage
	//La face à coller est la face 0. C'est la face supportant le point _position.
	//Elle possède aussi comme vecteur normal le vecteur contraire au vecteur {_position} vers
	//{_position+_lgPetitDiam*direction} par fourni à la construction du cylindre
	Tableaux<FacesP> facesAxe=axe.TableauFaces();
	FacesP& faceAxeAColler=facesAxe[0];

	//Conservation du nombre de face de l'axe pour pouvoir calculer 
	//l'index de la face "disque" extremité extérieur de l'axe épaule que l'on crée
	int nbFacesAxe=axe.NombreFaces();
	
	
	//Récupération d'une référence sur la face à coller de notre instance.
	//La face à coller est la face 0. C'est la face supportant le point _position.
	//Elle possède aussi comme vecteur normal le vecteur contraire au vecteur {_position} vers
	//{_position-_lgGrdDiam*direction} par fourni à la construction du cylindre
	Tableaux<FacesP> mesFaces =TableauFaces();
	FacesP& faceChapeauAColler=mesFaces[0];
	
	
	//Collage de l'axe sur notre piece courante qui représente le chapeau
	bool res=Coller(axe,faceChapeauAColler,faceAxeAColler);	

	//Récupération des pointeurs vers 
	//- la FacesP de jonction entre l'axe et le chapeau
	//- la FacesP , de forme disque, extreme de l'ancien axe
	 //mesFaces =TableauFaces();
	_faceJointure=&(TableauFaces()[0]);
	_faceDisquePetitDiam=&(TableauFaces()[NombreFaces()-nbFacesAxe+1]);

}


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

void AxeEpaule::ControleValiditeArgConstruct(){
	if(_petitRayon==_grdRayon)
		throw exception("les diamètres de l'axe épaulé sont égaux");

	if(_petitRayon>_grdRayon){

		//Inversion des rayons
		double temp=_petitRayon;
		_petitRayon=_grdRayon;
		_grdRayon=temp;

		//inversion des longueurs
		temp=_lgPetitDiam;
		_lgPetitDiam=_lgGrdDiam;
		_lgGrdDiam=temp;
	}
}
