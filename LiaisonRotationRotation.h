#pragma once

#include "Liaison.h"

class LiaisonRotationRotation : public Liaison
{
public:
	//Constructeur : le coefficient de la liaison en paramètre
	LiaisonRotationRotation(double coefficient);

	// Fonction virtuelle simuler : pointeur de mouvement d'entrée, renvoie un pointeur sur le mouvement de sortie
	// simule le mouvement
	Mouvement * simuler(Mouvement * mvt);
};