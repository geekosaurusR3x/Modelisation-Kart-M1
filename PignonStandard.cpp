/*
Création :				Christophe ELSENSOHN 
Date de création :		10/04/2012
Version :				0
Modifié par:			null
Date de modification:	null
*/

#include "StdAfx.h"
#include "PignonStandard.h"
#include "Extrusions.h"
#include "Perceuse.h"
#include "OutilPercageRectangulaire.h"
#include "Utilitaire.h"

//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################

//*****************************************************************************
//						CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************

//_____________________________________________________________________________
//
//	
PignonStandard::PignonStandard(const Repere3D& repere,double module, double diametreTravail,double longueur,double coteCarre,AttributsFacesP *PtAF)
											:
											Piece(repere,PtAF),
											_module(module),
											_dPrimitif(diametreTravail),
											_longueur(longueur),
											_coteCarre(coteCarre)
{
	ControleValiditeArgConstruct();
	buildAll();
	
}

PignonStandard::PignonStandard(const PignonStandard& pignon):Piece(pignon),_module(pignon._module),_dPrimitif(pignon._dPrimitif),_longueur(pignon._longueur),
								_coteCarre(pignon._coteCarre),_nbDents(pignon._nbDents){
									buildAll();
}


PignonStandard::~PignonStandard(void)
{
}


//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter de la Droites3D du pignon représentant son axe de rotation

Droites3D PignonStandard::getAxe() const{
	return Droites3D(_repere.Origine(),_repere.Z());
}

//_____________________________________________________________________________
//
//	Getter de la dimension du diamètre primitif

double PignonStandard::getDiametrePrimitif() const{
	return _dPrimitif;
}

//_____________________________________________________________________________
//
//	Getter de la longueur du pignon

double PignonStandard::getLongueur()const{
	return _longueur;
}

//_____________________________________________________________________________
//
//	Getter du diamètre de tete du pignon

double PignonStandard::getDiametreTete() const{
	return _dPrimitif+2*_module;
}

//_____________________________________________________________________________
//
//	Getter du diamètre de pied du pignon

double PignonStandard::getDiametrePied() const{
	return _dPrimitif-2.5*_module;
}

//_____________________________________________________________________________
//
//	Getter du nombre de dents

double PignonStandard::getNombreDents() const{
	return _nbDents;
}

//_____________________________________________________________________________
//
//	Getter de la dimension du carré d'entrainement

double PignonStandard::getCoteCarre() const{
	return _coteCarre;
}

//_____________________________________________________________________________
//
//	Getter du module

double PignonStandard::getModule() const{
	return _module;
}

//_____________________________________________________________________________
//
//	Getter du repère de la face inférieure (coté Z- repere local)
//	Repère passant par une dent

Repere3D PignonStandard::getRepereFaceInf() const
{
	return Repere3D(_repere.Origine(),_repere.X(),-_repere.Y(),-_repere.Z());
}

//_____________________________________________________________________________
//
//	Getter du repère de la face supérieure (coté Z+ repere local)
//	Repère passant par une dent

Repere3D PignonStandard::getRepereFaceSup() const
{
	return Repere3D(_repere.Origine()+_longueur*_repere.Z(),_repere.X(),-_repere.Y(),-_repere.Z());
}


//#############################################################################
//								DOMAINE PRIVE
//#############################################################################

//*****************************************************************************
//									METHODES
//*****************************************************************************


