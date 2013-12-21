//---------------------------------------------------------------------------
#ifndef LogicielGraphiqueBaseH
#define LogicielGraphiqueBaseH
//---------------------------------------------------------------------------


#include "ContextesInteractions.h"
#include "ResultatsInteractions.h"
#include "EnsemblesOptionsDialogue.h"
#include "EnsemblesMenus.h"
#include "LiaisonZBufferBRep.h"		
#include "BibliothequeVisualiseur.h"
#include "Tableaux.h"
#include "TablesEfficaces.h"
#include "EnteteLGBDLL.h"

/////////////////////////////////////////////////////////
// Couleurs pr�d�finies par le Logiciel Graphique de Base
/////////////////////////////////////////////////////////
extern 
CouleursRGB			*PCouleurRouge,
					*PCouleurVert,
					*PCouleurBleu,
					*PCouleurBlanc,
					*PCouleurJaune,
					*PCouleurNoir,
					*PCouleurRose,
					*PCouleurViolet,
					*PCouleurFuschia,
					*PCouleurBrun,
					*PCouleurGris ;

/////////////////////////////////////////////////////////
// Materiaux pr�d�finis par le Logiciel Graphique de Base
/////////////////////////////////////////////////////////

// Mat�riaux pr�d�finis, utilisables dans l'application
extern
const Materiaux		*PMateriauParDefautDuLGB,
					*PMateriauRouge,
					*PMateriauVert,
					*PMateriauBleu,
					*PMateriauBlanc,
					*PMateriauJaune,
					*PMateriauNoir,
					*PMateriauRose,
					*PMateriauViolet,
					*PMateriauFuschia,
					*PMateriauBrun,
					*PMateriauGris ;


class LGB_DLL Espaces ;


class LGB_DLL LogicielsGraphiquesBase
{
public :
	// Acc�s au LGB par d�faut (le seul et unique LGB)
	static LogicielsGraphiquesBase * Defaut () ;

	void ModifierCamera (int NumeroEspace, const Cameras &Cam) ;
	// Change la cam�ra (oeil, mire et focale) de l'espace dont le num�ro
	// est fourni.
	// Ne met pas l'affichage � jour.

	void ModifierStudio (int NumeroEspace, const Studios &Cam) ;
	// Change le studio de l'espace dont le num�ro est fourni.
	// Ne met pas l'affichage � jour.

	void ModifierCouleurDeFond (CouleursRGB *, int NumeroEspace=-1) ;
	// ATTENTION : � l'inverse des fcts qui pr�c�dent, le num�ro d'espace
	// vient en dernier !!!
	// Change la couleur de fond de l'espace sp�cifi� ou de tous les
	// espaces d�clar�s � d�faut.
	// Attention : un changement ult�rieur du studio de ce ou de ces espace(s)
	// re-initialise la couleur de fond � la valeur par d�faut.
	// La couleur est dupliqu�e donc elle peut �tre d�truite apr�s l'appel si
	// elle n'est plus utile.

	const Cameras &ConsulterCamera (int NumeroEspace) ;
	// Restitue la cam�ra (oeil, mire et focale) de l'espace dont le num�ro
	// est fourni.

	const Studios &ConsulterStudio (int NumeroEspace) ;
	// Restitue le studio (sources lumineuses) de l'espace dont le num�ro
	// est fourni.

	void	FixerEloignementPlansClippingAvantArriere (int NumEsp, double distPlanProche, double distPlanEloigne);
	// Distance de l'oeil aux plans de clipping avant et arri�re lorsqu'on va de l'oeil vers
	// la mire. Cette distance doit �tre >= 0. Si elle est < 0, elle est
	// ramen�e � 0 (+Epsilon).
	// La premi�re distance indiqu�e est celle du plan le plus proche de l'oeil.

