/*
 * input_output.c
 *
 *  Created on: 31 ago 2015
 *      Author: ibanez89
 */

#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "input_output.h"
#include "elaborazione.h"

unsigned int lettura_dati(FILE *file_dati, float consumi_unita[])
{
	unsigned int numero_unita;
	unsigned int numero_unita_lette;
	char buffer[8];

	fscanf(file_dati, "%7s %u", buffer, &numero_unita );
	numero_unita_lette = 0;
	while(!feof(file_dati) && numero_unita < MAX_NUM_UNITA){
		fscanf(file_dati, "%8s %f", buffer, &consumi_unita[numero_unita_lette]);
		numero_unita_lette++;
	}
	if(numero_unita_lette != (numero_unita+1)){
		return (0);
	}

	return (numero_unita);
}

void totale_unita_abitative(float consumi_unita[], unsigned int numero_unita)
{
	unsigned int unita = 1;
	float importo_totale = 0;

	while(unita <= numero_unita){
		importo_totale += calcolo(consumi_unita, numero_unita, unita);
		unita++;
	}
	printf("L'importo totale annuale da pagare del modulo abitativo e' ->: %f", importo_totale);



	return;
}
