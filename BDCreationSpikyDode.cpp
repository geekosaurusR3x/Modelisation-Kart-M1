#include "StdAfx.h"
#include "BDCreationSpikyDode.h"

// Ces variables devraient �tre des membres de la classe mais c'est refus� par le compilateur
// car elle sont non manag�es, � l'inverse de BDCreationSpikyDode qui DOIT l'�tre car elle h�rite
// de System::Windows::Forms::Form --> en d�sespoir de cause, je les mets l�.
AttributsFaces		ApplicationRegainDeBase::AFSpikyDode ;
AttributsSolides	ApplicationRegainDeBase::ASSpikyDode ;
SolidesP			ApplicationRegainDeBase::LaSpikyDodeConstruite ;
const Materiaux		*ApplicationRegainDeBase::PMatSpikyDode ;	// Rappel : on manipule les mat�riaux au travers de pointeurs
