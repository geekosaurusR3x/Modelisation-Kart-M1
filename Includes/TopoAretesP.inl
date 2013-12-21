//*****************************************************************************
//
// Module	: TopoAretesP
//
// Fichier	: TopoAretesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct inline de la classe TopoAretesP
//
//
//*****************************************************************************
// Includes
//	Accesseurs
//	Methodes
//*****************************************************************************

inline TopologiesBRep*	TopoAretesP::Dupliquer()	const
{
	return new TopoAretesP (*this) ;
}


inline const SommetsP& TopoAretesP::Sommet1 () const
{
	return sommet1 ;
}


inline const SommetsP& TopoAretesP::Sommet2 () const
{
	return sommet2 ;
}


inline SommetsP* TopoAretesP::PtrSommet1 ()
{
	return &sommet1 ;
}

inline SommetsP* TopoAretesP::PtrSommet2 ()
{
	return &sommet2 ;
}

inline const ContoursP& TopoAretesP::Contour1 () const
{
	return contour1 ;
}

inline const ContoursP& TopoAretesP::Contour2 () const
{
	return contour2 ;
}




inline ContoursP* TopoAretesP::PtrContour1 ()
{
	return &contour1 ;
}


inline ContoursP* TopoAretesP::PtrContour2 ()
{
	return &contour2 ;
}




inline const AretesP& TopoAretesP::AreteSuivanteDansContour1 () const
{
	return areteSuivante1 ;
}



inline const AretesP& TopoAretesP::AreteSuivanteDansContour2 () const
{
	return areteSuivante2 ;
}


inline AretesP* TopoAretesP::PtrAreteSuivanteDansContour1 ()
{
	return &areteSuivante1 ;
}



inline AretesP* TopoAretesP::PtrAreteSuivanteDansContour2 ()
{
	return &areteSuivante2 ;
}




inline const AretesP& TopoAretesP::AretePrecedenteDansContour1 () const
{
	return aretePrecedente1 ;
}



inline const AretesP& TopoAretesP::AretePrecedenteDansContour2 () const
{
	return aretePrecedente2 ;
}


inline AretesP* TopoAretesP::PtrAretePrecedenteDansContour1 ()
{
	return &aretePrecedente1 ;
}



inline AretesP* TopoAretesP::PtrAretePrecedenteDansContour2 ()
{
	return &aretePrecedente2 ;
}


inline void TopoAretesP::ModifSommet1 (const SommetsP &P)
{
	sommet1 = P ;
	// les mises a jour des aretes orientees incidentes a P, de la
	// geometrie (englobant) de la face sont faites au niveau de
	// AreteP
}




inline void TopoAretesP::ModifSommet2 (const SommetsP &P)
{
	sommet2 = P ;
	// les mises a jour des aretes orientees incidentes a P, de la
	// geometrie (englobant) de la face sont faites au niveau de
	// AreteP
}




inline void TopoAretesP::ModifContour1 (const ContoursP &C)
{
	contour1 = C ;
	// la mise a jour de la geometrie (englobant) de la face est
	// faite au niveau de AreteP
}




inline void TopoAretesP::ModifContour2 (const ContoursP &C)
{
	contour2 = C ;
	// la mise a jour de la geometrie (englobant) de la face est
	// faite au niveau de AreteP
}


inline const AretesOrienteesP&	TopoAretesP::AreteOrienteePositive()	const
{
	return areteOrienteePositive;
}

inline const AretesOrienteesP&	TopoAretesP::AreteOrienteeNegative()	const
{
	return areteOrienteeNegative;
}



inline AretesOrienteesP *	TopoAretesP::PtrAreteOrienteePositive()
{
	return &areteOrienteePositive;
}

inline AretesOrienteesP *	TopoAretesP::PtrAreteOrienteeNegative()
{
	return &areteOrienteeNegative;
}


inline bool	TopoAretesP::Continuite()	const
{
	return continuite;
}

inline void	TopoAretesP::ModifContinuite(bool C)
{
	continuite = C;
}


inline void TopoAretesP::ModifAreteSuivante1 (const AretesP &A)
// Sans mise à jour du contour
{
	areteSuivante1 = A ;

/*	// on conserve dans A le fait que l'un de ses contours est maintenant
	// le contour 1 de l'arete courante.
	if (A.Sommet1 () == Sommet2 ())
		A.ModifContour1 (Contour1 ()) ;
	else
		A.ModifContour2 (Contour1 ()) ;
*/

	// la mise a jour de la geometrie (englobant) de la face est
	// faite au niveau de AreteP
}




inline void TopoAretesP::ModifAreteSuivante2 (const AretesP &A)
// Sans mise à jour du contour
{
	areteSuivante2 = A ;

/*	// on conserve dans A le fait que l'un de ses contours est maintenant
	// le contour 2 de l'arete courante.
	if (A.Sommet1 () == Sommet1 ())
		A.ModifContour1 (Contour2 ()) ;
	else
		A.ModifContour2 (Contour2 ()) ;
*/
	// la mise a jour de la geometrie (englobant) de la face est
	// faite au niveau de AreteP
}




inline void TopoAretesP::ModifAretePrecedente1 (const AretesP &A)
// Sans mise à jour du contour
{
	aretePrecedente1 = A ;

/*	// on conserve dans A le fait que l'un de ses contours est maintenant
	// le contour 1 de l'arete courante.
	if (A.Sommet2 () == Sommet1 ())
		A.ModifContour1 (Contour1 ()) ;
	else
		A.ModifContour2 (Contour1 ()) ;
*/
	// la mise a jour de la geometrie (englobant) de la face est
	// faite au niveau de AreteP

}




inline void TopoAretesP::ModifAretePrecedente2 (const AretesP &A)
// Sans mise à jour du contour
{
	aretePrecedente2 = A ;

/*	// on conserve dans A le fait que l'un de ses contours est maintenant
	// le contour 2 de l'arete courante.
	if (A.Sommet2 () == Sommet2 ())
		A.ModifContour1 (Contour2 ()) ;
	else
		A.ModifContour2 (Contour2 ()) ;
*/
	// la mise a jour de la geometrie (englobant) de la face est
	// faite au niveau de AreteP

}
