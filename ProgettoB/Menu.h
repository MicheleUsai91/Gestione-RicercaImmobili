/**
 *  @file   Menu.h
 *  @brief  Libreria per il funzionamento del menu
 *
 *  Include tutte le librerie, ad eccezione di Utility, necessarie al funzionamento del menu
 */
#ifndef PROGETTOB_MENU_H
#define PROGETTOB_MENU_H

/// @brief  Librerie necessarie per il funzionamento del menu
#include "Funzioni_File.h"
#include "Funzioni_Generazione.h"
#include "Funzioni_Inserimento.h"
#include "Funzioni_Modifica.h"
#include "Funzioni_Ordinamento.h"
#include "Funzioni_Stampa.h"
#include "Immobile.h"
#include "Lista.h"

/// @brief  Enumerazione per le scelte del menu
typedef enum {INSERISCI_IMMOBILE,
              STAMPA_LISTA_IMMOBILI,
              CERCA_IMMOBILI,
              MODIFICA_IMMOBILE,
              VENDI_IMMOBILE,
              ORDINA_PREZZO,
              SALVA_IMMOBILE,
              CARICA_IMMOBILI,
              ESCI_M} SceltaMenu;

/// @brief  Prototipi delle funzioni relative al menu
void stampaMenu();
void avviaMenu();

#endif //PROGETTOB_MENU_H