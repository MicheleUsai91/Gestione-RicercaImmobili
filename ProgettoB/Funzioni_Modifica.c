/**
 *  @file   Funzioni_Modifica.c
 *  @brief  Procedure e funzioni per la modifica di un immobile
 */
#include "Funzioni_Modifica.h"

/**
 * @brief Procedura per modificare i dati di un immobile
 * @param[IN] immobile Puntatore all'immobile
 *
 * Per ogni campo chiede all'utente se vuole modificare i dati con un if, nel caso in cui la scelta sia true,
 * verrà richiamata la relativa funzione o procedura per il campo selezionato
 */
void modificaImmobile(Immobile *immobile){
    int scelta; // Intero necessario alla condizione if

    printf("\nPrezzo: %d\n", immobile->prezzo);
    printf("\nVuoi modificare il Prezzo?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        printf("\nInserisci il prezzo (0 - 10M)\n");
        immobile->prezzo = inserisciIntero(immobile->prezzo, PREZZO_MIN, PREZZO_MAX);
    }

    printf("\nMetri Quadri: %.2f\n", immobile->metriQuadri);
    printf("\nVuoi modificare i Metri Quadri?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        immobile->metriQuadri = inserisciFloat(immobile->metriQuadri, METRI_QUADRI_MIN, METRI_QUADRI_MAX);
    }

    printf("\nNumero Vani: %d\n", immobile->numeroVani);
    printf("\nVuoi modificare il Numero di Vani?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        printf("\nInserisci il numero di vani (0 - 502)\n");
        immobile->numeroVani = inserisciIntero(immobile->numeroVani, NUMERO_VANI_MIN, NUMERO_VANI_MAX);
    }

    stampaPosizione(immobile);
    printf("\nVuoi modificare la Regione?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        printf("Regione: \n");
        immobile->posizione.regione[DIM_POS] = inserisciArray(immobile->posizione.regione);
    }
    printf("\nVuoi modificare il Comune?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        printf("Comune: \n");
        immobile->posizione.comune[DIM_POS] = inserisciArray(immobile->posizione.comune);
    }
    printf("\nVuoi modificare la Via?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        printf("Via: \n");
        immobile->posizione.via[DIM_POS] = inserisciArray(immobile->posizione.via);
    }
    printf("\nVuoi modificare il Numero Civico?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        printf("Numero Civico: \n");
        immobile->posizione.numeroCivico = inserisciIntero(immobile->posizione.numeroCivico, 0, NUMERO_CIVICO_MAX);
    }

    stampaCodiceIdentificativo(immobile);
    printf("\nVuoi modificare il Codice Identificativo?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        inserisciCodiceIdentificativo(immobile);
    }

    printf("\nNumero Verande: %d\n", immobile->numeroVerande);

    stampaTipologia(immobile);
    printf("\nVuoi modificare la Tipologia?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        printf("\nInserisci il numero di verande (0 - 1000)\n");
        inserisciTipologia(immobile);
    }

    stampaBooleani(immobile);
    printf("\nVuoi modificare questi valori?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        inserisciBooleani(immobile);
    }

    stampaUso(immobile);
    printf("\nVuoi modificare l'Uso dell'Immobile?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        inserisciUsoImmobile(immobile);
    }

    stampaStato(immobile);
    printf("\nVuoi modificare lo Stato dell'Immobile?");
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta: ");
    scanf("%d", &scelta);
    if (scelta == true){
        inserisciStatoImmobile(immobile);
    }
}