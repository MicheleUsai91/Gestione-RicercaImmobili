/**
 * @file Funzioni_Inserimento.c
 * @brief Funzioni e procedure per inserire i dati
 */
#include "Funzioni_Inserimento.h"

/**
 * @brief Funzioni e procedure per inserire i dati
 * @param[IN] immobile Puntatore all'immobile
 *
 * Stampa i messaggi per l'utente e richiama funzioni o procedure necessarie all'inserimento del relativo campo
 */
void inserisciImmobile(Immobile *immobile){
    printf("\nInserisci i dati dell'immobile\n");
    printf("\nInserisci il prezzo (%d - %dM)\n", PREZZO_MIN, PREZZO_MAX/1000000);
    immobile->prezzo = inserisciIntero(immobile->prezzo, PREZZO_MIN, PREZZO_MAX);
    printf("\nMetri quadri (%d - %d): \n", METRI_QUADRI_MIN, METRI_QUADRI_MAX);
    immobile->metriQuadri = inserisciFloat(immobile->metriQuadri, METRI_QUADRI_MIN, METRI_QUADRI_MAX);
    printf("\nInserisci il numero di vani (%d - %d)\n", NUMERO_VANI_MIN, NUMERO_VANI_MAX);
    immobile->numeroVani = inserisciIntero(immobile->numeroVani, NUMERO_VANI_MIN, NUMERO_VANI_MAX);
    inserisciPosizione(immobile);
    inserisciCodiceIdentificativo(immobile);
    printf("\nInserisci il numero di verande (0 - %d)\n", MAX_NUM_VERANDE);
    immobile->numeroVerande = inserisciIntero(immobile->numeroVerande, 0, MAX_NUM_VERANDE);
    inserisciTipologia(immobile);
    inserisciBooleani(immobile);
    inserisciUsoImmobile(immobile);
    inserisciStatoImmobile(immobile);
}

/**
 * @brief Funzione per inserire un intero entro un range di valori
 * @param[IN] numero Numero inserito dall'utente che verrà poi controllato e restituito
 * @param[IN] min Minimo numero valido per restituire il valore
 * @param[IN] max Massimo numero valido per restituire il valore
 * @param[OUT] numero Se il numero inserito dall'utente rientra nei parametri, verrà restituito
 *
 * L'utente inserisce il numero e viene controllato con un if, se rientra tra min o max, nel caso in cui la condizione
 * non sia rispettata, verrà restituito un messaggio di errore
 */
int inserisciIntero(int numero, int min, int max){
    scanf("%d", &numero);
    if (numero < min || numero > max){
        printf("\n\aErrore! Il valore non rientra nei parametri\n");
        printf("\nInserisci nuovamente:\n");
        inserisciIntero(numero, min, max); // se l'inserimento è errato, l'utente può reinserire i dati
    }
    return numero;
}

/**
 * @brief Funzione per inserire un float entro un range di valori
 * @param[IN] numero Numero inserito dall'utente che verrà poi controllato e restituito
 * @param[IN] min Minimo numero valido per restituire il valore
 * @param[IN] max Massimo numero valido per restituire il valore
 * @param[OUT] numero Se il numero inserito dall'utente rientra nei parametri, verrà restituito
 *
 * L'utente inserisce il numero e viene controllato con un if, se rientra tra min o max, o che sia un carattere,
 * nel caso in cui la condizione non sia rispettata, verrà restituito un messaggio di errore
 */
float inserisciFloat(float numero, float min, float max){
    svuotaBuffer();
    scanf("%f", &numero);

    if (numero < min || numero > max && isdigit((int)numero) == false){
        printf("\n\aErrore! Il valore deve essere compreso tra 1 e 10000 e non deve contenere caratteri\n");
        inserisciFloat(numero, min, max); // se l'inserimento è errato, l'utente può reinserire i dati
    }
    return numero;
}

/**
 * @brief Funzione per inserire una stringa, che non contenga valori numerici
 * @param[IN] array Stringa inserita dall'utente
 * @param[OUT] array puntatore alla stringa inserita dall'utente
 *
 * L'utente inserisce la stringa e ogni carattere viene controllato che non sia un numero con un if, nel caso in cui
 * la condizione non sia rispettata, verrà restituito un messaggio di errore
 */
char inserisciArray(char array[]){
    svuotaBuffer();
    int i;
    scanf("%31[^\n]s", array);

    for (i=0;i<=DIM_POS;i++){
        if(isdigit(array[i]) == true){
            printf("\n\aErrore! Non puoi inserire numeri\n");
            printf("\nInserisci nuovamente:\n");
            return inserisciArray(array); // se l'inserimento è errato, l'utente può reinserire i dati
        }
    }
    return *array;
}

/**
 * @brief Funzione per inserire un booleano
 * @param[IN] valore Booleano inserito dall'utente
 * @param[OUT] valore puntatore alla stringa inserita dall'utente
 *
 * L'utente inserisce il valore e viene controllato con un if, che sia vero o falso e nel caso in cui la condizione
 * non sia rispettata, verrà restituito un messaggio di errore
 */
bool inserisciBooleano(bool valore){
    svuotaBuffer();
    printf("\n[%d] -> NO\n[%d] -> SI\n", false, true);
    printf("Scelta:");
    scanf("%d", &valore);

    if (valore != false && valore != true){
        printf("\n\aErrore! Il valore non rientra nei parametri\n");
        printf("\nInserisci nuovamente:\n");
        inserisciBooleano(valore); // se l'inserimento è errato, l'utente può reinserire i dati
    }
    return valore;
}

