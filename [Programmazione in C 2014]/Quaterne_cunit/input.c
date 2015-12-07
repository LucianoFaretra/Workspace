#include <stdio.h>
#include <stdlib.h>
#include "dati_globali.h"
#include "output.h"

unsigned int leggi_intero(void)
{
	unsigned int numero_letto;
	int esito_scanf;

	do{
		esito_scanf = scanf("%u", &numero_letto);
		if(esito_scanf == 0){
			scanf("%*[^\n]");
			messaggi(INPUT_ERRATO);
		}
	}while(esito_scanf == 0);

	return (numero_letto);
}
