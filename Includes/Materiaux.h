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
//	- 5 aout 1998	Int�gration de la texture
//	- 7 mars 2011	On interdit la duplication des mat�riaux pour �viter leur prolif�ration
//					et obliger � les r�f�rencer plut�t que de les copier.
//					Cons�quences :
//						Pour obtenir un mat�riaux, fournir ses caract�ristiques � la fonction
//						CreerMateriau qui restitue un pointeur sur le mat�riau s'il existe
//						d�j� et, sinon, qui le cr�e et restitue son adresse.
//
// Commentaires	: Interface de la classe Materiaux.
//		La texture est champ suppl�mentaire (un pointeur) qu'il faut mettre � jour
//		gr�ce aux accesseurs appropri�s.
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

// Ces 2 fonctions testent si le mat�riau existe d�j� et, sinon, elles le cr�e.
// Ensuite, son adresse est restitu�.
static const Materiaux *		CreerMateriau (const char*);			// Fichier preenregistre
static const Materiaux *		CreerMateriau (const Materiaux&);
static const Materiaux *		CreerMateriau (	const Couleurs*, 
										double Ka, double Kd, double Ks, double Kt, 
										double Ns, double Nt);
static const Materiaux *		CreerMateriau (	const Couleurs*);

// Destruction (et lib�ration de la m�moire occup�e) de tous les mat�riaux
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
	// Je mets tout �a en priv� pour en interdire l'utilisation. Dor�navant,
	// les mat�riaux ne sont plus ni copi�s ni modifi�s, pour �viter leur
	// multiplication : on cr�e un petit nombre de mat�riaux pr�d�finis et
	// ils sont r�f�renc�s partout o� ils sont utiles au lieu d'�tre dupliqu�s
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
