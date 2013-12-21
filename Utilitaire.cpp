#include "StdAfx.h"
#include "Utilitaire.h"


/*

CLASSE STATIC DE CALCUL D'INTERSECTION 2D

*/

const double Utilitaire::EpsDistance = 0.001 ;            // Distance sous laquelle deux points sont consid�r�s superpos�s

//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################

//*****************************************************************************
//									METHODES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Calcule l'�quation d'une droite passant par les points (x1,y1) et (x2,y2), 
//	suppos�s DIFFERENTS !!

void Utilitaire::EquationDroite (double x1, double y1, double x2, double y2, double *Pa, double *Pb, double *Pc) 
{
     *Pb = x1 - x2 ;
	 *Pa = y2 - y1 ; 
	 *Pc = -*Pa * x1 - *Pb * y1 ; 
}

	
//_____________________________________________________________________________
//
//	Distance du point (x,y) � la droite (P1,P2) 

double Utilitaire::DistancePointDroite (double x, double y, double x1, double y1, double x2, double y2)
{
     double    a,b,c ;

    EquationDroite (x1,y1,x2,y2,&a,&b,&c) ;

    double    norme = sqrt (a*a + b*b),
                dist = fabs (a*x + b*y + c) / norme ;

    return dist ;
}

//_____________________________________________________________________________
//
//	Intersections d'une droite quelconque et d'un cercle centr� � l'origine.
	// *PNbInt est le nombre d'intersections :
	//    -1 si donn�es incoh�rentes
	// 1 si tangence

void Utilitaire::IntersectionsDroiteCercleOrigine (double x1, double y1, double x2, double y2, double R,
													int* PNbInt, double* pxi1, double* pyi1, double* pxi2, double* pyi2)

{
/*Controle que:
  - les coordonn�es des points 1 et 2 ne sont pas confondus
  - le rayon est positif
*/
     if (((x1 == x2) && (y1 == y2)) || (R <= 0)) {
        *PNbInt = -1 ; return ;
    }

	//Calcul des coordonn�es du vecteur Point1 -> Point2
     double  dx = x2 - x1;
	 double  dy = y2 - y1;
	 
	//m�morisation de la longueur carr�e pour en faire la racine dans le but de normer le vecteur
     double  LongueurCarree = dx*dx + dy*dy;
	 
	 //Calcul de la distance entre l'origine du cercle, qui est x=0 et y=0, et la droite point1 --> point2
	 double  D = DistancePointDroite (0,0,x1,y1,x2,y2);
	 
	 //DeltaDist repr�sente la longueur entre la droite et le cercle du cot� oppos� au centre du cercle
	 /*
	  __________
 ____/__Delta___\______DeltaDist = distance entre cette droite et le point extreme haut du cercle
	|            |
	|     +      |
	|            |
	 \__________/
	 
	 */
     double  DeltaDist = R - D ;

	 //DeltaDist = 0 --> droite tangente au cercle. 1 point d'intersection
    if (fabs (DeltaDist) < EpsDistance) {    // Tangence
        *PNbInt = 1 ;

	//calcul du ratio que repr�sente le vecteur O ->Pt1 sur le vecteur Pt1->Pt2
	//Le signe n�gatif est n�cessaire puisque le point de tangence est dans le sens
	//contraire, pa rapport au Pt1 du vecteur O->Pt1
       double    Param = -(x1*dx + y1*dy) / LongueurCarree ;
	   //calcul des coordonn�es du point de tangence
       *pxi1 = x1 + Param*dx ;
       *pyi1 = y1 + Param*dy ;
    }
    else if (DeltaDist >= EpsDistance) {    // 2 intersections
        *PNbInt = 2 ;

       // METHODE 1
       double    K = -(x1*dx + y1*dy) / sqrt (LongueurCarree) ;
       double    L = sqrt (R*R - D*D) ;
       double    Param1 = (K-L) / sqrt (LongueurCarree),
                   Param2 = (K+L) / sqrt (LongueurCarree) ;
       *pxi1 = x1 + Param1*dx ;
       *pyi1 = y1 + Param1*dy ;
       *pxi2 = x1 + Param2*dx ;
       *pyi2 = y1 + Param2*dy ;
    }
    else
        *PNbInt = 0 ;
}

//_____________________________________________________________________________
//
//	Intersections d'une droite quelconque et d'un cercle // // *PNbInt est le nombre d'intersections :
		//    -1 si donn�es incoh�rentes
		// 1 si tangence
		// 0 ou 2 dans les autres cas.

void Utilitaire::IntersectionsDroiteCercle (double x1, double y1, double x2, double y2, double xc, double yc, double R, int* PNbInt, double* pxi1, double* pyi1, double* pxi2, double* pyi2)
{
     // Changement de rep�re
    x1 -= xc ; y1 -= yc ;
    x2 -= xc ; y2 -= yc ;

     IntersectionsDroiteCercleOrigine(x1,y1,x2,y2,R,PNbInt,pxi1,pyi1,pxi2,pyi2) ;

    if (*PNbInt > 0) {
        *pxi1 += xc ; *pyi1 += yc ;    // Changement de rep�re

       if (*PNbInt > 1)
            *pxi2 += xc ; *pyi2 += yc ;    // Changement de rep�re
    }
}



Utilitaire::Utilitaire(void)
{
}


Utilitaire::~Utilitaire(void)
{
}
