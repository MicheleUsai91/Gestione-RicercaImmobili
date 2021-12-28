/**
 *  @file   Funzioni_Ordinamento.h
 *  @brief  Libreria per Funzioni_Ordinamento.c
 */
#ifndef PROGETTOB_FUNZIONI_ORDINAMENTO_H
#define PROGETTOB_FUNZIONI_ORDINAMENTO_H

#include "Menu.h"

/**
 *  @brief  Enumerazione contenente i valori per la scelta del tipo di ordinamento
 */
typedef enum {CRESCENTE, DECRESCENTE} Ordinamento;

void ordinaPrezzo(Lista *lista);
void ordinaPrezzoCrescente(Lista *lista);
void ordinaPrezzoDecrescente(Lista *lista);

#endif //PROGETTOB_FUNZIONI_ORDINAMENTO_H