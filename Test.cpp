// => Dans le fichier : ApplicationRegainDlg.cpp
#include "stdafx.h"
// A METTRE EN HAUT DU FICHIER : 
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
/*

// A METTRE DANS UNE METHODE DE TEST

Chassis chassis;

Siege siege;
siege.transposerVers(chassis.getRepere3DFixationSiege());

ArretTriangulaire arret;
arret.transposerVers(chassis.getRepere3DFixationArriveeColonneDirection());

AxePiedColonneDirection axePiedColonneDirection;
axePiedColonneDirection.transposerVers(arret.getRepere3DEvidement());

Prisme axe;
axe.transposerVers(axePiedColonneDirection.getRepere3DOppose());

PignonStandard pignon;
pignon.transposerVers(axePiedColonneDirection.getRepere3DJointure());
pignon.rotationSurZ(PI/4);

Volant volant;
volant.transposerVers(axe.getRepere3DOppose());

SupportRoue supportRoueGauche;
supportRoueGauche.transposerVers(chassis.getPosition3DFixationRoueAvant(true));
supportRoueGauche.rotationSurZ(PI/2 + PI/5);

SupportRoue supportRoueDroite = SupportRoue(Repere3D(),5,20,20,5,5,15,3,5,7,3,5,true,&AttributsFaces(PMateriauVert));
supportRoueDroite.transposerVers(chassis.getPosition3DFixationRoueAvant(false));
supportRoueDroite.rotationSurZ(-PI/2 + PI/5);

// CODE TEMPORAIRE : ****
// TODO : Faire le support et recuperer le repere de celui-ci!
Repere3D rep(chassis.getRepere3DFixationSupportCremaillereCentral());
rep.ModifOrigine(rep.Origine() + 11 * rep.Z() 
	 + 3.25 * rep.X()
	 + 7 * rep.Y());
CremaillereStandard cremaillere(rep);
cremaillere.rotationSurY(-1.42);
//cremaillere.rotationSurX(PI);
// ****

Bielle bielleGauche, bielleDroite;
bielleGauche.transposerVers(supportRoueGauche.getRepere3DFixationBielle());
bielleGauche.rotationSurZAlesage1(-2*PI/3 - PI/5);

bielleDroite.transposerVers(supportRoueDroite.getRepere3DFixationBielle());
bielleDroite.rotationSurZAlesage1(2*PI/3 + PI/5);

LogicielsGraphiquesBase::Defaut()->AfficherSolide(chassis,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(siege,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(arret,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(axe,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(supportRoueGauche,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(supportRoueDroite,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(bielleGauche,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(bielleDroite,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(volant,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(axePiedColonneDirection,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(pignon,-1);
LogicielsGraphiquesBase::Defaut()->AfficherSolide(cremaillere,-1);*/