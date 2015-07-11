#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dati_globali.h"
#include "output.h"
#include "elaborazione.h"
#include "input.h"

int main(void)
{
	dati_matrice matrice1;
	int quaterna[QUATERNA] = {0};

	srand(time(NULL));

	messaggi(INSERIRE_RIGA);
	matrice1.numero_righe = leggi_intero();

	messaggi(INSERIRE_COLONNA);
	matrice1.numero_colonne = leggi_intero();

	alloca_matrice(&matrice1);
	if(controllo_matrice(matrice1.matrice) != 0){
		riempi_matrice(&matrice1);

		stampa(matrice1);
		if(genera_quaterna(matrice1, quaterna) == 0){
			messaggi(NESSUNA_QUATERNA);
		}
	}
	return (0);
}
