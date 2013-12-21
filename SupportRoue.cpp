#include "StdAfx.h"
#include "SupportRoue.h"
#include "OutilPercageCylindrique.h"
#include "Perceuse.h"

SupportRoue::SupportRoue(	const Repere3D& repere, 
							const double largeurBaseFixationChassis,
							const double largeurBaseSupport,
							const double longueurBase,
							const double epaisseurBase,
							const double epaisseurSupport,
							const double hauteurSupport,
							const double diametreFixationChassis,
							const double ecartFixationChassis,
							const double diametreFixationRoue,
							const double diametreFixationBielle,
							const double ecartFicationBielle,
							const bool gauche,
							AttributsFacesP *attributFace)
		:Piece(repere, attributFace)
{
	// Copie des paramètres
	_largeurBaseFixationChassis = largeurBaseFixationChassis;
	_largeurBaseSupport = largeurBaseSupport;
	_epaisseurBase = epaisseurBase;
	_hauteurSupport = hauteurSupport;
	_diametreFixationChassis = diametreFixationChassis;
	_ecartFixationChassis = diametreFixationChassis;
	_diametreFixationRoue = diametreFixationRoue;
	_diametreFixationBielle = diametreFixationBielle;
	_ecartFicationBielle = ecartFicationBielle;
	_longueurBase = longueurBase;
	_epaisseurSupport = epaisseurSupport;
	_gauche = gauche;
	verifierArguments();
	buildAll();
}

SupportRoue::~SupportRoue()
{
}

void SupportRoue::verifierArguments(){

	// Largeur de la base <=> Largeur du support
	if( _largeurBaseFixationChassis >= _largeurBaseSupport )
		throw exception("La largeur de la base de fixation du chassis doit être strictement inférieur à la largeur du support lui même!");

	if( _ecartFixationChassis + _diametreFixationChassis >= _longueurBase )
		throw exception("L'ecart entre la face avant de la base et la fixation du chassis ainsi que son diametre ne peut pas être plus grand que la longueur de la base!");

	if(_ecartFicationBielle + _diametreFixationBielle >= _largeurBaseSupport)
		throw exception("L'ecart entre la face de coté du support et la fixation de la bielle ainsi que son diametre ne peut pas être plus grand que la largeur du support!");

	if( _diametreFixationRoue >= _largeurBaseSupport || _diametreFixationRoue >= _hauteurSupport )
		throw exception("Le diametre de la fixation de la roue est trop grand par rapport à la hauteur du support ou à la largeur de celui-ci!");

	if( _diametreFixationBielle >= _epaisseurSupport )
		throw exception("Le diametre de fixation de la bielle ne peut être plus grand que l'epaisseur du support qui le contient!");

	if( _diametreFixationChassis >= _largeurBaseFixationChassis )
		throw exception("Le diametre de fixation du chassis ne peut être plus grand que l'epaisseur de la base de fixation au chassis!");
}

