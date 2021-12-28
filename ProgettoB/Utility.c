/**
 *  @file   Utility.c
 *  @brief  Procedure di supporto per il progetto
 *
 *  La procedura svuotaBuffer, permette di risolvere eventuali errori di inserimento dovuti a caratteri non eliminati
 *  dal buffer.
 *  La procedura inizializzaImmobileVuoto, riporta ogni valore dell'immobile a zero o terminatore di stringa, usata
 *  nella funzione vendiImmobile.
 *  La procedura stampaEnumerazione permette di stampare enumerazioni sia numericamente, sia alfabeticamente
 */
#include "Utility.h"

/// @brief  Ripulisce il buffer
void svuotaBuffer() {
    char c;
    do {
        c = getchar();
    } while (c != '\n');
}

/**
 *  @brief  Inizializza ogni campo dell'immobile a 0 o terminatore di stringa
 *  @param  immobile
 */
void inizializzaImmobileVuoto(Immobile *immobile){
    int i;
    immobile->prezzo = '\0';
    immobile->metriQuadri = '\0';
    immobile->numeroVani = '\0';

    for (i = 0 ; i <= DIM_POS ; i++){
        immobile->posizione.regione[i] = '\0';
    }
    for (i = 0 ; i <= DIM_POS ; i++){
        immobile->posizione.comune[i] = '\0';
    }
    for (i = 0 ; i <= DIM_POS ; i++){
        immobile->posizione.via[i] = '\0';
    }
    immobile->posizione.numeroCivico = '\0';

    for (i = 0; i < DIM_COD ; i++){
        immobile->codiceIdentificativoImmobile[i] = '\0';
    }
    immobile->tipologia = '\0';
    immobile->numeroVerande = '\0';
    immobile->ascensore = '\0';
    immobile->postoAuto = '\0';
    immobile->giardino = '\0';
    immobile->scantinato = '\0';
    immobile->usoImmobile = '\0';
    immobile->statoImmobile = '\0';
}

/**
 *  @brief  Stampa le enumerazioni del progetto
 *
 *  Sfruttando dei vettori di stringhe, contenti i valori delle relative enumerazioni, la procedura stampaEnumerazione
 *  permette di semplificare e standardizzare la stampa dei menu o scelte.
 *  Sfrutta la strcmp per controllare che l'enumerazione da stampare corrisponda a quella desiderata, confrontando
 *  la stringa in entrata name (dichiarata prima dell'utilizzo) con un testo, se sono equivalenti, stamperá la relativa
 *  enumerazione.
 *
 *  @param name Stringa per strcmp
 */
void stampaEnumerazione(char name[]) {
    int i;

    const char tipologia[TIPO_S][ARRAY_L] = {"Indipendente", "Semi Indipendente", "Appartamento", "Altro"};
    const char uso[USO_S][ARRAY_L] = {"Abitativo", "Ufficio", "Locale Commerciale"};
    const char stato[STAT_S][ARRAY_L] = {"Nuovo", "Ristrutturato", "Parzialmente Ristrutturato", "Da Ristrutturare", "Rudere"};
    const char menu[MENU_S][ARRAY_L] = {"Inserisci Immobile", "Stampa Lista Immobili", "Cerca Immobili", "Modifica Immobile",
                              "Vendi Immobile", "Ordina Per Prezzo", "Salva Immobile", "Carica Immobile", "Esci"};
    const char ordinamento[ORD_S][ARRAY_L] = {"Crescente","Decrescente"};
    const char sceltaInserimento[INS_S][ARRAY_L] = {"Inserimento","Generazione","Cambia Posizione","Esci"};
    const char sceltaStampa[STAM_S][ARRAY_L] = {"Estesa","Dati Base","Esci"};
    const char ricerca[RIC_S][ARRAY_L] = {"Regione","Tipologia","Stato Immobile","Esci"};

    if (strcmp(name, "tipologia") == 0) {
        for (i = 0; i < TIPO_S; i++) {
            printf("\n[%d] - %s", i, tipologia[i]);
        }
    } else if (strcmp(name, "uso") == 0) {
        for (i = 0; i < USO_S; i++) {
            printf("\n[%d] - %s", i, uso[i]);
        }
    } else if (strcmp(name, "stato") == 0) {
        for (i = 0; i < STAT_S; i++) {
            printf("\n[%d] - %s", i, stato[i]);
        }
    } else if (strcmp(name, "menu") == 0) {
        for (i = 0; i < MENU_S; i++) {
            printf("\n[%d] - %s", i, menu[i]);
        }
    } else if (strcmp(name, "ordinamento") == 0) {
        for (i = 0; i < ORD_S; i++) {
            printf("\n[%d] - %s", i, ordinamento[i]);
        }
    } else if (strcmp(name, "sceltaInserimento") == 0) {
        for (i = 0; i < INS_S; i++) {
            printf("\n[%d] - %s", i, sceltaInserimento[i]);
        }
    } else if (strcmp(name, "sceltaStampa") == 0) {
        for (i = 0; i < STAM_S; i++) {
            printf("\n[%d] - %s", i, sceltaStampa[i]);
        }
    } else if (strcmp(name, "ricerca") == 0) {
        for (i = 0; i < RIC_S; i++) {
            printf("\n[%d] - %s", i, ricerca[i]);
        }
    }
}