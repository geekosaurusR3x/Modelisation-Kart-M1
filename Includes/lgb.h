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
// Couleurs prédéfinies par le Logiciel Graphique de Base
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
// Materiaux prédéfinis par le Logiciel Graphique de Base
/////////////////////////////////////////////////////////

// Matériaux prédéfinis, utilisables dans l'application
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
	// Accès au LGB par défaut (le seul et unique LGB)
	static LogicielsGraphiquesBase * Defaut () ;

	void ModifierCamera (int NumeroEspace, const Cameras &Cam) ;
	// Change la caméra (oeil, mire et focale) de l'espace dont le numéro
	// est fourni.
	// Ne met pas l'affichage à jour.

	void ModifierStudio (int NumeroEspace, const Studios &Cam) ;
	// Change le studio de l'espace dont le numéro est fourni.
	// Ne met pas l'affichage à jour.

	void ModifierCouleurDeFond (CouleursRGB *, int NumeroEspace=-1) ;
	// ATTENTION : à l'inverse des fcts qui précèdent, le numéro d'espace
	// vient en dernier !!!
	// Change la couleur de fond de l'espace spécifié ou de tous les
	// espaces déclarés à défaut.
	// Attention : un changement ultérieur du studio de ce ou de ces espace(s)
	// re-initialise la couleur de fond à la valeur par défaut.
	// La couleur est dupliquée donc elle peut être détruite après l'appel si
	// elle n'est plus utile.

	const Cameras &ConsulterCamera (int NumeroEspace) ;
	// Restitue la caméra (oeil, mire et focale) de l'espace dont le numéro
	// est fourni.

	const Studios &ConsulterStudio (int NumeroEspace) ;
	// Restitue le studio (sources lumineuses) de l'espace dont le numéro
	// est fourni.

	void	FixerEloignementPlansClippingAvantArriere (int NumEsp, double distPlanProche, double distPlanEloigne);
	// Distance de l'oeil aux plans de clipping avant et arrière lorsqu'on va de l'oeil vers
	// la mire. Cette distance doit être >= 0. Si elle est < 0, elle est
	// ramenée à 0 (+Epsilon).
	// La première distance indiquée est celle du plan le plus proche de l'oeil.

	///////////////////////////////////////////////////////////////////////////
	//
	// POUR TOUTES LES FONCTIONS D'AFFICHAGE CI-DESSOUS :
	//
	// diverses fonctions d'affichage de solides ou de faces avec des couleurs
	// par défaut ou des couleurs imposées.
	// L'affichage se fait par défaut dans tous les espaces, c'est à dire si
	// le numéro d'espace est -1 .
	// Le ou les objets affichés sont ajoutés aux objets existants, sauf si
	// le paramètre ToutSeul est vrai.
	// Les attributs de solides (fournis à la construction du solide) ne 
	// sont pas utilisés dans cette version.
	// Les attributs de faces le sont. Si une face n'a pas d'attribut, elle est affichée
	// avec le matériel par défaut du LGB (blanc).
	//
	// ATTENTION : le LGB conserve une trace des objets affichés pour
	// optimiser les rafraichissements et affichages à venir. IL FAUT DONC
	// EFFACER les objets en préalable à leur destruction afin que le LGB ne
	// tente pas d'afficher des entités qui n'existent plus. Utiliser pour
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
	// ATTENTION : par défaut, ToutSeul EST VRAI, contrairement aux autres fonctions
	// d'affichage.

	void AfficherTousLesSolidesEtFacesIsolees (int NumEsp=-1, bool ToutSeul = true) ;
	// ATTENTION : par défaut, ToutSeul EST VRAI, contrairement aux autres fonctions
	// d'affichage.


	///////////////////////////////////////////////////////////////////////////
	//
	// Fonctions d'effacement de solides ou de faces de la liste des objets
	// affichés. Les entités effacées le sont dans l'espace indiqué
	// seulement, dans tous les espaces si l'espace est -1, qui est la
	// valeur par défaut.
	//
	///////////////////////////////////////////////////////////////////////////
	void ToutEffacer (int NumEsp=-1) ;
	void EffacerSolide (SolidesP S, int NumEsp=-1) ;
	void EffacerDesSolides (Tableaux <SolidesP> &, int NumEsp=-1) ;
	void EffacerDesFaces (Tableaux <FacesP> &, int NumEsp=-1) ;

	// Positionne la mire sur le barycentre de l'englobant de la face.
	// La focale n'est pas modifiée. Il n'y a donc pas garantie que la face
	// soit entièrement visible ou ne soit pas trop éloignée.
	// Seuls les éléments déjà affichés restent à l'écran. Aucun élément
	// supplémentaire n'apparaît.
	// Par défaut, l'opération concerne tous les espaces.
	void CadrageSurFace (FacesP &Face, int NumEsp=-1) ;

	// Positionne la mire sur le barycentre de l'englobant de toutes
	// les faces.
	// Positionne l'oeil à l'extérieur de l'englobant, "devant à droite".
	// à une distance de la mire un peu supérieure à 10 fois le côté de l'englobant.
	// La focale est calculée de manière à ce que toutes les faces soient
	// visibles.
	// Par défaut, l'opération concerne tous les espaces.
	void CadrageSurFaces (Tableaux <FacesP> &TabFaces, int NumEsp=-1) ;

	// Positionne la mire sur le barycentre de l'englobant du solide.
	// La focale n'est pas modifiée. Il n'y a donc pas garantie que le solide
	// soit entièrement visible ou ne soit pas trop éloigné.
	// Seuls les éléments déjà affichés restent à l'écran. Aucun élément
	// supplémentaire n'apparaît.
	// Par défaut, l'opération concerne tous les espaces.
	//
	// Des sources lumineuses sont placées sur les 8 sommets de l'englobant.
	//
	// ATTENTION : seules les entités affichées avant le cadrage restent visibles.
	void CadrageSurSolide (SolidesP &Solide, int NumEsp=-1) ;

	// Positionne la mire au milieu des objets existants. Ce milieu
	// est le centre de l'englobant des objets existants.
	// Positionne l'oeil à l'extérieur de l'englobant, "devant à droite".
	// à une distance de la mire un peu supérieure à 10 fois le côté de l'englobant.
	// La focale est calculée de manière à ce que toute la scène soit visible.
	// Par défaut, l'opération concerne tous les espaces.
	//
	// Des sources lumineuses sont placées sur les 8 sommets de l'englobant.
	//
	// ATTENTION : seules les entités affichées avant le cadrage restent visibles.
	void CadrageSurScene (int NumEsp=-1) ;

	// Active ou desactive l'élimination des faces arrières dans l'espace
	// spécifié, ou dans tous les espaces si le numéro est -1.
	// Il est nécessaire de désactiver l'élimination des faces
	// arrières quand on affiche autre chose que des solides.
	void	ActiverExploitationFacesArrieres (int NumeroEspace=-1) ;
	void	DesactiverExploitationFacesArrieres (int NumeroEspace=-1) ;

	// FONCTION RESERVEE A FRED HESCHUNG !!! Elle efface les faces
	// arrières sans les détruire.
	void EffacerFacesArrieres () ;

	// La structure qui contient tous les résultats de la dernière
	// interaction en date. Faudrait la rendre privée et écrire les fonctions
	// d'accès ...
	// Voir la classe ResultatsInteractions pour les détails.
	ResultatsInteractions	ResultatsInteraction ;

	void FixerContexteProchaineInteraction (	const char *MessageBarreEtat,
												const EnsemblesOptionsDialogue &EOD,
                                   				const	EnsemblesMenus &EM,
                                   				TraitementsInteractifs *TI) ;

	int LogicielsGraphiquesBase::AjouterEspace (	HDC Hdc, int xhg, int yhg, int largeur, int hauteur,
													Vues *V,
													ZBuffer *AV) ;
	// Ajoute un triplet Vue/Cloture/AlgoVisu (= 1 espace) au LGB et restitue le
	// numéro de l'espace créé. La numérotation commence à 0.
	// En cas d'échec, on retourne -1.
	//
	// Attention: on ne vérifie pas que la clôture n'appartient pas déjà à un
	// espace !!! --> s'en assurer à l'extérieur.
	//
	// On peut ne pas fournir la vue et l'algo de visu (NULL pour les param
	// non renseignés). Dans ce cas, une vue et/ou un algo de visu par
	// défaut sont attribués.
	//
	// Les vues et les algos de visu sont utiles parce que l'on veut que le LGB gère la
	// désignation. Il faut donc qu'il ait connaissance des faces affichées.
	// Pour cela, deux possibilités :
	// .	soit c'est une fonction extérieure au LGB qui affiche les solides et
	//		cette dernière doit alors informer le LGB des faces qu'elle a
	//		affichées,
	// .	soit c'est le LGB qui offre ce service et dans ce cas il doit
	//		connaître la vue et l'algo d'affichage. C'est le deuxième choix qui
	//		a été fait.

	void AllumerPixel (int NumEsp, int x, int y, CouleursRGB *Coul) ;

	int NombreEspaces () const ;
	// Restitue le nombre d'espaces gérés par le LGB (c'est le même que le
	// nombre de clôtures

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
	// On réduit la focale de 10 %

	void LookRight (Espaces &Espace) ;
	// On tourne la mire à droite de AngleDeplacement radians

	void LookLeft (Espaces &Espace) ;
	// On tourne la mire à gauche de AngleDeplacement radians

	void LookUp (Espaces &Espace) ;
	// On tourne la mire vers le haut de AngleDeplacement radians

	void LookDown (Espaces &Espace) ;
	// On tourne la mire vers le bas de AngleDeplacement radians

	void Backwards (Espaces &Espace) ;
	// On avance l'oeil et la mire selon le Regard d'une distance égale
	// à FractionDistanceOeilMire % de la distance Oeil,Mire

	void Forwards (Espaces &Espace) ;
	// On recule l'oeil et la mire selon le Regard d'une distance égale
	// à FractionDistanceOeilMire % de la distance Oeil,Mire

	void TurnRight (Espaces &Espace) ;
	// On tourne l'oeil vers la droite

	void TurnLeft (Espaces &Espace) ;
	// On tourne l'oeil vers la gauche

	void TurnDown (Espaces &Espace) ;
	// On tourne l'oeil vers le bas

	void TurnUp (Espaces &Espace) ;
	// On tourne l'oeil vers le haut

	int TrouverEspace (const Espaces &Espace) ;
	// retrouve le numéro de l'espace

	void	GestionClickSourisCloture (int X, int Y, int Bouton, int NumEsp) ;
	// Gestion d'un click dans la clôture: on regarde si l'une des options
	// de dialogue du contexte d'interaction courant peut être satisfaite
	// par le click.
	// Cloture est la clôture dans laquelle le click a été fait,

	void	GestionMouvementSourisCloture (	int X, int Y,
											int NumEsp) ;
	//                                          TImage *Cloture) ;
	// Gestion d'un mouvement de la souris dans la clôture: on regarde si
	// l'une des options de dialogue du contexte d'interaction courant peut
	// être satisfaite par le mouvement.
	// Cloture est la clôture dans laquelle le mouvement a été fait,

	virtual ~LogicielsGraphiquesBase () ;
	// Ca, vu le nom, on dirait bien que c'est le destructeur de LGB ...

	// Redessine tout ce qui est actuellement affiché, dans tous les
	// espaces déclarés si NumEsp = -1, dans l'espace désigné sinon.
	void Rafraichir (int NumEsp = -1) ;		// La bonne orthographe
	void Raffraichir (int NumEsp = -1) ;	// La mauvaise orthographe ...

	// Les fonctions nécessaires aux boîtes de dialogue pour l'acquisition
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
	// Affiche le message dans la barre d'état instanciée par l'application
	// et connue par une classe dérivée.

	void	EmpilerLeContexteInteraction () ;
	// Place le contexte d'interaction courant en première position de la file
	// d'attente

	void	DepilerUnContexteInteraction () ;
	// Place, dans le contexte d'interaction courant, le contexte d'interaction en
	// première position de la file d'attente

	void	ClotureFenetre (int NumEsp,int X, int Y,Points3D *P) ;
	// transforme le pixel X,Y de la clôture en un point 3D du
	// plan de projection.

	LogicielsGraphiquesBase () ;
	// Le constructeur est interdit d'utilisation puisque le LGB est un singleton

