#pragma once

#include <list>
#include <vector>
#include "Liaison.h"
#include <iostream>

using namespace std;

// Classe ChaineCinematique
// Représente la chaine sous forme de liste de noeuds composés d'une liaison et d'une liste de chaines cinématiques à ajouter en suivant d'une chaine

class ChaineCinematique
{
private:
	list<ChaineCinematique *> _listeChaine; // Liste des chaines suivantes du noeud en cours
	Liaison* _liaison; // La liaison

	static int _nbLiaisons; // Nombre de liaisons (mis à jour au fur et à mesure d'ajout de liaisons)
	int _numLiaison; // prend déjà en compte l'indiçage du tableau (commence à 0 => -1)
	
public:

	// tableau de Mouvements en sortie de chaque liaison, il peut être consulté via le numéro de la liaison en indice, et obtient à cet indice le mouvement de sortie
	// /!\ on stocke des pointeurs de mouvements !
	static vector<Mouvement *> _tabMvts;

	ChaineCinematique(Liaison* liaison);

	// ajouter une chaine à la liste des suivants
	void ajouterSuivant(ChaineCinematique * chaine);

	void setLiaison(Liaison* liaison);

	// obtenir le numéro de liaison courante
	int getNumLiaison() const;

	// Fonction simuler récursive : simule la liaison, ce qui remplit le tableau _tabMvts dans l'ordre de la chaine, et appelle récursivement la fonction simuler de chaque chaine suivante
	// Prend le mouvement d'entrée en paramètre (un pointeur de mouvement)
	void simuler(Mouvement * mvt);
};