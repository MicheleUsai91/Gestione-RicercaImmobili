/**
 * @file Funzioni_Inserimento.h
 * @brief Libreria per il file Funzioni_Inserimento.c
 */
#ifndef PROGETTOB_FUNZIONI_INSERIMENTO_H
#define PROGETTOB_FUNZIONI_INSERIMENTO_H

#include "Immobile.h"
#include "Utility.h"

void inserisciImmobile(Immobile *immobile);
int inserisciIntero(int numero, int min, int max);
float inserisciFloat(float numero, float min, float max);
char inserisciArray(char array[]);
void inserisciPosizione(Immobile *immobile);
bool inserisciBooleano (bool valore);
void inserisciCodiceIdentificativo(Immobile *immobile);
void inserisciTipologia(Immobile *immobile);
void inserisciBooleani(Immobile *immobile);
void inserisciUsoImmobile(Immobile *immobile);
void inserisciStatoImmobile(Immobile *immobile);

#endif //PROGETTOB_FUNZIONI_INSERIMENTO_H