/*
Création :				Christophe ELSENSOHN 
Date de création :		09/04/2012
Version :				4
Modifié par:			Christophe ELSENSOHN 
Date de modification:	13/04/2012
*/

#include "StdAfx.h"
#include "CremaillereStandard.h"
#include "ArretTriangulaire.h"
#include "OutilPercageCylindrique.h"
#include "Perceuse.h"

#define DELTA 0.0001

//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################

//*****************************************************************************
//						CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Constructeur d'instance de CremaillereStandard 

/*
PARAMETRES
		
	- repere							(const Repere3D&)	:	repère de la crémaillère.
																L'axe de travail de la crémaillère suivra l'axe X du repère
																L'origine se trouvera sur la face inférieure
																(opposée aux dents) à l'intersection des diagonales de
																la face.
												  
	- nbDents							(unsigned int)		:	nombre de dents du bloc denture.
		
	- module							(double)			:	Définitions wikipédia :
																	"paramètre dimensionnel générateur relatif à la périodicité des dents donc à leur taille. "
																	"Quotient du diamètre primitif par le nombre de dents"
																Plus simplement le diamètre primitif est compris entre le grand diamètre, dit de tête, et le petit diamètre, dit de pied.
																Le nombre de dents * le module donne le diamètre primitif.
																Pour une crémaillère cela n'a pas de sens de parler de diamètre, cependant, pour que 2
																éléments puissent s'entrainer l'un l'autre, ils doivent avoir le même module.
		
	- longueurTotale					(double)			:	Longueur totale de la crémaillère.
																Egale à la longueur du bloc de denture + 2 * la longueur des bloc inclinés.
		
	- longueurBlocDentures				(double)			:	longueur du bloc de denture. 
													
	- largeurCremaillere				(double)			:	largeur de la crémaillère (suivant l'axe d'une dent)
		
	- distanceBase_HautDenture			(double)			:	distance entre la face de base (inférieure) et le haut des dents.
		
	- hauteurBasePlanIncline			(double)			:	dimension du plat de la face avant.
																dimension à partir de la face inférieure
																le haut de ce plat définira le début de la partie incliné
														
	- anglePlat							(double)			:	angle d'inclinaison de la partie inclinée.
																angle entre la partie supérieure (horizon local) et la partie incliné.
	
	- diamPercage						(double)			:	diamètre de percage des trous.
	
	- profondeurPercage					(double)			:	profondeur de percage des trous.

	- distancePercageDepuisExtremite	(double)		:	distance de percage des trous depuis leurs extrémités respectives.
		
	- PtAF								(AttributsFacesP*)	:	Attribut des faces de l'axe épaulé goupillable. 
																Représente la couleur de l'axe épaulé goupillable.

---------------------------------------------------------
---------------------RECOMMANDATIONS---------------------
---------------------------------------------------------
Le percage des trous se fait au milieu de la pente.

Il est possible de mettre un angle de plat à:
0		-->	il n'y a pas d'inclinaison.
PI/2	-->	Il n'y a pas d'inclinaison apparente. Les trous sont faits sur la face avant.
			Pour les avoir centrés sur la hauteur de la face avant, mettez le paramètre hauteurBasePlanIncline à 0.


EXCEPTIONS LEVEES
Une exception sera levé si:
- La combinaison du nombre de dents et du module font que les dents débordent du bloc denture.
- La longueur totale est inférieure à la longueur du bloc denture.
- La hauteur (paramètre distanceBase_HautDenture) est inférieure à la hauteur d'un dent (définie par le module).
- la hauteur des plats avants (paramètre hauteurBasePlanIncline) est supérieure à la hauteur totale de la crémaillère.
- la distance de percage ( paramètre distancePercageDepuisExtremite) est inférieure au diamètre de percage.

*/
CremaillereStandard::CremaillereStandard(	const Repere3D& repere,
											unsigned int nbDents,
											double module,
											double longueurTotale,
											double longueurBlocDentures,
											double largeurCremaillere,
											double hauteurBaseAxeTravail,
											double hauteurBasePlanIncline,
											double anglePlat,
											double diamPercage,
											double profondeurPercage,
											double distancePercageDepuisExtremite,
											AttributsFacesP *PtAF)
											:
											Piece(repere,PtAF),
											_nbDents(nbDents),
											_module(module),
											_lgTotal(longueurTotale),
											_demiLongueurBlocDentures(longueurBlocDentures/2),
											_largeurCrem(largeurCremaillere),
											_hauteurBaseTete(hauteurBaseAxeTravail),
											_hauteurBase(hauteurBasePlanIncline),
											_anglePlat(anglePlat),
											_rayonPercage(diamPercage/2),
											_profPercage(profondeurPercage),
											_distPercExtrem(distancePercageDepuisExtremite),
											_largeurBlocIncline((_lgTotal-longueurBlocDentures)/2)
{
	ControleValiditeArgConstruct();
	buildAll();
	
}


