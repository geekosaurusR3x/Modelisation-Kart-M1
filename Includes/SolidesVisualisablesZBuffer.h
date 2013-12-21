//*******************************************************************
//
// Fichier	: SolidesVisualisablesZBuffer.h
//
// Auteur	: Y. Lanuel
//
// Date		: 14 Octobre 1997
//
// Commentaires	: Interface de la classe SolidesVisualisablesZBuffer
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_SolidesVisualisablesZBuffer_h_
#define	_SolidesVisualisablesZBuffer_h_


#include	"BibliothequeVisualiseur.h"
#include	"PolygonesVisualisablesZBuffer.h"
#include "Listes.h"
#include	"EnteteZBufferDLL.h"

#include	<iostream>
using namespace std ; ;


class ZBUFFER_DLL SolidesVisualisablesZBuffer	: public ObjetsVisualisables
{
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	SolidesVisualisablesZBuffer(const Listes<PolygonesVisualisablesZBuffer*>& L);
	~SolidesVisualisablesZBuffer();

//*******************************************************************
//	Methodes
//*******************************************************************
inline const Listes<PolygonesVisualisablesZBuffer*>& Liste() const;
inline int NombreFaces()	const;

//*******************************************************************
//	Operrateurs
//*******************************************************************


//*******************************************************************
//	Partie privee
//*******************************************************************
private:
	Listes<PolygonesVisualisablesZBuffer*>	L;

	SolidesVisualisablesZBuffer(const SolidesVisualisablesZBuffer&);
	const SolidesVisualisablesZBuffer&	operator = (const SolidesVisualisablesZBuffer&);

   int	NbFaces;

};


#include	"SolidesVisualisablesZBuffer.inl"

#endif

