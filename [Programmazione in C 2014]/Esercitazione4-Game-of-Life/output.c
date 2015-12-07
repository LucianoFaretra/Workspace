/** \file output.c
 * \brief A Documented file.
 * File contenente le istruzioni per stampare dati a video.
 * \section License
 * Rilasciato sotto licenza GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 04.2015
 */


#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "accesso_dati.h"

/** \fn void display_world(void)
 * Funzione di stampa della matrice
 * \param void la funzione non riceve nulla
 */
void display_world(void)
{
	size_t indice_colonne;
	size_t indice_righe;

	indice_righe = 0;
	while(MAX_RIGHE > indice_righe){
		indice_colonne = 0;
		while( MAX_COLONNE > indice_colonne){
				if(lettura(world, indice_righe, indice_colonne) == 1){
					printf("%c", '*');
				}
				else{
					printf("%c", 'o');
				}
		indice_colonne++;
		}
		puts("");
		indice_righe++;
	}
	return;
}
