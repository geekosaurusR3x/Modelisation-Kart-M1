#include "StdAfx.h"
#include "Bielle.h"
#include "TIColorerSolide.h"
#include "Perceuse.h"
#include "OutilPercageCylindrique.h"

#define NbSegArc 16
#define NbSegCercle 32

Bielle::Bielle( const Repere3D& repere, 
				const double diametreAlesage1,
				const double entreAxe, 
				const double diametreAlesage2, 
				const double epaisseur,
				const double largeur,
				AttributsFacesP *attributFace)
		:Piece(repere, attributFace)
{
	// Copie des param�tres
	_diametreAlesage1 = diametreAlesage1;
	_entreAxe = entreAxe;
	_diametreAlesage2 = diametreAlesage2; 
	_epaisseur = epaisseur;
	_largeur = largeur;
	verifierArguments();
	buildAll();
}

Bielle::~Bielle()
{
}

void Bielle::verifierArguments(){

	// Dimetres des alesages <=> largeur de la bielle
	if( _diametreAlesage1 >= _largeur || _diametreAlesage2 >= _largeur )
		throw exception("Le diametres des alesages doit �tre strictement inf�rieur � la largeur de la bielle!");
}

void Bielle::buildAll(){

	//Demi largeur de la bielle
	double demiLargeur = _largeur/2;
	
	//Definition du nombre de points port�s par les arcs des contours exterieurs
	int nbPointsArc = NbSegArc + 1;

	//Nombre de points total sur un profil exterieur
	int nbPointsContoursExt = nbPointsArc;

	//Point du second al�sage
	Points3D pointAlesage2( _repere.Origine() + _entreAxe *  _repere.X());
	
	//Tableau des points du contour ext�rieur de la face sup�rieur
	Tableaux<SommetsP> faceSup( 2 * nbPointsArc, 1);
	
	//Tableau des points du contour ext�rieur de la face inf�rieur
	Tableaux<SommetsP> faceInf( 2 * nbPointsArc, 1);

	//Vecteur de l'�paisseur de la bielle plan inf�rieur vers plan sup�rieur
	Vecteurs3D v = _epaisseur * _repere.Z();

	//Valeur incr�mentale d'un angle pour cr�er les diff�rents points
	double Alpha = 0;

	//Calcul du pas dans un al�sage
	double Pas=2 * PI / NbSegCercle;

	//Calcul du pas dans un arc ext�rieur
	double pasArc=PI / (NbSegArc);

	//Cr�ation des points des contours ext�rieurs de la bielle autour du Point de l'alesage 1
	Alpha = 0;
	for(int i=0 ; i<nbPointsArc ;i++){

		//Calcul du ieme point du contour ext�rieur autour de l'axe de l'al�sage 1 sur la face inf�rieure
		Points3D p = _repere.Origine() + demiLargeur * cos(Alpha) * _repere.Y()-demiLargeur * sin(Alpha) * _repere.X();
		faceInf[i] = SommetsP(_repere.Origine() + demiLargeur * cos(Alpha) * _repere.Y()-demiLargeur * sin(Alpha) * _repere.X());

		//Cr�ation du ieme point du contour ext�rieur autour de l'axe de l'al�sage 1 sur la face sup�rieure par projection
		faceSup[i] = SommetsP(faceInf[i].Point3D() + v);

		Alpha += pasArc;
	}

	Alpha = 0;
	//Cr�ation des points des contours ext�rieurs de la bielle autour du Point de l'alesage 2
	for(int i=nbPointsArc ; i<(2*nbPointsArc) ;i++){

		//Calcul du ieme point du contour ext�rieur autour de l'axe de l'al�sage 2 sur la face inf�rieure
		faceInf[i] = SommetsP(pointAlesage2-demiLargeur*cos(Alpha)* _repere.Y()+demiLargeur*sin(Alpha)* _repere.X());
		Points3D p = pointAlesage2-demiLargeur*cos(Alpha)* _repere.Y()+demiLargeur*sin(Alpha)* _repere.X();

		//Cr�ation du ieme point du contour ext�rieur autour de l'axe de l'al�sage 2 sur la face sup�rieure par projection
		faceSup[i]=SommetsP(faceInf[i].Point3D()+v);
		
		Alpha+=pasArc;
	}

	//Tableau des aretes du contour ext�rieur du plan sup�rieur
	Tableaux<AretesP> aretesContourExtSup(2*NbSegArc,1);

	//Tableau des aretes du contour ext�rieur du plan inf�rieur
	Tableaux<AretesP> aretesContourExtInf(2*NbSegArc,1);

	//Tableau des aretes de liaison de la tranche (plan inf�rieur --> plan sup�rieur) du contour ext�rieur
	Tableaux<AretesP> aretesLiaisonInfSupExt(2*NbSegArc,1);

	//aretes du contour
	for(int i = 0; i<(2*NbSegArc)+2;i++){
		aretesContourExtSup[i]=AretesP(faceSup[i],faceSup[(i+1)%(2*nbPointsArc)]);
		aretesContourExtInf[i]=AretesP(faceInf[i],faceInf[(i+1)%(2*nbPointsArc)]);
		aretesLiaisonInfSupExt[i]=AretesP(faceSup[i],faceInf[i]);
	}

	//Initialisation du tableau des contours
	Tableaux<ContoursP> TabCont( (2*NbSegArc)+2+2+(2*(NbSegCercle+2) ),1);

	//initialisation d'un compteur. Si attaque en directe sur Nb_Effectifs --> RunTime Exception
	int compteur=TabCont.Nb_Effectifs();

	//Cr�ation des contours et faces

	//Contours contenant 4 aretes
	Tableaux<AretesP> T4A(4,1);

	//Cr�ation des faces du contour ext�rieur
	for(int i = 0; i<(2*NbSegArc)+2;i++){
		
		T4A[0] = aretesContourExtSup[i];
		T4A[1] = aretesLiaisonInfSupExt[i];
		T4A[2] = aretesContourExtInf[i];
		T4A[3] = aretesLiaisonInfSupExt[(i+1)%(2*nbPointsArc)];
		TabCont[compteur] = ContoursP(T4A);
		AjouterFace( FacesP( TabCont[compteur],_attributFace ) );
		compteur++;
	}

	//Face inf�rieur
	//On la retourne puisque le sens des aretes donne un sens positif vers l'int�rieur de la bielle
	aretesContourExtInf.Inversion();

	//Cr�ation du contour ext�rieur inf�rieur
	ContoursP CE=ContoursP(aretesContourExtInf);
	//Cr�ation de la face de ce contour
	FacesP F(CE,_attributFace);

	AjouterFace(F);

	//Cr�ation du contour ext�rieur inf�rieur
	CE=ContoursP(aretesContourExtSup);
	//Cr�ation de la face de ce contour
	FacesP F1(CE,_attributFace);
	AjouterFace(F1);

	// Cr�ation des outils de percage
	OutilPercageCylindrique outil1 = OutilPercageCylindrique(false, false, 32, _diametreAlesage1/2, _epaisseur);
	OutilPercageCylindrique outil2 = OutilPercageCylindrique(false, false, 32, _diametreAlesage2/2, _epaisseur);

	// Percage des alesages
	Perceuse::percer(_repere.Origine(), *this, F1, F, &outil1);
	Perceuse::percer(pointAlesage2+v, *this, F, F1, &outil2);
}


void Bielle::rotationSurZAlesage1(double teta){
	rotationSurZ(teta);
}

void Bielle::rotationSurZAlesage2(double teta){

	// G�n�ration de la matrice rotation autour de X
	Matrices4D matriceRotation;
	matriceRotation.DevenirRotationQuelconque (getRepere3DAlesage2().Origine(), getRepere3DAlesage2().Z(), teta);

	// Transformation de la piexe
	Transformer(matriceRotation);
	
	// D�placement du repere
	_repere.ModifOrigine(_repere.Origine() * matriceRotation);
	_repere.X(_repere.X() * matriceRotation);
	_repere.Y(_repere.Y() * matriceRotation);

}

Repere3D Bielle::getRepere3DAlesage1() const{
	return _repere;
}

Repere3D Bielle::getRepere3DAlesage2() const{
	Points3D p = _repere.Origine() + _entreAxe * _repere.X();
	return Repere3D(p, -(_repere.X()), -(_repere.Y()), _repere.Z());
}

