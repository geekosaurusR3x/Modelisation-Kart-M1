#include "StdAfx.h"
#include "OutilPercage.h"
#include "BibliothequeMathematique.h"
#include "TIColorerSolide.h"
#include <exception>
OutilPercage::OutilPercage(bool avecBaseHaut, bool avecBaseBas, int nombreFacettes)
		 // Par défaut, l'outil est constuit en (0,0,0) sur O
		 :Piece(Repere3D(Points3D(0,0,0), *IMonde, *JMonde, *KMonde), new AttributsFaces(PMateriauRouge)){

	// Valeurs par défaut
	_avecBaseHaut = avecBaseHaut;
	_avecBaseBas = avecBaseBas;
	_nombreFacettes = nombreFacettes;
}

OutilPercage::~OutilPercage(){

}

 const ContoursP OutilPercage::getContourDePercage(){
	
	// Si la base supérieur est affiché, on retourne la base du bas
	if( _avecBaseHaut && ! _avecBaseBas)
		return getContourBaseBas();

	// Inversement pour la base inférieur
	else if ( _avecBaseBas )
		return getContourBaseHaut();
	else
		throw new exception("Le cylindre doit comporter une face vide! Re-construisez l'objet avec les paramètres recommandés");
}

void OutilPercage::buildAll(){

	// Création des tableaux de sommets
	Tableaux<SommetsP> sommetsBaseBas, sommetsBaseHaut;

	// Construction des sommets de l'outils en fonction de sa topologie
	buildSommets(sommetsBaseBas, sommetsBaseHaut);

	// Création des tableaux d'aretes de l'outil 
	Tableaux<AretesP> aretes(4,1);
	Tableaux<AretesP> aretesBaseHaut(_nombreFacettes,1);
	Tableaux<AretesP> aretesBaseBas(_nombreFacettes,1);
	Tableaux<AretesP> aretesLat(_nombreFacettes,1);

	// La création d'arêtes est différente en fonction du mode de création et de la topologie de l'outil
	int i;

	// Création des aretes pour les n prochaines faces
	for (i = 0 ; i < _nombreFacettes;i++)
	{
		aretesBaseBas[i] = AretesP( sommetsBaseBas[i], sommetsBaseBas[(i+1) % _nombreFacettes] );
		aretesBaseHaut[i] = AretesP( sommetsBaseHaut[i], sommetsBaseHaut[(i+1) % _nombreFacettes] );
		aretesLat [i] = AretesP( sommetsBaseBas[i], sommetsBaseHaut[i] );
    }

	// Création des facettes latérales
	for (i = 0 ; i < _nombreFacettes;i++)
	{
			aretes[0] = aretesLat [i] ;
			aretes[1] = aretesBaseHaut[i];
			aretes[2] = aretesLat [(i+1) % _nombreFacettes] ;
			aretes[3] = aretesBaseBas[i];
			AjouterFace(FacesP( ContoursP(aretes), _attributFace ));
	}

	// Attention : Il faut inverser les aretes du haut pour que la normale soit en dehors de la matière
	aretesBaseHaut.Inversion();

	// Ajout des faces supérieurs et inférieurs
	AjouterFace(FacesP( ContoursP( aretesBaseHaut ), _attributFace ));	// Avant derniere face : Face du haut
	AjouterFace(FacesP( ContoursP( aretesBaseBas ), _attributFace ));	// Derniere face : Face du bas
}



ContoursP OutilPercage::getContourBaseHaut(){

	// On retourne l'avant dernier contour enregistré 
	// Correspond à la face du haut
	Tableaux<FacesP> faces = TableauFaces();
	return faces[NombreFaces()-2].ContourExterieur();
}

ContoursP OutilPercage::getContourBaseBas() {

	// On retourne le dernier contour enregistré 
	// Correspond à la face du bas
	Tableaux<FacesP> faces = TableauFaces();
	return faces[NombreFaces()-1].ContourExterieur();
}

bool OutilPercage::avecBaseBas() const{
	return _avecBaseBas;
}

bool OutilPercage::avecBaseHaut() const{
	return _avecBaseHaut;
}

Tableaux<FacesP> OutilPercage::faceOutils(){
	Tableaux<FacesP> faces = Tableaux<FacesP>(TableauFaces());

	// Si la base du haut est paramétré comme innexistante, 
	// On la supprime
	if( !_avecBaseHaut )
		faces.Supprimer(TableauFaces()[NombreFaces()-2]);

	// Si la base du bas est paramétré comme innexistante, 
	// On la supprime
	if( !_avecBaseBas )
		faces.Supprimer(TableauFaces()[NombreFaces()-1]);
	return faces;
}