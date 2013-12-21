//*****************************************************************************
// 
// Module	: IdentifiantsP
// 
// Fichier	: IdentifiantsP.h
// 
// Auteur	: regain (Christian, Estelle)
// 
// Date creat.	: Tue Feb 18 10:31:22 MET 1997
// 
// Version	: 1.0
//
// Commentaires	: Interfaces des classes Identifiants.
//
//	A FAIRE DANS LA PROCHAINE VERSION:
//		1. Toutes les m�thodes des identifiants sont const et renvoie des const (ou
//			au contraire, ne le sont pas)
//		2. Faire le point sur les r�f�rences
//		3. Faire le point sur les fonctions qui ne sont pas etendues
//		4. Fixer la bonne strategie de stockage des informations du modeleur (Listes, etc.)
// 
// Herite de	: la classe IdentifiantsEntitesBRep
// 
//*****************************************************************************
// Classe	: SommetsP
// Classe	: AretesP
// Classe	: AretesOrienteesP
// Classe	: ContoursP
// Classe	: FacesP
// Classe	: SolidesP
//*****************************************************************************


#ifndef	_IdentifiantsP_H_
#define	_IdentifiantsP_H_

//#include <stdio.h>
//#include <vcl.h>			// Parce que je ne sais plus quoi faire pour que les inclusions qui suivent marchent

#include	<iostream>
using namespace std ;

#include	"BibliothequeMathematique.h"
#include	"EnteteBRepPDLL.h"
#include	"IdentifiantsEntitesBRep.h"
#include	"Listes.h"
#include	"Tableaux.h"
#include	"AttributsFacesP.h"
#include	"AttributsSolidesP.h"



class BREPP_DLL		SommetsP;
class BREPP_DLL		AretesP;
class BREPP_DLL		AretesOrienteesP;
class BREPP_DLL		ContoursP;
class BREPP_DLL		FacesP;
class BREPP_DLL		SolidesP;
class BREPP_DLL		RepSommetsP ;
class BREPP_DLL		RepAretesP;
class BREPP_DLL		RepAretesOrienteesP;
class BREPP_DLL		RepContoursP;
class BREPP_DLL		RepFacesP;
class BREPP_DLL		RepSolidesP;


//#include 	"ModelesP.h"

//*****************************************************************************
//
// Classe	: SommetsP
//
//*****************************************************************************


class BREPP_DLL		SommetsP	: public IdentifiantsEntitesBRep
{
public :

	SommetsP () ;
	SommetsP (const SommetsP &S) ;
	SommetsP (const Points3D &P) ;
	~SommetsP () ;

	void Detruire (void) ;
   // D�truit le sommet.
   // La destruction est physique, il y a effectivement lib�ration de m�moire.

	void Vider (void) ;
   // D�truit le sommet mais pas les entit�s sur lesquelles il s'appuie. Comme
   // il n'y a pas de telle entit�s, Vider �quivaut � Detruire.


inline const 	Points3D& 	Point3D () 				const ;
void 				ModifPoint3D (const Points3D &P) ;

// ATTENTION :	l'appel a la fonction qui suit provoque la creation
// de la liste des aretes incidentes PLUS deux copies de la liste
// (2 return). L'affectation du resultat a une variable locale
// provoque certainement une troisieme copie.
// Les aretes obtenues sont dans un ordre correspondant a une rotation
// autour du sommet
// mais sont NON ORIENTEES INDIVIDUELLEMENT
//*****************************************************************************
// ATTENTION : nouvelle convention � dater du 19.03.2000 : les ar�tes orient�es
// issues d'un sommet sont TOUTES conserv�es au niveau du sommet ET dans l'ordre
// o� elles ont �t� cr��es. Elles ne sont ordonn�es qu'� partir du moment o� les
// cha�nages le rendent possible. Cela signifie que si l'on consulte les AO
// d'un sommet d'un objet qui n'est pas un solide (ou pas encore un solide),
// on ne garantit pas de les fournir dans un ordre correspondant � une rotation
// autour du sommet
//*****************************************************************************
const Listes<AretesP> 	ListeAretesIncidentes () 		 ;
const Tableaux<AretesP> TableauAretesIncidentes () 	;


// ATTENTION :	l'appel a la fonction qui suit provoque la creation
// de la liste des aretes incidentes PLUS deux copies de la liste
// (2 return). L'affectation du resultat a une variable locale
// provoque certainement une troisieme copie.
// Les aretes obtenues sont dans un ordre correspondant a une rotation
// autour du sommet
// et sont ORIENTEES INDIVIDUELLEMENT : elles ont toutes le sommet
// comme origine.
//*****************************************************************************
// ATTENTION : nouvelle convention � dater du 19.03.2000 : les ar�tes orient�es
// issues d'un sommet sont TOUTES conserv�es au niveau du sommet ET dans l'ordre
// o� elles ont �t� cr��es. Elles ne sont ordonn�es qu'� partir du moment o� les
// cha�nages le rendent possible. Cela signifie que si l'on consulte les AO
// d'un sommet d'un objet qui n'est pas un solide (ou pas encore un solide),
// on ne garantit pas de les fournir dans un ordre correspondant � une rotation
// autour du sommet
//*****************************************************************************
const Listes<AretesOrienteesP> ListeAretesOrienteesIncidentes()   ;
const Tableaux<AretesOrienteesP>& TableauAretesOrienteesIncidentes ()  ;

// Restitue les ar�tes orient�es incidentes au sommet et qui appartiennent
// effectivement � un contour. Ce nombre est �gal au nombre d'ar�tes si
// le SolidesP est ferm�, inf�rieur sinon.
// Par exemple, si on supprime la face sup�rieure d'un cube, les quatre sommets
// du dessus conserve 3 ar�tes mais n'ont plus que deux ar�tes orient�es
// incidentes sur des contours.
// Les ar�tes orient�es restitu�es partent du sommet.
// ATTENTION : si l'objet consult� n'est pas un solide valide, il peut
// manquer des cha�nages qui permettent d'ordonner la liste des ar�tes.
// Dans ce cas, la liste est compl�te mais non ordonn�e.
const Tableaux<AretesOrienteesP> TableauAretesOrienteesIncidentesDansUnContour () ;

inline const int 		NombreAretes () 			const ;
inline const int 		NombreAretesOrientees () 		const ;


// ATTENTION : la premi�re ar�te (orient�e ou non) a le num�ro 0 !!!
// Les ar�tes sont fournies dans un ordre correspondant � une rotation
// autour du sommet � condition que le solide soit valide dans le
// voisinage du sommet (chaque ar�te issue du contour appartient �
// deux contours exactement).
inline const AretesP 		IemeArete (int  i) 			const ;
inline const AretesOrienteesP	IemeAreteOrientee (int  i) 		const ;


// Conserve dans le sommet une nouvelle ar�te orient�e issue de lui.
// TOUTE ARETE QUI SE CREE doit evoquer cette fonction
// sur ses 2 sommets. L'arete orientee recue DOIT AVOIR
// le sommet POUR ORIGINE.
// Fonction � usage interne.
inline void 	IntegrerNouvelleAreteOrientee (const AretesOrienteesP &A) ;


// Retire une AO de la liste des AO issues d'un sommet.
// Fonction � usage interne.
inline void 	RetirerAreteOrientee (AretesOrienteesP &AO) ;

const SommetsP& 	operator = (const SommetsP &) ;
friend 	ostream& BREPP_DLL	operator << (ostream &, const SommetsP &) ;
void 		Decode (int tabul, ostream &  f, bool SurFichier, bool SurConsole)  ;

private :

inline const RepSommetsP&	Representation () const ;
inline RepSommetsP*		PtrRepresentation () ;

friend 	class BREPP_DLL AretesP ;
};


