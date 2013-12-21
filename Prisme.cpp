/*
Cr�ation :				Christophe ELSENSOHN 
Date de cr�ation :		05/04/2012
Version :				0
Modifi� par:			null
Date de modification:	null
*/
#include "StdAfx.h"
#include "Prisme.h"

//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################

//*****************************************************************************
//						CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Destructeur de la classe Prisme
Prisme::~Prisme()
{
	//Rien � d�sallouer
}

//_____________________________________________________________________________
//
//	Constructeur de la classe Prisme
/*
#PARAMETRES
	- repere	(const Repere3D&)	:	La longueur suivra l'axe Z de ce rep�re.
										La largeur  suivra l'axe X de ce rep�re.
										La hauteur  suivra l'axe Y de ce rep�re.
										origine se trouvant sur la face dont le vecteur normal est oppos� � l'axe Z du rep�re fourni.
									    Ce point se trouve � l'intersection des diagonales du rectangle largeur*hauteur.

	- longueur	(double)			: dimension du Prisme suivant l'axe Z du rep�re.

	- largeur	(double)			: dimension du Prisme suivant l'axe X du rep�re.

	- hauteur	(double)			: dimension du Prisme suivant l'axe Y du rep�re.

	_ PtAF		(AttributFacesP*)	: couleur des faces.
*/
Prisme::Prisme(const Repere3D& repere,double longueur, double largeur, double hauteur,AttributsFacesP *PtAF):
		Piece(repere,PtAF),_longueur(longueur),_largeur(largeur),_hauteur(hauteur)
{
	buildAll();
}

//_____________________________________________________________________________
//
//	Constructeur par recopie de la classe Prisme

Prisme::Prisme(const Prisme& prisme):
			Piece(prisme),_hauteur(prisme._hauteur),_largeur(prisme._largeur),_longueur(prisme._longueur)
{
	buildAll();
}

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter de la Droites3D du prisme

Droites3D Prisme::getAxe() const
{
	return Droites3D(_repere.Origine(),_repere.Z());
}

//_____________________________________________________________________________
//
//	Getter du Vecteurs3D de la direction du Prisme

const Vecteurs3D Prisme::getDirection()const
{
	return _repere.Z();
}

//_____________________________________________________________________________
//
//	Getter du vecteur se trouvant sur la face oppos�e � la face de base
const Repere3D Prisme::getRepere3DOppose() const
{
	return Repere3D(_repere.Origine() + getLongueur() * _repere.Z(), _repere.X(), _repere.Y(), _repere.Z());
}

//_____________________________________________________________________________
//
//	Getter de la longueur du Prisme

double Prisme::getLongueur()const
{
	return _longueur;
}

//_____________________________________________________________________________
//
//	Getter de la largeur du Prisme

double Prisme::getLargeur() const
{
	return _largeur;
}

//_____________________________________________________________________________
//
//	Getter de la hauteur du Prisme

double Prisme::getHauteur()const
{
	return _hauteur;
}

//_____________________________________________________________________________
//
//	M�thode renvoyant la FacesP de la base du Prisme.
//	La base du prisme est la face contenant le Points3D position
//	dont le vecteur normal est le vecteur oppos� au  vecteur Z du repere fourni lors de la construction

const FacesP& Prisme::faceBase()const
{
	return *_base;
}

//_____________________________________________________________________________
//
//	M�thode renvoyant la face oppos� � la base g�n�ratrice du prisme

const FacesP& Prisme::faceSommet()const
{
	return *_sommet;
}

//_____________________________________________________________________________
//
//	M�thode renvoyant un tableau de pointeurs vers les faces des flans du prisme.

Tableaux<const FacesP*> Prisme::flans()const
{
	return _flans;
}


//#############################################################################
//								DOMAINE PRIVE
//#############################################################################

//*****************************************************************************
//									METHODES
//*****************************************************************************

//_____________________________________________________________________________
//
//	M�thode de construction du Prisme
//Le Prisme ainsi construit aura :
//	- la Longueur suivant Z du rep�re
//	- la Largeur  suivant X du rep�re
//	- la Hauteur  suivant Y du rep�re

void  Prisme::buildAll()
{
	/*############################################################################
	UNE TECHNIQUE POUR GENERER LES 2 AUTRES VECTEURS D'UN REPERE DIRECT ORTHONORME
	A PARTIR D'UN VECTEUR REPRESENTANT L'AXE Z LOCAL NOMMEE _direction
	#############################################################################*/
	/*_axeY_Prisme = _direction.VecteurPerpendiculaireNorme();
	_axeX_Prisme = _axeY_Prisme & _direction;
	_axeX_Prisme = _axeX_Prisme.VecteurNorme();*/

	//M�morisation des Vecteurs � partir du rep�re
	Vecteurs3D axeX_Prisme =_repere.X();
	Vecteurs3D axeY_Prisme =_repere.Y();
	Vecteurs3D axeZ_Prisme =_repere.Z();
	
	//Liste des Points3D qui serviront � g�n�rer le profil de la base.
	Listes<Points3D> ptsPlanBase;

	//Calcul des demi_XXX pour centrer le Prisme sur sa largeur et hauteur
	double demiLargeur=_largeur/2;
	double demiHauteur=_hauteur/2;

	//Ajout des points g�n�rateurs dans la Listes<Points3D>
	ptsPlanBase.InsertionEnTete(_repere.Origine()+demiLargeur*axeX_Prisme+demiHauteur*axeY_Prisme);
	ptsPlanBase.InsertionEnTete(_repere.Origine()-demiLargeur*axeX_Prisme+demiHauteur*axeY_Prisme);
	ptsPlanBase.InsertionEnTete(_repere.Origine()-demiLargeur*axeX_Prisme-demiHauteur*axeY_Prisme);
	ptsPlanBase.InsertionEnTete(_repere.Origine()+demiLargeur*axeX_Prisme-demiHauteur*axeY_Prisme);

	//Cr�ation de l'extrusion � partir de la liste des points g�n�rateur dans le sens du vecteur Z
	//sur la longeur "_longueur"
	Extrusions extrusion(ptsPlanBase,_longueur*axeZ_Prisme,NULL,_attributFace);

	//Ajout des Faces3D de l'extrusion au faces de notre Prisme
	AjouterFaces ( extrusion.TableauFaces());

	//M�morisation d'un pointeur vers la Faces3D correspondant � la Face3D g�n�ratrice
	_base=&(TableauFaces()[4]);

	//M�morisation d'un pointeur vers la Faces3D oppos�e � la face "_base"
	_sommet=&(TableauFaces()[5]);

	//Alimentation du Tableaux de pointeurs de Faces3D avec les faces correspondant aux flans du Prisme
	for (int i = 0; i<4;i++){
		_flans[i]=&(TableauFaces()[i]);
	}

}

