#include "StdAfx.h"
#include "OutilPercageCylindrique.h"
#include "BibliothequeMathematique.h"
#include "TIColorerSolide.h"

OutilPercageCylindrique::OutilPercageCylindrique(bool avecBaseHaut, bool avecBaseBas, int nombreFacettes, const double rayon, const double hauteur)
		 :OutilPercage(avecBaseHaut,avecBaseBas, nombreFacettes){

	// Valeurs par défaut
	_rayon = rayon;
	_hauteur = hauteur;
	buildAll();
}

OutilPercageCylindrique::~OutilPercageCylindrique(){

}


void OutilPercageCylindrique::buildSommets(Tableaux<SommetsP>& sommetsBaseBas, Tableaux<SommetsP>& sommetsBaseHaut){

	// Paramétrage des points d'origine (En bas et en haut du cylindre)
	Points3D pOrigineBas = Points3D(_rayon,0,0);
	Points3D pOrigineHaut = pOrigineBas + _hauteur * _repere.Z();

	// Création des tableaux de sommets
	sommetsBaseBas = Tableaux<SommetsP>(_nombreFacettes, 1);
	sommetsBaseHaut = Tableaux<SommetsP>(_nombreFacettes, 1);

	// Affectation du premier sommet
	sommetsBaseBas[0] = SommetsP( pOrigineBas ) ;
	sommetsBaseHaut[0] = SommetsP( pOrigineHaut ) ;

	// Création d'une matrice rotation, à partir du point (0,0,0) sur l'axe _direction
	// de rotation 2*PI/_nombreFacettes
	// Permet de creer tous les sommets du cylindre en tournant autour de l'axe central
	Matrices4D matriceRotation;
	matriceRotation.DevenirRotationOZ(2*PI/_nombreFacettes);

	// Création des sommets en tournant autour de l'axe _direction graxe à la matrice de rotation
	for(int i=1 ; i<_nombreFacettes ;i++){
		sommetsBaseBas[i] = sommetsBaseBas[i-1].Point3D() * matriceRotation ;
		sommetsBaseHaut[i] = sommetsBaseHaut[i-1].Point3D() * matriceRotation ;
	}
}