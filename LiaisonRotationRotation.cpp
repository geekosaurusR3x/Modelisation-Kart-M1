#include "StdAfx.h"
#include "LiaisonRotationRotation.h"
#include "Rotation.h"

LiaisonRotationRotation::LiaisonRotationRotation(double coefficient)
{
	_coefficient = coefficient;
}

Mouvement * LiaisonRotationRotation::simuler(Mouvement * mvt)
{
	return new Rotation(mvt->getValeur()*_coefficient);
}