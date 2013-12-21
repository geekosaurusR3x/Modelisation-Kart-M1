#include "StdAfx.h"
#include "ChaineCinematique.h"

int ChaineCinematique::_nbLiaisons = -1;

vector<Mouvement *> ChaineCinematique::_tabMvts = vector<Mouvement *>();

ChaineCinematique::ChaineCinematique(Liaison* liaison)
{
	_liaison = liaison;

	_numLiaison = ++_nbLiaisons;
}

void ChaineCinematique::ajouterSuivant(ChaineCinematique * chaine)
{
	_listeChaine.push_back(chaine);
	// ajouter par yannick afin d'agrandire le tableau de mouvement
	_tabMvts.push_back(NULL);
}

void ChaineCinematique::setLiaison(Liaison* liaison)
{
	_liaison = liaison;
}

int ChaineCinematique::getNumLiaison() const
{
	return _numLiaison;
}

void ChaineCinematique::simuler(Mouvement * mvt)
{
	_tabMvts[_numLiaison] = _liaison->simuler(mvt);

	list<ChaineCinematique *>::iterator it;
	
	for(it=_listeChaine.begin(); it != _listeChaine.end(); it++)
		(*it)->simuler(mvt);
}