	///////////////////////////////////////////////////////////////////////////
	//
	// POUR TOUTES LES FONCTIONS D'AFFICHAGE CI-DESSOUS :
	//
	// diverses fonctions d'affichage de solides ou de faces avec des couleurs
	// par d�faut ou des couleurs impos�es.
	// L'affichage se fait par d�faut dans tous les espaces, c'est � dire si
	// le num�ro d'espace est -1 .
	// Le ou les objets affich�s sont ajout�s aux objets existants, sauf si
	// le param�tre ToutSeul est vrai.
	// Les attributs de solides (fournis � la construction du solide) ne 
	// sont pas utilis�s dans cette version.
	// Les attributs de faces le sont. Si une face n'a pas d'attribut, elle est affich�e
	// avec le mat�riel par d�faut du LGB (blanc).
	//
	// ATTENTION : le LGB conserve une trace des objets affich�s pour
	// optimiser les rafraichissements et affichages � venir. IL FAUT DONC
	// EFFACER les objets en pr�alable � leur destruction afin que le LGB ne
	// tente pas d'afficher des entit�s qui n'existent plus. Utiliser pour
	// cela les fonctions d'effacement qui suivent les fonctions d'affichage.
	//
	///////////////////////////////////////////////////////////////////////////

	void  AfficherSolide (SolidesP, int NumEsp=-1, bool ToutSeul = false) ;
	void  AfficherDesSolides (	Tableaux <SolidesP> &, int NumEsp=-1,
								bool ToutSeul = false) ;
	void  AfficherDesFaces (Tableaux <FacesP> &, int NumEsp=-1,
				bool ToutSeul = false) ;
	
	void  AfficherDesFaces (	Listes <FacesP> &LF,
					int NumEsp, bool ToutSeul) ;

	void AfficherTousLesSolides (int NumEsp=-1, bool ToutSeul = true) ;
	// ATTENTION : par d�faut, ToutSeul EST VRAI, contrairement aux autres fonctions
	// d'affichage.

	void AfficherTousLesSolidesEtFacesIsolees (int NumEsp=-1, bool ToutSeul = true) ;
	// ATTENTION : par d�faut, ToutSeul EST VRAI, contrairement aux autres fonctions
	// d'affichage.


	///////////////////////////////////////////////////////////////////////////
	//
	// Fonctions d'effacement de solides ou de faces de la liste des objets
	// affich�s. Les entit�s effac�es le sont dans l'espace indiqu�
	// seulement, dans tous les espaces si l'espace est -1, qui est la
	// valeur par d�faut.
	//
	///////////////////////////////////////////////////////////////////////////
	void ToutEffacer (int NumEsp=-1) ;
	void EffacerSolide (SolidesP S, int NumEsp=-1) ;
	void EffacerDesSolides (Tableaux <SolidesP> &, int NumEsp=-1) ;
	void EffacerDesFaces (Tableaux <FacesP> &, int NumEsp=-1) ;

	// Positionne la mire sur le barycentre de l'englobant de la face.
	// La focale n'est pas modifi�e. Il n'y a donc pas garantie que la face
	// soit enti�rement visible ou ne soit pas trop �loign�e.
	// Seuls les �l�ments d�j� affich�s restent � l'�cran. Aucun �l�ment
	// suppl�mentaire n'appara�t.
	// Par d�faut, l'op�ration concerne tous les espaces.
	void CadrageSurFace (FacesP &Face, int NumEsp=-1) ;

	// Positionne la mire sur le barycentre de l'englobant de toutes
	// les faces.
	// Positionne l'oeil � l'ext�rieur de l'englobant, "devant � droite".
	// � une distance de la mire un peu sup�rieure � 10 fois le c�t� de l'englobant.
	// La focale est calcul�e de mani�re � ce que toutes les faces soient
	// visibles.
	// Par d�faut, l'op�ration concerne tous les espaces.
	void CadrageSurFaces (Tableaux <FacesP> &TabFaces, int NumEsp=-1) ;

	// Positionne la mire sur le barycentre de l'englobant du solide.
	// La focale n'est pas modifi�e. Il n'y a donc pas garantie que le solide
	// soit enti�rement visible ou ne soit pas trop �loign�.
	// Seuls les �l�ments d�j� affich�s restent � l'�cran. Aucun �l�ment
	// suppl�mentaire n'appara�t.
	// Par d�faut, l'op�ration concerne tous les espaces.
	//
	// Des sources lumineuses sont plac�es sur les 8 sommets de l'englobant.
	//
	// ATTENTION : seules les entit�s affich�es avant le cadrage restent visibles.
	void CadrageSurSolide (SolidesP &Solide, int NumEsp=-1) ;

