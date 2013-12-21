//*****************************************************************************
//
// Module	: Identifiants
//
// Fichier	: Identifiants.inl
//
// Auteur	: Heschung Frederic
//
// Date creat.	: 29/07/99
//
// Version	:
//
// Commentaires	: Implementation des fct inline de la classe Identifiants
//
//
//*****************************************************************************
//	Methodes
//*****************************************************************************

inline bool Identifiants::EstInitialise () const
{	return (objet != NULL) ;
}


inline void	Identifiants::ModifObjet(void *adr)
{
	objet	= adr;
}



