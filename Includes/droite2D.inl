//
// Module	: Droites2D
//
// Fichier	: Droites2D.inl
//
// Auteur	: Heschung Fr�d�ric
//
// Date creat.	:
//
// Version	: 1.0
//
// Commentaires	: Impl�mentation des fonctions inline de la classe Droites2D
//
// 2. Accesseurs
// 3. Modifications
// 4. M�thodes


// 2. Accesseurs

inline const Points3D & Droites2D::Point () const
{
	return point ;
}

inline const Vecteurs3D & Droites2D::Vecteur () const
{
	return vecteur ;
}

// 3. Modifications
inline void Droites2D::ModifPoint (const Points3D & P)
{
	point = P ;
}

inline void Droites2D::ModifVecteur (const Vecteurs3D & V)
{
	vecteur = V ;
}

inline double Droites2D::Lambda (const Points3D & P) const
{
	return Vecteurs3D (point , P).Norme () ;
}

inline void Droites2D::Cartesienne (double & a , double & b , double & c) const
// cette proc�dure calcule les coefficients de l'�quation
// cart�sienne de la droite courante
{
	a = -vecteur.Y () ;
	b = vecteur.X () ;
	c = -a * point.X () - b * point.Y ();
}