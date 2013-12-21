//*******************************************************************
//
// Fichier	: Vues.h
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Interface de la classe Vues
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_Vues_h_
#define	_Vues_h_


#include	"Cameras.h"
#include	"AlgosVisu.h"
#include	"Images.h"
#include	"Scenes.h"
#include	"Studios.h"

#include	<iostream>
using namespace std ;
#include	"EnteteVisualiseurDLL.h"


class VISUALISEUR_DLL Vues
 {
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	Vues();
	~Vues();

//*******************************************************************
//	Accesseurs
//*******************************************************************
inline	const char*	Nom ()					const;
inline	void			ModifNom (const char* N);

inline	AlgosVisu*	PtrAlgoVisu ();
inline	void			ModifAlgoVisu (AlgosVisu* A);

inline	const Cameras&	Camera ()				const;
inline	void				ModifCamera (const Cameras& C);
inline	bool				EstCameraModifiee ()		const;

inline	const Studios&	Studio ()				const;
inline	void				ModifStudio (const Studios& S);
inline	bool				EstStudioModifie ()		const;

inline	const Scenes&		Scene ()				const;
inline	Scenes&				Scene () ;
inline	void				ModifScene (const Scenes& S);
inline	bool				EstSceneModifiee ()		const;

inline	const Images&	Image ()				const;
inline	void				ModifImage (const Images& I);
inline	bool				EstImageModifiee ()		const;

inline	void				MettreAJourEtat();

inline   double         TempsCPU()			const;

//*******************************************************************
//	Methodes
//*******************************************************************
	void		CalculerImage ();

//*******************************************************************
//	Operateurs
//*******************************************************************
friend	ostream& VISUALISEUR_DLL	operator<< (ostream&, const Vues&);

//*******************************************************************
//	Partie privee
//*******************************************************************
private:

	char*	_Nom;
	double	_TempsUtilisateur;
	double	_TempsCPU;
	Images	_Image;
	Scenes	_Scene;
	Cameras	_Camera;
	AlgosVisu	*_AlgoVisu;
	Studios	_Studio;

	// L'etat permet de connaitre le ou lesquels des composants de la
	// vue a ou ont ete modifié depuis le dernier calcul d'image
	int	Etat;


//-------------------------------------------------------------------
// Méthodes déclarées privées pour en interdire l'utilisation
//-------------------------------------------------------------------
	Vues(const Vues&);
	const Vues&	operator = (const Vues&);
};


#include	"Vues.inl"

#endif

