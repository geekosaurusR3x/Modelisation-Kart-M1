#include "StdAfx.h"
#include "ArretTriangulaire.h"
#include "Prisme.h"
#include "OutilPercageCylindrique.h"
#include "Perceuse.h"

ArretTriangulaire::ArretTriangulaire(	const Repere3D& repere, 
										const double hauteurBase,
										const double angleTriangle,
										const double longueur,
										const double largeur,
										const double diametreEvidement, 
										const double ecart,
										const bool ecartDepuisCoteGauche,
										const double bordure,
										const double hauteurMax,
										const double pronfondeurEvidement,
										AttributsFacesP *attributFace)
				  :Piece(repere, attributFace)
{
	_hauteurBase = hauteurBase;
	_angleTriangle = angleTriangle;
	_longueur = longueur;
	_largeur = largeur;
	_diametreEvidement = diametreEvidement;
	_ecart = ecart;
	_ecartDepuisCoteGauche = ecartDepuisCoteGauche;
	_bordure = bordure;
	_hauteurMax = hauteurMax;
	_pronfondeurEvidement = pronfondeurEvidement;
	verifierArguments();
	buildAll();
}

ArretTriangulaire::~ArretTriangulaire(){

}

void ArretTriangulaire::verifierArguments(){
	if ( _diametreEvidement >= _largeur || _diametreEvidement >= _longueur )
		throw exception("Le diametre de l'evidement est trop grand par rapport aux dimensions de la pièce");

	if( _angleTriangle <0 || _angleTriangle >= PI/2 )
		throw exception("L'angle doit être exprimé en radian, entre 0 et PI/2 exclut!");
}

