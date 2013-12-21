//*****************************************************************************
// 
// Module	: Englobants
// 
// Fichier	: Englobants.h
// 
// Auteur	: lanuel							
// 
// Date creat.	: Fri Jul 12 14:10:48 MET DST 1996
// 
// Commentaires	: Interface de la classe Englobants.
// 
// 
//*****************************************************************************
// Includes
// Classe Englobants
//	Constructeurs et destructeur
//	Accesseurs
//	Methodes
//	Surcharge des operateurs
//	Partie privee
//*****************************************************************************



#ifndef __Englobants__h__
#define	__Englobants__h__



//*****************************************************************************
// 
// Includes
// 
//*****************************************************************************
#include	<iostream>
using namespace std ;


#include	<Points3D.h>
#include	<Droites3D.h>
#include	"EnteteVisualiseurDLL.h"


//*****************************************************************************
// 
// Classe Englobants
// 
//*****************************************************************************
class VISUALISEUR_DLL Englobants
{

public:


//*****************************************************************************
//	Constructeurs et destructeur
//*****************************************************************************

	Englobants();
	Englobants(const Englobants&);
	~Englobants();


	Englobants(const Points3D& PtBasGauche, const Points3D& PtHautDroit);

//*****************************************************************************
//	Accesseurs
//*****************************************************************************
inline const Points3D& BasGauche() const;
inline const Points3D& HautDroit() const;
inline const Englobants& BasGauche(const Points3D&);
inline const Englobants& HautDroit(const Points3D&);

//*****************************************************************************
//	Methodes
//*****************************************************************************
	bool	ExisteIntersection(const Droites3D&)	const;
	bool	Appartient(const Points3D&)		const;
	bool	Appartient(const Englobants&)		const;


//*****************************************************************************
//	Surcharge des operateurs
//*****************************************************************************
	const Englobants&	operator = (const Englobants&);

friend ostream& VISUALISEUR_DLL operator << (ostream&, const Englobants&);

friend	Englobants VISUALISEUR_DLL operator *  (const Englobants&, const Englobants&);
friend	Englobants VISUALISEUR_DLL operator +  (const Englobants&, const Englobants&);
friend	Englobants VISUALISEUR_DLL operator -  (const Englobants&, const Englobants&);

friend	Englobants VISUALISEUR_DLL operator +  (const Englobants&, const Vecteurs3D&);
friend	Englobants VISUALISEUR_DLL operator /  (const Englobants&, int);

//*****************************************************************************
//	Partie privee
//*****************************************************************************
private:

	Points3D	pbg, phd;

};



#include	"Englobants.inl"



#endif	__Englobants__h__