private :
	void	ClotureFenetre (Espaces &E,int X, int Y,Points3D *P) ;
	// transforme le pixel X,Y de la clôture en un point 3D du
	// plan de projection.

	//Espaces & TrouverEspace (const Panel *Cloture) ;
	Espaces & TrouverEspace (const HDC Hdc) ;
	// retrouve l'adresse de l'espace qui utilise la clôture passée en paramètre


	bool UneFaceEstDesignee	(	const Points3D P, const Points3D Oeil,
   									TablesEfficaces <FacesP> &TF,
   									FacesP *Face) ;
	// vrai si le rayon (Oeil,P) traverse une face affichée

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
	// Sauvegarde de l'image de la clôture d'un espace dans un fichier

	// la variable qui contient l'action interactive en cours et les options
	// de dialogue qui permettraient de la réveiller
	ContextesInteractions	ContexteInteraction ;

	// La pile des contextes d'interaction en attente
	Listes <ContextesInteractions>	PileContextes ;

	// Liste des espaces (1 espace = 1 triplet cloture/algovisu/Vue). Chaque
	// espace mémorise les faces qu'il affiche.
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
	// Vraie si le Popup associé contient l'option passée en paramètre*/

	void ModifierMire (const Points3D &NouvelleMire) ;
	// Change la mire et met le repère de visualisation à jour. N'affiche pas.

	void ModifierOeil (const Points3D &NouvelOeil) ;
	// Change l'oeil et met le repère de visualisation à jour. N'affiche pas.

	void ModifierOeilEtMire (const Points3D &NouvelOeil, const Points3D &NouvelleMire) ;
	// Change l'oeil, la mire et met le repère de visualisation à jour.
	// N'affiche pas.

	void ModifierCamera (const Cameras &Cam) ;
	// Change la caméra (oeil, mire et focale) et met le repère de
   // visualisation à jour.
	// N'affiche pas.

	void ModifierStudio (const Studios &St) ;
	// Change le studio.
	// N'affiche pas.


	bool EffacerUneFace (FacesP F) ;
	// Retire une face de l'ensemble des faces affichées, retire les
	// ObjetsVisualisables qui lui correspondent de la scène et les libère

   const Espaces & operator = (const Espaces &E) ;
   // L'affectation ne fait qu'utiliser les affectations des données membres.
   // --> y a duplication partielle (de la scene et des FacesAffichees)
   // --> N'utiliser l'affectation que lorsque l'espace ne contient encore
   // rien, cad lorsque Scene et FacesAffichees sont encore vides.

   // FONCTION RESERVEE A FRED HESCHUNG !!! Elle efface les faces
   // arrières sans les détruire.
   void EffacerFacesArrieres () ;


