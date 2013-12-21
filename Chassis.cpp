#include "StdAfx.h"
#include "Chassis.h"
#include "OutilPercageRectangulaire.h"
#include "OutilPercageCylindrique.h"
#include "Perceuse.h"
#include "Prisme.h"

Chassis::Chassis(	const Repere3D& repere, 
					const double longueurChassisAvant, 
					const double longueurChassisArriere, 
					const double largeurChassis, 
					const double profondeurRoueAvant, 
					const double ecartRoueArriere, 
					const double largeurEvidementFourche,
					const double longeurEvidementFourche,
					const double ecartFourcheSiege,
					const double largeurEvidementSiege,
					const double longueurEvidementSiege,
					const double ecartPivotSupportRoue,
					const double diametrePivotSupportRoue,
					const double largeurEvidementSupportCremaillere,
					const double longeurEvidementSupportCremaillere,
					const double ecartSupportsCremaillereArriveColonneDirection,
					const double profondeurTousEvidements,
					const double profondeurChassis,
					const double diametreAxeRoueArriere,
					const double largeurArretRoueArriere,
					const double longueurAxeRoueArriere,
					const double diametrePercageGoupilleArret,
					const double largeurEvidementArriveColonneDirection,
					const double longueurEvidementArriveColonneDirection,
					const double ecartSupportCremaillereFourche,
					const double ecartArriveColonnesDirectionFaceAvant,
					AttributsFacesP *attributFace)
	:Piece(repere, attributFace){

	_longueurChassisAvant = longueurChassisAvant;
	_longueurChassisArriere = longueurChassisArriere;
	_largeurChassis = largeurChassis;
	_profondeurRoueAvant = profondeurRoueAvant;
	_ecartRoueArriere = ecartRoueArriere;
	_largeurEvidementFourche = largeurEvidementFourche;
	_longeurEvidementFourche = longeurEvidementFourche;
	_ecartFourcheSiege = ecartFourcheSiege;
	_largeurEvidementSiege = largeurEvidementSiege;
	_longueurEvidementSiege = longueurEvidementSiege;
	_ecartPivotSupportRoue = ecartPivotSupportRoue ;
	_diametrePivotSupportRoue = diametrePivotSupportRoue;
	_largeurEvidementSupportCremaillere = largeurEvidementSupportCremaillere;
	_longeurEvidementSupportCremaillere = longeurEvidementSupportCremaillere;
	_ecartSupportsCremaillereArriveColonneDirection = ecartSupportsCremaillereArriveColonneDirection;
	_profondeurTousEvidements = profondeurTousEvidements;
	_profondeurChassis = profondeurChassis;
	_diametreAxeRoueArriere = diametreAxeRoueArriere;
	_largeurArretRoueArriere = largeurArretRoueArriere;
	_diametrePercageGoupilleArret = diametrePercageGoupilleArret;
	_largeurEvidementArriveColonneDirection = largeurEvidementArriveColonneDirection;
	_longueurEvidementArriveColonneDirection = longueurEvidementArriveColonneDirection;
	_ecartSupportCremaillereFourche = ecartSupportCremaillereFourche;
	_ecartArriveColonnesDirectionFaceAvant = ecartArriveColonnesDirectionFaceAvant;
	_longueurAxeRoueArriere = longueurAxeRoueArriere;
	verifierArguments();
	buildAll();
}

