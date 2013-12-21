//*****************************************************************************
// 
// Fichier	: Biliotheque_Mathematique.h
// 
// Auteur	: Y. LANUEL							
// 
// Date creat.	: 27/05/96							
// 
// Commentaires	: Liste des fichiers d'entete de la categorie Math.
//
// 
//*****************************************************************************

#pragma once

#include	"Points3D.h"
#include	"Plans3D.h"
#include	"Vecteurs3D.h"
#include	"Matrices3D.h"
#include	"Droites2D.h"
#include	"Droites3D.h"
#include	"Reperes3D.h"
#include	"Rectangles.h"
#include	"Englobants3D.h"
#include	"Angles.h"
#include	"Polygones.h"
#include	"MacroMath.h"

// FONCTION A APPELER EN FIN D'EXECUTION
inline void FermerBibliothequeMathematique ()
{
	delete IMonde ;
	delete JMonde ;
	delete KMonde ;
	IMonde = JMonde = KMonde = NULL ;
}



