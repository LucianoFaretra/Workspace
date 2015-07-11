/*
 * inputOutput.c
 *
 *  Created on: 10/lug/2015
 *      Author: ibanez89
 */
#include <stdlib.h>
#include <stdio.h>
#include "inputOutput.h"
#include "dati_globali.h"

/**
 * \fn unsigned int inizializzazione(void)
 * La funzione stampa il menu di scelta inizializzando il programma
 * \return valore inserito dall'utente
 */
unsigned int inizializzazione(void)
{
	/**
	 * \var valore_inserito
	 * Valore inserito dall'utente
	 */
	unsigned int valore_inserito = EXIT;

	do{
		puts("Prego inserire il numero di funzione da eseguire;");
		puts("");
		puts("0 - Stampa Giacenza");
		puts("1 - Aggiungi Nuovo Record");
		puts("2 - Elimina Record");
		puts("3 - Modifica Quantità record");
		puts("4 - Modifica Prezzo record");
		puts("5 - Esci");
		puts("");

		printf("->: ");
		valore_inserito = lettura_intero();

		if(valore_inserito > EXIT){
			puts("Attenzione, scelta non valida!");
		}
	}while(valore_inserito > EXIT);

	return (valore_inserito);
}

/**
 * \fn unsigned int lettura_intero(void)
 * La funzione legge un'intero senza segno dallo stdin
 * \return ritorna l'intero senza segno letto
 */
unsigned int lettura_intero(void)
{
	/**
	 * \var intero
	 * inetro letto da tastiera
	 */
	unsigned int intero;
	/**
	 * \var esitoScanf
	 * Esito della funzione scanf
	 */
	int esitoScanf;

	do{
		esitoScanf = scanf("%u", &intero);
		if(esitoScanf == 0){
			scanf("%*[^/n]");
			puts("Attenzione non e' stato inserito un intero positivo!");
		}
	}while(esitoScanf == 0);

	return (intero);
}

/**
 * \fn float lettura_float(void)
 * La funzione legge un float dallo stdin
 * \return il float letto da tastiera
 */
float lettura_float(void)
{
	float prezzo;
	int esitoScanf;

	do{
		esitoScanf = scanf("%f", &prezzo);
		if(esitoScanf == 0){
			scanf("%*[^/n]");
			puts("Attenzione non e' stato inserito un prezzo valido!");
		}
	}while(esitoScanf == 0);

	return (prezzo);
}

/**
 * \fn unsigned int lettura_progressivo(void)
 * La funzione legge da file il progressivo attuale
 * \return la funzione ritorna il progressivo letto
 */
unsigned int lettura_progressivo(void)
{
	/**
	 * \var file_progressivo
	 * Puntatore alla struttura di tipo file
	 */
	FILE* file_progressivo;

	/**
	 * \var progressivo_attuale
	 * Variabile contenente il progressivo attuale
	 */
	int progressivo_attuale;

	file_progressivo = fopen("index_progressivo.txt", "r");

	if(file_progressivo == NULL){
		puts("Attenzione, file index_progressivo non presente");
	}
	else{
		fscanf(file_progressivo, "%u", &progressivo_attuale);
		if(progressivo_attuale < MINIMOPROGRESSIVO){
			puts("attenzione file progressivo corrotto!");
			progressivo_attuale = 0;
		}
	}

	return (progressivo_attuale);
}

/**
 * \fn unsigned int scrittura_progressivo(unsigned int progressivo_attuale)
 * La funzione scrive il progressivo su file
 * \param progressivo_attuale Attuale numero di progressivo
 * \return esito dell'operazione, 0 successo, 1 fallimento
 */
unsigned int scrittura_progressivo(unsigned int progressivo_attuale)
{
	/**
	 * \var file_progressivo
	 * Puntatore a struttura di tipo file
	 */
	FILE* file_progressivo;
	/**
	 * \var esito_scrittura
	 * Variabile contenente l'esito della funzione, 1 fallimento, 0 successo
	 */
	unsigned int esito_scrittura = 1;

	file_progressivo = fopen("index_progressivo.txt", "w");

	if(file_progressivo == NULL){
		puts("Attenzione, apertura file index_progressivo non riuscita");
	}
	else{
		fprintf(file_progressivo, "%u", progressivo_attuale);
		esito_scrittura = 0;
	}

	return (esito_scrittura);
}


