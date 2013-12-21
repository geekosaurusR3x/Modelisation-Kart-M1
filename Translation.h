#pragma once

#include "Vecteurs3D.h"
#include "Mouvement.h"

// Classe Translation : décrit un mouvement de translation, hérite de la classe Mouvement
// Représentée par une distance (un réel)
// Pas de .cpp

class Translation : public Mouvement
{
private:
	double _distance;

public:
	// Constructeur avec la distance en paramètre
	Translation (double distance) : _distance(distance) {}

	//Fonction virtuelle getValeur de 'Mouvement', renvoie la distance de la translation dans ce cas
	double getValeur() { return _distance;}
};