//_____________________________________________________________________________
//
//	Constructeur par recopie de CremaillereStandard

CremaillereStandard::CremaillereStandard(const CremaillereStandard& cremaillere):Piece(cremaillere),
											_nbDents(cremaillere._nbDents),
											_module(cremaillere._module),
											_lgTotal(cremaillere._lgTotal),
											_demiLongueurBlocDentures(cremaillere._demiLongueurBlocDentures),
											_largeurCrem(cremaillere._largeurCrem),
											_hauteurBaseTete(cremaillere._hauteurBaseTete),
											_hauteurBase(cremaillere._hauteurBase),
											_anglePlat(cremaillere._anglePlat),
											_rayonPercage(cremaillere._rayonPercage),
											_profPercage(cremaillere._profPercage),
											_distPercExtrem(cremaillere._distPercExtrem),
											_largeurBlocIncline(cremaillere._largeurBlocIncline)
{
	//inutile de récupérer 
	//	_facePlanInclineXMoins
	//	_OriginePtPercageXMoins
	//	_OriginePtPercageXPlus
	//Ils seront déterminé dans buildAll
	buildAll();
}

//_____________________________________________________________________________
//
//	Destructeur de CremaillereStandard

CremaillereStandard::~CremaillereStandard(void)
{
	//Rien alloué dynamiquement
}

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************
 
//_____________________________________________________________________________
//
//	Getter de l'axe de travail de la crémaillère.

Droites3D CremaillereStandard::getAxe()const{
	return Droites3D(_repere.Origine(),_repere.X());
}

//_____________________________________________________________________________
//
//	Getter du repère du trou gauche, ou en X moins du repère local

Repere3D CremaillereStandard::getRepereTrouGauche()const{
	return creerRepereTrou(_OriginePtPercageXMoins);
}

//_____________________________________________________________________________
//
//	Getter du repère du trou droit, ou en X plus du repère local

Repere3D CremaillereStandard::getRepereTrouDroit()const{
	return creerRepereTrou(_OriginePtPercageXPlus);
}

//#############################################################################
//								DOMAINE PRIVE
//#############################################################################

//*****************************************************************************
//									METHODES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Méthode qui crée un Repere sur le point atteins par le vecteur passé en paramètre depuis l'origine.

Repere3D CremaillereStandard::creerRepereTrou(const Vecteurs3D& vecteurOrigineCentreTrou)const{
	Points3D centreTrou=_repere.Origine()+vecteurOrigineCentreTrou.X()*_repere.X()+vecteurOrigineCentreTrou.Y()*_repere.Y()+vecteurOrigineCentreTrou.Z()*_repere.Z();
	
	Vecteurs3D z= _facePlanInclineXMoins.VecteurNormal().VecteurNorme();
	Vecteurs3D x= _repere.X().VecteurNorme();
	Vecteurs3D y= (z&x).VecteurNorme();
	return Repere3D(centreTrou,x,y,z);
}

//_____________________________________________________________________________
//
//	Méthode de construction de la crémaillère.Pour plus de détail voir dans le code.

