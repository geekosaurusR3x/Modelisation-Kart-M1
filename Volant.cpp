/*
Cr�ation :				Christophe ELSENSOHN 
Date de cr�ation :		05/04/2012
Version :				0
Modifi� par:			null
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
	- repere				(const Repere3D&)	: rep�re de Volant.
													L'axe de volant suivra le vecteur Z de
													ce rep�re
												  Origine se trouvant sur l'axe de r�volution. 
													Il se situe au centre de la face de jonction 
													du petit diam�tre et du grand diam�tre.

	- diametreDisque		(double)			: diam�tre du disque volant

	- epaisseurDisque		(double)			: Epaisseur du disque volant

	- diametreAxe			(double)			: dimension du petit diam�tre

	- longueurAxe			(double)			: longueur du petit diam�tre de l'extr�mit� 
													jusqu'au plan de jonction avec le disque volant

	- coteCreuCarre			(double)			: dimension du cot� du carr� d'entrainement

	- profondeurCreu		(double)			: profondeur du carr� d'entrainement
	
	- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe �paul�.
													Repr�sente la couleur de l'axe �paul�.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- "diametreAxe" et "diametreDisque" sont �gaux.
- la diagonale du carr� est plus grande que le diam�tre d'axe.
- la profondeur du creu est sup�rieur � la longueur totale du volant (axe + disque)

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
//	Getter du rep�re du carr� d'entrainement. Le vecteur Z du rep�re est VERS l'int�rieur du volant

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
//	M�thode de construction de Volant
//	Elle fait suite � AxeEpaule::buildAll()
//	Cette m�thode s'occupe de faire un trou 
//	borgne (non d�bouchant) carr� dont la profondeur suit l'axe du volant.

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
//	M�thode de contr�le des arguments pass�s pour la 
//	construction de Volant.
//	Elle fait suite � AxeEpaule::ControleValiditeArgConstruct()
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- la diagonale du carr� est plus grande que le diam�tre d'axe.
- la profondeur du creu est sup�rieur � la longueur totale du volant (axe + disque)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

void Volant::ControleValiditeArgConstruct(){
	if(_profCreu>=_lgPetitDiam+_lgGrdDiam){
		throw exception(
		"La profondeur du creu carr� est plus grande que la longueur totale de la pi�ce. Il n'y a plus de surface d'appui pour le volant.");
	}
	double demiCote=_coteCreu/2;
	Vecteurs3D v(demiCote,demiCote,0);
	if(v.Norme()>=_petitRayon){
		throw exception("La dimension du cot� du creu carr� n'est pas conforme avec le petit diam�tre. Le carr� n'est pas inclus dans le petit diam�tre.");
	}
}