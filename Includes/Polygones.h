/******************************************************************
 * Classe Polygones		                                          *
 *                                                                *
 * auteur 				: Genco	/ Minich										*
 * date création 		: 24 / 11 / 04											*
 *																						*
 * Classe qui défini les polygones                                *
 * Un polygone est une ligne brisée bien fermée							*
 *                                                                *
 ******************************************************************/


//------------------------------------------------------------------------------
#ifndef __Polygones__H__
#define __Polygones__H__
//------------------------------------------------------------------------------

#include "BibliothequeMathematique.h"
#include "Tableaux.h"
#include "Listes.h"		// pour les résultats de l'intersection



class Polygones
{
   public:

//------------------------------------------------------------------------------
// Constructeurs et destructeurs.
//------------------------------------------------------------------------------

      // Constructeur par défaut.
      Polygones () ;

      // Construit un polygone à partir d'un tableau de points.
      Polygones ( const Tableaux <Points3D> & ) ;


//------------------------------------------------------------------------------
// Accesseurs.
//------------------------------------------------------------------------------

      // Accesseur pour la liste des points du polygone.
      const Tableaux <Points3D> & TableauSommets () const ;

		// Fonctions qui renvoie le nombre de points du polygone.
		int NombreSommets () const ;


//------------------------------------------------------------------------------
// Surcharge des opérateurs.
//------------------------------------------------------------------------------

      // Opérateur d'égalité.
      // L'égalité se contente de vérifier que les i-èmes points des 2
      // polygones sont superposés. Il n'y a pas de vérification de l'égalité
      // à un décalage près.
      friend bool operator== (const Polygones &, const Polygones &) ;

      // CONSULTATION du ième sommet. La numérotation commence à 0.
      // Si i est >= N ou < 0, on fait une permutation circulaire
      const Points3D & operator [] (int i) const ;

      // ACCES EN MODIFICATION au ième sommet. La numérotation commence à 0.
      // Echoue si i est > N ou < 0.
      // Si i = N, un point non initialisé est ajouté en fin du polygone
      // et est restitué.
      Points3D & operator [] (int i) ;


//------------------------------------------------------------------------------
// Méthodes.
//------------------------------------------------------------------------------

      // Suppression de tous les sommets du polygone
      void Vider () ;

      // Fonction qui indique si le point P appartient au polygone.
      // Algorithme basé sur la méthode des angles capables.
      // Si le point est strictement dans le polygone, le résultat est vrai mais
      // le booléen en E/S est faux.
      // Si le point est sur le polygone, le résultat est vrai mais
      // le booléen en E/S est vrai.
      // Si le point est strictemnt en dehors du polygone, le résultat est
      // faux et le booléen en E/S est inutilisé.
      bool EstDans ( const Points3D &, bool * Dessus )  const ;

		// Restitue une normale normée
		Vecteurs3D Normale () const ;

		// Restitue une normale normée et orientée selon le sens de rotation
      // du polygone.
      Vecteurs3D NormaleOrientee () const ;

		// Applique à tous les sommets du polygone la transformation décrite
      // par Mat.
      void Transformer (const Matrices4D &Mat) ;

      // Ajout d'un sommet en queue du polygone
      void AjouterSommet (const Points3D &) ;

      // Suppression du sommet d'indice i (les indices commencent à 0).
	  // Ne fait rien si ce sommet n'existe pas
      void SupprimerSommet (int i) ;

      // Calcul du centre de gravité. En cas d'échec (0 sommets), le résultat est faux.
	  // Fonctionne pour les polygones concaves
      bool CentreDeGravite (Points3D	*PG) ;

		// Calcul du centre de gravité et de l'aire. En cas d'échec (0 sommets), le résultat est
		// faux.
		// Fonctionne pour les polygones concaves
		bool CentreDeGraviteEtAire (Points3D	*PG, double *PA) ;

