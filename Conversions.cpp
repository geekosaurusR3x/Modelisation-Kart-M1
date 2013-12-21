#include "StdAfx.h"
#include <string>
#include "vcclr.h"

char * SystemStringVersCharEtoile (System::String ^S)
// PENSER A LIBERER LE RESULTAT avec un appel à delete []
// La chaîne vide contient '\0' donc il faut la libérer aussi.
{
	// Obtain a pointer to the System::String in order to
    // first lock memory into place, so that the
    // Garbage Collector (GC) cannot move that object
    // while we call native functions.
    pin_ptr<const wchar_t> wch = PtrToStringChars(S);

    // Make a copy of the system string as a multibyte
    // char* string. Allocate two bytes in the multibyte
    // output string for every wide character in the input
    // string, including space for a terminating null.
    size_t			origsize = wcslen(wch) + 1;
    const size_t	newsize = origsize*2;
    size_t			convertedChars = 0;

    char *nstring = new char[newsize];
    wcstombs_s(&convertedChars, nstring, newsize, wch, _TRUNCATE);
    return nstring ;
}