#include <stdlib.h>
#include <stdio.h>
#include "datiGlobali.h"
#include "inputOutput.h"
#include "string.h"

void mostra(Treni treno1)
{
	printf("%5s %20s %5s %20s %5s %.2f", treno1.codTreno, treno1.CittaPartenza, treno1.OraPartenza, treno1.CittaArrivo, treno1.OraArrivo, treno1.prezzo);

	return;
}

void visualizza(FILE* alfa)
{
	Treni treno;

	while(!feof(alfa)){
		fscanf(alfa, "%5s %20s %5s %20s %5s %f", treno.codTreno, treno.CittaPartenza, treno.OraPartenza, treno.CittaArrivo, treno.OraArrivo, &treno.prezzo);
		mostra(treno);
	}

	return;
}

int leggiIntero(void)
{
	int interoLetto;
	int esitoScanf;

	do{
		esitoScanf = scanf("%d", &interoLetto);
		if(esitoScanf == 0){
			scanf("%*[^\n]");
			puts("Attenzione non e' stato inserito un intero");
		}
	}while(esitoScanf == 0);

	return (interoLetto);
}

/*
INPUT				DESCRIZIONE											Dominio
alfa				Puntatore a file contenente la lista dei treni 		File contenente stringhe di caratteri
partenza[]			Stringa contenente il paese da cercare				Stringa di caratteri

OUTPUT				DESCRIZIONE											DOMINIO
(a video)
treno				Struttura contenente i dati del treno cercato		Struttura dati
nonTrovato			Messaggio treno non trovato							stringa di caratteri

DATI				DESCRIZIONE
esito				Esito della ricerca									0 successo, 1 Fallita

(pseudo codifica)

Impostare esito a 1
Se non e' possibile aprire il file
	Allora far comparire un messaggio d'errore
	Altrimenti Apri il file
		Mentre il file non e' finito
			cerca la stringa partenza[] tra le partenze
				Se la stringa corrisponde
					Allora stampa i dati del treno
					impostare esito a 0
				Altrimenti
					Passa alla stringa successiva
		Fine Mentre
		Se esito equivale 1
			Allora
				Stampa messaggio nonTrovato
		Fine Se
Fine Se

CASI DI TEST:

Test1:

Input
File ElencoTreni.txt non esistente
partenza == Bari

Output
Attenzione il puntatore a file e' nullo

Test2:
File ElencoTreni.txt corrotto
partenza == Roma

Output
Esito imprevedibile

Test2:
File ElencoTreni.txt presente come specifica
partenza == Bari

Output
IC714 Bari 05:07 Bologna 12:31 100

*/

void mostraPartenze(FILE *alfa, char partenza[])
{
	Treni treno;
	int esito = 1;
	char *nonTrovato = "Attenzione, partenza non trovata";

	if(alfa == NULL){
		puts("Attenzione il puntatore a file e' nullo");
	}
	else{
		while(!feof(alfa)){
			fscanf(alfa, "%5s %20s %5s %20s %5s %f", treno.codTreno, treno.CittaPartenza, treno.OraPartenza, treno.CittaArrivo, treno.OraArrivo, &treno.prezzo);
			if(strcmp(partenza, treno.CittaPartenza) == 0){
				mostra(treno);
				esito = 0;
			}
			if(esito == 1){
				printf("%s", nonTrovato);
			}
		}
	}
	return;
}


/*
INPUT				DESCRIZIONE											Dominio
alfa				Puntatore a file contenente la lista dei treni 		File contenente stringhe di caratteri
minimo				Prezzo minimo da cercare							Float
massimo				Prezzo massimo da cercare							Float

OUTPUT				DESCRIZIONE											DOMINIO
(a video)
treno				Struttura contenente i dati del treno cercato		Struttura dati
nonTrovato			Messaggio treno non trovato							stringa di caratteri

DATI				DESCRIZIONE
esito				Esito della ricerca									0 successo, 1 Fallita

(pseudo codifica)

Impostare esito a 1
Se non e' possibile aprire il file
	Allora far comparire un messaggio d'errore
	Altrimenti Apri il file
		Mentre il file non e' finito
			se prezzo e' >= di prezzo minomo e <= di prezzo massimo
					Allora stampa i dati del treno
					impostare esito a 0
				Altrimenti
					Passa alla stringa successiva
		Fine Mentre
		Se esito equivale 1
			Allora
				Stampa messaggio nonTrovato
		Fine Se
Fine Se

CASI DI TEST:

Test1:

Input
File ElencoTreni.txt non esistente
minimo == 50
massimo == 10

Output
Attenzione il puntatore a file e' nullo

Test2:
File ElencoTreni.txt corrotto
minimo == 0
massimo == 0

Output
Esito Imprevedibile

Test2:
File ElencoTreni.txt presente come specifica
minimo == 0
massimo == 200

Output
IC714 Bari 05:07 Bologna 12:31 100

Test3:
File ElencoTreni.txt presente come specifica
minimo == 0
massimo == 90

Output
Attenzione, i criteri non hanno prodotto alcun risultato

*/

void mostraPrezzo(FILE *alfa, float minimo, float massimo)
{
	Treni treno;
	int esito = 1;
	char *nonTrovato = "Attenzione, i criteri non hanno prodotto alcun risultato";

	if(alfa == NULL){
		puts("Attenzione il puntatore a file e' nullo");
	}
	else{
		while(!feof(alfa)){
			fscanf(alfa, "%5s %20s %5s %20s %5s %f", treno.codTreno, treno.CittaPartenza, treno.OraPartenza, treno.CittaArrivo, treno.OraArrivo, &treno.prezzo);
			if(treno.prezzo >= minimo && treno.prezzo <= massimo){
				mostra(treno);
				esito = 0;
			}
			if(esito == 1){
				printf("%s", nonTrovato);
			}
		}
	}
	return;
}
