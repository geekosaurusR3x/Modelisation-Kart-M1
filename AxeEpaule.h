/*
Cr�ation :				Christophe ELSENSOHN 
Date de cr�ation :		05/04/2012
Version :				0
Modifi� par:			null
Date de modification:	null
*/

#pragma once
#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"
#include "Piece.h"

class AxeEpaule: public Piece
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
//					Constructeur d'instance de AxeEpaule 

	AxeEpaule(const Repere3D& repere=Repere3D(),
			double petitDiametre=5, double longueurPetitDiametre=10, double grandDiametre=8,
			double longueurGrandDiametre=4,AttributsFacesP *PtAF=new AttributsFaces(PMateriauVert))throw(exception);
/*
PARAMETRES

	- position				(const Points3D&)	: point se trouvant sur l'axe de l'axe �paul�. 
													Il se situe au centre de la face de jonction 
													du petit diam�tre et du grand diam�tre.

	- repere				(const Repere3D&)	: rep�re de l'axe �paul�.
													L'axe de l'axe �paul� suivra le vecteur Z de
													ce rep�re

	- petitDiametre			(double)			: diam�tre du petit diam�tre

	- longueurPetitDiametre (double)			: longueur du petit diam�tre de l'extr�mit� 
													jusqu'au plan de jonction avec le grand diam�tre

	- grandDiametre			(double)			: diam�tre du grand diam�tre

	- longueurGrandDiametre	(double)			: longueur du grand diam�tre de l'extr�mit� 
													jusqu'au plan de jonction avec le petit diam�tre

	- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe �paul�.
													Repr�sente la couleur de l'axe �paul�.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- "petitDiametre" et "grandDiametre" sont �gaux.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/


//_____________________________________________________________________________
//
//					Constructeur par recopie de AxeEpaule 

	AxeEpaule(const AxeEpaule& axeEpaule);


//_____________________________________________________________________________
//
//					Destructeur de AxeEpaule 

	virtual ~AxeEpaule();
	

//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************
	
//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP de forme Disque extr�me du petit diam�tre

	const FacesP& faceJointure()const;
	
//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP de forme Disque extr�me du petit diam�tre

	const FacesP& faceExtremitePetitDiam()const;

//_____________________________________________________________________________
//
//	Getter de la Droites3D de l'AxeEpaule.
//	Droites3D compos� de l'axe Z du rep�re et du Points3D position

	Droites3D getAxe() const;

//_____________________________________________________________________________
//
//	Getter du Repere de la face de Jointure
//	L'axe Z du rep�re est orient� vers le Grand diam�tre. Son origine se trouve sur 
//	l'axe la pi�ce au niveau du plan de jointure "grand diam�tre" - "petit diam�tre"

	Repere3D getRepereJointure()const;

//_____________________________________________________________________________
//
//	Getter du rep�re se trouvant sur la face circulaire extr�me du grand diam�tre
//	L'axe Z du rep�re est orient� vers l'ext�rieur.
//	Son origine se trouve sur l'axe la pi�ce au niveau de la face circulaire extreme du grand diam�tre

	Repere3D getRepereFaceGrandDiametre() const;

//_____________________________________________________________________________
//
//	Getter du rep�re se trouvant sur la face circulaire extr�me du petit diam�tre
//	L'axe Z du rep�re est orient� vers l'ext�rieur.
//	Son origine se trouve sur l'axe la pi�ce au niveau de la face circulaire extreme du petit diam�tre

	Repere3D getRepereFacePetitDiametre() const;


//#############################################################################
//								DOMAINE PROTECTED
//#############################################################################
protected:

//*****************************************************************************
//							DONNEES MEMBRES
//*****************************************************************************
//_____________________________________________________________________________
//
//	Rayon du petit diam�tre

	double _petitRayon;

//_____________________________________________________________________________
//
//	Longueur du petit diam�tre

	double _lgPetitDiam;

//_____________________________________________________________________________
//
//	Rayon du grand diam�tre

	double _grdRayon;

//_____________________________________________________________________________
//
//	Longueur du grand diam�tre

	double _lgGrdDiam;

//_____________________________________________________________________________
//
//	Pointeur sur la face disque du petit diam�tre

	const FacesP* _faceDisquePetitDiam;

//_____________________________________________________________________________
//
//	Pointeur sur la face de jointure des 2 diam�tres

	const FacesP* _faceJointure;


//#############################################################################
//								DOMAINE PRIVE
//#############################################################################
private:

//*****************************************************************************
//									METHODES
//*****************************************************************************
	
//_____________________________________________________________________________
//
//	M�thode de construction de AxeEpaule
//	Cette m�thode cr�e 2 Cylindres: 1 pour le chapeau (grand diam�tre) et un pour l'axe (petit diam�tre).
//	Puis elle colle l'axe sur le chapeau.

	virtual void buildAll();

//_____________________________________________________________________________
//
//	M�thode de contr�le des arguments pass�s pour la construction de l'axe �paul�
//	Si le grand diam�tre est plus petit que le petit diam�tre, 
//	les valeurs sont invers�es comme suit:
//
//	petitRayon --> grandRayon
//	grandRayon --> petitRayon
//	longueurPetitDiam�tre --> longeurGrandDiam�tre
//	longeurGrandDiam�tre --> longueurPetitDiam�tre 

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- "petitDiametre" et "grandDiametre" sont �gaux.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
	virtual void ControleValiditeArgConstruct() throw (exception);
};

