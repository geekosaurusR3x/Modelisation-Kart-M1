#ifndef __LiaisonZBufferBRep__
#define __LiaisonZBufferBRep__



#include "BibliothequeMathematique.h"
#include "BibliothequeZBuffer.h"
#include "bibliothequeBRepP.h"
#include "BibliothequeSTL.h"
// #include "LGB.h"

#include "EnteteLGBDLL.h"


// IL VAUDRAIT MIEUX INCLURE lgb.h que d'avoir les lignes ci-dessous mais ça
// provoque une erreur que je ne comprends pas.
//

// Type pour le couple de pointeurs associé à chaque face affichée.
// Pour une face donnée, ces 2 pointeurs pointent sur le premier et
// le dernier maillon de la scène qui correspondent à la face.
typedef struct {	ElemListes <ObjetsVisualisables *> *P1, *P2 ;} TCouplePointeurs ;


class	LGB_DLL TrianglesSTLVisualisables : public PolygonesVisualisablesZBuffer
{
public:
		TrianglesSTLVisualisables(const STLTriangle &T, const Vecteurs3D &N) ;
		int	NbPoints()	const ;
		const Points3D&	IemePoint(int i)	const ;
		Vecteurs3D	Normale(const Points3D& P) const ;
		Plans3D	Plan() ;

private:
		Points3D			P1,P2,P3 ;
      Vecteurs3D		normale ;
      Plans3D			plan ;

		TrianglesSTLVisualisables() ;
		const ObjetsVisualisables& operator= (const ObjetsVisualisables&) ;
};


class	LGB_DLL FacesBRepVisualisables : public PolygonesVisualisablesZBuffer
// Ce sont des faces du BRep directement visualisables parce que convexes
{
public:
	FacesBRepVisualisables(const FacesP &F) ;
	int NbPoints()	const ;
	const Points3D&	IemePoint(int i)	const ;
	Vecteurs3D	Normale(const Points3D& ) const ;
	Plans3D	Plan()  ;

private:
	FacesP	Face ;
	FacesBRepVisualisables() ;
	const ObjetsVisualisables& operator= (const ObjetsVisualisables&) ;
} ;


class	LGB_DLL FacesPVisualisables
{
public:
		FacesPVisualisables(const FacesP& Face) ;

		//***********************************************************************
		// Insertion de la face dans une scène
		//void InsererDansScene(Scenes& S) ;
		//void InsererDansScene(Scenes& S, CouleursRGB *Couleur) ;

		// Insère la face dans la scène S et restitue, dans *PC, les adresses des maillons
		// de S qui contiennent le premier et le dernier polygoneVisualisable correspondant
		// à la face.
		void InsererDansScene(Scenes& S, TCouplePointeurs	*PC) ;

private:
		FacesP	F ;
		bool EstConvexe() ;
};


/*
//*****************************************************************************
//
//	SolidesPVisualisablesZBuffer
//
//*****************************************************************************
class	LGB_DLL SolidesPVisualisables
{
public:

		//***********************************************************************
      // Constructeur par défaut
		//***********************************************************************
		SolidesPVisualisables(const SolidesP& S) ;

		//***********************************************************************
      // Insertion du solide dans une scène
      // Les deux premières fonctions (insertion dans la scène avec le
      // matériau par défaut ou avec le matériau par défaut à la couleur près)
      // sont inutiles. Le LGN n'utilise plus que la troisième.
		//***********************************************************************
		void InsererDansScene(Scenes& S) ;
		void InsererDansScene(Scenes& S, Materiaux Materiau) ;
		void InsererDansScene(Scenes& S, CouleursRGB *Couleur) ;

private:
		SolidesP	Solide;
};

*/
/*
//*****************************************************************************
//
//	facesPVisualisablesZBuffer
//
//*****************************************************************************
class	LGB_DLL FacesPVisualisables : public PolygonesVisualisablesZBuffer
{
public:

		//***********************************************************************
      // Constructeur
		//***********************************************************************
		FacesPVisualisables(const FacesP& Face)			: F(Face), PolygonesVisualisablesZBuffer()
	  	{
   		ModifEnglobant(F.Englobant());
     	}


		//***********************************************************************
      // Surcharge des fonction virtuelles
		//***********************************************************************
      int	NbPoints()	const
	  	{
			return F.NombreSommets();
	  	}

	  	const Points3D&	IemePoint(int i)	const
	  	{
			return F.IemeSommet(i+1).Point3D();
	  	}

	  	Vecteurs3D	Normale(const Points3D& P) const
	  	{
			return F.Plan().Normale();
	  	}

     	Plans3D		Plan()				const
     	{
     		return F.Plan();
     	}


private:
		FacesP	F;
};




*/
#endif

