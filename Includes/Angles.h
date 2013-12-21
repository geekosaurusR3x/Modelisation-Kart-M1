#ifndef AnglesH
#define AnglesH

#include	"Points3D.h"
#include	"Vecteurs3D.h"

#include	"EnteteMathDLL.h"


extern double MATH_DLL AngleSecteur (	const Points3D &C, const Points3D &P1,
													const Points3D &P2, const Vecteurs3D &K) ;
//************************************************************************
// Calcule l'angle oriente forme par les vecteurs (C,P1) et (C,P2).
// Le sens positif est donne par le vecteur K d'apres la regle du tire
// bouchon. K ne doit donc pas être dans le plan (C,P1,P2).
// L'angle retourné est entre -Pi et Pi.
// ATTENTION : LES TROIS POINTS SONT SUPPOSES DISTINCTS.
//************************************************************************

#endif
