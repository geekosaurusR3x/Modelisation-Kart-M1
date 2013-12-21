//*****************************************************************************
//										
// Module	: Points3D
//										
// Fichier	: Points3D.cc
//
// Auteur	: Y. LANUEL							
//
// Date creat.	: 21/05/96							
//
// Commentaires	: Inline de la classe Points3D
//
//
//*****************************************************************************

//*****************************************************************************
//		Consultation
//*****************************************************************************
inline double	Points3D::X()		const
{
	return m[0];
}


inline double	Points3D::Y()		const
{
	return m[1];
}


inline double	Points3D::Z()		const
{
	return m[2];
}


//*****************************************************************************
//		Modification
//*****************************************************************************
inline void	Points3D::ModifX(double v)
{
	m[0]	= v;
}


inline void	Points3D::ModifY(double v)
{
	m[1]	= v;
}


inline void	Points3D::ModifZ(double v)
{
	m[2]	= v;
}












