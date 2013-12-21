#ifndef TriangulationEtSTL_H
#define TriangulationEtSTL_H

#include "BibliothequeBRepP.h"
#include "EnteteSTLDLL.h"
// #include <stdio.h>



/////////////////////////////*  DEBUT DECLARE.H  *//////////////////////////////


typedef FILE *Fichier;
#define VIDE                     0x0000

//////////////////////////////*  FIN DECLARE.H  *///////////////////////////////



/////////////////////////////*  DEBUT DECIMAL.H  *//////////////////////////////

#define Decimal                                   double
#define DecimauxEgaux(d1,d2,epsilon)             (fabs((d1)-(d2)) < epsilon)
#define DecimalNul(d,epsilon)                    (fabs(d) < epsilon)
#define DecimalMinimum(d1,d2)                    (d1 < d2 ? d1 : d2)
#define DecimalMaximum(d1,d2)                    (d1 > d2 ? d1 : d2)
#define DecimalComprisEntre(d,d1,d2)             DecimalMinimum(borne1,borne2) <= val) && (val <= DecimalMaximum(borne1,borne2)
#define DecimalChaine(d,ndec,chaine)              gcvt(d,ndec,chaine);

//////////////////////////////*  FIN DECIMAL.H  *///////////////////////////////



////////////////////////////*  DEBUT LISTES_G.H  *//////////////////////////////


template <class T> class ElementListe
{ T element;
  ElementListe<T> *suivant;

  public:
  // Accesseurs
  inline const T &Element (void) const { return element; };
  inline ElementListe<T> * const &Suivant (void) const { return suivant; };
  // Modificateurs
  inline T &Element (void) { return element; };
  inline ElementListe<T> * &Suivant (void) { return suivant; };
  // Constructeurs
  // Constructeur par defaut
  ElementListe (void) {};
  // Constructeur complet
  ElementListe (const T &elem, ElementListe<T> * const &suiv) : element(elem), suivant(suiv) {};

}; // template <class T> class ElementListe


////////////////////////////////////////////////////////////////////////////////


template <class T> class Liste
{ ElementListe<T> *debut;

  public:
  // Debut de la liste
  // Accesseurs
  inline ElementListe<T> * const &Debut (void) const { return debut; };
  ElementListe<T> * const &Fin   (void) const;
  ElementListe<T> * const &Ieme  (const unsigned int &) const;
  // Modificateurs
  ElementListe<T> * &Debut (void) { return debut; };
  ElementListe<T> * &Fin   (void);
  ElementListe<T> * &Ieme (const unsigned int &);
  // Constructeurs
  // Constructeur a vide
  Liste (void) : debut(NULL) {};
  // Constructeur de copie
  Liste (const Liste<T> &list) : debut(NULL) { *this=list; };
  // Test a vide
  bool EstVide (void) const;
  // Destructeur
 ~Liste (void);
  // Operateurs
  // Affectation
  Liste<T> &operator = (const Liste<T> &);
  // Ajout d'un element
  void Ajouter (const T &);
  // Retrait d'un element
  void Retirer (void);
  // Vider la liste
  void Vider (void);
  // Nombre d'elements de la liste
  unsigned int Taille (void) const;

}; // template <class T> class Liste


// Affichage console
template <class T> ostream &operator << (ostream &os, const Liste<T> &list)
{ ElementListe<T> *aux=list.Debut();
  while (aux != NULL)
  { os << aux->Element() << endl;
    aux=aux->Suivant();
  } return os;
} // template <class T> operator <<


////////////////////////////////////////////////////////////////////////////////


// Accesseurs

// Fin de la liste
template <class T> ElementListe<T> * const &Liste<T>::Fin (void) const
{ ElementListe<T> * const *result=&debut;
  while (*result != NULL)
  result=&((*result)->Suivant());
  return *result;
} // template <class T> Liste<T>::Fin


