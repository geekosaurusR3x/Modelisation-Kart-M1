#include "StdAfx.h"
#include "BDCreationBoite.h"

// Ces variables devraient �tre des membres de la classe mais c'est refus� par le compilateur
// car elle sont non manag�es, � l'inverse de BDCreationBoite qui DOIT l'�tre car elle h�rite
// de System::Windows::Forms::Form --> en d�sespoir de cause, je les mets l�.
AttributsFaces		ApplicationRegainDeBase::AF ;
AttributsSolides	ApplicationRegainDeBase::AS ;
SolidesP			ApplicationRegainDeBase::LaBoiteConstruite ;
const Materiaux		*ApplicationRegainDeBase::PMat ;	// Rappel : on manipule les mat�riaux au travers de pointeurs
