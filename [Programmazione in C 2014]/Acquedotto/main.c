#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "elaborazione.h"
#include "input_output.h"

int main(void)
{
	FILE* dati;
	abitazione dati_letti[LIMITE_MEMORIA_UNITA_ABITATIVE];
	unsigned int numero_case;

	dati = fopen("consumi.txt", "r");
	if(dati == NULL){
		puts("Attenzione non e' stato possibile aprire il file consumi.txt il programma terminera in modo inatteso");
	}
	else{
		numero_case = lettura_file(dati, dati_letti);
		if(numero_case <= LIMITE_MEMORIA_UNITA_ABITATIVE){
			stampa_totale(dati_letti, numero_case);
		}
	}
	return (0);
}
