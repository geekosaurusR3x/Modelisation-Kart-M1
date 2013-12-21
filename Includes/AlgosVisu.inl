//*******************************************************************
//
// Fichier	: AlgosVisu.inl
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Inline de la classe AlgosVisu
//
//*******************************************************************


inline	Vues*	AlgosVisu::PtrVue ()
{
	return _Vue;
}

inline	const Vues&	AlgosVisu::Vue ()		const
{
	return *_Vue;
}

inline	void	AlgosVisu::ModifVue (Vues* V)
{
	_Vue = V;
}






