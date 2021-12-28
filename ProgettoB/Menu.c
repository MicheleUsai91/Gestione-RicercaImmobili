/**
 *  @file   Menu.c
 *  @brief  Procedure per avviare e visualizzare il Menu
 *
 *  La procedura stampaMenu sfrutta la procedura stampaEnumerazione per numerare e visualizzare ogni scelta.
 *  La procedura stampaEnumerazione si trova in Utility.c.
 *  La procedura avviaMenu, richiamata nel main, richiama stampaMenu e tramite un switch case consente la scelta
 *  da partte dell'utente
 */

/**
 *  @brief Stampa il menu
 */
#include "Menu.h"

void stampaMenu(){
    printf("       _\n"
           "     _|=|__________\n"
           "    /              \\\n"
           "   /      MENU      \\\n"
           "  /__________________\\\n"
           "   ||  || /--\\ ||  ||\n"
           "   ||[]|| | .| ||[]||\n"
           " ()||__||_|__|_||__||()\n"
           "( )|-|-|-|====|-|-|-|( ) \n"
           "^^^^^^^^^^====^^^^^^^^^^^\n");
    char menu[] = "menu"; // array di supporto per stampaEnumerazione
    stampaEnumerazione(menu);
}

/**
 *  @brief Avvia il menu e acquisisce la scelta dell'utente
 */
void avviaMenu(){
    char nomeFile[DIM_NAME]; // array di supporto per funzioni relative alle gestione dei file
    SceltaMenu menu;
    Lista *lista = (Lista *) calloc (MAX_NUM_IMMOBILI, sizeof(Immobile)); // alloco un blocco di memoria vuoto per la lista

    while(menu != 8) {
        stampaMenu();
        printf("\n\nSelezionare l'opzione desiderata tramite il numero corrispondente\n");
        printf("\nScelta:");
        scanf("%d", &menu);

        switch (menu){ // possibili scelte dell'utente in cui vengono richiamate le funzioni o procedure
            case INSERISCI_IMMOBILE:
                printf("\n\t INSERISCI IMMOBILE\n\n");
                inserimentoLista(lista);
            case MODIFICA_IMMOBILE:
                printf("\n\t MODIFICA IMMOBILE\n\n");
                modificaImmobileLista(lista);
            case STAMPA_LISTA_IMMOBILI:
                printf("\n\t STAMPA LISTA IMMOBILI\n\n");
                stampaListaImmobili(lista);
            case CERCA_IMMOBILI:
                printf("\n\t CERCA IMMOBILI\n\n");
                cercaImmobili(lista);
            case ORDINA_PREZZO:
                printf("\n\t ORDINA PER PREZZO\n\n");
                ordinaPrezzo(lista);
            case VENDI_IMMOBILE:
                printf("\n\t VENDI IMMOBILE\n\n");
                vendiImmobile(lista, lista->indiceLista);
            case SALVA_IMMOBILE:
                printf("\n\t SALVA IMMOBILE\n\n");
                salvaImmobili(lista, nomeFile);
            case CARICA_IMMOBILI:
                printf("\n\t CARICA IMMOBILE\n\n");
                caricaImmobili(lista, nomeFile);
            case ESCI_M:
                free(lista); // libera la memoria allocata precedentemente
                break;
            default:
                printf("\nErrore! Selezionare un numero tra %d e %d\n", ESCI_M, CARICA_IMMOBILI);
        }
    }
}