//*******************************************************************
//
// Fichier	: PolygonesZBuffer.h
//
// Auteur	: Y. Lanuel
//
// Date		: 14 Octobre 1997
//
// Commentaires	: Interface de la classe PolygonesZBuffer
//
//*******************************************************************
// Constructeurs particuliers
// Accesseurs
// Methodes
// Operateurs
//*******************************************************************


#ifndef	_PolygonesZBuffer_h_
#define	_PolygonesZBuffer_h_


#include	"EnteteZBufferDLL.h"

#include	"PolygonesVisualisablesZBuffer.h"

#include	"Listes.h"
#include	"Iterateurs.h"

#include	<iostream> 
using namespace std ;


class ZBUFFER_DLL PolygonesZBuffer	: public PolygonesVisualisablesZBuffer
 {
public:
//*******************************************************************
//	Constructeurs et destructeur
//*******************************************************************
	PolygonesZBuffer();
	PolygonesZBuffer(const PolygonesZBuffer&);
	~PolygonesZBuffer();

//*******************************************************************
//	Methodes
//*******************************************************************
			int							NbPoints ()							const;
			const Points3D&			IemePoint (int i)					const;
        	Vecteurs3D					Normale(const Points3D&)		const;
			Plans3D						Plan()								;
inline	const Listes<Points3D>&	ListesPoints ()					const;
			void							AjouterPoint (const Points3D& P);

//*******************************************************************
//	Operateurs
//*******************************************************************
	const PolygonesZBuffer&	operator = (const PolygonesZBuffer&);
friend	ostream& ZBUFFER_DLL		operator<< (ostream&, const PolygonesZBuffer&);

//*******************************************************************
//	Partie privee
//*******************************************************************
private:

	Plans3D			_Plan;
	Listes<Points3D>	_ListePoints;
	int			_NbPoints;

};


#include	"PolygonesZBuffer.inl"

#endif

