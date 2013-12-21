#include "Conversions.h"
#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"
#include "TIDestructionsSolides.h"
#include "TIColorerSolide.h"
#include "TINormaleFace.h"
#include "TIDecodagesSolides.h"
#include "TIDecodagesFaces.h"
#include "TINormaleFace.h"
#include "BDLumiereAmbiante.h"
#include "BDCreationBoite.h"
#include "BDCreationSphere.h"
#include "BDCreationEllipsoide.h"
#include "BDCreationDodecaedre.h"
#include "BDCreationSpikyDode.h"

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
#include "karting.h"
#include "SupportCremaillere.h"
#include "ChaineCinematique.h"
#include "Liaison.h"
#include "LiaisonRotationRotation.h"
#include "LiaisonRotationTranslation.h"
#include "LiaisonTranslationRotation.h"
#include "Mouvement.h"
#include "SupportVolant.h"

#include "Roue.h"


#include "Rotation.h"


#define ANGLEAXEDEPT PI/6
Karting::Karting()
{// construit le karting
	this->nbgoupilles = 0;
	this->chassis = Chassis();
	
	this->siege = Siege();
	this->siege.transposerVers(chassis.getRepere3DFixationSiege());

	this->arret = ArretTriangulaire();
	this->arret.transposerVers(chassis.getRepere3DFixationArriveeColonneDirection());


	Repere3D rep4(chassis.getRepere3DFixationFourche());
	Points3D pt = rep4.Origine();
	pt.ModifX(pt.X()+2.5);
	//support de volant
	SVolant = SupportVolant(rep4,23,9.5,5,5,1,5,1,1,1);
	SVolant.rotationSurZ(PI/2);
	SVolant.deplacerVers(pt);

	axePiedColonneDirection = AxePiedColonneDirection();
	axePiedColonneDirection.transposerVers(arret.getRepere3DEvidement());
	axePiedColonneDirection.rotationSurZ(PI/6);

	this->axe = Prisme();
	this->axe.transposerVers(axePiedColonneDirection.getRepere3DOppose());
	

	pignon = PignonStandard() ;
	pignon.transposerVers(axePiedColonneDirection.getRepere3DJointure());
	//pignon.rotationSurZ(PI/6);
	

	volant= Volant();
	volant.transposerVers(axe.getRepere3DOppose());
	
	supportRoueGauche= SupportRoue( Repere3D(),5,20,20,5,5,17,3,5,5.5,3,5,false,&AttributsFaces(PMateriauVert));
	supportRoueGauche.transposerVers(chassis.getPosition3DFixationRoueAvant(true));
	supportRoueGauche.rotationSurZ(PI/2);

	supportRoueDroite= SupportRoue( Repere3D(),5,20,20,5,5,17,3,5,5.5,3,5,true,&AttributsFaces(PMateriauVert));
	supportRoueDroite.transposerVers(chassis.getPosition3DFixationRoueAvant(false));
	supportRoueDroite.rotationSurZ(-PI/2);
	
	Repere3D rep6(supportRoueDroite.getRepere3DFixationInterieurRoue());
	AxeRD = AxeEpauleGoupillable(rep6,5,11, 14,5,3,5,2,2);

	Repere3D rep5(supportRoueGauche.getRepere3DFixationInterieurRoue());
	AxeRG = AxeEpauleGoupillable(rep5,5,11, 14,5,3,5,2,2);

	Repere3D reproueavd(AxeRD.getRepereFacePetitDiametre());
	RAvD = Roue(reproueavd,20,3,3);
	RAvD.rotationSurX(PI/2);
	RAvD.rotationSurZ(PI);

	Repere3D reproueavg(AxeRG.getRepereFacePetitDiametre());
	RAvG = Roue(reproueavg,20,3,3);
	RAvG.rotationSurX(PI/2);
	RAvG.rotationSurZ(PI);
	
	Repere3D reproueard(chassis.getRepere3DFixationRoueArriere(false));
	RArD = Roue(reproueard,20,3,3.8);
	pt = reproueard.Origine();
	pt.ModifY(pt.Y()-3.5);
	RArD.rotationSurX(PI/2);
	RArD.deplacerVers(pt);

	Repere3D reprouearg(chassis.getRepere3DFixationRoueArriere(true));
	RArG = Roue(reprouearg,20,3,3.8);
	pt = reprouearg.Origine();
	pt.ModifY(pt.Y()+3.5);
	RArG.rotationSurX(PI/2);
	RArG.deplacerVers(pt);

	Repere3D rep(chassis.getRepere3DFixationSupportCremaillereCentral());
	rep.ModifOrigine(rep.Origine() + 11 * rep.Z() + 3.25 * rep.X() + 7 * rep.Y());

	cremaillere= CremaillereStandard (chassis.getRepere3DFixationSupportCremaillereCentral());

	Repere3D rep3(chassis.getRepere3DFixationSupportCremaillereCentral());
	pt = rep3.Origine();
	
	cremaillere.rotationSurY(10*PI/180);

	cremaillere.rotationSurZ(-PI/2);
	// ajustement de la hauteur :
	pt.ModifZ(pt.Z()+6.5);
	// ajustement de la position 
	pt.ModifX(pt.X()-4);
	cremaillere.deplacerVers(pt);

	//bielleGauche = Bielle(cremaillere.getRepereTrouGauche())); (pour demo)
	bielleGauche = Bielle(supportRoueGauche.getRepere3DFixationBielle());
	
	bielleGauche.rotationSurZAlesage1(-2*PI/3 - PI/4);

	bielleDroite = Bielle(supportRoueDroite.getRepere3DFixationBielle()) ;
	
	bielleDroite.rotationSurZAlesage1(2*PI/3 + PI/4);

	
	Repere3D rep2(chassis.getRepere3DFixationSupportCremaillereCentral());
	pt = rep2.Origine();
	
	pt.ModifX(pt.X()+5);
	pt.ModifY(pt.Y()-10);
	pt.ModifZ(pt.Z()+1);

	supportcrema = SupportCremaillere(10.0,4, pt,10,2,5,10,2, 20);
	// on fait pivoter le support pour le mettre dans le bon sens :
	Matrices4D matriceRotation;
	matriceRotation.DevenirRotationQuelconque (pt,rep2.X(),PI/2);
	supportcrema.getSupport().Transformer(matriceRotation);
	matriceRotation.DevenirRotationQuelconque (pt,rep2.Z(),-PI);
	supportcrema.getSupport().Transformer(matriceRotation);

	// Mise en place des Goupilles : 
	/*Goupille(	const Repere3D& repere			= Repere3D(), 
				const double hauteur			= 10,
				const double diametre			= 3,
				const double longueurTete		= 5,
				AttributsFacesP *attributFace	= &AttributsFaces(PMateriauVert))
				throw(exception);*/
	// goupille sur les suport de roue : 
		
	goup[nbgoupilles] = Goupille(chassis.getPosition3DFixationRoueAvant(true),10,3,5);
	nbgoupilles++;
	
	goup[nbgoupilles] = Goupille(chassis.getPosition3DFixationRoueAvant(false),10,3,5);
	nbgoupilles++;
	// goupilles sur les Bielles : 
	goup[nbgoupilles] = Goupille(supportRoueGauche.getRepere3DFixationBielle(),10,3,5);
	goup[nbgoupilles].transposerVers(supportRoueGauche.getRepere3DFixationBielle());
	nbgoupilles++;
	goup[nbgoupilles] = Goupille(supportRoueDroite.getRepere3DFixationBielle(),10,3,5);
	goup[nbgoupilles].transposerVers(supportRoueDroite.getRepere3DFixationBielle());
	nbgoupilles++;

		// goupilles sur la cremaillere (Pour une raison inconnu mal placé) :
	goup[nbgoupilles] = Goupille(cremaillere.getRepereTrouGauche(),6,1,3);
	goup[nbgoupilles].deplacerVers(cremaillere.getRepereTrouGauche().Origine());
	
	nbgoupilles++;
	goup[nbgoupilles] = Goupille(cremaillere.getRepereTrouDroit(),6,1,3);
	goup[nbgoupilles].deplacerVers(cremaillere.getRepereTrouDroit().Origine());
	
	nbgoupilles++;
	construireCHaineCinematique();
	
	
}
void Karting::DessinerKarting(bool goupilles)
{// affiche le karting
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(chassis,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(siege,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(arret,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(axe,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(SVolant,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(supportRoueGauche,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(supportRoueDroite,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(bielleGauche,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(bielleDroite,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(volant,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(axePiedColonneDirection,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(pignon,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(cremaillere,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(supportcrema.getSupport(),-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(AxeRG,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(AxeRD,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(RAvD,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(RAvG,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(RArD,-1);
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(RArG,-1);

		if(goupilles)
			this->DessinerGoupilles();

}

Karting::~Karting()
{ 
	//nettoyage de la chaine cinematique :
	for(int i=0;i<7;i++)
		{
			delete LesCHaines[i] ;
			delete LesLiaison[i];
		}
}
void Karting::DessinerGoupilles()
{
	for(int i=0;i<nbgoupilles;i++)
		LogicielsGraphiquesBase::Defaut()->AfficherSolide(goup[i],-1);
}
void Karting::Mouvements(int degre)
{// applique un mouvement a l'ensemble des pieces qui bouges 
	// on lance l'execution : 
	Rotation mv(degre*PI/180); 
	LesCHaines[0]->simuler(&mv);
	// on recupere le tableau de mouvement et on l'applique au piece concerne
		// application au valant : 
		volant.rotationSurZ(degre);
		// application a la colonne :
		axe.rotationSurZ(LesCHaines[0]->_tabMvts[LesCHaines[0]->getNumLiaison()]->getValeur());
		// application au pignon:
		pignon.rotationSurZ(LesCHaines[0]->_tabMvts[LesCHaines[1]->getNumLiaison()]->getValeur());
		// application a la cremaillere:
		Points3D dest = cremaillere.getRepere3D().Origine();
		double val = (LesCHaines[0]->_tabMvts[LesCHaines[2]->getNumLiaison()]->getValeur());
		dest.ModifY(dest.Y()+val);
		cremaillere.deplacerVers(dest);
		// application aux  bieles :
		bielleGauche.rotationSurZAlesage2(LesCHaines[0]->_tabMvts[LesCHaines[3]->getNumLiaison()]->getValeur());
		bielleDroite.rotationSurZAlesage2(LesCHaines[0]->_tabMvts[LesCHaines[3]->getNumLiaison()]->getValeur());
		// application aux supports de roues :
		supportRoueDroite.rotationSurZ(LesCHaines[0]->_tabMvts[LesCHaines[4]->getNumLiaison()]->getValeur());
		supportRoueGauche.rotationSurZ(LesCHaines[0]->_tabMvts[LesCHaines[4]->getNumLiaison()]->getValeur());
		//application aux axes :
		AxeRG.transposerVers(supportRoueGauche.getRepere3DFixationInterieurRoue());
		AxeRD.transposerVers(supportRoueDroite.getRepere3DFixationInterieurRoue());
		
		//application aux roues :
		RAvG.transposerVers(AxeRG.getRepereFacePetitDiametre());
		RAvG.rotationSurX(PI/2);
		RAvG.rotationSurZ(PI);

		RAvD.transposerVers(AxeRD.getRepereFacePetitDiametre());
		RAvD.rotationSurX(PI/2);
		RAvD.rotationSurZ(PI);
}
void Karting::construireCHaineCinematique()
{
	// constructions des liaisons 
		// entre le voalant et l'axe :
		LesLiaison[0] = new LiaisonRotationRotation(1);
		// entre l'axe et le pigon
		LesLiaison[1] = new LiaisonRotationRotation(1);
		// entre le pignon et la cremaillere
		// la valeur de 0.05 est a ajuster pour coordonée le mouvement (un pigon 360 ° doit provoquer 18.8 de mouvement (circonferance du pignon) 
		LesLiaison[2] =  new LiaisonRotationTranslation(3,0.05);
		// entre la cremailllere et la biele droite
		LesLiaison[3] = new LiaisonTranslationRotation(20,1);
		// entre la biele et le support de roue droite
		LesLiaison[4] = new LiaisonRotationRotation(0.05);
		// de la maniere faite on ne peut avoir que une liaison !!!! alors que entre la crema et les bielle y en a deux a mouvement identique
		// liaison axe support
		LesLiaison[5] = new LiaisonRotationRotation(0.05);
		// liaison roue axe
		LesLiaison[6] = new LiaisonRotationRotation(0.05);
		// creation de la chaine 
		for(int i=0;i<7;i++)
		{
			LesCHaines[i] = new ChaineCinematique(LesLiaison[i]);
			if(i>0)
				LesCHaines[i-1]->ajouterSuivant(LesCHaines[i]);
		}

}
void Karting::rafraichirKarting()
{
	// on efface les pieces qui ont bougés 

		LogicielsGraphiquesBase::Defaut()->EffacerSolide(axe,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(supportRoueGauche,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(supportRoueDroite,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(bielleGauche,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(bielleDroite,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(volant,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(pignon,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(cremaillere,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(AxeRG,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(AxeRD,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(RAvD,-1);
		LogicielsGraphiquesBase::Defaut()->EffacerSolide(RAvG,-1);

	//reafichage :
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(axe,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(supportRoueGauche,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(supportRoueDroite,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(bielleGauche,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(bielleDroite,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(volant,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(pignon,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(cremaillere,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(AxeRG,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(AxeRD,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(RAvD,-1);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(RAvG,-1);
}