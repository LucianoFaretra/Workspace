/**
INPUT				DESCRIZIONE											DOMINIO
dati				puntatore a file consumi.txt						Non nullo
Tariffari/Quote		Vedi dati globali, tariffari che compongono il prezzo dei servizi	Float
consumi				Consumi unita abitativa letto da file				float >= 0

OUTPUT				DESCRIZIONE											DOMINIO
importo				Importo totale modulo								float >= 0


(pseudocodifica)

Se dati e' nullo
	Allora
		Stampa messaggio d'errore
		riotrna come importo -1
	Altrimenti
		mentre il file non e' ancora finito
			assegna a consumi i consumi di un'unita abitativa

			se consumi >= AGEVOLATA e consumi < BASE
				Allora
					aggiungi ad importo (consumi * TARIFFA_AGEVOLATA)

			Altrimenti Se consumi >= BASE e consumi < FASCIA_1
				Allora
					aggiungi ad importo (consumi * TARIFFA_BASE)

			Altrimenti Se consumi >= FASCIA_1 e consumi < FASCIA_2
				Allora
					Aggiungi aggiungi ad importo (consumi * TARIFFA_FASCIA_1)

			Altrimenti Se consumi >= FASCIA_2 e consumi < FASCIA_3
				Allora
					Aggiungi aggiungi ad importo (consumi * TARIFFA_FASCIA_2)

			Altrimenti Se consumi >= FASCIA_3
				Allora
					Aggiungi aggiungi ad importo (consumi * TARIFFA_FASCIA_3)

			Fine Se

			Aggiungi ad importo QUOTA_FISSA_UNITA
			Aggiungi ad importo (consumi * FOGNA)
			Aggiungi ad importo (consumi * DEPURAZIONE)
		Fine Mentere
	Aggiungi ad importo QUOTA_MODULO
Fine Se
Ritorna importo

TEST 1

dati = nullo
consumi = 20

Output a video

Stampa messaggio d'errore

TEST 2

dati = non nullo
consumi = 0

Output a video

L'importo totale della unita abitative e' pari a: € 0

TEST 3

dati = non nullo
consumi = 20

Output a video

L'importo totale della unita abitative e' pari a: € 43.35

*/
#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "elaborazione.h"
#include "input_output.h"

float calcolo_unita(FILE* dati)
{
	float importo;
	float consumi;

	if(dati == NULL){
		puts("Errore");
		importo = -1;
	}
	else{
		importo = 0;
		while(!feof(dati)){

			consumi = lettura_file(dati);

			if(consumi >= AGEVOLATA && consumi < BASE){
				importo += consumi * TARIFFA_AGEVOLATA;
			}
			else if( consumi >= BASE && consumi < FASCIA_1 ){
					importo += consumi * TARIFFA_BASE;
			}
			else if(consumi >= FASCIA_1 && consumi < FASCIA_2){
					importo += consumi * TARIFFA_FASCIA_1;
			}
			else if(consumi >= FASCIA_2 && consumi < FASCIA_3){
					importo += consumi * TARIFFA_FASCIA_2;
			}
			else if(consumi >= FASCIA_3){
					importo += consumi * TARIFFA_FASCIA_3;
			}

			importo += QUOTA_FISSA_UNITA;
			importo += (consumi * FOGNA);
			importo += (consumi * DEPURAZIONE);
		}
	}
		importo += (QUOTA_MODULO);

	return (importo);
}
