//*******************************************************************
//
// Fichier	: PolygonesVisualisablesZBuffer.h
//
// Auteur	: Y. Lanuel
//
// Date		: 14 Octobre 1997
//
// Commentaires	: Interface de la classe PolygonesVisualisablesZBuffer
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_PolygonesVisualisablesZBuffer_h_
#define	_PolygonesVisualisablesZBuffer_h_


#include	"BibliothequeVisualiseur.h"

#include	"EnteteZBufferDLL.h"

#include	<iostream> 
using namespace std ;


class ZBUFFER_DLL PolygonesVisualisablesZBuffer	: public ObjetsVisualisables
{
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	PolygonesVisualisablesZBuffer();
	~PolygonesVisualisablesZBuffer();

//*******************************************************************
//	Methodes
//*******************************************************************
virtual	const 		Points3D&	IemePoint (int i)			const	= 0;
virtual	Vecteurs3D	Normale (const Points3D&)				const	= 0;
virtual	int			NbPoints ()									const	= 0;
virtual	Plans3D		Plan()												= 0;

//*******************************************************************
//	Operateurs
//*******************************************************************

//*******************************************************************
//	Partie privee
//*******************************************************************
private:

//-------------------------------------------------------------------
// Méthodes déclarées privées pour en interdire l'utilisation
//-------------------------------------------------------------------
	PolygonesVisualisablesZBuffer(const PolygonesVisualisablesZBuffer&);
	const PolygonesVisualisablesZBuffer&	operator = (const PolygonesVisualisablesZBuffer&);

};


#include	"PolygonesVisualisablesZBuffer.inl"

#endif

