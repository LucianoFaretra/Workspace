#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "elaborazione.h"
#include "input_output.h"

int main(void)
{
	FILE* dati;
	float importo_totale;

	dati = fopen("consumi.txt", "r");
	if(dati == NULL){
		puts("Attenzione non e' stato possibile aprire il file consumi.txt il programma terminera in modo inatteso");
	}
	else{
		importo_totale = calcolo_unita(dati);
		fclose(dati);
		if(importo_totale < 0){
			puts("Attenzione c'è stato un errore nel calcolo degli importi");
		}
		else{
			stampa_totale(importo_totale);
		}
	}
	return (0);
}
