/** \file elaborazione.c
 * \brief A Documented file.
 * File contenente le istruzioni per acquisire dati dallo standard input.
 * \section License
 * Rilasciato sotto licenza GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 04.2015
 */

#include <stdio.h>
#include <stdlib.h>

/** \fn void play_life(void)
 * Funzione che effettua il ciclo di iterazione
 * \param void la funzione non riceve nulla
 */
void lettura_numero(int *numeroPtr)
{
	scanf("%u", numeroPtr);

	return;
}