// Ieme element
template <class T> ElementListe<T> * const &Liste<T>::Ieme (const unsigned int &i) const
{ ElementListe<T> * const *result=&debut;
  if (i < Taille())
  { int aux=i;
    while ((*result != NULL) && (aux > 0))
    { result=&((*result)->Suivant());
      aux--;
    }
  }
/*  else
  Erreur("Liste<T>::Ieme : Indice invalide");
  return *result;
*/
} // template <class T> Liste<T>::Ieme


// Modificateurs

// Fin de la liste
template <class T> ElementListe<T> * &Liste<T>::Fin (void)
{ ElementListe<T> **result=&debut;
  while (*result != NULL)
  result=&((*result)->Suivant());
  return *result;
} // template <class T> Liste<T>::Fin


// Ieme element
template <class T> ElementListe<T> * &Liste<T>::Ieme (const unsigned int &i)
{ ElementListe<T> **result=&debut;
  if (i < Taille())
  { int aux=i;
    while ((*result != NULL) && (aux > 0))
    { result=&((*result)->Suivant());
      aux--;
    }
  }
/*
  else
	Erreur("Liste<T>::Ieme : Indice invalide");
*/
  return *result;
} // template <class T> Liste<T>::Ieme


// Test a vide
template <class T> inline bool Liste<T>::EstVide (void) const
{ return (debut == NULL);
} // template <class T> Liste<T>::EstVide


// Destructeur
template <class T> Liste<T>::~Liste (void)
{ Vider();
} // template <class T> Liste<T>::~Liste


// Operateurs
// Affectation
template <class T> Liste<T> &Liste<T>::operator = (const Liste<T> &list)
{ Vider();
  ElementListe<T> *src=list.debut;
  ElementListe<T> **dest=&debut;
  while (src != NULL)
  { *dest=new ElementListe<T>(src->Element(),NULL);
    dest=&((*dest)->Suivant());
    src=src->Suivant();
  }
  return *this;
} // template <class T> Liste<T>::operator =


// Ajout d'un element EN TETE
template <class T> void Liste<T>::Ajouter (const T &element_G)
{ ElementListe<T> *save=debut;
  debut=new ElementListe<T>;
  if (debut != NULL)
  { debut->Element()=element_G;
    debut->Suivant()=save;
  }
/*
  else
  Erreur("Liste<T>::Ajouter : Memoire insuffisante");
*/
} // template <class T> Liste<T>::Ajouter


// Retrait d'un element
template <class T> void Liste<T>::Retirer (void)
{ if (!EstVide())
  { ElementListe<T> *save=debut;
    debut=debut->Suivant(); delete save;
  }
/*
  else
  Erreur("Tentative de retrait d'un element d'une liste NULL!");
*/
} // template <class T> Liste<T>::Retirer


// Vider la liste
template <class T> void Liste<T>::Vider (void)
{ while (!EstVide()) Retirer();
} // template <class T> Liste<T>::Vider


// Nombre d'elements de la liste
template <class T> unsigned int Liste<T>::Taille (void) const
{ unsigned int result=0; ElementListe<T> *aux=debut;
  while (aux != NULL)
  { aux=aux->Suivant();
    result++;
  } return result;
} // template <class T> Liste<T>::Taille


//////////////////////////////*  FIN LISTES_G.H  *//////////////////////////////




////////////////////////////* DEBUT VECTEUR2D.H *///////////////////////////////

class Vecteur2D
{ Decimal comp[2];

