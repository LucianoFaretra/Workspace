#include <stdlib.h>
#include <stdio.h>
#include "datiGlobali.h"

int lettura_intero(void)
{
	int intero;
	int esitoScanf;

	do{
		esitoScanf = scanf("%u", &intero);
		if(esitoScanf == 0){
			scanf("%*[^\n]");
			puts("Attenzione inserire un intero!");
		}
	}while(esitoScanf == 0);

	return (intero);
}

void inserimento_data(int *giorno, int *mese, int *anno)
{
	puts("Prego inserire la data");

	puts("Inserire il giorno");
	printf("->: ");
	*giorno = lettura_intero();
	puts("Inserire il mese");
	printf("->: ");
	*mese  = lettura_intero();
	puts("Inserire l'anno");
	printf("->: ");
	*anno  = lettura_intero();

	return;
}

void stampa_giorni(int data){

	if(data > 0){
		printf("\nEcco i giorni trascorsi: %u", data);
	}
	else if(data == 0){
		puts("ERRORE: l'anno inserito non e' bisestile, data inesistente");
	}
	else if(data == -1){
		puts("ERRORE: e' stata inserito un giorno inesistente");
	}
	else if(data == -2){
		puts("ERRORE: e' stata inserito un mese inesistente");
	}
	else if(data == -3){
		puts("ERRORE: e' stata inserito un anno negativo (operazione non supportata)");
	}
}
