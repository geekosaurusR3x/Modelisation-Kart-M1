#include "StdAfx.h"
#include "Piece.h"

#define NULL 0

Piece::Piece(const Repere3D& repere, AttributsFacesP* attributFace)
	  :_repere(repere),
	   _attributFace(attributFace)
{
}

Piece::~Piece(){

}


Repere3D Piece::getRepere3D()const {
	// Retourne le repere 3D de la piece
	return _repere;
}

void Piece::rotationSurX(double teta){
	// Génération de la matrice rotation autour de X
	Matrices4D matriceRotation;
	matriceRotation.DevenirRotationQuelconque (getRepere3D().Origine(), getRepere3D().X(), teta);

	// Transformation de la piexe
	Transformer(matriceRotation);
	
	// Déplacement du repere
	_repere = Repere3D(_repere.Origine() * matriceRotation, getRepere3D().X() * matriceRotation, getRepere3D().Y() * matriceRotation, getRepere3D().Z() * matriceRotation);
}

void Piece::rotationSurY(double teta){
	// Génération de la matrice rotation autour de X
	Matrices4D matriceRotation;
	matriceRotation.DevenirRotationQuelconque (getRepere3D().Origine(), getRepere3D().Y(), teta);

	// Transformation de la piexe
	Transformer(matriceRotation);
	
	// Déplacement du repere
	_repere = Repere3D(_repere.Origine() * matriceRotation, getRepere3D().X() * matriceRotation, getRepere3D().Y() * matriceRotation, getRepere3D().Z() * matriceRotation);
}

void Piece::rotationSurZ(double teta){
	// Génération de la matrice rotation autour de X
	Matrices4D matriceRotation;
	matriceRotation.DevenirRotationQuelconque (getRepere3D().Origine(), getRepere3D().Z(), teta);

	// Transformation de la piexe
	Transformer(matriceRotation);
	
	// Déplacement du repere
	_repere = Repere3D(getRepere3D().Origine() * matriceRotation, getRepere3D().X() * matriceRotation, getRepere3D().Y() * matriceRotation, getRepere3D().Z() * matriceRotation);
}
	

void Piece::deplacerVers(const Points3D& nouvellePosition){
	// Calcul du vecteur déplacement
	Vecteurs3D vectDeplacement = Vecteurs3D( _repere.Origine(), nouvellePosition );

	// Calcul de la nouvelle position
	_repere.ModifOrigine(nouvellePosition - getRepere3D().Origine());

	// Application de la translation
	Matrices4D matriceRotation;
	matriceRotation.DevenirTranslation(vectDeplacement);
	Transformer(matriceRotation);
}


void Piece::transposerVers(Repere3D repere){
	// On norme les vecteurs
	repere.normer();
	
	// Application de la translation
	Matrices4D matriceRotation;
	matriceRotation.DevenirChangementDeRepereLocalVersLocal(getRepere3D().Origine(), getRepere3D().X(), getRepere3D().Y(), getRepere3D().Z(), repere.Origine(), repere.X(), repere.Y(), repere.Z());
	Transformer(matriceRotation);

	// Application des données
	_repere = repere;
}

FacesP Piece::ConstuireFacesDepuisSommets(Tableaux<SommetsP> sommets){

	// Création d'un tableau d'arêtes de même dimention
	Tableaux<AretesP> aretes(sommets.Nb_Elements(),1);

	// Pour chaque sommet, on le lit avec son voisin, de proche en proche
	for(int i=0; i<sommets.Nb_Elements(); i++){

		int indice = i;
		int prochainIndice = i+1;

		// Si l'indice atteind 0, alors le prochain indice n'est pas son suivant
		// Mais le premier
		// Permet de fermer la face
		if( i == sommets.Nb_Elements()-1 )
			prochainIndice = 0;

		// Construction de l'arete
		aretes[i] = AretesP( sommets[indice], sommets[prochainIndice] );
	}

	// On retourne la face construite 
	return FacesP( ContoursP(aretes), _attributFace );;
}