  public:
  // ACCESSEURS
  inline const Decimal &operator [] (const unsigned int &) const;
  // MODIFICATEURS
  inline Decimal &operator [] (const unsigned int &);
  // CONSTRUCTEURS
  // Par defaut
  Vecteur2D (void);
  // Complet
  Vecteur2D (const Decimal &, const Decimal &);
  // De copie
  Vecteur2D (const Vecteur2D &);
  // DESTRUCTEUR
 ~Vecteur2D (void) {};
  // OPERATIONS
  // Affectation
  Vecteur2D &operator = (const Vecteur2D &);
  // Opposee (moins unaire)
  Vecteur2D  operator - (void) const;
  // Multiplication vecteur scalaire
  Vecteur2D  operator * (const Decimal   &) const;
  // Division par un scalaire
  Vecteur2D  operator / (const Decimal   &) const;
  // Somme vecteur vecteur
  Vecteur2D  operator + (const Vecteur2D &) const;
  // Difference vecteur vecteur
  Vecteur2D  operator - (const Vecteur2D &) const;
  // Produit scalaire)
  Decimal    operator * (const Vecteur2D &) const;
  // Produit vectoriel
  Decimal    operator ^ (const Vecteur2D &) const;
  // FONCTIONS DIVERSES
  // Norme Euclidienne
  Decimal Norme (void) const;
  // Normer le vecteur
  inline const Vecteur2D &Normer (void);
  // Donne un vecteur normal
  inline Vecteur2D Normal (void) const;
  // Test de nullite
  bool Nul (const Decimal &) const;

}; // Vecteur2D


// Multiplication a gauche par un scalaire
extern Vecteur2D operator * (const Decimal &, const Vecteur2D &);

// Affichage console
//extern ConsoleFrame &operator << (ConsoleFrame &, const Vecteur2D &);
extern ostream & operator << (ostream &, const Vecteur2D &);

// Saisie console
extern istream & operator >> (istream &, Vecteur2D &);

// Sauvegarder sur disque
inline Fichier& operator << (Fichier& file, const Vecteur2D &v)
{ fprintf(file,"%lf\t%lf",v[0],v[1]);
  return file;
} // operator <<


////////////////////////////////////////////////////////////////////////////////


class Matrice2x2
{ Decimal comp[2][2];

  public:
  // ACCESSEURS
  inline Vecteur2D Ligne   (const unsigned int &) const;
  inline Vecteur2D Colonne (const unsigned int &) const;
  // MODIFICATEURS
  inline void ModifLigne   (const unsigned int &, const Vecteur2D &);
  inline void ModifColonne (const unsigned int &, const Vecteur2D &);
  // CONSTRUCTEURS
  // Par defaut
  Matrice2x2 (void);
  // A l'aide de 2 vecteurs colonnes
  Matrice2x2 (const Vecteur2D &, const Vecteur2D &);
  // De copie
  Matrice2x2 (const Matrice2x2 &m) { *this=m; };
  // DESTRUCTEUR
 ~Matrice2x2 (void) {};
  // OPERATEURS
  // Affectation
  Matrice2x2 &operator = (const Matrice2x2 &);
  // Moins unaire ou opposee
  Matrice2x2  operator - (void)               const;
  // Multiplication a droite par un scalaire
  Matrice2x2  operator * (const Decimal    &) const;
  // Division par un scalaire
  Matrice2x2  operator / (const Decimal    &) const;
  // Somme matricielle
  Matrice2x2  operator + (const Matrice2x2 &) const;
  // Moins binaire ou difference matricielle
  Matrice2x2  operator - (const Matrice2x2 &) const;
  // Multiplication matricielle
  Matrice2x2  operator * (const Matrice2x2 &) const;
  // Multiplication a droite par un vecteur
  Vecteur2D   operator * (const Vecteur2D  &) const;
  // DIVERS OU AUTRE
  // Determinant
  inline Decimal Determinant (void) const;
  // Trace
  inline Decimal Trace (void) const;
  // Antitrace
  inline Decimal AntiTrace (void) const;
  // Transposee
  Matrice2x2 Transposee (void) const;
  // Inverser
  bool Inverser (void);

}; // Matrice2x2


// Multiplication a gauche par un scalaire
extern Matrice2x2 operator * (const Decimal &, const Matrice2x2 &);

