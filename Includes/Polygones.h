/******************************************************************
 * Classe Polygones		                                          *
 *                                                                *
 * auteur 				: Genco	/ Minich										*
 * date cr�ation 		: 24 / 11 / 04											*
 *																						*
 * Classe qui d�fini les polygones                                *
 * Un polygone est une ligne bris�e bien ferm�e							*
 *                                                                *
 ******************************************************************/


//------------------------------------------------------------------------------
#ifndef __Polygones__H__
#define __Polygones__H__
//------------------------------------------------------------------------------

#include "BibliothequeMathematique.h"
#include "Tableaux.h"
#include "Listes.h"		// pour les r�sultats de l'intersection



class Polygones
{
   public:

//------------------------------------------------------------------------------
// Constructeurs et destructeurs.
//------------------------------------------------------------------------------

      // Constructeur par d�faut.
      Polygones () ;

      // Construit un polygone � partir d'un tableau de points.
      Polygones ( const Tableaux <Points3D> & ) ;


//------------------------------------------------------------------------------
// Accesseurs.
//------------------------------------------------------------------------------

      // Accesseur pour la liste des points du polygone.
      const Tableaux <Points3D> & TableauSommets () const ;

		// Fonctions qui renvoie le nombre de points du polygone.
		int NombreSommets () const ;


//------------------------------------------------------------------------------
// Surcharge des op�rateurs.
//------------------------------------------------------------------------------

      // Op�rateur d'�galit�.
      // L'�galit� se contente de v�rifier que les i-�mes points des 2
      // polygones sont superpos�s. Il n'y a pas de v�rification de l'�galit�
      // � un d�calage pr�s.
      friend bool operator== (const Polygones &, const Polygones &) ;

      // CONSULTATION du i�me sommet. La num�rotation commence � 0.
      // Si i est >= N ou < 0, on fait une permutation circulaire
      const Points3D & operator [] (int i) const ;

      // ACCES EN MODIFICATION au i�me sommet. La num�rotation commence � 0.
      // Echoue si i est > N ou < 0.
      // Si i = N, un point non initialis� est ajout� en fin du polygone
      // et est restitu�.
      Points3D & operator [] (int i) ;


//------------------------------------------------------------------------------
// M�thodes.
//------------------------------------------------------------------------------

      // Suppression de tous les sommets du polygone
      void Vider () ;

      // Fonction qui indique si le point P appartient au polygone.
      // Algorithme bas� sur la m�thode des angles capables.
      // Si le point est strictement dans le polygone, le r�sultat est vrai mais
      // le bool�en en E/S est faux.
      // Si le point est sur le polygone, le r�sultat est vrai mais
      // le bool�en en E/S est vrai.
      // Si le point est strictemnt en dehors du polygone, le r�sultat est
      // faux et le bool�en en E/S est inutilis�.
      bool EstDans ( const Points3D &, bool * Dessus )  const ;

		// Restitue une normale norm�e
		Vecteurs3D Normale () const ;

		// Restitue une normale norm�e et orient�e selon le sens de rotation
      // du polygone.
      Vecteurs3D NormaleOrientee () const ;

		// Applique � tous les sommets du polygone la transformation d�crite
      // par Mat.
      void Transformer (const Matrices4D &Mat) ;

      // Ajout d'un sommet en queue du polygone
      void AjouterSommet (const Points3D &) ;

      // Suppression du sommet d'indice i (les indices commencent � 0).
	  // Ne fait rien si ce sommet n'existe pas
      void SupprimerSommet (int i) ;

      // Calcul du centre de gravit�. En cas d'�chec (0 sommets), le r�sultat est faux.
	  // Fonctionne pour les polygones concaves
      bool CentreDeGravite (Points3D	*PG) ;

		// Calcul du centre de gravit� et de l'aire. En cas d'�chec (0 sommets), le r�sultat est
		// faux.
		// Fonctionne pour les polygones concaves
		bool CentreDeGraviteEtAire (Points3D	*PG, double *PA) ;

