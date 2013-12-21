#include "StdAfx.h"
#include "AxePiedColonneDirection.h"
#include "Prisme.h"

//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################

//*****************************************************************************
//						CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Constructeur d'instance de AxePiedColonneDirection 

/*
#PARAMETRES
		- repere				(const Repere3D&)	: repère de l'axe.
														L'axe de l'axe de révolution
														origine se trouvant sur l'axe de l'axe 
														Il se situe au centre de la face cylindrique.
		
		- Diametre				(double)			: diamètre
		
		- longueurDiametre		(double)			: longueur du cylindre 
		
		- coteCarre				(double)			: cote du carré.
		
		- longueurCarre			(double)			: Longueur d'extrusion du carré
		
		- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe épaulé goupillable.
														Représente la couleur de l'axe épaulé goupillable.

	#RECOMMANDATIONS
		Faire attention à ce que la diagonale du carré soit inférieure au diamètre.
		Dans le cas contraire, une Exception sera levée.
*/
AxePiedColonneDirection::AxePiedColonneDirection(const Repere3D& repere, double diametre,
												double longueurDiametre,double coteCarre,
												double longueurCarre, AttributsFacesP *PtAF):
												Piece(repere,PtAF),_rayon(diametre/2),
												_lgDiametre(longueurDiametre),
												_demiCoteCarre(coteCarre/2),
												_lgCarre(longueurCarre)
{
	ControleValiditeArgConstruct();
	buildAll();
}

//_____________________________________________________________________________
//
//	Constructeur par recopie de AxePiedColonneDirection

AxePiedColonneDirection::AxePiedColonneDirection(const AxePiedColonneDirection& axePiedColonneDirection):Piece(axePiedColonneDirection),
	_rayon(axePiedColonneDirection._rayon),_lgDiametre(axePiedColonneDirection._lgDiametre),_demiCoteCarre(axePiedColonneDirection._demiCoteCarre),_lgCarre(axePiedColonneDirection._lgCarre)
{

	buildAll();
}

//_____________________________________________________________________________
//
//	Destructeur de AxePiedColonneDirection

AxePiedColonneDirection::~AxePiedColonneDirection()
{
	//Rien à désallouer
}


//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter du repere de la face carree
Repere3D AxePiedColonneDirection::getRepere3DOppose(){
	Repere3D rep(_repere);
	rep.ModifOrigine(_repere.Origine() + (_lgDiametre + _lgCarre) * _repere.Z());
	return rep;
}

//_____________________________________________________________________________
//
//	Getter du repere de la face carree

Repere3D AxePiedColonneDirection::getRepere3DJointure(){
	Repere3D rep(_repere);
	rep.ModifOrigine(_repere.Origine() + (_lgDiametre) * _repere.Z());
	return rep;
}

//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP extreme cylindrique

const FacesP& AxePiedColonneDirection::faceInferieur()const{
	return *_faceInf;
}

//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP de jonction entre 
//	le cylindre et le carré

const FacesP& AxePiedColonneDirection::faceJonction()const{
	return *_faceJonction;
}

//_____________________________________________________________________________
//
//	Getter de la référence sur la FacesP extreme du carré

const FacesP& AxePiedColonneDirection::faceCarre()const{
	return *_faceCarre;
}

//_____________________________________________________________________________
//
//	Getter de la Droites3D de l'AxePiedColonneDirection.
//	Droites3D composé de l'axe Z du repère et du Points3D position

Droites3D AxePiedColonneDirection::getAxe() const
{
	return Droites3D(_repere.Origine(),_repere.Z());
}


//#############################################################################
//								DOMAINE PRIVE
//#############################################################################

//*****************************************************************************
//									METHODES
//*****************************************************************************

/*
	Méthode de construction de AxePiedColonneDirection
	Cette méthode crée un cylindre dont elle récupère les faces
	pour alimenter la collection de FacesP de notre AxePiedColonneDirection
	Puis elle crée un Prisme qu'elle colle à l'extrémité du cylindre
	*/
void AxePiedColonneDirection::buildAll(){
	//Création du point de jonction qui se trouve sur la face opposé
	//à la face de base (contenant l'origine)
	Points3D centreJonction=_repere.Origine()+_lgDiametre*_repere.Z();

	//Construction d'un cylindre de longueur _LgDiametre et de rayon _rayon
	Cylindres cyl(_repere.Origine(),centreJonction,_rayon,NULL,_attributFace);

	//Ajout des faces du cylindre à la collection de faces de notre objet
	AjouterFaces(cyl.TableauFaces());

	//Création d'un Prisme
	Prisme p(Repere3D(centreJonction,_repere.X(),_repere.Y(),_repere.Z()),_lgCarre,_demiCoteCarre*2,_demiCoteCarre*2,_attributFace);
	
	
	//Mémorisation des pointeurs vers les faces inférieur(de base) et supérieur (jonction)
	_faceInf=&(TableauFaces()[0]);
	_faceJonction=&(TableauFaces()[1]);
	
	//Référence sur la face à coller du prisme
	FacesP faceACollerPrisme=p.faceBase();

	//Collage du prisme sur le cylindre
	bool res=Coller(p,*_faceJonction,faceACollerPrisme);
	
	unsigned int nbFace=NombreFaces();
	//Mémorisation du pointeur vers la faces supérieur de l'axePiedColonneDirection
	_faceCarre=&(TableauFaces()[nbFace-1]);

}

//_____________________________________________________________________________
//
//	Méthode de controle des arguments passés pour la construction
	
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- la diagonale du carré est supérieure au diamètre.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
	
void AxePiedColonneDirection::ControleValiditeArgConstruct(){

	Vecteurs3D v(_demiCoteCarre,_demiCoteCarre,0);
	double norme=v.Norme();
	if(norme>=_rayon){
		throw exception("les cotés du carré sont plus grand que le diamètre. Rien ne pourra être monté sur cet axe.");
	}
}