#include "stdafx.h"
#include "TINormaleFace.h"
#include "BibliothequeLGB.h"
#include "BibliothequeBRepP.h"
#include "Form1.h"

TINormaleFace::TINormaleFace ()
	: TraitementsInteractifs ()
{
}

SolidesP	ConstruireNormale (FacesP Face)
// Construit un solide symbolisant la normale à la face.
// Le solide est placé sur le barycentre de la face et peut donc
// être hors de la face.
// Sa longueur est égale à 5% de la dimension du solide à laquelle la
// face appartient s'il existe. Sinon, c'est 10 % de la dimension de la face.
{
	SolidesP	Sol = Face.Solide () ;

	double	HauteurTot ;

	Englobants3D	EnglobantFace = Face.Englobant () ;

	if (Sol.EstInitialise ()) {
		Englobants3D	E = Sol.Englobant () ;
		Vecteurs3D		V (E.BasGauche (),E.HautDroit ()) ;
		HauteurTot = 0.05*V.Norme () ; ;
	}
	else {
		Vecteurs3D		V (EnglobantFace.BasGauche (),EnglobantFace.HautDroit ()) ;
		HauteurTot = 0.1*V.Norme () ; ;
	}

	double	LargeurPied = HauteurTot / 24,
            LargeurTete = HauteurTot / 4,
            HauteurPied = (7./8.)*HauteurTot ;

	// Construction d'un repère centré sur le "barycentre" de la face, dont
	// le (xOy) correspond au plan de la face et dont le z est la normale à
	// la face.
	Points3D	Origine = 0.5*(EnglobantFace.BasGauche ()+EnglobantFace.HautDroit ()) ;

	Vecteurs3D	K = Face.VecteurNormal ().VecteurNorme (),
				U (Face.ContourExterieur ().IemeAreteOrientee (0).Origine ().Point3D (),
				Face.ContourExterieur ().IemeAreteOrientee (0).Extremite ().Point3D ()),
				I = (K & U).VecteurNorme (),
				J = (K & I).VecteurNorme () ;

	SommetsP	S1 (Origine-LargeurPied/2*I - LargeurPied/2*J) ;
	SommetsP	S2 (Origine-LargeurPied/2*I + LargeurPied/2*J) ;
	SommetsP	S3 (Origine+LargeurPied/2*I + LargeurPied/2*J) ;
	SommetsP	S4 (Origine+LargeurPied/2*I - LargeurPied/2*J) ;
	SommetsP	S5 (Origine-LargeurPied/2*I - LargeurPied/2*J + HauteurPied*K) ;
	SommetsP	S6 (Origine-LargeurPied/2*I + LargeurPied/2*J + HauteurPied*K) ;
	SommetsP	S7 (Origine+LargeurPied/2*I + LargeurPied/2*J + HauteurPied*K) ;
	SommetsP	S8 (Origine+LargeurPied/2*I - LargeurPied/2*J + HauteurPied*K) ;
	SommetsP	S9 (Origine-LargeurTete/2*I - LargeurTete/2*J + HauteurPied*K) ;
	SommetsP	S10 (Origine-LargeurTete/2*I + LargeurTete/2*J + HauteurPied*K) ;
	SommetsP	S11 (Origine+LargeurTete/2*I + LargeurTete/2*J + HauteurPied*K) ;
	SommetsP	S12 (Origine+LargeurTete/2*I - LargeurTete/2*J + HauteurPied*K) ;
	SommetsP	S13 (Origine+HauteurTot*K) ;

	AretesP	A1 (S1,S2) ;
	AretesP	A2 (S2,S3) ;
	AretesP	A3 (S3,S4) ;
	AretesP	A4 (S4,S1) ;
	AretesP	A5 (S5,S6) ;
	AretesP	A6 (S6,S7) ;
	AretesP	A7 (S7,S8) ;
	AretesP	A8 (S8,S5) ;
	AretesP	A9 (S9,S10) ;
	AretesP	A10 (S10,S11) ;
	AretesP	A11 (S11,S12) ;
	AretesP	A12 (S12,S9) ;
	AretesP	A13 (S1,S5) ;
	AretesP	A14 (S2,S6) ;
	AretesP	A15 (S3,S7) ;
	AretesP	A16 (S4,S8) ;
	AretesP	A17 (S9,S13) ;
	AretesP	A18 (S10,S13) ;
	AretesP	A19 (S11,S13) ;
	AretesP	A20 (S12,S13) ;

	Listes <AretesP>	L1 ;
	L1.InsertionEnQueue (A1) ;
	L1.InsertionEnQueue (A2) ;
	L1.InsertionEnQueue (A3) ;
	L1.InsertionEnQueue (A4) ;

	Listes <AretesP>	L2 ;
	L2.InsertionEnQueue (A1) ;
	L2.InsertionEnQueue (A13) ;
	L2.InsertionEnQueue (A5) ;
	L2.InsertionEnQueue (A14) ;

	Listes <AretesP>	L3 ;
	L3.InsertionEnQueue (A2) ;
	L3.InsertionEnQueue (A14) ;
	L3.InsertionEnQueue (A6) ;
	L3.InsertionEnQueue (A15) ;

	Listes <AretesP>	L4 ;
	L4.InsertionEnQueue (A3) ;
	L4.InsertionEnQueue (A15) ;
	L4.InsertionEnQueue (A7) ;
	L4.InsertionEnQueue (A16) ;

	Listes <AretesP>	L5 ;
	L5.InsertionEnQueue (A4) ;
	L5.InsertionEnQueue (A16) ;
	L5.InsertionEnQueue (A8) ;
	L5.InsertionEnQueue (A13) ;

	Listes <AretesP>	L6 ;
	L6.InsertionEnQueue (A9) ;
	L6.InsertionEnQueue (A10) ;
	L6.InsertionEnQueue (A11) ;
	L6.InsertionEnQueue (A12) ;

	Listes <AretesP>	L7 ;
	L7.InsertionEnQueue (A8) ;
	L7.InsertionEnQueue (A7) ;
	L7.InsertionEnQueue (A6) ;
	L7.InsertionEnQueue (A5) ;

	Listes <AretesP>	L8 ;
	L8.InsertionEnQueue (A9) ;
	L8.InsertionEnQueue (A17) ;
	L8.InsertionEnQueue (A18) ;

	Listes <AretesP>	L9 ;
	L9.InsertionEnQueue (A10) ;
	L9.InsertionEnQueue (A18) ;
	L9.InsertionEnQueue (A19) ;

	Listes <AretesP>	L10 ;
	L10.InsertionEnQueue (A11) ;
	L10.InsertionEnQueue (A19) ;
	L10.InsertionEnQueue (A20) ;

	Listes <AretesP>	L11 ;
	L11.InsertionEnQueue (A12) ;
	L11.InsertionEnQueue (A20) ;
	L11.InsertionEnQueue (A17) ;

	Listes <FacesP>	ListeFaces ;
	AttributsFaces	*PAF = new AttributsFaces (PMateriauRouge) ;
	FacesP F1 (ContoursP (L1),PAF) ;
	ListeFaces.InsertionEnQueue (F1) ;
	ListeFaces.InsertionEnQueue (FacesP (ContoursP (L2),PAF)) ;
	ListeFaces.InsertionEnQueue (FacesP (ContoursP (L3),PAF)) ;
	ListeFaces.InsertionEnQueue (FacesP (ContoursP (L4),PAF)) ;
	ListeFaces.InsertionEnQueue (FacesP (ContoursP (L5),PAF)) ;
	ContoursP C (L6) ;
	FacesP	F (C,PAF) ;
	F.AjouterContourInterieur (ContoursP (L7)) ;
	ListeFaces.InsertionEnQueue (F) ;
	ListeFaces.InsertionEnQueue (FacesP (ContoursP (L8),PAF)) ;
	ListeFaces.InsertionEnQueue (FacesP (ContoursP (L9),PAF)) ;
	ListeFaces.InsertionEnQueue (FacesP (ContoursP (L10),PAF)) ;
	ListeFaces.InsertionEnQueue (FacesP (ContoursP (L11),PAF)) ;

	return SolidesP (ListeFaces) ;
}

