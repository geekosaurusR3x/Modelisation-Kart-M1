#ifndef __TopologiesP__h__
#define	__TopologiesP__h__


#include	"BibliothequeBRep.h"
#include	"Listes.h"
#include        "Tableaux.h"



class BREPP_DLL		TopoSommetsP ;
class BREPP_DLL		TopoAretesP ;
class BREPP_DLL		TopoAretesOrienteesP ;
class BREPP_DLL		TopoContoursP ;
class BREPP_DLL		TopoFacesP ;
class BREPP_DLL		TopoSolidesP ;



//*****************************************************************************
//
// Module	: TopoSommetsP
//
// Fichier	: TopoSommetsP.h
//
// Auteur	: regain
//
// Date creat.	: Thu Feb 20 11:37:50 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe TopoSommetsP.
//
//
//*****************************************************************************
// Includes
// Classe TopoSommetsP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************





//*****************************************************************************
//
// Classe TopoSommetsP
//
//*****************************************************************************

class BREPP_DLL TopoSommetsP : public TopologiesBRep
{
public :

//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	TopoSommetsP () ;
	TopoSommetsP (const TopoSommetsP &) ;
	~TopoSommetsP () ;


//*****************************************************************************
// ATTENTION : nouvelle convention à dater du 19.03.2000 : les arêtes orientées
// issues d'un sommet sont TOUTES conservées au niveau du sommet ET dans l'ordre
// où elles ont été créées. Elles ne sont ordonnées qu'à partir du moment où les
// chaînages le rendent possible. Cela signifie que si l'on consulte les AO
// d'un sommet d'un objet qui n'est pas un solide (ou pas encore un solide),
// on ne garantit pas de les fournir dans un ordre correspondant à une rotation
// autour du sommet
//*****************************************************************************
inline const Tableaux<AretesOrienteesP>& TableauAretesOrienteesIncidentes () ;

// ATTENTION : la premiere arete (ev. orientee) a le numéro 0 !!
// Les arêtes sont fournies dans un ordre correspondant à une rotation
// autour du sommet à condition que le solide soit valide dans le
// voisinage du sommet (chaque arête issues du contour appartient à
// deux contours exactement).
const AretesP 		IemeArete (int i) ;
const AretesOrienteesP IemeAreteOrientee (int i) const;

// Les deux fonctions qui suivent ont le même résultat
inline const int 		NombreAretes () 			const ;
inline const int 		NombreAretesOrientees () 		const ;

const AretesOrienteesP& PremiereAreteOrienteeIncidente () ;

// ATTENTION :	l'appel a la fonction qui suit provoque la creation de la liste
//		des aretes incidentes PLUS une copie de la liste (return).
//		L'affectation du resultat a une variable locale provoque
//		certainement une deuxieme copie.
// Sauf exception (voir plus haut), les aretes obtenues sont dans un
// ordre correspondant a une rotation autour du sommet
// mais sont NON ORIENTEES INDIVIDUELLEMENT
//*****************************************************************************
// ATTENTION : nouvelle convention à dater du 19.03.2000 : les arêtes orientées
// issues d'un sommet sont TOUTES conservées au niveau du sommet ET dans l'ordre
// où elles ont été créées. Elles ne sont ordonnées qu'à partir du moment où les
// chaînages le rendent possible. Cela signifie que si l'on consulte les AO
// d'un sommet d'un objet qui n'est pas un solide (ou pas encore un solide),
// on ne garantit pas de les fournir dans un ordre correspondant à une rotation
// autour du sommet
//*****************************************************************************

	const Listes<AretesP>  ListeAretesIncidentes () ; 	// Parcours + copie
   const Tableaux<AretesP> TableauAretesIncidentes () ;   // Parcours + copie


	// ATTENTION :	l'appel a la fonction qui suit provoque la creation de la liste
	//		des aretes incidentes PLUS une copie de la liste (return).
	//		L'affectation du resultat a une variable locale provoque
	//		certainement une deuxieme copie.
	// Sauf exception (voir plus haut), les aretes obtenues sont dans un
	// ordre correspondant a une rotation autour du sommet
	// et sont ORIENTEES INDIVIDUELLEMENT : elles ont toutes le sommet comme origine.
	//*****************************************************************************
	// ATTENTION : nouvelle convention à dater du 19.03.2000 : les arêtes orientées
	// issues d'un sommet sont TOUTES conservées au niveau du sommet ET dans l'ordre
	// où elles ont été créées. Elles ne sont ordonnées qu'à partir du moment où les
	// chaînages le rendent possible. Cela signifie que si l'on consulte les AO
	// d'un sommet d'un objet qui n'est pas un solide (ou pas encore un solide),
	// on ne garantit pas de les fournir dans un ordre correspondant à une rotation
	// autour du sommet
	//*****************************************************************************
	const Listes<AretesOrienteesP> ListeAretesOrienteesIncidentes() ;
   // 1 Parcours

