#pragma once

#include "Vecteurs3D.h"

// Classe Mouvement : abstraite, représente des mouvements (classes filles)
// Une seule fonction virtuelle : getValeur

class Mouvement
{
public:
	//Fonction virtuelle, représentera les valeurs des mouvements hérités
	virtual double getValeur() = 0;
};