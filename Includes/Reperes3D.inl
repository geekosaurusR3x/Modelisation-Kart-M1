//*****************************************************************************
//										
// Module	: Reperes3D
//										
// Fichier	: Reperes3D.cc
//
// Auteur	: Y. LANUEL							
//
// Date creat.	: 21/05/96							
//
// Commentaires	: Inline de la classe Reperes3D
//
//
//*****************************************************************************




inline	const Points3D&		Reperes3D::Origine()	const
{
	return origine;
}



inline	const Matrices3D&		Reperes3D::Base()	const
{
	return matricePassage;
}




inline	const Points3D&		Reperes3D::OrigineInverse()	const
{
	return origineInverse;
}



inline	const Matrices3D&		Reperes3D::BaseInverse()	const
{
	return matriceInverse;
}





inline	void	Reperes3D::ModifOrigine(const Points3D& P)
{
	origine = P;
}


inline	void	Reperes3D::ModifBase(const Matrices3D& M)
{
	matricePassage = M;
}


inline	void	Reperes3D::ModifOrigineInverse(const Points3D& P)
{
	origineInverse = P;
}


inline	void	Reperes3D::ModifBaseInverse(const Matrices3D& M)
{
	matriceInverse = M;

}