/**
 * \fn unsigned int lettura_magazzino(tab_magazzino magazzino[])
 * \param magazzino[] struttura contenente la giacenza di magazzino
 * \return esito dell'oprtazione, 0 successo,  1 fallimento
 */
unsigned int lettura_magazzino(tab_magazzino magazzino[])
{
	/**
	 * \var file_hardware
	 * puntatore a struttura di tipo file
	 */
	FILE* file_hardware;
	/**
	 * \var esito
	 * variabile contenente l'esito della funzione, 0 successo, 1 fallimento
	 */
	unsigned int esito;
	/**
	 * \var indice_array
	 * variabile contenente l'indice di scorrimento per l'array
	 */
	int indice_array;

	file_hardware = fopen("hardware.txt", "r");
	if(file_hardware == NULL){
		puts("File hardware.txt non trovato, il programma terminera in modo inatteso");
		esito = 1;
	}
	else{
		indice_array = 0;
		while(!feof(file_hardware) && indice_array < DIMENISIONEMAGAZZINO){
			fscanf(file_hardware, "%u %30s %u %f", &magazzino[indice_array].record, magazzino[indice_array].nomeProdotto, &magazzino[indice_array].quantita, &magazzino[indice_array].prezzo);
			indice_array++;
		}
	}

	return (esito);
}


/**
 * \fn unsigned int scrittura_magazzino(tab_magazzino magazzino[])
 * Funzione per la scrittura dei dati della memoria riguardanti in magazzino su file
 * \param magazzino[] struttura contenente la giacenza di magazzino
 * \return esito dell'operazione, 1 successo, 0 fallimento
 */
unsigned int scrittura_magazzino(tab_magazzino magazzino[])
{
	/**
	 * \var file_hardware
	 * puntatore alla struttura di tipo file
	 */
	FILE* file_hardware;
	/**
	 * \var esito
	 * esito dell'operazione, 1 successo, 0 fallimento
	 */
	unsigned int esito;
	/**
	 * \var indice_array
	 * indice dell'array per sccorrere l'array stessa
	 */
	int indice_array;

	file_hardware = fopen("hardware.txt", "w");
	if(file_hardware == NULL){
		puts("Impossibile creare File hardware.txt, il programma terminera in modo inatteso");
		esito = 1;
	}
	else{
		indice_array = 0;
		while(indice_array < DIMENISIONEMAGAZZINO){
			if(magazzino[indice_array].record != 0){
				fprintf(file_hardware, "\n%u %30s %u %f", magazzino[indice_array].record, magazzino[indice_array].nomeProdotto, magazzino[indice_array].quantita, magazzino[indice_array].prezzo);
			}
			indice_array++;
		}
	}

	return (esito);
}

/**
 * \fn void stampa_magazzino(tab_magazzino magazzino[])
 * funzione per stampare la giacenza di magazzino caricata in memoria
 * \param magazzino[] struttura contenente la giacenza di magazzino attuale
 */
void stampa_magazzino(tab_magazzino magazzino[])
{
	/**
	 * \var indice_array
	 * indice utilizzato per scorrere l'array
	 */
	int indice_array;

	printf("%-8s %30s %-8s %-8s \n", "Record#", "Nome attrezzo", "Quantita'", "Costo");
	indice_array = 0;
	while(indice_array < DIMENISIONEMAGAZZINO && magazzino[indice_array].record != 0){
		printf("%8u %30s %8u %8.2f \n", magazzino[indice_array].record, magazzino[indice_array].nomeProdotto, magazzino[indice_array].quantita, magazzino[indice_array].prezzo);
		indice_array++;
	}

	return;
}

/**
 * \fn void stampa_operazione_avvenuta(void)
 * Funzione di stampa messaggio operazione avvenuta
 */
void stampa_operazione_avvenuta(void)
{
	puts("Operazione avvenuta con successo!");
	return;
}
/**
 * \fn void stampa_operazione_errore(void)
 * Funzione di stampa messaggio operazione fallita
 */
void stampa_operazione_errore(void)
{
	puts("Operazione non riuscita, errore!");
	return;
}