//_____________________________________________________________________________
//
//	
void PignonStandard::buildAll(){
	
	//variables local.
	Points3D origine;
	Vecteurs3D x(1,0,0);
	Vecteurs3D y(0,1,0);
	Vecteurs3D z(0,0,1);

	//calcul de la longueur de l'arc entre 2 centres de dent
	double pas= PI*_module;
	
	//Calcul du diamètre de Tete (grand diamètre)
	double diamTete=_dPrimitif+2*_module;
	
	//Calcul du diamètre de pied (petit diamètre)
	double diamPied=_dPrimitif-2.5*_module;

	//Angle des flans de denture. 
	double angleDent=PI/9; //20°
	
	//Point de centre de denture sur le diamètre primitif
	Points3D ptCentreDentPrimitif(_dPrimitif/2,0,0);

	//Matrice de rotation du quart de pas
	double anglePas=2*pas/_dPrimitif;

	//Matrice de rotation d'un quart de pas pour les point de passage des flans
	//de denture
	Matrices4D rotZQuartPas;
	rotZQuartPas.DevenirRotationQuelconque(origine,z,anglePas/4);

	//Point de passage de la droite des flans de denture sur le diamètre primitif
	//= centre de denture * rotation du quart de pas en positif
	Points3D ptPassageFlanTrigo=ptCentreDentPrimitif*rotZQuartPas;

	
	//Droite des flans de denture
	Vecteurs3D vectFlan(-cos(angleDent),sin(angleDent),0);
	Droites3D flanTrigo(ptPassageFlanTrigo,vectFlan);
	Points3D pt2 = ptPassageFlanTrigo+10*vectFlan;


	//Calcul du point d'intersection entre la droite de flan et le diamètre de pied
	double pxi1,pyi1,pxi2,pyi2;
	int nbPoint;
	Utilitaire::IntersectionsDroiteCercle(ptPassageFlanTrigo.X(),ptPassageFlanTrigo.Y(),ptPassageFlanTrigo.X()-2,ptPassageFlanTrigo.Y(),0,0,diamPied/2,&nbPoint,&pxi1,&pyi1,&pxi2,&pyi2);
	Points3D ptIntersectionFlanPiedTrigo(pxi1,pyi1,0);

	//Calcul du point d'intersection entre la droite de flan et le diamètre de tête
	Utilitaire::IntersectionsDroiteCercle(ptPassageFlanTrigo.X(),ptPassageFlanTrigo.Y(),pt2.X(),pt2.Y(),0,0,diamTete/2,&nbPoint,&pxi1,&pyi1,&pxi2,&pyi2);
	Points3D ptIntersectionFlanTeteTrigo(pxi1,pyi1,0);
	
	//Matrice de rotation de symetrique les points symétriques de tete et de pied
	Matrices4D symYLocal;
	symYLocal.DevenirRotationQuelconque(origine,x,PI);

	//Point d'intersection symétrique à ptIntersectionFlanTeteTrigo
	Points3D ptIntersectionFlanTeteHoraire=ptIntersectionFlanTeteTrigo*symYLocal;

	
	//Point d'intersection symétrique à ptIntersectionFlanPiedTrigo
	Points3D ptIntersectionFlanPiedHoraire=ptIntersectionFlanPiedTrigo*symYLocal;

	//Tableau des points du profil
	Tableaux<Points3D> ptDenture(_nbDents*4,1);

	//Alimentation du profil avec les points de la première denture
	ptDenture[0]=ptIntersectionFlanPiedHoraire;
	ptDenture[1]=ptIntersectionFlanTeteHoraire;
	ptDenture[2]=ptIntersectionFlanTeteTrigo;
	ptDenture[3]=ptIntersectionFlanPiedTrigo;
	
	//Matrice de rotation d'un pas en positif (trigo)
	Matrices4D rotZPas;
	rotZPas.DevenirRotationQuelconque(origine,z,anglePas);

	
	//Alimentation du tableau de points du profil en prenant le point
	//à la case [courante -4] sur lequel on applique la rotation d'un pas
	for (unsigned int i =1;i<_nbDents;i++){
		for(unsigned int j=0;j<4;j++){
			Points3D p =ptDenture[4*(i-1)+j]*rotZPas;
			ptDenture[i*4+j]=ptDenture[4*(i-1)+j]*rotZPas;
		}
	}

	//Extrusion du profil suivant z local
	ptDenture.Inversion();
	Extrusions extrusion(Listes<Points3D>(ptDenture),_longueur*z,NULL,_attributFace);

	//Ajout des faces à notre objet
	AjouterFaces(extrusion.TableauFaces());
	
	//Récupération des Faces à percer
	unsigned int nbFaces=NombreFaces();
	FacesP faceAPercer =(TableauFaces()[nbFaces-2]);

	FacesP faceDebouchante =(TableauFaces()[nbFaces-1]);

	// Outils de percage
	OutilPercageRectangulaire outil = OutilPercageRectangulaire(false, false, _coteCarre, _coteCarre, _longueur);

	// Percage
	Repere3D rep(origine,x,y,z);
	Perceuse::percer(rep, *this,faceDebouchante ,faceAPercer,  &outil);

	//Calcul de la matrice de mise en position à l'endroit fourni à la construction
	Matrices4D orientationRepere;
	orientationRepere.DevenirChangementDeRepereMondeVersLocal(origine,_repere.X(),_repere.Y(),_repere.Z());
	Matrices4D translation;
	translation.DevenirTranslation(Vecteurs3D(_repere.Origine().X(),_repere.Origine().Y(),_repere.Origine().Z()));
	Matrices4D transformation=orientationRepere*translation;

	//Mise en place du pignon à l'endroit voulu
	Transformer(transformation);

}

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

void PignonStandard::ControleValiditeArgConstruct(){
	//Nombre de dents du pignon;
	_nbDents=_dPrimitif/_module;
	if(_nbDents*_module!=_dPrimitif){
		throw exception("Le nombre de dents n'est pas entier. Revoyer vos modules et diamètre primitif");
	}
	
	Vecteurs3D diaCarre(_coteCarre,_coteCarre,0);
	if(diaCarre.Norme()>getDiametrePied()){
		throw exception("Le carré d'entrainement est plus grand que le diamètre primitif");
	}
}
