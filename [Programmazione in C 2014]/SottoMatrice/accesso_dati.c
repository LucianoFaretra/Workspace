/** \file accesso_dati.c
 * \brief Modulo di accesso ai dati
 * \section License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "dati_globali.h"

/** \fn int lettura_matrice(int **matrice, int riga, int colonna)
 * 	Funzione di accesso ad dati, riceve delle coordinate e restituisce il valore
 * \param **matrice matrice su cui cercare i dati
 * \param riga coordinata X
 * \param colonna coordinata Y
 * \return il valore contenenuto nella matrice in posizione X, Y
 */

int lettura_matrice(int **matrice, int riga, int colonna)
{
	return (matrice[riga][colonna]);
}

/** \fn void scrittura_matrice(int **matrice, int riga, int colonna, int valore)
 * 	Funzione di accesso ad dati, riceve un valore e lo scrive nella matrice alle coordinate X Y
 * \param **matrice matrice su cui scrivere i dati
 * \param riga coordinata X
 * \param colonna coordinata Y
 * \param valore valore da scrivere nella matrice
 */

void scrittura_matrice(int **matrice, int riga, int colonna, int valore)
{
	matrice[riga][colonna] = valore;
	return;
}
