//*******************************************************************
//
// Fichier	: Textures.h
//
// Auteur	: Richard Eric
//
// Date		: 22/07/1998
//
// Commentaires	: Interface de la classe Textures
//		Cette classe permet de cr�er et de param�trer une texture. Une texture est
//		compos�e d'un bitmap (voir la classe BitmapTextures) et de quelques param�tres.
//		Le m�me bitmap peut compos� plusieurs textures et ce avec des valeurs des
//		param�tres diff�rents.
//
//*******************************************************************
// Constructeurs particuliers
//		Textures(NomFichier)
// Methodes
//		Bitmap							renvoie le bitmap
//		NbRepetitionX (+Modif...)	Manipule le nombre de fois que doit �tre
//			rep�t� sur l'axe des X le bitmap sur la face textur�e (=1 par d�faut)
//		NbRepetitionY (+Modif...)	Manipule le nombre de fois que doit �tre
//			rep�t� sur l'axe des Y le bitmap sur la face textur�e (=1 par d�faut)
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
// Partie priv�e
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