private:
	Espaces (const Espaces &E)
	{
	}

	void LibererCouplesPointeursFacesAffichees () ;
	// Désalloue les couples de pointeurs associés aux faces affichées

	void ViderScene () ;
	// Libère les objets visualisables dans la scène.

	void MiseAJourRepereVisualisation () ;
	// Mise à jour du repère de visualisation (Regard, Haut, Droite) APRES
	// modification de l'oeil et/ou de la mire.
	// ATTENTION : cette fonction ne doit être utilisée qu'après une modification,
	// PAS POUR UNE INITIALISATION du repère.

	Vues					*Vue ;
	HDC						Cloture ;
	int						Xhg, Yhg, Largeur, Hauteur ;
	ZBuffer					*AlgoVisu ;

	// Ce TImage est superposé à la zone client du TPanel. Il
	// sert à accéder directement aux pixels du TPanel
	//   TImage					*ClotureEnPixels ;

	// le booléen qui suit est vrai tant que l'éclairage du studio est celui
	// par défaut. Tant que c'est le cas, la sélection de "I'm lost" ou
	// "Display all" recalcule les sources lumineuses.
	bool						EclairageParDefaut ;

	// Liste des faces actuellement affichées
	TablesEfficaces <FacesP>	FacesAffichees ;

	// La vue contient l'oeil et la mire. On conserve en plus divers vecteurs
	// pour faciliter les mouvements.
	Vecteurs3D				Regard,		// vecteur Oeil-->Mire normé
							Haut,		// vecteur Pied-->Tete normé de l'observateur
							Droite ;	// vecteur Epaule-->Main droite normé lorsque l'observateur a les bras écartés.
										// (Droite,Regard,Haut) forment un trièdre direct.

