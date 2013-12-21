/**
 * Classe Repere3D
 * ***************
 * La classe Repere3D est une amélioration de la classe Reperes3D de la bibliothèque de Regain.
 * Elle permet de modifier ou de récupérer les données du repere directement avec des vecteurs sans passer par la matrice 3D
 * Remarque : Le repere est toujours normé!
 *
 * Auteur :		SCHEIBEL Jean-Baptiste
 * Créé le :	5 avril 2012
 * Modifié le : 9 avril 2012
 * Version :	1
 */
#pragma once
#include "reperes3d.h"

class Repere3D : public Reperes3D
{
public:
	/**
	 * Constructeur par défaut du Repere3D
	 * Construit le repere en fonction des vecteurs mondes : (O,I,J,K)
	 */
	Repere3D();

	/**
	 * Construit le repere à partir d'une position données
	 * Les vecteurs du repere correspont au vecteurs monde (I,J,K)
	 * o : Point d'origine du repere
	 */
	Repere3D(const Points3D& o);

	/**
	 * Construit un repere à partir d'un autre
	 * repere : repere à copier
	 */
	Repere3D(const Repere3D&);

	/**
	 * Construit un repere à partir d'une position et de 3 vecteurs
	 * o : Origine du repere
	 * x : Vecteur x du repere
	 * y : Vecteur y du repere
	 * z : Vecteur z du repere
	 */
	Repere3D( const Points3D& o, const Vecteurs3D& x, const Vecteurs3D& y, const Vecteurs3D& z);

	/**
	 * Destructeur du repere 3D
	 */
	virtual ~Repere3D();

	/**
	 * Permet de récuperer le vecteur X du repere
	 */
	Vecteurs3D X() const;

	/**
	 * Permet de récuperer le vecteur Y du repere
	 */
	Vecteurs3D Y() const;

	/**
	 * Permet de récuperer le vecteur Z du repere
	 */
	Vecteurs3D Z() const;

	/**
	 * Permet de modifier le vecteur X du repere
	 * x : nouveau vecteur X
	 */
	void X(const Vecteurs3D x);

	/**
	 * Permet de modifier le vecteur Y du repere
	 * y : nouveau vecteur Y
	 */
	void Y(const Vecteurs3D y);

	/**
	 * Permet de modifier le vecteur Z du repere
	 * z : nouveau vecteur Z
	 */
	void Z(const Vecteurs3D z);

	/**
	 * Permet de normer le repere
	 */
	void normer();
};

