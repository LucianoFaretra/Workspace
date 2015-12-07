#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "accesso_dati.h"
#include "output.h"

void stampa_quaterne(int quaterna[])
{
	size_t indice_quaterna;

	indice_quaterna = 0;
	puts("");
	printf("{ ");
	while(indice_quaterna < QUATERNA){
		printf("%d ", quaterna[indice_quaterna]);
		indice_quaterna++;
	}
	printf("}\n");

	return;
}

void stampa(dati_matrice matrice)
{
	size_t indice_riga;
	size_t indice_colonna;

	indice_riga = 0;
	while(indice_riga < matrice.numero_righe){
		indice_colonna = 0;
		while(indice_colonna < matrice.numero_colonne){
			printf("%d ", matrice.matrice[indice_riga][indice_colonna]);//lettura_matrice_doppia(matrice, indice_riga, indice_colonna));
			indice_colonna++;
		}
	puts("");
	indice_riga++;
	}
	return;
}

void messaggi(int messaggio)
{
	if( messaggio == INSERIRE_RIGA ){
		puts("");
		puts("Prego insierire il numero righe che compongono la matrice:");
		printf(":>");
	}
	else if( messaggio == INSERIRE_COLONNA ){
			puts("");
			puts("Prego insierire il numero colonne che compongono la matrice:");
			printf(":>");
		}
	else if( messaggio == INPUT_ERRATO ){
		puts("Attenzione, e' stato inserito un input non valido, riprovare");
	}
	else if( messaggio == IMPOSSIBILE_ALLOCARE ){
		puts("Attenzione non e' stato possibile allocare la matrice\n"
				"Il programma terminera' in modo inaspettato");
	}
	else if( messaggio == MESSAGGIO_QUATERNA ){
		puts("Ecco le quaterne trovate:");
	}
	else if( messaggio == NESSUNA_QUATERNA ){
		puts("Purtroppo non e' stata trovata nessuna quaterna valida");
	}

	return;
}

