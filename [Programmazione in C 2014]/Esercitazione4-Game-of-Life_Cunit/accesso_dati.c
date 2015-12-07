/** \file accesso_dati.c
 * \brief A Documented file.
 * File contenente le istruzioni per eseguire l'accesso sui dati.
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

/** \fn int lettura(int matrice[][MAX_COLONNE], size_t indice_righe, size_t indice_colonne)
 * Funzione di lettura dati dalla stringa, riceve le coordinate e ne restituisce il dato letto in quelle coordinate
 * \param matrice[][[MAX_COLONNE] array da scrivere
 * \param indice_righe indice contenenete il numero di riga da controllare
 * \param indice_colonne indice contenente il numero di colonna da controllare
 * \return il numero letto dalla funzione nelle coordinate specificate.
 */
int lettura(int matrice[][MAX_COLONNE], size_t indice_righe, size_t indice_colonne)
{
	int dato_letto;

	dato_letto = matrice[indice_righe][indice_colonne];

	return (dato_letto);
}

/** \fn void scrittura(int matrice[][MAX_COLONNE], size_t indice_righe, size_t indice_colonne, int valore)
 * Funzione di scrittura dati nella stringa, riceve le coordinate e il dato da scrivere
 * \param matrice[][[MAX_COLONNE] array da scrivere
 * \param indice_righe indice contenenete il numero di riga da controllare
 * \param indice_colonne indice contenente il numero di colonna da controllare
 * \param valore valore da scrivere nell'array
 * \return il numero letto dalla funzione nelle coordinate specificate.
 */
void scrittura(int matrice[][MAX_COLONNE], size_t indice_righe, size_t indice_colonne, int valore)
{
		world[indice_righe][indice_colonne] = valore;

	return;
}

/** \fn void copia_dati(int matrice_destinazione[][MAX_COLONNE], matrice_origine[][MAX_COLONNE])
 * La funzione copia i dati dei due vettori
 * \param matrice_destinazione[][[MAX_COLONNE] array in cui incollare i dati
 * \param matrice_origine[][[MAX_COLONNE] array da cui prelevare i dati da copiate
 */
void copia_dati(int matrice_destinazione[][MAX_COLONNE], int matrice_origine[][MAX_COLONNE])
{
	size_t indice_righe;
	size_t indice_colonne;

	indice_righe = 0;
	do{
		indice_colonne = 0;
		do{
			scrittura(matrice_destinazione, indice_righe, indice_colonne, lettura(matrice_origine, indice_righe, indice_colonne));
		indice_colonne++;
		}while(MAX_COLONNE > indice_colonne);
	indice_righe++;
	}while(MAX_RIGHE > indice_righe);

	return;
}
