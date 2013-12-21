/*
Création :				Christophe ELSENSOHN 
Date de création :		05/04/2012
Version :				0
Modifié par:			null
Date de modification:	null
*/
#include "StdAfx.h"
#include "Volant.h"
#include "Matrices4D.h"
#include "Prisme.h"
#include "OutilPercageRectangulaire.h"
#include "Perceuse.h"

//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################

//*****************************************************************************
//						CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Constructeur d'instance de Volant 

/*
PARAMETRES
	- repere				(const Repere3D&)	: repère de Volant.
													L'axe de volant suivra le vecteur Z de
													ce repère
												  Origine se trouvant sur l'axe de révolution. 
													Il se situe au centre de la face de jonction 
													du petit diamètre et du grand diamètre.

	- diametreDisque		(double)			: diamètre du disque volant

	- epaisseurDisque		(double)			: Epaisseur du disque volant

	- diametreAxe			(double)			: dimension du petit diamètre

	- longueurAxe			(double)			: longueur du petit diamètre de l'extrémité 
													jusqu'au plan de jonction avec le disque volant

	- coteCreuCarre			(double)			: dimension du coté du carré d'entrainement

	- profondeurCreu		(double)			: profondeur du carré d'entrainement
	
	- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe épaulé.
													Représente la couleur de l'axe épaulé.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- "diametreAxe" et "diametreDisque" sont égaux.
- la diagonale du carré est plus grande que le diamètre d'axe.
- la profondeur du creu est supérieur à la longueur totale du volant (axe + disque)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
Volant::Volant(	const Repere3D& repere,double diametreDisque, double epaisseurDisque,double diametreAxe,
				double longueurAxe,double coteCreuCarre,double profondeurCreu,AttributsFacesP *PtAF):
					AxeEpaule(repere,diametreAxe,longueurAxe,diametreDisque,epaisseurDisque,PtAF),
					_coteCreu(coteCreuCarre),_profCreu(profondeurCreu)
{
	ControleValiditeArgConstruct();
	buildAll();
}


//_____________________________________________________________________________
//
//	Constructeur par recopie de Volant

	Volant::Volant(const Volant& volant):AxeEpaule(volant),_coteCreu(volant._coteCreu),_profCreu(volant._profCreu)
{
}

//_____________________________________________________________________________
//
//	Destructeur de Volant

Volant::~Volant(void)
{
}

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter du repère du carré d'entrainement. Le vecteur Z du repère est VERS l'intérieur du volant

Repere3D Volant::getRepere3D()const{
	Matrices4D matriceRotation;
	matriceRotation.DevenirRotationQuelconque (_repere.Origine(), _repere.X(), PI);

	Repere3D rep(_repere.Origine() - (_lgPetitDiam - _profCreu) * (_repere.Z() * matriceRotation), _repere.X() * matriceRotation, _repere.Y() * matriceRotation, _repere.Z() * matriceRotation);
	return rep;
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
//	Méthode de construction de Volant
//	Elle fait suite à AxeEpaule::buildAll()
//	Cette méthode s'occupe de faire un trou 
//	borgne (non débouchant) carré dont la profondeur suit l'axe du volant.

void Volant::buildAll(){
	Vecteurs3D z=_repere.Z();
	Vecteurs3D y=_repere.Y();
	Vecteurs3D zCreu=-z;
	
	Points3D PointPercage=_repere.Origine()+_lgPetitDiam*z;
	Repere3D repCreu(PointPercage, y&zCreu,y,zCreu);

	// Outil de percage
	OutilPercageRectangulaire outil1 = OutilPercageRectangulaire(false, true, _coteCreu, _coteCreu, _profCreu);

	// Percage
	FacesP face = *_faceDisquePetitDiam;
	Perceuse::percer(repCreu, *this, face, &outil1);

}


//_____________________________________________________________________________
//
//	Méthode de contrôle des arguments passés pour la 
//	construction de Volant.
//	Elle fait suite à AxeEpaule::ControleValiditeArgConstruct()
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- la diagonale du carré est plus grande que le diamètre d'axe.
- la profondeur du creu est supérieur à la longueur totale du volant (axe + disque)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

void Volant::ControleValiditeArgConstruct(){
	if(_profCreu>=_lgPetitDiam+_lgGrdDiam){
		throw exception(
		"La profondeur du creu carré est plus grande que la longueur totale de la pièce. Il n'y a plus de surface d'appui pour le volant.");
	}
	double demiCote=_coteCreu/2;
	Vecteurs3D v(demiCote,demiCote,0);
	if(v.Norme()>=_petitRayon){
		throw exception("La dimension du coté du creu carré n'est pas conforme avec le petit diamètre. Le carré n'est pas inclus dans le petit diamètre.");
	}
}