	// Restitue les arêtes orientées incidentes au sommet et qui appartiennent
	// effectivement à un contour. Ce nombre est égal au nombre d'arêtes si
	// le SolidesP est fermé, inférieur sinon.
	// Par exemple, si on supprime la face supérieure d'un cube, les quatre sommets
	// du dessus conserve 3 arêtes mais n'ont plus que deux arêtes orientées
	// incidentes sur des contours.
	// Les arêtes orientées restituées partent du sommet.
	// ATTENTION : si l'objet consulté n'est pas un solide valide, il peut
	// manquer des chaînages qui permettent d'ordonner la liste des arêtes.
	// Dans ce cas, la liste est complète mais non ordonnée.
	const Tableaux<AretesOrienteesP> TableauAretesOrienteesIncidentesDansUnContour () ;

	//*********************************************************************
	// Conserve dans le sommet une nouvelle arête orientée issue de lui.
	// TOUTE ARETE QUI SE CREE doit evoquer cette fonction
	// sur ses 2 sommets. L'arete orientee recue DOIT AVOIR
	// le sommet POUR ORIGINE.
	//*********************************************************************
	void 	IntegrerNouvelleAreteOrientee (const AretesOrienteesP &A) ;

	//*********************************************************************
   // Fonction à usage interne : retire une arête orientée des arêtes
   // orientées conservées au niveau du sommet si elle existe.
	//*********************************************************************
	inline 	void 		RetirerAreteOrientee (AretesOrienteesP &AO) ;

	void MettreAJourTableAretesOrientees () ;
	inline    bool AJour () 										const ;
	inline   TopologiesBRep*	Dupliquer() const ;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const TopoSommetsP& 	operator = (const TopoSommetsP &) ;

friend 	ostream& BREPP_DLL 	operator << (ostream &, const TopoSommetsP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :

	Tableaux<AretesOrienteesP> tabAretesOrientees ;
   bool aJour ;
   int nombreAretesIncidentes ;
};





//*****************************************************************************
//
// Module	: TopoAretesP
//
// Fichier	: TopoAretesP.h
//
// Auteur	: regain
//
// Date creat.	: Fri Feb 21 14:42:26 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe TopoAretesP.
//
//
//*****************************************************************************
// Includes
// Classe TopoAretesP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************




//*****************************************************************************
//
// Classe TopoAretesP
//
//*****************************************************************************

class BREPP_DLL TopoAretesP	: public TopologiesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	TopoAretesP () ;
	TopoAretesP (const TopoAretesP &) ;

	TopoAretesP (const SommetsP &S1, const SommetsP &S2, bool C) ;

	~TopoAretesP () ;

//*****************************************************************************
//	Consultation
//*****************************************************************************
inline const SommetsP& 	Sommet1 () 				const ;
inline const SommetsP& 	Sommet2 () 				const ;
inline 	const ContoursP& 	Contour1 () 				const ;
inline 	const ContoursP& 	Contour2 () 				const ;
inline 	const AretesP& 		AreteSuivanteDansContour1 () 		const ;
inline 	const AretesP& 		AreteSuivanteDansContour2 () 		const ;
inline 	const AretesP& 		AretePrecedenteDansContour1 () 		const ;
inline 	const AretesP& 		AretePrecedenteDansContour2 () 		const ;

inline 	const AretesOrienteesP&	AreteOrienteePositive()			const;
inline 	const AretesOrienteesP&	AreteOrienteeNegative()			const;

