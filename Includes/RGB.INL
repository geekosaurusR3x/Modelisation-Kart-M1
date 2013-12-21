//*****************************************************************************
//										
// Module	: CouleursRGB
//										
// Fichier	: CouleursRGB.inl
//
// Auteur	: lanuel							
//
// Date creat.	: Tue Jul  9 16:42:21 MET DST 1996
//
// Commentaires	: Inline de la classe CouleursRGB
//
//
//*****************************************************************************




//*****************************************************************************
//	Accesseurs
//*****************************************************************************


//*****************************************************************************
//		Consultation
//*****************************************************************************
inline double	CouleursRGB::R()	const
{
	return val[0];
}


inline double	CouleursRGB::G()	const
{
	return val[1];
}


inline double	CouleursRGB::B()	const
{
	return val[2];
}


//*****************************************************************************
//		Modification
//*****************************************************************************
inline const CouleursRGB&	CouleursRGB::R(double r)
{
	val[0]	= r;
	return *this;
}


inline const CouleursRGB&	CouleursRGB::G(double g)
{
	val[1]	= g;
	return *this;
}


inline const CouleursRGB&	CouleursRGB::B(double b)
{
	val[2]	= b;
	return *this;
}






