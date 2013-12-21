/*
Création :				Christophe ELSENSOHN 
Date de création :		05/04/2012
Version :				0
Modifié par:			null
Date de modification:	null
*/
#pragma once

#include "BibliothequeBRepP.h"
#include "BibliothequeLGB.h"
#include "TIColorerSolide.h"
#include "Materiaux.h"
#include "Attributs.h"
#include "AxeEpaule.h"

class Volant:public AxeEpaule
{

//#############################################################################
//								DOMAINE PUBLIC
//#############################################################################
public:

//*****************************************************************************
//						CONSTRUCTEURS ET DESTRUCTEURS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Constructeur d'instance de Volant 

	Volant(const Repere3D& repere=Repere3D(),
		double diametreDisque=10, double epaisseurDisque=4,double diametreAxe=5,
		double longueurAxe=5,double coteCreuCarre=2,double profondeurCreu=4,
		AttributsFacesP *PtAF= &AttributsFaces(PMateriauBleu));

/*
PARAMETRES
	- repere				(const Repere3D&)	: repère de Volant.
													L'axe de volant suivra le vecteur Z de
													ce repère
												  Origine se trouvant sur l'axe de révolution. 
													Il se situe au centre de la face de jonction 
													du petit diamètre et du grand diamètre.

	- diametreDisque		(double)			: diamètre du disque volant

	- epaisseurDisque		(double)			: Epaisseur du disque volant

	- diametreAxe			(double)			: dimension du petit diamètre

	- longueurAxe			(double)			: longueur du petit diamètre de l'extrémité 
													jusqu'au plan de jonction avec le disque volant

	- coteCreuCarre			(double)			: dimension du coté du carré d'entrainement

	- profondeurCreu		(double)			: profondeur du carré d'entrainement
	
	- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe épaulé.
													Représente la couleur de l'axe épaulé.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera levé si:
- "diametreAxe" et "diametreDisque" sont égaux.
- la diagonale du carré est plus grande que le diamètre d'axe.
- la profondeur du creu est supérieur à la longueur totale du volant (axe + disque)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

//_____________________________________________________________________________
//
//	Constructeur par recopie de Volant

	Volant(const Volant& volant);

//_____________________________________________________________________________
//
//	Destructeur de Volant

	virtual ~Volant(void);


//*****************************************************************************
//							GETTERS ET SETTERS
//*****************************************************************************

//_____________________________________________________________________________
//
//	Getter du repère du carré d'entrainement. Le vecteur Z du repère est VERS l'intérieur du volant
//	L'origine se trouve à l'intersection de l'axe de révolution et de la face enfoncée du creu

	virtual Repere3D getRepere3D()const;


//#############################################################################
//								DOMAINE PROTECTED
//#############################################################################
protected:

//*****************************************************************************
//							DONNEES MEMBRES
//*****************************************************************************

//_____________________________________________________________________________
//
//	Coté du creu carré

	double _coteCreu;

//_____________________________________________________________________________
//
//	distance entre la face extreme et le fond du creu carré

	double _profCreu;

	
//#############################################################################
//								DOMAINE PRIVE
//#############################################################################
private:

//*****************************************************************************
//									METHODES
//*****************************************************************************
	
//_____________________________________________________________________________
//
//	Méthode de construction de Volant
//	Elle fait suite à AxeEpaule::buildAll()
//	Cette méthode s'occupe de faire un trou borgne (non débouchant) carré dont la profondeur suit l'axe du volant.

	virtual void buildAll();

//_____________________________________________________________________________
//
//	Méthode de contrôle des arguments passés pour la 
//	construction de Volant.
//	Elle fait suite à AxeEpaule::ControleValiditeArgConstruct()
//	Une Exception est levée si:
//		- le carré déborde de la section du petit diamètre
//		- la profondeur de l'évidement carré est plus long que la longueur totale du volant.
	
	virtual void ControleValiditeArgConstruct() throw (exception);
};