void SupportRoue::buildAll(){

	// Création des tableaux de sommets
	Tableaux<SommetsP> sommets = Tableaux<SommetsP>(4, 1);

	// Point d'origine : Centre de la fixation du chassis
	Points3D pOrigine = _repere.Origine();
	Vecteurs3D x = _repere.X();
	Vecteurs3D y = _repere.Y();
	Vecteurs3D z = _repere.Z();

	// Calcul des points de références de la face avant de la base
	Points3D pAvantGHBase = pOrigine - _ecartFixationChassis * x + ( _largeurBaseFixationChassis / 2 ) * y;
	Points3D pAvantGBBase = pAvantGHBase - _epaisseurBase * z;
	Points3D pAvantDBBase = pAvantGBBase - _largeurBaseFixationChassis * y;
	Points3D pAvantDHBase = pAvantDBBase + _epaisseurBase * z;

	// Calcul des points de références de la face arriere de la base
	Points3D pArriereGHBase = pAvantGHBase + _longueurBase * x + ( ( _largeurBaseSupport - _largeurBaseFixationChassis ) / 2 ) * y;
	Points3D pArriereGBBase = pArriereGHBase - _epaisseurBase * z;
	Points3D pArriereDBBase = pArriereGBBase - _largeurBaseSupport * y;
	Points3D pArriereDHBase = pArriereDBBase + _epaisseurBase * z;

	// Calcul des points de références de la face arriere du support de roue
	Points3D pArriereGBSupport = pArriereGBBase + _epaisseurSupport * x;
	Points3D pArriereGHSupport = pArriereGBSupport + ( _hauteurSupport + _epaisseurBase ) * z;
	Points3D pArriereDHSupport = pArriereGHSupport - _largeurBaseSupport * y;
	Points3D pArriereDBSupport = pArriereDHSupport - ( _hauteurSupport + _epaisseurBase ) * z;

	// Calcul des points de références de la face avant du support de roue
	Points3D pAvantGHSupport = pArriereGHBase + _hauteurSupport * z;
	Points3D pAvantDHSupport = pArriereDHBase + _hauteurSupport * z;

	// Calcul des points des trous
	double ecartBielle = _gauche ? _largeurBaseSupport - _ecartFicationBielle:_ecartFicationBielle ;

	Points3D pFixationBielle = pAvantDHSupport + ( _epaisseurSupport/2 ) * x + ecartBielle * y;
	Points3D pFixationRoue = pOrigine + ( _longueurBase - _ecartFixationChassis ) * x + ( _hauteurSupport / 2 ) * z;

	// Génération des sommets pour la base : Face avant
	sommets[0] = SommetsP( pAvantGHBase ) ;
	sommets[1] = SommetsP( pAvantGBBase ) ;
	sommets[2] = SommetsP( pAvantDBBase ) ;
	sommets[3] = SommetsP( pAvantDHBase ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la base : Face de coté
	sommets[0] = SommetsP( pAvantGHBase ) ;
	sommets[1] = SommetsP( pArriereGHBase ) ;
	sommets[2] = SommetsP( pArriereGBBase ) ;
	sommets[3] = SommetsP( pAvantGBBase ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la base : Face de coté
	sommets[0] = SommetsP( pArriereDHBase ) ;
	sommets[1] = SommetsP( pAvantDHBase ) ;
	sommets[2] = SommetsP( pAvantDBBase ) ;
	sommets[3] = SommetsP( pArriereDBBase ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la base : Face du dessus
	sommets[0] = SommetsP( pAvantGHBase ) ;
	sommets[1] = SommetsP( pAvantDHBase ) ;
	sommets[2] = SommetsP( pArriereDHBase ) ;
	sommets[3] = SommetsP( pArriereGHBase ) ;
	FacesP faceDessusBase = ConstuireFacesDepuisSommets(sommets);
	AjouterFace(faceDessusBase);

	// Génération des sommets pour la base : Face du dessous
	sommets[0] = SommetsP( pAvantGBBase ) ;
	sommets[1] = SommetsP( pArriereGBBase ) ;
	sommets[2] = SommetsP( pArriereDBBase ) ;
	sommets[3] = SommetsP( pAvantDBBase ) ;
	FacesP faceDessousBase = ConstuireFacesDepuisSommets(sommets);
	AjouterFace(faceDessousBase);

	// Génération des sommets pour le support : Face arriere
	sommets[0] = SommetsP( pArriereGBSupport ) ;
	sommets[1] = SommetsP( pArriereGHSupport ) ;
	sommets[2] = SommetsP( pArriereDHSupport ) ;
	sommets[3] = SommetsP( pArriereDBSupport ) ;
	FacesP faceArriereSupport = ConstuireFacesDepuisSommets(sommets);
	AjouterFace(faceArriereSupport);

	// Génération des sommets pour le support : Face de coté à droite
	sommets[0] = SommetsP( pArriereDBBase ) ;
	sommets[1] = SommetsP( pArriereDBSupport ) ;
	sommets[2] = SommetsP( pArriereDHSupport ) ;
	sommets[3] = SommetsP( pAvantDHSupport ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour le support : Face de coté à gauche
	sommets[0] = SommetsP( pArriereGBBase ) ;
	sommets[1] = SommetsP( pAvantGHSupport ) ;
	sommets[2] = SommetsP( pArriereGHSupport ) ;
	sommets[3] = SommetsP( pArriereGBSupport ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour le support : Face avant
	sommets[0] = SommetsP( pAvantGHSupport ) ;
	sommets[1] = SommetsP( pArriereGHBase ) ;
	sommets[2] = SommetsP( pArriereDHBase ) ;
	sommets[3] = SommetsP( pAvantDHSupport ) ;
	FacesP faceAvantSupport = ConstuireFacesDepuisSommets(sommets);
	AjouterFace(faceAvantSupport);

	// Génération des sommets pour le support : Face du dessous
	sommets[0] = SommetsP( pArriereGBBase ) ;
	sommets[1] = SommetsP( pArriereGBSupport ) ;
	sommets[2] = SommetsP( pArriereDBSupport ) ;
	sommets[3] = SommetsP( pArriereDBBase ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour le support : Face du dessus
	sommets[0] = SommetsP( pAvantGHSupport ) ;
	sommets[1] = SommetsP( pAvantDHSupport ) ;
	sommets[2] = SommetsP( pArriereDHSupport ) ;
	sommets[3] = SommetsP( pArriereGHSupport ) ;
	FacesP faceDessusSupport = ConstuireFacesDepuisSommets(sommets);
	AjouterFace(faceDessusSupport);

	// Percage du trou pour la fixation de la bielle
	OutilPercageCylindrique outilBielle = OutilPercageCylindrique(false, true, 32, _diametreFixationBielle/2, _hauteurSupport/2);
	Perceuse::percer(pFixationBielle, *this, faceDessusSupport, &outilBielle);

	// Percage du trou pour la fixation au chassis
	OutilPercageCylindrique outilChassis = OutilPercageCylindrique(false, false, 32, _diametreFixationChassis/2, _epaisseurBase);
	Perceuse::percer(pOrigine, *this, faceDessousBase, faceDessusBase, &outilChassis);

	// Percage du trou pour la fixation avec la roue
	OutilPercageCylindrique outilRoue = OutilPercageCylindrique(false, false, 32, _diametreFixationRoue/2, _epaisseurSupport);
	Perceuse::percer(pFixationRoue, *this, faceArriereSupport, faceAvantSupport, &outilRoue);
}

Repere3D SupportRoue::getRepere3DFixationBielle() const{
	// Calcul de la position de la fixation de la bielle par rapport à la position de référence
	Points3D posFixBielle = _repere.Origine();
	posFixBielle = posFixBielle + (-_ecartFixationChassis + _longueurBase + _epaisseurSupport/2) * _repere.X();
	posFixBielle = posFixBielle + ((_gauche?1:-1) * ((_largeurBaseSupport/2 - _ecartFicationBielle))) * _repere.Y();
	posFixBielle = posFixBielle + (_hauteurSupport) * _repere.Z();

	Repere3D rep = Repere3D(_repere);
	rep.ModifOrigine(posFixBielle);
	return rep;
}

Repere3D SupportRoue::getRepere3DFixationInterieurRoue() const{

	// Position du repere
	Points3D posFixRoue =  _repere.Origine()+ (-_ecartFixationChassis + _longueurBase) * _repere.X() + (_hauteurSupport/2) * _repere.Z();

	// Génération de la matrice rotation autour de Y
	Matrices4D matriceRotation;
	matriceRotation.DevenirRotationQuelconque (posFixRoue, getRepere3DFixationChassis().Y(), PI/2);
	
	// Déplacement du repere
	return Repere3D(posFixRoue, _repere.X() * matriceRotation, _repere.Y() * matriceRotation, _repere.Z() * matriceRotation);
}

Repere3D SupportRoue::getRepere3DFixationExterieurRoue() const{

	// Position du repere
	Points3D posFixRoue =  _repere.Origine() + (-_ecartFixationChassis + _longueurBase + _epaisseurSupport) * _repere.X() + (_hauteurSupport/2) * _repere.Z();

	// Génération de la matrice rotation autour de Y
	Matrices4D matriceRotation;
	matriceRotation.DevenirRotationQuelconque (posFixRoue, getRepere3DFixationChassis().Y(),- PI/2);
	
	// Déplacement du repere
	return Repere3D(posFixRoue, _repere.X() * matriceRotation, _repere.Y() * matriceRotation, _repere.Z() * matriceRotation);
}

Repere3D SupportRoue::getRepere3DFixationChassis() const{
	return _repere;
}
