#include "StdAfx.h"
#include "Siege.h"


Siege::Siege(	const Repere3D& repere, 
				const double largeurAssise,
				const double longueurAssise,
				const double epaisseurAssise,
				const double hauteurDossier,
				const double epaisseurDossier,
				AttributsFacesP *attributFace)
	   :Prisme( repere, epaisseurAssise, longueurAssise, largeurAssise, attributFace)
{
	_largeurAssise = largeurAssise;
	_longueurAssise = longueurAssise;
	_epaisseurAssise = epaisseurAssise;
	_hauteurDossier = hauteurDossier;
	_epaisseurDossier = epaisseurDossier;
	verifierArguments();
	buildAll();
}

void Siege::verifierArguments(){
	if ( _epaisseurDossier >= _longueurAssise ) 
		throw exception("L'epaisseur du dossier ne peut être supérieur à la longueur de l'assise!");
}

void Siege::buildAll(){
	// Pour le dossier
	Repere3D repDossier(_repere);
	repDossier.ModifOrigine( _repere.Origine() + (_epaisseurAssise )  * _repere.Z() - (_longueurAssise /2 - _epaisseurDossier/2) * _repere.X() );
	Prisme dossier(repDossier,  _hauteurDossier, _epaisseurDossier, _largeurAssise, _attributFace);
	
	// Assemblage des deux prismes
	FacesP faceACollerAssise = faceSommet();
	FacesP faceACollerDossier = dossier.faceBase();
	Coller( dossier, faceACollerAssise, faceACollerDossier);
}