extern SommetsP BREPP_DLL		SommetErreur ;


//*****************************************************************************
//
// Classe	: AretesP
//
//*****************************************************************************

class BREPP_DLL		AretesP	: public IdentifiantsEntitesBRep
{
public :
	AretesP () ;
	AretesP (const AretesP &) ;

	AretesP (SommetsP& Origine, SommetsP& Extremite, bool Lisse = false);

	~AretesP () ;
	void Detruire (void) ;
   // D�truit l'ar�te et toutes les entit�s sur lesquelles elle s'appuie
   // (sommets et AretesOrientees) � condition qu'elles ne servent pas �
   // une autre ar�te (ce qui ne peut pas �tre le cas pour les ar�tes
   // orient�es).
   // La destruction est physique, il y a effectivement lib�ration de m�moire.

   void Vider(void) ;
   // D�truit l'ar�te sans d�truire les entit�s sur lesquelles elle s'appuie.


//*****************************************************************************
//	Consultation
//*****************************************************************************
inline 	const SommetsP& 			Sommet1 () 										const ;
inline 	const SommetsP& 			Sommet2 () 										const ;
inline 	const ContoursP& 			Contour1 () 									const ;
inline 	const ContoursP& 			Contour2 () 									const ;
inline 	const FacesP&				Face1 () 										const ;
inline 	const FacesP&				Face2 () 										const ;
inline 	const AretesP& 			AreteSuivanteDansContour1 () 				const ;
inline 	const AretesP& 			AreteSuivanteDansContour2 () 				const ;
inline 	const AretesP& 			AretePrecedenteDansContour1 () 			const ;
inline 	const AretesP& 			AretePrecedenteDansContour2 () 			const ;
inline 	const AretesOrienteesP&	AreteOrienteePositive () 					const ;
inline 	const AretesOrienteesP&	AreteOrienteeNegative()						const ;
inline 	bool							EstIsolee ()									const ;

inline 	bool							Continuite()									const ;

const Droites3D& 			Droite3D () ;

//*****************************************************************************
//	Modification
//*****************************************************************************
 	void 		ModifSommet1 (const SommetsP &P);
	void 		ModifSommet2 (const SommetsP &P);
	void 		ModifContour1 (const ContoursP &C);
 	void 		ModifContour2 (const ContoursP &C)  ;

 	void 		ModifAreteSuivanteDansContour1 (const AretesP &A);
 	void 		ModifAreteSuivanteDansContour2 (const AretesP &A);
 	void 		ModifAretePrecedenteDansContour1 (const AretesP &A);
 	void 		ModifAretePrecedenteDansContour2 (const AretesP &A);

inline 	void		ModifContinuite(bool);
	void 		Decode (int tabul, bool Sens, ostream &  f, bool SurFichier, bool SurConsole) ;

