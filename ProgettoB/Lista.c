/**
 *  @file   Lista.c
 *  @brief  Procedure e funzioni per le operazioni su array di Immobili
 */
#include "Lista.h"

/**
 * @brief Procedura per l'inserimento di un immobile all'interno della lista
 * @param[IN] lista Prende l'array di immobili
 *
 * Stampa l'elenco degli immobili con relativo valore Occupato o Disponibile e permette all'utente di scegliere quale
 * inserire, evitando quindi di sovrascrivere un immobile già occupato da dati.
 * Scelta l'immobile da inserire, viene data la possibilità di generarlo, inserirlo o cambiare posizione
 */
void inserimentoLista(Lista *lista){
    int i, sceltaIndice, sceltaInserimento, posti = 0; // variabili di supporto
    char inserimento[] = "sceltaInserimento"; // stringa necessaria alla funzione stampaEnumerazione

    /*
     * Sapendo che il valore del prezzo dopo la calloc in Menu.c è zero, basta un confronto per capire se è un posto
     * disponibile o no
     */
    printf("\nIn quale posizione vuoi inserire l'immobile?\n");
    for( i = 0 ; i < MAX_NUM_IMMOBILI ; i++){
        if (lista->listaImmobili[i].prezzo != 0){
            printf("\nIMMOBILE %d -> Occupato\n", i);
        }
        else if (lista->listaImmobili[i].prezzo == 0){
            printf("\nIMMOBILE %d -> Disponibile\n", i);
            posti++;
        }
    }
    printf("\nAttualmente ci sono %d posti disponibili\n", posti);
    printf("\nScelta:");
    scanf("%d", &sceltaIndice);

    printf("\nVuoi inserire i dati o generarli?\n");
    stampaEnumerazione(inserimento);
    printf("\n\nScelta:");
    scanf("%d", &sceltaInserimento);

    switch (sceltaInserimento) {
        case INSERIMENTO:
            inserisciImmobile(&lista->listaImmobili[sceltaIndice]);
            break;
        case GENERAZIONE:
            generaImmobile(&lista->listaImmobili[sceltaIndice]);
            break;
        case CAMBIA_POSIZIONE:
            inserimentoLista(lista);
        case ESCI_I:
            break;
        default:
            printf("\nInserisci un numero valido!\n");
            inserimentoLista(lista);
        }
}

/**
 * @brief Procedura per la stampa dell'intera lista immobili
 * @param[IN] lista Prende l'array di immobili
 *
 * Procedura che permette di visualizzare la lista completa di tutti i gli immobili con ogni dettaglio oppure una
 * lista compatta
 */
void stampaListaImmobili(Lista *lista) {
    int i, scelta; // variabili di supporto
    char stampa[] = "sceltaStampa"; // stringa necessaria alla funzione stampaEnumerazione

    printf("\nVuoi visualizzare la lista estesa o solo i dati base?\n");
    stampaEnumerazione(stampa);
    printf("\n\nScelta:");
    scanf("%d", &scelta);

    switch (scelta) {
        case ESTESA: // Stampa ogni immobile completo di ogni dettaglio tramite stampaImmobile
            for (i = 0 ; i < MAX_NUM_IMMOBILI ; i++) {
                printf("\n\t IMMOBILE %d\n\n", i);
                stampaImmobile(&lista->listaImmobili[i]);
                printf("\n");
            }
            break;
        case DATI_BASE: // Stampa solo i dettagli base di ogni immobile in formatto tabella
            printf("\nIMMOBILE\t|\tPREZZO\t|\tMETRI QUADRI\t|\tCODICE ID\n");
            printf("------------------------------------------------------------------------------\n");
            for (i = 0; i < MAX_NUM_IMMOBILI ; i++) {
                printf("\t%d\t|\t", i);
                printf("%d\t|\t", lista->listaImmobili[i].prezzo);
                printf("%.2f\t\t|\t", lista->listaImmobili[i].metriQuadri);
                printf("%s\n", lista->listaImmobili[i].codiceIdentificativoImmobile);
            }
            printf("\n");
            break;
        case ESCI_S:
            break;
        default:
            printf("\nInserisci un numero valido!\n");
            inserimentoLista(lista); // Nel caso di inserimento fuori valori riparte
    }
}

/**
 * @brief Funzione per la vendita di un immobile
 * @param[IN] lista Prende l'array di immobili
 * @param[IN] indice Prende l'indice degli immobili
 * @param[OUT] lista Restituisce l'intera lista
 *
 * Funzione che, dopo aver fatto visualizzare all'utente la lista degli immobili, permette di venderne uno ed
 * inizializzarlo a vuoto
 */
Immobile vendiImmobile(Lista *lista, int indice){
    printf("\nQuale immobile vuoi vendere?\n");
    stampaListaImmobili(lista);
    printf("\n\nScelta:");
    scanf("%d", &indice);

    printf("\nL'immobile e stato venduto per %d Euro\n", lista->listaImmobili[indice].prezzo);
    inizializzaImmobileVuoto(&lista->listaImmobili[indice]); // Inizializza l'immobile a vuoto

    return *lista->listaImmobili;
}

