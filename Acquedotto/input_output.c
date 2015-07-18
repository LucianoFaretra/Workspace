#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "input_output.h"
#include "elaborazione.h"

unsigned int lettura_file(FILE* dati, abitazione dati_letti[])
{
	unsigned int numero_case;
	int indice_array;

	if(dati == NULL){
		puts("Attenzione puntatore a file nullo!");
	}
	else{
		fscanf(dati, "%d", &numero_case);
		if(numero_case <= LIMITE_MEMORIA_UNITA_ABITATIVE){
			indice_array = 0;
			while(!feof(dati) && indice_array < numero_case){
				fscanf(dati, "%u %f", &dati_letti[indice_array].id, &dati_letti[indice_array].consumi);
				indice_array++;
			}
		}
		else{
			puts("Impossibile continuare, limite memoria per unità abitative superato");
		}
	}

	return (numero_case);
}

void stampa_totale(abitazione dati_letti[], unsigned int numero_case)
{
	float importo_totale = 0;
	int indice_array;

	indice_array = 0;
	while(indice_array < numero_case){
		importo_totale += calcolo_unita(dati_letti[indice_array], numero_case);
		indice_array++;
	}
	if(importo_totale < 0){
		puts("Errore nel calcolo degli importi, il programma terminera in modo inatteso");
	}
	else{
		printf("L'importo totale della n' %u unita abitative e' pari a: € %.2f", numero_case, importo_totale);

	}
	return;
}