	static bool	Scission (AretesP A, SommetsP S, AretesP &A1, AretesP &A2) ;
	// Scinde l'ar�te A sur le sommet S. L'ar�te elle-m�me est d�truite et les
	// deux ar�tes construites sont restitu�es. A1 va du premier sommet de A � S
	// et A2 va de S au deuxi�me sommet de A.
	// Le r�sultat est vrai ssi l'op�ration a r�ussi (S ne se superpose pas � un
	// des sommets de A).
	// Si A appartenait � un contour, A1 et A2 sont ins�r�es dans ce m�me contour.
	// Si A �tait cha�n�e � d'autres ar�tes par l'un ou l'autre de ses sommets,
	// les liens sont mis � jours avec A1 et A2.
	// Cette fonction est statique car, si elle �tait une fonction membre, ce
	// serait une fonction membre qui d�truit l'objet qui l'a invoqu�. C'est
	// autoris� mais pas tr�s beau.
	// pour l'invoquer, �crire AretesP::Scission (A,S,A1,A2)
	// S peut ne PAS se trouver sur A !


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const AretesP& 		operator = (const AretesP &) ;
	friend	ostream& BREPP_DLL	operator << (ostream&, const AretesP&);

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

inline 	SommetsP* 		PtrSommet1 ();
inline 	SommetsP* 		PtrSommet2 ();
inline 	ContoursP*		PtrContour1();
inline 	ContoursP*		PtrContour2();
inline 	FacesP*			PtrFace1 ();
inline 	FacesP*			PtrFace2 ();
inline 	AretesP* 		PtrAreteSuivanteDansContour1 ();
inline 	AretesP* 		PtrAreteSuivanteDansContour2 ();
inline 	AretesP* 		PtrAretePrecedenteDansContour1 ();
inline 	AretesP* 		PtrAretePrecedenteDansContour2 ();
inline 	AretesOrienteesP *	PtrAreteOrienteePositive() ;
inline 	AretesOrienteesP *	PtrAreteOrienteeNegative() ;
	void 			GeometriePlusAJour();

void 		ModifAreteSuivante1 (const AretesP &A);
void 		ModifAreteSuivante2 (const AretesP &A);
void 		ModifAretePrecedente1 (const AretesP &A);
void 		ModifAretePrecedente2 (const AretesP &A);



	const RepAretesP&	Representation () const ;
 	RepAretesP* 		PtrRepresentation () ;
inline  	void 			ModifDroite3D (	const Droites3D &D) ;
	void			MettreAJourGeometrie();
inline 	bool			EstGeometrieAJour() const;

	friend class BREPP_DLL FacesP ;
	friend class BREPP_DLL TopoAretesOrienteesP ;
	friend class BREPP_DLL SommetsP ;
	friend class BREPP_DLL TopoContoursP ;
};



//*****************************************************************************
// Declare une arete vide pour toutes les fonctions qui devraient retourner
// une arete mais ne le peuvent a cause d'une erreur (mauvais chainages
// par exemple)
//*****************************************************************************

extern AretesP BREPP_DLL	AreteErreur ;


//*****************************************************************************
//
// Classe	: AretesOrienteesP
//
//*****************************************************************************


class BREPP_DLL		AretesOrienteesP : public IdentifiantsEntitesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	AretesOrienteesP () ;
	AretesOrienteesP (const AretesOrienteesP &) ;

	AretesOrienteesP (const AretesP &A, const bool &sens) ;

	~AretesOrienteesP () ;
	void Detruire (void) ;
   // D�truit l'ar�te orient�e et lib�re la m�moire qu'occupe sa repr�sentation.
   // Pas de r�percutions sur d'autres entit�s car l'ar�te orient�e ne s'appuie
   // sur rien.

   void Vider(void) ;
   // Idem Detruire car une AreteOrienteeP n'a pas d'entit�s support.


//*****************************************************************************
//	Consultation
//*****************************************************************************
const SommetsP				Origine()										const;
const SommetsP				Extremite()										const;
const AretesP&				Arete()											const;
AretesP&						Arete()											;
const ContoursP			Contour()										const;
const AretesOrienteesP	AreteOrienteeSuivanteDansContour()		const;
const AretesOrienteesP	AreteOrienteePrecedenteDansContour()	const;
const AretesOrienteesP	AreteOrienteeOpposee()						const;
bool							Sens()											const;

//*****************************************************************************
//	Modification
//*****************************************************************************
void	ModifOrigine(const SommetsP&);
void	ModifExtremite(const SommetsP&);
void	ModifContour(const ContoursP&);
void	ModifAreteOrienteeSuivanteDansContour(const AretesOrienteesP&);
void	ModifAreteOrienteePrecedenteDansContour(const AretesOrienteesP&);
void	SortirDuContour(void);

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
			const AretesOrienteesP& 	  			operator = (const AretesOrienteesP &) ;
friend 	ostream& BREPP_DLL		  				operator <<(ostream &,const AretesOrienteesP&) ;
friend	const AretesOrienteesP	BREPP_DLL 	operator - (const AretesOrienteesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

AretesOrienteesP *	PtrAreteOrienteeOpposee () ;

//*****************************************************************************
//	Modification
//*****************************************************************************
SommetsP *						PtrOrigine();
AretesP *						PtrArete ();

const RepAretesOrienteesP&	Representation()							const;
RepAretesOrienteesP*			PtrRepresentation();

void	ModifAreteOrienteeSuivante(const AretesOrienteesP&);
void	ModifAreteOrienteePrecedente(const AretesOrienteesP&);

friend class BREPP_DLL TopoAretesOrienteesP ;
friend class BREPP_DLL TopoContoursP ;
};


//*****************************************************************************
// Declare une arete orientee vide pour toutes les fonctions qui devraient
// retourner une arete orientee mais ne le peuvent a cause d'une erreur
// (mauvais chainages par exemple)
//*****************************************************************************

extern AretesOrienteesP BREPP_DLL	AreteOrienteeErreur ;



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&




