/**
 *  @file   Funzioni_Generazione.c
 *  @brief  Procedure  per la generazione casuale
 */
#include "Funzioni_Generazione.h"

/**
 * @brief  Procedure  per la generazione casuale
 * @param[IN] immobile Prende in ingresso un puntatore ad immobile
 */
void generaImmobile(Immobile *immobile){

    srand (time(NULL));
    int metriQuadri; // variabile di supporto

    immobile->metriQuadri = rand()%METRI_QUADRI_MAX+((float)(rand()%METRI_QUADRI_MAX)/(float)(rand()%METRI_QUADRI_MAX));
    immobile->prezzo = (int)immobile->metriQuadri*P_MED_M_QUAD;

    metriQuadri = (int)immobile->metriQuadri;
    immobile->numeroVani = VANI_MIN + rand()% (metriQuadri/ DIM_VANI); // Il numero vani è dipendente dai metri quadri

    posizioneRandom(immobile);

    codiceRandom(immobile);

    immobile->numeroVerande = rand()% VERANDE_MAX;

    immobile->tipologia = rand()% ALTRO + 1;

    immobile->ascensore = false + rand()% (true+1);
    immobile->postoAuto = false + rand()% (true+1);
    immobile->scantinato = false + rand()% (true+1);
    immobile->giardino = false + rand()% (true+1);

    immobile->usoImmobile = rand()% LOCALE_COMMERCIALE + 1;
    immobile->statoImmobile = rand()% RUDERE + 1;

}

/**
 * @brief  Procedura per la generazione casuale della posizione
 *
 * Dati dei vettori di stringhe contenti tutte le regioni italiane, i comuni con il maggior numero di cittadini della
 * rispettiva regione e alcune vie scelte casualmente, tramite la s rand vengono scelte casualmente.
 *
 * @param[IN] immobile Prende in ingresso un puntatore ad immobile
 */
void posizioneRandom(Immobile *immobile){
    const char regioni[MAX_NUM][MAX_L] = {"Abruzzo", "Basilicata", "Calabria", "Campania", "Emilia-Romagna",
                                          "Friuli Venezia Giulia", "Lazio", "Liguria", "Lombardia", "Marche",
                                          "Molise", "Piemonte", "Puglia", "Sardegna", "Sicilia",
                                          "Toscana", "Trentino-Alto Adige", "Umbria", "Valle d'Aosta", "Veneto"};

    const char comuni[MAX_NUM][MAX_L] = {"Pescara", "Potenza", "Catanzaro", "Napoli", "Bologna", "Trieste",
                                         "Roma", "Genova", "Milano", "Ancona", "Campobasso", "Torino", "Bari",
                                         "Cagliari", "Palermo", "Firenze", "Trento", "Perugia", "Aosta", "Venezia"};

    const char vie[MAX_NUM][MAX_L] = {"Andrea Doria", "Emilio Colombo", "Educandato", "Medina", "Rizzoli", "Carnaro",
                                      "del Quirinale", "Aurelia", "Moscova", "Rodi", "Vittorio Veneto",
                                      "Maria Vittoria", "Dante", "Corso Vittorio Emanuele", "Capuccini", "Pelliceria",
                                      "Bassano", "Pievaiola", "Cretier", "Piave"};

    strcpy(immobile->posizione.regione, regioni[rand()%(MAX_NUM-1)]);
    strcpy(immobile->posizione.comune, comuni[rand()%(MAX_NUM-1)]);
    strcpy(immobile->posizione.via, vie[rand()%(MAX_NUM-1)]);
    immobile->posizione.numeroCivico = rand()% NUMERO_CIVICO_MAX;
}

/**
 * @brief  Procedura  per la generazione del codice identificativo
 *
 * Le prime 4 lettere per essere concordi alla regione e comune, vengono ricavate dalla generazione in posizioneRandom,
 * e convertite in maiuscolo con toupper, le restanti cifre sono generate casualmente
 *
 * @param[IN] immobile Prende in ingresso un puntatore ad immobile
 */
void codiceRandom(Immobile *immobile){
    int i;

    immobile->codiceIdentificativoImmobile[0] = toupper(immobile->posizione.regione[0]);
    immobile->codiceIdentificativoImmobile[1] = toupper(immobile->posizione.regione[1]);
    immobile->codiceIdentificativoImmobile[2] = toupper(immobile->posizione.comune[0]);
    immobile->codiceIdentificativoImmobile[3] = toupper(immobile->posizione.comune[1]);

    for (i=DIM_COD-5; i<DIM_COD; i++){
        immobile->codiceIdentificativoImmobile[i] = '0' + rand()%10;
    }
}