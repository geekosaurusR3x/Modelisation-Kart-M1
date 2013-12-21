//*****************************************************************************
//										
// Module	: Vecteurs3D
//										
// Fichier	: Vecteurs3D.inl
//
// Auteur	: Y. LANUEL							
//
// Date creat.	: 08/07/96							
//
// Commentaires	: Inline de la classe Vecteurs3D
//
//
//*****************************************************************************



//*****************************************************************************
//	Consultation
//*****************************************************************************
inline double	Vecteurs3D::X()		const
{
	return m[0];
}


inline double	Vecteurs3D::Y()		const
{
	return m[1];
}


inline double	Vecteurs3D::Z()		const
{
	return m[2];
}


//*****************************************************************************
//	Modification
//*****************************************************************************
inline void	Vecteurs3D::ModifX(double v)
{
	m[0]	= v;
}


inline void	Vecteurs3D::ModifY(double v)
{
	m[1]	= v;
}


inline void	Vecteurs3D::ModifZ(double v)
{
	m[2]	= v;
}