void Chassis::verifierArguments(){
	if ( _profondeurRoueAvant*4 >= _largeurChassis )
		throw exception("La pronfondeur reservée pour les roues est trop grande. Elle doit être 4 fois plus petite que la largeur du chassis");

	double largeurBaseAvant = _largeurChassis - _profondeurRoueAvant*2;
	double largeurFBaseAvant = largeurBaseAvant - _profondeurRoueAvant*2;
	double distTotalCremaillere = _largeurEvidementSupportCremaillere*3;
	double distAxeRoueAvant = largeurBaseAvant - 2*_ecartPivotSupportRoue;

	// Pronfondeur reservee aux roue avant <=> Largeur du chassis
	if ( _profondeurRoueAvant*4 >= _largeurChassis )
		throw exception("La pronfondeur reservée pour les roues est trop grande. Elle doit être 4 fois plus petite que la largeur du chassis");

	// Distance total des cremaillere <=> Distance entre les 2 axes des roues avants
	if ( distTotalCremaillere >= distAxeRoueAvant )
		throw exception("Les cremailleres sont trop grande! Elles ne peuvent pas être positionnées entre les 2 axes des roues avant. Agrandissez la largeur du chassis ou diminuer leurs tailles!");

	double largeurTotal = _longueurChassisAvant
						+ _longueurChassisArriere
						+ _ecartPivotSupportRoue * 2;

	double largeurTotalPieces = _ecartArriveColonnesDirectionFaceAvant 
							  + _largeurEvidementArriveColonneDirection 
							  + _ecartSupportsCremaillereArriveColonneDirection
							  + _largeurEvidementSupportCremaillere
							  + _ecartSupportCremaillereFourche
							  + _largeurEvidementFourche
							  + _ecartFourcheSiege
							  + _longueurEvidementSiege;

	// Longueur de toutes les pieces <=> longueur du chassis
	if ( largeurTotalPieces >= largeurTotal ){
		throw exception("La longueurs de toutes les pieces du chassis (boitier de la colonne de direction, cremaillere, fourche, siege) ainsi que l'ecart entres-elles représentent une longueur plus grande que celle du chassis lui même!");
	}

	// Boitier de l'arrivé de la colonne de direction <=> Largeur avant du chassis
	if ( _longueurEvidementArriveColonneDirection >= largeurFBaseAvant )
		throw exception("La longueur de l'évidement du boitier de l'arrivée de la colonne de direction est plus grande que la longueur de la base avant du chassis. Elle doit être au moins 4 fois plus petite que la largeur finale du chassis");

	// Longueur de la fourche <=> Largeur avant du chassis
	if ( _longeurEvidementFourche >= largeurBaseAvant )
		throw exception("La longueur de l'évidement de la fourche est plus grande que la largeur de la base avant du chassis. Elle doit être au moins 2 fois plus petite que la largeur finale du chassis");

	// Largeur du siege <=> largeur du chassis
	if( _largeurEvidementSiege >= _largeurChassis )
		throw exception("La largeur de l'évidement du siège est plus grande que la largeur finale du chassis!");

	if ( _profondeurTousEvidements >= _profondeurChassis)
		throw exception("La pronfondeur des évidements ne doit pas être plus grand que la pronfondeur du chassis lui-même!");
}