	// Positionne la mire au milieu des objets existants. Ce milieu
	// est le centre de l'englobant des objets existants.
	// Positionne l'oeil � l'ext�rieur de l'englobant, "devant � droite".
	// � une distance de la mire un peu sup�rieure � 10 fois le c�t� de l'englobant.
	// La focale est calcul�e de mani�re � ce que toute la sc�ne soit visible.
	// Par d�faut, l'op�ration concerne tous les espaces.
	//
	// Des sources lumineuses sont plac�es sur les 8 sommets de l'englobant.
	//
	// ATTENTION : seules les entit�s affich�es avant le cadrage restent visibles.
	void CadrageSurScene (int NumEsp=-1) ;

	// Active ou desactive l'�limination des faces arri�res dans l'espace
	// sp�cifi�, ou dans tous les espaces si le num�ro est -1.
	// Il est n�cessaire de d�sactiver l'�limination des faces
	// arri�res quand on affiche autre chose que des solides.
	void	ActiverExploitationFacesArrieres (int NumeroEspace=-1) ;
	void	DesactiverExploitationFacesArrieres (int NumeroEspace=-1) ;

	// FONCTION RESERVEE A FRED HESCHUNG !!! Elle efface les faces
	// arri�res sans les d�truire.
	void EffacerFacesArrieres () ;

	// La structure qui contient tous les r�sultats de la derni�re
	// interaction en date. Faudrait la rendre priv�e et �crire les fonctions
	// d'acc�s ...
	// Voir la classe ResultatsInteractions pour les d�tails.
	ResultatsInteractions	ResultatsInteraction ;

	void FixerContexteProchaineInteraction (	const char *MessageBarreEtat,
												const EnsemblesOptionsDialogue &EOD,
                                   				const	EnsemblesMenus &EM,
                                   				TraitementsInteractifs *TI) ;

	int LogicielsGraphiquesBase::AjouterEspace (	HDC Hdc, int xhg, int yhg, int largeur, int hauteur,
													Vues *V,
													ZBuffer *AV) ;
	// Ajoute un triplet Vue/Cloture/AlgoVisu (= 1 espace) au LGB et restitue le
	// num�ro de l'espace cr��. La num�rotation commence � 0.
	// En cas d'�chec, on retourne -1.
	//
	// Attention: on ne v�rifie pas que la cl�ture n'appartient pas d�j� � un
	// espace !!! --> s'en assurer � l'ext�rieur.
	//
	// On peut ne pas fournir la vue et l'algo de visu (NULL pour les param
	// non renseign�s). Dans ce cas, une vue et/ou un algo de visu par
	// d�faut sont attribu�s.
	//
	// Les vues et les algos de visu sont utiles parce que l'on veut que le LGB g�re la
	// d�signation. Il faut donc qu'il ait connaissance des faces affich�es.
	// Pour cela, deux possibilit�s :
	// .	soit c'est une fonction ext�rieure au LGB qui affiche les solides et
	//		cette derni�re doit alors informer le LGB des faces qu'elle a
	//		affich�es,
	// .	soit c'est le LGB qui offre ce service et dans ce cas il doit
	//		conna�tre la vue et l'algo d'affichage. C'est le deuxi�me choix qui
	//		a �t� fait.

	void AllumerPixel (int NumEsp, int x, int y, CouleursRGB *Coul) ;

	int NombreEspaces () const ;
	// Restitue le nombre d'espaces g�r�s par le LGB (c'est le m�me que le
	// nombre de cl�tures

	Espaces & IemeEspace (int i) ;

	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	//
	// LES FONCTIONS QUI SUIVENT, AUSSI BIEN DANS LA CLASSE LGB QUE DANS LES
	// CLASSES SUIVANTES, NE SONT PAS UTILES AUX PROGRAMMEURS D'APPLICATIONS
	//
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	void ZoomIn (Espaces &Espace) ;
	// On augmente la focale de 10 %

	void ZoomOut (Espaces &Espace) ;
	// On r�duit la focale de 10 %

	void LookRight (Espaces &Espace) ;
	// On tourne la mire � droite de AngleDeplacement radians

	void LookLeft (Espaces &Espace) ;
	// On tourne la mire � gauche de AngleDeplacement radians

	void LookUp (Espaces &Espace) ;
	// On tourne la mire vers le haut de AngleDeplacement radians

	void LookDown (Espaces &Espace) ;
	// On tourne la mire vers le bas de AngleDeplacement radians

	void Backwards (Espaces &Espace) ;
	// On avance l'oeil et la mire selon le Regard d'une distance �gale
	// � FractionDistanceOeilMire % de la distance Oeil,Mire

