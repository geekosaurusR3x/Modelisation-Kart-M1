#include "StdAfx.h"
#include "BDCreationEllipsoide.h"

// Ces variables devraient �tre des membres de la classe mais c'est refus� par le compilateur
// car elle sont non manag�es, � l'inverse de la bo�te de dialogue  qui DOIT l'�tre car elle h�rite
// de System::Windows::Forms::Form --> en d�sespoir de cause, je les mets l�.
AttributsFaces		ApplicationRegainDeBase::AFEllipsoide ;
AttributsSolides	ApplicationRegainDeBase::ASEllipsoide ;
SolidesP			ApplicationRegainDeBase::LaEllipsoideConstruite ;
const Materiaux		*ApplicationRegainDeBase::PMatEllipsoide ;	// Rappel : on manipule les mat�riaux au travers de pointeurs
