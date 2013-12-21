#include "StdAfx.h"
#include "BDCreationSphere.h"

// Ces variables devraient être des membres de la classe mais c'est refusé par le compilateur
// car elle sont non managées, à l'inverse de la boîte de dialogue  qui DOIT l'être car elle hérite
// de System::Windows::Forms::Form --> en désespoir de cause, je les mets là.
AttributsFaces		ApplicationRegainDeBase::AFSphere ;
AttributsSolides	ApplicationRegainDeBase::ASSphere ;
SolidesP			ApplicationRegainDeBase::LaSphereConstruite ;
const Materiaux		*ApplicationRegainDeBase::PMatSphere ;	// Rappel : on manipule les matériaux au travers de pointeurs
