/*
Cr�ation :				Christophe ELSENSOHN 
Date de cr�ation :		05/04/2012
Version :				0
Modifi� par:			null
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

	- position				(const Points3D&)	: point se trouvant sur l'axe de l'axe �paul�. 
													Il se situe au centre de la face de jonction 
													du petit diam�tre et du grand diam�tre.

	- repere				(const Repere3D&)	: rep�re de l'axe �paul�.
													L'axe de l'axe �paul� suivra le vecteur Z de
													ce rep�re

	- petitDiametre			(double)			: diam�tre du petit diam�tre

	- longueurPetitDiametre (double)			: longueur du petit diam�tre de l'extr�mit� 
													jusqu'au plan de jonction avec le grand diam�tre

	- grandDiametre			(double)			: diam�tre du grand diam�tre

	- longueurGrandDiametre	(double)			: longueur du grand diam�tre de l'extr�mit� 
													jusqu'au plan de jonction avec le petit diam�tre

	- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe �paul�.
													Repr�sente la couleur de l'axe �paul�.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- "petitDiametre" et "grandDiametre" sont �gaux.

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

	//V�rification des arguments fournis pour la construction
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
	//Rien � d�sallouer
}

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP de jointure entre les 2 diam�tres

const FacesP& AxeEpaule::faceJointure()const{
	return *_faceJointure;
}

//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP de  forme Disque extr�me du petit diam�tre

const FacesP& AxeEpaule::faceExtremitePetitDiam()const
{
	return *_faceDisquePetitDiam;
}

//_____________________________________________________________________________
//
//	Getter de la Droites3D de l'AxeEpaule.
//	Droites3D compos� de l'axe Z du rep�re et du Points3D position

Droites3D AxeEpaule::getAxe() const
{
	return Droites3D(_repere.Origine(),_repere.Z());
}

//_____________________________________________________________________________
//
//	Getter du Repere de la face de Jointure
//	L'axe Z du rep�re est orient� vers le Grand diam�tre. Son origine se trouve sur 
//	l'axe la pi�ce au niveau du plan de jointure "grand diam�tre" - "petit diam�tre"

Repere3D AxeEpaule::getRepereJointure()const
{
	//return Piece::getRepere3D();
	return Repere3D(_repere.Origine(),-_repere.X(),_repere.Y(),-_repere.Z());
		
}

//_____________________________________________________________________________
//
//	Getter du rep�re se trouvant sur la face circulaire extr�me du grand diam�tre
//	L'axe Z du rep�re est orient� vers l'ext�rieur.
//	Son origine se trouve sur l'axe la pi�ce au niveau de la face circulaire extreme du grand diam�tre

Repere3D AxeEpaule::getRepereFaceGrandDiametre() const
{
	return Repere3D(_repere.Origine()-_lgGrdDiam*_repere.Z(),_repere.X(),_repere.Y(),_repere.Z());
}

//_____________________________________________________________________________
//
//	Getter du rep�re se trouvant sur la face circulaire extr�me du petit diam�tre
//	L'axe Z du rep�re est orient� vers l'ext�rieur.
//	Son origine se trouve sur l'axe la pi�ce au niveau de la face circulaire extreme du petit diam�tre

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
//	M�thode de construction de AxeEpaule
//	Cette m�thode cr�e 2 Cylindres: 
//	- 1 pour le chapeau (grand diam�tre)
//	- 1 pour l'axe		(petit diam�tre).

//	Puis elle colle l'axe sur le chapeau.

void AxeEpaule::buildAll()
{

	//R�cup�ration du vecteur de "rotation" de l'axe �paul�
	Vecteurs3D& direction=_repere.Z();
	//Cr�ation du cylindre qui sera le chapeau de notre instance
	Cylindres chapeau(_repere.Origine(),_repere.Origine()-_lgGrdDiam*direction, _grdRayon, NULL, _attributFace);


	//On ajoute les faces du chapeau � notre collection de FacesP
	AjouterFaces ( chapeau.TableauFaces());

	//Cr�ation du cylindre qui sera l'"axe" de notre instance
	Cylindres axe(_repere.Origine(),_repere.Origine()+_lgPetitDiam*direction,_petitRayon, NULL, _attributFace);
	
	//R�cup�ration d'une r�f�rence sur la face � coller de axe pour le collage
	//La face � coller est la face 0. C'est la face supportant le point _position.
	//Elle poss�de aussi comme vecteur normal le vecteur contraire au vecteur {_position} vers
	//{_position+_lgPetitDiam*direction} par fourni � la construction du cylindre
	Tableaux<FacesP> facesAxe=axe.TableauFaces();
	FacesP& faceAxeAColler=facesAxe[0];

	//Conservation du nombre de face de l'axe pour pouvoir calculer 
	//l'index de la face "disque" extremit� ext�rieur de l'axe �paule que l'on cr�e
	int nbFacesAxe=axe.NombreFaces();
	
	
	//R�cup�ration d'une r�f�rence sur la face � coller de notre instance.
	//La face � coller est la face 0. C'est la face supportant le point _position.
	//Elle poss�de aussi comme vecteur normal le vecteur contraire au vecteur {_position} vers
	//{_position-_lgGrdDiam*direction} par fourni � la construction du cylindre
	Tableaux<FacesP> mesFaces =TableauFaces();
	FacesP& faceChapeauAColler=mesFaces[0];
	
	
	//Collage de l'axe sur notre piece courante qui repr�sente le chapeau
	bool res=Coller(axe,faceChapeauAColler,faceAxeAColler);	

	//R�cup�ration des pointeurs vers 
	//- la FacesP de jonction entre l'axe et le chapeau
	//- la FacesP , de forme disque, extreme de l'ancien axe
	 //mesFaces =TableauFaces();
	_faceJointure=&(TableauFaces()[0]);
	_faceDisquePetitDiam=&(TableauFaces()[NombreFaces()-nbFacesAxe+1]);

}


//_____________________________________________________________________________
//
//	M�thode de contr�le des arguments pass�s pour la construction de l'axe �paul�
//	Si le grand diam�tre est plus petit que le petit diam�tre, 
//	les valeurs sont invers�es comme suit:
//
//	petitRayon --> grandRayon
//	grandRayon --> petitRayon
//	longueurPetitDiam�tre --> longeurGrandDiam�tre
//	longeurGrandDiam�tre --> longueurPetitDiam�tre 

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- "petitDiametre" et "grandDiametre" sont �gaux.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

void AxeEpaule::ControleValiditeArgConstruct(){
	if(_petitRayon==_grdRayon)
		throw exception("les diam�tres de l'axe �paul� sont �gaux");

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
