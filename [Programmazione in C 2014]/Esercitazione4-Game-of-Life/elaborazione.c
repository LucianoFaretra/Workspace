/** \file elaborazione.c
 * \brief A Documented file.
 * File contenente le istruzioni per eseguire calcoli sui dati.
 * \section License
 * Rilasciato sotto licenza GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 04.2015
 */

/**
* INPUT							DESCRIZIONE												DOMINIO
* init_value						Valore ricevuto per inizializzare l'array				intero
* world[MAX_RIGHE][MAX_COLONNE]	Vettore contenente il campo da gioco da inizializzare	intero 0 o 1
*
* OUTPUT							DESCRIZIONE												DOMINIO
* world[MAX_RIGHE][MAX_COLONNE]	Vettore contenente il campo da gioco inizializzato		intero 0 o 1
*
* DATI LAVORO						DESCRIZIONE												DOMINIO
* indice_colonne					Indice colonne dell'array								intero senza segno >= 0
* indice_righe					Indice delle righe										intero senza segno >= 0
*
* Se world è nullo
*	Allora
*		Stampa messaggio d'errore
*	Altrimenti
*		Azzera indice_righe a zero
*		Mentre ci sono ancora righe da inizializzare
*			Azzera indice_colonne a zero
*			Mentre ci sono ancora colonne da inizializzare
*				assegna a world[indice_righe][indice_colonne] il valore di init_value
*				incrementa indice_colonne di uno
*			Fine Mentre
*			Incrementa indice_righe a zero
*		Fine mentre
* Fine Se
*/

#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "accesso_dati.h"
#include "elaborazione.h"
#include "time.h"

/** \fn void int_world(int init_value)
 * Funzione di inizializzazione del campo da gioco
 * \param init_value valore da utilizzare per inizializzare il campo
 */
void int_world(int init_value)
{
	size_t indice_colonne;
	size_t indice_righe;

	indice_righe = 0;
	while(MAX_RIGHE > indice_righe){
		indice_colonne = 0;
		while( MAX_COLONNE > indice_colonne){
			scrittura(world_temp, indice_righe, indice_colonne, init_value);
			indice_colonne++;
		}
		indice_righe++;
	}
	return;
}

/** \fn void play_life(void)
 * Funzione che effettua il ciclo di iterazione
 * \param void la funzione non riceve nulla
 */
void play_life(void)
{
	size_t indice_righe;
	size_t indice_colonne;

	indice_righe = 0;
	do{
		indice_colonne = 0;
		do{
			scrittura(world_temp, indice_righe, indice_colonne, nuovo_stato(indice_righe, indice_colonne));
			indice_colonne++;
		}while(indice_colonne < MAX_COLONNE);
		indice_righe++;
	}while(indice_righe < MAX_RIGHE);

	return;
}

/** \fn int caselle_adiacenti_positive(size_t indice_righe, size_t indice_colonne)
 * La funzione controlla che le caselle perimetrali a quella corrispondente alla coordinata siano di tipo 1 o 0
 * \param indice_righe indice contenenete il numero di riga da controllare
 * \param indice_colonne indice contenente il numero di colonna da controllare
 * \return il numero di caselle con valore 1 presenti nel perimetro.
 */