friend class LogicielsGraphiquesBase ;
} ;

/*class LGB_DLL GestionEvenements
{
public:
	GestionEvenements () ;
	~GestionEvenements () ;

	// Gestion du click souris dans la clôture
	void __fastcall ClotureMouseDown (TObject *Sender,TMouseButton Button, TShiftState Shift, int X, int Y) ;

	// Gestion du mouvement souris dans la clôture
	void __fastcall ClotureMouseMove (TObject *Sender,TShiftState Shift, int X, int Y) ;

	// Gestion de l'option Annulation du Popup associé à chaque clôture : on
	// interrompt le traitement interactif en cours, s'il y en a un
	void __fastcall MenuAnnulationClick(TObject *Sender) ;

	// Gestion de l'option DisplayAllSolids du Popup associé à
	// chaque clôture : on efface tout et on redessine tous les solides dans
	// la clôture d'où émane la demande.
	void __fastcall MenuDisplayAllSolidsClick (TObject *Sender) ;

	// Gestion de l'option Zoom du Popup associé à chaque clôture
	void __fastcall MenuZoomClick(TObject *Sender) ;

	// Gestion de l'option "regarder ailleurs" du Popup associé à chaque clôture
	void __fastcall MenuLookElseWhereClick (TObject *Sender) ;

	// Gestion de l'option "avancer/reculer" du Popup associé à chaque clôture
	void __fastcall MenuForwardsBackwardsClick (TObject *Sender) ;

	// Gestion de l'option "tourner autour" du Popup associé à chaque clôture
	void __fastcall MenuTurnAroundClick (TObject *Sender) ;

	// Gestion de l'option "TargetAtASolid" du Popup associé à chaque clôture
	void __fastcall MenuTargetAtASolidClick (TObject *Sender) ;

	// Gestion de l'option "TargetAtAFace" du Popup associé à chaque clôture
	void __fastcall MenuTargetAtAFaceClick (TObject *Sender) ;

	// Gestion de l'option "mode fil de fer" du Popup associé à chaque clôture
	void __fastcall MenuWireFrameModeClick (TObject *Sender) ;

	// Gestion de l'option "mode ombré" du Popup associé à chaque clôture
	void __fastcall MenuShadedModeClick (TObject *Sender) ;

	// Gestion de l'option "vue initiale" du Popup associé à chaque clôture
	void __fastcall MenuVueGenerale (TObject *Sender) ;

	// Gestion de l'option "Snapshot" du Popup associé à chaque clôture
	void __fastcall MenuSnapshot (TObject *Sender) ;

	void __fastcall OnPaintFiche(TObject *Sender) ;
	// Fonction associée à l'événement OnPaint de la fiche.
	// Mettre la dedans tout ce qu'il faut faire en cas de dessin de la fiche.
	// En fait, seul le contenu des clôtures n'est pas géré par Builder. On
	// redessine donc le contenu des clôtures.
	// Cette fonction est, entre autres, appelée au début de l'exécution. C'est
	// elle qui fait que les objets dont on a demandé l'affichage dans le
   // constructeur de la fiche deviennent visibles : en effet, l'exécution
   // du constructeur de la fiche est SUIVIE du dessin des composants
   // graphiques. Donc les clôtures apparaissent, se remplissent de noir
   // et effacent ce que l'on a affiché dans le constructeur. Il faut donc
   // demander de raffraichir les clôtures après le constructeur et on
   // choisit de le faire dans le OnPaint.

private:
} ;



*/



#endif
