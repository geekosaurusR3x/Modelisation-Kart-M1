#pragma once

#include "AfficheurErreurs.h"

class AfficheurErreursGraphique :
	public AfficheurErreurs
{
public:
	AfficheurErreursGraphique(void);
	void AfficherUneErreur (const char *Msg, bool Fatale) ;

public:
	~AfficheurErreursGraphique(void);

};
