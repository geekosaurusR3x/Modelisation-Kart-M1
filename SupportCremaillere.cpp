#include "stdafx.h"
#include "SupportCremaillere.h"

SupportCremaillere::SupportCremaillere(double angle,Points3D depart, Points3D support, int lB,int lpB,int hD,int hG, int size, int extru){

	//Initialisation des attributs du support
	_angle = angle;
	_longueurBase=lB;
	_longueurPetiteBase= lpB;
	_hauteurGauche= hG;
	_hauteurDroite=hD;
	_taille = size;
	_depart = depart;
	_support = support;
	_extrusion = extru;
	
	//Creation du support de cremaillere par le point du milieu de la diagonale
	SupportCremaillereParPoint();
}

SupportCremaillere::SupportCremaillere(double angle, int prof, Points3D depart, int lB,int lpB,int hD,int hG, int size, int extru){
	
	//Initialisation des attributs du support
	_angle = angle;
	_profondeur = prof;
	_longueurBase=lB;
	_longueurPetiteBase= lpB;
	_hauteurGauche= hG;
	_hauteurDroite=hD;
	_taille = size;
	_depart = depart;
	_extrusion = extru;

	//Creation du support de cremaillere
	Support_Cremaillere();
}

//Creation du support en utilisant le Points3D du milieu de la diagonale
void SupportCremaillere::SupportCremaillereParPoint(){
	//Initialisation des variables _abscisse et _ordonnées qui seront utilisée plus tard
	//Initialisation du vecteur de direction pour permettre l'extrusion

	double _abscisse = 0;
	double _ordonnee = 0;

	Vecteurs3D _direction(0,0,1);

	//Les points sont créés selon les spécifications données par l'utilisateur
	Points3D P1(_depart);
	Points3D P2(_depart + Points3D(_longueurBase,0,0));
	Points3D P3(_depart + Points3D(_longueurBase,_hauteurDroite,0));
	Points3D P4(_support);
	Points3D P5(_depart + Points3D(_longueurPetiteBase,_hauteurGauche,0));
	Points3D P6(_depart + Points3D(0,_hauteurGauche,0));

	/********************************************************************************************************
	Les points P4bisH et P4bisB sont les deux points de part et d'autre de P4, support de la cremaillère
	Pour les calculer, on passe par les coordonnées polaires
		- On a la taille de la cremaillère à supporter : _taille = X ainsi que l'angle (en degré) _angle = Y°
		- On convertis cet angle en radian : _angle = pi * (_angle)/180
		- abs = _taille/2 * cos(_angle) ord = _taille/2 + sin(_angle) permettent d'obtenir l'abscisse et
		ordonnée du nouveau point. La valeur d'_angle est differentes pouur les 2 points P4bisH et P4bisB.
		En effet, pour le 1er, elle vaut Pi - _angle, pour le second elle vaut 2Pi - _angle
		- abs = P4.X() + abs de même pour ord, et par la suite on fait de même pour le second point à calculer
	*********************************************************************************************************/

	//Creation du point P4bisH
	_angle = PI *(_angle/180);
	_abscisse = _taille/2 * cos(PI - _angle);
	_ordonnee = _taille/2 * sin(PI - _angle);
	_abscisse = P4.X() + _abscisse;
	_ordonnee = P4.Y() + _ordonnee;
	Points3D P4bisH(_abscisse,_ordonnee,0);

	//Creation du point P4bisB
	_abscisse = _taille/2 * cos(2*PI - _angle);
	_ordonnee = _taille/2 * sin(2*PI - _angle);
	_abscisse = P4.X() + _abscisse;
	_ordonnee = P4.Y() + _ordonnee;
	Points3D P4bisB(_abscisse,_ordonnee,0);

	//Liste des points pour l'extrusion
	Listes<Points3D> Liste;
	Liste.InsertionEnQueue(P1);
	Liste.InsertionEnQueue(P2);
	Liste.InsertionEnQueue(P3);
	Liste.InsertionEnQueue(P4bisB);
	Liste.InsertionEnQueue(P4bisH);
	Liste.InsertionEnQueue(P5);
	Liste.InsertionEnQueue(P6);
	
	//Extrusion en elle-même
	AttributsFaces AF(PMateriauBleu);
	Extrusions E(Liste, _extrusion*_direction,NULL, &AF);
	Support.AjouterFaces(E.TableauFaces());
}