	void Forwards (Espaces &Espace) ;
	// On recule l'oeil et la mire selon le Regard d'une distance �gale
	// � FractionDistanceOeilMire % de la distance Oeil,Mire

	void TurnRight (Espaces &Espace) ;
	// On tourne l'oeil vers la droite

	void TurnLeft (Espaces &Espace) ;
	// On tourne l'oeil vers la gauche

	void TurnDown (Espaces &Espace) ;
	// On tourne l'oeil vers le bas

	void TurnUp (Espaces &Espace) ;
	// On tourne l'oeil vers le haut

	int TrouverEspace (const Espaces &Espace) ;
	// retrouve le num�ro de l'espace

	void	GestionClickSourisCloture (int X, int Y, int Bouton, int NumEsp) ;
	// Gestion d'un click dans la cl�ture: on regarde si l'une des options
	// de dialogue du contexte d'interaction courant peut �tre satisfaite
	// par le click.
	// Cloture est la cl�ture dans laquelle le click a �t� fait,

	void	GestionMouvementSourisCloture (	int X, int Y,
											int NumEsp) ;
	//                                          TImage *Cloture) ;
	// Gestion d'un mouvement de la souris dans la cl�ture: on regarde si
	// l'une des options de dialogue du contexte d'interaction courant peut
	// �tre satisfaite par le mouvement.
	// Cloture est la cl�ture dans laquelle le mouvement a �t� fait,

	virtual ~LogicielsGraphiquesBase () ;
	// Ca, vu le nom, on dirait bien que c'est le destructeur de LGB ...

	// Redessine tout ce qui est actuellement affich�, dans tous les
	// espaces d�clar�s si NumEsp = -1, dans l'espace d�sign� sinon.
	void Rafraichir (int NumEsp = -1) ;		// La bonne orthographe
	void Raffraichir (int NumEsp = -1) ;	// La mauvaise orthographe ...

	// Les fonctions n�cessaires aux bo�tes de dialogue pour l'acquisition
	// d'un point
	virtual	int		ConstruireEtMontrerBDAcqPoint (const char *) = 0 ;
	virtual	void	CacherEtDetruireBDAcqPoint (int NumeroBD) = 0 ;
	virtual	void	MontrerBDAcqPoint (int NumeroBD) = 0 ;
	virtual	void	CacherBDAcqPoint (int NumeroBD) = 0 ;

	void InitialView (Espaces &Espace) ;
	// On remet oeil, mire et focale initiaux.

	// Change le mode de visu dans un ou tous les espaces
	void ModeFilDeFer (int NumEsp = -1) ;
	void ModeEclaire (int NumEsp) ;

	// Interruption du traitement interactif en cours
	void LogicielsGraphiquesBase::InterruptionTraitementInteractif () ;

protected :
	static void InitialiserUniqueLGB (LogicielsGraphiquesBase *LGB) ;

	virtual void AfficherMessageBarreEtat (char *) = 0 ;
	// Affiche le message dans la barre d'�tat instanci�e par l'application
	// et connue par une classe d�riv�e.

	void	EmpilerLeContexteInteraction () ;
	// Place le contexte d'interaction courant en premi�re position de la file
	// d'attente

	void	DepilerUnContexteInteraction () ;
	// Place, dans le contexte d'interaction courant, le contexte d'interaction en
	// premi�re position de la file d'attente

	void	ClotureFenetre (int NumEsp,int X, int Y,Points3D *P) ;
	// transforme le pixel X,Y de la cl�ture en un point 3D du
	// plan de projection.

	LogicielsGraphiquesBase () ;
	// Le constructeur est interdit d'utilisation puisque le LGB est un singleton

private :
	void	ClotureFenetre (Espaces &E,int X, int Y,Points3D *P) ;
	// transforme le pixel X,Y de la cl�ture en un point 3D du
	// plan de projection.

	//Espaces & TrouverEspace (const Panel *Cloture) ;
	Espaces & TrouverEspace (const HDC Hdc) ;
	// retrouve l'adresse de l'espace qui utilise la cl�ture pass�e en param�tre


	bool UneFaceEstDesignee	(	const Points3D P, const Points3D Oeil,
   									TablesEfficaces <FacesP> &TF,
   									FacesP *Face) ;
	// vrai si le rayon (Oeil,P) traverse une face affich�e

