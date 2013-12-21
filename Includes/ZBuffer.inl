//*******************************************************************
//
// Fichier	: ZBuffer.inl
//
// Auteur	: Y. Lanuel
//
// Date		: 14 Octobre 1997
//
// Commentaires	: Inline de la classe ZBuffer
//
//*******************************************************************


#define	MODE_FIL_DE_FER		1
#define	MODE_LIGNES_CACHEES	2
#define	MODE_TACHE				3
#define	MODE_ECLAIRE			4


inline	void	ZBuffer::ModeFilDeFer ()
{
	_Mode = MODE_FIL_DE_FER;
	_ChangementMode	= true;
}


inline	void	ZBuffer::ModeLignesCachees ()
{
	_Mode = MODE_LIGNES_CACHEES;
	_ChangementMode	= true;
}


inline	void	ZBuffer::ModeTache ()
{
	_Mode = MODE_TACHE;
	_ChangementMode	= true;
}

inline	void	ZBuffer::ModeEclaire ()
{
	_Mode = MODE_ECLAIRE;
	_ChangementMode	= true;
}