//*****************************************************************************
//
// Classe	: ContoursP
//
//*****************************************************************************
// Constructeurs et destructeur
//	ContoursP (const Listes<AretesP> &)
//	ContoursP (const Listes<AretesOrienteesP> &)
//
// Consultation
//	ListeAretes
//	NombreAretes
//	IemeArete
//	ListeAretesOrientees
//	NombreAretesOrientees
//	IemeAreteOrientee
//	Face
//	VecteurNormal
//
// Modification
//	AjouterArete
//	AjouterAreteOrientee
//	ModifFace
//	InsererArete
//	InsererAreteOrientee
//	RemplacerArete
//	RemplacerAreteOrientee
//
// Surcharge des operateurs
//	operator = (const ContoursP &) ;
//	operator << (ostream &, const ContoursP &) ;
//
// Partie privee
//	PtrIemeArete
//	PtrIemeAreteOrientee
//	PtrFace
//	Representation
//	PtrRepresentation
//*****************************************************************************


class BREPP_DLL		ContoursP : public IdentifiantsEntitesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************

	ContoursP () ;
	ContoursP (const ContoursP &) ;

	ContoursP (const Listes<AretesP>&) ;
	ContoursP (const Listes<AretesOrienteesP> &) ;
	ContoursP (const Tableaux<AretesP>&) ;
	ContoursP (const Tableaux<AretesOrienteesP> &) ;
	~ContoursP () ;

	void Detruire (void) ;
   // D�truit le contour et toutes les entit�s sur lesquelles elle s'appuie
   // (ar�tes et sommets) � condition qu'elles ne servent pas � un
   // autre contour.
   // La destruction est physique, il y a effectivement lib�ration de m�moire.

   void Vider(void) ;
   // D�truit le contour sans d�truire les entit�s sur lesquelles il s'appuie.


//*****************************************************************************
//	Consultation
//*****************************************************************************
inline Listes<AretesP>				ListeAretes () 									const ;
inline Tableaux<AretesP>			TableauAretes ()									const ;
inline int								NombreAretes () 									const ;
Listes<SommetsP> 						ListeSommets ()									const ;

// ATTENTION : la premi�re ar�te (orient�e ou non) a le num�ro 0 !!!
inline const AretesP  				IemeArete (const int) 							const ;
inline const AretesOrienteesP  	IemeAreteOrientee (const int) 				const ;
inline 		 Listes<AretesOrienteesP> 		ListeAretesOrientees () 			const ;
inline const  Tableaux<AretesOrienteesP>&	TableauAretesOrientees () 			const ;

void													TableauAretesOrientees (Tableaux<AretesOrienteesP>&)			const ;
// Idem avec un tableau en r�f�rence. Les AO sont AJOUTEES en QUEUE du tableau.

inline int 								NombreAretesOrientees () 						const ;
inline const FacesP & 				Face () 												const ;
inline 		 const Vecteurs3D  	VecteurNormal () 									const ;


//*****************************************************************************
//	Modification
//*****************************************************************************

// Ajoute une arete au contour : c'est la procedure qui s'occupe
// de l'orientation de l'arete. Attention, les aretes ajoutees au
// fur et a mesure doivent avoir une extremite en commun. La derniere
// arete ajoutee se doit de fermer le contour.

void	AjouterArete (AretesP) 	;
void	AjouterAretes ( const Listes<AretesP>& ) ;
void	AjouterAretes ( const Tableaux<AretesP>&) ;


// Ajoute une arete orientee au contour : les aretes orientees doivent
// se suivre, la derniere devant fermer le contour.

void	AjouterAreteOrientee (AretesOrienteesP);
void	AjouterAretesOrientees ( const Listes<AretesOrienteesP>& ) ;
void	AjouterAretesOrientees ( const Tableaux<AretesOrienteesP>& ) ;


inline void	ModifFace(const FacesP&)	;

// Insertion d'une arete juste avant la ieme arete (la premi�re a le num�ro 0).
// Si i < 0 ou >= NbAretes, on insere avant l'arete retournee par
// IemeArete dans ce cas.
// ATTENTION : l'arete inseree DOIT IMPERATIVEMENT partager au moins un
//	       de ses sommets avec la (i-1)eme ou la ieme arete
void	InsererArete (int i, AretesP A) ;
void	InsererAreteOrientee (int i, AretesOrienteesP AO) ;


// Retrait d'une arete. L'ar�te n'est pas d�truite.
// Une partie des cha�nages de l'ar�te et du contour est supprim�e.
void	RetirerArete (AretesP A) ;
void	RetirerAreteOrientee (AretesOrienteesP AO) ;

// Retrait d'une arete de rang i (la premi�re a le num�ro 0).
// L'ar�te n'est pas d�truite.
// Si i < 0 ou >= NbAretes, il est ramen� dans l'intervalle
// Une partie des cha�nages de l'ar�te et du contour est supprim�e.
void	RetirerArete (int i) ;
void	RetirerAreteOrientee (int i) ;


// remplacement d'une arete (ev orientee) par une autre
// ATTENTION : - La nouvelle arete DOIT IMPERATIVEMENT partager au moins un
//	       de ses sommets avec la (i-1)eme ou la (i+1)eme arete.
//             - Les cha�nages au niveau des ar�tes ne se fait que du(des) cote(s)
// 		 du(des) sommet(s) partag�(s) avec la (i-1)�me ou(et) la (i+1)�me.
//			 Par cons�quent, les cha�nages ne seront correct qu'� partir du moment o�
// 		 le contour est ferm�.
// ATTENTION : la premi�re ar�te (ev orientee) a le num�ro 0 !!!
void	RemplacerArete	(int i, AretesP A) ;
void	RemplacerAreteOrientee (int i, AretesOrienteesP AO) ;

