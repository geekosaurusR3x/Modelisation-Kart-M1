#pragma once
#include "Attributs.h"
#include "AttributsFacesP.h"
#include "TIColorerSolide.h"
#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"
#include "math.h"

/*************************************************************************
Cette classe poss�de deux constructeur :
	- Le premier prend l'angle d'inclinaison du support ainsi que les
	diff�rentes longueurs de la pi�ces ET 2 Points3D, le point de d�part 
	de la pi�ce et le milieu de la diagonale du support, ce point doit
	se situer sur la diagonale de la face de l api�ce.
	- Le deuxieme prend l'angle, le point de depart, les differentes
	longueurs de la piece, mais remplace le point du milieu de la diagonale
	par une profondeur, le milieu de la diagonale est calcul� lors de la 
	construction.

Les constructeur ne servent qu'� initialiser les diff�rents attributs,
la construction de la pi�ce se fait dans SupportCremaillereParPoints
pour le 1er constructeur, et par Support_Cremaillere pour le 2nd.

Pour tester : 

void CApplicationRegainDlg::OnTestsTest1()
{
	SupportCremaillere crem(45.0, Points3D(0,0,0),Points3D(60,60,0),100,70,70,100,50, 200);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(crem.getSupport());
	LGB->Raffraichir () ;

}

void CApplicationRegainDlg::OnTestsTest2()
{
	SupportCremaillere crem(45.0,60, Points3D(0,0,0),100,70,70,100,50, 200);
	LogicielsGraphiquesBase::Defaut()->AfficherSolide(crem.getSupport());
	LGB->Raffraichir () ;
}



**************************************************************************/

class SupportCremaillere{
	private:
		SolidesP Support;//Le Support de Cr�maill�re
		int _profondeur;//Profondeur de l'emplacement du rail de cremaillere
		double _angle;//Angle d'inclinaison du support de l'emplacement du rail de creamaillere
					  //L'angle est exprim� en degr�
		int _longueurBase;//Longueur de la base qui se situe au niveau du chassis
		int _hauteurGauche;//Grande hauteur
		int _hauteurDroite;//Petite hauteur
		int _longueurPetiteBase;//Longueur de la base si situant en haut
		int _taille;//Largeur cremaill�re � supporter
		int _extrusion;//Longueur totale de la pi�ce souhait�e
		Points3D _depart;//Point de depart du support
		Points3D _support;//milieu de la diagonale du support, doit �tre connu � l'avance
						  //C'est ce point qui d�finit aussi la profondeur du support dans le 1er constructeur

	public:
		SupportCremaillere(double angle ,Points3D depart, Points3D milieu,
							int lB,int lpB,int hD,int hG, int size, int extru);//Sert � l'initialisation des attributs
																					  //Permet la construction � l'aide du milieu
																					  //de la diagonale du support
		SupportCremaillere(double angle, int profondeur, Points3D depart,
							int lB,int lpB,int hD,int hG, int size, int extru);
		SupportCremaillere(){ ;};
		void SupportCremaillereParPoint( );//Mod�lisation du support en utilisant le milieu de la diagonale
		void Support_Cremaillere();
		SolidesP getSupport();
		~SupportCremaillere();
};