void CremaillereStandard::buildAll(){
	double alphaDenture=2*PI/18; //20°
	double tanAlphaDenture=tan(alphaDenture);
	double distX_TeteTravail=1*_module*tanAlphaDenture;
	double distX_PiedTravail=1.4*_module*tanAlphaDenture;
	double distZ_TeteTravail=_module;
	double distZ_PiedTravail=1.4*_module;
	double pas=PI*_module;
	double demiPas=pas/2;
	double quartPas=pas/4;
	double distX_intersec_AxeTravail_FlanDentureExtreme=(2*_nbDents+1)*quartPas;
	const Vecteurs3D& z=_repere.Z();//*KMonde;
	const Vecteurs3D& y=_repere.Y();//*JMonde;
	const Vecteurs3D& x=_repere.X();//*IMonde;
	const Points3D& origine=_repere.Origine();
	const Points3D refDenture=origine+_largeurCrem/2*y+(_hauteurBaseTete-distZ_TeteTravail)*z;
	Listes<Points3D> ptsProfilGenerateur;
/*
0      1         4     5        8     9       12     13       16      17
 _______          _____          _____          _____          _______		hauteur de tete
|       \        /     \        /     \        /     \        /       |		@ = refDenture locale se trouve sur l'axe de travail
|        \      /       \      /   @   \      /       \      /        |
|         \____/         \____/         \____/         \____/         |
|        2      3        6    7        10    11       14    15        |		hauteur de pied
|_____________________________________________________________________|
19													                  18

 zlocal
/ \
 |
 |
 ------>xlocal
*/
	//-------------------------------------
	// Création du départ de la face des dentures
	//-------------------------------------
	//Points de départ du bloc de crémaillère.
	//Correspond au point 0 du schéma
	Points3D depart=refDenture-_demiLongueurBlocDentures*x+distZ_TeteTravail*z;
	ptsProfilGenerateur.InsertionEnQueue(depart);
	
	//correspond au point 1 du schéma
	Points3D ptDepartTeteDenture=refDenture-(distX_intersec_AxeTravail_FlanDentureExtreme+distX_TeteTravail)*x+distZ_TeteTravail*z;
	ptsProfilGenerateur.InsertionEnQueue(ptDepartTeteDenture);
	
	//correspond au point 2 du schéma
	Points3D ptDepartPiedDenture=refDenture-(distX_intersec_AxeTravail_FlanDentureExtreme-distX_PiedTravail)*x-distZ_PiedTravail*z;
	ptsProfilGenerateur.InsertionEnQueue(ptDepartPiedDenture);


/*
On réalise ceci pour chaque dent
		B     C
		 _____
        /     \
       /       \
	  /    @    \
	 /           \
	A             D

zlocal
/ \
 |
 |
 ------>xlocal
*/
	
	
	for (unsigned int i = 0;i<_nbDents;i++)
	{
		int k=(_nbDents-1)-2*i;
		//Correspond au @ local de la dent courante
		Points3D centreDenture=refDenture-k*demiPas*x;

		// correspond au point A de la dent courante
		Points3D pt=centreDenture-(quartPas+distX_PiedTravail)*x-distZ_PiedTravail*z;
		ptsProfilGenerateur.InsertionEnQueue(pt);
		
		// correspond au point B de la dent courante
		pt=centreDenture-(quartPas-distX_TeteTravail)*x+distZ_TeteTravail*z;
		ptsProfilGenerateur.InsertionEnQueue(pt);
		
		// correspond au point C de la dent courante
		pt=centreDenture+(quartPas-distX_TeteTravail)*x+distZ_TeteTravail*z;
		ptsProfilGenerateur.InsertionEnQueue(pt);

		// correspond au point D de la dent courante
		pt=centreDenture+(quartPas+distX_PiedTravail)*x-distZ_PiedTravail*z;
		ptsProfilGenerateur.InsertionEnQueue(pt);

	}

	//-------------------------------------
	// Création de la fin de la face des dentures
	//-------------------------------------

	//correspond au point 15 du schéma
	Points3D ptFinPiedDenture=refDenture+(distX_intersec_AxeTravail_FlanDentureExtreme-distX_PiedTravail)*x-distZ_PiedTravail*z;
	ptsProfilGenerateur.InsertionEnQueue(ptFinPiedDenture);

	//correspond au point 16 du schéma
	Points3D ptFinTeteDenture=refDenture+(distX_intersec_AxeTravail_FlanDentureExtreme+distX_TeteTravail)*x+distZ_TeteTravail*z;
	ptsProfilGenerateur.InsertionEnQueue(ptFinTeteDenture);

	//correspond au point 17 du schéma
	Points3D fin=refDenture+_demiLongueurBlocDentures*x+distZ_TeteTravail*z;
	ptsProfilGenerateur.InsertionEnQueue(fin);
	
	//-------------------------------------
	//Fermeture du profil
	//-------------------------------------

	//Correspond au point 18
	Points3D ptBaseBlocDroit=refDenture+_demiLongueurBlocDentures*x-(_hauteurBaseTete-distZ_TeteTravail)*z;
	ptsProfilGenerateur.InsertionEnQueue(ptBaseBlocDroit);
	
	//Correspond au point 19
	Points3D ptBaseBlocGauche=refDenture-_demiLongueurBlocDentures*x-(_hauteurBaseTete-distZ_TeteTravail)*z;
	ptsProfilGenerateur.InsertionEnQueue(ptBaseBlocGauche);

	//Extrusion du profil
	Extrusions extrusion(ptsProfilGenerateur,-_largeurCrem*y,NULL,_attributFace);

	//Récupération des faces de l'extrusion pour notre crémaillère.
	AjouterFaces ( extrusion.TableauFaces());

	//Nombre de facedu blocDenture pour récupérer les faces
	//surlesquelles seront collées les blocInclinés
	unsigned int nbFaces=NombreFaces();
	FacesP faceXMoins =TableauFaces()[nbFaces-3];
	faceXMoins.ModifAttribut(&AttributsFaces(PMateriauJaune));
	FacesP faceXPlus =TableauFaces()[nbFaces-5];
	faceXPlus.ModifAttribut(&AttributsFaces(PMateriauNoir));



	//---------------------------------------------------------------

	//			BLOCS INCLINES

	//---------------------------------------------------------------



	//Projection du point origine sur la face z- du repère local
	//Points3D projeteOrigineZMoins=origine-_demiLongueurBlocDentures*z;
	//Création du point de référence décalé de DELTA pour pouvoir réaliser le collage
	//Points3D ptRef=projeteOrigineZMoins+DELTA*x;

	//Création des tableaux de Sommets
	//Tableau de sommets du plan de jointure en X- du repère local
	Tableaux<SommetsP> tabProfilBlocInclineXMoinsJointif(4,1);

	//Tableaux de sommets du plan extreme du bloc incliné en X- du repère local
	Tableaux<SommetsP> tabProfilBlocInclineXMoinsExtreme(4,1);

	//Tableau de sommets du plan de jointure en X+ du repère local
	Tableaux<SommetsP> tabProfilBlocInclineXPlusJointif(4,1);

	//Tableaux de sommets du plan extreme du bloc incliné en X+ du repère local
	Tableaux<SommetsP> tabProfilBlocInclineXPlusExtreme(4,1);

	//Calcul du point arrière bas du bloc incliné en X- du repère local
	Points3D coinArriereBas=origine-_demiLongueurBlocDentures*x+(_largeurCrem/2-DELTA)*y +DELTA*z;

	//Alimentation des tableaux de sommets par projection du
	//coinArriereBas sur les différents plans des bloc incliné
	tabProfilBlocInclineXMoinsJointif[0]=SommetsP(coinArriereBas);
	tabProfilBlocInclineXMoinsExtreme[0]=tabProfilBlocInclineXMoinsJointif[0].Point3D()-_largeurBlocIncline*x;
	tabProfilBlocInclineXPlusJointif[0]=tabProfilBlocInclineXMoinsJointif[0].Point3D()+2*_demiLongueurBlocDentures*x;
	tabProfilBlocInclineXPlusExtreme[0]=tabProfilBlocInclineXPlusJointif[0].Point3D()+_largeurBlocIncline*x;

	//Calcul du point avant bas du bloc incliné en X- du repère local
	Points3D coinAvantBas=coinArriereBas-(_largeurCrem-2*DELTA)*y;

	//Alimentation des tableaux de sommets par projection du
	//coinAvantBas sur les différents plans des bloc incliné
	tabProfilBlocInclineXMoinsJointif[1]=SommetsP(coinAvantBas);
	tabProfilBlocInclineXMoinsExtreme[1]=tabProfilBlocInclineXMoinsJointif[1].Point3D()-_largeurBlocIncline*x;
	tabProfilBlocInclineXPlusJointif[1]=tabProfilBlocInclineXMoinsJointif[1].Point3D()+2*_demiLongueurBlocDentures*x;
	tabProfilBlocInclineXPlusExtreme[1]=tabProfilBlocInclineXPlusJointif[1].Point3D()+_largeurBlocIncline*x;

	//Calcul du point haut du plan avant du bloc incliné en X- du repère local
	Points3D coinHautPlatAvant=coinAvantBas+(_hauteurBase-DELTA)*z;

	//Alimentation des tableaux de sommets par projection du
	//coinHautPlatAvant sur les différents plans des bloc incliné
	tabProfilBlocInclineXMoinsJointif[2]=SommetsP(coinHautPlatAvant);
	tabProfilBlocInclineXMoinsExtreme[2]=tabProfilBlocInclineXMoinsJointif[2].Point3D()-_largeurBlocIncline*x;
	tabProfilBlocInclineXPlusJointif[2]=tabProfilBlocInclineXMoinsJointif[2].Point3D()+2*_demiLongueurBlocDentures*x;
	tabProfilBlocInclineXPlusExtreme[2]=tabProfilBlocInclineXPlusJointif[2].Point3D()+_largeurBlocIncline*x;

//----------------------------------------------------------------------------------------------------------
//Controle de la nécessité de faire un plat sur le dessus pour ne pas déborder de la face de collage
//----------------------------------------------------------------------------------------------------------
	//Point qui servira de support à la droite de limite supérieure
	//Pour éviter que le bloc incliné déborde du bloc denture
	//Ce qui empechera un bon collage
	Points3D ptLimiteSup=coinArriereBas+(_hauteurBaseTete -2 * DELTA)*z;

	//Droite de limite supérieure
	Droites3D limiteSup(ptLimiteSup,y);

	//Calcul de l'élévation sur une longueur à plat de _largeurCrem-2*DELTA avec un angle de
	// _anglePlat
	double monteZPente =tan( _anglePlat ) * (_largeurCrem-2*DELTA);

	//Point haut de la pente temporaire
	Points3D PointHautPenteTemp=coinHautPlatAvant+(_largeurCrem-2*DELTA)*y+monteZPente*z;
	
	//Création de la pente a partir du point coinHautPlatAvant
	//vers le point temporaire
	Droites3D dpente(coinHautPlatAvant,PointHautPenteTemp);

	//superpose et ptIntersection seront alimentés par la 
	//fonction Intersection
	bool superpose;
	Points3D ptIntersection;

	//Calcul de l'intersection de la pente et de la droite
	//limiteSup
	bool resIntersectHorizontale = limiteSup.Intersection(dpente,&ptIntersection,&superpose);
	
	//S'il n'y a pas d'intersection avec la droite horizontale, c'est qu'il n'y a pas d'inclinaison de la pente
	if(!resIntersectHorizontale){
		//On définit un point d'intersection qui se trouve de l'autre bloc
		ptIntersection=coinHautPlatAvant+(_largeurCrem-2*DELTA)*y;
	}

		//Creation du vecteur partant du point ptLimiteSup
		//vers ptIntersection.
		Vecteurs3D vectO_Intersect(ptLimiteSup,ptIntersection);

		//On regarde si les vecteurs vectO_Intersect et y du repère local
		//vont dans le même sens par le produit scalaire des 2 vecteurs
		double scalaire=vectO_Intersect*y;
		if(scalaire<0){
			//Le point d'intersection se trouve sur la bordure supérieure
			//du bloc denture. Il y a donc un plat à faire.
			//Alimentation des tableaux de sommets par projection du point ptIntersection
			//sur les différents plans
			tabProfilBlocInclineXMoinsJointif[3]=SommetsP(ptIntersection);
			tabProfilBlocInclineXMoinsExtreme[3]=tabProfilBlocInclineXMoinsJointif[3].Point3D()-_largeurBlocIncline*x;
			tabProfilBlocInclineXPlusJointif[3]=tabProfilBlocInclineXMoinsJointif[3].Point3D()+2*_demiLongueurBlocDentures*x;
			tabProfilBlocInclineXPlusExtreme[3]=tabProfilBlocInclineXPlusJointif[3].Point3D()+_largeurBlocIncline*x;

			//Puisqu'il y a un plat, le profil passe donc par le point ptLimiteSup
			//Alimentation des tableaux de sommets par projection du point ptLimiteSup
			//sur les différents plans
			tabProfilBlocInclineXMoinsJointif[4]=SommetsP(ptLimiteSup);
			tabProfilBlocInclineXMoinsExtreme[4]=tabProfilBlocInclineXMoinsJointif[4].Point3D()-_largeurBlocIncline*x;
			tabProfilBlocInclineXPlusJointif[4]=tabProfilBlocInclineXMoinsJointif[4].Point3D()+2*_demiLongueurBlocDentures*x;
			tabProfilBlocInclineXPlusExtreme[4]=tabProfilBlocInclineXPlusJointif[4].Point3D()+_largeurBlocIncline*x;

		}else{
			
			if(scalaire>0){
				//L'intersection avec la droite de limite supérieure 
				//se fait en dehors du bloc denture. Il n'y a pas de plat
				// à faire
		
				//Il faut cependant trouver le point d'intersection avec la verticale
				//Création de la droite verticale
				Droites3D dVert(ptLimiteSup,z);

				//Calcul de l'intersection (ptIntersection) entre la droite dpente et la droite verticale dVert
				dVert.Intersection(dpente,&ptIntersection,&superpose);
			}

			//Si le scalaire == 0 --> la pente est horizontale. Le point d'intersection a déjà été défini plus haut


			//Alimentation des tableaux de sommets par projection du point ptIntersection
			//sur les différents plans
			tabProfilBlocInclineXMoinsJointif[3]=SommetsP(ptIntersection);
			tabProfilBlocInclineXMoinsExtreme[3]=tabProfilBlocInclineXMoinsJointif[3].Point3D()-_largeurBlocIncline*x;
			tabProfilBlocInclineXPlusJointif[3]=tabProfilBlocInclineXMoinsJointif[3].Point3D()+2*_demiLongueurBlocDentures*x;
			tabProfilBlocInclineXPlusExtreme[3]=tabProfilBlocInclineXPlusJointif[3].Point3D()+_largeurBlocIncline*x;

		}

		//------------------------------------
		//Fin du controle de plans supérieur
		//------------------------------------


	//Tableau de sommets pour la réalisation des différents plans
	Tableaux<SommetsP> T4(4,1);
		

	//Nombre de points. Si plan supérieur existe alors = 5. sinon = 4
	int nbPoints=tabProfilBlocInclineXMoinsJointif.Nb_Effectifs();

	//----------------------------------------------------
	//FACES ARRIERE DES BLOCS INCLINES
	//----------------------------------------------------

	//face arrière bloc X- du repère local
	T4[0]=tabProfilBlocInclineXMoinsJointif[0];
	T4[1]=tabProfilBlocInclineXMoinsExtreme[0];
	T4[2]=tabProfilBlocInclineXMoinsExtreme[nbPoints-1];
	T4[3]=tabProfilBlocInclineXMoinsJointif[nbPoints-1];
	FacesP faceArriereXMoins=ConstuireFacesDepuisSommets(T4);
	
	//face arrière bloc X+ du repère local
	T4[0]=tabProfilBlocInclineXPlusExtreme[0];
	T4[1]=tabProfilBlocInclineXPlusJointif[0];
	T4[2]=tabProfilBlocInclineXPlusJointif[nbPoints-1];
	T4[3]=tabProfilBlocInclineXPlusExtreme[nbPoints-1];
	FacesP faceArriereXPlus=ConstuireFacesDepuisSommets(T4);

	//----------------------------------------------------
	//FACES ARRIERE DES BLOCS INCLINES
	//----------------------------------------------------

	//face avant (plat) bloc Z- du repère local
	T4[0]=tabProfilBlocInclineXMoinsExtreme[1];
	T4[1]=tabProfilBlocInclineXMoinsJointif[1];
	T4[2]=tabProfilBlocInclineXMoinsJointif[2];
	T4[3]=tabProfilBlocInclineXMoinsExtreme[2];
	FacesP faceAvantXMoins=ConstuireFacesDepuisSommets(T4);
	
	//face avant (plat) bloc Z+ du repère local
	T4[0]=tabProfilBlocInclineXPlusJointif[1];
	T4[1]=tabProfilBlocInclineXPlusExtreme[1];
	T4[2]=tabProfilBlocInclineXPlusExtreme[2];
	T4[3]=tabProfilBlocInclineXPlusJointif[2];
	FacesP faceAvantXPlus=ConstuireFacesDepuisSommets(T4);


	//----------------------------------------------------
	//FACES INCLINES DES BLOCS INCLINES
	//----------------------------------------------------
	//face inclinée bloc Z- du repère local
	T4[0]=tabProfilBlocInclineXMoinsExtreme[2];
	T4[1]=tabProfilBlocInclineXMoinsJointif[2];
	T4[2]=tabProfilBlocInclineXMoinsJointif[3];
	T4[3]=tabProfilBlocInclineXMoinsExtreme[3];
	_facePlanInclineXMoins=ConstuireFacesDepuisSommets(T4);
	//Face qui sera percée par la suite

	//face inclinée bloc Z+ du repère local
	T4[0]=tabProfilBlocInclineXPlusJointif[2];
	T4[1]=tabProfilBlocInclineXPlusExtreme[2];
	T4[2]=tabProfilBlocInclineXPlusExtreme[3];
	T4[3]=tabProfilBlocInclineXPlusJointif[3];
	FacesP facePlanInclineXPlus=ConstuireFacesDepuisSommets(T4);
	//Face qui sera percée par la suite

	//----------------------------------------------------
	//FACES INFERIEURES DES BLOCS INCLINES
	//----------------------------------------------------
	//face inférieure bloc Z- du repère local
	T4[0]=tabProfilBlocInclineXMoinsExtreme[0];
	T4[1]=tabProfilBlocInclineXMoinsJointif[0];
	T4[2]=tabProfilBlocInclineXMoinsJointif[1];
	T4[3]=tabProfilBlocInclineXMoinsExtreme[1];
	FacesP faceInferieureXMoins=ConstuireFacesDepuisSommets(T4);

	//face inférieure bloc Z+ du repère local
	T4[0]=tabProfilBlocInclineXPlusJointif[1];
	T4[1]=tabProfilBlocInclineXPlusJointif[0];
	T4[2]=tabProfilBlocInclineXPlusExtreme[0];
	T4[3]=tabProfilBlocInclineXPlusExtreme[1];;
	FacesP faceInferieureXPlus=ConstuireFacesDepuisSommets(T4);


	//Tableaux de sommets des faces extremes et de jointures
	Tableaux<SommetsP> TCoteExtremeXMoins(nbPoints,1);
	Tableaux<SommetsP> TCoteExtremeXPlus(nbPoints,1);
	Tableaux<SommetsP> TCoteJointifXMoins(nbPoints,1);
	Tableaux<SommetsP> TCoteJointifXPlus(nbPoints,1);

	//Alimentation des tableaux de sommets des faces extremes
	//et de jointure par les points contenu dans les tableaux
	//de points correspondants.
	for(unsigned int i=0;i<nbPoints;i++){
		TCoteExtremeXMoins[i]=tabProfilBlocInclineXMoinsExtreme[i];
		TCoteExtremeXPlus[i]=tabProfilBlocInclineXPlusExtreme[i];
		TCoteJointifXMoins[i]=tabProfilBlocInclineXMoinsJointif[i];
		TCoteJointifXPlus[i]=tabProfilBlocInclineXPlusJointif[i];
	}

	//Inversion de l'ordre des sommets des tableaux de sommets
	//des plans de jointure en Z- et extreme en Z+ (repère local)
	//Puisque l'ordre des points n'est pas trigo dans ces 2 tableaux
	TCoteJointifXMoins.Inversion();
	TCoteExtremeXPlus.Inversion();

	//Construction des Faces des plans de jointures et extreme
	FacesP faceACollerXMoins=ConstuireFacesDepuisSommets(TCoteJointifXMoins);
	FacesP faceACollerXPlus=ConstuireFacesDepuisSommets(TCoteJointifXPlus);
	FacesP faceExtremeXPlus=ConstuireFacesDepuisSommets(TCoteExtremeXPlus);
	FacesP faceExtremeXMoins=ConstuireFacesDepuisSommets(TCoteExtremeXMoins);

	//Creation des solides des blocs inclinés
	SolidesP blocXMoins,blocXPlus;

	//Ajout des faces a coller aux blocs inclinés [indice 0]
	blocXMoins.AjouterFace(faceACollerXMoins);
	blocXPlus.AjouterFace(faceACollerXPlus);

	//Ajout des faces avant aux blocs inclinés [indice 1]
	blocXMoins.AjouterFace(faceAvantXMoins);
	blocXPlus.AjouterFace(faceAvantXPlus);

	//Ajout des Faces inférieures aux blocs inclinés [indice 2]
	blocXMoins.AjouterFace(faceInferieureXMoins);
	blocXPlus.AjouterFace(faceInferieureXPlus);
	
	//Ajout des faces arrières aux blocs inclinés [indice 3]
	blocXMoins.AjouterFace(faceArriereXMoins);
	blocXPlus.AjouterFace(faceArriereXPlus);
	
	//Ajout des faces supérieures si elles existent [indice 4??]
	//Cf "Controle de la nécessité de faire un plat sur le dessus"
	if(nbPoints==5){
		//Création de la face du plan supérieur du bloc X-
		T4[0]=tabProfilBlocInclineXMoinsExtreme[3];
		T4[1]=tabProfilBlocInclineXMoinsJointif[3];
		T4[2]=tabProfilBlocInclineXMoinsJointif[4];
		T4[3]=tabProfilBlocInclineXMoinsExtreme[4];
		FacesP facePlanSupXMoins=ConstuireFacesDepuisSommets(T4);

		//Ajout de la face au blocXMoins
		blocXMoins.AjouterFace(facePlanSupXMoins);

		//Création de la face du plan supérieur du bloc X+
		T4[0]=tabProfilBlocInclineXPlusExtreme[3];
		T4[1]=tabProfilBlocInclineXPlusExtreme[4];
		T4[2]=tabProfilBlocInclineXPlusJointif[4];
		T4[3]=tabProfilBlocInclineXPlusJointif[3];
		FacesP facePlanSupXPlus=ConstuireFacesDepuisSommets(T4);

		//Ajout de la face au blocXPlus
		blocXPlus.AjouterFace(facePlanSupXPlus);
	}

	//Ajout des faces extremes [indice nbFaces-2]
	blocXMoins.AjouterFace(faceExtremeXMoins);
	blocXPlus.AjouterFace(faceExtremeXPlus);
		
	//Ajout des faces incline [indice nbFaces-1]
	blocXMoins.AjouterFace(_facePlanInclineXMoins);
	blocXPlus.AjouterFace(facePlanInclineXPlus);

	//Calcul Point de percage su le bloc XMoins
	Vecteurs3D vecteurPente(coinHautPlatAvant,ptIntersection);

	//Le point de percage se trouve au milieu de la pente à _distPercExtrem de l'extrémité
	Points3D ptPercageXMoins=coinHautPlatAvant+0.5*vecteurPente-(_largeurBlocIncline-_distPercExtrem)*x;

	//Mémorisation du vecteur origine vers le point de percage
	_OriginePtPercageXMoins=Vecteurs3D(origine,ptPercageXMoins);

	//Création du point de percage sur le bloc X+ par décalage
	Points3D ptPercageXPlus=ptPercageXMoins+(_lgTotal-2*_distPercExtrem)*x;

	//Mémorisation du vecteur origine vers le point de percage
	_OriginePtPercageXPlus=Vecteurs3D(origine,ptPercageXPlus);

	// Outils de percage
	OutilPercageCylindrique outil1 = OutilPercageCylindrique(false, true, 32, _rayonPercage, _profPercage);
	OutilPercageCylindrique outil2 = OutilPercageCylindrique(false, true, 32, _rayonPercage, _profPercage);

	// Percage
	Perceuse::percer(ptPercageXMoins, blocXMoins, _facePlanInclineXMoins,  &outil1);
	Perceuse::percer(ptPercageXPlus, blocXPlus, facePlanInclineXPlus, &outil2);

	
	//Collage des 2 blocs inclinés sur le bloc denture
	Coller(blocXMoins,faceXMoins,faceACollerXMoins);
	Coller(blocXPlus,faceXPlus,faceACollerXPlus);

}


