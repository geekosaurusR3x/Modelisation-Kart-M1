#ifndef _MACRO_TIME_H
#define _MACRO_TIME_H

#include "Time.h"

inline double Moins ( struct time* Apres , struct time* Avant )
{
	double d1 , d2 ;
/*
   d1=Apres->ti_hour*360000 + Apres->ti_min*6000 + Apres->ti_sec*100 +Apres->ti_hund ;
   d2=Avant->ti_hour*360000 + Avant->ti_min*6000 + Avant->ti_sec*100 +Avant->ti_hund ;
   return d1-d2 ;
*/
        return 11111111 ;
}


#endif _MACRO_TIME_H

