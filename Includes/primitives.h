#ifndef _Primitives_H_
#define _Primitives_H_

///////////////////////////////////////////////////////////////////////////////////////
//
//				VOLUMES PRIMITIFS (cubes, sphères cylindres ...)
//
// Toutes les constructions demandent un attribut de solide (utiliser la classe 
// AttributsSolides, qui hérite de AttributsSolidesP, et la classe AttributsFacees,
// qui hérite de AttributsFacesP.
// Le pointeur fourni pour ces 2 paramètres peut être NULL. Dans ce cas, des attributs
// par défaut seront utilisés au moment de l'affichage.
// L'attribut de solide n'est pas utilisé dans cette version.
//
///////////////////////////////////////////////////////////////////////////////////////

#include "IdentifiantsP.h"
#include "AttributsFacesP.h"
#include "AttributsSolidesP.h"

extern int CalculCoeffPol (double R, double SeuilPrecision) ;


class BREPP_DLL Cubes : public SolidesP
{
public :
	// Création d'un cube. Origine est le premier sommet, les 7 autres sont
	// obtenus en ajoutant Arete à X et/ou Y et/ou Z.
	// Arete doit être strictement positif !!
	// Si les paramètres sont invalides, le solide retourné est non initialisé
	// (le tester avec EstInitialise ())
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre
	Cubes (	const Points3D & Origine , const double Arete, 
			const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;

	// Les 2 fonctions qui suivent ne sont pas implémentées !!!
	void	ModifOrigine (const Points3D & Origine) ;
	void	ModifArete (const double a) ;

private :
	SolidesP CreerCube (const Points3D & Origine , const double Arete, 
			const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;

	Points3D		origine ;
	double		arete ;
} ;


class BREPP_DLL Cones : public SolidesP
{
public :

	Cones (	const Points3D & Origine , const Points3D & Extremite,
			const double RayonOrigine, const double RayonExtremite, 
			const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;
	// Attention : la distance entre les points et les rayons doivent être
	// supérieurs à l'epsilon de proximité.
	// Si les paramètres sont invalides, le solide retourné est non initialisé
	// (le tester avec EstInitialise ())
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre

private :
	SolidesP CreerCone (	const Points3D & Origine , const Points3D & Extremite,
							const double RayonOrigine,	const double RayonExtremite, 
							const AttributsSolidesP *PAS, const AttributsFacesP *PAF);
	// Teste les paramètres et en déduit s'il faut créer un cône ou un cône
	// tronqué.
	// Si les paramètres sont invalides, le solide retourné est non initialisé
	// (le tester avec EstInitialise ())

	SolidesP CreerConeNonTronque (	const Points3D & Origine ,
									const Points3D & Extremite,
									const double RayonExtremite, 
									const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	SolidesP CreerConeTronque (	const Points3D & Origine ,
								const Points3D & Extremite,
								const double RayonOrigine,
								const double RayonExtremite, 
								const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	Points3D	origine, extremite ;
	double	rayonOrigine, rayonExtremite ;
} ;


class BREPP_DLL Boites : public SolidesP
{
public :
	// création d'une boîte à faces parallèles aux plans de base
	// Les dimensions ne doivent pas etre NULLES !!!
	// Si les paramètres sont invalides, le solide retourné est non initialisé
	// (le tester avec EstInitialise ())
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre
	Boites (	const Points3D & Origine,
				const double EnX, const double EnY, const double EnZ, 
				const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;

	// Les 4 fonctions qui suivent ne sont pas implémentées !!!
	void	ModifOrigine (const Points3D & Origine) ;
	void	ModifEnX (const double EnX) ;
	void	ModifEnY (const double EnY) ;
	void	ModifEnZ (const double EnZ) ;

private :
	SolidesP CreerBoite (	const Points3D & Origine,
							const double EnX,
							const double EnY,
							const double EnZ, 
							const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	Points3D		origine ;
	double		enX, enY, enZ ;
} ;


class BREPP_DLL Parallelepipedes : public SolidesP
{
public :
	// Construction d'un parallelepipede.
	// P1 est le sommet de départ, P2 et P3 sont respectivement
	// les sommets le précédent et le suivant sur une même face.
	// P4 est l'extremite de l'arete partant de P1 et n'etant pas
	// situee dans le plan (P2,P1,P3).
	// Attention : les distances entre les points doivent être
	// supérieures à l'epsilon de proximité.
	// Si les données sont incorrectes, on restitue SolideErreur (à tester avec
	// EstInitialise ()).
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre
	Parallelepipedes (	const Points3D &P1, const Points3D &P2,
						const Points3D &P3, const Points3D &P4, 
						const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;

	// Les 4 fonctions qui suivent ne sont pas implémentées !!!
	void	ModifP1 (const Points3D & P) ;
	void	ModifP2 (const Points3D & P) ;
	void	ModifP3 (const Points3D & P) ;
	void	ModifP4 (const Points3D & P) ;

private :
	SolidesP CreerParallelepipede (	const Points3D &P1, const Points3D &P2,
									const Points3D &P3, const Points3D &P4, 
									const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	Points3D		p1,p2,p3,p4 ;
} ;


class BREPP_DLL Cylindres : public SolidesP
{
public :
	// Creation d'un cylindre. P1 et P2 sont les centres des 2 bases, R est
	// (devinez quoi ? ... OUI:) le rayon
	// Attention : la distance entre les points et le rayon doivent être
	// supérieurs à l'epsilon de proximité.
	// Si les paramètres sont invalides, le solide retourné est non initialisé
	// (le tester avec EstInitialise ())
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre
	Cylindres (	const Points3D &P1, const Points3D &P2, const double R, 
				const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;

	// Les 3 fonctions qui suivent ne sont pas implémentées !!!
	void	ModifCentre1 (const Points3D & P) ;
	void	ModifCentre2 (const Points3D & P) ;
	void	ModifRayon (const double R) ;

private :
	SolidesP CreerCylindre (const Points3D &P1, const Points3D &P2,
							const double R, 
							const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	Points3D		centre1,centre2 ;
	double		rayon ;
} ;


class BREPP_DLL Spheres : public SolidesP
{
public :
	// Creation d'un sphere. P est le centre, R est
	// (devinez quoi ? ... OUI:) le rayon
	// Attention : la distance entre les points et le rayon doivent être
	// supérieurs à l'epsilon de proximité.
	// Si les paramètres sont invalides, le solide retourné est non initialisé
	// (le tester avec EstInitialise ())
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre
	Spheres (	const Points3D &P, const double R, 
				const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;

	// Les 3 fonctions qui suivent ne sont pas implémentées !!!
	void	ModifCentre (const Points3D & P) ;
	void	ModifRayon (const double R) ;

private :
	SolidesP CreerSphere (	const Points3D &P, const double R, 
							const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	Points3D		centre ;
	double		rayon ;
} ;


class BREPP_DLL Ellipsoides : public SolidesP
{
public :
	// Création d'un ellipsoide.
	// Origine est le centre, les vecteurs U et V dirigent deux axes principaux,
	// le troisième étant dirigé par leur produit vectoriel, et R1, R2 R3 sont
	// les rayons sur ces trois axes.
	// Si les paramètres sont invalides, le solide retourné est non initialisé
	// (le tester avec EstInitialise ())
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre
	Ellipsoides (	const Points3D & Origine , const Vecteurs3D U, const Vecteurs3D V, 
					const double R1, const double R2, const double R3, 
					const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;

public : //private :
	SolidesP CreerEllipsoide (	const Points3D & Origine , const Vecteurs3D U, const Vecteurs3D V, 
								const double R1, const double R2, const double R3, 
								const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	Points3D		origine ;
   Vecteurs3D	u,v ;
	double		r1,r2,r3 ;
} ;


class BREPP_DLL Tetraedres : public SolidesP
{
public :
	// Création d'une pyramide à base triangulaire. L'ordre des sommets
	// est sans importance.
	// Les points ne doivent pas être coplanaires. Ils le sont si
	// la distance de P4 au plan (P1,P2,P3) est inférieure à ModelesP::Defaut ()->PrecisionProximite ()
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre
	Tetraedres (	const Points3D & P1,
					const Points3D & P2,
					const Points3D & P3,
					const Points3D & P4, 
					const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;

public : //private :
	SolidesP CreerPyramide (	const Points3D & P1,
								const Points3D & P2,
								const Points3D & P3,
            					const Points3D & P4, 
								const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	Points3D		mP1, mP2, mP3, mP4 ;
} ;

class BREPP_DLL Pyramides : public SolidesP
{
public :
	// Création d'une pyramide à base quelconque (mais supposée plane).
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre
	Pyramides (	const Tableaux <Points3D> & Base,
   				const Points3D & Apex, 
				const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;

public : //private :
	SolidesP Pyramides::CreerPyramide (	Tableaux <Points3D> Base,
										const Points3D & Apex, 
										const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;
	// La base n'est pas en const parce que parfois modifiée

	Points3D					mApex ;
   Tableaux <Points3D>	mBase ;
} ;

class BREPP_DLL Etoiles6Branches : public SolidesP
{
public :
	// Création d'un prisme dont la base est une étoile à 6 branches
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre
	Etoiles6Branches (	double GrandRayon, double PetitRayon, double Hauteur, 
						const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;

public : //private :
	SolidesP	Etoiles6Branches::CreerEtoile6Branches (double GrandRayon, double PetitRayon, 
														double Hauteur, 
														const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	double	mGrandRayon, mPetitRayon, mHauteur ;
} ;


class BREPP_DLL SellesDeCheval : public SolidesP
{
public :
	SellesDeCheval (double Longueur, double Largeur, double H1, double HMilieu, double H2,
					const Points3D &P, 
					const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;
	// Création d'une selle de cheval à base rectangulaire.
	// Longueur (selon Ox) et Largeur (selon (Oy) sont les dimensions du rectangle.
	// P est le barycentre du rectangle.
	// H1 est l'altitude au dessus du milieu de la première largeur
	// HMilieu est l'altitude au barycentre du rectangle
	// H2 est l'altitude au dessus du milieu de la deuxième largeur
	// Et il faut que HMilieu < Min (H1,H2)
	// Les 2 points bas de la selle sont les milieux des deux longueurs du rectangle
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre

public : //private :
	SolidesP	CreerSelleDeCheval (double Longueur, double Largeur, double H1, double HMilieu, double H2,
									const Points3D &P, 
									const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	double	mLongueur, mLargeur, mH1, mHMilieu, mH2 ;
   Points3D	mP ;
} ;

class BREPP_DLL Dodecaedres : public SolidesP
{
public :
	Dodecaedres (	const Points3D& P, double R, 
					const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;
	// Création d'un dodécaèdre centré en P et de rayon R.
	// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
	// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
	// ceux qui sont fournis en paramètre

public : //private :
	SolidesP	CreerDodecaedre (	const Points3D& P, double Rayon, 
									const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	double	mR ;
   Points3D	mP ;
} ;


class BREPP_DLL SpikyDodecaedres : public SolidesP
{
public :
	SpikyDodecaedres (	const Points3D& P, double Rayon,
						double Alpha, double Taux, 
						const AttributsSolidesP *PAS = NULL, const AttributsFacesP *PAF = NULL) ;
// Création d'un dodécaèdre épineux centré en P et de rayon R.
// C'est un dodecagone dont chaque sommet est remplacé par une pyramide
// triangulaire formée par trois triangles isocèles identiques
// et dont les angles de base font Alpha degrés.
// Alpha est en DEGRES !!
// Il faut que Alpha > 72 ° et < 90 ° si on veut construire un vrai dodécaèdre
// épineux sans patrons.
// Un angle > 30° et <= 72 est toléré mais, dans ce cas, le polyèdre admet
// probablement des patrons.
// Si l'angle est <= 30° ou >= 90°, on restitue le solide d'erreur).
// Si l'angle est <= 54°, la pyramide est à l'intérieur du dodécaèdre original ;
// le volume du solide est donc inférieur au volume initial mais l'objet est
// convexe.
// Sur un sommet du dodécagone, la pyramide recouvre une proportion de chacune de
// ses arêtes. Cette proportion est définie par le Taux. Par exemple,
// si Taux = 0.4, 40 % de l'arête sont couverts (le taux doit être < 50 %
// sinon on restitue le solide d'erreur).
// *PAS et *PAF sont respectivement l'attribut éventuel pour le solide et l'attribut éventuel
// pour toutes les faces. Les attributs originaux sont copiés donc l'appelant peut libérer
// ceux qui sont fournis en paramètre

public : //private :
	SolidesP	CreerSpikyDodecaedre (	const Points3D& P, double Rayon,
										double Alpha, double Taux, 
										const AttributsSolidesP *PAS, const AttributsFacesP *PAF) ;

	double	mRayon, mAlpha, mTaux ;
   Points3D	mP ;
} ;


//
////SolidesP PieceEnL (const Points3D & Depart ,
////		   const double DeltaX     ,
////		   const double DeltaY     ,
////		   const double DeltaZ     ,
////		   const double EnX        ,
////		   const double EnY        ) ;
//// Création d'un volume en L par opération booléenne entre
//// deux boîtes.
//// Tous les delta correspondent au trois dimensions du
//// parallélépipède extérieur.
//// Tous les En correspondent au parallélépipède enlevant
//// de la matière.
//// Le point de départ correspond au coin supprimé de la
//// boîte extérieure.

#endif
