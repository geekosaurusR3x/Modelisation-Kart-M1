/*
Création :				Christophe ELSENSOHN
Date de création :		05/04/2012
Version :				0
Modifié par:			Oussam LARKEM
Date de modification:	23/05/2012
*/
#include "StdAfx.h"
#include "SupportVolant.h"
#include "Perceuse.h"
#include "OutilPercage.h"
#include "OutilPercageCylindrique.h"

#define NIVEAU_DETAIL 32 //cavité
#define NIVEAU_DETAIL_TROUS 32


//Destructeur de la classe SupportVolant
SupportVolant::~SupportVolant()
{
	//Rien à désallouer
}

/*
Constructeur de la classe SupportVolant
#PARAMETRES
	- repere	      (const Repere3D&)	   :  La hauteur suivra l'axe Z de ce repère.
						    				  La largeur suivra l'axe X de ce repère.
											  L'épasseur suivra l'axe Y de ce repère.
											  origine se trouvant sur la face dont le vecteur normal est opposé à l'axe Y du repère fourni.
											  Ce point se trouve au mileu de la largeur à la basse du support.

	- hauteur			(double)			: hauteur du support (axe Z)

	- largeur			(double)			: largeur du support (axe X)

	- epaisseur	        (double)			: épaisseur du support (axe Y).

	- profondeurCavit1  (double)	    	: pronfondeur de la cavité arrière (y==0) jusqu'au centre du cercle (profondeur totale = profondeurCavit + largeurCavit/2 )

	- profondeurCavit2  (double)	    	: pronfondeur de la cavité avant (y == _epaisseur) jusqu'au centre du cercle (profondeur totale = profondeurCavit + largeurCavit/2 )

	- largeurCavit      (double)			: largeur de la cavité

	- hauteurTrous      (double)			: hauteur des troue à partir de le base

	- ecartementTrous   (double)			: écartement des trous (x2 la distance des trous à partir de l'axe)

	- diametreTrous     (double)			: diamètre des trous

	_ PtAF	        	(AttributFacesP*)   : couleur des faces.
*/
SupportVolant::SupportVolant(const Repere3D& repere,double hauteur,double largeur, double epaisseur,
	double profondeurCavit1,double profondeurCavit2,double largeurCavit,double hauteurTrous,double ecartementTrous,double diametreTrous,AttributsFacesP *PtAF):
		Piece(repere,PtAF),_epaisseur(epaisseur),_largeur(largeur),_hauteur(hauteur)
{
	
	_profondeurCavit1 = profondeurCavit1;
	_profondeurCavit2 = profondeurCavit2;
	_largeurCavit = largeurCavit;
	_hauteurTrous = hauteurTrous;
	_ecartementTrous = ecartementTrous;
	_diametreTrous = diametreTrous;

	buildAll();
}



/*
Getter du Vecteurs3D de la direction du Support Volant
*/
const Vecteurs3D SupportVolant::getDirection()const{
	return _repere.Y();
}

const Repere3D SupportVolant::getRepere3DOppose() const{
	return Repere3D(_repere.Origine() /*+ getLongueur() * _repere.Z()*/, _repere.X(), _repere.Y(), _repere.Z());
}

/*
Getter de la hauteur du SupportVolant
*/
double SupportVolant::getHauteur()const
{
	return _hauteur;
}

/*
Getter de la Largeur du SupportVolant
*/
double SupportVolant::getLargeur()const
{
	return _largeur;
}

/*
Getter de l'epaisseur du SupportVolant
*/
double SupportVolant::getEpaisseur() const
{
	return _epaisseur;
}


double SupportVolant::getProfondeurCavit1() const
{

	return _profondeurCavit1;

}

double SupportVolant::getProfondeurCavit2() const
{

	return _profondeurCavit2;

}

double SupportVolant::getLargeurCavit() const
{

	return _largeurCavit;

}

/*
Getter de la Droites3D du SupportVolant
*/
const Droites3D& SupportVolant::getAxe() const
{
	return _axe;
}


