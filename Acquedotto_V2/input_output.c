#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "input_output.h"
#include "elaborazione.h"

float lettura_file(FILE* dati)
{
	float consumi;
	int indice_array;

	if(dati == NULL){
		puts("Attenzione puntatore a file nullo!");
	}
	else{
		fscanf(dati, "%f", &consumi);
	}
	return (consumi);
}

void stampa_totale(float importo_totale)
{
	if(importo_totale < 0){
		puts("Errore nel calcolo degli importi, il programma terminera in modo inatteso");
	}
	else{
		printf("L'importo totale della unita abitative e' pari a: € %.2f", importo_totale);

	}
	return;
}
