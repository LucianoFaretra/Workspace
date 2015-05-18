/** \file main.c
 * \brief Esercizio in cui data una matrice di n righe e n colonne composta da numeri casuali, il computer trova qual'è la submatrice di 3x3 più grande
 * \section License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "input.h"
#include "output.h"
#include "elaborazione_dati.h"
#include <time.h>


int main(void)
{
	/** \var numero_righe
	 * Variabile contenente il numero di righe da cui e' composta la matrice da analizzare
	 */
	int numero_righe;
	/** \var numero_colonne
	 * Variabile contenente il numero di colonne da cui e' composta la matrice da analizzare
	 */
	int numero_colonne;
	/** \var **matricePtr
	 * Puntatore a matrice doppia su cui allocare la memoria
	 */
	int **matricePtr;

	srand(time(NULL)); //Inizializza il seme per generare numeri casuali basati sull'orario

	stampa_messaggi(INSERIMENTO_RIGHE);//Stampa il messaggio d'inserimento
	numero_righe = controllo_input();//Leggi il numero di righe dalla tastiera
	stampa_messaggi(INSERIMENTO_COLONNE);//Stampa il messaggio d'inserimento
	numero_colonne = controllo_input();//Leggi il numero di colonne dalla tastiera

	matricePtr = alloca_matrice(numero_righe, numero_colonne);//Alloca lo spazio alla matrice

	if(1 == controllo_matrice_nulla(matricePtr)){//Se la matrice ha lo spazio allocato correttamente, allora
		composizione_matrice(matricePtr, numero_righe, numero_colonne);//Riempi la matrice di numeri casuali
		stampa_matrice(matricePtr, numero_righe, numero_colonne);//Stampa la matrice
		stampa_risultato(trova_submatrice_maggiore(matricePtr, numero_righe, numero_colonne));//Trova la submatrice piu grande e stampane i dati
	}

	return (0);//Termina il programma
}
