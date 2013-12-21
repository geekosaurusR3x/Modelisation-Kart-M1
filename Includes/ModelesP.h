//*****************************************************************************
//
// Module	: ModelesP
//
// Fichier	: ModelesP.h
//
// Auteur	: regain
//
// Date creat.	: Tue Feb 18 13:52:05 MET 1997
//
// Version	:
//
// Commentaires	: Interface de la classe ModelesP.
//
//*****************************************************************************

#ifndef __ModelesP__h__
#define	__ModelesP__h__

//#include	<vcl.h>			// pour que l'inclusion de iostream ci-dessous n'amène pas plein de pbs

#include	"EnteteBRepPDLL.h"
#include	"IdentifiantsP.h"
#include	"Points3D.h"
#include	"TypeCle.h"
#include	"Listes.h"
#include	"TablesEfficaces.h"
#include	<iostream>
using namespace std ;


class BREPP_DLL 		SommetsP;
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
class BREPP_DLL		ModelesP;


typedef void (*ProcedureSauvegarde)(const char*, const ModelesP&);



//*****************************************************************************
//
// Classe ModelesP
//
//*****************************************************************************

class BREPP_DLL ModelesP
{

public :
	ModelesP (const Points3D & P1, const Points3D & P2) ;
	~ModelesP () ;

	// Fonctions d'ajout d'une entité dans le modèle. Ce sont ces
   // fonctions qui attribuent les clés
	RepSommetsP*			AjouterSommet(RepSommetsP*);
	RepAretesP*				AjouterArete(RepAretesP*);
	RepAretesOrienteesP*	AjouterAreteOrientee(RepAretesOrienteesP*);
	RepContoursP*			AjouterContour(RepContoursP*);
	RepFacesP*				AjouterFace(RepFacesP*);
	RepSolidesP*			AjouterSolide(RepSolidesP*);

	// Ces fonctions retirent du modèle les représentations qu'on leur
   // passe et les désallouent.
	void			DetruireSommet(const SommetsP&);
	void			DetruireArete(const AretesP&);
	void			DetruireAreteOrientee(const AretesOrienteesP&);
	void			DetruireContour(const ContoursP&);
	void			DetruireFace(const FacesP&);
	void			DetruireSolide(const SolidesP&);

	SolidesP		RechercherSolideParCle (const TypeCle) ;
	FacesP		RechercherFaceParCle (const TypeCle) ;
	ContoursP	RechercherContourParCle (const TypeCle) ;
	AretesP		RechercherAreteParCle (const TypeCle) ;
	SommetsP		RechercherSommetParCle (const TypeCle) ;

   // Restitue la liste des solides du BRep. Moins efficace que la fct
   // suivante à cause des copies de listes.
	Listes<SolidesP>	ListeSolides()			;

	// Initialise L avec la liste des solides du BRep.
	// L'ancien contenu de la liste est perdu.
	void					ListeSolides(Listes<SolidesP> &L)			const;

   // Restitue la liste des arêtes du BRep. Moins efficace que la fct
   // suivante à cause des copies de listes.
	Listes<AretesP>	ListeAretes()			const;

	// Initialise L avec la liste des arêtes du BRep.
	// L'ancien contenu de la liste est perdu.
	void	ListeAretes(Listes<AretesP> &L)	const ;

   // Restitue une liste avec toutes les faces qui n'appartiennent
   // pas à un solide
	// L'ancien contenu de la liste est perdu.
   // Attention : cette fonction provoque un parcours de TOUTES les faces
   // stockées dans le modèle !
   void  ListeFacesIsolees (Listes <FacesP> *LF)	const ;

	// Restitue une liste LFS avec toutes les faces qui n'appartiennent
	// pas à un solide et une autre liste LFI de toutes les faces qui n'appartiennent
	// pas à un solide (faces isolées).
	// L'ancien contenu des listes est perdu.
	// Attention : cette fonction provoque un parcours de TOUTES les faces
	// stockées dans le modèle !
	void ListesFaces (Listes <FacesP> *LFS, Listes <FacesP> *LFI)	const ;