// Affichage console
extern ostream &operator << (ostream &, const Matrice2x2 &);


/////////////////////////////*  FIN VECTEUR2D.H  *//////////////////////////////



////////////////////////////* DEBUT VECTEUR3D.H *///////////////////////////////

class STL_DLL Vecteur3D
{ Decimal comp[3];

  public:
  // ACCESSEURS
  inline const Decimal &operator [] (const unsigned int &) const;
  // MODIFICATEURS
  inline Decimal &operator [] (const unsigned int &);
  // CONSTRUCTEURS
  // Par defaut
  Vecteur3D (void);
  // Complet
  Vecteur3D (const Decimal &, const Decimal &, const Decimal &);
  // De copie
  Vecteur3D (const Vecteur3D &);
  // DESTRUCTEUR
 ~Vecteur3D (void) {};
  // OPERATIONS
  // Affectation
  Vecteur3D &operator = (const Vecteur3D &);
  // Opposee (moins unaire)
  Vecteur3D  operator - (void) const;
  // Multiplication vecteur scalaire
  Vecteur3D  operator * (const Decimal   &) const;
  // Division par un scalaire
  Vecteur3D  operator / (const Decimal   &) const;
  // Somme vecteur vecteur
  Vecteur3D  operator + (const Vecteur3D &) const;
  // Difference vecteur vecteur
  Vecteur3D  operator - (const Vecteur3D &) const;
  // Produit vectoriel
  Vecteur3D  operator ^ (const Vecteur3D &) const;
  // Produit scalaire)
  Decimal    operator * (const Vecteur3D &) const;
  // FONCTIONS DIVERSES
  // Norme Euclidienne
  Decimal Norme (void) const;
    // Normer le vecteur
  const Vecteur3D &Normer (void);
  // Test de nullite
  bool Nul (const Decimal &) const;

}; // Vecteur3D


// Multiplication a gauche par un scalaire
extern Vecteur3D STL_DLL operator * (const Decimal &, const Vecteur3D &);

// Affichage console
extern ostream & STL_DLL operator << (ostream &, const Vecteur3D &);

// Saisie console
extern istream & STL_DLL operator >> (istream &, Vecteur3D &);

// Sauvegarder sur disque
inline Fichier & STL_DLL operator << (Fichier &file, const Vecteur3D &v)
{ fprintf(file,"%lf\t%lf\t%lf",v[0],v[1],v[2]);
  return file;
} // operator <<


////////////////////////////////////////////////////////////////////////////////


class Matrice3x3
{ Decimal comp[3][3];

  public:
  // ACCESSEURS
  inline Vecteur3D Ligne   (const unsigned int &) const;
  inline Vecteur3D Colonne (const unsigned int &) const;
  // MODIFICATEURS
  void ModifLigne   (const unsigned int &, const Vecteur3D &);
  void ModifColonne (const unsigned int &, const Vecteur3D &);
  // CONSTRUCTEURS
  // Par defaut
  Matrice3x3 (void);
  // A l'aide de 3 vecteurs colonnes
  Matrice3x3 (const Vecteur3D &, const Vecteur3D &, const Vecteur3D &);
  // De copie
  Matrice3x3 (const Matrice3x3 &m) { *this=m; };
  // DESTRUCTEUR
 ~Matrice3x3 (void) {};
  // OPERATEURS
  // Affectation
  Matrice3x3 &operator = (const Matrice3x3 &);
  // Moins unaire
  Matrice3x3  operator - (void) const;
  // Multiplication a droite par un scalaire
  Matrice3x3  operator * (const Decimal    &) const;
  // Division par un scalaire
  Matrice3x3  operator / (const Decimal    &) const;
  // Somme matricielle
  Matrice3x3  operator + (const Matrice3x3 &) const;
  // Moins binaire ou difference matricielle
  Matrice3x3  operator - (const Matrice3x3 &) const;
  // Multiplication par une matrice
  Matrice3x3  operator * (const Matrice3x3 &) const;
  // Multiplication a droite par un vecteur
  Vecteur3D   operator * (const Vecteur3D  &) const;
  // DIVERS OU AUTRE
  // Determinant
  Decimal Determinant (void) const;
  // Trace
  inline Decimal Trace (void) const;
  // Antitrace
  inline Decimal AntiTrace (void) const;
  // Transposee
  Matrice3x3 Transposee (void) const;
  // Inverser
  bool Inverser (void);

}; // Matrice3x3


