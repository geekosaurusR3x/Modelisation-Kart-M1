#include "StdAfx.h"
#include "BDCreationSpikyDode.h"

// Ces variables devraient être des membres de la classe mais c'est refusé par le compilateur
// car elle sont non managées, à l'inverse de BDCreationSpikyDode qui DOIT l'être car elle hérite
// de System::Windows::Forms::Form --> en désespoir de cause, je les mets là.
AttributsFaces		ApplicationRegainDeBase::AFSpikyDode ;
AttributsSolides	ApplicationRegainDeBase::ASSpikyDode ;
SolidesP			ApplicationRegainDeBase::LaSpikyDodeConstruite ;
const Materiaux		*ApplicationRegainDeBase::PMatSpikyDode ;	// Rappel : on manipule les matériaux au travers de pointeurs