//Creation du support en utilisant la profondeur
void SupportCremaillere::Support_Cremaillere(){

	//Initialisation des variables _abscisse et _ordonnées qui seront utilisée plus tard
	//Initialisation du vecteur de direction pour permettre l'extrusion

	double _abscisse = 0;
	double _ordonnee = 0;
	double angle;

	Vecteurs3D _direction(0,0,1);

	//Les points sont créés selon les spécifications données par l'utilisateur
	Points3D P1(_depart);
	Points3D P2(_depart + Points3D(_longueurBase,0,0));
	Points3D P3(_depart + Points3D(_longueurBase,_hauteurDroite,0));
	Points3D P4(_depart + Points3D(_longueurPetiteBase,_hauteurGauche,0));
	Points3D P5(_depart + Points3D(0,_hauteurGauche,0));

	//On calcul le milieu de la diagonale [P3 P4]
	Points3D _milieu((P3.X() + P4.X())/2, (P3.Y() + P4.Y())/2,(P3.Z() + P4.Z())/2);
	//Calcul de l'angle S1S2 S1_milieu
	Vecteurs3D V1(P1, P2);
	Vecteurs3D V2(P1, _milieu);
	angle = acos((V1*V2) / (V1.Norme() * V2.Norme()));//Valeur de l'angle en radian

	//Pour trouver le point du milieu du support, il faut effectuer une rotation
	//de centre milieu, et d'angle PI+angle

	_abscisse = _profondeur * cos(PI + angle);
	_ordonnee = _profondeur * sin(PI + angle);

	_abscisse = _milieu.X() + _abscisse;
	_ordonnee = _milieu.Y() + _ordonnee;


	Points3D milieuSupport(_abscisse,_ordonnee,P1.Z());

	// De même que pour SupportCremaillereParPoints on calcule les points autour de ce dernier
	//Creation du point PmilieuBisH
	_angle = PI *(_angle/180);
	_abscisse = _taille/2 * cos(PI - _angle);
	_ordonnee = _taille/2 * sin(PI - _angle);

	_abscisse = milieuSupport.X() + _abscisse;
	_ordonnee = milieuSupport.Y() + _ordonnee;

	Points3D PmilieuBisH(_abscisse,_ordonnee,P1.Z());

	//Creation du point PmilieuBisB
	_abscisse = _taille/2 * cos(2*PI - _angle);
	_ordonnee = _taille/2 * sin(2*PI - _angle);


	_abscisse = milieuSupport.X() + _abscisse;
	_ordonnee = milieuSupport.Y() + _ordonnee;

	Points3D PmilieuBisB(_abscisse,_ordonnee,P1.Z());

	//Liste des points pour l'extrusion
	Listes<Points3D> Liste;
	Liste.InsertionEnQueue(P1);
	Liste.InsertionEnQueue(P2);
	Liste.InsertionEnQueue(P3);
	Liste.InsertionEnQueue(PmilieuBisB);
	Liste.InsertionEnQueue(PmilieuBisH);
	Liste.InsertionEnQueue(P4);
	Liste.InsertionEnQueue(P5);
	
	//Extrusion en elle-même
	AttributsFaces AF(PMateriauBleu);
	Extrusions E(Liste, _extrusion*_direction,NULL, &AF);
	Support.AjouterFaces(E.TableauFaces());
}

SolidesP SupportCremaillere::getSupport(){
	return this->Support;
}

SupportCremaillere::~SupportCremaillere(){}