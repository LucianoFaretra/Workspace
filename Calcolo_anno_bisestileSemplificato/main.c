#include <stdlib.h>
#include <stdio.h>
#include "datiGlobali.h"
#include "inputOutput.h"
#include "elaborazione.h"

int main(void)
{
	int scelta;
	int giorno;
	int mese;
	int anno;
	int giorni;

	do{
		printf("\nVuoi inserire una data?\n -:1 - Per continuare\n -:0 - Per uscire \n->: ");
		scelta = lettura_intero();
		if(scelta == 0){
			puts("Grazie e arrivederci");
		}
		else if(scelta == 1){
			inserimento_data(&giorno, &mese, &anno);
			giorni = giorni_trascorsi(giorno, mese, anno);
			stampa_giorni(giorni);
		}
		else{
			puts("Attenzione, e' stato inserito un valore non valido");
		}
	}while(scelta != 0);

	return (0);
}


