/** \file input.c
 * \brief File contenente le funzioni di input.
 * Il seguente file contiene tutte le funzioni di input dati
 * \section  License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "output.h"
#include "dati_globali.h"

/** \fn int lettura_intero(void)
 * La funzione legge un valore dallo standard input, se si tratta di un intero lo
 * restituisce alla funzione chiamante, altrimenti ripete l'inserimento
 * \return intero_letto Intero letto dallo standard input correttamente
 */
int lettura_intero(void)
{
	/** \var intero_letto
	 * Intero letto dalla tastiera da convalidare
	 */
	int intero_letto;

	/** \var esitoScanf
	 * Esito della lettura del dato, 1 se la lettura ha avuto esito positivo, 0 se negativo
	 */
	int esitoScanf;

	do{
		printf(">: ");
		esitoScanf = scanf("%d", &intero_letto);
		if(esitoScanf == 0){//Se la lettura ha avuto esito negativo
			scanf("%*[^\n]");//Pulisce il buffer
			stampa_messaggi(INPUT_ERRATO);//Stampa messaggio d'errore per avvertire l'utente dell'errore
		}
	}while(esitoScanf == 0);//Esegui finchè la lettura non ha avuto successo

	return (intero_letto);//Ritorna il valore letto correttamente
}

/** \fn matrice controllo_matrice_quadrata(void)
 * La funzione legge il numero di righe e colonne e l'assegna alla struttura dati m, accetta solo amtrice quadrata
 * \return m Struttura contenente i dati della matrice
 */
void controllo_matrice_quadrata(matrice *m)
{
	do{
		stampa_messaggi(INSERISCI_INTERO_RIGHE);
		m->righe = lettura_intero(); //Assegna a m->righe il valore letto dallo stdio
		stampa_messaggi(INSERISCI_INTERO_COLONNE);
		m->colonne = lettura_intero();//Assegna a m->colonne il valore letto dallo stdio
	}while(m->righe != m->colonne);

	return;
}