// Multiplication a gauche par un scalaire
extern Matrice3x3 operator * (const Decimal &, const Matrice3x3 &);

// Affichage console
extern ostream &operator << (ostream &, const Matrice3x3 &);


/////////////////////////////* FIN VECTEUR3D.H *////////////////////////////////



///////////////////////////////*  DEBUT GEO.H  *////////////////////////////////

extern void EquationDroite2D        (const Vecteur2D &, const Vecteur2D &, Vecteur3D &);
extern bool InterEntreDroites       (const Vecteur3D &, const Vecteur3D &, Vecteur2D &);
extern bool BiPointDansMemeDemiPlan (const Vecteur3D &, const Vecteur2D &, const Vecteur2D &);
extern bool IntersectionExiste      (const Vecteur2D &, const Vecteur2D &, const Vecteur2D &, const Vecteur2D &);
extern bool InterEntreSegments      (const Vecteur2D &, const Vecteur2D &, const Vecteur2D &, const Vecteur2D &, Vecteur2D &);
extern Decimal AngleEn3Points       (const Vecteur2D &, const Vecteur2D &, const Vecteur2D &);
extern bool PointEstSurSegment      (const Vecteur2D &, const Vecteur2D &, const Vecteur2D &); 

////////////////////////////////*  FIN GEO.H  */////////////////////////////////


///////////////////////////////*  DEBUT STL.H  *////////////////////////////////

/******************************************************************************/
/* class STLSommet
/* Description: Pour les besoins de l'algorythme de triangulation on définit
/*              une class STLSommet composée d'un point 3D ainsi que de son
/*              image 2D dans le plan de la facette
/*
/*
/******************************************************************************/


class STLSommet
{ Vecteur3D pt3D;
  Vecteur2D pt2D;
  bool unique;
  public:
  // Accesseurs
  inline const Vecteur3D &Point3D (void) const { return pt3D;   };
  inline const Vecteur2D &Point2D (void) const { return pt2D;   };
  inline const bool      &Unique  (void) const { return unique; };
  // Modificateurs
  inline Vecteur3D &Point3D (void) { return pt3D;   };
  inline Vecteur2D &Point2D (void) { return pt2D;   };
  inline bool      &Unique  (void) { return unique; };
  // Constructeurs
  // Defaut
  STLSommet (void) {};
  // Complet
  STLSommet (const Vecteur3D &v3D, const Vecteur2D &v2D, bool uni) : pt3D(v3D), pt2D(v2D), unique(uni) {};
  // A partir de la partie 3D
  STLSommet (const Vecteur3D &v3D) : pt3D(v3D), pt2D(Vecteur2D()), unique(true) {};
  // De copie
  STLSommet (const STLSommet &sommet) { *this=sommet; };
  // Destructeur
 ~STLSommet (void) {};
  // Operateurs

}; // class STLSommet


// Affichage console
extern ostream &operator << (ostream &, const STLSommet &);

// Sauvegarder sur disque
extern Fichier &operator << (Fichier &, const STLSommet &);


////////////////////////////////////////////////////////////////////////////////


