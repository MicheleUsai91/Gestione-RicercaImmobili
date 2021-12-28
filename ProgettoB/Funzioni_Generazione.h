/**
 *  @file   Funzioni_Generazione.h
 *  @brief  Libreria di Funzioni_Generazione.c
 */
#ifndef PROGETTOB_FUNZIONI_GENERAZIONE_H
#define PROGETTOB_FUNZIONI_GENERAZIONE_H

#include "Immobile.h"
#include "Utility.h"

#define DIM_VANI        20  ///< Dimensione media di un vano catastale @link https://www.predeion.it/vani-catastali
#define VANI_MIN        2   ///< Minimo numero possibile di vani per un immobile (bagno e camera)
#define VERANDE_MAX     5   ///< Massimo numero di verande ipotizzato per un immobile
#define MAX_L           25  ///< Massima lunghezza per le stringhe della posizione
#define MAX_NUM         20  ///< Massimo numero di regioni, comuni o vie nel vettore di stringhe
#define P_MED_M_QUAD    950 ///< Scelto per rispettare i valori di prezzo massimi, ma avere un prezzo concorde ai m^2

void generaImmobile(Immobile *immobile);
void codiceRandom(Immobile *immobile);
void posizioneRandom(Immobile *immobile);

#endif //PROGETTOB_FUNZIONI_GENERAZIONE_H