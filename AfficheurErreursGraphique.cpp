#include "StdAfx.h"
#include "AfficheurErreursGraphique.h"

AfficheurErreursGraphique::AfficheurErreursGraphique(void)
: AfficheurErreurs ()
{
	Initialiser (this) ;
}

void AfficheurErreursGraphique::AfficherUneErreur (const char *Msg, bool Fatale)
{
	System::String	^m = gcnew System::String (Msg);
	System::Windows::Forms::MessageBox::Show(	m, 
												"ATTENTION", 
												System::Windows::Forms::MessageBoxButtons::OK,
												System::Windows::Forms::MessageBoxIcon::Exclamation);
	
	if (Fatale)
		exit (1) ;
}

AfficheurErreursGraphique::~AfficheurErreursGraphique(void)
{
}