//_____________________________________________________________________________
//
//	Méthode de contrôle des arguments passés pour la construction d'une crémaillère
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- La combinaison du nombre de dents et du module font que les dents débordent du bloc denture.
- La longueur totale est inférieure à la longueur du bloc denture.
- La hauteur (paramètre distanceBase_HautDenture) est inférieure à la hauteur d'un dent (définie par le module).
- la hauteur des plats avants (paramètre hauteurBasePlanIncline) est supérieure à la hauteur totale de la crémaillère.
- la distance de percage ( paramètre distancePercageDepuisExtremite) est inférieure au diamètre de percage.
- l'angle d'inclinaison n'est pas compris en 0 et Pi/2


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!.
*/

void CremaillereStandard::ControleValiditeArgConstruct(){
	if(_demiLongueurBlocDentures<(2*_nbDents+(2-_nbDents%2)*PI*_module)){
		throw exception("Le nombre de dents ne peut pas entrer dans la largeur du bloc denture définie.");
	}

	if(_hauteurBaseTete<2.4*_module){
			throw exception("La hauteur des dents est supérieure à la hauteur de la crémaillère.");
	}

	if(_hauteurBase>_hauteurBaseTete){
		throw exception("La hauteur des méplats avant pour les blocs inclinés est supérieure à la hauteur de la crémaillère.");
	}
	
	if(_distPercExtrem<_rayonPercage){
		throw exception("Le positionnement des trous de percage est incorrect. Le diamètre du trou déborde de la face extérieure. Revoir diamètre de percage et/ou distancePercageDepuisExtremite.");
	}

	if(_lgTotal<_demiLongueurBlocDentures*2){
		throw exception("La longueur totale de la pièce est inférieure à la longueur du bloc denture.");
	}

	if(_anglePlat<0 || _anglePlat > PI/2){
		throw exception("L'angle du plan incliné déborde des limites prévues. Si vous voulez les angles dans l'autre sens alors: Réduisez l'angle et faite pivoter la crémaillère de 180° sur son axe Z.");
	}
}