bool	PointDansContour (	const Points3D &P, const Vecteurs3D &N,
									bool *SurLeContour) ;
//************************************************************************
// teste l'appartenance du point P au contour. Ne restitue vrai que
// si P est STRICTEMENT DANS le contour. S'il est sur le contour, la
// fonction rend faux mais le bool�en SurLeContour est vrai.
// ATTENTION : le point est suppos� �tre DANS LE PLAN du contour
//************************************************************************

bool CentreGraviteEtAire (Points3D *PG, double *PA) ;
// Restitue le centre de masse et l'aire d'un contour en n�gligent
// les �ventuels contours int�rieurs
// Le r�sultat est vrai si et seulement si le calcul a �t� possible.


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const ContoursP&	operator = (const ContoursP &) ;
friend 	ostream& BREPP_DLL	operator << (ostream &, const ContoursP &) ;
	void Decode (int tabul, ostream &  f, bool SurFichier, bool SurConsole)  ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

// ATTENTION : la premi�re ar�te (ev orientee) a le num�ro 0 !!!
inline AretesP *				PtrIemeArete (const int)	;
inline AretesOrienteesP *	PtrIemeAreteOrientee (const int);
inline FacesP *					PtrFace ()			;
const RepContoursP & Representation ()	const;
RepContoursP *			PtrRepresentation ();
inline void				SortirAreteOrientee ( const AretesOrienteesP& ) ;
inline void ModifAreteSuivante (const AretesOrienteesP& Pos ,const AretesP& Suiv) ;
inline void	ModifAretePrecedente (const AretesOrienteesP& Pos ,const AretesP& Prec) ;

friend class BREPP_DLL TopoAretesP ;
friend class BREPP_DLL AretesP ;
friend class BREPP_DLL TopoAretesOrienteesP ;
};

extern ContoursP BREPP_DLL		ContourErreur ;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


//*****************************************************************************
//
// Classe	: FacesP
//
//*****************************************************************************
// Constructeurs et destructeur
//	FacesP (const ContoursP &) ;
//	FacesP (const Listes<ContoursP> &) ;
//
// Consultation
//	NombreContoursInterieurs
//	IemeContourInterieur
//	ContourExterieur
//	ListeContoursInterieurs
//	Solide
//	VecteurNormal
//	Plan
//	Englobant
//	ListeSommets
//	NombreSommets
//	IemeSommet
//
// Modification
//	AjouterContourInterieur
//	ModifSolide
//	ModifEnglobant
//	ModifPlan
//
// Surcharge des operateurs
//	const FacesP& 	operator = (const FacesP &) ;
// 	operator << (ostream &, const FacesP &) ;
//
// Partie privee
//	PtrIemeContourInterieur
//	PtrContourExterieur
//	PtrSolide
//	PtrPlan
//	PtrEnglobant
//	GeometriePlusAJour
//	Representation
//	PtrRepresentation
//	MettreAJourGeometrie
//	CalculPlan
//	CalculEnglobant
//*****************************************************************************

class BREPP_DLL FacesP : public IdentifiantsEntitesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	FacesP () ;
	FacesP (const FacesP &) ;
	
	FacesP (ContoursP, const AttributsFacesP *PA = AttributsFacesP::AttributParDefaut ()) ;
	// l'attribut, s'il existe, est dupliqu� donc PA peut �tre lib�r� par l'appelant

	FacesP (const Listes<ContoursP> &, const AttributsFacesP *PA = AttributsFacesP::AttributParDefaut ()) ;
	// l'attribut, s'il existe, est dupliqu� donc PA peut �tre lib�r� par l'appelant

	FacesP ( const Tableaux<ContoursP> &, const AttributsFacesP *PA = AttributsFacesP::AttributParDefaut ()) ;
	// l'attribut, s'il existe, est dupliqu� donc PA peut �tre lib�r� par l'appelant

	~FacesP () ;

	void Detruire (void) ;
	// D�truit la face et toutes les entit�s sur lesquelles elle s'appuie
	// (contours, ar�tes et sommets) � condition qu'elles ne servent pas � une
	// autre face.
	// La destruction est physique, il y a effectivement lib�ration de m�moire.

	void Vider(void) ;
	// D�truit la face sans d�truire les entit�s sur lesquelles elle s'appuie.