void ArretTriangulaire::buildAll(){

	
	// Calcul de la hauteur du triangle
	double hauteurTriangle = tan( _angleTriangle ) * _largeur;
	double hauteurArriereTotal = hauteurTriangle + _hauteurBase;

	// Initialisation du tableau de sommets
	Tableaux<SommetsP> sommets = Tableaux<SommetsP>(4, 1);
	Tableaux<SommetsP> sommets5 = Tableaux<SommetsP>(5, 1);

	// Point de la base
	Points3D pDevantBD = _repere.Origine() - _longueur / 2 * _repere.Y() - (_largeur / 2 + _bordure / 2) * _repere.X();
	Points3D pDevantBG = pDevantBD + _longueur * _repere.Y();
	Points3D pArriereBG = pDevantBG + (_largeur+_bordure) * _repere.X();
	Points3D pArriereBD = pDevantBD + (_largeur+_bordure) * _repere.X();

	// Point du triangle 
	Points3D pDevantTriHD = pDevantBD + _hauteurBase * _repere.Z();
	Points3D pDevantTriHG = pDevantBG + _hauteurBase * _repere.Z();
	Points3D pArriereTriHG = pDevantBG + _largeur * _repere.X() + hauteurArriereTotal * _repere.Z();
	Points3D pArriereTriHD = pDevantBD + _largeur * _repere.X() + hauteurArriereTotal * _repere.Z();

	// Base arriere
	Points3D pArriereHG = pArriereTriHG + _bordure * _repere.X();
	Points3D pArriereHD = pArriereTriHD + _bordure * _repere.X();

	// Définition des droites de test des limites aux bornes
	Droites3D limitZ(pDevantBG + _hauteurMax * _repere.Z(), pArriereBG + _hauteurMax * _repere.Z());
	Droites3D pente(pDevantTriHG, pArriereTriHG);

	Points3D intersection;
	bool memePlan;

	// Si une intersection existe, alors il fau
	if( limitZ.Intersection(pente, &intersection, &memePlan) ){
		if( !memePlan && abs(intersection.Z()) - abs(pArriereHG.Z()) < 0 ){

			// Modification en X
			pArriereTriHG.ModifX(intersection.X());
			pArriereTriHD.ModifX(intersection.X());

			// Modification en Z
			pArriereTriHG.ModifZ(intersection.Z());
			pArriereTriHD.ModifZ(intersection.Z());

			// et du point arriere
			pArriereHG.ModifZ(intersection.Z());
			pArriereHD.ModifZ(intersection.Z());

			//// Affectation de la nouvelle bordure
			// Peut être sauvegardé mais non utile pour le moment
			// Attention : Ne doit pas écraser la bordure de départ! Même si elle n'est pas en phase avec la modélisation!
			//_nouvellebordure = sqrt( ((pArriereTriHG.X()-pArriereHG.X()) * ((pArriereTriHG.X()-pArriereHG.X()) ))
			//				+((pArriereTriHG.Y()-pArriereHG.Y()) * ((pArriereTriHG.Y()-pArriereHG.Y()) ))
			//				+((pArriereTriHG.Z()-pArriereHG.Z()) * ((pArriereTriHG.Z()-pArriereHG.Z()) )));
		}
	}


	// Face dessous
	sommets[0] = SommetsP( pDevantBD ) ;
	sommets[1] = SommetsP( pDevantBG ) ;
	sommets[2] = SommetsP( pArriereBG ) ;
	sommets[3] = SommetsP( pArriereBD ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Face avant
	sommets[0] = SommetsP( pDevantBD ) ;
	sommets[1] = SommetsP( pDevantTriHD ) ;
	sommets[2] = SommetsP( pDevantTriHG ) ;
	sommets[3] = SommetsP( pDevantBG ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Face arriere
	sommets[0] = SommetsP( pArriereBD ) ;
	sommets[1] = SommetsP( pArriereBG ) ;
	sommets[2] = SommetsP( pArriereHG ) ;
	sommets[3] = SommetsP( pArriereHD ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Face gauche
	sommets5[0] = SommetsP( pDevantBG ) ;
	sommets5[1] = SommetsP( pDevantTriHG ) ;
	sommets5[2] = SommetsP( pArriereTriHG ) ;
	sommets5[3] = SommetsP( pArriereHG ) ;
	sommets5[4] = SommetsP( pArriereBG ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets5));

	// Face droite
	sommets5[0] = SommetsP( pDevantBD ) ;
	sommets5[1] = SommetsP( pArriereBD ) ;
	sommets5[2] = SommetsP( pArriereHD ) ;
	sommets5[3] = SommetsP( pArriereTriHD ) ;
	sommets5[4] = SommetsP( pDevantTriHD ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets5));

	// Face du dessus
	sommets[0] = SommetsP( pArriereTriHD ) ;
	sommets[1] = SommetsP( pArriereHD ) ;
	sommets[2] = SommetsP( pArriereHG ) ;
	sommets[3] = SommetsP( pArriereTriHG ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Couvercle
	sommets[0] = SommetsP( pDevantTriHG ) ;
	sommets[1] = SommetsP( pDevantTriHD ) ;
	sommets[2] = SommetsP( pArriereTriHD ) ;
	sommets[3] = SommetsP( pArriereTriHG ) ;
	_facePercee = ConstuireFacesDepuisSommets(sommets);
	AjouterFace( _facePercee );

	

	// Percage de l'evidement
	OutilPercageCylindrique outil = OutilPercageCylindrique(false, true, 32, _diametreEvidement/2, _pronfondeurEvidement);
	Repere3D repEvid = getRepere3DEvidement();
	Perceuse::percer(repEvid.Origine() + _pronfondeurEvidement * repEvid.Z(), *this, _facePercee, &outil);
}


Repere3D ArretTriangulaire::getRepere3DEvidement(){
	
	double hauteurNormalTriangle = tan( _angleTriangle ) * _largeur + _hauteurBase;

	// On récupere le point de devant, en haut, à droite
	double largeurTriangle = _largeur;
	double hauteurTriangle = hauteurNormalTriangle - _hauteurBase ;

	if( _hauteurMax < hauteurNormalTriangle){
		hauteurTriangle = _hauteurMax - _hauteurBase;
		largeurTriangle =  hauteurTriangle / tan( _angleTriangle );
	}

	Points3D pDevantHD = _repere.Origine() - _longueur / 2 * _repere.Y() - (_largeur / 2 + _bordure / 2)* _repere.X() + _hauteurBase * _repere.Z();
	Points3D pDevantHG = pDevantHD + _longueur * _repere.Y();

	// Calcul des ecarts depuis les points de repere
	pDevantHD = pDevantHD + _ecart * _repere.Y();
	pDevantHG = pDevantHG - _ecart * _repere.Y();

	// On calcul la position de l'évidement
	Points3D pEvidement = (_ecartDepuisCoteGauche?pDevantHG:pDevantHD) + hauteurTriangle/2 * _repere.Z() + (largeurTriangle / 2 ) * _repere.X();

	Repere3D nouvRep = Perceuse::getRepereDePercageDepuisFace(pEvidement, _facePercee);

	// On inverse le sens 
	Matrices4D matriceRotation;
	matriceRotation.DevenirRotationQuelconque (pEvidement, _repere.Y(), PI);

	// On rentre dans l'évidement
	nouvRep = Repere3D( pEvidement, nouvRep.X() * matriceRotation, nouvRep.Y() * matriceRotation, nouvRep.Z() * matriceRotation);
	nouvRep.ModifOrigine( nouvRep.Origine() - _pronfondeurEvidement * nouvRep.Z()) ;

	// On retourne le repere
	return nouvRep;

}