	void	Vider () ;

	// Chargement d'un fichier au format REGAIN. Si le booléen est vrai
	// le précédent contenu du modèle est perdu, sinon, ce qui est chargé est
	// ajouté à ce qui est présent.
	void	Chargement(const char* NomDuFichier, bool Remplacement = true);

	// Sauvegarde le modèle en fichier au format REGAIN
	void	Sauvegarde(const char* NomDuFichier);

	void	ModifProcSauvegardeSpecifique(ProcedureSauvegarde);
	void	SauvegardeSpecifique(const char* Nom)	const;

	static	ModelesP *	Defaut();
	static	void		ModifDefaut(ModelesP&);

	void		ModifTailleEspaceUtilisateur (const Points3D P1, const Points3D & P2) ;
	// Autorisée seulement si aucun objet n'a encore été stocké dans le modèle !!

	double	PrecisionProximite () ;
	// valeur en deça de laquelle deux points sont considérés superposés

	void CoinsEspaceUtilisateur (Points3D *Pmin,Points3D *Pmax) ;

   void AutoriserMessagesErreur () ;
   void InterdireMessagesErreur () ;
   bool MessagesErreurSontAutorises () ;

	friend 	ostream& BREPP_DLL 	operator << (ostream &, const ModelesP &) ;


private :
	ModelesP (const ModelesP &) ;
	const ModelesP& 	operator = (const ModelesP &) ;

	// On conserve une table par type d'entité (solide, face etc). La table
   // est indexée par les clés des entités du BRep et chaque élément de la
   // table est un pointeur sur la représentation de cet élément.
   // Chaque table est donc un ensemble de couples
   //					(clé,pointeur sur la représentation)
   // cet ensemble étant triée sur les clés. Les accès sont tous en temps
   // logarithmique.
	TablesEfficaces <TypeCle>			SommetsCrees ;
	TablesEfficaces <TypeCle>			AretesCreees ;
   TablesEfficaces <TypeCle>			AretesOrienteesCreees ;
   TablesEfficaces <TypeCle>			ContoursCrees ;
   TablesEfficaces <TypeCle>			FacesCreees ;
   TablesEfficaces <TypeCle>			SolidesCrees ;

	// données nécessaires à une bonne gestion de la proximité dans l'espace réel
	Points3D						pointMin, pointMax ;
	double						precisionProximite ;
	bool							EspaceUtilisateurEstDefini ;

   bool							messagesErreurSontAutorises ;

	ProcedureSauvegarde		Sauve;

	void ConstruireListes(	Listes<RepSommetsP*> &LSommets,
   								Listes<RepAretesP*> &LAretes,
   								Listes<RepContoursP*> &LContours,
								   Listes<RepFacesP*> &LFaces,
								   Listes<RepSolidesP*> &LSolides) ;

	void	SauvegardeSolides(ofstream&,const Listes<RepSolidesP*> &LSolides)		const;
	void	SauvegardeFaces(ofstream&,const Listes<RepFacesP*> &LFaces)				const;
	void	SauvegardeContours(ofstream&,const Listes<RepContoursP*> &LContours)	const;
	void	SauvegardeAretes(ofstream&,const Listes<RepAretesP*> &LAretes)			const;
	void	SauvegardeSommets(ofstream&,const Listes<RepSommetsP*> &LSommets)		const;

	void	ChargementSolides(ifstream&);
	void	ChargementFaces(ifstream&);
	void	ChargementContours(ifstream&,Listes<ContoursP>&,Listes<Listes<AretesP>*>&) ;
	void	ChargementAretes(ifstream&,Listes<RepAretesP*>&);
	void	ChargementSommets(ifstream&);
};

#endif	__ModelesP__h__