	const FacesP&		Face1 () 				const ;
	const FacesP&		Face2 () 				const ;

inline 	bool			Continuite()				const;
	bool			EstIsolee (void) 			const ;

inline	TopologiesBRep*		Dupliquer()				const ;

//*****************************************************************************
//	Modification
//*****************************************************************************
inline SommetsP* 		PtrSommet1 ()  ;
inline SommetsP* 		PtrSommet2 ()  ;
inline ContoursP* 		PtrContour1 ()  ;
inline ContoursP* 		PtrContour2 ()  ;
inline AretesP* 		PtrAreteSuivanteDansContour1 ()  ;
inline AretesP* 		PtrAreteSuivanteDansContour2 ()  ;
inline AretesP* 		PtrAretePrecedenteDansContour1 ()  ;
inline AretesP* 		PtrAretePrecedenteDansContour2 ()  ;
inline AretesOrienteesP *	PtrAreteOrienteePositive() ;
inline AretesOrienteesP *	PtrAreteOrienteeNegative() ;
	FacesP*			PtrFace1 () ;
	FacesP*			PtrFace2 () ;

//*****************************************************************************
//	Remplacement
//*****************************************************************************
inline 	void 			ModifSommet1 (const SommetsP &P) 	;
inline 	void 			ModifSommet2 (const SommetsP &P) 	;
inline 	void 			ModifContour1 (const ContoursP &C) 	;
inline 	void 			ModifContour2 (const ContoursP &C) 	;
	void 			ModifAreteSuivanteDansContour1 (const AretesP &A) ;
	void 			ModifAreteSuivanteDansContour2 (const AretesP &A) ;
	void 			ModifAretePrecedenteDansContour1 (const AretesP &A);
	void 			ModifAretePrecedenteDansContour2 (const AretesP &A);

inline void 			ModifAreteSuivante1 (const AretesP &A) ;
inline void 			ModifAreteSuivante2 (const AretesP &A) ;
inline void 			ModifAretePrecedente1 (const AretesP &A);
inline void 			ModifAretePrecedente2 (const AretesP &A);

inline void 			ModifContinuite(bool)			;

//*****************************************************************************
//	Methodes
//*****************************************************************************
	void			CreerAretesOrienteesAssociees(const AretesP &A);

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const TopoAretesP& operator = (const TopoAretesP &) ;

	friend 	ostream& BREPP_DLL operator << (ostream &, const TopoAretesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :
	AretesOrienteesP		areteOrienteePositive ;
	AretesOrienteesP		areteOrienteeNegative ;
	ContoursP			contour1, contour2 ;
	SommetsP			sommet1, sommet2 ;
	AretesP				areteSuivante1, aretePrecedente1 ;
	AretesP				areteSuivante2, aretePrecedente2 ;
	bool				continuite;
};





//*****************************************************************************
//
// Module	: TopoAretesOrienteesP
//
// Fichier	: TopoAretesOrienteesP.h
//
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 15:15:47 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe TopoAretesOrienteesP.
//
//
//*****************************************************************************
// Includes
// Classe TopoAretesOrienteesP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************




//*****************************************************************************
//
// Classe TopoAretesOrienteesP
//
//*****************************************************************************

class BREPP_DLL TopoAretesOrienteesP : public TopologiesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	TopoAretesOrienteesP () ;
	TopoAretesOrienteesP (const TopoAretesOrienteesP &) ;

	TopoAretesOrienteesP::TopoAretesOrienteesP (	const AretesP &A,
							const bool &Sens) ;

	~TopoAretesOrienteesP () ;


//*****************************************************************************
//	Methodes
//*****************************************************************************
inline 	bool							Sens()					const;

inline 	const SommetsP				Origine()				const;
inline 	SommetsP *					PtrOrigine() ;
inline 	const SommetsP				Extremite()				const;
inline 	const AretesP&				Arete()					const;
inline 	AretesP *					PtrArete ()				;
inline 	const ContoursP			Contour()				const;

	const AretesOrienteesP	AreteOrienteeSuivanteDansContour()				const;
	const AretesOrienteesP	AreteOrienteePrecedenteDansContour()			const;

	const AretesOrienteesP 	AreteOrienteeOpposee()						const;
	AretesOrienteesP * 		PtrAreteOrienteeOpposee () 		;

	void			ModifOrigine(const SommetsP&);
	void			ModifExtremite(const SommetsP&);
	void			ModifContour(const ContoursP&);

	// Modifie l'arête suivante(resp- precedente) dans le contour avec mise à
	// jour de la topologie du contour
	void			ModifAreteOrienteeSuivanteDansContour(const AretesOrienteesP&);
	void			ModifAreteOrienteePrecedenteDansContour(const AretesOrienteesP&);

	// Modifie l'arête suivante(resp- precedente) dans le contour sans mise à
	// jour de la topologie du contour
	void			ModifAreteOrienteeSuivante(const AretesOrienteesP&);
	void			ModifAreteOrienteePrecedente(const AretesOrienteesP&);

	void 			SortirDuContour () ;

inline	TopologiesBRep*		Dupliquer()				const ;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const TopoAretesOrienteesP& 	operator = (const TopoAretesOrienteesP &) ;

