//*****************************************************************************
//										
// Module	: Droites3D
//										
// Fichier	: Droites3D.inl
//
// Auteur	: Y. LANUEL							
//
// Date creat.	: 09/07/96							
//
// Commentaires	: Inline de la classe Droites3D
//
//
//*****************************************************************************



//*****************************************************************************
//	Accesseurs
//*****************************************************************************


//*****************************************************************************
//		Consultation
//*****************************************************************************
inline const Points3D&	Droites3D::Origine()			const
{
	return p;
}


inline const Vecteurs3D& Droites3D::Direction()		const
{
	return v;
}


//*****************************************************************************
//		Modification
//*****************************************************************************
inline const Droites3D&	Droites3D::Origine(const Points3D& Pt)
{
	p	= Pt;
        return *this;
}


inline const Droites3D&	Droites3D::Direction(const Vecteurs3D& Vect)
{
	v	= Vect;
        return *this;
}

