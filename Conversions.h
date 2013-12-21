#pragma once

extern char * SystemStringVersCharEtoile (System::String ^S) ;
// PENSER A LIBERER LE RESULTAT avec un appel à delete []
// La chaîne vide contient '\0' donc il faut la libérer aussi.
