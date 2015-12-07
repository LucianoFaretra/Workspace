/**
 * \file inputOutput.c
 * File contenente le funzioni di input/output
 * \author Luciano faretra
 * \date 2015
 * \ver 1.0
 */

#include <stdlib.h>
#include <stdio.h>
#include "inputOutput.h"

/**
 * \fn unsigned int** lettura_file_testo(void)
 * La funzione legge il file di testo e la salva in una tabella
 * \return ritorna la matrice bidimensionale allocata dinamicamente contenente la tabella
 */
unsigned int** lettura_file_testo(void)
{
	/**
	 * \var file_tabelle
	 * Puntatore a struttura di tipo file
	 */
	FILE* file_tabelle;
	/**
	 * \var tabella
	 * Pntatre doppio a intero senza segno
	 */
	unsigned int** tabella;
	/**
	 * \var numero_righe
	 * intero contenente il numero di righe che compongono la tabella
	 */
	unsigned int numero_righe;
	/**
	 * \var numero_colonne
	 * intero contenente il numero di colonne che compongono la tabella
	 */
	unsigned int numero_colonne;
	/**
	 * \var indice_righe
	 * Indice per scorrere le righe dell'array
	 */
	int indice_righe;
	/**
	 * \var indice_colonne
	 * indice per scorrere le colonne dell'array
	 */
	int indice_colonne;
	/**
	 * \var err
	 * Segnale d'errore
	 */
	int err = 0;

	file_tabelle = fopen("tabelle.txt", "r");
	if(file_tabelle != NULL){
		fscanf(file_tabelle, "%u %u", &numero_righe, &numero_colonne);
	}
	tabella = malloc(numero_righe * sizeof(int*));
	if(tabella != NULL){
		indice_righe = 0;
		while(indice_righe < numero_righe){
			tabella[indice_righe] = malloc(numero_colonne * sizeof(int));
			indice_righe++;
		}
	}
	else{
		puts("errore allocazione righe, il programma terminera in modo inatteso");
		err = 1;
	}
	if(err != 1){
		while(!feof(file_tabelle)){
			indice_righe = 0;
			while(indice_righe < numero_righe){
				indice_colonne = 0;
				while(indice_colonne < numero_colonne){
 					fscanf(file_tabelle, "%u", &tabella[indice_righe][indice_colonne]);
 					indice_colonne++;
				}
				indice_righe++;
			}
		}
	}


	return (tabella);
}

/**
 * \fn void stampa_targhet(int i)
 * \param i Posizione del targhet
 */
void stampa_targhet(int i)
{
	if(i == -1){
		puts("\nil targhet non e' stato trovato\n");
	}
	else{
		printf("\nil targhet e' nella posizione della riga: %d\n", i);
	}
	return;
}