	void CalculAngleSinEtCos (	const Points3D &Oeil,
   									const Vecteurs3D &OeilMireNorme,
                              const Points3D &P,
                              double &angle,
                              double &s, double &c) ;

	double CalculFocale (	const Points3D &Oeil,
   							const Vecteurs3D &OeilMireNorme,
							const Points3D &PMin,
							const Points3D &PMax,
							const Points3D &P3,
							const Points3D &P4,
							const Points3D &P5,
							const Points3D &P6,
							const Points3D &P7,
							const Points3D &P8,
							int		NumEsp) ;

	void FinCadrage (const Englobants3D &EnglobantScene, int NumEsp) ;
	// Fin commune de CadrageSurScene et CadrageSurFaces

	void SauverClotureDansFichier(int NumEsp, char * NomFichier) ;
	// Sauvegarde de l'image de la cl�ture d'un espace dans un fichier

	// la variable qui contient l'action interactive en cours et les options
	// de dialogue qui permettraient de la r�veiller
	ContextesInteractions	ContexteInteraction ;

	// La pile des contextes d'interaction en attente
	Listes <ContextesInteractions>	PileContextes ;

	// Liste des espaces (1 espace = 1 triplet cloture/algovisu/Vue). Chaque
	// espace m�morise les faces qu'il affiche.
	Tableaux <Espaces>		TableauEspaces ;
} ;


class Espaces
{
public:
	Espaces () ;
	Espaces (Vues *V, HDC HdcClot, int xhg, int yhg, int largeur, int hauteur, ZBuffer *AV) ;
	~Espaces () ;
	friend bool operator == (const Espaces &E1, const Espaces &E2) ;

	/*	bool ContientOption (TMenuItem *Option) ;
	// Vraie si le Popup associ� contient l'option pass�e en param�tre*/

	void ModifierMire (const Points3D &NouvelleMire) ;
	// Change la mire et met le rep�re de visualisation � jour. N'affiche pas.

	void ModifierOeil (const Points3D &NouvelOeil) ;
	// Change l'oeil et met le rep�re de visualisation � jour. N'affiche pas.

	void ModifierOeilEtMire (const Points3D &NouvelOeil, const Points3D &NouvelleMire) ;
	// Change l'oeil, la mire et met le rep�re de visualisation � jour.
	// N'affiche pas.

	void ModifierCamera (const Cameras &Cam) ;
	// Change la cam�ra (oeil, mire et focale) et met le rep�re de
   // visualisation � jour.
	// N'affiche pas.

	void ModifierStudio (const Studios &St) ;
	// Change le studio.
	// N'affiche pas.


	bool EffacerUneFace (FacesP F) ;
	// Retire une face de l'ensemble des faces affich�es, retire les
	// ObjetsVisualisables qui lui correspondent de la sc�ne et les lib�re

   const Espaces & operator = (const Espaces &E) ;
   // L'affectation ne fait qu'utiliser les affectations des donn�es membres.
   // --> y a duplication partielle (de la scene et des FacesAffichees)
   // --> N'utiliser l'affectation que lorsque l'espace ne contient encore
   // rien, cad lorsque Scene et FacesAffichees sont encore vides.

   // FONCTION RESERVEE A FRED HESCHUNG !!! Elle efface les faces
   // arri�res sans les d�truire.
   void EffacerFacesArrieres () ;


private:
	Espaces (const Espaces &E)
	{
	}

	void LibererCouplesPointeursFacesAffichees () ;
	// D�salloue les couples de pointeurs associ�s aux faces affich�es

	void ViderScene () ;
	// Lib�re les objets visualisables dans la sc�ne.

	void MiseAJourRepereVisualisation () ;
	// Mise � jour du rep�re de visualisation (Regard, Haut, Droite) APRES
	// modification de l'oeil et/ou de la mire.
	// ATTENTION : cette fonction ne doit �tre utilis�e qu'apr�s une modification,
	// PAS POUR UNE INITIALISATION du rep�re.

	Vues					*Vue ;
	HDC						Cloture ;
	int						Xhg, Yhg, Largeur, Hauteur ;
	ZBuffer					*AlgoVisu ;

	// Ce TImage est superpos� � la zone client du TPanel. Il
	// sert � acc�der directement aux pixels du TPanel
	//   TImage					*ClotureEnPixels ;

