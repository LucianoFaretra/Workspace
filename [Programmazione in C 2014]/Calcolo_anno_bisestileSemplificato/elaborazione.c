#include <stdlib.h>
#include <stdio.h>
#include "datiGlobali.h"
#include "elaborazione.h"


int giorni_trascorsi(int giorno, int mese, int anno)
{
	int giorni_bisestile[MESI] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int giorni_non_bisestile[MESI] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int esito;

	esito = giorno_non_valido(giorno);
	if(esito != -1){
		esito = mese_non_valido(mese);
		if(esito != -2){
			esito = anno_non_valido(anno);
			if(esito != -3){
				esito = date_inesistenti(giorno, mese, anno);
				if(esito != -4){
					esito = anno_bisestile(giorno, mese, anno);
					if(esito == 1){
						esito = conta_giorni(giorno, mese, anno, giorni_non_bisestile);
					}
					else if(esito == 2){
						esito = conta_giorni(giorno, mese, anno, giorni_bisestile);
					}
				}

			}
		}
	}
	return (esito);
}

int giorno_non_valido(int giorno)
{
	int esito;

	esito = giorno;
	if((giorno < 1) || (giorno > 31) ){
		esito = -1;
	}

	return (esito);
}

int mese_non_valido(int mese)
{
	int esito;

	esito = mese;
	if((mese < 1) || (mese > 12) ){
		esito = -2;
	}

	return (esito);
}

int anno_non_valido(int anno)
{
	int esito;

	esito = anno;
	if(anno < 0){
		esito = -3;
	}

	return (esito);
}

int date_inesistenti(int giorno, int mese, int anno)
{
	int esito;

	if( (giorno == 30 && mese == 2) ||
		(giorno == 31 && (mese == 2 ||
						  mese == 4 ||
						  mese == 6 ||
						  mese == 9 ||
						  mese == 11)) ){
		esito = -4;
	}
	else{
		esito = 0;
	}

	return (esito);
}

int anno_bisestile(int giorno, int mese, int anno)
{
	int esito;

	if((anno%4) != 0){
		esito = 1;
		if( (giorno == 29) && ( mese == 2 ) ){
			esito = 0;
		}
	}
	else{
		esito = 2;
	}

	return (esito);
}

int conta_giorni(int giorno, int mese, int anno, int calendario[])
{
	int giorni;
	unsigned int indice_array;

	giorni = 0;
	indice_array = 0;
	while( indice_array < MESI ){
		if( indice_array < (mese - 1) ){
			giorni += calendario[indice_array];
		}
		else if(indice_array == (mese - 1)){
			giorni += giorno;
		}
		indice_array++;
	}

	return (giorni);
}
