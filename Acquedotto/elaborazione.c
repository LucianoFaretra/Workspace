/**
INPUT				DESCRIZIONE											DOMINIO
dati_letti			Struttura contenente le informazioni di la casa		Non vuota
Tariffari/Quote		Vedi dati globali, tariffari che compongono il prezzo dei servizi	Float
numero_case			Numero case che compongono il nucleo abitativo		intero > 0

OUTPUT				DESCRIZIONE											DOMINIO
importo				Importo unita abitativa								float >= 0


(pseudocodifica)

imposta importo a -1
Se dati_letti e' NULL
	Allora
		Stampa messaggio d'errore
	Altrimenti
		Se consumo unita' e' maggiore di AGEVOLATA e minore di BASE
			Allora
				importo += dati_letti.consumi * TARIFFA_AGEVOLATA
			Altrimenti Se consumo unita' e' maggiore di BASE e minore di FASCIA_1
				Allora
					importo += dati_letti.consumi * TARIFFA_BASE
			Altrimenti Se consumo unita' e' maggiore di FASCIA_1 e minore di FASCIA_2
				Allora
					importo += dati_letti.consumi * TARIFFA_FASCIA_1
			Altrimenti Se consumo unita' e' maggiore di FASCIA_2 e minore di FASCIA_3
				Allora
					importo += dati_letti.consumi * TARIFFA_FASCIA_2
			Altrimenti Se consumo unita' e' maggiore di FASCIA_3
				Allora
					importo += dati_letti.consumi * TARIFFA_FASCIA_3
		Fine se

		importo += QUOTA_FISSA_UNITA
		importo += dati_letti.consumi * FOGNA
		importo += dati_letti.consumi * DEPURAZIONE
		importo += (QUOTA_MODULO / numero_case )
Fine Se
Ritorna importo

TEST 1

dati_letti = non vuoto
numero_case = <= LIMITE_MEMORIA_UNITA_ABITATIVE

Output a video

L'importo totale della n' 5 unita abitative e' pari a: € 1011.93

TEST 2

dati_letti = non vuoto
numero_case = > LIMITE_MEMORIA_UNITA_ABITATIVE

Output a video

Impossibile continuare, limite memoria per unità abitative superato


*/
#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "elaborazione.h"

float calcolo_unita(abitazione dati_letti, unsigned int numero_case)
{
	float importo = -1;

		if(dati_letti.consumi >= AGEVOLATA && dati_letti.consumi < BASE){
			importo += dati_letti.consumi * TARIFFA_AGEVOLATA;
		}
		else if( dati_letti.consumi >= BASE && dati_letti.consumi < FASCIA_1 ){
				importo += dati_letti.consumi * TARIFFA_BASE;
		}
		else if(dati_letti.consumi >= FASCIA_1 && dati_letti.consumi < FASCIA_2){
				importo += dati_letti.consumi * TARIFFA_FASCIA_1;
		}
		else if(dati_letti.consumi >= FASCIA_2 && dati_letti.consumi < FASCIA_3){
				importo += dati_letti.consumi * TARIFFA_FASCIA_2;
		}
		else if(dati_letti.consumi >= FASCIA_3){
				importo += dati_letti.consumi * TARIFFA_FASCIA_3;
		}

		importo += QUOTA_FISSA_UNITA;
		importo += (dati_letti.consumi * FOGNA);
		importo += (dati_letti.consumi * DEPURAZIONE);
		importo += (QUOTA_MODULO / numero_case );

	return (importo);
}
