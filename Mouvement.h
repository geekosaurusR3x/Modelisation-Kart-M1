#pragma once

#include "Vecteurs3D.h"

// Classe Mouvement : abstraite, repr�sente des mouvements (classes filles)
// Une seule fonction virtuelle : getValeur

class Mouvement
{
public:
	//Fonction virtuelle, repr�sentera les valeurs des mouvements h�rit�s
	virtual double getValeur() = 0;
};