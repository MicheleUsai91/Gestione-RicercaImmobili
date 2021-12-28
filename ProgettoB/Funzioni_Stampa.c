/**
 *  @file   Funzioni_Stampa.c
 *  @brief  Procedure per la stampa delle informazioni
 */
#include "Funzioni_Stampa.h"

/**
 * @brief Procedura per la stampa delle informazioni di un singolo immobile
 * @param[IN] immobile Prende in ingresso un puntatore ad immobile
 *
 * Stampa ogni valore in maniera ordinata, ragruppando le informazioni pervalori numerici, posizione, codice
 * indentificativo, boolenai ed enumerazioni (tipologia etc...)
 */
void stampaImmobile(Immobile *immobile){
    printf("Prezzo      \t|\t");
    printf("%d\n", immobile->prezzo);
    printf("Metri Quadri\t|\t");
    printf("%.2f\n", immobile->metriQuadri);
    printf("Numero Vani\t|\t");
    printf("%d\n", immobile->numeroVani);
    printf("Numero Verande\t|\t");
    printf("%d\n", immobile->numeroVerande);
    stampaPosizione(immobile);
    stampaCodiceIdentificativo(immobile);
    stampaBooleani(immobile);
    stampaTipologia(immobile);
    stampaUso(immobile);
    stampaStato(immobile);
}

/**
 * @brief Procedura stampare ogni valore della posizione
 * @param[IN] immobile Prende in ingresso un puntatore ad immobile
 */
void stampaPosizione(Immobile *immobile){
    printf("\n\t POSIZIONE\n\n");
    printf("Regione \t|\t");
    printf("%s\n", immobile->posizione.regione);
    printf("Comune  \t|\t");
    printf("%s\n", immobile->posizione.comune);
    printf("Via\t\t|\t");
    printf("%s\n", immobile->posizione.via);
    printf("Numero Civico\t|\t");
    printf("%d\n", immobile->posizione.numeroCivico);
}

/**
 * @brief Procedura per stampare il codice identificativo
 * @param[IN] immobile Prende in ingresso un puntatore ad immobile
 *
 * Sfrutta un ciclo for per stampare carattere per carattere
 */
void stampaCodiceIdentificativo(Immobile *immobile){
    int i;
    printf("\nCodice ID:\t|\t");
    for (i = 0 ; i < DIM_COD ; i++){
        printf("%c", immobile->codiceIdentificativoImmobile[i]);
    }
}

/**
 * @brief Procedura per stampare la tipologia
 * @param[IN] immobile Prende in ingresso un puntatore ad immobile
 *
 * Sfrutta un case switch per stampare una stringa corrispondente al valore dell'enumerazione
 */
void stampaTipologia(Immobile *immobile){
    switch (immobile->tipologia){
        case INDIPENDENTE:
            printf("Tipologia\t|\t");
            printf("Indipendente\n"); break;
        case SEMI_INDIPENDENTE:
            printf("Tipologia\t|\t");
            printf("Semi Indipendente\n"); break;
        case APPARTAMENTO:
            printf("Tipologia\t|\t");
            printf("Appartamento\n"); break;
        case ALTRO:
            printf("Tipologia\t|\t");
            printf("Altro\n"); break;
    }
}

/**
 * @brief Procedura per stampare tutti i booleani
 * @param[IN] immobile Prende in ingresso un puntatore ad immobile
 *
 * Sfrutta un if per stampare una stringa corrispondente al valore bool
 */
void stampaBooleani(Immobile *immobile){
    printf("\n\nAscensore\t|\t");
    if (immobile->ascensore == true){
        printf("SI\n");
    }
    else {
        printf("NO\n");
    }
    printf("Posto Auto\t|\t");
    if (immobile->postoAuto == true){
        printf("SI\n");
    }
    else {
        printf("NO\n");
    }
    printf("Scantinato\t|\t");
    if (immobile->scantinato == true){
        printf("SI\n");
    }
    else {
        printf("NO\n");
    }
    printf("Giardino\t|\t");
    if (immobile->giardino == true){
        printf("SI\n");
    }
    else {
        printf("NO\n");
    }
}

/**
 * @brief Procedura per stampare l'uso
 * @param[IN] immobile Prende in ingresso un puntatore ad immobile
 *
 * Sfrutta un case switch per stampare una stringa corrispondente al valore dell'enumerazione
 */
void stampaUso(Immobile *immobile){
    switch (immobile->usoImmobile){
        case ABITATIVO:
            printf("Uso\t\t|\t");
            printf("Abitativo\n"); break;
        case UFFICIO:
            printf("Uso\t\t|\t");
            printf("Ufficio\n"); break;
        case LOCALE_COMMERCIALE:
            printf("Uso\t\t|\t");
            printf("Locale Commerciale\n"); break;
    }
}

/**
 * @brief Procedura per stampare lo stato
 * @param[IN] immobile Prende in ingresso un puntatore ad immobile
 *
 * Sfrutta un case switch per stampare una stringa corrispondente al valore dell'enumerazione
 */
void stampaStato(Immobile *immobile){
    switch (immobile->statoImmobile){
        case NUOVO:
            printf("Stato\t\t|\t");
            printf("Nuovo\n"); break;
        case RISTRUTTURATO:
            printf("Stato\t\t|\t");
            printf("Ristrutturato\n"); break;
        case PARZIALMENTE_RISTRUTTURATO:
            printf("Stato\t\t|\t");
            printf("Parzialmente Ristrutturato\n"); break;
        case DA_RISTRUTTURARE:
            printf("Stato\t\t|\t");
            printf("Da Ristrutturare\n"); break;
        case RUDERE:
            printf("Stato\t\t|\t");
            printf("Rudere\n"); break;
    }
}