/**
 * @brief Procedura per la modifica di un immobile della lista
 * @param[IN] lista Prende l'array di immobili
 *
 * Procedura che sfrutta modificaImmobile per modificare i dati di un immobile in lista
 */
void modificaImmobileLista(Lista *lista){
    int scelta;
    stampaListaImmobili(lista);
    printf("\nQuale Immobile vuoi modificare?\n");
    printf("\n\nScelta:");
    scanf("%d", &scelta);
    modificaImmobile(&lista->listaImmobili[scelta]);
}

/**
 * @brief Funzione per la ricerca di imombili secondo specifici campi
 * @param[IN] lista Prende l'array di immobili
 * @param[OUT] lista Restituisce l'intera lista
 *
 * Funzione che permette di ricercare degli immobili secondo Regione, Tipologia o Stato
 */
Immobile cercaImmobili(Lista *lista){
    int scelta;
    char ricerca[] = "ricerca"; // stringa necessaria alla funzione stampaEnumerazione
    printf("\nQuale campo vuoi cercare?\n");
    stampaEnumerazione(ricerca);
    printf("\n\nScelta:");
    scanf("%d", &scelta);

    switch (scelta) {
        case REGIONE:
            ricercaRegione(lista);
            break;
        case TIPOLOGIA:
            ricercaTipologia(lista);
            break;
        case STATO_IMMOBILE:
            ricercaStato(lista);
            break;
        case ESCI_R:
            break;
        default:
            printf("\nErrore! Selezionare un numero tra 1 e 3\n");
            cercaImmobili(lista);
            break;
    }
    return *lista->listaImmobili;
}

/**
 * @brief Procedura per la ricerca secondo Regione
 * @param[IN] lista Prende l'array di immobili
 *
 * Procedura che permette di ricercare un immobile confrontanto l'input dell'utente e la stringa contente io valore
 * della regione
 */
void ricercaRegione(Lista *lista){
    svuotaBuffer();
    char array[DIM_POS]; // Stringa per l'input utente
    int i; // Contattore
    printf("Inserisci il nome della Regione: \n");
    scanf("%31[^\n]s", array);
    getchar();
    /*
     * Confronta l'input utente con ogni immobile della lista e ritorna la posizione in cui compare l'immobile che
     * rispetta la ricerca
     */
    for (i = 0 ; i < MAX_NUM_IMMOBILI ; i++){
        if (strcmp(array, lista->listaImmobili[i].posizione.regione) == 0){
            printf("\nEsiste un immobile in posizione %d che rispetta la ricerca\n", i);
        }
    }
    printf("\nNessun immobile corrispondente alla ricerca trovato\n");
}

/**
 * @brief Procedura per la ricerca secondo Tipologia
 * @param[IN] lista Prende l'array di immobili
 *
 * Procedura che permette di ricercare un immobile confrontanto l'input dell'utente e il valore della tipologia
 */
void ricercaTipologia(Lista *lista){
    int tipologia, i; // Variabili di supporto
    printf("\nTipologia \n\n");
    char tipologiaChar[] = "tipologia"; // stringa necessaria alla funzione stampaEnumerazione
    stampaEnumerazione(tipologiaChar);
    printf("\nScelta:");
    scanf("%d", &tipologia);
    getchar();
    /*
     * Confronta l'input utente con ogni immobile della lista e ritorna la posizione in cui compare l'immobile che
     * rispetta la ricerca
     */
    for (i = 0 ; i < MAX_NUM_IMMOBILI ; i++){
        if (tipologia == lista->listaImmobili[i].tipologia){
            printf("\nEsiste un immobile in posizione %d che rispetta la ricerca\n", i);
        }
    }
    printf("\nNessun immobile corrispondente alla ricerca trovato\n");
}

/**
 * @brief Procedura per la ricerca secondo Stato
 * @param[IN] lista Prende l'array di immobili
 *
 * Procedura che permette di ricercare un immobile confrontanto l'input dell'utente e la stringa contente io valore
 * della regione
 */
void ricercaStato(Lista *lista){
    int stato, i; // Variabili di supporto
    printf("\nStato immobile \n\n");
    char statoChar[] = "stato"; // stringa necessaria alla funzione stampaEnumerazione
    stampaEnumerazione(statoChar);
    printf("\nScelta:");
    scanf("%d", &stato);
    getchar();
    /*
     * Confronta l'input utente con ogni immobile della lista e ritorna la posizione in cui compare l'immobile che
     * rispetta la ricerca
     */
    for (i = 0 ; i < MAX_NUM_IMMOBILI ; i++){
        if (stato == lista->listaImmobili[i].statoImmobile){
            printf("\nEsiste un immobile in posizione %d che rispetta la ricerca\n", i);
        }
    }
    printf("\nNessun immobile corrispondente alla ricerca trovato\n");
}