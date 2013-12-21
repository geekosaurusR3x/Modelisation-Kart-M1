#include "StdAfx.h"
#include "LiaisonTranslationTranslation.h"
#include "Translation.h"

LiaisonTranslationTranslation::LiaisonTranslationTranslation(double coefficient)
{
	_coefficient = coefficient;
}

Mouvement * LiaisonTranslationTranslation::simuler(Mouvement * mvt)
{
	return  new Translation(mvt->getValeur()*_coefficient);
}