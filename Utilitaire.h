#pragma once

#include <math.h>

class Utilitaire
{
public:
	
//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################

//*****************************************************************************
//									METHODES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Calcule l'équation d'une droite passant par les points (x1,y1) et (x2,y2), 
//	supposés DIFFERENTS !!

	static void EquationDroite (double x1, double y1, double x2, double y2,
								double *Pa, double *Pb, double *Pc) ;
	
//_____________________________________________________________________________
//
//	Distance du point (x,y) à la droite (P1,P2) 

	static double DistancePointDroite (double x, double y, double x1,
										double y1, double x2, double y2);

//_____________________________________________________________________________
//
//	Intersections d'une droite quelconque et d'un cercle centré à l'origine.
	// *PNbInt est le nombre d'intersections :
	//    -1 si données incohérentes
	// 1 si tangence

	static void IntersectionsDroiteCercleOrigine (double x1, double y1, double x2,
													double y2, double R, int* PNbInt,
													double* pxi1, double* pyi1,
													double* pxi2, double* pyi2);

//_____________________________________________________________________________
//
//	Intersections d'une droite quelconque et d'un cercle // // *PNbInt est le nombre d'intersections :
		//    -1 si données incohérentes
		// 1 si tangence
		// 0 ou 2 dans les autres cas.

	static void IntersectionsDroiteCercle (double x1, double y1, double x2, double y2,
											double xc, double yc, double R, int* PNbInt,
											double* pxi1, double* pyi1, double* pxi2,
											double* pyi2);

//_____________________________________________________________________________
//
//	

	Utilitaire(void);
	~Utilitaire(void);

//#############################################################################
//								DOMAINE PRIVE
//#############################################################################
private:

//_____________________________________________________________________________
//
//	Constante Epsilon permettant de dire si 2 points sont égaux
	static const double EpsDistance;
	
};