	// le bool�en qui suit est vrai tant que l'�clairage du studio est celui
	// par d�faut. Tant que c'est le cas, la s�lection de "I'm lost" ou
	// "Display all" recalcule les sources lumineuses.
	bool						EclairageParDefaut ;

	// Liste des faces actuellement affich�es
	TablesEfficaces <FacesP>	FacesAffichees ;

	// La vue contient l'oeil et la mire. On conserve en plus divers vecteurs
	// pour faciliter les mouvements.
	Vecteurs3D				Regard,		// vecteur Oeil-->Mire norm�
							Haut,		// vecteur Pied-->Tete norm� de l'observateur
							Droite ;	// vecteur Epaule-->Main droite norm� lorsque l'observateur a les bras �cart�s.
										// (Droite,Regard,Haut) forment un tri�dre direct.

friend class LogicielsGraphiquesBase ;
} ;

/*class LGB_DLL GestionEvenements
{
public:
	GestionEvenements () ;
	~GestionEvenements () ;

	// Gestion du click souris dans la cl�ture
	void __fastcall ClotureMouseDown (TObject *Sender,TMouseButton Button, TShiftState Shift, int X, int Y) ;

	// Gestion du mouvement souris dans la cl�ture
	void __fastcall ClotureMouseMove (TObject *Sender,TShiftState Shift, int X, int Y) ;

	// Gestion de l'option Annulation du Popup associ� � chaque cl�ture : on
	// interrompt le traitement interactif en cours, s'il y en a un
	void __fastcall MenuAnnulationClick(TObject *Sender) ;

	// Gestion de l'option DisplayAllSolids du Popup associ� �
	// chaque cl�ture : on efface tout et on redessine tous les solides dans
	// la cl�ture d'o� �mane la demande.
	void __fastcall MenuDisplayAllSolidsClick (TObject *Sender) ;

	// Gestion de l'option Zoom du Popup associ� � chaque cl�ture
	void __fastcall MenuZoomClick(TObject *Sender) ;

	// Gestion de l'option "regarder ailleurs" du Popup associ� � chaque cl�ture
	void __fastcall MenuLookElseWhereClick (TObject *Sender) ;

	// Gestion de l'option "avancer/reculer" du Popup associ� � chaque cl�ture
	void __fastcall MenuForwardsBackwardsClick (TObject *Sender) ;

	// Gestion de l'option "tourner autour" du Popup associ� � chaque cl�ture
	void __fastcall MenuTurnAroundClick (TObject *Sender) ;

	// Gestion de l'option "TargetAtASolid" du Popup associ� � chaque cl�ture
	void __fastcall MenuTargetAtASolidClick (TObject *Sender) ;

	// Gestion de l'option "TargetAtAFace" du Popup associ� � chaque cl�ture
	void __fastcall MenuTargetAtAFaceClick (TObject *Sender) ;

	// Gestion de l'option "mode fil de fer" du Popup associ� � chaque cl�ture
	void __fastcall MenuWireFrameModeClick (TObject *Sender) ;

	// Gestion de l'option "mode ombr�" du Popup associ� � chaque cl�ture
	void __fastcall MenuShadedModeClick (TObject *Sender) ;

	// Gestion de l'option "vue initiale" du Popup associ� � chaque cl�ture
	void __fastcall MenuVueGenerale (TObject *Sender) ;

	// Gestion de l'option "Snapshot" du Popup associ� � chaque cl�ture
	void __fastcall MenuSnapshot (TObject *Sender) ;

	void __fastcall OnPaintFiche(TObject *Sender) ;
	// Fonction associ�e � l'�v�nement OnPaint de la fiche.
	// Mettre la dedans tout ce qu'il faut faire en cas de dessin de la fiche.
	// En fait, seul le contenu des cl�tures n'est pas g�r� par Builder. On
	// redessine donc le contenu des cl�tures.
	// Cette fonction est, entre autres, appel�e au d�but de l'ex�cution. C'est
	// elle qui fait que les objets dont on a demand� l'affichage dans le
   // constructeur de la fiche deviennent visibles : en effet, l'ex�cution
   // du constructeur de la fiche est SUIVIE du dessin des composants
   // graphiques. Donc les cl�tures apparaissent, se remplissent de noir
   // et effacent ce que l'on a affich� dans le constructeur. Il faut donc
   // demander de raffraichir les cl�tures apr�s le constructeur et on
   // choisit de le faire dans le OnPaint.

private:
} ;



*/



#endif
