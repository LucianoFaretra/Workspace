

#include <stdlib.h>
#include <stdio.h>
#include "datiGlobali.h"
#include "inputOutput.h"

int main(void)
{
	int scelta;
	FILE* alfa;
	char partenza[20] = {""};
	float minimo;
	float massimo;

	alfa = fopen("ElencoTreni.txt", "r");
	if(alfa == NULL){
		puts("Attenzione non e' stato possibile aprire il file ElencoTreni.txt");
	}
	else{
		do{
			puts("Effettua la tua scelta!");
			puts("0 - Visualizza il contenuto del File ElencoTreni.txt;");
			puts("1 - Visualizza i treni che partono da una città inserita da tastiera dall'utente;");
			puts("2 - Visualizza i treni che hanno un prezzo compreso nell'intervallo inserito");
			puts("3 - Esci");

			scelta = leggiIntero();
			if(scelta < 0 || scelta > 3){
				puts("Attenzione e' stato inserito un valore non valido, ripetere l'inserimento!");
			}
			else if(scelta == 0){
				visualizza(alfa);
			}
			else if(scelta == 1){
				printf("Prego inserire il nome della citta di partenza: ");
	            scanf("%20s", partenza);
				mostraPartenze(alfa, partenza);
			}
			else if(scelta == 2){
				printf("Prego inserire il prezzo minimo \n ->: ");
				scanf("%f", &minimo);
				printf("\nPrego inserire il prezzo massimo \n ->: ");
				scanf("%f", &massimo);
				mostraPrezzo(alfa, minimo, massimo);
			}
			else if(scelta == 3){
				puts("Grazie e arrivederci");
			}

		}while(scelta < 0 || scelta > 3);
	}

	return (0);
}

