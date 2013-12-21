//*****************************************************************************
//
// Module	: Extrusions
//
// Fichier	: Extrusions.h
//
// Auteur	: Heschung Frédéric
//
// Date creat.	: 07/07/99
//
// Version	:
//
// Commentaires	: Interface de la classe Extrusions
//
//
//*****************************************************************************
// Includes
// Classe ModelesP
//	Constructeurs
// Methodes
// Divers : les fonctions internes à la classe Extrusions
//
//*****************************************************************************



//*****************************************************************************
//
// Includes
//
//*****************************************************************************


#ifndef _EXTRUSIONS_H_
#define _EXTRUSIONS_H_

#include "IdentifiantsP.h"

#include "BibliothequeMathematique.h"

#include "Tableaux.h"


//*****************************************************************************
//
// Classe Extrusions
//
//*****************************************************************************

class BREPP_DLL Extrusions : public SolidesP
{
public :
	Extrusions (Listes<Points3D>& Poly , const Vecteurs3D& V, 
				const AttributsSolidesP *PAS, const AttributsFacesP *PAF ) ;
	// Extrusion d'un polygone ( liste de pts ) selon un vecteur, cad création
	// d'UN PRISME.
	// Le polygone n'a pas besoin d'être orienté dans le sens inverse du vecteur,
	// MAIS il l'est forcément à la sortie.
	// Le polygone doit être plan, sans auto-intersections et doit contenir au
	// moins 3 points non alignés. Le vecteur ne doit pas être
	// parallèle au plan du polygone.

   Extrusions ( Listes<Points3D>& Poly , const Listes<Points3D>& Ligne, 
					const AttributsSolidesP *PAS, const AttributsFacesP *PAF ) ;
	// Extrusion d'un polygone selon une ligne brisée ( liste de pts )
	// On ne traite pas les cas où il y a recouvrement de matière
	// Le polygone doit être plan, sans auto-intersections et doit contenir au
	// moins 3 points non alignés. 
	// La position de la ligne brisée n'a pas d'importance. Seules comptent les
	// orientations et longueurs des différents segments qui la composent. 
	// Ce sont ces quantités qui définissent les dimensions des différents
	// tuyaux qui constituent l'objet construit.

	Extrusions ( Listes<Points3D>& Poly , const Points3D& O ,
				const Vecteurs3D& Direction , double alpha, 
				const AttributsSolidesP *PAS, const AttributsFacesP *PAF ) ;
	// Extrusion d'un polygone autour d'une droite ( définie par un vecteurs et
	// un point) d'un angle alpha (en radians). Il s'agit donc d'UNE REVOLUTION.
	// Le polygone doit être plan, sans auto-intersections et doit contenir au
	// moins 3 points non alignés. 
	// Le polygone ne doit pas avoir d'intersection avec l'axe. 
	// L'objet construit est de type tore.
	// Le sens de rotation est donné par la règle du tire-bouchon.
	// Le polygone n'a pas besoin d'être orientée dans le sens opposé à la rotation
	// MAIS il l'est forcément à la sortie.


	Extrusions (	Listes <Points3D> &Profil, double Angle, 
					const AttributsSolidesP *PAS, const AttributsFacesP *PAF ) ;
	// Construction d'un solide par révolution d'un profil OUVERT plan autour de l'axe joignant les deux
	// extrémités du profil.
	// Le sens positif de rotation est donné par le vecteur allant de l'origine à l'extrémité
	// du profil (règle du tire-bouchon).
	// L'angle (en radians) peut varier de 0 (exclu) à 2.pi.
	// 
	// Le solide construit "ressemble" à une sphère : des facettes triangulaires sur les 2 pôles et
	// des facettes quadrangulaires partout ailleurs.
	// Les simplifications que permettraient des segments perpendiculaires au profil ne sont pas
	// exploitées.

private :
	SolidesP ExtrusionSimple (	Listes<Points3D>& Poly , const Vecteurs3D& V, 
								const AttributsSolidesP *PAS, const AttributsFacesP *PAF ) ;

	SolidesP ExtrusionSurLigneBrisee (	Listes<Points3D>& Poly , const Listes<Points3D>& Ligne, 
										const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	SolidesP ExtrusionParRevolution (	Listes<Points3D>& Poly ,
										const Points3D& O ,const Vecteurs3D& Direction , double alpha, 
										const AttributsSolidesP *PAS, const AttributsFacesP *PAF ) ;

	SolidesP ExtrusionOrientee (	Listes<Points3D>& , const Vecteurs3D&, 
									const AttributsSolidesP *PAS, const AttributsFacesP *PAF ) ;

	void OrienterPolygone ( Listes<Points3D>& , const Vecteurs3D& , bool& ) ;

	void ExtrusionSurSolideSansBout (	Listes <FacesP> &ListeDesFaces , const Plans3D& ,
										Points3D , Points3D ,
										Listes<SommetsP>& , Listes<AretesP>&, 
										const AttributsFacesP *PAF ) ;

	Vecteurs3D Perpendiculaire ( const Vecteurs3D& ) ;

	void FermerSolide ( Listes <FacesP> &ListeDesFaces , const Listes<SommetsP>& ,
						const Listes<AretesP>& , const Listes<SommetsP>& ,
						const Listes<AretesP>&, 
						const AttributsFacesP *PAF ) ;

	void Swipping ( Listes <FacesP> &ListeDesFaces , const Matrices4D& , Listes<SommetsP>& ,
					Listes<AretesP>&  , int, 
					const AttributsFacesP *PAF ) ;

	void ExtrusionAutourAxe (	Listes <FacesP> &ListeDesFaces , Listes<Points3D>&  ,
								const Matrices4D& , double , int, 
								const AttributsFacesP *PAF ) ;

	SolidesP RevolutionProfilOuvert (Listes <Points3D> &Profil, double Angle, const AttributsSolidesP *PAS, const AttributsFacesP *PAF ) ;


	double DistancePolygoneDroite ( const Listes<Points3D>& , const Points3D A, const Vecteurs3D& ) ;
} ;


#endif _EXTRUSIONS_H_