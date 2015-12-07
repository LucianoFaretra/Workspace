/** \file elaborazione.h
 * \brief A Documented file.
 * File contenente gli headers del file accesso_dati.
 * \section License
 * Rilasciato sotto licenza GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 04.2015
 */

#ifndef ELABORAZIONE_H_
#define ELABORAZIONE_H_

void int_world(int init_value);
void play_life(void);
int caselle_adiacenti_positive(size_t indice_righe, size_t indice_colonne);
int nuovo_stato(size_t indice_righe, size_t indice_colonne);
void campo_pre_partita(void);
void copia_dati(int matrice_destinazione[][MAX_COLONNE], int matrice_origine[][MAX_COLONNE]);

#endif /* ELABORAZIONE_H_ */
