#pragma once 
#include "OutilPercage.h"
#include "Bielle.h"
#include "SupportRoue.h"
#include "Chassis.h"
#include "Repere3D.h"
#include "AxeEpauleGoupillable.h"
#include "Volant.h"
#include "ArretTriangulaire.h"
#include "Siege.h"
#include "Goupille.h"
#include "AxePiedColonneDirection.h"
#include "PignonStandard.h"
#include "CremaillereStandard.h"
#include "SupportCremaillere.h"
#include "ChaineCinematique.h"
#include "Liaison.h"
#include "SupportVolant.h"
#include "Roue.h"
public class Karting 
{
private :
	Chassis chassis;
	Siege siege;
	ArretTriangulaire arret;
	Prisme axe;
	PignonStandard pignon;
	Volant volant;
	SupportRoue supportRoueGauche;

	SupportRoue supportRoueDroite;
	Bielle bielleGauche ;
	SupportCremaillere supportcrema;  

	Bielle bielleDroite ;
	
	CremaillereStandard cremaillere;
	
	SupportVolant SVolant;
	AxeEpauleGoupillable AxeRG,AxeRD;
	Roue RAvD,RAvG,RArD,RArG;

	AxePiedColonneDirection axePiedColonneDirection;
	Goupille goup [10];
	int nbgoupilles;

	ChaineCinematique * LesCHaines[7];
	Liaison *  LesLiaison[7];

	void DessinerGoupilles();
	void construireCHaineCinematique();
public : 
	Karting();
	void DessinerKarting(bool goupilles = false);
	void rafraichirKarting();
	~Karting();
	void Mouvements(int degre);
	
};