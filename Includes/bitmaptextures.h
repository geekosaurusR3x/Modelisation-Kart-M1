//*******************************************************************
//
// Fichier	: BitmapTextures.h
//
// Auteur	: Richard Eric
//
// Date		: 22/07/1998
//
// Commentaires	: Implementation de la classe BitmapTextures
//
//*******************************************************************
// Constructeurs particuliers
//		Aucun (voir m�thode statique cr�er)
// Accesseurs
//		Nom			Nom du bitmap de la texture (= nom du fichier qui le contient)
//		Maxx			Largeur du bitmap
//		Maxy			Hauteur du bitmap
//		Image			Renvoie le tableau des "pixels" du bitmap
// Methodes
//		Creer(NomFichier) M�thode statique garantissant qu'un bitmap ne peut �tre charg�
//			qu'une seule fois en m�moire. C'est en fait le seul "constructeur" de cette classe.
//*******************************************************************

#ifndef _BITMAPTEXTURE_
#define _BITMAPTEXTURE_



#include <iostream>
using namespace std ;

#include "Tables.h"

#include	"EnteteVisualiseurDLL.h"


class VISUALISEUR_DLL BitmapTextures
{
//******************************************************************
// Partie publique
//******************************************************************
public:
			~BitmapTextures(void);

			const char * 		Nom(void)		const;
			int 					Maxx(void)		const;
			int 					Maxy(void)		const;
			GLubyte *			Image(void)		const;


static 	BitmapTextures * 	Creer(char * nombmp);



//******************************************************************
// Partie priv�e
//******************************************************************
private:
		int maxx,maxy;
		GLubyte *image;
		char * nom;
		static Tables<BitmapTextures *> textures;
		static int nb;


// M�thodes priv�es de services ou ne devant pas �tre utilis�es
		void Copie(const BitmapTextures &t);
		BitmapTextures(char* nombmp);
		BitmapTextures(const BitmapTextures &t);
		const BitmapTextures operator = (const BitmapTextures &t);
		friend ostream & operator << (ostream &s,const BitmapTextures &t);
};


#endif


