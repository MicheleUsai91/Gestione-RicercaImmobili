/**
 *  @file   Immobile.h
 *  @brief  Libreria necessaria per il progetto
 *
 *  Include tutte le enumerazioni base, le macro e le librerie standard fondamentali al funzionamento del progetto
 */
#ifndef PROGETTOB_IMMOBILE_H
#define PROGETTOB_IMMOBILE_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define DIM_POS             31          ///< Massima dimensione delle stringhe per la struttura Posizione
#define DIM_COD             9           ///< Dimensione massima del codice
#define PREZZO_MIN          0           ///< Prezzo minimo
#define PREZZO_MAX          10000000    ///< Prezzo massimo
#define METRI_QUADRI_MIN    1           ///< Numero minimo di metri quadri per la procedura generaImmobile
#define METRI_QUADRI_MAX    10000       ///< Numero massimo di metri quadri per la procedura generaImmobile
#define NUMERO_VANI_MIN     0           ///< Numero minimo di vani per la procedura generaImmobile
#define NUMERO_VANI_MAX     502         ///< Numero massimo di vani per la procedura generaImmobile
#define NUMERO_CIVICO_MAX   999         ///< Massimo valore per il numero civico
#define MAX_NUM_VERANDE     1000        ///< Numero massimo di verande per la procedura generaImmobile
#define MAX_NUM_IMMOBILI    3           ///< Numero massimo di immobili per listaImmobili

/**
 *  @brief  Struttura contenente i valori della posizione
 */
typedef struct {
    char regione[DIM_POS+1];
    char comune[DIM_POS+1];
    char via[DIM_POS+1];
    int  numeroCivico;
} Posizione;

/**
 *  @brief  Enumerazione per la tipologia
 */
typedef enum {INDIPENDENTE, SEMI_INDIPENDENTE, APPARTAMENTO, ALTRO} Tipologia;

/**
 *  @brief  Enumerazione per l'uso
 */
typedef enum {ABITATIVO, UFFICIO, LOCALE_COMMERCIALE} UsoImmobile;

/**
 *  @brief  Enumerazione per lo stato
 */
typedef enum {NUOVO, RISTRUTTURATO, PARZIALMENTE_RISTRUTTURATO, DA_RISTRUTTURARE, RUDERE} StatoImmobile;

/**
 *  @brief  Struttura contenente i valori dell'Immobile'
 */
typedef struct {
    int prezzo;
    float metriQuadri;
    int numeroVani;
    Posizione posizione;
    char codiceIdentificativoImmobile [DIM_COD];
    int numeroVerande;
    Tipologia tipologia;
    bool ascensore;
    bool postoAuto;
    bool scantinato;
    bool giardino;
    UsoImmobile usoImmobile;
    StatoImmobile statoImmobile;
} Immobile;

/**
 *  @brief  Struttura contenente l'array di immobili e l'indice dell'array
 */
typedef struct {
    Immobile listaImmobili[MAX_NUM_IMMOBILI];
    int indiceLista;
} Lista;

#endif //PROGETTOB_IMMOBILE_H