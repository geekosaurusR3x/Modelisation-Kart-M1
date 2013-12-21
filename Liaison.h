#pragma once

#include "Mouvement.h"

// Classe Liaison : repr�sente une liaison (classe abstraite) comportant une fonction virtuelle : simuler
// Une liaison est compl�tement ind�pendante des pi�ces. Elle poss�de un mouvement en entr�e (un pointeur !) et doit renvoyer un mouvement de sortie (un pointeur aussi !)
// Il y a 4 liaisons possibles : Rotation -> Translation, Translation -> Rotation, Rotation -> Rotation, Translation -> Translation
// Poss�de une donn�e membre : un coefficient de liaison (le mouvement de sortie est proportionnel � un mouvement d'entr�e (facteur de liaison), souvent �gal � 1

class Liaison
{
protected:
	double _coefficient;

public:
	//Simule la liaison avec un pointeur sur le mouvement en entr�e, et renvoie un pointeur sur le mouvement de sortie effectu�
    virtual Mouvement * simuler(Mouvement * mvt) = 0;
};