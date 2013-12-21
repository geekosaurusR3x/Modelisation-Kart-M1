//*****************************************************************************
// 
// Fichier	: MacroMath.h
// 
// Auteur	: Y. LANUEL							
// 
// Date creat.	: 27/05/96							
// 
// Commentaires	: Macros indispensables.
// 
// 
//*****************************************************************************


#define _USE_MATH_DEFINES

#include <cmath>
//#include	<values.h> // Pour MAXDOUBLE

#include "FLOAT.H"

#define	MIN(a,b)	((a)<(b)?(a):(b))
#define	MAX(a,b)	((a)>(b)?(a):(b))

#define	MIN3(a,b,c)	MIN(MIN(a,b),c)
#define	MAX3(a,b,c)	MAX(MAX(a,b),c)

#define	EPS2	0.01
#define	EPS4	0.0001
#define	EPS6	0.000001
#define	EPS8	0.00000001
#define	MaxReel	DBL_MAX
#define	PI	M_PI


#define	True	true
#define	False	false

#define	Egal(a,b,e)	(fabs((a)-(b)) < e ? True : False)
#define	Sup(a,b,e)	(((a)-(b))>e ? True : False)
#define	Inf(a,b,e)	(((b)-(a))>e ? True : False)
#define	InfEgal(a,b,e)	(((b)-(a))>-e ? True : False)
#define	SupEgal(a,b,e)	(((a)-(b))>-e ? True : False)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif


