/*
Cr�ation :				Christophe ELSENSOHN 
Date de cr�ation :		09/04/2012
Version :				4
Modifi� par:			Christophe ELSENSOHN 
Date de modification:	13/04/2012
*/
#pragma once
#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"
#include "Piece.h"
class CremaillereStandard:public Piece
{
//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################
public:

//*****************************************************************************
//						CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Constructeur d'instance de AxeEpauleGoupillable


		CremaillereStandard(const Repere3D& repere=Repere3D(), unsigned int nbDents=5,double module=1,
						double longueurTotale=55,double longueurBlocDentures=30, double largeurCremaillere=8,
						double distanceBase_HautDenture=6,double hauteurBasePlanIncline=4, double anglePlat=10*2*PI/360,
						double diamPercage=2,double profondeurPercage=4, double distancePercageDepuisExtremite=2,
						AttributsFacesP *PtAF=&AttributsFaces(PMateriauJaune))throw(exception);
/*
PARAMETRES
		
	- repere							(const Repere3D&)	:	rep�re de la cr�maill�re.
																L'axe de travail de la cr�maill�re suivra l'axe X du rep�re
																L'origine se trouvera sur la face inf�rieure
																(oppos�e aux dents) � l'intersection des diagonales de
																la face.
												  
	- nbDents							(unsigned int)		:	nombre de dents du bloc denture.
		
	- module							(double)			:	D�finitions wikip�dia :
																	"param�tre dimensionnel g�n�rateur relatif � la p�riodicit� des dents donc � leur taille. "
																	"Quotient du diam�tre primitif par le nombre de dents"
																Plus simplement le diam�tre primitif est compris entre le grand diam�tre, dit de t�te, et le petit diam�tre, dit de pied.
																Le nombre de dents * le module donne le diam�tre primitif.
																Pour une cr�maill�re cela n'a pas de sens de parler de diam�tre, cependant, pour que 2
																�l�ments puissent s'entrainer l'un l'autre, ils doivent avoir le m�me module.
		
	- longueurTotale					(double)			:	Longueur totale de la cr�maill�re.
																Egale � la longueur du bloc de denture + 2 * la longueur des bloc inclin�s.
		
	- longueurBlocDentures				(double)			:	longueur du bloc de denture. 
													
	- largeurCremaillere				(double)			:	largeur de la cr�maill�re (suivant l'axe d'une dent)
		
	- distanceBase_HautDenture			(double)			:	distance entre la face de base (inf�rieure) et le haut des dents.
		
	- hauteurBasePlanIncline			(double)			:	dimension du plat de la face avant.
																dimension � partir de la face inf�rieure
																le haut de ce plat d�finira le d�but de la partie inclin�
														
	- anglePlat							(double)			:	angle d'inclinaison de la partie inclin�e.
																angle entre la partie sup�rieure (horizon local) et la partie inclin�.
	
	- diamPercage						(double)			:	diam�tre de percage des trous.
	
	- profondeurPercage					(double)			:	profondeur de percage des trous.

	- distancePercageDepuisExtremite	(double)		:	distance de percage des trous depuis leurs extr�mit�s respectives.
		
	- PtAF								(AttributsFacesP*)	:	Attribut des faces de l'axe �paul� goupillable. 
																Repr�sente la couleur de l'axe �paul� goupillable.


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							RECOMMANDATIONS

Le percage des trous se fait au milieu de la pente.

Il est possible de mettre un angle de plat �:
0		-->	il n'y a pas d'inclinaison.
PI/2	-->	Il n'y a pas d'inclinaison apparente. Les trous sont faits sur la face avant.
			Pour les avoir centr�s sur la hauteur de la face avant, mettez le param�tre hauteurBasePlanIncline � 0.


							EXCEPTIONS LEVEES

Une exception sera lev� si:
- La combinaison du nombre de dents et du module font que les dents d�bordent du bloc denture.
- La longueur totale est inf�rieure � la longueur du bloc denture.
- La hauteur (param�tre distanceBase_HautDenture) est inf�rieure � la hauteur d'un dent (d�finie par le module).
- la hauteur des plats avants (param�tre hauteurBasePlanIncline) est sup�rieure � la hauteur totale de la cr�maill�re.
- la distance de percage ( param�tre distancePercageDepuisExtremite) est inf�rieure au diam�tre de percage.
- l'angle d'inclinaison n'est pas compris en 0 et Pi/2


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

//_____________________________________________________________________________
//
//	Constructeur par recopie de CremaillereStandard
	
	CremaillereStandard(const CremaillereStandard& cremaillere);

//_____________________________________________________________________________
//
//	Destructeur de CremaillereStandard
	
	virtual ~CremaillereStandard();

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter de la droite passant par l'origine de la pi�ce et ayant comme
//	direction, l'axe de travail de la cr�maill�re
	
	Droites3D getAxe() const;
	
//_____________________________________________________________________________
//
//	Getter du Rep�re du trou gauche (ou X- du repere local) de la cr�maill�re.  
	
	Repere3D getRepereTrouGauche()const;

//_____________________________________________________________________________
//
//	Getter du Rep�re du trou droit (ou X+ du repere local) de la cr�maill�re.

	Repere3D getRepereTrouDroit()const;


//#############################################################################
//								DOMAINE PROTECTED
//#############################################################################
protected:

//*****************************************************************************
//							DONNEES MEMBRES
//*****************************************************************************

//_____________________________________________________________________________
//
//	nombre de dents de la cr�maill�re

	unsigned int _nbDents;

//_____________________________________________________________________________
//
//	module de la denture de la cr�maill�re

	double _module;

//_____________________________________________________________________________
//
//	Longueur totale de la cr�maill�re

	double _lgTotal;

//_____________________________________________________________________________
//
//	moiti� de la longueur du bloc de denture

	double _demiLongueurBlocDentures;

//_____________________________________________________________________________
//
//	Largeur de la cr�maill�re

	double _largeurCrem;

//_____________________________________________________________________________
//
//	Hauteur de la cr�maill�re, jusqu'� la face sup�rieure des dents

	double _hauteurBaseTete;

//_____________________________________________________________________________
//
//	Hauteur des plats de la face avant menant sur la face inclin�e

	double _hauteurBase;

//_____________________________________________________________________________
//
//	angle d'inclinaison

	double _anglePlat;

//_____________________________________________________________________________
//
//	rayon des percages

	double _rayonPercage;

//_____________________________________________________________________________
//
//	profondeur des percages

	double _profPercage;

//_____________________________________________________________________________
//
//	distance entre le bord extr�me du bloc inclin� et le point de percage

	double _distPercExtrem;

//_____________________________________________________________________________
//
//	longueur des blocs inclin�s

	double _largeurBlocIncline;

//_____________________________________________________________________________
//
//	FacesP inclin�. Utilis� pour r�cup�rer son vecteur normal

	FacesP _facePlanInclineXMoins;

//_____________________________________________________________________________
//
//	Vecteur de l'origine vers le point de percage en X moins

	Vecteurs3D _OriginePtPercageXMoins;

//_____________________________________________________________________________
//
//	Vecteur de l'origine vers le point de percage en X plus

	Vecteurs3D _OriginePtPercageXPlus;


//#############################################################################
//								DOMAINE PRIVE
//#############################################################################
private:

//*****************************************************************************
//									METHODES
//*****************************************************************************
	
//_____________________________________________________________________________
//
//	M�thode de construction de la cr�maill�re

	virtual void buildAll();
	
//_____________________________________________________________________________
//
//	M�thode de contr�le des arguments pass�s pour la construction d'une cr�maill�re
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- La combinaison du nombre de dents et du module font que les dents d�bordent du bloc denture.
- La longueur totale est inf�rieure � la longueur du bloc denture.
- La hauteur (param�tre distanceBase_HautDenture) est inf�rieure � la hauteur d'un dent (d�finie par le module).
- la hauteur des plats avants (param�tre hauteurBasePlanIncline) est sup�rieure � la hauteur totale de la cr�maill�re.
- la distance de percage ( param�tre distancePercageDepuisExtremite) est inf�rieure au diam�tre de percage.
- l'angle d'inclinaison n'est pas compris en 0 et Pi/2


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!.
*/
	virtual void ControleValiditeArgConstruct() throw (exception);

//_____________________________________________________________________________
//
//	M�thode qui cr�e un Rep�re3D inclin� sur le point atteind depuis l'origine par le vecteur pass� en param�tre.
	
	Repere3D creerRepereTrou(const Vecteurs3D& vecteurOrigineCentreTrou)const;
	
};

