#include "StdAfx.h"
#include "Roue.h"


Roue::Roue(	const Repere3D& repere,	//Points3D centre, 
			const double rayon,const double epaisseur,
			const double largeur,AttributsFacesP *attributFace)
		:Piece(repere, attributFace)
{
	//_centre = centre;
	_rayon = rayon;
	_epaisseur = epaisseur;
	_largeur = largeur;
	buildAll();
}

Roue::~Roue(){

}

void Roue::buildAll(){

	// Créaton d'un cylindre qui sera office de corps
	Repere3D repFin(_repere);
	repFin.ModifOrigine( _repere.Origine() - _epaisseur * _repere.Y() );
	Cylindres corps(_repere.Origine(), repFin.Origine(), _rayon, NULL, _attributFace);

	//Recuperation des faces des deux bases
	FacesP face1 = corps.TableauFaces()[0];
	FacesP face2 = corps.TableauFaces()[1];

	//percage du trou pour le support
	OutilPercageCylindrique outil1 = OutilPercageCylindrique(false, false, 100, _largeur, _epaisseur);
	Perceuse::percer(_repere.Origine(), corps, face2,face1,  &outil1);

	AjouterFaces(corps.TableauFaces());

}