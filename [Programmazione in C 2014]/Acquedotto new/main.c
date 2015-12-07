/*
 * main.c
 *
 *  Created on: 31 ago 2015
 *      Author: ibanez89
 */
/**
 * 18:05
 */

#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "input_output.h"

int main(void)
{
	FILE* file_dati;
	float consumi_unita[MAX_NUM_UNITA] = {0};
	unsigned int numero_unita;

	file_dati = fopen("consumi.txt", "r");
	if(file_dati != NULL){
		numero_unita = lettura_dati(file_dati, consumi_unita);
		if(numero_unita != 0){
			totale_unita_abitative(consumi_unita, numero_unita);
		}
		else{
			printf("Attenzione, numero unita 0, il file e' vuoto oppure errato");
		}

	}
	else{
		printf("Non e' stato possibile aprire il file consumi.txt il programma terminera' ora!");
	}
	getchar();



	return (0);
}