class ELCDS
{ STLSommet som;
  ELCDS *suiv;
  public:
  // Accesseurs
  inline const STLSommet &Sommet  (void) const { return som;  };
  inline ELCDS * const   &Suivant (void) const { return suiv; };
  // Modificateurs
  inline STLSommet &Sommet  (void) { return som;  };
  inline ELCDS *   &Suivant (void) { return suiv; };
  // Constructeurs
  // Defaut
  // Complet
  ELCDS (const STLSommet &sommet, ELCDS * const &suivant) : som(sommet), suiv(suivant) {};
  // Destructeur
 ~ELCDS (void) {};
  // Operateurs

}; // class ELCDS (ElementListeCirculaireDeSommets)


////////////////////////////////////////////////////////////////////////////////


class STL_DLL STLContour
{ ELCDS *debut;

  public:
  // Accesseurs
  inline ELCDS * const &Debut (void) const { return debut; };
  // Accesseurs evolues
  // Dernier pointeur de la liste circulaire (donc meme valeur que debut)
  ELCDS * const &Fin  (void) const;
  // Donne le pointeur sur le ieme sommet du contour
  ELCDS * const &Ieme (const unsigned int &i) const;
  // Modificateurs
  inline ELCDS * &Debut (void) { return debut; };
  // Modificateurs evolues
  // Dernier pointeur de la liste circulaire (donc meme valeur que debut)
  ELCDS * &Fin  (void);
  // Donne le pointeur sur le ieme sommet du contour
  ELCDS * &Ieme (const unsigned int &i);
  // Test si vide
  inline bool EstVide (void) const { return (debut == NULL); };
  // Nombre de sommets
  unsigned int Taille (void) const;
  // Calcul le sens reel du contour
  bool SensReel (void) const;
  // Constructeurs
  // Defaut (A vide)
  STLContour (void) { debut=NULL; };
  // De copie
  STLContour (const STLContour &contour) : debut(NULL) { *this=contour; };
  // Chargement du disque
  STLContour (const Fichier &);
  // Mise a jour de la partie 2D du contour
  void MiseAJourPartie2D (const Matrice3x3 &, const Vecteur3D &);
  // Destructeur
 ~STLContour (void);
  // Operateurs
  STLContour &operator = (const STLContour &);
  // Ajout d'un sommet
  void Ajouter (const STLSommet &);
  // Retrait d'un sommet
  void Retirer (void);
  // Vider le contour
  void Vider (void);
  // Inverser le sens du contour
  void Inverser (void);
  // Extrait les 3 1ers points 2D du contour
  void PremierTriangle2D (Vecteur2D &, Vecteur2D &, Vecteur2D &) const;
  // Test si un point est a l'interieur du contour
  bool PointEstInterieur (const Vecteur2D &, bool &) const;
  // Test d'intersection avec un segment
  bool EstCoupeParSegment (const Vecteur2D &, const Vecteur2D &) const;
  // Test si au moins un point du contour est situe sur le segment
  bool SegmentPasseParPoint (const Vecteur2D &, const Vecteur2D &) const;
  // Test si un sommet du contour est interieur au triangle
  bool UnSommetEstInterieurAuTriangle (const Vecteur2D &, const Vecteur2D &, const Vecteur2D &) const;

}; // class STLContour


// Affichage console
extern ostream & STL_DLL operator << (ostream &, const STLContour &);

// Affichage console une liste de contours
extern ostream & STL_DLL operator << (ostream &, const Liste<STLContour> &);

// Sauvegarder sur disque
extern Fichier & STL_DLL operator << (Fichier &, const STLContour &);

// Sauvegarder sur disque une liste de contours
extern Fichier & STL_DLL operator << (Fichier &, const Liste<STLContour> &);


////////////////////////////////////////////////////////////////////////////////


