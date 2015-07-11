/** \file elaborazione.c
 * \brief A Documented file.
 * File contenente gli headers dell'accesso ai dati.
 * \section License
 * Rilasciato sotto licenza GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 04.2015
 */

#ifndef ACCESSO_DATI_H_
#define ACCESSO_DATI_H_
#include "dati_globali.h"

int lettura(int matrice[][MAX_COLONNE], size_t indice_righe, size_t indice_colonne);
void scrittura(int world[][MAX_COLONNE], size_t indice_righe, size_t indice_colonne, int valore);
void copia_dati(int matrice_destinazione[][MAX_COLONNE], int matrice_origine[][MAX_COLONNE]);

#endif /* ACCESSO_DATI_H_ */
