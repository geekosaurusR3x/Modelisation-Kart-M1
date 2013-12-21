//*******************************************************************
//
// Fichier	: Textures.h
//
// Auteur	: Richard Eric
//
// Date		: 22/07/1998
//
// Commentaires	: Interface de la classe Textures
//		Cette classe permet de créer et de paramétrer une texture. Une texture est
//		composée d'un bitmap (voir la classe BitmapTextures) et de quelques paramètres.
//		Le même bitmap peut composé plusieurs textures et ce avec des valeurs des
//		paramètres différents.
//
//*******************************************************************
// Constructeurs particuliers
//		Textures(NomFichier)
// Methodes
//		Bitmap							renvoie le bitmap
//		NbRepetitionX (+Modif...)	Manipule le nombre de fois que doit être
//			repété sur l'axe des X le bitmap sur la face texturée (=1 par défaut)
//		NbRepetitionY (+Modif...)	Manipule le nombre de fois que doit être
//			repété sur l'axe des Y le bitmap sur la face texturée (=1 par défaut)
//*******************************************************************
#ifndef _TEXTURE_
#define _TEXTURE_

#include <iostream>
using namespace std ;
#include <windows.h>
#include <gl/gl.h>
#include "BitmapTextures.h"

#include	"EnteteVisualiseurDLL.h"


class VISUALISEUR_DLL Textures
{
//*******************************************************
// Partie publique
//*******************************************************
public:
		Textures(char * nombmp);
		~Textures(void);


// Accesseurs
		BitmapTextures*	Bitmap(void)						const;

		int					NbRepetitionX()					const;
		void					ModifNbRepetitionX(int);

		int					NbRepetitionY()					const;
		void					ModifNbRepetitionY(int);


//*******************************************************
// Partie privée
//*******************************************************
private:
	BitmapTextures	*bmp;

	int				nbrepetition_x;
	int				nbrepetition_y;

	const Textures operator = (const Textures &t);
	friend ostream & operator << (ostream &s,const Textures &t);

};


#endif


