#include "StdAfx.h"
#include "OutilPercageRectangulaire.h"
#include "BibliothequeMathematique.h"
#include "TIColorerSolide.h"

OutilPercageRectangulaire::OutilPercageRectangulaire(bool avecBaseHaut, bool avecBaseBas, double largeur, double longueur,double hauteur)
		 :OutilPercage(avecBaseHaut,avecBaseBas, 4){

	_longueur = longueur;
	_largeur = largeur;
	_hauteur = hauteur;
	buildAll();
}

OutilPercageRectangulaire::~OutilPercageRectangulaire(){

}


void OutilPercageRectangulaire::buildSommets(Tableaux<SommetsP>& sommetsBaseBas, Tableaux<SommetsP>& sommetsBaseHaut){
	
	// Point d'origine supérieur et inférieur
	Points3D pOrigineBas = Points3D(-_longueur/2,-_largeur/2,0);
	Points3D pOrigineHaut = Points3D(-_longueur/2,-_largeur/2,_hauteur);

	// Allocation des tableaux
	sommetsBaseBas = Tableaux<SommetsP>(_nombreFacettes, 1);
	sommetsBaseHaut = Tableaux<SommetsP>(_nombreFacettes, 1);

	// Parcourt de lu rectangle et construction de ses sommets
	sommetsBaseBas[0] = SommetsP( pOrigineBas ) ;
	sommetsBaseHaut[0] = SommetsP( pOrigineHaut ) ;

	sommetsBaseBas[1] = SommetsP( pOrigineBas + Points3D(_longueur,0,0) ) ;
	sommetsBaseHaut[1] = SommetsP( pOrigineHaut + Points3D(_longueur,0,0) ) ;

	sommetsBaseBas[2] = SommetsP( pOrigineBas + Points3D(_longueur,_largeur,0) ) ;
	sommetsBaseHaut[2] = SommetsP( pOrigineHaut + Points3D(_longueur,_largeur,0) ) ;
	
	sommetsBaseBas[3] = SommetsP( pOrigineBas + Points3D(0,_largeur,0) ) ;
	sommetsBaseHaut[3] = SommetsP( pOrigineHaut + Points3D(0,_largeur,0) ) ;
}