/**
 *  @file   Funzioni_Stampa.h
 *  @brief  Libreria per Funzioni_Stampa.c
 */
#ifndef PROGETTOB_FUNZIONI_STAMPA_H
#define PROGETTOB_FUNZIONI_STAMPA_H

#include "Immobile.h"
#include "Menu.h"

void stampaImmobile(Immobile *immobile);
void stampaPosizione(Immobile *immobile);
void stampaCodiceIdentificativo(Immobile *immobile);
void stampaTipologia(Immobile *immobile);
void stampaBooleani(Immobile *immobile);
void stampaUso(Immobile *immobile);
void stampaStato(Immobile *immobile);

#endif //PROGETTOB_FUNZIONI_STAMPA_H