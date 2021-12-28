/**
 *  @file   Utility.h
 *  @brief  Libreria di Utility.c
 *
 *  Include tutte le librerie, ad eccezione di Utility, necessarie al funzionamento del menu
 */
#ifndef PROGETTOB_UTILITY_H
#define PROGETTOB_UTILITY_H

#include "Immobile.h"
#include "Menu.h"

#define ARRAY_L 30  ///< Lunghezza massima per le stringhe in stampaEnumerazione
#define TIPO_S  4   ///< Numero degli elementi del vettore di stringhe tipologia
#define USO_S   3   ///< Numero degli elementi del vettore di stringhe uso
#define STAT_S  5   ///< Numero degli elementi del vettore di stringhe stato
#define MENU_S  9   ///< Numero degli elementi del vettore di stringhe menu
#define ORD_S   2   ///< Numero degli elementi del vettore di stringhe ordine
#define INS_S   4   ///< Numero degli elementi del vettore di stringhe inserimento
#define STAM_S  3   ///< Numero degli elementi del vettore di stringhe stampa
#define RIC_S   4   ///< Numero degli elementi del vettore di stringhe ricerca

void svuotaBuffer();
void inizializzaImmobileVuoto(Immobile *immobile);
void stampaEnumerazione(char name[]);

#endif //PROGETTOB_UTILITY_H