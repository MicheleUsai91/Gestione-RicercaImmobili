/**
 *  @file   Funzioni_File.c
 *  @brief  Procedure e funzioni per il salvataggio ed esportazione dei file
 */
#include "Funzioni_File.h"

/**
 * @brief  Procedure e funzioni per il salvataggio
 * @param lista Prende l'array di immobili
 * @param nomeFile[] Stringa per l'inserimento da parte dell'utente
 */
void salvaImmobili(Lista *lista, char nomeFile[]){
    svuotaBuffer();
    long int size; // Variabile necessaria alla stampa della dimensione del file
    printf("\nInserire il nome del file .bin (dimensione massima nome %d caratteri):\n", DIM_NAME-4);
    scanf("%19[^\n]s", nomeFile);

    FILE *file = fopen(nomeFile, "wb"); // wb = Scrive un file binario

    if (file == NULL){
        printf("\n\aErrore Salvataggio\n");
    }

    fwrite(lista, sizeof(Lista), 1, file);
    size = ftell(file); // Restituisce la dimensione in Bytes del file
    fclose(file);

    printf("\nFile %s creato con successo.\nDimensione %luBytes\n\n", nomeFile, size);
}

/**
 * @brief  Procedure e funzioni per il caricamento
 * @param lista Prende l'array di immobili
 * @param[IN] nomeFile[] Stringa per l'inserimento da parte dell'utente ed il confronto con i file esistenti
 * @param[OUT] lista Ritorna un puntatore a lista
 */
Lista caricaImmobili(Lista *lista, char nomeFile[]){
    svuotaBuffer();

    printf("\nInserire il nome del file .bin:\n");
    scanf("%19[^\n]s", nomeFile);

    FILE *file = fopen(nomeFile, "rb"); // rb = Legge un file binario

    if (file == NULL){
        printf("\n\aFile non trovato, reinserire il nome");
        caricaImmobili(lista, nomeFile);
    }

    fread(lista, sizeof(Lista), 1, file);
    fclose(file);

    printf("\nFile caricato con successo\n\n");

    return *lista;
}