/**
 * \file elaborazione.c
 * File contenente le funzioni di manipolazione dati
 * \author Luciano faretra
 * \date 2015
 * \ver 1.0
 */

#include <stdlib.h>
#include <stdio.h>
#include "elaborazione.h"


/**
 * \fn int trova_targhet(unsigned int** tabella, int j, int targhet)
 * Cerca il targhet relativo alla colonna j nella tabella
 * \param tabella puntatore doppio alla tabella in cui cercare il targhet
 * \param j colonna in cui cercare il targhet
 * \param targhet targhet da cercare
 * \return ritorna la posizione del targhet, -1 nel caso in cui non ci sia
 */
int trova_targhet(unsigned int** tabella, int j, int targhet)
{
	int i = -1;
	FILE* file_tabelle;
	unsigned int numero_righe;
	unsigned int numero_colonne;
	unsigned int indice_righe;

	file_tabelle = fopen("tabelle.txt", "r");
	if(file_tabelle != NULL){
		fscanf(file_tabelle, "%u %u", &numero_righe, &numero_colonne);
	}

	if(j <= numero_colonne){
		indice_righe = 0;
		while(indice_righe < numero_righe ){
			if(tabella[indice_righe][j] == targhet){
				i = indice_righe;
				indice_righe = numero_righe;
			}
			else
				printf("%d\n", tabella[indice_righe][j]);
				indice_righe++;
		}
	}
	else{
		puts("numero colonna inesistente");
	}

	return (i=+1); //Il c comincia da 0 non da 1
}