int caselle_adiacenti_positive(size_t indice_righe, size_t indice_colonne)
{
	int indice_sub_righe;
	int indice_sub_colonne;
	int indice_temp_righe;
	int indice_temp_colonne;
	int indice_temp_overflow_righe;
	int indice_temp_overflow_colonne;
	unsigned int contatore_caselle;

	contatore_caselle = 0;
	indice_sub_righe = -1;
	while(indice_sub_righe < 2){
		indice_sub_colonne = -1;
		while(indice_sub_colonne < 2){
			if((indice_sub_righe != 0) || (indice_sub_colonne != 0)){

				indice_temp_righe = ( indice_righe + indice_sub_righe );
				indice_temp_colonne = ( indice_colonne + indice_sub_colonne );

				if((indice_temp_righe == MAX_RIGHE) && (indice_temp_colonne == MAX_RIGHE)){
					indice_temp_overflow_righe = ( indice_temp_righe - MAX_RIGHE );
					indice_temp_overflow_colonne = (indice_temp_colonne - MAX_COLONNE);
					if(1 == lettura(world, indice_temp_overflow_righe, indice_temp_overflow_colonne)){
						contatore_caselle++;
					}
				}
				else if((indice_temp_righe == MAX_RIGHE ) && (indice_temp_colonne < MAX_COLONNE)){
					indice_temp_overflow_righe = ( indice_temp_righe - MAX_RIGHE);
					if(1 == lettura(world, indice_temp_overflow_righe, indice_temp_colonne)){
						contatore_caselle++;
					}
				}
				else if((indice_temp_righe < MAX_RIGHE) && (indice_temp_colonne == MAX_COLONNE)){
					indice_temp_overflow_colonne = ( indice_temp_colonne - MAX_COLONNE );
					if(1 == lettura(world, indice_temp_righe, indice_temp_overflow_colonne)){
						contatore_caselle++;
					}
				}
				else if((indice_temp_righe >= 0) && (indice_temp_colonne >= 0)){
					if(1 == lettura(world, indice_temp_righe, indice_temp_colonne)){
						contatore_caselle++;
					}
				}
				else if((indice_temp_righe < 0) && (indice_temp_colonne < 0)){
					indice_temp_overflow_righe = (MAX_RIGHE + indice_temp_righe);
					indice_temp_overflow_colonne = (MAX_COLONNE + indice_temp_colonne);
					if(1 == lettura(world, indice_temp_overflow_righe, indice_temp_overflow_colonne)){
						contatore_caselle++;
					}
				}
				else if((indice_temp_righe < 0) && (indice_temp_colonne >= 0)){
					indice_temp_overflow_righe = (MAX_RIGHE + indice_temp_righe);
					if(1 == lettura(world, indice_temp_overflow_righe, indice_temp_colonne)){
						contatore_caselle++;
					}
				}
				else if((indice_temp_righe >= 0) && (indice_temp_colonne < 0)){
					indice_temp_overflow_colonne = (MAX_COLONNE + indice_temp_colonne);
					if(1 == lettura(world, indice_temp_righe, indice_temp_overflow_colonne)){
						contatore_caselle++;
					}
				}
			}
			indice_sub_colonne++;
		}
		indice_sub_righe++;
	}
	return (contatore_caselle);
}

/** \fn int nuovo_stato(size_t indice_righe, size_t indice_colonne)
 * Funzione che definisce il nuovo stato della casella delle coordinate, seguendo le regole del gioco
 * \param indice_righe indice contenenete il numero di riga da controllare
 * \param indice_colonne indice contenente il numero di colonna da controllare
 * \return il valore del nuovo stato della casella rilativa alle coordinate
 */
int nuovo_stato(size_t indice_righe, size_t indice_colonne)
{
	int nuovo_stato;

	if(0 == lettura(world, indice_righe, indice_colonne)){
		if(3 == caselle_adiacenti_positive(indice_righe, indice_colonne))
			nuovo_stato = 1;
	}
	else
		if((caselle_adiacenti_positive(indice_righe, indice_colonne) >= 2) && (caselle_adiacenti_positive(indice_righe, indice_colonne) <= 3))
			nuovo_stato = 1;
		else
			nuovo_stato = 0;

	return (nuovo_stato);
}

/** \fn void campo_pre_partita(void)
 * Funzione che inizializza il campo in modo da creare la prima schermata del campo
 * \param void la funzione non riceve nulla
 */
void campo_pre_partita(void)
{
	size_t indice_righe;
	size_t indice_colonne;
	unsigned int numero_casuale;

	//srand (time(NULL));

	indice_righe = 0;
	do{
		indice_colonne = 0;
		do{
			numero_casuale = rand()%3;
			if(numero_casuale == 0)
				scrittura(world, indice_righe, indice_colonne, CASELLA_PIENA);
			else
				scrittura(world, indice_righe, indice_colonne, CASELLA_VUOTA);
			indice_colonne++;
		}while(indice_colonne < MAX_COLONNE);
		indice_righe++;
	}while(indice_righe < MAX_RIGHE);

	return;
}
