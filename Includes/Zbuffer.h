//*******************************************************************
//
// Fichier	: ZBuffer.h
//
// Auteur	: Y. Lanuel
//
// Date		: 14 Octobre 1997
//
// Commentaires	: Interface de la classe ZBuffer
//
//*******************************************************************
// Methodes
//	ModifFenetreAffichage(TClientDC*)
//      ModeFilDeFer()
//	ModeLignesCachees()
//	CalculerImage()
//*******************************************************************


#ifndef	_ZBuffer_h_
#define	_ZBuffer_h_

#include	"BibliothequeVisualiseur.h"
#include	"PolygonesVisualisablesZBuffer.h"
#include	"SolidesVisualisablesZBuffer.h"

#include	"EnteteZBufferDLL.h"

#include	<iostream> 
using namespace std ;


class ZBUFFER_DLL ZBuffer	: public AlgosVisu
 {
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	ZBuffer();
	~ZBuffer();

//*******************************************************************
//	Methodes
//*******************************************************************
	void	ModifFenetreAffichage(HDC);
//	void	ModifFenetreAffichage(HWND C);

	void	CalculerImage ();

inline	void	ModeFilDeFer ();
inline	void	ModeLignesCachees ();
inline	void	ModeTache ();
inline	void	ModeEclaire ();


	void	InitialiserCloture(int l, int h);

	// Ajout Christian le 19 août 2002.
	// Voir explications plus bas
	void	ActiverExploitationFacesArrieres () ;
	void	DesactiverExploitationFacesArrieres () ;

	// Distance de l'oeil aux plans de clipping avant et arrière lorsqu'on
   // va de l'oeil vers la mire.
   // Ces distances doivent être >= 0 et la deuxième doit être strictement
   // supérieure à la première.
   // Si DistAv < 0, elle est ramenée à 0.
   // Si DistAr <= DistAv, elle est ramenée à DistAv + 10
   void	FixerEloignementPlansClippingAvantArriere (double DistAv, double DistAr) ;

//*******************************************************************
//	Partie privee
//*******************************************************************
private:

	int		_Mode;
	bool		_ChangementMode;
	int		_Largeur, _Hauteur;

   double	EloignementPlanClippingAvant ;
   double	EloignementPlanClippingArriere ;

	Vecteurs3D	CouleurFond;

   //PolygonesVisualisablesZBuffer		**T1,**T2;
   int										Nb;

	// Ajout Christian le 19 août 2002.
	// Ce booléen permet d'activer ou d'inhiber l'optimisation apportée
	// par les faces arrières : quand on affiche autre chose que des
	// solides, par exemple des ensembles de faces, il faut autoriser
	// d'afficher les faces dont les normales s'éloignent car elles sont
	// parfois visibles.
	//
	// Par défaut, l'optimisation est activée.
	bool	ActiverTestFacesArrieres ;


//*******************************************************************
//	Méthodes particulières
//*******************************************************************
	bool	InitialiserFormat(HDC);
	void	InitialiserContexteZBuffer(HDC);

	void	Afficher();
	void	ConstruireStudioZBuffer();
	void	ConstruireViseeZBuffer();
	void	ConstruireSceneZBuffer();
   void	ConstruirePolygone(PolygonesVisualisablesZBuffer *P);
   void	ConstruireSolide(SolidesVisualisablesZBuffer *S);
   void 	ConstruirePolygoneLigne(PolygonesVisualisablesZBuffer *P);
   void 	ConstruirePolygoneLigneCache(PolygonesVisualisablesZBuffer *P);
   void 	ConstruirePolygoneTache(PolygonesVisualisablesZBuffer *P);
   void 	ConstruirePolygoneEclaire(PolygonesVisualisablesZBuffer *P);
   void 	ConstruirePolygoneTexture(PolygonesVisualisablesZBuffer *P);

	HDC 			contexte;
   HGLRC			Gl;

//-------------------------------------------------------------------
// Méthodes déclarées privées pour en interdire l'utilisation
//-------------------------------------------------------------------
	ZBuffer(const ZBuffer&);
	const ZBuffer&		operator = (const ZBuffer&);

friend	ostream& ZBUFFER_DLL	operator<< (ostream&, const ZBuffer&);
};


#include	"ZBuffer.inl"

#endif

