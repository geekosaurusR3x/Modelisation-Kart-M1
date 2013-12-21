/*
Cr�ation :				Christophe ELSENSOHN 
Date de cr�ation :		10/04/2012
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

class AxePiedColonneDirection:public Piece
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
//	Constructeur d'instance de AxePiedColonneDirection 

		AxePiedColonneDirection(const Repere3D& repere=Repere3D(),
			double diametre=5, double longueurDiametre=10,double coteCarre=2,
			double longueurCarre=5,AttributsFacesP *PtAF=&AttributsFaces(PMateriauVert))
			throw(exception);
/*
#PARAMETRES
		- repere				(const Repere3D&)	: rep�re de l'axe.
														L'axe de l'axe de r�volution
														origine se trouvant sur l'axe de l'axe 
														Il se situe au centre de la face cylindrique.
		
		- Diametre				(double)			: diam�tre
		
		- longueurDiametre		(double)			: longueur du cylindre 
		
		- coteCarre				(double)			: cote du carr�.
		
		- longueurCarre			(double)			: Longueur d'extrusion du carr�
		
		- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe �paul� goupillable.
														Repr�sente la couleur de l'axe �paul� goupillable.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- la diagonale du carr� est sup�rieure au diam�tre.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

//_____________________________________________________________________________
//
//	Constructeur par recopie de AxePiedColonneDirection

		AxePiedColonneDirection(const AxePiedColonneDirection& axePiedColonneDirection);

//_____________________________________________________________________________
//
//	Destructeur de AxePiedColonneDirection

	virtual ~AxePiedColonneDirection(void);


//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter du repere sur la face carr�e

	Repere3D getRepere3DOppose();

//_____________________________________________________________________________
//
//	Getter du repere sur la jointure

	Repere3D getRepere3DJointure();

//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP cylindrique du diam�tre

	const FacesP& faceInferieur()const;


//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP de jonction entre le diam�tre et le carr�

	const FacesP& faceJonction()const;


//_____________________________________________________________________________
//
//	Getter de la r�f�rence sur la FacesP carr� extreme

	const FacesP& faceCarre()const;
	
//_____________________________________________________________________________
//
//	Getter de la Droites3D de l'Axe.
//	Droites3D compos� de l'axe Z du rep�re et du Points3D se trouvant sur la face oppos� au carr�

	Droites3D getAxe() const;


//#############################################################################
//								DOMAINE PROTECTED
//#############################################################################
protected:

//*****************************************************************************
//							DONNEES MEMBRES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Rayon du diam�tre

	double _rayon;

//_____________________________________________________________________________
//
//	Longueur de la partie cylindrique

	double _lgDiametre;

//_____________________________________________________________________________
//
//	moiti� du cot� du carr�

	double _demiCoteCarre;

//_____________________________________________________________________________
//
//	longueur d'extrusion du carr�

	double _lgCarre;

//_____________________________________________________________________________
//
//	Pointeur sur la face cylindrique oppos� au carr�

	const FacesP* _faceInf;

//_____________________________________________________________________________
//
//	Pointeur sur la face de jonction cylindre carr�

	const FacesP* _faceJonction;

//_____________________________________________________________________________
//
//	/Pointeur sur la face Extreme Carre

	const FacesP* _faceCarre;

//#############################################################################
//								DOMAINE PRIVE
//#############################################################################
private:

//*****************************************************************************
//									METHODES
//*****************************************************************************
	
//_____________________________________________________________________________
//
//	M�thode de construction de AxePiedColonneDirection
	
	virtual void buildAll();

//_____________________________________________________________________________
//
//	M�thode de controle des arguments pass�s pour la construction
	
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- la diagonale du carr� est sup�rieure au diam�tre.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
	virtual void ControleValiditeArgConstruct() throw (exception);
	
};

