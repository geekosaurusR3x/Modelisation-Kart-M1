//*****************************************************************************
//
// Module	: Materiaux
//
// Fichier	: Materiaux.h
//
// Auteur	: lanuel
//
// Date creat.	: Tue Jul  9 17:00:15 MET DST 1996
//
// Modifications : 
//	- 5 aout 1998	Intégration de la texture
//	- 7 mars 2011	On interdit la duplication des matériaux pour éviter leur prolifération
//					et obliger à les référencer plutôt que de les copier.
//					Conséquences :
//						Pour obtenir un matériaux, fournir ses caractéristiques à la fonction
//						CreerMateriau qui restitue un pointeur sur le matériau s'il existe
//						déjà et, sinon, qui le crée et restitue son adresse.
//
// Commentaires	: Interface de la classe Materiaux.
//		La texture est champ supplémentaire (un pointeur) qu'il faut mettre à jour
//		grâce aux accesseurs appropriés.
//
//*****************************************************************************

#ifndef __Materiaux__h__
#define __Materiaux__h__



//*****************************************************************************
//
// Includes
//
//*****************************************************************************

#include	"BibliothequeMathematique.h"

#include	"EnteteVisualiseurDLL.h"
#include	"Textures.h"

#include	<iostream>
using namespace std ;



class	VISUALISEUR_DLL Couleurs;


//*****************************************************************************
//
// Classe Materiaux
//
//*****************************************************************************
class VISUALISEUR_DLL Materiaux
{
public:
//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************
	Materiaux();
	~Materiaux();


//*****************************************************************************
//	Accesseurs
//*****************************************************************************

// Ces 2 fonctions testent si le matériau existe déjà et, sinon, elles le crée.
// Ensuite, son adresse est restitué.
static const Materiaux *		CreerMateriau (const char*);			// Fichier preenregistre
static const Materiaux *		CreerMateriau (const Materiaux&);
static const Materiaux *		CreerMateriau (	const Couleurs*, 
										double Ka, double Kd, double Ks, double Kt, 
										double Ns, double Nt);
static const Materiaux *		CreerMateriau (	const Couleurs*);

// Destruction (et libération de la mémoire occupée) de tous les matériaux
static void DetruireMateriaux () ;

inline 	const char*				Nom()		const;
inline 	const Couleurs*		PtrCouleur()	const;
inline	double			CoefficientAmbiant()				const;
inline	double			CoefficientDiffus()				const;
inline	double			CoefficientSpeculaire()			const;
inline	double			CoefficientTransparence()		const;
inline	double			IndiceReflexion()					const;
inline	double			IndiceRefraction()				const;
inline	const Textures*			Texture()						const;
inline 	double			Ka()		const;	// Coef Ambiant
inline 	double			Kd()		const;	// Coef Diffus
inline 	double			Ks()		const;	// Coef Spec
inline 	double			Kt()		const;	// Coef Transparence
inline 	double			Ns()		const;	// Indice speculaire
inline 	double			Ro()		const;
inline 	double			nr()		const;
inline 	double			nt()		const;   // Indice refraction
inline 	double			k()		const;
inline 	double			m()		const;

inline 	bool			Conducteur()	const;
inline 	bool			Transparent()	const;
inline 	bool			Reflechissant()	const;

inline 	const Couleurs&		Couleur()	const;
inline 	const Materiaux&		Caracteristiques(Couleurs* coul,
	double Ka, double Kd, double Ks, double Kt, double Ns, double Nr);

static	void	Chemin(const char*);


//*****************************************************************************
//	Methodes
//*****************************************************************************


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	friend	ostream& 	VISUALISEUR_DLL operator << (ostream&, const Materiaux&);
	friend	istream&  	VISUALISEUR_DLL operator >> (istream&, Materiaux&);

	bool operator == (const Materiaux &M2) const ;

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:
	// Christian le 7-03-2011
	// Je mets tout ça en privé pour en interdire l'utilisation. Dorénavant,
	// les matériaux ne sont plus ni copiés ni modifiés, pour éviter leur
	// multiplication : on crée un petit nombre de matériaux prédéfinis et
	// ils sont référencés partout où ils sont utiles au lieu d'être dupliqués
	Materiaux(const Materiaux&);
	Materiaux(const char*);			// Fichier preenregistre
	Materiaux(const Couleurs*, double Ka, double Kd, double Ks, double Kt, double Ns, double Nt);
	void						ModifCouleur(const Couleurs*);
	inline	void				ModifCoefAmbiant(double)			;
	inline	void				ModifCoefDiffus(double)				;
	inline	void				ModifCoefSpeculaire(double)		;
	inline	void				ModifCoefTransparence(double)		;
	inline	void				ModifIndiceReflexion(double)		;
	inline	void				ModifIndiceRefraction(double)		;
	inline	void				ModifTexture(Textures*)				;
	const	Materiaux&	operator =  (const Materiaux&);

	char*	nom;

	Couleurs*	c;

	double	ka,
				kd,
				ks,
				kt,

				ns,

				ro,

				nrefl,
				ntrans,
				kabs,

				mrugosite;

	bool		conducteur,
				transparent,
				reflechissant;


	void	F_Approx_n(double* n, double *ro);
	void	F_Approx_k(double* k, double *ro);

	Textures	*texture;


static	char	chemin[200];


};



#include	"Materiaux.inl"



#endif	__Materiaux__h__
