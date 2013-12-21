#include "StdAfx.h"
#include "LiaisonRotationTranslation.h"
#include "Translation.h"

LiaisonRotationTranslation::LiaisonRotationTranslation(double rayon, double coefficient)
{
	_rayon = rayon;
	_coefficient = coefficient;
}

Mouvement * LiaisonRotationTranslation::simuler(Mouvement * mvt)
{
	double angle = mvt->getValeur();

	return new Translation(angle*_rayon*_coefficient);
}