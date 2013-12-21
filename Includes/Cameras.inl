//*******************************************************************
//
// Fichier	: Cameras.inl
//
// Auteur	: Y. Lanuel
//
// Date		: 2 Octobre 1997
//
// Commentaires	: Inline de la classe Cameras
//
//*******************************************************************



inline	const Points3D&	Cameras::Observateur ()		const
{
	return _Repere.Origine();
	
}


inline	const Points3D&	Cameras::Mire ()		const
{
	return _Mire;
}


inline	Vecteurs3D	Cameras::DirectionVisee ()		const
{
	return Vecteurs3D(Observateur(), Mire()).VecteurNorme();
}


inline	double	Cameras::DistanceFocale ()		const
{
	return _DistanceFocale;
}


inline	void	Cameras::ModifObservateur (const Points3D& Obs)
{
	_Repere	= Reperes3D(Obs, Vecteurs3D(Obs,Mire()));
}


inline	void	Cameras::ModifMire (const Points3D& M)
{
	_Mire	= M;
	_Repere	= Reperes3D(Observateur(), Vecteurs3D(Observateur(),Mire()));
}


inline	void	Cameras::ModifDirectionVisee (const Vecteurs3D& Dir)
{
	_Mire	= Observateur() + Observateur().Distance(Mire()) * Dir.VecteurNorme();
	_Repere	= Reperes3D(Observateur(), Vecteurs3D(Observateur(),Mire()));
	
}


inline	void	Cameras::ModifDistanceFocale (double Dist)
{
	_DistanceFocale	= Dist;
}


inline	const Vecteurs3D&	Cameras::VecteurDebout()				const
{
	return _Debout;
}


inline	void	Cameras::ModifVecteurDebout(const Vecteurs3D& V)
{
	_Debout = V;
}



