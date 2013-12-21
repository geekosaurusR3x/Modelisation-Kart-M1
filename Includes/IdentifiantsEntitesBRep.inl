//*****************************************************************************
//
// Module	: IdentifiantsEntitesBRep
//
// Fichier	: IdentifiantsEntitesBRep.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 29/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct inline de la classe
// 					  IdentifiantsEntitesBRep
//
//
//*****************************************************************************
//	Accesseurs
//	Surcharge des operateurs
//*****************************************************************************

//*****************************************************************************
// Accesseurs
//*****************************************************************************


inline const TypeCle	IdentifiantsEntitesBRep::Cle()		const
{
	return RepresentationBRep().Cle();
}



inline const RepEntitesBRep&	IdentifiantsEntitesBRep::RepresentationBRep()	const
{
	return (const RepEntitesBRep&)(*(RepEntitesBRep*)objet);
}

inline RepEntitesBRep*		IdentifiantsEntitesBRep::PtrRepresentationBRep()
{
	return (RepEntitesBRep*)objet;
}