void Chassis::buildAll(){
	// Création des tableaux de sommets
	Tableaux<SommetsP> sommets = Tableaux<SommetsP>(4, 1);

	// Point d'origine : Centre de la fixation du chassis
	Points3D pOrigine = _repere.Origine();
	Vecteurs3D x=_repere.X();
	Vecteurs3D y=_repere.Y();
	Vecteurs3D z=_repere.Z();

	// Calcul des points de références de la face arriere du chassis
	Points3D pArriereHG = pOrigine-_ecartRoueArriere*x+ _largeurChassis/2*y;
	Points3D pArriereBG = pArriereHG -_profondeurChassis*z;
	Points3D pArriereBD = pArriereBG -_largeurChassis*y;
	Points3D pArriereHD = pArriereBD + _profondeurChassis*z;

	// Calcul des points de références de la face arriere gauche du chassis
	Points3D pFaceArriereGaucheHG = pArriereHG + _longueurChassisArriere*x;
	Points3D pFaceArriereGaucheBG = pFaceArriereGaucheHG -_profondeurChassis*z;

	// Calcul des points de références de la face arriere droite du chassis
	Points3D pFaceArriereDroiteHD = pFaceArriereGaucheHG -_largeurChassis*y;
	Points3D pFaceArriereDroiteBD = pFaceArriereGaucheBG - _largeurChassis*y;

	// Calcul des points de références de la face arriere vers avant gauche du chassis
	Points3D pFaceArriereVersAvantGaucheHG = pFaceArriereGaucheHG +_profondeurRoueAvant*x-_profondeurRoueAvant*y;
	Points3D pFaceArriereVersAvantGaucheBG = pFaceArriereVersAvantGaucheHG -_profondeurChassis*z;

	// Calcul des points de références de la face arriere vers avant droite du chassis
	Points3D pFaceArriereVersAvantDroiteHD = pFaceArriereDroiteHD +_profondeurRoueAvant*x+_profondeurRoueAvant*y;
	Points3D pFaceArriereVersAvantDroiteBD = pFaceArriereVersAvantDroiteHD -_profondeurChassis*z;

	// Calcul des points de références de la face du chanfrein avant du chassis coté gauche
	Points3D pFaceAvantChanfreinGaucheHD = pFaceArriereVersAvantGaucheHG + _longueurChassisAvant*x;
	Points3D pFaceAvantChanfreinGaucheBD = pFaceAvantChanfreinGaucheHD -_profondeurChassis*z;
	Points3D pFaceAvantChanfreinGaucheHG = pFaceAvantChanfreinGaucheHD + _profondeurRoueAvant*x -_profondeurRoueAvant*y;
	Points3D pFaceAvantChanfreinGaucheBG = pFaceAvantChanfreinGaucheHG  -_profondeurChassis*z;

	// Calcul des points de références de la face du chanfrein avant du chassis coté droit
	Points3D pFaceAvantChanfreinDroitHG = pFaceAvantChanfreinGaucheHD -(_largeurChassis-_profondeurRoueAvant*2)*y;
	Points3D pFaceAvantChanfreinDroitBG = pFaceAvantChanfreinGaucheBD -(_largeurChassis-_profondeurRoueAvant*2)*y;
	Points3D pFaceAvantChanfreinDroitHD = pFaceAvantChanfreinGaucheHG -(_largeurChassis-_profondeurRoueAvant*4)*y;
	Points3D pFaceAvantChanfreinDroitBD = pFaceAvantChanfreinGaucheBG -(_largeurChassis-_profondeurRoueAvant*4)*y;

	// Génération des sommets pour la face arriere du chassis
	sommets[0] = SommetsP( pArriereHG ) ;
	sommets[1] = SommetsP( pArriereBG ) ;
	sommets[2] = SommetsP( pArriereBD ) ;
	sommets[3] = SommetsP( pArriereHD ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la face arriere gauche du chassis
	sommets[0] = SommetsP( pArriereHG ) ;
	sommets[1] = SommetsP( pFaceArriereGaucheHG ) ;
	sommets[2] = SommetsP( pFaceArriereGaucheBG ) ;
	sommets[3] = SommetsP( pArriereBG ) ;
	FacesP faceArrChassisGauche = ConstuireFacesDepuisSommets(sommets);
	AjouterFace(faceArrChassisGauche);

	// Génération des sommets pour la face arriere droite du chassis
	sommets[0] = SommetsP( pArriereHD ) ;
	sommets[1] = SommetsP( pArriereBD ) ;
	sommets[2] = SommetsP( pFaceArriereDroiteBD ) ;
	sommets[3] = SommetsP( pFaceArriereDroiteHD ) ;
	FacesP faceArrChassisDroite = ConstuireFacesDepuisSommets(sommets);
	AjouterFace(faceArrChassisDroite);

	// Génération des sommets pour la face arriere vers avant gauche du chassis
	sommets[0] = SommetsP( pFaceArriereGaucheHG ) ;
	sommets[1] = SommetsP( pFaceArriereVersAvantGaucheHG ) ;
	sommets[2] = SommetsP( pFaceArriereVersAvantGaucheBG ) ;
	sommets[3] = SommetsP( pFaceArriereGaucheBG ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la face arriere vers avant droite du chassis
	sommets[0] = SommetsP( pFaceArriereDroiteHD ) ;
	sommets[1] = SommetsP( pFaceArriereDroiteBD ) ;
	sommets[2] = SommetsP( pFaceArriereVersAvantDroiteBD ) ;
	sommets[3] = SommetsP( pFaceArriereVersAvantDroiteHD ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la face avant gauche du chassis
	sommets[0] = SommetsP( pFaceArriereVersAvantGaucheHG ) ;
	sommets[1] = SommetsP( pFaceAvantChanfreinGaucheHD ) ;
	sommets[2] = SommetsP( pFaceAvantChanfreinGaucheBD ) ;
	sommets[3] = SommetsP( pFaceArriereVersAvantGaucheBG ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la face avant droit du chassis
	sommets[0] = SommetsP( pFaceArriereVersAvantDroiteHD ) ;
	sommets[1] = SommetsP( pFaceArriereVersAvantDroiteBD ) ;
	sommets[2] = SommetsP( pFaceAvantChanfreinDroitBG ) ;
	sommets[3] = SommetsP( pFaceAvantChanfreinDroitHG ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la face du chanfrein avant gauche du chassis
	sommets[0] = SommetsP( pFaceAvantChanfreinGaucheHD ) ;
	sommets[1] = SommetsP( pFaceAvantChanfreinGaucheHG ) ;
	sommets[2] = SommetsP( pFaceAvantChanfreinGaucheBG ) ;
	sommets[3] = SommetsP( pFaceAvantChanfreinGaucheBD ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la face du chanfrein avant droit du chassis
	sommets[0] = SommetsP( pFaceAvantChanfreinDroitHG ) ;
	sommets[1] = SommetsP( pFaceAvantChanfreinDroitBG ) ;
	sommets[2] = SommetsP( pFaceAvantChanfreinDroitBD ) ;
	sommets[3] = SommetsP( pFaceAvantChanfreinDroitHD ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la face de la face avant du chassis
	sommets[0] = SommetsP( pFaceAvantChanfreinDroitHD ) ;
	sommets[1] = SommetsP( pFaceAvantChanfreinDroitBD ) ;
	sommets[2] = SommetsP( pFaceAvantChanfreinGaucheBG ) ;
	sommets[3] = SommetsP( pFaceAvantChanfreinGaucheHG ) ;
	AjouterFace(ConstuireFacesDepuisSommets(sommets));

	// Génération des sommets pour la face supérieur
	Tableaux<SommetsP> sommetsSup = Tableaux<SommetsP>(9, 1);
	sommetsSup[0] = SommetsP( pArriereHG ) ;
	sommetsSup[1] = SommetsP( pArriereHD ) ;
	sommetsSup[2] = SommetsP( pFaceArriereDroiteHD ) ;
	sommetsSup[3] = SommetsP( pFaceArriereVersAvantDroiteHD ) ;
	sommetsSup[4] = SommetsP( pFaceAvantChanfreinDroitHG ) ;
	sommetsSup[5] = SommetsP( pFaceAvantChanfreinDroitHD ) ;
	sommetsSup[6] = SommetsP( pFaceAvantChanfreinGaucheHG ) ;
	sommetsSup[7] = SommetsP( pFaceAvantChanfreinGaucheHD ) ;
	sommetsSup[8] = SommetsP( pFaceArriereVersAvantGaucheHG ) ;
	sommetsSup[9] = SommetsP( pFaceArriereGaucheHG ) ;
	FacesP faceSuperieur = ConstuireFacesDepuisSommets(sommetsSup);
	AjouterFace(faceSuperieur);

	// Génération des sommets pour la face inférieur
	sommetsSup[0] = SommetsP( pFaceArriereGaucheBG ) ;
	sommetsSup[1] = SommetsP( pFaceArriereVersAvantGaucheBG ) ;
	sommetsSup[2] = SommetsP( pFaceAvantChanfreinGaucheBD ) ;
	sommetsSup[3] = SommetsP( pFaceAvantChanfreinGaucheBG ) ;
	sommetsSup[4] = SommetsP( pFaceAvantChanfreinDroitBD ) ;
	sommetsSup[5] = SommetsP( pFaceAvantChanfreinDroitBG ) ;
	sommetsSup[6] = SommetsP( pFaceArriereVersAvantDroiteBD ) ;
	sommetsSup[7] = SommetsP( pFaceArriereDroiteBD ) ;
	sommetsSup[8] = SommetsP( pArriereBD ) ;
	sommetsSup[9] = SommetsP( pArriereBG ) ;
	FacesP faceInferieur = ConstuireFacesDepuisSommets(sommetsSup);
	AjouterFace(faceInferieur);


	// Percage des evidements
	// Percage de la colonne de direction
	Repere3D rep = Repere3D(getRepere3DFixationArriveeColonneDirection().Origine() + _profondeurTousEvidements * _repere.Z(), _repere.X(), -_repere.Y(), -_repere.Z());
	OutilPercageRectangulaire outilColDirection = OutilPercageRectangulaire(false, true, _longueurEvidementArriveColonneDirection, _largeurEvidementArriveColonneDirection, _profondeurTousEvidements);
	Perceuse::percer(rep, *this, faceSuperieur, &outilColDirection);

	// Percage de la fixation des supports de roue de gauche
	rep.ModifOrigine(getPosition3DFixationRoueAvant(true).Origine() + _profondeurChassis * _repere.Z());
	OutilPercageCylindrique outilFixationSupportRoueG = OutilPercageCylindrique(false, false, 36, _diametrePivotSupportRoue/2, _profondeurChassis);
	Perceuse::percer(rep, *this, faceInferieur, faceSuperieur, &outilFixationSupportRoueG);

	// Percage de la fixation des support de roue de droite
	rep.ModifOrigine(getPosition3DFixationRoueAvant(false).Origine()+ _profondeurChassis * _repere.Z());
	OutilPercageCylindrique outilFixationSupportRoueD = OutilPercageCylindrique(false, false, 36, _diametrePivotSupportRoue/2, _profondeurChassis);
	Perceuse::percer(rep, *this, faceInferieur, faceSuperieur, &outilFixationSupportRoueD);

	// Percage de la fixation des supports de cremaillere
	OutilPercageRectangulaire outilSupportCremaillereC = OutilPercageRectangulaire(false, true, _longeurEvidementSupportCremaillere, _largeurEvidementSupportCremaillere, _profondeurTousEvidements);
	OutilPercageRectangulaire outilSupportCremaillereG = OutilPercageRectangulaire(false, true, _longeurEvidementSupportCremaillere, _largeurEvidementSupportCremaillere, _profondeurTousEvidements);
	OutilPercageRectangulaire outilSupportCremaillereD = OutilPercageRectangulaire(false, true, _longeurEvidementSupportCremaillere, _largeurEvidementSupportCremaillere, _profondeurTousEvidements);
	
	// Cremaillere centrale
	rep.ModifOrigine(getRepere3DFixationSupportCremaillereCentral().Origine() + _profondeurTousEvidements * _repere.Z());
	Perceuse::percer(rep, *this, faceSuperieur, &outilSupportCremaillereC);
	
	// Cremaillere de droite
	rep.ModifOrigine(getRepere3DFixationSupportCremaillere(false).Origine() + _profondeurTousEvidements * _repere.Z());
	Perceuse::percer(rep, *this, faceSuperieur, &outilSupportCremaillereD);
	
	// Cremaillere de gauche
	rep.ModifOrigine(getRepere3DFixationSupportCremaillere(true).Origine() + _profondeurTousEvidements * _repere.Z());
	Perceuse::percer(rep, *this, faceSuperieur, &outilSupportCremaillereG);

	// Percage de l'evidement de la fourche
	rep.ModifOrigine(getRepere3DFixationFourche().Origine() + _profondeurTousEvidements * _repere.Z());
	OutilPercageRectangulaire outilFourche = OutilPercageRectangulaire(false, true, _longeurEvidementFourche, _largeurEvidementFourche, _profondeurTousEvidements);
	Perceuse::percer(rep, *this, faceSuperieur, &outilFourche);

	// Percage de l'evidement du siege
	rep.ModifOrigine(getRepere3DFixationSiege().Origine() + _profondeurTousEvidements * _repere.Z());
	OutilPercageRectangulaire outilSiege = OutilPercageRectangulaire(false, true, _largeurEvidementSiege, _longueurEvidementSiege, _profondeurTousEvidements);
	Perceuse::percer(rep, *this, faceSuperieur, &outilSiege);


	// CREATION DES AXES ARRIERE
	AttributsFaces atAxe = AttributsFaces(PMateriauRouge);

	// Récupération du repere de la roue arriere
	Repere3D repAxeRoueArGauche = getRepere3DFixationRoueArriere(true);
	Repere3D repAxeRoueArDroite = getRepere3DFixationRoueArriere(false);

	// Calcul du point d'arrivé
	Points3D pAxeFinGauche = repAxeRoueArGauche.Origine() + _longueurAxeRoueArriere * repAxeRoueArGauche.Z(); 
	Points3D pAxeFinDroite = repAxeRoueArDroite.Origine() + _longueurAxeRoueArriere * repAxeRoueArDroite.Z(); 

	// Création des 2 axes
	Cylindres axeGauche(repAxeRoueArGauche.Origine(), pAxeFinGauche, _diametreAxeRoueArriere/2, NULL, &atAxe) ;
	Cylindres axeDroite(repAxeRoueArDroite.Origine(), pAxeFinDroite, _diametreAxeRoueArriere/2, NULL, &atAxe) ;

	// récupération de la face à coller
	FacesP faceACollerAxeGauche = axeGauche.TableauFaces()[0];
	FacesP faceACollerAxeDroite = axeDroite.TableauFaces()[0];

	// CREATION DES ARRETS DES AXES ARRIERES

	// Création des reperes des arrets
	Repere3D repArretAxeRoueArGauche(repAxeRoueArGauche);
	Repere3D repArretAxeRoueArDroite(repAxeRoueArDroite);
	repArretAxeRoueArGauche.ModifOrigine(pAxeFinGauche);
	repArretAxeRoueArDroite.ModifOrigine(pAxeFinDroite);

	// Création des arrets
	Prisme arretAxeGauche(repArretAxeRoueArGauche,_largeurArretRoueArriere, _largeurArretRoueArriere, _largeurArretRoueArriere, &atAxe);
	Prisme arretAxeDroite(repArretAxeRoueArDroite,_largeurArretRoueArriere, _largeurArretRoueArriere, _largeurArretRoueArriere, &atAxe);

	// PERCAGE

	// Point de percage
	Points3D ptsArretPercageGauche = repArretAxeRoueArGauche.Origine() + _largeurArretRoueArriere /2 * repArretAxeRoueArGauche.Z() + _largeurArretRoueArriere /2 * repArretAxeRoueArGauche.Y();
	Points3D ptsArretPercageDroite = repArretAxeRoueArDroite.Origine() + _largeurArretRoueArriere /2 * repArretAxeRoueArDroite.Z() + _largeurArretRoueArriere /2 * repArretAxeRoueArDroite.Y();

	// récupération des faces à percer des arrets
	FacesP faceAPercerArretsGauche = *(arretAxeGauche.flans()[0]);
	FacesP faceAPercerArretsDroite = *(arretAxeDroite.flans()[0]);

	// récupération des faces à percer des arrets
	FacesP faceDebouchanteArretsGauche = *(arretAxeGauche.flans()[2]);
	FacesP faceDebouchanteArretsDroite = *(arretAxeDroite.flans()[2]);

	// Outil de percage
	OutilPercageCylindrique outilG = OutilPercageCylindrique(false, false, 32, _diametrePercageGoupilleArret/2, _largeurArretRoueArriere);
	OutilPercageCylindrique outilD = OutilPercageCylindrique(false, false, 32, _diametrePercageGoupilleArret/2, _largeurArretRoueArriere);

	// Percage
	Perceuse::percer(ptsArretPercageGauche, arretAxeGauche, faceAPercerArretsGauche, faceDebouchanteArretsGauche, &outilG);
	Perceuse::percer(ptsArretPercageDroite, arretAxeDroite, faceAPercerArretsDroite, faceDebouchanteArretsDroite, &outilD);

	// COLLAGE DES AXES

	// récupération des faces à coller des arrets
	FacesP faceACollerArretGauche = arretAxeGauche.faceBase();
	FacesP faceACollerArretDroite = arretAxeDroite.faceBase();

	// récupération de la face de l'axe
	FacesP faceAxeGauche = axeGauche.TableauFaces()[1];
	FacesP faceAxeDroite = axeDroite.TableauFaces()[1];

	// Collage des arrets
	axeGauche.Coller(arretAxeGauche, faceAxeGauche, faceACollerArretGauche);
	axeDroite.Coller(arretAxeDroite, faceAxeDroite, faceACollerArretDroite);

	// Collage des Axes
	Coller(axeGauche, faceArrChassisGauche, faceACollerAxeGauche);
	Coller(axeDroite, faceArrChassisDroite, faceACollerAxeDroite);
}


Repere3D Chassis::getRepere3DFixationSupportCremaillereCentral() const{

	// A partir de l'origine du point de fixation de la colonne de direction
	Points3D pos = getRepere3DFixationArriveeColonneDirection().Origine(); 

	// On modifie la position en X pour arriver sur l'évidement de la cremaillere central
	pos = pos -( _largeurEvidementArriveColonneDirection/2 + _ecartSupportsCremaillereArriveColonneDirection + _largeurEvidementSupportCremaillere/2 ) * _repere.X();

	return Repere3D(pos, _repere.X(), _repere.Y(), _repere.Z());
}

Repere3D Chassis::getRepere3DFixationSupportCremaillere(bool gauche) const{

	// Calcul des creamilleres de coté à partir de la cremaillere centrale
	Points3D pos = getRepere3DFixationSupportCremaillereCentral().Origine(); 

	// Il suffit de calculer la distance entre 2 cremaillere
	double distEntreSupportsCrem = abs(getPosition3DFixationRoueAvant(gauche).Origine().Y() - getRepere3DFixationSupportCremaillereCentral().Origine().Y())/2;

	// Et de modifier la position en Y en fonction de la cremaillere voulue
	pos = pos + ((gauche?1:-1) * distEntreSupportsCrem) * _repere.Y();

	return Repere3D(pos, _repere.X(), _repere.Y(), _repere.Z());
}

Repere3D Chassis::getRepere3DFixationArriveeColonneDirection() const{

	// Calcul de la position de l'arivee de la colonne de direction à partir de l'origine du chassis
	Points3D pos = _repere.Origine();

	// Il suffit de décaliser le repere en X de la longueur du chassis - l'ecart entre l'avant du chassis et l'evidement
	pos = pos + (-_ecartRoueArriere+_longueurChassisAvant+_longueurChassisArriere+_profondeurRoueAvant*2-_ecartArriveColonnesDirectionFaceAvant-_largeurEvidementArriveColonneDirection/2) * _repere.X();
	pos = pos - _profondeurTousEvidements * _repere.Z();

	return Repere3D(pos, _repere.X(), _repere.Y(), _repere.Z());
}

Repere3D Chassis::getRepere3DFixationFourche() const{

	// Calcul de la fourche à partir du repere de la cremaillere centrale
	Points3D pos = getRepere3DFixationSupportCremaillereCentral().Origine(); 

	// Décalage du repere en X
	pos = pos - ( _largeurEvidementSupportCremaillere/2 + _ecartSupportCremaillereFourche + _largeurEvidementFourche/2) * _repere.X();

	return Repere3D(pos, _repere.X(), _repere.Y(), _repere.Z());
}


Repere3D Chassis::getRepere3DFixationRoueArriere(bool gauche) const{

	// Décalage en Y à partir de la position d'origine
	Points3D pos = _repere.Origine() + (gauche?1:-1)*(_largeurChassis/2) * _repere.Y();

	// et en Z
	pos = pos - _profondeurChassis/2 * _repere.Z();

	return Repere3D(pos, _repere.X(), (gauche?-1:1)*_repere.Z(), (gauche?1:-1)*_repere.Y());
}


Repere3D Chassis::getRepere3DFixationSiege() const{

	// Calcul de la position du repere à partir de la position de la fourche
	Points3D pos = getRepere3DFixationFourche().Origine(); 

	// Décalage ensuite sur le repere en X
	pos = pos - ( _largeurEvidementFourche/2 + _ecartFourcheSiege + _longueurEvidementSiege/2) * _repere.X();

	return Repere3D(pos, _repere.X(), _repere.Y(), _repere.Z());
}

Repere3D Chassis::getPosition3DFixationRoueAvant(bool gauche) const{

	// A partir de l'origine du chassis (repere de reference)
	Points3D pos =  _repere.Origine();

	// Decalage en X pour arriver au milieu de la face avant du chassis (capot)
	pos = pos + (-_ecartRoueArriere+_longueurChassisAvant/2+_longueurChassisArriere+_profondeurRoueAvant) * _repere.X();

	// puis décalage en Y pour être sur le même plan que cette face
	pos = pos + (gauche?1:-1)*(_largeurChassis/2-_profondeurRoueAvant-_ecartPivotSupportRoue) * _repere.Y();

	// Decalage en Z
	pos = pos - _profondeurChassis * _repere.Z();

	return Repere3D(pos, _repere.X(), _repere.Y(), _repere.Z());
}

