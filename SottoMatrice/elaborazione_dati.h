/** \file elaborazione_dati.h
 * \brief File contenente tutti gli headers delle funzioni di manipolazione dati
 * \section License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */

#ifndef ELABORAZIONE_DATI_H_
#define ELABORAZIONE_DATI_H_

int** alloca_matrice(int numero_righe, int numero_colonne);
int controllo_matrice_nulla(int **matrice);
void composizione_matrice(int **matrice, int numero_righe, int numero_colonne);
int genera_numero_random(void);
int somma_sub_matrice(int **matrice, int numero_righe, int numero_colonne, int coordinata_righe, int coordinata_colonne);
dati_submatrice trova_submatrice_maggiore(int **matrice, int numero_righe, int numero_colonne);

#endif /* ELABORAZIONE_DATI_H_ */
