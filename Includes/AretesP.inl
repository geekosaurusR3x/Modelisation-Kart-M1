//*****************************************************************************
//
// Module	: AretesP
//
// Fichier	: AretesP.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 26/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct inline de la classe AretesP
//
//
//*****************************************************************************
// Includes
//	Methodes
//	Surcharge des operateurs
//*****************************************************************************



inline const SommetsP& 		AretesP::Sommet1 () const
{
	return	Representation().Topologie().Sommet1();
}



inline const SommetsP& 		AretesP::Sommet2 () const
{
	return	Representation().Topologie().Sommet2();
}



inline SommetsP* 		AretesP::PtrSommet1 ()
{
	return	PtrRepresentation()->PtrTopologie()->PtrSommet1();
}




inline SommetsP* 		AretesP::PtrSommet2 ()
{
	return	PtrRepresentation()->PtrTopologie()->PtrSommet2();
}




inline const ContoursP& 	AretesP::Contour1 () const
{
	return	Representation().Topologie().Contour1();
}




inline const ContoursP& 	AretesP::Contour2 () const
{
	return	Representation().Topologie().Contour2();
}




inline ContoursP* 	AretesP::PtrContour1 ()
{
	return	PtrRepresentation()->PtrTopologie()->PtrContour1();
}




inline ContoursP* 	AretesP::PtrContour2 ()
{
	return	PtrRepresentation()->PtrTopologie()->PtrContour2();
}




inline const FacesP& 		AretesP::Face1 () const
{
	return	Representation().Topologie().Face1();
}




inline const FacesP& 		AretesP::Face2 () const
{
	return	Representation().Topologie().Face2();
}




inline FacesP*		AretesP::PtrFace1 ()
{
	return	PtrRepresentation()->PtrTopologie()->PtrFace1() ;
}




inline FacesP*		AretesP::PtrFace2 ()
{
	return	PtrRepresentation()->PtrTopologie()->PtrFace2() ;
}




inline const AretesP& 		AretesP::AreteSuivanteDansContour1 () const
{
	return	Representation().Topologie().AreteSuivanteDansContour1();
}


inline const AretesP& 		AretesP::AreteSuivanteDansContour2 () const
{
	return	Representation().Topologie().AreteSuivanteDansContour2();
}




inline AretesP*		AretesP::PtrAreteSuivanteDansContour1 ()
{
	return	PtrRepresentation()	->PtrTopologie()
					->PtrAreteSuivanteDansContour1();
}


inline AretesP* 	AretesP::PtrAreteSuivanteDansContour2 ()
{
	return	PtrRepresentation()	->PtrTopologie()
					->PtrAreteSuivanteDansContour2();
}




inline const AretesP& 		AretesP::AretePrecedenteDansContour1 () const
{
	return	Representation().Topologie().AretePrecedenteDansContour1();
}


inline const AretesP& 		AretesP::AretePrecedenteDansContour2 () const
{
	return	Representation().Topologie().AretePrecedenteDansContour2();
}




inline AretesP*		AretesP::PtrAretePrecedenteDansContour1 ()
{
	return	PtrRepresentation()	->PtrTopologie()
					->PtrAretePrecedenteDansContour1();
}


inline AretesP* 	AretesP::PtrAretePrecedenteDansContour2 ()
{
	return	PtrRepresentation()	->PtrTopologie()
					->PtrAretePrecedenteDansContour2();
}



inline bool	AretesP::EstIsolee () const
{
	return	Representation().Topologie().EstIsolee();
}


inline bool	AretesP::Continuite()		const
{
	return Representation().Topologie().Continuite();
}


inline void	AretesP::ModifContinuite(bool Cont)
{
	PtrRepresentation()->PtrTopologie()->ModifContinuite(Cont);
}

inline const 	AretesOrienteesP&	AretesP::AreteOrienteePositive()	const
{
	return	Representation().Topologie().AreteOrienteePositive();
}




inline const	AretesOrienteesP&      AretesP::AreteOrienteeNegative()	const
{
	return	Representation().Topologie().AreteOrienteeNegative();
}




inline AretesOrienteesP *	AretesP::PtrAreteOrienteePositive()
{
	return	PtrRepresentation()->PtrTopologie()->PtrAreteOrienteePositive();
}




inline AretesOrienteesP *      AretesP::PtrAreteOrienteeNegative()
{
	return	PtrRepresentation()->PtrTopologie()->PtrAreteOrienteeNegative();
}




inline void 	AretesP::ModifDroite3D (const Droites3D &D)
{
	PtrRepresentation()->PtrGeometrie()->ModifDroite3D(D);
}




inline bool	AretesP::EstGeometrieAJour()		const
{
	return Representation().Geometrie().EstAJour();
}
