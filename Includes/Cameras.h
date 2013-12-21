//*******************************************************************
//
// Fichier	: Cameras.h
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Interface de la classe Cameras
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_Cameras_h_
#define	_Cameras_h_


#include	"BibliothequeMathematique.h"

#include	<iostream>
using namespace std ;
#include	"EnteteVisualiseurDLL.h"


class VISUALISEUR_DLL Cameras
 {
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	Cameras();
	Cameras(const Cameras&);

	Cameras (const Points3D& Obs, const Points3D& Mire, double DF);

	~Cameras();

//*******************************************************************
//	Accesseurs
//*******************************************************************
inline	const Points3D&	Observateur ()											const;
inline	void					ModifObservateur (const Points3D& Obs);

inline	const Points3D&	Mire ()													const;
inline	void					ModifMire (const Points3D& M);

inline	Vecteurs3D	    DirectionVisee ()										const;
inline	void					ModifDirectionVisee (const Vecteurs3D& Dir);

inline	double				DistanceFocale ()										const;
inline	void					ModifDistanceFocale (double Dist);

inline	const Vecteurs3D&	VecteurDebout()										const;
inline	void					ModifVecteurDebout(const Vecteurs3D&);

//*******************************************************************
//	Methodes
//*******************************************************************
Vecteurs3D		TransformerPointEcran (int x, int y)		const;
Points3D		TransformerPointMonde (const Points3D& P)	const;

//*******************************************************************
//	Operateurs
//*******************************************************************
	const Cameras&	operator = (const Cameras&);

friend	ostream& VISUALISEUR_DLL	operator<< (ostream&, const Cameras&);

//*******************************************************************
//	Partie privee
//*******************************************************************
private:

	Reperes3D	_Repere;
	Points3D		_Mire;
	double		_DistanceFocale;
   Vecteurs3D	_Debout;

};


#include	"Cameras.inl"

#endif