class STL_DLL STLTriangle
{ Vecteur3D s1, s2, s3; // Les 3 sommets d'un triangle decrit dans l'espace 3D
  public:
  // Accesseurs
  inline const Vecteur3D &Sommet1 (void) const { return s1; };
  inline const Vecteur3D &Sommet2 (void) const { return s2; };
  inline const Vecteur3D &Sommet3 (void) const { return s3; };
  // Modificateurs
  inline Vecteur3D &Sommet1 (void) { return s1; };
  inline Vecteur3D &Sommet2 (void) { return s2; };
  inline Vecteur3D &Sommet3 (void) { return s3; };
  // Constructeurs
  // Defaut
  STLTriangle (void) {};
  // Complet
  STLTriangle (const Vecteur3D &v1, const Vecteur3D &v2, const Vecteur3D &v3) : s1(v1), s2(v2), s3(v3) {};
  // De copie
  STLTriangle (const STLTriangle &triangle) { *this=triangle; };
  // Destructeur
 ~STLTriangle (void) {};
  // Test si degenere
  bool EstDegenere (void) const;

  friend bool STL_DLL operator == (const STLTriangle &T1, const STLTriangle &T2) ;
}; // STLTriangle3D


// Affichage console
extern ostream &operator << (ostream &, const STLTriangle &);

// Sauvegarder sur disque
extern Fichier &operator << (Fichier &, const Liste<STLTriangle> &);

// Affichage console
extern ostream &operator << (ostream &, const Liste<STLTriangle> &);


// Sauvegarder sur disque
extern Fichier & STL_DLL operator << (Fichier &, const Liste< Liste<STLTriangle> > &);


// Charger du disque
extern Fichier STL_DLL operator >> (Fichier, STLTriangle &);

// Charger du disque
extern Fichier STL_DLL operator >> (Fichier, Liste<STLTriangle> &);

// Charger du disque
extern Fichier STL_DLL operator >> (Fichier, Liste< Liste<STLTriangle> > &);


////////////////////////////////////////////////////////////////////////////////


class STL_DLL STLFace
{ STLContour ex;
  Liste<STLContour> in;
  bool sens;


  public:
  // Constructeurs
  // à partir d'une FacesP (face du Brep)
  STLFace (const FacesP &F) ;
  // Defaut
  STLFace (void) {}
  // Complet
  STLFace (const STLContour &contour) : ex(contour) {}
  // De copie
  STLFace (const STLFace &face) { *this=face; }
  // Chargement du disque
  STLFace (const Fichier &);

  // Accesseurs
  inline const STLContour        &Exterieur (void) const { return ex;   }
  inline const Liste<STLContour> &Interieur (void) const { return in;   }
  inline const bool              &Sens      (void) const { return sens; }
  // Modificateurs
  inline STLContour              &Exterieur (void) { return ex;   }
  inline Liste<STLContour>       &Interieur (void) { return in;   }
  inline bool                    &Sens      (void) { return sens; }

  // Repere local
  bool RepereLocal (const Vecteur3D &, Matrice3x3 &, Vecteur3D &);
  // Mise a jour de la partie 2D d'une STLFace
  void MiseAJourPartie2D (const Vecteur3D &);
  // Destructeur
 ~STLFace (void) {};
  // Orienter la face
  void Orienter (const bool &);
  // Algorithme de triangulation
  // Test si une face possede au moins 1 contour interieur
  inline bool EstPleine (void) const { return in.EstVide(); };
  // Renvoie un STLTriangle forme des 3 1ers points 3D du contour exterieur
  STLTriangle PremierTriangle3D (void) const;
  // Test si la face est un triangle plein
  bool EstUneFaceTriangle (void) const { return (EstPleine() && ex.Taille() < 4); };
  // Test si le premier triangle est plein
  bool PremierTriangleEstPlein (void) const;
  // Test si le premier triangle est valide
  bool PremierTriangleEstValide (void) const;
  // Intersection avec un segment
  bool EstCoupeParSegment (const Vecteur2D &, const Vecteur2D &) const;
  // Test si au moins un point de la face est situe sur le segment
  bool SegmentPasseParPoint (const Vecteur2D &, const Vecteur2D &) const;
  // Retourne les infos sur une fusion possible
  // entre le contour exterieur et un des contour interieur
  bool InfosFusionValide (unsigned int &, unsigned int &, unsigned int &) const;
  // Fusionner un des contours interieurs au contour exterieur
  bool Fusionner (void);
  // Triangulation
  bool Triangulation (Liste<STLTriangle> &) const;

}; // class STLFace


