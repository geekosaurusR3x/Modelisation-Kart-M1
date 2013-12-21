#include "StdAfx.h"
#include "Perceuse.h"
#include "Piece.h"


void Perceuse::percer(const Repere3D& repere, SolidesP& solide, FacesP& faceDebouchante, FacesP& faceAPercer, OutilPercage* outil) throw(exception){

	// La direction est celle de la normale de la face débouchante
	// Elle est attribué sur le repereZ
	outil->transposerVers(repere);

	// On récupère le contour supérieur pour l'appliquer à la face depouchante
	if(!outil->avecBaseHaut()){
		ContoursP contourBaseHaut = outil->getContourBaseHaut();
		faceDebouchante.AjouterContourInterieur( contourBaseHaut );
	}

	// On récupère le contour inférieur pour l'appliquer à la face à percer
	if(!outil->avecBaseBas()){
		ContoursP contourBaseBas = outil->getContourBaseBas();
		faceAPercer.AjouterContourInterieur( contourBaseBas );
	}

	// On ajoute les faces au solide
	solide.AjouterFaces( outil->faceOutils() );
}

void Perceuse::percer(const Points3D& position, SolidesP& solide, FacesP& faceDebouchante, FacesP& faceAPercer, OutilPercage* outil) throw(exception){
	Perceuse::percer(getRepereDePercageDepuisFace(position, faceAPercer), solide, faceDebouchante, faceAPercer, outil);
}


void Perceuse::percer(const Repere3D& repere, SolidesP& solide, FacesP& faceAPercer, OutilPercage* outil) throw(exception){

	// La direction est celle de la normale de la face débouchante
	// Elle est attribué sur le repereZ
	outil->transposerVers(repere);

	// On récupère le contour pour le contour intérieur de la face
	// ContoursP contourBaseHaut = piece->getContourDePercage();
	ContoursP contourBaseHaut = outil->getContourDePercage();
	faceAPercer.AjouterContourInterieur( contourBaseHaut );

	// On ajoute les faces au solide
	solide.AjouterFaces( outil->faceOutils() );
}

void Perceuse::percer(const Points3D& position, SolidesP& solide, FacesP& faceAPercer, OutilPercage* outil) throw(exception){
	Perceuse::percer(getRepereDePercageDepuisFace(position, faceAPercer), solide,faceAPercer, outil) ;
}


Repere3D Perceuse::getRepereDePercageDepuisFace(const Points3D& position, FacesP& faceAPercer){
	// Vecteur Z : Inverse de la normale
	Vecteurs3D VectZ = -(faceAPercer.VecteurNormal().VecteurNorme());

	// Vecteur X dans le plan de la face :
	Points3D p = faceAPercer.Englobant().BasGauche();
	Points3D pos = position;
	Vecteurs3D VectX = Vecteurs3D(position, faceAPercer.Englobant().BasGauche()).VecteurNorme();

	// Vecteur Y, produit vectoriel de Z à X
	Vecteurs3D VectY = VectZ & VectX;
	
	// Création du repere
	Repere3D r = Repere3D(position, VectX, VectY, VectZ);
	return Repere3D(position, VectX, VectY, VectZ);
}