	friend 	ostream& BREPP_DLL 		operator << (ostream &, const TopoAretesOrienteesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :
	AretesP				arete;
	bool				sens;
};





//*****************************************************************************
// 
// Module	: TopoContoursP
// 
// Fichier	: TopoContoursP.h
// 
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 15:43:08 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe TopoContoursP.
// 
// 
//*****************************************************************************
// Includes
// Classe TopoContoursP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************


//*****************************************************************************
//
// Classe TopoContoursP
//
//*****************************************************************************

class BREPP_DLL TopoContoursP : public TopologiesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	TopoContoursP () ;
	TopoContoursP (const TopoContoursP &) ;

	TopoContoursP (const Listes<AretesP>& , ContoursP) ;
	TopoContoursP (const Listes<AretesOrienteesP> &, ContoursP) ;
   TopoContoursP (const Tableaux<AretesP>& , ContoursP ) ;
   TopoContoursP (const Tableaux<AretesOrienteesP>&, ContoursP ) ;

	~TopoContoursP () ;

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
	void	AjouterArete (AretesP , ContoursP) 	;
   void 	AjouterAretes ( const Listes<AretesP>& , ContoursP ) ;
   void	AjouterAretes ( const Tableaux<AretesP>& , ContoursP ) ;
   void	AjouterAretesOrientees ( const Listes<AretesOrienteesP>& , ContoursP ) ;
   void	AjouterAretesOrientees ( const Tableaux<AretesOrienteesP>& , ContoursP ) ;
inline    void						SortirAreteOrientee (const AretesOrienteesP& ) ;
   void 						ModifAreteSuivante (const AretesOrienteesP& Pos,const AretesP& Suiv) ;
   void 						ModifAretePrecedente (const AretesOrienteesP& Pos,const AretesP& Prec) ;
	Listes<AretesP>		ListeAretes () 											const ;
   Tableaux<AretesP>		TableauAretes ()												const ;
inline 	int			NombreAretes () 											const ;
	// ATTENTION : la premiere arete a le numéro 0 !!
	const AretesP  		IemeArete (const int) 									const ;
	AretesP *				PtrIemeArete (const int)		;

	void						AjouterAreteOrientee (AretesOrienteesP, ContoursP);

	// L'arête insérée est insérée à la position demandée puis chaînée aux
	// (i-1)ème et (i+1)ème arêtes orientées.
	// La première AO a le numéro 0
	void 						InsererAreteOrientee ( int , AretesOrienteesP ) ;

	// ATTENTION : la premiere arete orientee a le numéro 0 !!
   void 						RemplacerAreteOrientee ( int , AretesOrienteesP , const ContoursP& ) ;

	// Retrait d'une arete. L'arête n'est pas détruite.
	// Une partie des chaînages de l'arête et du contour est supprimée.
	void	RetirerArete (AretesP A, ContoursP Cont) ;
	void	RetirerAreteOrientee (AretesOrienteesP AO, ContoursP Cont) ;

	// Retrait d'une arete de rang i (la première a le numéro 0).
	// L'arête n'est pas détruite.
	// Si i < 0 ou >= NbAretes, il est ramené dans l'intervalle
	// Une partie des chaînages de l'arête et du contour est supprimée.
	void	RetirerArete (int i, ContoursP Cont) ;
	void	RetirerAreteOrientee (int i, ContoursP Cont) ;

inline	Listes<AretesOrienteesP> 	ListeAretesOrientees () 					  	const ;
inline    const Tableaux<AretesOrienteesP>&	TableauAretesOrientees ()							const ;
inline 	int								NombreAretesOrientees () 						const ;
	// ATTENTION : la premiere arete orientee a le numéro 0 !!
	const AretesOrienteesP		IemeAreteOrientee (const int) 				const ;
	AretesOrienteesP *			PtrIemeAreteOrientee (const int)	;
inline    const FacesP & 				Face () 												const ;
inline 	FacesP *							PtrFace ()				;
inline 	void 								ModifFace (const FacesP&);
inline 	const Vecteurs3D  			VecteurNormal () 									const ;

//*****************************************************************************
//	Methodes
//*****************************************************************************
inline	TopologiesBRep*		Dupliquer()				const ;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const TopoContoursP& 	operator = (const TopoContoursP &) ;

	friend 	ostream& BREPP_DLL 	operator << (ostream &, const TopoContoursP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :
//	AretesOrienteesP 	premierearete ;
	Tableaux<AretesOrienteesP> tabAretesOrientees ;
	FacesP 			face ;

};





//*****************************************************************************
//
// Module	: TopoFacesP
//
// Fichier	: TopoFacesP.h
//
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 15:22:25 MET 1997
// 
// Version	:
//
// Commentaires	: Interface de la classe TopoFacesP.
//
// 
//*****************************************************************************
// Includes
// Classe TopoFacesP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************




//*****************************************************************************
//
// Classe TopoFacesP
//
//*****************************************************************************
class BREPP_DLL TopoFacesP : public TopologiesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	TopoFacesP () ;
	TopoFacesP (const TopoFacesP &) ;