void TINormaleFace::Traitement ()
{
	switch (phase)
	{
	case 0 :	{	phase++ ;
					EnsemblesOptionsDialogue	EOD ;
					EnsemblesMenus					EM ;

					EOD.AjouterOption (LGBDesignationFace) ;
					LogicielsGraphiquesBase::Defaut ()->FixerContexteProchaineInteraction (
							"Montrer la face dont vous voulez la normale",
							EOD,
							EM,
							this) ;
				}
				break ;
	case 1 :
				{
					FacesP	Face = LogicielsGraphiquesBase::Defaut ()->ResultatsInteraction.FaceDesignee ;

					// Construction d'une flèche issue de la face
					SolidesP	Fleche = ConstruireNormale (Face) ;
					LogicielsGraphiquesBase::Defaut ()->AfficherSolide (Fleche,-1) ;
					NSConsole::Console->MontrerConsole () ;
					char S [100] ;
					sprintf (S,"normale (%lf;%lf;%lf)", 
								Face.VecteurNormal ().X(), 
								Face.VecteurNormal ().Y(), 
								Face.VecteurNormal ().Z()) ;
					
					(*NSConsole::Console) << S ;
					delete this ;
				}
				break ;
	}
}


void TINormaleFace::Interruption ()
{
	// rien à faire : pas de mémoire allouée dynamiquement, ni dans phase 0
	// ni dans phase 1 ;
}


TINormaleFace::~TINormaleFace ()
{
}




TINormaleFace::TINormaleFace (const TINormaleFace &TID)
:	TraitementsInteractifs (TID)
{
}

const TINormaleFace&	TINormaleFace::operator = (const TINormaleFace &O)
{
	if (&O != this)
	{
		(TraitementsInteractifs &)(*this) = O;
	}

	return *this;
}

ostream& 	operator << (ostream & os, const TINormaleFace &TID)
{
	os << "Phase=" << TID.phase << " dans traitement interactif TIDecodage\n" ;
   return os ;
}

bool 	operator == (const TINormaleFace&, const TINormaleFace&)
{
	return false ;
}


