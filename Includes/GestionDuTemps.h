#pragma once

#include <time.h>

void DureeEnClair (long long Duree, int *PAnnees, int *PMois, int *PJours, int *PHeures, int *PMinutes, int *PSecondes) ;
// Prend la dur�e fournie, exprim�e en secondes, et la transforme en ann�es, mois, jours ...
// On suppose que tous les mois ont 30 jours.
// Il n'est pas v�rifi� que le nb d'ann�es ne d�passe pas la capacit� des entiers.

void DureeEnChaine (time_t T, bool AvecMoisEtAnnees, char ch []) ;
// Restitue la dur�e fournie sous la forme d'une cha�ne. 
// Si le bool�en est vrai, la cha�ne commence par un nombre d'ann�es et de mois.
// Dans tous les cas, elle se poursuit par les nb de jours, minutes et secondes.
// Si le bool�en est vrai, il n'est pas v�rifi� que le nb d'ann�es ne d�passe pas la
// capacit� des entiers.
// Si le bool�en est faux, il n'est pas v�rifi� que le nb de jour ne d�passe pas la
// capacit� des entiers.
