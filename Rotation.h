#pragma once

#include "Vecteurs3D.h"
#include "Mouvement.h"

// Classe Translation : décrit un mouvement de rotation, hérite de la classe Mouvement
// Représentée par un angle (un réel)
// Pas de .cpp

class Rotation : public Mouvement
{
private:
	double _angle;

public:
	// Constructeur : angle en paramètre
	Rotation(double angle) : _angle(angle) {}

	//Fonction virtuelle getValeur de 'Mouvement', renvoie l'angle de la rotation dans ce cas
	double getValeur() { return _angle;}
};