#pragma once
#include "Prisme.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"
#include "Perceuse.h"
#include "OutilPercageCylindrique.h"

class Roue : public Piece
{
	//Points3D _centre;//centre de la roue
	double _rayon;//rayon de la roue
	double _epaisseur;//epaisseur de la roue
	double _largeur;//rayon de l'emplacement du support de roue(le rayon)
	//SolidesP _roue;

	// Permet de construire l'objet
	// Appelé une fois dans le constructeur
	virtual void buildAll();


public:

	Roue(		const Repere3D& repere			= Repere3D(), 
				//const Points3D centre = Points3D(0,0,0),
				const double rayon			= 10,
				const double epaisseur			= 3,
				const double largeur		= 5,
				AttributsFacesP *attributFace	= &AttributsFaces(PMateriauVert));

	virtual ~Roue();
};
