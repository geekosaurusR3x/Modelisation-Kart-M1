/*
Création :				Christophe ELSENSOHN 
Date de création :		09/04/2012
Version :				4
Modifié par:			Christophe ELSENSOHN 
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
		
	- repere							(const Repere3D&)	:	repère de la crémaillère.
																L'axe de travail de la crémaillère suivra l'axe X du repère
																L'origine se trouvera sur la face inférieure
																(opposée aux dents) à l'intersection des diagonales de
																la face.
												  
	- nbDents							(unsigned int)		:	nombre de dents du bloc denture.
		
	- module							(double)			:	Définitions wikipédia :
																	"paramètre dimensionnel générateur relatif à la périodicité des dents donc à leur taille. "
																	"Quotient du diamètre primitif par le nombre de dents"
																Plus simplement le diamètre primitif est compris entre le grand diamètre, dit de tête, et le petit diamètre, dit de pied.
																Le nombre de dents * le module donne le diamètre primitif.
																Pour une crémaillère cela n'a pas de sens de parler de diamètre, cependant, pour que 2
																éléments puissent s'entrainer l'un l'autre, ils doivent avoir le même module.
		
	- longueurTotale					(double)			:	Longueur totale de la crémaillère.
																Egale à la longueur du bloc de denture + 2 * la longueur des bloc inclinés.
		
	- longueurBlocDentures				(double)			:	longueur du bloc de denture. 
													
	- largeurCremaillere				(double)			:	largeur de la crémaillère (suivant l'axe d'une dent)
		
	- distanceBase_HautDenture			(double)			:	distance entre la face de base (inférieure) et le haut des dents.
		
	- hauteurBasePlanIncline			(double)			:	dimension du plat de la face avant.
																dimension à partir de la face inférieure
																le haut de ce plat définira le début de la partie incliné
														
	- anglePlat							(double)			:	angle d'inclinaison de la partie inclinée.
																angle entre la partie supérieure (horizon local) et la partie incliné.
	
	- diamPercage						(double)			:	diamètre de percage des trous.
	
	- profondeurPercage					(double)			:	profondeur de percage des trous.

	- distancePercageDepuisExtremite	(double)		:	distance de percage des trous depuis leurs extrémités respectives.
		
	- PtAF								(AttributsFacesP*)	:	Attribut des faces de l'axe épaulé goupillable. 
																Représente la couleur de l'axe épaulé goupillable.


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							RECOMMANDATIONS

Le percage des trous se fait au milieu de la pente.

Il est possible de mettre un angle de plat à:
0		-->	il n'y a pas d'inclinaison.
PI/2	-->	Il n'y a pas d'inclinaison apparente. Les trous sont faits sur la face avant.
			Pour les avoir centrés sur la hauteur de la face avant, mettez le paramètre hauteurBasePlanIncline à 0.


							EXCEPTIONS LEVEES

Une exception sera levé si:
- La combinaison du nombre de dents et du module font que les dents débordent du bloc denture.
- La longueur totale est inférieure à la longueur du bloc denture.
- La hauteur (paramètre distanceBase_HautDenture) est inférieure à la hauteur d'un dent (définie par le module).
- la hauteur des plats avants (paramètre hauteurBasePlanIncline) est supérieure à la hauteur totale de la crémaillère.
- la distance de percage ( paramètre distancePercageDepuisExtremite) est inférieure au diamètre de percage.
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
//	Getter de la droite passant par l'origine de la pièce et ayant comme
//	direction, l'axe de travail de la crémaillère
	
	Droites3D getAxe() const;
	
//_____________________________________________________________________________
//
//	Getter du Repère du trou gauche (ou X- du repere local) de la crémaillère.  
	
	Repere3D getRepereTrouGauche()const;

//_____________________________________________________________________________
//
//	Getter du Repère du trou droit (ou X+ du repere local) de la crémaillère.

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
//	nombre de dents de la crémaillère

	unsigned int _nbDents;

//_____________________________________________________________________________
//
//	module de la denture de la crémaillère

	double _module;

//_____________________________________________________________________________
//
//	Longueur totale de la crémaillère

	double _lgTotal;

//_____________________________________________________________________________
//
//	moitié de la longueur du bloc de denture

	double _demiLongueurBlocDentures;

//_____________________________________________________________________________
//
//	Largeur de la crémaillère

	double _largeurCrem;

//_____________________________________________________________________________
//
//	Hauteur de la crémaillère, jusqu'à la face supérieure des dents

	double _hauteurBaseTete;

//_____________________________________________________________________________
//
//	Hauteur des plats de la face avant menant sur la face inclinée

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
//	distance entre le bord extrème du bloc incliné et le point de percage

	double _distPercExtrem;

//_____________________________________________________________________________
//
//	longueur des blocs inclinés

	double _largeurBlocIncline;

//_____________________________________________________________________________
//
//	FacesP incliné. Utilisé pour récupérer son vecteur normal

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
//	Méthode de construction de la crémaillère

	virtual void buildAll();
	
//_____________________________________________________________________________
//
//	Méthode de contrôle des arguments passés pour la construction d'une crémaillère
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- La combinaison du nombre de dents et du module font que les dents débordent du bloc denture.
- La longueur totale est inférieure à la longueur du bloc denture.
- La hauteur (paramètre distanceBase_HautDenture) est inférieure à la hauteur d'un dent (définie par le module).
- la hauteur des plats avants (paramètre hauteurBasePlanIncline) est supérieure à la hauteur totale de la crémaillère.
- la distance de percage ( paramètre distancePercageDepuisExtremite) est inférieure au diamètre de percage.
- l'angle d'inclinaison n'est pas compris en 0 et Pi/2


!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!.
*/
	virtual void ControleValiditeArgConstruct() throw (exception);

//_____________________________________________________________________________
//
//	Méthode qui crée un Repère3D incliné sur le point atteind depuis l'origine par le vecteur passé en paramètre.
	
	Repere3D creerRepereTrou(const Vecteurs3D& vecteurOrigineCentreTrou)const;
	
};