// Affichage console
extern ostream & STL_DLL operator << (ostream &, const STLFace &);

// Sauvegarder sur disque
extern Fichier & STL_DLL operator << (Fichier &, const STLFace &);

// Triangulation d'une liste de STLFace
extern void STL_DLL Triangulation (const Liste<STLFace> &, Liste<STLTriangle>&);


////////////////////////////////*  FIN STL.H  */////////////////////////////////




///////////////////////////*  DEBUT BREP-STL-LINK.H  *//////////////////////////

// Sauvegarde au format STL une liste de solides polyedrique
extern void SaveSTLFormat (const char *, Listes<SolidesP> &);

// Charge un ensemble de solides polyedriques a partir d'un fichier au format
// STL.
//	Les solides chargés sont AJOUTES à LSol.
// ATTENTION : un seul solide par fichier dans la version actuelle
// Le booléen dit si le fichier STL est au format texte ou binaire.
// ATTENTION : le mode binaire n'est pas implanté !!!
// Si deux triangles partagent une même arête dans le fichier, celle ci n'est
// créée qu'une seule fois. On fait de même avec les sommets partagés
extern void LoadSTLFormat (const char *NomFichierSTL, bool ModeTexte, Listes<SolidesP> &LSol) ;


// Triangulation d'un SolidesP à l'aide d'un ensemble de TRIANGLES STL
// Les triangles sont indépendants les uns des autres. Chaque sommet
// de la triangulation est donc défini de nombreuses fois. Il n'y a pas
// de notion d'arête.
// Les triangles sont orientés avec la même convention que les faces du solide.
// Les triangles calculés sont AJOUTES à LTriangles
extern void TriangulationSolideParTriangles (SolidesP &solid, Listes <STLTriangle> &LTriangles) ;

// Maillage d'un SolidesP à l'aide d'un ensemble de polygones CONVEXES.
// Les polygones sont indépendants les uns des autres. Chaque sommet
// du maillage est donc défini de nombreuses fois. Il n'y a pas
// de notion d'arête.
// Les mailles sont orientées avec la même convention que les faces du solide.
// Méthode : les faces du solide original qui sont convexes ne sont pas triangulées,
// les autres le sont.
// Les mailles calculées sont AJOUTES à LPolyg
extern void MaillageSolideParPolygonesConvexes (SolidesP &solid,Listes <Listes <Points3D> > &LPolyg) ;


// Triangulation d'un SolidesP à l'aide d'un ensemble de FacesP triangulaires
// Le solide résultant ne partage rien avec l'original.
// Il est un vrai objet BRep, dans lequel les arêtes ne sont pas dupliquées.
extern SolidesP TriangulationSolideParFacesTriangulaires (SolidesP &);


// Maillage d'un SolidesP à l'aide d'un ensemble de FacesP CONVEXES,
// pas forcément triangulaires
// Le solide résultant ne partage rien avec l'original.
// Il est un vrai objet BRep, dans lequel les arêtes ne sont pas dupliquées.
// Méthode : les faces du solide original qui sont convexes ne sont pas triangulées,
// les autres le sont.
extern SolidesP MaillageSolideParFacesConvexes (SolidesP &solid) ;


///////////////////////////*  FIN BREP-STL-LINK.H  *////////////////////////////



////////////////////////////*  DEBUT FICHIER.H  *///////////////////////////////


extern bool FichierOuvertLecture  (const char *, Fichier &fichier);
extern bool FichierOuvertEcriture (const char *, Fichier &fichier);


/////////////////////////////*  FIN FICHIER.H  *////////////////////////////////



#endif