#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dati_globali.h"
#include "elaborazione.h"

void FibonacciSearcher(string str[])
{

	unsigned int indice_array;
	unsigned int posizione_fibonacci;

	indice_array = 0;
	do{
		if(str == NULL){
			puts("Attenzione stringa nulla");
			indice_array = MAX_STRINGHE;
		}
		else{
			if(0 == strlen(stringhe[indice_array])){
				puts("Attenzione stringa vuota");
				indice_array = MAX_STRINGHE;
			}
			else{
				if(0 < strcmp(stringhe[indice_array], stringhe[indice_array + 1])){
					puts("Attenzione le stringhe non sono in ordine lessicografico");
					indice_array = MAX_STRINGHE;
				}
				else{
					strcpy(str[indice_array], stringhe[indice_array]);
				}
			}
		}
	}while(indice_array < MAX_STRINGHE);

	posizione_fibonacci = 1;

	while(posizione_fibonacci <= MAX_NUMERI){
		fibonacci[posizione_fibonacci] = calcolo_fibonacci(posizione_fibonacci);
		posizione_fibonacci++;
	}

	return;
}


unsigned int calcolo_fibonacci(int posizione_fibonacci)
{
	unsigned int numero_successivo_fibonacci;
	unsigned int contatore_fibonacci;
	unsigned int primo_numero_fibonacci = 0;
	unsigned int secondo_numero_fibonacci = 1;

	contatore_fibonacci = 0;
	while(posizione_fibonacci > contatore_fibonacci){

		if(contatore_fibonacci <= 1){
			numero_successivo_fibonacci = contatore_fibonacci;
		}
		else{
			numero_successivo_fibonacci = (primo_numero_fibonacci + secondo_numero_fibonacci);
			primo_numero_fibonacci = secondo_numero_fibonacci;
			secondo_numero_fibonacci = numero_successivo_fibonacci;
		}
		contatore_fibonacci++;
	}

	return numero_successivo_fibonacci;
}


int lookFor(string key)
{
	unsigned int n = MAX_STRINGHE;
	unsigned int m = 0;
	unsigned int k;
	unsigned int base = 0;
	unsigned int posizione;
	unsigned int esito;
	string s;

	while(fibonacci[m] <= n){
		m++;
	}

	k = m;

	while(k > 0){
		posizione = (base + fibonacci[--k] );
		strcpy(s, stringhe[posizione]);
		if( 0 == strcmp(s, key)){
			esito = posizione;
			k = 0;
		}
		else if(0 < strcmp(key, s) ){
			k--;
		}
	    else if (0 > strcmp(key, s)){
	    	base = posizione;
	        k = ( k - 2);
	    }
	}
    return esito;
}
