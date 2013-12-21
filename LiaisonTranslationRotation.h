#pragma once

#include "Liaison.h"
#include "Vecteurs3D.h"

class LiaisonTranslationRotation : public Liaison
{
private:
	//le rayon de l'élément tournant (ex : roue dentée)
	double _rayon;

public:
	//Constructeur : le rayon de l'élément tournant et le coefficient de la liaison en paramètre
	LiaisonTranslationRotation(double rayon, double coefficient);

	// Fonction virtuelle simuler : pointeur de mouvement d'entrée, renvoie un pointeur sur le mouvement de sortie
	// simule le mouvement
	Mouvement * simuler(Mouvement * mvt);
};