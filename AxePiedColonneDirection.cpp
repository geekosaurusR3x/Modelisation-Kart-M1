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
		- repere				(const Repere3D&)	: rep�re de l'axe.
														L'axe de l'axe de r�volution
														origine se trouvant sur l'axe de l'axe 
														Il se situe au centre de la face cylindrique.
		
		- Diametre				(double)			: diam�tre
		
		- longueurDiametre		(double)			: longueur du cylindre 
		
		- coteCarre				(double)			: cote du carr�.
		
		- longueurCarre			(double)			: Longueur d'extrusion du carr�
		
		- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe �paul� goupillable.
														Repr�sente la couleur de l'axe �paul� goupillable.

	#RECOMMANDATIONS
		Faire attention � ce que la diagonale du carr� soit inf�rieure au diam�tre.
		Dans le cas contraire, une Exception sera lev�e.
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
	//Rien � d�sallouer
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
//	Getter de la r�f�rence sur la FacesP extreme cylindrique

const FacesP& AxePiedColonneDirection::faceInferieur()const{
	return *_faceInf;
}

//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP de jonction entre 
//	le cylindre et le carr�

const FacesP& AxePiedColonneDirection::faceJonction()const{
	return *_faceJonction;
}

//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP extreme du carr�

const FacesP& AxePiedColonneDirection::faceCarre()const{
	return *_faceCarre;
}

//_____________________________________________________________________________
//
//	Getter de la Droites3D de l'AxePiedColonneDirection.
//	Droites3D compos� de l'axe Z du rep�re et du Points3D position

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
	M�thode de construction de AxePiedColonneDirection
	Cette m�thode cr�e un cylindre dont elle r�cup�re les faces
	pour alimenter la collection de FacesP de notre AxePiedColonneDirection
	Puis elle cr�e un Prisme qu'elle colle � l'extr�mit� du cylindre
	*/
void AxePiedColonneDirection::buildAll(){
	//Cr�ation du point de jonction qui se trouve sur la face oppos�
	//� la face de base (contenant l'origine)
	Points3D centreJonction=_repere.Origine()+_lgDiametre*_repere.Z();

	//Construction d'un cylindre de longueur _LgDiametre et de rayon _rayon
	Cylindres cyl(_repere.Origine(),centreJonction,_rayon,NULL,_attributFace);

	//Ajout des faces du cylindre � la collection de faces de notre objet
	AjouterFaces(cyl.TableauFaces());

	//Cr�ation d'un Prisme
	Prisme p(Repere3D(centreJonction,_repere.X(),_repere.Y(),_repere.Z()),_lgCarre,_demiCoteCarre*2,_demiCoteCarre*2,_attributFace);
	
	
	//M�morisation des pointeurs vers les faces inf�rieur(de base) et sup�rieur (jonction)
	_faceInf=&(TableauFaces()[0]);
	_faceJonction=&(TableauFaces()[1]);
	
	//R�f�rence sur la face � coller du prisme
	FacesP faceACollerPrisme=p.faceBase();

	//Collage du prisme sur le cylindre
	bool res=Coller(p,*_faceJonction,faceACollerPrisme);
	
	unsigned int nbFace=NombreFaces();
	//M�morisation du pointeur vers la faces sup�rieur de l'axePiedColonneDirection
	_faceCarre=&(TableauFaces()[nbFace-1]);

}

//_____________________________________________________________________________
//
//	M�thode de controle des arguments pass�s pour la construction
	
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- la diagonale du carr� est sup�rieure au diam�tre.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
	
void AxePiedColonneDirection::ControleValiditeArgConstruct(){

	Vecteurs3D v(_demiCoteCarre,_demiCoteCarre,0);
	double norme=v.Norme();
	if(norme>=_rayon){
		throw exception("les cot�s du carr� sont plus grand que le diam�tre. Rien ne pourra �tre mont� sur cet axe.");
	}
}