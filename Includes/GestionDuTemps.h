#pragma once

#include <time.h>

void DureeEnClair (long long Duree, int *PAnnees, int *PMois, int *PJours, int *PHeures, int *PMinutes, int *PSecondes) ;
// Prend la durée fournie, exprimée en secondes, et la transforme en années, mois, jours ...
// On suppose que tous les mois ont 30 jours.
// Il n'est pas vérifié que le nb d'années ne dépasse pas la capacité des entiers.

void DureeEnChaine (time_t T, bool AvecMoisEtAnnees, char ch []) ;
// Restitue la durée fournie sous la forme d'une chaîne. 
// Si le booléen est vrai, la chaîne commence par un nombre d'années et de mois.
// Dans tous les cas, elle se poursuit par les nb de jours, minutes et secondes.
// Si le booléen est vrai, il n'est pas vérifié que le nb d'années ne dépasse pas la
// capacité des entiers.
// Si le booléen est faux, il n'est pas vérifié que le nb de jour ne dépasse pas la
// capacité des entiers.
