//*****************************************************************************
//										
// Module	: Materiaux
//										
// Fichier	: Materiaux.inl
//
// Auteur	: lanuel							
//
// Date creat.	: Tue Jul  9 17:00:15 MET DST 1996
//
// Commentaires	: Inline de la classe Materiaux
//
//
//*****************************************************************************




//*****************************************************************************
//	Accesseurs
//*****************************************************************************


//*****************************************************************************
//		Consultation
//*****************************************************************************
inline const char*		Materiaux::Nom()		const
{
	return nom;
}

	
inline const Couleurs*		Materiaux::PtrCouleur()	const
{
	return c;
}


inline const Couleurs&		Materiaux::Couleur()	const
{
	return *c;
}


inline double	Materiaux::Ka()		const
{
	return ka;
}


inline double	Materiaux::Kd()		const
{
	return kd;
}

inline double	Materiaux::Ks()		const
{
	return ks;
}

inline double	Materiaux::Kt()		const
{
	return kt;
}

inline double	Materiaux::Ns()		const
{
	return ns;
}

inline double	Materiaux::CoefficientAmbiant()		const
{
	return ka;
}


inline double	Materiaux::CoefficientDiffus()		const
{
	return kd;
}

inline double	Materiaux::CoefficientSpeculaire()		const
{
	return ks;
}

inline double	Materiaux::CoefficientTransparence()		const
{
	return kt;
}

inline double	Materiaux::IndiceReflexion()		const
{
	return ns;
}

inline void	Materiaux::ModifCoefAmbiant(double c)
{
	 ka	= c;
}


inline void	Materiaux::ModifCoefDiffus(double c)
{
	 kd	= c;
}

inline void	Materiaux::ModifCoefSpeculaire(double c)
{
	 ks	= c;
}

inline void	Materiaux::ModifCoefTransparence(double c)
{
	 kt	= c;
}

inline void	Materiaux::ModifIndiceReflexion(double c)
{
	 ns	= c;
}

inline double	Materiaux::Ro()		const
{
	return ro;
}

inline double	Materiaux::nr()		const
{
	return nrefl;
}

inline double	Materiaux::IndiceRefraction()		const
{
	return nrefl;
}

inline void	Materiaux::ModifIndiceRefraction(double c)
{
	 nrefl = c;
}

inline double	Materiaux::nt()		const
{
	return ntrans;
}

inline double	Materiaux::k()		const
{
	return kabs;
}

inline double	Materiaux::m()		const
{
	return mrugosite;
}

	
inline bool	Materiaux::Conducteur()	const
{
	return conducteur;
}

inline bool	Materiaux::Transparent()	const
{
	return transparent;
}

inline bool	Materiaux::Reflechissant()	const
{
	return reflechissant;
}






//*****************************************************************************
//		Modification
//*****************************************************************************
inline	const Materiaux&	Materiaux::Caracteristiques(Couleurs* coul,
double Ka, double Kd, double Ks, double Kt, double Ns, double Nr)
{
	c=coul ;
	ka=Ka;
	kd=Kd;
	ks=Ks;
	kt=Kt;
	ns=Ns;
	nrefl=Nr;
	if (Ks>0) reflechissant=1;
	else reflechissant=0;
	if (Kt>0) transparent=1;
	else transparent=0;

	return *this;
}


inline const Textures*	Materiaux::Texture()			const
{
	return texture;
}


inline	void	Materiaux::ModifTexture(Textures* T)
{
	texture = T;
}


