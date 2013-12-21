//*****************************************************************************
//										
// Module	: Englobants3D
//										
// Fichier	: Englobants3D.inl
//
// Auteur	: lanuel							
//
// Date creat.	: Fri Jul 12 14:10:48 MET DST 1996
//
// Commentaires	: Inline de la classe Englobants3D
//
//
//*****************************************************************************


inline const Points3D& Englobants3D::BasGauche() const
{
	return pbg;
}
inline const Points3D& Englobants3D::HautDroit() const
{
	return phd;
}

inline void Englobants3D::ModifBasGauche(const Points3D& P)
{
	pbg=P;
}

inline void Englobants3D::ModifHautDroit(const Points3D& P)
{
	phd=P;
}
