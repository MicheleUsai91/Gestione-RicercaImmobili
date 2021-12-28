/**
 *  @file   Funzioni_File.h
 *  @brief  Libreria per Funzioni_File.c
 */
#ifndef PROGETTOB_FUNZIONI_FILE_H
#define PROGETTOB_FUNZIONI_FILE_H

#include "Menu.h"
#include "Immobile.h"

#define DIM_NAME 20 ///<    Dimensione massima per il nome di un file

void salvaImmobili(Lista *lista, char nomeFile[]);
Lista caricaImmobili(Lista *lista, char nomeFile[]);

#endif //PROGETTOB_FUNZIONI_FILE_H