//*****************************************************************************
//	Consultation
//*****************************************************************************
	inline 	const int						NombreContoursInterieurs () 			const ;

	// ATTENTION : le premier Contour Interieur a le num�ro 0 !!
	inline 	const ContoursP 				IemeContourInterieur (const int) 	const ;
	inline 	const ContoursP 				ContourExterieur () 						const ;
	inline 	const Listes<ContoursP> 	ListeContoursInterieurs ()				const ;
	inline   const Tableaux<ContoursP>	TableauContoursInterieurs ()			const ;
	inline 	const SolidesP 				Solide ()									const ;

 	const Vecteurs3D				VecteurNormal ()							const ;
	// S'il n'est pas possible de calculer le vecteur normal, la face devient
	// une face non initialis�e et le vecteur nul est restitu�. Ceci arrive
	// apr�s un chargement � partir d'un fichier d�fectueux, lors de la premi�re
	// consultation de la normal.
	// Sinon, le vecteur restitu� est orient� vers l'ext�rieur et norm�.

 	Plans3D 					Plan ()										;
	// S'il n'est pas possible de calculer le plan, la face devient
	// une face non initialis�e et le plan x=0 est restitu�. Ceci arrive
	// apr�s un chargement � partir d'un fichier d�fectueux, lors de la premi�re
	// consultation du plan.
	// Sinon, le plan restitu� est celui de la face.

 	const Englobants3D 			Englobant ();
	// S'il n'est pas possible de calculer l'englobant, la face devient
	// une face non initialis�e et l'englobant par d�faut est restitu�. Ceci arrive
	// apr�s un chargement � partir d'un fichier d�fectueux, lors de la premi�re
	// consultation de l'englobant.
	// Sinon, l'englobant restitu� est celui de la face.

	inline 	Listes<SommetsP>				ListeSommets ()							const ;
	inline  Tableaux<SommetsP>				TableauSommets ()							const ;
	inline 	const int						NombreSommets () 							const ;

	// ATTENTION : le premier sommet a le num�ro 0 !!
	inline 	const SommetsP					IemeSommet (int)							const ;

	bool IntersectionRayonFace	(const Droites3D	&D,
									   Points3D			*PointInt,
									   bool					*DroiteToucheContour) ;
	//************************************************************************
	// Teste s'il existe une intersection entre la face et la droite
	// pass�e en param�tre. Si c'est le cas, le point d'intersection
	// est restitu�.
	// Si la droite passe par un trou de la face, il n'y a pas d'intersection.
	// Si la droite touche un contour, on consid�re qu'il n'y a pas
	// d'intersection mais le bool�en DroiteToucheContour est vrai.
	//************************************************************************

	bool	PointDansFace (const Points3D &P, bool *SurUnContour) ;
	//************************************************************************
	// teste l'appartenance STRICTE du point P � la face. Si P est sur un
	// des contours, le bool�en SurUnContour est cependant vrai.
	// ATTENTION : le point est suppos� �tre DANS LE PLAN de la face
	//************************************************************************

//*****************************************************************************
//	Modification
//*****************************************************************************
	void			AjouterContourInterieur (ContoursP) 	;
	void			RetirerContourInterieur (ContoursP) 	;
	void			ModifSolide (const SolidesP &)		;
	void			ModifEnglobant (const Englobants3D &)	;
	void			ModifPlan (const Plans3D &)		;
   void 			ModifVecteurNormal ( const Vecteurs3D& ) ;

	// Scinde une face en deux faces en cr�ant une ar�te reliant deux sommets de son
	// contour EXTERIEUR.
	// L'ar�te cr��e est restitu�e dans AreteDeScission.
	// *this est la face � scinder. Au terme de la scission, *this est la "moiti�"
	// qui utilise AreteDeScission dans le sens (S1,S2) et F est la "moiti�" utilisant
	// cette m�me ar�te dans le sens (S2,S1).
	// Les deux faces tournent dans le m�me sens que l'originale.
	// Aucune v�rification d'ordre g�om�trique n'est effectu�e.
	// Si *this appartient � un solide, la face cr��e est ajout�e � ce solide.
   // Les �ventuels contours int�rieurs restent dans *this.
	bool Scission (SommetsP S1, SommetsP S2, AretesP &AreteDeScission, FacesP &F) ;

	// Remplace une face triangulaire F par trois faces triangulaires (F1,F2,F3).
	// Chaque face triangulaire construite est constitu�e de deux sommets cons�cutifs
	// de F et du sommet construit � partir de P (Som).
	// P DOIT se trouver � l'int�rieur de F.
	// Si F appartient � un solide, elle en est retir�e et les 3 faces y
   // sont ajout�es. Si l'appelant conserve le tableau ou la liste des
   // faces du solide, il doit donc soit en retirer F et y ajouter F1, F2, F3
   // soit le ou la r�-initialiser en appelant une fonction de consultation
   // des faces du solide.
	// F est d�truite et NE DOIT PLUS �tre utilis�e apr�s l'appel.
	// Le r�sultat de la fonction est vrai si l'op�ration de subdivision a r�ussi.
	static bool SubdivisionFaceTriangulaire (	FacesP F, Points3D &P,
   														FacesP &F1, FacesP &F2, FacesP &F3,
															SommetsP &S) ;

	inline const AttributsFacesP	*Attribut () const ;
	// Le pointeur restitu� est un const * pour interdire la modif 
	// de l'attribut (on restitue l'adresse de l'attribut conserv�
	// dans la face !

	inline void ModifAttribut (const AttributsFacesP *PA) ;
	// *PA est dupliqu� donc PA doit �tre lib�r� par l'appelant apr�s l'appel

	bool CentreGraviteEtAire (Points3D *PG, double *PA) ;
	// Restitue le centre de masse et l'aire d'une face
	// Les �ventuels contours int�rieurs sont pris en compte.
	// Le r�sultat est vrai si et seulement si le calcul a �t� possible.

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
    const FacesP& 		operator = (const FacesP &) 			;

	friend 	ostream& BREPP_DLL	operator << (ostream &, const FacesP &) 	;
	void Decode (int tabul, ostream &  f, bool SurFichier, bool SurConsole) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

	// ATTENTIOn : le premier Contour Interieur a le num�ro 0 !!
	ContoursP *		PtrIemeContourInterieur (const int)	;
	ContoursP*		PtrContourExterieur ()			;
	SolidesP*		PtrSolide ()				;

	Plans3D *		PtrPlan ()				;
	Englobants3D*		PtrEnglobant ()				;

	void			GeometriePlusAJour ()			;
	const RepFacesP & 	Representation ()			const ;
	RepFacesP *		PtrRepresentation ()			;

	bool			MettreAJourGeometrie ()			;
	// Si la mise � jour de la g�om�trie �choue, la fonction lib�re la m�moire
	// occup�e par la face (mais pas celle des entit�s de plus bas niveau) et
	// en fait une face non initialis�e. Elle restitue alors faux.

	bool			CalculNormalePlan ( Vecteurs3D& , Plans3D& ) const ;
	// Si le calcul de la normale et du plan �couent, la fonction restitue faux.
	// Ceci arrive quand la face est mal construite, c'est � dire quand on
	// n'arrive pas � trouver deux ar�tes cons�cutives non align�es.
	// Ceci survient par exemple sur des fichiers STL, m�me sur ceux produits par
	// Catia (c'�tait le cas sur la porte au format STL fournie par Daimler
	// Chrysler dans le cadre du projet DRAGON : il y avait des triangles dont
	// deux sommets �taient exactement identiques !

	Englobants3D		CalculEnglobant ()			;


