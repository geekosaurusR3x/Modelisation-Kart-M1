#pragma once

#include "Liaison.h"
#include "Vecteurs3D.h"

class LiaisonTranslationRotation : public Liaison
{
private:
	//le rayon de l'�l�ment tournant (ex : roue dent�e)
	double _rayon;

public:
	//Constructeur : le rayon de l'�l�ment tournant et le coefficient de la liaison en param�tre
	LiaisonTranslationRotation(double rayon, double coefficient);

	// Fonction virtuelle simuler : pointeur de mouvement d'entr�e, renvoie un pointeur sur le mouvement de sortie
	// simule le mouvement
	Mouvement * simuler(Mouvement * mvt);
};