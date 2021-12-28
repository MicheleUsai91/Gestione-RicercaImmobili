/**
 *  @file   Lista.h
 *  @brief  Libreria per Lista.c
 */
#ifndef PROGETTOB_LISTA_H
#define PROGETTOB_LISTA_H

#include "Menu.h"

typedef enum {INSERIMENTO, GENERAZIONE, CAMBIA_POSIZIONE, ESCI_I} SceltaInserimento;
typedef enum {ESTESA, DATI_BASE, ESCI_S} SceltaStampa;
typedef enum {REGIONE, TIPOLOGIA, STATO_IMMOBILE, ESCI_R} Ricerca;

void inserimentoLista(Lista *lista);
void stampaListaImmobili(Lista *lista);
Immobile vendiImmobile(Lista *lista, int indice);
void modificaImmobileLista(Lista *lista);
Immobile cercaImmobili(Lista *lista);
void ricercaRegione(Lista *lista);
void ricercaTipologia(Lista *lista);
void ricercaStato(Lista *lista);

#endif //PROGETTOB_LISTA_H