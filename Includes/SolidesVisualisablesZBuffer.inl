//*******************************************************************
//
// Fichier	: SolidesVisualisablesOpenGl.inl
//
// Auteur	: Y. Lanuel
//
// Date		: 14 Octobre 1997
//
// Commentaires	: Inline de la classe SolidesVisualisablesOpenGl
//
//*******************************************************************


inline const Listes<PolygonesVisualisablesZBuffer*>&	SolidesVisualisablesZBuffer::Liste() const
{
	return L;
}


inline int SolidesVisualisablesZBuffer::NombreFaces() const
{
	return NbFaces;
}



