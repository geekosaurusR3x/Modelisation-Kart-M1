//*****************************************************************************
//										
// Module	: Rectangles
//										
// Fichier	: Rectangles.inl
//
// Auteur	: M. Krajecki							
//
// Date creat.	: Mon Aug  5 14:33:12 MET DST 1996
//
// Commentaires	: Inline de la classe Rectangles
//
//
//*****************************************************************************


inline double Rectangles::Xmin()	const
{
	return xmin;
}

inline double Rectangles::Ymin()	const
{
	return ymin;
}

inline double Rectangles::Xmax()	const
{
	return xmax;
}

inline double Rectangles::Ymax()	const
{
	return ymax;
}

inline const Rectangles& Rectangles::Xmin(double x)
{
	xmin=x;
	return *this;
}

inline const Rectangles& Rectangles::Ymin(double y)
{
	ymin=y;
	return *this;
}

inline const Rectangles& Rectangles::Xmax(double x)
{
	xmax=x;
	return *this;
}

inline const Rectangles& Rectangles::Ymax(double y)
{
	ymax=y;
	return *this;
}

