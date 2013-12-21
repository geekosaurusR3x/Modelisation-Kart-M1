//*****************************************************************************
//										
// Module	: Englobants
//										
// Fichier	: Englobants.inl
//
// Auteur	: lanuel							
//
// Date creat.	: Fri Jul 12 14:10:48 MET DST 1996
//
// Commentaires	: Inline de la classe Englobants
//
//
//*****************************************************************************


inline const Points3D& Englobants::BasGauche() const
{
	return pbg;
}
inline const Points3D& Englobants::HautDroit() const
{
	return phd;
}

inline const Englobants& Englobants::BasGauche(const Points3D& P)
{
	pbg=P;
	return *this;
}

inline const Englobants& Englobants::HautDroit(const Points3D& P)
{
	phd=P;
	return *this;
}
