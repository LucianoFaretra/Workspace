#include <stdio.h>
#include <stdlib.h>
#include "dati_globali.h"

int lettura_matrice_doppia(int **matrice, unsigned int numero_riga, unsigned int numero_colonna)
{
	return (matrice[numero_riga][numero_colonna]);
}

void scrittura_matrice_doppia(int **matrice, unsigned int numero_riga, unsigned int numero_colonna, int valore)
{
	matrice[numero_riga][numero_colonna] = valore;

	return;
}

int lettura_matrice(int matrice[], unsigned int numero_posizione)
{
	return (matrice[numero_posizione]);
}

void scrittura_matrice(int *matrice, unsigned int numero_posizione, int valore)
{
	matrice[numero_posizione] = valore;

	return;
}
