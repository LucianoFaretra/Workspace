/** \file output.c
 * \brief File contenente le funzioni di output
 * \section License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "dati_globali.h"
#include "accesso_dati.h"


/** \fn void stampa_messaggi(unsigned int messaggio)
 * 	Funzione di stampa messaggi per l'utente
 * \param messaggio flag per la selezione del messaggio da stampare
 */
void stampa_messaggi(unsigned int messaggio)
{
	if(messaggio == INSERIMENTO_RIGHE){
		printf("Inserire il numero di righe che compongono la matrice: ");
	}
	else if(messaggio == INSERIMENTO_COLONNE){
		printf("Inserire il numero di colonne che compongono la matrice: ");
	}
	return;
}

/** \fn void stampa_matrice(int **matrice, int numero_righe, int numero_colonne)
 * 	La funzione riempie la matrice di dati
 * \param **matrice matrice da stampare
 * \param numero_righe numero righe di cui è composta la matrice
 * \param numero_colonne numero colonne di cui è composta la matrice
 */
void stampa_matrice(int **matrice, int numero_righe, int numero_colonne)
{
	unsigned int indice_righe;
	unsigned int indice_colonne;

	puts("La matrice da esaminare e' la seguente:\n");
	indice_righe = 0;
	while(indice_righe < numero_righe){
		indice_colonne = 0;
		while(indice_colonne < numero_colonne){
			printf("%2d ", lettura_matrice(matrice, indice_righe, indice_colonne));//Leggi il valore e stampalo formattato
			indice_colonne++;
		}
		puts("");//Vaia  capo
		indice_righe++;
	}

	return;
}

/** \fn void stampa_risultato(dati_submatrice reticolo_piu_grande)
 * 	La funzione stampa i dati della submatrice piu grande
 * \param reticolo_piu_grande struttura contenente i dati della submatrice piu grande
 */
void stampa_risultato(dati_submatrice reticolo_piu_grande)
{
	printf("\nLa submatrice 3x3 più grande e' quella perimetrale alla cella con coordinate "
		"X:%d e Y:%d con valore: %d.\n", reticolo_piu_grande.riga, reticolo_piu_grande.colonna, reticolo_piu_grande.somma_valori);
	return;
}
