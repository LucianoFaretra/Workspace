/** \file elaborazione_dati.c
 * \brief File contenente le funzioni di elaborazione dati
 * Il seguente file contiene le funzioni di elaborazione dei dati
 * \section  License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dati_globali.h"
#include "output.h"
#include "elaborazione_dati.h"

/** \fn matrice alloca_matrice(matrice m)
 * La funzione alloca la memoria necessaria alla matrice
 * \return m Struttura contenente la matrice allocata
 */
void alloca_matrice(matrice *m)
{
	/** \var indice_righe
	 * Indice utilizzato per scandire la amtrice
	 */
	size_t indice_righe = 0;

	m->mat = malloc(m->righe * sizeof(int *)); //Alloca la memoria per le righe della matrice

	while(indice_righe < m->righe){
		m->mat[indice_righe] = malloc(m->colonne * sizeof(int)); //Alloca la memoria per le colonne della matrice
		indice_righe++;
	}
	return;
}

/** \fn int controllo_matrice_void(matrice m)
 * La funzione riceve una struttura contenente una matrice e controlla se e' stata allocata la memoria o no
 * \return esito_controllo se esito_controllo equivale a 0 l'allocazione della memoria ha fallito, altrimenti se 1 l'allocazione e stata effettuata correttamente
 */
int controllo_matrice_void(matrice m)
{
	/** \var esito_controllo
	 * La variabile indica l'esito del controllo sulla matrice
	 */
	int esito_controllo;

	if(m.mat == NULL){//Controlla se la matrice e' nulla
		esito_controllo = 0;//Se nulla assegna ad esito 0
	}
	else{
		esito_controllo = 1;//Altrimenti assegna ad esito 1
	}

	return (esito_controllo);//Restituisci l'esito alla funzione chiamante
}

/** \fn int genera_numero_casuale(void)
 * La funzione genera un numero casuale compreso tra 0 e MAX_CASUALE
 * \return numero generato casualmente
 */
int genera_numero_casuale(void)
{
	return (rand() % MAX_CASUALE);
}

/** \fn void riempi_matrice(matrice *m)
 * La funzione riempie la matrice di numeri casuali
 * \param *m struttura contenente la matrice, il numero di riche e numero di colonne passato per indirizzo
 */
void riempi_matrice(matrice *m)
{

	/** \var indice_righe
	 * La variabile contiene l'indice di scorrimento per le righe
	 */
	size_t indice_righe;

	/** \var indice_colonne
	 * La variabile contiene l'indice di scorrimento per le colonne
	 */
	size_t indice_colonne;

	indice_righe = 0;
	while(indice_righe < m->righe){
		indice_colonne = 0;
		while(indice_colonne < m->colonne){
			m->mat[indice_righe][indice_colonne] = genera_numero_casuale();//Assegna alla coordinata il numero casuale
			indice_colonne++;
		}
		indice_righe++;
	}
	return;
}

/** \fn int controlla_quadrato_magico(matrice m)
 * La funzione calcola le righe, colonne e diagonali e stampa un messaggio a seconda
 * che sia un quadrato magico o meno
 * \param m struttura contenente la matrice, il numero di riche e numero di colonne
 */
int controlla_quadrato_magico(matrice m)
{
	/** \var esitoControllo
	 * La variabile contiene l'esito del controllo se la matrice è magica o meno
	 */
	int esitoControllo = 1;

	/** \var *valoreRighe
	 * l'array *valoreRighe contiene la somma dei valori contenuti in ogni riga della matrice
	 */
	int *valoreRighe = malloc(m.righe*sizeof(int));

	/** \var *valoreColonne
	 * l'array *valoreColonne contiene la somma dei valori contenuti in ogni colonna della matrice
	 */
	int *valoreColonne = malloc(m.righe*sizeof(int));
	/** \var valoreDiagonale1
	 * La variabile contiene il valore della diagonale che parte dala coordinata m.righe, 0
	 */
	int valoreDiagonale1 = 0;
	/** \var valoreDiagonale2
	 * La variabile contiene il valore della diagonale che parte dala coordinata 0, m.colonn
	 */
	int valoreDiagonale2 = 0;
	/** \var indice_righe
	 * La variabile contiene l'indice di scorrimento per le righe
	 */
	size_t indice_righe;
	/** \var indice_colonne
	 * La variabile contiene l'indice di scorrimento per le colonne
	 */
	size_t indice_colonne;

	indice_righe = 0;
	while(indice_righe < m.righe){
		indice_colonne = 0;
		while(indice_colonne < m.colonne){
			if((indice_colonne + indice_righe) == (m.righe - 1)){//Un valore fa parte della diagonale se il risultato delle sue coordinate e' pari a m.righe - 1
				valoreDiagonale2 += m.mat[indice_righe][indice_colonne];//Somma il valore alla variabile contenente il valore della diagonale2
			}
			if(indice_colonne == indice_righe){//Un valore fa parte della diagonale1 se le coordinate X e Y sono uguali
				valoreDiagonale1 += m.mat[indice_righe][indice_colonne];//Somma il valore alla variabile contenente il valore della diagonale1
			}
			valoreRighe[indice_righe] += m.mat[indice_righe][indice_colonne];//Somma il numero dell'apposito totale di riga
		indice_colonne++;
		}
		valoreColonne[indice_colonne] += m.mat[indice_righe][indice_colonne];//Somma il numero dell'apposito totale di colonna
		indice_righe++;
	}

	if(valoreDiagonale1 != valoreDiagonale2){//Se le due diagonali sono diverse
		esitoControllo = 0;//L'esito e' negativo
	}
	else{
		indice_righe = 0;
		while(indice_righe < m.righe){
			indice_colonne = 0;
			while(indice_colonne < m.colonne){
				if((valoreRighe[indice_righe] != valoreColonne[indice_colonne]) && (valoreRighe[indice_righe] != valoreDiagonale1)){//controlla che i totali delle righe siano uguali ai totali delle colonne
					indice_righe = m.righe;//Esci dal ciclo
					indice_colonne = m.colonne;//Esci dal ciclo
					esitoControllo = 0;//L'esito e' negativo
				}
			indice_colonne++;
			}
		indice_righe++;
		}
	}

	return (esitoControllo);
}
