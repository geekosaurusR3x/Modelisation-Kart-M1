#include "StdAfx.h"
#include "Repere3D.h"

Repere3D::Repere3D()
		 :Reperes3D(Points3D(0,0,0), *IMonde, *JMonde, *KMonde){
}

Repere3D::Repere3D(const Points3D& o)
		 :Reperes3D(o, *IMonde, *JMonde, *KMonde){
	// Un repere doit être normé
	normer();
}
Repere3D::Repere3D(const Repere3D& repere)
		 :Reperes3D(repere){
	// Un repere doit être normé
	normer();
}

Repere3D::~Repere3D(){
}


Repere3D::Repere3D( const Points3D& o, const Vecteurs3D& x, const Vecteurs3D& y, const Vecteurs3D& z)
		 :Reperes3D(o, x, y, z){
}


Vecteurs3D Repere3D::X() const{
	// Récupération de la matrice 3D pour creer le vecteur X du repere
	Matrices3D mat = Base();
	return Vecteurs3D( mat.M(0,0), mat.M(1,0), mat.M(2,0));
}

Vecteurs3D Repere3D::Y() const{
	// Récupération de la matrice 3D pour creer le vecteur Y du repere
	Matrices3D	mat = Base();
	return Vecteurs3D( mat.M(0,1), mat.M(1,1), mat.M(2,1));
}

Vecteurs3D Repere3D::Z() const{
	// Récupération de la matrice 3D pour creer le vecteur Y du repere
	Matrices3D	mat = Base();
	return Vecteurs3D( mat.M(0,2), mat.M(1,2), mat.M(2,2));
}


void Repere3D::X(const Vecteurs3D x){

	// On norme le vecteur
	x.VecteurNorme();

	// Modification de la matrice pour modifier le vecteur X
	Matrices3D	mat = Base();
	mat.ModifM(0, 0, x.X());
	mat.ModifM(1, 0, x.Y());
	mat.ModifM(2, 0, x.Z());
}

void Repere3D::Y(const Vecteurs3D y){

	// On norme le vecteur
	y.VecteurNorme();

	// Modification de la matrice pour modifier le vecteur Y
	Matrices3D	mat = Base();
	mat.ModifM(0, 1, y.X());
	mat.ModifM(1, 1, y.Y());
	mat.ModifM(2, 1, y.Z());
}

void Repere3D::Z(const Vecteurs3D z){

	// On norme le vecteur
	z.VecteurNorme();

	// Modification de la matrice pour modifier le vecteur Z
	Matrices3D	mat = Base();
	mat.ModifM(0, 2, z.X());
	mat.ModifM(1, 2, z.Y());
	mat.ModifM(2, 2, z.Z());
}

void Repere3D::normer(){
	// Norme les 3 vecteurs du repere
	X(X().VecteurNorme());
	Y(Y().VecteurNorme());
	Z(Z().VecteurNorme());
}