/*
Méthode de construction du Support Volant
Le SupportVolant ainsi construit aura :
	- la Hauteur    suivant Z du repère
	- la Largeur    suivant X du repère
	- la Epaisseur  suivant Y du repère
*/
void  SupportVolant::buildAll(){
	/*############################################################################
	UNE TECHNIQUE POUR GENERER LES 2 AUTRES VECTEURS D'UN REPERE DIRECT ORTHONORME
	A PARTIR D'UN VECTEUR REPRESENTANT L'AXE Z LOCAL NOMMEE _direction
	#############################################################################*/


	//Mémorisation des Vecteurs à partir du repère
	Vecteurs3D axeX_supportVolant =_repere.X();
	Vecteurs3D axeY_supportVolant =_repere.Y();
	Vecteurs3D axeZ_supportVolant =_repere.Z();
	
	//Liste des Points3D qui serviront à générer le profil.
	Listes<Points3D> ptsPlanBase;

	Listes<SommetsP> SommetsPlan;
	//Calcul des demi_largeur pour centrer le support sur sa largeur

	double _demiLargeur = _largeur/2;



	//*************************
	
	//Ajout des sommets de la premiere face dans la Listes<SommetsP>

    FacesP faceAPercer1;
	FacesP faceAPercer2;

	SommetsPlan.InsertionEnQueue (SommetsP(_repere.Origine()+ _demiLargeur *axeX_supportVolant+ _hauteur *axeZ_supportVolant));
	
	SommetsPlan.InsertionEnQueue (SommetsP(_repere.Origine()+ (_largeurCavit/2) *axeX_supportVolant+ _hauteur *axeZ_supportVolant));

	
	for(int i = 0 ; i <= NIVEAU_DETAIL ; i++)
		SommetsPlan.InsertionEnQueue (SommetsP( _repere.Origine() + ( ( _largeurCavit/2* cos ((double)(i)/NIVEAU_DETAIL*PI))  ) * axeX_supportVolant
			+ (_hauteur-_profondeurCavit1 - ( _largeurCavit/2* sin((double)(i)/NIVEAU_DETAIL*PI)) ) *axeZ_supportVolant ));

	
	SommetsPlan.InsertionEnQueue (SommetsP(_repere.Origine()+ (-_largeurCavit/2) *axeX_supportVolant+ _hauteur *axeZ_supportVolant));
	SommetsPlan.InsertionEnQueue (SommetsP(_repere.Origine()- _demiLargeur *axeX_supportVolant+ _hauteur *axeZ_supportVolant));
	SommetsPlan.InsertionEnQueue (SommetsP(_repere.Origine()- _demiLargeur *axeX_supportVolant + 0 *axeZ_supportVolant));
	SommetsPlan.InsertionEnQueue (SommetsP(_repere.Origine()+ _demiLargeur *axeX_supportVolant + 0 *axeZ_supportVolant));

	//************************************************************************************************

	Tableaux<AretesP> tabAretes;

	for(int i = 0 ; i < NIVEAU_DETAIL+6 ; i++ )
	{
		tabAretes[i] = AretesP(SommetsPlan[i],SommetsPlan[i+1]);


	}

	tabAretes[NIVEAU_DETAIL+6]= AretesP(SommetsPlan[NIVEAU_DETAIL+6],SommetsPlan[0]);
		ContoursP C(tabAretes);
	 faceAPercer1 = FacesP(C,_attributFace);


	////////////////////////*********************************

	 //Ajout des sommets de la premiere face dans la Listes<SommetsP>

	Listes<SommetsP> SommetsPlan2;

	SommetsPlan2.InsertionEnQueue (SommetsP(_repere.Origine()+ _demiLargeur *axeX_supportVolant+ _hauteur *axeZ_supportVolant+_epaisseur*axeY_supportVolant));
	
	SommetsPlan2.InsertionEnQueue (SommetsP(_repere.Origine()+ (_largeurCavit/2) *axeX_supportVolant+ _hauteur *axeZ_supportVolant+_epaisseur*axeY_supportVolant));

	
	for(int i = 0 ; i <= NIVEAU_DETAIL ; i++)
		SommetsPlan2.InsertionEnQueue (SommetsP( _repere.Origine() + ( ( _largeurCavit/2* cos ((double)(i)/NIVEAU_DETAIL*PI))  ) * axeX_supportVolant
			+ (_hauteur-_profondeurCavit2 - ( _largeurCavit/2* sin((double)(i)/NIVEAU_DETAIL*PI)) ) *axeZ_supportVolant +_epaisseur*axeY_supportVolant));

	
	SommetsPlan2.InsertionEnQueue (SommetsP(_repere.Origine()+ (-_largeurCavit/2) *axeX_supportVolant+ _hauteur *axeZ_supportVolant+_epaisseur*axeY_supportVolant));
	SommetsPlan2.InsertionEnQueue (SommetsP(_repere.Origine()- _demiLargeur *axeX_supportVolant+ _hauteur *axeZ_supportVolant+_epaisseur*axeY_supportVolant));
	SommetsPlan2.InsertionEnQueue (SommetsP(_repere.Origine()- _demiLargeur *axeX_supportVolant + 0 *axeZ_supportVolant+_epaisseur*axeY_supportVolant));
	SommetsPlan2.InsertionEnQueue (SommetsP(_repere.Origine()+ _demiLargeur *axeX_supportVolant + 0 *axeZ_supportVolant+_epaisseur*axeY_supportVolant));

	

	for(int i = NIVEAU_DETAIL+6 ; i > 0 ; i-- )
	{
		tabAretes[NIVEAU_DETAIL+6-i] = AretesP(SommetsPlan2[i],SommetsPlan2[i-1]);


	}

	tabAretes[NIVEAU_DETAIL+6]= AretesP(SommetsPlan2[0],SommetsPlan2[NIVEAU_DETAIL+6]);
	C = ContoursP(tabAretes);
	faceAPercer2 = FacesP(C,_attributFace);

	///***percage

	OutilPercageCylindrique outil1 = OutilPercageCylindrique(false, false, NIVEAU_DETAIL_TROUS, _diametreTrous , _epaisseur);
	Perceuse::percer(_repere.Origine()+ (_ecartementTrous/2)*axeX_supportVolant+(_hauteurTrous)*axeZ_supportVolant, *this, faceAPercer2, faceAPercer1, &outil1);
	OutilPercageCylindrique outil2 = OutilPercageCylindrique(false, false, NIVEAU_DETAIL_TROUS, _diametreTrous, _epaisseur);
	Perceuse::percer(_repere.Origine()+ (-_ecartementTrous/2)*axeX_supportVolant+(_hauteurTrous)*axeZ_supportVolant, *this, faceAPercer2, faceAPercer1, &outil2);

	//***

	//ajout des face à l'objet

	AjouterFace(faceAPercer1);
	AjouterFace(faceAPercer2);

	Tableaux<AretesP> tab4Aretes;
	
	for(int i = 0 ; i < NIVEAU_DETAIL+6 ; i++ )
	{
		tab4Aretes[0] = AretesP(SommetsPlan2[i],SommetsPlan2[i+1]);
		tab4Aretes[1] = AretesP(SommetsPlan2[i+1],SommetsPlan[i+1]);
		tab4Aretes[2] = AretesP(SommetsPlan[i+1],SommetsPlan[i]);
		tab4Aretes[3] = AretesP(SommetsPlan[i],SommetsPlan2[i]);
		C = ContoursP(tab4Aretes);
		AjouterFace(FacesP(C,_attributFace));
	}
	

	tab4Aretes[0] = AretesP(SommetsPlan2[NIVEAU_DETAIL+6],SommetsPlan2[0]);
		tab4Aretes[1] = AretesP(SommetsPlan2[0],SommetsPlan[0]);
		tab4Aretes[2] = AretesP(SommetsPlan[0],SommetsPlan[NIVEAU_DETAIL+6]);
		tab4Aretes[3] = AretesP(SommetsPlan[NIVEAU_DETAIL+6],SommetsPlan2[NIVEAU_DETAIL+6]);
		C = ContoursP(tab4Aretes);
		AjouterFace(FacesP(C,_attributFace));


	

	//FIN************************************************************************************************************************
	



	//Mémorisation de l'axe du Support
	_axe=Droites3D(_repere.Origine(), _repere.Z());
}
