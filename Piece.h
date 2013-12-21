/**
 * Classe Piece
 * ************
 * La classe piece est la classe parente de toutes les pi�ces qui peuvent �tre mod�lis�es.
 * C'est une am�lioration de la classe SolidesP de Regain.
 * Elle contient un Repere 3D local � l'objet permettant de le situer dans l'espace et de conna�tre son orientation
 * Elle permet d'executer plusieurs action : Rotation sur un axe local de l'objet, deplacement dans l'espace, transposer sur un nouveau repere de l'espace
 *
 * Recommandation: 
 * ***************
 * Il est tr�s important de n'utiliser que les m�thodes de transformation, translation, rotation de la classe pi�ce et non pas les primitives de la biblioth�que Regain!
 * En cas d'utilisation d'une m�thode non recommand�e, les donn�es de la pi�ce risque de ne plus �tre coh�rent.
 * Il est donc essentiel de faire appel � l'�quipe mod�lisation en cas de possible m�thode manquante!
 *
 * Auteur :		SCHEIBEL Jean-Baptiste
 * Cr�� le :	4 avril 2012
 * Modifi� le : 9 avril 2012
 * Version :	1
 */
#pragma once
#include "BibliothequeBRepP.h"
#include "BibliothequeMathematique.h"
#include "AttributsFacesP.h"
#include "Repere3D.h"

class Piece : public SolidesP
{
protected:
	// Repere 3D local de l'objet
	Repere3D _repere;

	// Attributs des faces qui leurs seront appliqu�s
	AttributsFacesP *_attributFace;

	/**
	 * Permet de construire une pi�ce
	 * M�thode � impl�menter pour chaque pi�ce h�ritant de cette classe
	 */
	virtual void buildAll() = 0;

	/**
	 * Permet de construire une face � partir d'un tableau de sommets
	 * Les sommets dans le tableau doivent �tre ordonn�es dans le sens de construction
	 * Retourne la face construite
	 */
	FacesP ConstuireFacesDepuisSommets(Tableaux<SommetsP> sommets);


public:

	virtual Repere3D getRepere3D()const;

	/**
	 * Constructeur de Piece
	 * repere : Repere local de la piece
	 * attributFace : Attribut des faces
	 */
	Piece(const Repere3D& repere, AttributsFacesP* attributFace);

	/**
	 * Destructeur de Piece
	 */
	virtual ~Piece();
	
	/**
	 * Permet d'executer une rotation de sur teta l'axe local X de l'objet
	 * teta : Angle de rotation. Doit �tre exprim� en radian
	 */
	virtual void rotationSurX(double teta);

	/**
	 * Permet d'executer une rotation de sur teta l'axe local Y de l'objet
	 * teta : Angle de rotation. Doit �tre exprim� en radian
	 */
	virtual void rotationSurY(double teta);

	/**
	 * Permet d'executer une rotation de sur teta l'axe local Z de l'objet
	 * teta : Angle de rotation. Doit �tre exprim� en radian
	 */
	virtual void rotationSurZ(double teta);

	/**
	 * Permet de d�placer le repere local vers une nouvelle position.
	 * Seul la position du repere change. l'orientation du repere reste la m�me!
	 * nouvellePosition : Nouvelle position du repere local dans l'espace
	 */
	void deplacerVers(const Points3D& nouvellePosition);

	/**
	 * Permet de transposer le repere local vers un nouveau repere de l'espace
	 * Modifie la position du repere et son orientation avec les donn�es du nouveau repere
	 * repere : Nouveau repere local de la piece
	 */
	void transposerVers(Repere3D repere);
	

};