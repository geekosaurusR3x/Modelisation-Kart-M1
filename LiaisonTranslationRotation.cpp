#include "StdAfx.h"
#include "LiaisonTranslationRotation.h"
#include "Rotation.h"

LiaisonTranslationRotation::LiaisonTranslationRotation(double rayon, double coefficient)
{
	_rayon = rayon;
	_coefficient = coefficient;
}

Mouvement * LiaisonTranslationRotation::simuler(Mouvement * mvt)
{
	double angle;
	angle = mvt->getValeur()/_rayon;

	return new Rotation(angle*_coefficient);
}