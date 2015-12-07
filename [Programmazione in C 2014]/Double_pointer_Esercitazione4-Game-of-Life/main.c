/** \file main.c
 * \brief A Documented file.
 * File contenente le istruzioni per eseguire il ciclo del programma.
 * \section License
 * Rilasciato sotto licenza GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 04.2015
 */

#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "output.h"
#include "elaborazione.h"
#include "input.h"

int main(void)
{
	unsigned int numero_iterazioni = 0;
	unsigned int indice_iterazioni = 1;

	printf("Per cortesia inserire il numero di iterazioni da effettuare: \n >: ");
	lettura_numero(&numero_iterazioni);
	int_world(INIZIALIZZATORE);
	campo_pre_partita();
	puts("Stampa campo iniziale:");
	display_world();
	while(indice_iterazioni <= numero_iterazioni){
		printf("Calcolo iterazione numero %u\n", indice_iterazioni);
		play_life();
		copia_dati(world, world_temp);
		display_world();
		indice_iterazioni++;
	}

	return (EXIT_SUCCESS);
}
