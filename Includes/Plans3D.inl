//*****************************************************************************
//										
// Module	: Plans3D
//										
// Fichier	: Plans3D.inl
//
// Auteur	: Y. LANUEL, M. KRAJECKI					
//
// Date creat.	: 30/07/96							
//
// Commentaires	: Inline de la classe Plans3D
//
//
//*****************************************************************************

//*****************************************************************************
//		Consultation
//*****************************************************************************
inline double	Plans3D::A()		const
{
	return a;
}


inline double	Plans3D::B()		const
{
	return b;
}


inline double	Plans3D::C()		const
{
	return c;
}

inline double	Plans3D::D()		const
{
	return d;
}

inline const Vecteurs3D	Plans3D::Normale()	const
{
	return Vecteurs3D(a,b,c);
}


//*****************************************************************************
//		Modification
//*****************************************************************************
inline const Plans3D&	Plans3D::A(double v)
{
	a	= v;
        return *this;
}


inline const Plans3D&	Plans3D::B(double v)
{
	b	= v;
        return *this;
}


inline const Plans3D&	Plans3D::C(double v)
{
	c	= v;
        return *this;
}

inline const Plans3D&	Plans3D::D(double v)
{
	d	= v;
        return *this;
}