/**
 * @brief Procedura per inserire la posizione
 * @param[IN] immobile Puntatore all'immobile
 *
 * Procedura basata sulla funzione inserisciArray
 */
void inserisciPosizione(Immobile *immobile){
    printf("\n\t  POSIZIONE\n");
    printf("\nRegione: \n");
    immobile->posizione.regione[DIM_POS] = inserisciArray(immobile->posizione.regione);
    printf("\nComune: \n");
    immobile->posizione.comune[DIM_POS] = inserisciArray(immobile->posizione.comune);
    printf("\nVia: \n");
    immobile->posizione.via[DIM_POS] = inserisciArray(immobile->posizione.via);
    printf("\nNumero Civico (0 - %d): \n", NUMERO_CIVICO_MAX);
    immobile->posizione.numeroCivico = inserisciIntero(immobile->posizione.numeroCivico, 0, NUMERO_CIVICO_MAX);
}

/**
 * @brief Procedura per inserire il codice
 * @param[IN] immobile Puntatore all'immobile
 *
 * Procedura che tramite un ciclo for permette di inserire carattere per carattere, controllando che le prime 4 lettere
 * siano maiuscole e non siano numeri, e le ultime 4 cifre siano solo numeriche
 */
void inserisciCodiceIdentificativo(Immobile *immobile){
    svuotaBuffer();

    int i;

    printf("\nCodice identificativo immobile: \n");
    printf("\nPrime 2 lettere per la regione, le 2 successive per il comune e le restanti 5 numeriche\n");
    for (i = 0 ; i < DIM_COD ; i++){
        scanf("%c", &immobile->codiceIdentificativoImmobile[i]);
        if (immobile->codiceIdentificativoImmobile[i] == '\n'){
            break; // se l'inserimeto è corretto, la procedura si fermerà
        }
    }
    // controllo sui caratteri
    for (i=0; i<=DIM_COD-6; i++){
        if (isupper(immobile->codiceIdentificativoImmobile[i]) == false){
            printf("\n\aErrore! Solo maiuscole\n");
            inserisciCodiceIdentificativo(immobile); // se l'inserimento è errato, l'utente può reinserire i dati
        }
    }
    // controllo sulle cifre
    for (i=DIM_COD-5; i<DIM_COD; i++){
        if (isdigit(immobile->codiceIdentificativoImmobile[i]) == false){
            printf("\n\aErrore! Le ultime 5 cifre devono essere numeri\n");
            inserisciCodiceIdentificativo(immobile); // se l'inserimento è errato, l'utente può reinserire i dati
        }
    }
}

/**
 * @brief Procedura per inserire la tipologia
 * @param[IN] immobile Puntatore all'immobile
 *
 * Procedura che sfrutta la procedura stampaEnumerazione per stampare la scelta della tipologia e successivamente
 * usa la procedura inserisciIntero per la scelta dell'utente
 */
void inserisciTipologia(Immobile *immobile){
    svuotaBuffer();

    printf("\nTipologia\n");
    char tipologia[] = "tipologia"; // stringa necessaria alla funzione stampaEnumerazione
    stampaEnumerazione(tipologia);
    printf("\nScelta: ");
    immobile->tipologia = inserisciIntero(immobile->tipologia, INDIPENDENTE, ALTRO);
}

/**
 * @brief Procedura per inserire i 4 valori booleani
 * @param[IN] immobile Puntatore all'immobile
 *
 * Procedura che sfrutta la funzione inserisciBooleano per inserire i campi con valore bool
 */
void inserisciBooleani(Immobile *immobile){
    printf("\nE' provvisto di ascensore?");
    immobile->ascensore = inserisciBooleano(immobile->ascensore);

    printf("\nE' provvisto di posto auto?");
    immobile->postoAuto = inserisciBooleano(immobile->postoAuto);

    printf("\nE' provvisto di scantinato?");
    immobile->scantinato = inserisciBooleano(immobile->scantinato);

    printf("\nE' provvisto di giardino?");
    immobile->giardino = inserisciBooleano(immobile->giardino);
}

/**
 * @brief Procedura per inserire l'uso dell'immobile
 * @param[IN] immobile Puntatore all'immobile
 *
 * Procedura che sfrutta la procedura stampaEnumerazione per stampare la scelta dell'uso e successivamente
 * usa la procedura inserisciIntero per la scelta dell'utente
 */
void inserisciUsoImmobile(Immobile *immobile){
    svuotaBuffer();

    printf("\nUso immobile\n\n");
    char uso[] = "uso"; // stringa necessaria alla funzione stampaEnumerazione
    stampaEnumerazione(uso);
    printf("\nScelta: ");
    immobile->usoImmobile = inserisciIntero(immobile->usoImmobile, ABITATIVO, LOCALE_COMMERCIALE);
}

/**
 * @brief Procedura per inserire lo stato dell'immobile
 * @param[IN] immobile Puntatore all'immobile
 *
 * Procedura che sfrutta la procedura stampaEnumerazione per stampare la scelta dello stato e successivamente
 * usa la procedura inserisciIntero per la scelta dell'utente
 */
void inserisciStatoImmobile(Immobile *immobile){
    svuotaBuffer();

    printf("\nStato immobile\n\n");
    char stato[] = "stato"; // stringa necessaria alla funzione stampaEnumerazione
    stampaEnumerazione(stato);
    printf("\nScelta: ");
    immobile->statoImmobile = inserisciIntero(immobile->statoImmobile, NUOVO, RUDERE);
}