      // Intersection avec une droite. *Lpoints est la liste des points trouvés,
      // *LPositions donne, pour chaque point de Lpoints, sa position sur
      // le polygone : la position est un réel dont la partie entière donne
      // le numéro du segment (de 0 à N-1) et dont la partie décimale donne
      // la position sur ce segment (de 0 inclus à 1 exclu).
      // Par exemple, 2.333 signifie au premier tiers du troisième segment.
      //
      // FONCTION NON IMPLANTEE !!
      //
      void IntersectionAvecDroite (	const Droites3D &Dro,
      										Listes <Points3D>	*Lpoints,
                              	   Listes <double>	*Lpositions) const ;

      // Calcul et restitution de l'enveloppe convexe de *this.
      // Si après suppression des sommets superposés, *this a 3 sommets ou moins,
      // l'enveloppe convexe est égale à *this.
      // METHODE :
      /* L'idée est de chercher un point extrême dans une quelconque direction, définie par un vecteur V.
      *  Soit E ce point. Il appartient nécessairement à l'enveloppe convexe et on construit donc l'enveloppe en
      *  commençant en E.
      *  On cherche ensuite le point A du nuage tel que l'angle (V,EA) soit le plus petit (l'angle est dans le sens
      *  trigo et doit aller de V vers EA). Ce point est le deuxième point de l'enveloppe convexe.
      *  On déplace E en A, on ré-initialise V avec EA et on répète ce mécanisme jusqu'à revenir au point de départ.
      *  Quand deux ou plusieurs points forment le même écart angulaire avec V, on prend le plus éloigné.
      *  Si on ne le fait pas, l'algo marche quand même mais il y aura plusieurs segments consécutifs alignés
      *  dans l'EC calculée.
      */

	  void EnveloppeConvexe (Polygones *PP) const ;

      // Vérifie si *this et Pol ont un recouvrement.
      // Attention : une adjacence n'est pas considérée comme un recouvrement.
      // Il n'y a recouvrement que si l'aire de la zone partagée est > 0.
		// On suppose que les polygones ont chacun au moins 3 points non alignés
      //bool EstPartiellementRecouvert (const Polygones &Pol) const ;

		void InsererDesPoints (int pos, Polygones &Points, int deb, int fin) ;
      // Insère à partir de l'indice pos les points deb à fin du polygone Points
      // 0 <= pos < Nb_Effectifs ()

      // Restitution de l'englobant du polygone
		// On suppose que le polygone a au moins 3 points non alignés
      Englobants3D Englobant () const ;

      // Inversion du sens de parcours du polygone
		// Le premier point est inchangé
		void Inverser () ;

protected :
      // Le tableau contenant les sommets du polygone.
      Tableaux <Points3D>	tab_points ;

//------------------------------------------------------------------------------
// Partie privée.
//------------------------------------------------------------------------------

   private:

		// Filtre qui indique si le point P appartient au rectangle dont l'extremité
		// bas gauche (respectivement haut droite) est le point composé des
		// coordonnées minimales (respectivement maximales) de tous les points du
		// polygone.
      // Ce filtre est imparfait.
		// Si le point n'est pas dans l'englobant alors il n'est pas dans le
		// polygone. Par contre la réciproque n'est pas vérifiée. Le point peut
		// être dans l'englobant mais pas dans le polygone.
		bool Polygones::FiltreEnglobant ( const Points3D & P ) const ;

      Points3D ChercherPointExtreme (const Tableaux <Points3D> &P, const Vecteurs3D &V) const ;
      // Cherche le point du tableau le plus éloigné dans la direction donnée
      // par V

      void ChercherEtSupprimerProchainPoint (	Tableaux <Points3D> *TP,
							const Points3D &E,
							const Vecteurs3D &V,
                     Points3D *ProchainPoint) const ;
      // Cherche et supprime dans le tableau le point qui succède à E dans l'enveloppe
      // convexe

      double Polygones::CalculAngle (const Points3D &E, const Vecteurs3D &V, const Points3D &A) const ;
      // Calcule l'angle formé par V et [E,A].
      // L'angle est calculé en allant dans le sens trigo de V vers [E,A] et
      // est entre 0 et 2.Pi
      // ATTENTION : E est supposé différent de A !
};

//------------------------------------------------------------------------------
#endif
