/**
 *  @file   Funzioni_Modifica.c
 *  @brief  Procedure e funzioni per la modifica di un immobile
 */
#include "Funzioni_Ordinamento.h"

/**
 * @brief Procedura per ordinare la lista degli immobile per prezzo
 * @param[IN] lista Puntatore a lista
 *
 * Chiede all'utente come vuole che sia effettuto l'ordine tramite la procedura stampaEnumerazione e la scelta richiama
 * una delle due procedure possibili
 */
void ordinaPrezzo(Lista *lista){
    int scelta;
    char ordinamento[] = "ordinamento"; // stringa necessaria alla funzione stampaEnumerazione

    printf("\nVuoi ordinare in ordine crescente o decrescente?\n");
    stampaEnumerazione(ordinamento);
    printf("Scelta:");
    scanf("%d", &scelta);

    switch (scelta){
        case CRESCENTE:
            ordinaPrezzoCrescente(lista);
            break;
        case DECRESCENTE:
            ordinaPrezzoDecrescente(lista);
            break;
        default:
            printf("\nInserisci una delle due opzioni\n");
            ordinaPrezzo(lista); // Nel caso in cui l'input sia sbagliato riparte
            break;
    }
}

/**
 * @brief Procedura per ordinare i valori crescentemente
 * @param[IN] @param[IN] lista Puntatore a lista
 *
 * In base al confronto dei campi prezzo, copia l'immobile nella lista di supporto (nell'unico posto libero), e dopo
 * ogni confronto verrà spostato una cella più avanti, fino a che risulti il maggiore rispetto ad ogni altro immobile
 */
void ordinaPrezzoCrescente(Lista *lista){
    Lista *listaSupporto  = (Lista *) calloc (1, sizeof(Immobile)); // inizializza un solo immobile vuoto
    int i, j; // contattori

    for (i=0;i<MAX_NUM_IMMOBILI;i++){
        for (j=i+1;j<MAX_NUM_IMMOBILI;j++){
            if (lista->listaImmobili[i].prezzo > lista->listaImmobili[j].prezzo){
                listaSupporto->listaImmobili[0] = lista->listaImmobili[i];
                lista->listaImmobili[i] = lista->listaImmobili[j];
                lista->listaImmobili[j] = listaSupporto->listaImmobili[0];
            }
        }
    }
    free(listaSupporto); // libera la memoria di listaSupporto
}

/**
 * @brief Procedura per ordinare i valori decrescentemente
 * @param[IN] @param[IN] lista Puntatore a lista
 *
 * In base al confronto dei campi prezzo, copia l'immobile nella lista di supporto (nell'unico posto libero), e dopo
 * ogni confronto verrà spostato una cella più indietro, fino a che risulti il minore rispetto ad ogni altro immobile
 */
void ordinaPrezzoDecrescente(Lista *lista){
    Lista *listaSupporto  = (Lista *) calloc (1, sizeof(Immobile));
    int i, j; // contattori

    for (i=0;i<MAX_NUM_IMMOBILI;i++){
        for (j=i+1;j<MAX_NUM_IMMOBILI;j++){
            if (lista->listaImmobili[i].prezzo < lista->listaImmobili[j].prezzo){
                listaSupporto->listaImmobili[0] = lista->listaImmobili[i];
                lista->listaImmobili[i] = lista->listaImmobili[j];
                lista->listaImmobili[j] = listaSupporto->listaImmobili[0];
            }
        }
    }
    free(listaSupporto); // libera la memoria di listaSupporto
}