/** \file input.c
 * \brief File contenente le funzioni di input da tastiera
 * \section License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */
#include <stdio.h>
#include <stdlib.h>
#include "dati_globali.h"
#include "input.h"

/** \fn unsigned int controllo_input(void)
 * 	Funzione di convalida dell'input, legge un numero, se non valido da un'errore e richiede l'inserimento
 * \return numero_consentito restituisce il numero letto correttamente
 */
unsigned int controllo_input(void)
{
	/** \var numero_consentito
	 * variabile contenente il numero da analizzare per vedere se rispetta i prerequisiti per la grandella della matrice
	 */
	unsigned int numero_consentito;

	do{
		numero_consentito = lettura_intero(); //Richiama la funzione di lettura dallo stadin
		if(numero_consentito <= DIMENSIONE_SUBMATRICE){ //Se il numero non e' valido, allora
			puts("Attenzione il valore inserito supera i limiti consentiti!\n"
					"Reinserire il valore: "); //Stampa messaggio d'errore
		}
	}while(numero_consentito <= DIMENSIONE_SUBMATRICE); //Finche non e' inserito un numero valido ripete la lettura

	return (numero_consentito); // Ritorna il numero letto correttamente
}

/** \fn unsigned int lettura_intero(void){
 * 	Funzione di lettura di un'intero dallo stdinput
 * \return intero, il numero letto
 */
unsigned int lettura_intero(void){

	/** \var intero
	 * Variabile senza segno contenente il numero letto dallo standardinput
	 */
	unsigned int intero;
	/** \var esitoScanf
	 * Variabile che salva l'esito della lettura da scanf
	 */
	int esitoScanf;

	do{
		esitoScanf = scanf("%u", &intero); //Legge il valore dalla teatiera, lo assegna ad intero, se la lettura ha esito positivo, scanf assume il valore diverso da 1
		if(esitoScanf == 0){ //Se esitoScanf ha il valore pari a ' significa che e' stato inseirito un valore non valido
			scanf("%*[^\n]"); //Pulisce il buffer di lettura
			puts("\nAttenzione valore inserito non valido, inserire un numero intero positivo: ");//Stampa un messaggio d'errore
		}
	}while(esitoScanf == 0); //Ripete l'inserimento finch'e non viene inserito un valore corretto

	return (intero); //Ritorna un valore valido
}
