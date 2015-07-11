/*
 * dati_globali.h
 *
 *  Created on: 19/mag/2015
 *      Author: ibanez89
 */

#ifndef DATI_GLOBALI_H_
#define DATI_GLOBALI_H_

/**
 * \def INPUT_ERRATO
 * flag corrispondente all'input errato
 */
#define INPUT_ERRATO 0
/**
 * \def INSERISCI_INTERO_RIGHE
 * flag corrispondente al messaggio per l'inserimento delle righe
 */
#define INSERISCI_INTERO_RIGHE 1
/**
 * \def INSERISCI_INTERO_COLONNE
 * flag corrispondente al messaggio per l'inserimento delle colonne
 */
#define INSERISCI_INTERO_COLONNE 2
/**
 * \def ERRORE_ALLOCAZIONE
 * flag corrispondente al messaggio per l'errore dell'allocazione
 */
#define ERRORE_ALLOCAZIONE 3
/**
 * \def STAMPA_MATRICE
 * flag corrispondente al messaggio introduttivo per la stampa della matrice
 */
#define STAMPA_MATRICE 4
/**
 * \def MATRICE_NON_MAGICA
 * flag corrispondente al messaggio che attesta che non si e' difronte ad un quadrato magico
 */
#define MATRICE_NON_MAGICA 5
/**
 * \def MATRICE_MAGICA
 * flag corrispondente al messaggio che attesta che si e' difronte ad un quadrato magico
 */
#define MATRICE_MAGICA 6
/**
 * \def TENTATIVI
 * flag corrispondente al messaggio che attesta il numero di tentativi effettuati
 */
#define TENTATIVI 7

/**
 * \def MAX_CASUALE
 * flag massimo numero calcolabile casualmente
 */
#define MAX_CASUALE 3

/** \struct matrice
 * Struttura contenente i dati della matrice
 */
typedef struct matrice{
	///Numero di righe
	int righe;
	///Numero di colonne
	int colonne;
	///Matrice bidimensionale
	int **mat;
}matrice;

#endif /* DATI_GLOBALI_H_ */
