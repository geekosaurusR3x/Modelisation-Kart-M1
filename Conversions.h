#pragma once

extern char * SystemStringVersCharEtoile (System::String ^S) ;
// PENSER A LIBERER LE RESULTAT avec un appel � delete []
// La cha�ne vide contient '\0' donc il faut la lib�rer aussi.
