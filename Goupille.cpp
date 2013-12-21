#include "StdAfx.h"
#include "Goupille.h"


Goupille::Goupille(	const Repere3D& repere, 
					const double hauteur,
					const double diametre,
					const double longueurTete,
					AttributsFacesP *attributFace)
		:Prisme(repere, diametre, longueurTete, diametre, attributFace)
{
	_hauteur = hauteur;
	_diametre = diametre;
	_longueurTete = longueurTete;
	verifierArguments();
	buildAll();
}

Goupille::~Goupille(){

}

void Goupille::verifierArguments(){
	// Aucun test nescessaire !
}

void Goupille::buildAll(){

	// Cr�aton d'un cylindre qui sera office de corps
	Repere3D repFin(_repere);
	repFin.ModifOrigine( _repere.Origine() - _hauteur * _repere.Z() );
	Cylindres corps(_repere.Origine(), repFin.Origine(), _diametre/2, NULL, _attributFace) ;

	// R�cup�ration de la face de collage du prisme et du cylindre
	FacesP faceDuCorpsAColler = corps.TableauFaces()[0];
	FacesP faceDeBase = faceBase();

	// Collage
	Coller( corps, faceDeBase, faceDuCorpsAColler );

}