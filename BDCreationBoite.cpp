#include "StdAfx.h"
#include "BDCreationBoite.h"

// Ces variables devraient être des membres de la classe mais c'est refusé par le compilateur
// car elle sont non managées, à l'inverse de BDCreationBoite qui DOIT l'être car elle hérite
// de System::Windows::Forms::Form --> en désespoir de cause, je les mets là.
AttributsFaces		ApplicationRegainDeBase::AF ;
AttributsSolides	ApplicationRegainDeBase::AS ;
SolidesP			ApplicationRegainDeBase::LaBoiteConstruite ;
const Materiaux		*ApplicationRegainDeBase::PMat ;	// Rappel : on manipule les matériaux au travers de pointeurs
