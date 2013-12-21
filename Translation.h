#pragma once

#include "Vecteurs3D.h"
#include "Mouvement.h"

// Classe Translation : d�crit un mouvement de translation, h�rite de la classe Mouvement
// Repr�sent�e par une distance (un r�el)
// Pas de .cpp

class Translation : public Mouvement
{
private:
	double _distance;

public:
	// Constructeur avec la distance en param�tre
	Translation (double distance) : _distance(distance) {}

	//Fonction virtuelle getValeur de 'Mouvement', renvoie la distance de la translation dans ce cas
	double getValeur() { return _distance;}
};