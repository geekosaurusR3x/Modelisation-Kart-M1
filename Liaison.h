#pragma once

#include "Mouvement.h"

// Classe Liaison : représente une liaison (classe abstraite) comportant une fonction virtuelle : simuler
// Une liaison est complètement indépendante des pièces. Elle possède un mouvement en entrée (un pointeur !) et doit renvoyer un mouvement de sortie (un pointeur aussi !)
// Il y a 4 liaisons possibles : Rotation -> Translation, Translation -> Rotation, Rotation -> Rotation, Translation -> Translation
// Possède une donnée membre : un coefficient de liaison (le mouvement de sortie est proportionnel à un mouvement d'entrée (facteur de liaison), souvent égal à 1

class Liaison
{
protected:
	double _coefficient;

public:
	//Simule la liaison avec un pointeur sur le mouvement en entrée, et renvoie un pointeur sur le mouvement de sortie effectué
    virtual Mouvement * simuler(Mouvement * mvt) = 0;
};