friend class BREPP_DLL SolidesP ;
friend class BREPP_DLL AretesP ;
friend class BREPP_DLL TopoContoursP ;
};

extern FacesP BREPP_DLL	FaceErreur ;
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


//*****************************************************************************
//
// CLASSE	: SolidesP
//
//*****************************************************************************
// Constructeurs et destructeur
//	SolidesP (const Listes<FacesP> &) ;
//
// Consulation
// 	NombreSommets
//	NombreAretes
//	NombreFaces
//	IemeSommet
//	IemeArete
//	IemeFace
//	ListeSommets
//	ListeAretes
//	ListeFaces
//	Englobant
//
// Modification
//	AjouterFace
//	ModifEnglobant
//
// Surcharge des operateurs
//	operator = (const SolidesP &) ;
// 	operator << (ostream &, const SolidesP &) ;
//
// Partie privee
//	PtrIemeFace
//	PtrEnglobant
//	Representation
//	PtrRepresentation
//	MiseAJourGeometrie
//	GeometriePlusAJour
//	CalculEnglobant
//*****************************************************************************

class BREPP_DLL SolidesP : public IdentifiantsEntitesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	SolidesP () ;
	SolidesP (const SolidesP &) ;

	SolidesP (const Listes<FacesP> &, const AttributsSolidesP *PA = NULL) ;
	// l'attribut, s'il existe, est dupliqu� donc PA peut �tre lib�r� par l'appelant

   SolidesP (const Tableaux<FacesP>&, const AttributsSolidesP *PA = NULL) ;
	// l'attribut, s'il existe, est dupliqu� donc PA peut �tre lib�r� par l'appelant

	~SolidesP () ;
	SolidesP Dupliquer () const ;	// cr�e un solide identique � l'original (pas de partage)

   void Detruire (void) ;
   // D�truit le solide et toutes les entit�s sur lesquelles il s'appuie (faces,
   // contours, ar�tes et sommets.
   // La destruction est physique, il y a effectivement lib�ration de m�moire.

   void Vider(void) ;
   // D�truit le solide sans d�truire les entit�s sur lesquelles il s'appuie.

//*****************************************************************************
//	Consultation
//*****************************************************************************
inline int				NombreSommets ()									const ;
inline int				NombreAretes ()									const ;
inline int				NombreFaces ()										const ;

// ATTENTIOn : le premier Sommet (resp arete, face) a le num�ro 0 !!
// ATTENTION : FONCTION TRES TRES TRES LENTE !!! Mieux vaut
// demander le tableau des sommets et le parcourir soi-m�me
inline const SommetsP 			IemeSommet (const int)				const ;

// ATTENTION : FONCTION TRES TRES TRES LENTE !!! Mieux vaut
// demander le tableau des ar�tes et le parcourir soi-m�me
inline const AretesP 			IemeArete (const int)					const ;

inline const FacesP 				IemeFace (const int)				const ;
inline const Listes<SommetsP> ListeSommets ()							const ;
inline const Tableaux<SommetsP> TableauSommets()						const ;
inline const Listes<AretesP> 	ListeAretes ()							const ;
inline const Tableaux<AretesP>	TableauAretes () 						const ;
inline const Listes<FacesP>		ListeFaces ()							const ;
inline const Tableaux<FacesP>&	TableauFaces ()						const ;
const Englobants3D &	Englobant () 				;


//*****************************************************************************
//	Modification
//*****************************************************************************
// Ajoute une face au solide deja cree
void 			AjouterFace (FacesP &) 	      	;
void 			AjouterFaces ( const Listes<FacesP>& ) ;
void 			AjouterFaces ( const Tableaux<FacesP>& ) ;
void			RetirerFace (FacesP &F) ;

// Change l'englobant du solide
inline void			ModifEnglobant (const Englobants3D &)	;

// Transforme le solide avec la transfo de matrice M
void			Transformer (const Matrices4D & M) ;

// Calcul du volume et du centre de masse (centre de gravit�).
// Fonctionne pour les poly�dres convexes et concaves.
// Si le calcul a �t� possible, la fonction restitue vrai. 
// Sinon (pas assez de faces), elle restitue faux.
bool CentreDeMasseEtVolume (Points3D *PG, double *PVol) ;

