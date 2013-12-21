//*******************************************************************
//
// Fichier	: Vues.inl
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Inline de la classe Vues
//
//*******************************************************************


#define	EtatAJour				0
#define	EtatStudioModifie		1
#define	EtatSceneModifiee		2
#define	EtatCameraModifiee	4
#define	EtatImageModifiee		8


inline	const char*	Vues::Nom ()		const
{
	return	_Nom;
}


inline	void	Vues::ModifNom (const char* N)
{
	delete _Nom;
	_Nom = _strdup(N);
}


inline	AlgosVisu*	Vues::PtrAlgoVisu ()
{
	return _AlgoVisu;
}


inline	void	Vues::ModifAlgoVisu (AlgosVisu* A)
{
	_AlgoVisu = A;
}


inline	const Cameras&	Vues::Camera ()		const
{
	return _Camera;
}


inline	void	Vues::ModifCamera (const Cameras& C)
{
	_Camera = C;
	Etat	= Etat | EtatCameraModifiee;
}


inline	bool	Vues::EstCameraModifiee ()		const
{
	return	(Etat & EtatCameraModifiee) ? true : false;
}


inline	const Studios&	Vues::Studio ()		const
{
	return _Studio;
}


inline	void	Vues::ModifStudio (const Studios& S)
{
	_Studio = S;
	Etat	= Etat | EtatStudioModifie;
}


inline	bool	Vues::EstStudioModifie ()		const
{
	return	Etat & EtatStudioModifie;
}


inline	const Scenes&	Vues::Scene ()		const
{
	return _Scene;
}


inline	Scenes&	Vues::Scene ()
{
	Etat	= Etat | EtatSceneModifiee;
	return _Scene;
}


inline	void	Vues::ModifScene (const Scenes& S)
{
	_Scene = S;
	Etat	= Etat | EtatSceneModifiee;
}


inline	bool	Vues::EstSceneModifiee ()		const
{
	return	(Etat & EtatSceneModifiee) ? true : false;
}


inline	const Images&	Vues::Image ()		const
{
	return _Image;
}


inline	void	Vues::ModifImage (const Images& I)
{
	_Image = I;
	Etat	= Etat | EtatImageModifiee;
}


inline	bool	Vues::EstImageModifiee ()		const
{
	return	(Etat & EtatImageModifiee) ? true : false;
}


inline	void	Vues::MettreAJourEtat()
{
	Etat	= EtatAJour;
}

inline	double	Vues::TempsCPU()		const
{
	return	_TempsCPU;
}





