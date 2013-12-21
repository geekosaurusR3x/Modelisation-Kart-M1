#include "StdAfx.h"
#include "BDCreationEllipsoide.h"

// Ces variables devraient être des membres de la classe mais c'est refusé par le compilateur
// car elle sont non managées, à l'inverse de la boîte de dialogue  qui DOIT l'être car elle hérite
// de System::Windows::Forms::Form --> en désespoir de cause, je les mets là.
AttributsFaces		ApplicationRegainDeBase::AFEllipsoide ;
AttributsSolides	ApplicationRegainDeBase::ASEllipsoide ;
SolidesP			ApplicationRegainDeBase::LaEllipsoideConstruite ;
const Materiaux		*ApplicationRegainDeBase::PMatEllipsoide ;	// Rappel : on manipule les matériaux au travers de pointeurs