      // Intersection avec une droite. *Lpoints est la liste des points trouv�s,
      // *LPositions donne, pour chaque point de Lpoints, sa position sur
      // le polygone : la position est un r�el dont la partie enti�re donne
      // le num�ro du segment (de 0 � N-1) et dont la partie d�cimale donne
      // la position sur ce segment (de 0 inclus � 1 exclu).
      // Par exemple, 2.333 signifie au premier tiers du troisi�me segment.
      //
      // FONCTION NON IMPLANTEE !!
      //
      void IntersectionAvecDroite (	const Droites3D &Dro,
      										Listes <Points3D>	*Lpoints,
                              	   Listes <double>	*Lpositions) const ;

      // Calcul et restitution de l'enveloppe convexe de *this.
      // Si apr�s suppression des sommets superpos�s, *this a 3 sommets ou moins,
      // l'enveloppe convexe est �gale � *this.
      // METHODE :
      /* L'id�e est de chercher un point extr�me dans une quelconque direction, d�finie par un vecteur V.
      *  Soit E ce point. Il appartient n�cessairement � l'enveloppe convexe et on construit donc l'enveloppe en
      *  commen�ant en E.
      *  On cherche ensuite le point A du nuage tel que l'angle (V,EA) soit le plus petit (l'angle est dans le sens
      *  trigo et doit aller de V vers EA). Ce point est le deuxi�me point de l'enveloppe convexe.
      *  On d�place E en A, on r�-initialise V avec EA et on r�p�te ce m�canisme jusqu'� revenir au point de d�part.
      *  Quand deux ou plusieurs points forment le m�me �cart angulaire avec V, on prend le plus �loign�.
      *  Si on ne le fait pas, l'algo marche quand m�me mais il y aura plusieurs segments cons�cutifs align�s
      *  dans l'EC calcul�e.
      */

	  void EnveloppeConvexe (Polygones *PP) const ;

      // V�rifie si *this et Pol ont un recouvrement.
      // Attention : une adjacence n'est pas consid�r�e comme un recouvrement.
      // Il n'y a recouvrement que si l'aire de la zone partag�e est > 0.
		// On suppose que les polygones ont chacun au moins 3 points non align�s
      //bool EstPartiellementRecouvert (const Polygones &Pol) const ;

		void InsererDesPoints (int pos, Polygones &Points, int deb, int fin) ;
      // Ins�re � partir de l'indice pos les points deb � fin du polygone Points
      // 0 <= pos < Nb_Effectifs ()

      // Restitution de l'englobant du polygone
		// On suppose que le polygone a au moins 3 points non align�s
      Englobants3D Englobant () const ;

      // Inversion du sens de parcours du polygone
		// Le premier point est inchang�
		void Inverser () ;

protected :
      // Le tableau contenant les sommets du polygone.
      Tableaux <Points3D>	tab_points ;

//------------------------------------------------------------------------------
// Partie priv�e.
//------------------------------------------------------------------------------

   private:

		// Filtre qui indique si le point P appartient au rectangle dont l'extremit�
		// bas gauche (respectivement haut droite) est le point compos� des
		// coordonn�es minimales (respectivement maximales) de tous les points du
		// polygone.
      // Ce filtre est imparfait.
		// Si le point n'est pas dans l'englobant alors il n'est pas dans le
		// polygone. Par contre la r�ciproque n'est pas v�rifi�e. Le point peut
		// �tre dans l'englobant mais pas dans le polygone.
		bool Polygones::FiltreEnglobant ( const Points3D & P ) const ;

      Points3D ChercherPointExtreme (const Tableaux <Points3D> &P, const Vecteurs3D &V) const ;
      // Cherche le point du tableau le plus �loign� dans la direction donn�e
      // par V

      void ChercherEtSupprimerProchainPoint (	Tableaux <Points3D> *TP,
							const Points3D &E,
							const Vecteurs3D &V,
                     Points3D *ProchainPoint) const ;
      // Cherche et supprime dans le tableau le point qui succ�de � E dans l'enveloppe
      // convexe

      double Polygones::CalculAngle (const Points3D &E, const Vecteurs3D &V, const Points3D &A) const ;
      // Calcule l'angle form� par V et [E,A].
      // L'angle est calcul� en allant dans le sens trigo de V vers [E,A] et
      // est entre 0 et 2.Pi
      // ATTENTION : E est suppos� diff�rent de A !
};

//------------------------------------------------------------------------------
#endif