	TopoFacesP (const ContoursP &) ;
	TopoFacesP (const Listes<ContoursP> &) ;
   TopoFacesP (const Tableaux<ContoursP> &) ;

	~TopoFacesP () ;

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline 	void								AjouterContourInterieur (const ContoursP &)   ;
inline 	void								RetirerContourInterieur (const ContoursP &)   ;
inline 	const int						NombreContoursInterieurs () 					const ;
// ATTENTION : le premier CI a le numéro 0 !!
inline 	const ContoursP 				IemeContourInterieur (const int) 			const ;
inline 	ContoursP *						PtrIemeContourInterieur (const int)	      ;
inline 	const ContoursP 				ContourExterieur () 								const ;
inline 	ContoursP *						PtrContourExterieur ()		              ;
			const Listes<ContoursP> 	ListeContoursInterieurs ()						const ;
   		const Tableaux<ContoursP>  TableauContoursInterieurs ()					const ;
inline	const SolidesP 				Solide ()											const ;
inline 	SolidesP *						PtrSolide ()				      ;
inline	void								ModifSolide (const SolidesP &)		;

//*****************************************************************************
//	Methodes
//*****************************************************************************
	Listes<SommetsP>				ListeSommets ()									const ;
   Tableaux<SommetsP>			TableauSommets ()									const ;
inline	const int						NombreSommets () 									const ;
	// ATTENTION : le premier sommet a le numéro 0 !!
		 	const SommetsP					IemeSommet (const int)							const ;

inline	TopologiesBRep*				Dupliquer()											const ;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const TopoFacesP& operator = (const TopoFacesP &) ;

	friend 	ostream& BREPP_DLL operator << (ostream &, const TopoFacesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :
	Tableaux<ContoursP> 	TContours ;
	SolidesP 		Sol ;
};





//*****************************************************************************
//
// Module	: TopoSolidesP
//
// Fichier	: TopoSolidesP.h
//
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 14:35:31 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe TopoSolidesP.
//
//
//*****************************************************************************
// Includes
// Classe TopoSolidesP
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************


//*****************************************************************************
//
// Classe TopoSolidesP
//
//*****************************************************************************
class BREPP_DLL TopoSolidesP : public TopologiesBRep
{
public :
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	TopoSolidesP () ;
	TopoSolidesP (const TopoSolidesP &) ;

	TopoSolidesP (const Listes<FacesP> &) ;
   TopoSolidesP ( const Tableaux<FacesP> & ) ;

	~TopoSolidesP () ;

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline	void 							AjouterFace (FacesP &)		;
	void							RetirerFace (FacesP & F)	;
inline 	void 							AjouterFaces ( const Listes<FacesP>&) ;
inline 	void 							AjouterFaces ( const Tableaux<FacesP>&) ;
inline  	int							NombreFaces ()								const ;
// ATTENTION : la premiere face a le numéro 0 !!
inline	const FacesP 				IemeFace (const int)		const ;
inline	FacesP *						PtrIemeFace (const int)			;
inline	const Listes<FacesP>		ListeFaces ()								const ;
inline   const Tableaux<FacesP>&	TableauFaces ()							const ;

//*****************************************************************************
//	Methodes
//*****************************************************************************
	const Listes<AretesP> 		ListeAretes ()							const ;
   const Tableaux<AretesP>		TableauAretes ()						const ;
inline 	int						NombreAretes ()						const ;
// ATTENTION : la premiere arete a le numéro 0 !!
	const AretesP 					IemeArete (const int)		const ;
	const Listes<SommetsP>		ListeSommets ()	 					const ;
   const Tableaux<SommetsP>	TableauSommets ()						const ;
inline	int								NombreSommets ()						const ;
// ATTENTION : le premier sommet a le numéro 0 !!
	const SommetsP 				IemeSommet (int)		const ;

inline	TopologiesBRep*				Dupliquer()								const ;

//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const TopoSolidesP& operator = (const TopoSolidesP &) ;

	friend 	ostream& BREPP_DLL operator << (ostream &, const TopoSolidesP &) ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private :
		Tableaux<FacesP> TFaces ;
};

#include "TopoSommetsP.inl"
#include "TopoAretesP.inl"
#include "TopoAretesOrientees.inl"
#include "TopoContoursP.inl"
#include "TopoFacesP.inl"
#include "TopoSolidesP.inl"



#endif __TopologiesP__h__