bool FusionFaces (Tableaux <FacesP> &TF, FacesP &FaceConstruite) ;
	// Supprime du solide les faces du tableau TF, les d�truit, construit
   // une face pour boucher le trou qu'elles laissent, l'ajoute au solide
   // et la restitue. Aucun test de nature g�om�trique n'est r�alis� sur
	// la face construite. Par exemple, elle peut ne pas �tre plane.
   //
   // Les contours int�rieurs des faces de TF deviennent des contours
   // int�rieurs de la face reconstruite pour boucher. D'autres CI peuvent
   // appara�tre, si les faces � supprimer ens�rent une ou plusieurs zones vides.
	//
	// La fonction restitue faux si elle a �chou�, par exemple parce que les
	// faces ne sont pas connexes, ce qui n�cessiterait plusieurs faces de bouchage.
   //
   // Attention : une m�me face ne doit pas appara�tre plusieurs fois dans TF.
	//
	// Si la fonction �choue, le solide n'est pas modifi�.
	// Sinon les faces de TF sont d�truites (avec leurs contours ext�rieurs et
   // leurs ar�tes et sommets s'ils ne servent plus) et la face construite
   // est ajout�e au solide.

	void FusionFacesCoplanaires (double AngleEnDegre) ;
	// Fusionne entre elles toutes les faces adjacentes coplanaires.
	// Les faces devenues inutiles sont d�truites.
	// AngleEnDegre sp�cifie l'angle en de�a duquel deux faces adjacentes sont
	// consid�r�es coplanaires.

	bool Coller (SolidesP	&Sol2, FacesP F1, FacesP &F2) ;
	// Colle � *this le solide Sol2.
	// L'unique contact entre les 2 solides doit se faire par la face F1 de *this et
	// la face F2 de Sol2. F2 doit �tre strictement incluse dans F1 et n'avoir
	// de contact avec aucun de ses contours int�rieurs s'il en existe. Ces crit�res
	// ne sont pas v�rifi�s.
	// Le collage �choue si F1 n'appartient pas � *this ou si F2 n'appartient
	// pas � Sol2.
	// En cas de succ�s, Sol2 et F2 ne doivent plus �tre utilis�s. Toutes les faces
	// de Sol2 deviennent des faces de *this, � l'exception de F2 dont le
	// contour ext�rieur devient un contour int�rieur de F1 et dont les contours
	// int�rieurs deviennent des faces � part enti�re.

	inline const AttributsSolidesP	*Attribut () const ;
	// Le pointeur restitu� est un const * pour interdire la modif 
	// de l'attribut (on restitue l'adresse de l'attribut conserv�
	// dans la face !

	inline void ModifAttribut (const AttributsSolidesP *PA) ;
	// *PA est dupliqu� donc PA doit �tre lib�r� par l'appelant apr�s l'appel

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const SolidesP& 	operator = (const SolidesP &) ;

friend 	ostream& BREPP_DLL	operator << (ostream &, const SolidesP &) ;
void Decode (int tabul, ostream &  f, bool SurFichier, bool SurConsole) const ;


//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

// ATTENTIOn : la premi�re face a le num�ro 0 !!
inline 	FacesP *		PtrIemeFace (const int)		;
inline 	Englobants3D *		PtrEnglobant ()			;
	const RepSolidesP & 	Representation ()		const ;
	RepSolidesP *		PtrRepresentation ()		;


	void 				MiseAJourGeometrie () 		;
inline 	void		GeometriePlusAJour () 		;
	Englobants3D 			CalculEnglobant () 		;

friend 	class BREPP_DLL FacesP ;
};

extern SolidesP BREPP_DLL	SolideErreur ;

template class BREPP_DLL Conteneurs <SolidesP> ;
template class BREPP_DLL ElemListes <SolidesP> ;
template class BREPP_DLL Listes <SolidesP> ;
template class BREPP_DLL Iterateurs <SolidesP> ;
template class BREPP_DLL Tables <SolidesP> ;
template class BREPP_DLL Tableaux <SolidesP> ;

template class BREPP_DLL Conteneurs <FacesP> ;
template class BREPP_DLL ElemListes <FacesP> ;
template class BREPP_DLL Listes <FacesP> ;
template class BREPP_DLL Iterateurs <FacesP> ;
template class BREPP_DLL Tables <FacesP> ;
template class BREPP_DLL Tableaux <FacesP> ;

template class BREPP_DLL Conteneurs <ContoursP> ;
template class BREPP_DLL ElemListes <ContoursP> ;
template class BREPP_DLL Listes <ContoursP> ;
template class BREPP_DLL Iterateurs <ContoursP> ;
template class BREPP_DLL Tables <ContoursP> ;
template class BREPP_DLL Tableaux <ContoursP> ;

template class BREPP_DLL Conteneurs <AretesOrienteesP> ;
template class BREPP_DLL ElemListes <AretesOrienteesP> ;
template class BREPP_DLL Listes <AretesOrienteesP> ;
template class BREPP_DLL Iterateurs <AretesOrienteesP> ;
template class BREPP_DLL Tables <AretesOrienteesP> ;
template class BREPP_DLL Tableaux <AretesOrienteesP> ;

template class BREPP_DLL Conteneurs <AretesP> ;
template class BREPP_DLL ElemListes <AretesP> ;
template class BREPP_DLL Listes <AretesP> ;
template class BREPP_DLL Iterateurs <AretesP> ;
template class BREPP_DLL Tables <AretesP> ;
template class BREPP_DLL Tableaux <AretesP> ;

template class BREPP_DLL Conteneurs <SommetsP> ;
template class BREPP_DLL ElemListes <SommetsP> ;
template class BREPP_DLL Listes <SommetsP> ;
template class BREPP_DLL Iterateurs <SommetsP> ;
template class BREPP_DLL Tables <SommetsP> ;
template class BREPP_DLL Tableaux <SommetsP> ;


#include	"RepresentationsP.h"
#include "SommetsP.inl"
#include "AretesP.inl"
//#include "AretesOrienteesP.inl"
#include "ContoursP.inl"
#include "FacesP.inl"
#include "SolidesP.inl"

#endif
