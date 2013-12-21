#pragma once

#include "Vecteurs3D.h"
#include "Mouvement.h"

// Classe Translation : d�crit un mouvement de rotation, h�rite de la classe Mouvement
// Repr�sent�e par un angle (un r�el)
// Pas de .cpp

class Rotation : public Mouvement
{
private:
	double _angle;

public:
	// Constructeur : angle en param�tre
	Rotation(double angle) : _angle(angle) {}

	//Fonction virtuelle getValeur de 'Mouvement', renvoie l'angle de la rotation dans ce cas
	double getValeur() { return _angle;}
};