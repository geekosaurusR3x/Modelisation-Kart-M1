#pragma once

#include <list>
#include <vector>
#include "Liaison.h"
#include <iostream>

using namespace std;

// Classe ChaineCinematique
// Repr�sente la chaine sous forme de liste de noeuds compos�s d'une liaison et d'une liste de chaines cin�matiques � ajouter en suivant d'une chaine

class ChaineCinematique
{
private:
	list<ChaineCinematique *> _listeChaine; // Liste des chaines suivantes du noeud en cours
	Liaison* _liaison; // La liaison

	static int _nbLiaisons; // Nombre de liaisons (mis � jour au fur et � mesure d'ajout de liaisons)
	int _numLiaison; // prend d�j� en compte l'indi�age du tableau (commence � 0 => -1)
	
public:

	// tableau de Mouvements en sortie de chaque liaison, il peut �tre consult� via le num�ro de la liaison en indice, et obtient � cet indice le mouvement de sortie
	// /!\ on stocke des pointeurs de mouvements !
	static vector<Mouvement *> _tabMvts;

	ChaineCinematique(Liaison* liaison);

	// ajouter une chaine � la liste des suivants
	void ajouterSuivant(ChaineCinematique * chaine);

	void setLiaison(Liaison* liaison);

	// obtenir le num�ro de liaison courante
	int getNumLiaison() const;

	// Fonction simuler r�cursive : simule la liaison, ce qui remplit le tableau _tabMvts dans l'ordre de la chaine, et appelle r�cursivement la fonction simuler de chaque chaine suivante
	// Prend le mouvement d'entr�e en param�tre (un pointeur de mouvement)
	void simuler(Mouvement * mvt);
};