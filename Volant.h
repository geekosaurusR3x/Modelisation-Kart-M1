/*
Cr�ation :				Christophe ELSENSOHN 
Date de cr�ation :		05/04/2012
Version :				0
Modifi� par:			null
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
	- repere				(const Repere3D&)	: rep�re de Volant.
													L'axe de volant suivra le vecteur Z de
													ce rep�re
												  Origine se trouvant sur l'axe de r�volution. 
													Il se situe au centre de la face de jonction 
													du petit diam�tre et du grand diam�tre.

	- diametreDisque		(double)			: diam�tre du disque volant

	- epaisseurDisque		(double)			: Epaisseur du disque volant

	- diametreAxe			(double)			: dimension du petit diam�tre

	- longueurAxe			(double)			: longueur du petit diam�tre de l'extr�mit� 
													jusqu'au plan de jonction avec le disque volant

	- coteCreuCarre			(double)			: dimension du cot� du carr� d'entrainement

	- profondeurCreu		(double)			: profondeur du carr� d'entrainement
	
	- PtAF					(AttributsFacesP*)	: Attribut des faces de l'axe �paul�.
													Repr�sente la couleur de l'axe �paul�.

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

							EXCEPTIONS LEVEES

Une exception sera lev� si:
- "diametreAxe" et "diametreDisque" sont �gaux.
- la diagonale du carr� est plus grande que le diam�tre d'axe.
- la profondeur du creu est sup�rieur � la longueur totale du volant (axe + disque)

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
//	Getter du rep�re du carr� d'entrainement. Le vecteur Z du rep�re est VERS l'int�rieur du volant
//	L'origine se trouve � l'intersection de l'axe de r�volution et de la face enfonc�e du creu

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
//	Cot� du creu carr�

	double _coteCreu;

//_____________________________________________________________________________
//
//	distance entre la face extreme et le fond du creu carr�

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
//	M�thode de construction de Volant
//	Elle fait suite � AxeEpaule::buildAll()
//	Cette m�thode s'occupe de faire un trou borgne (non d�bouchant) carr� dont la profondeur suit l'axe du volant.

	virtual void buildAll();

//_____________________________________________________________________________
//
//	M�thode de contr�le des arguments pass�s pour la 
//	construction de Volant.
//	Elle fait suite � AxeEpaule::ControleValiditeArgConstruct()
//	Une Exception est lev�e si:
//		- le carr� d�borde de la section du petit diam�tre
//		- la profondeur de l'�videment carr� est plus long que la longueur totale du volant.
	
	virtual void ControleValiditeArgConstruct() throw (exception);
};

