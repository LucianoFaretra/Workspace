/** \file output.c
 * \brief File contenente le funzioni di output
 * Il seguente file contiene le funzioni di stampa dei messaggi
 * \section  License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"


/** \fn void stampa_messaggi(int messaggio)
 * La funzione stampa il messaggio a seconda del valore che riceve in input
 * \param messaggio valore flag sul messaggio da stampare
 */
void stampa_messaggi(int messaggio)
{
	if(messaggio == INPUT_ERRATO){
		puts("Attenzione non e' stato inserito un intero valido!"
				"\nRipetere l'inserimento");
	}
	else if(messaggio == INSERISCI_INTERO_RIGHE){
		puts("Inserire un intero positivo pari al numero di righe della matrice quadrata:");
	}
	else if(messaggio == INSERISCI_INTERO_COLONNE){
		puts("Inserire un intero positivo pari al numero di colonne della matrice quadrata, deve essere uguale alle righe:");
	}
	else if(messaggio == ERRORE_ALLOCAZIONE){
		puts("Attenzione, non e' stato possibile allocare memoria alla matrice, il programma terminera' in modo inatteso.");
	}
	else if(messaggio == STAMPA_MATRICE){
		puts("La seguente e' la matrice generata casualmente:");
	}
	else if(messaggio == MATRICE_MAGICA){
		puts("Ottimo, hai trovato un quadrato magico!");
	}
	else if(messaggio == MATRICE_NON_MAGICA){
		puts("Peccato, la matrice generata non e' un quadrato magico");
	}
	else if(messaggio == TENTATIVI){
		printf("Diavolo, ci abbiamo dovuto provare tutte queste volte: ");
	}
	return;
}

/** \fn void stampa_matrice(matrice m)
 * La funzione stampa la matrice ricevuta in input
 * \param m struttura contenente la matrice da stampare
 */
void stampa_matrice(matrice m)
{
	size_t indice_righe;
	size_t indice_colonne;

	indice_righe = 0;
	while(indice_righe < m.righe){
		indice_colonne = 0;
		while(indice_colonne < m.colonne){
			printf("%2d ", m.mat[indice_righe][indice_colonne]);
			indice_colonne++;
		}
		puts("");
		indice_righe++;
	}
	return;
}
