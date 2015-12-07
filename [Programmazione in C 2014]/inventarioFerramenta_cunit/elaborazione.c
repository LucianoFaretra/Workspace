/*
 * elaborazione.c
 *
 *  Created on: 10/lug/2015
 *      Author: ibanez89
 */
#include <stdlib.h>
#include <stdio.h>
#include "inputOutput.h"
#include "dati_globali.h"
#include <string.h>

/**
 * \fn creazione_articolo (unsigned int *progressivo_attuale, tab_magazzino magazzino[])
 * Funzione di creazione nuovo record
 * \param *progressivo_attuale progressivo di record attuale
 * \param magazzino[] array di strutture contenente la giacenza di magazzino
 * \return esito dell'operazione, 0 ok, 1 fallita
 */
unsigned int creazione_articolo(unsigned int *progressivo_attuale, tab_magazzino magazzino[])
{

	/**
	 * \var esito
	 * variabile contenente l'esito dell'operazione
	 */
	unsigned int esito = 1;
	/**
	 * \var indice_Array
	 * indice array per scorrimento arrays
	 */
	unsigned int indice_array;

	indice_array = 0;
	while(indice_array < DIMENISIONEMAGAZZINO){
		if(magazzino[indice_array].record == 0){
			printf("Inserire il nome del prodotto - max 30ct - \n ->: ");
			scanf("%30s", magazzino[indice_array].nomeProdotto);
			printf("Inserire la quantita disponibile del prodotto \n ->: ");
			scanf("%u", &magazzino[indice_array].quantita);
			printf("Inserire il prezzo unitario del prodotto \n ->: ");
			scanf("%f", &magazzino[indice_array].prezzo);

			*progressivo_attuale = ((*progressivo_attuale) + 1);

			magazzino[indice_array].record = *progressivo_attuale;
			indice_array = DIMENISIONEMAGAZZINO;
			esito = 0;
		}
		indice_array++;
	}
	return (esito);
}

/**
 * \fn unsigned int elimina_record(tab_magazzino magazzino[], unsigned int record_da_eliminare)
 * Funzione per eliminazione di un record
 * \param magazzino[] struttura contenente la giacenza di magazzino
 * \param record_da_eliminare indice record relativo al record da eliminare
 * \return esito dell'operazione, 0 riuscita, 1 fallita
 */
unsigned int elimina_record(tab_magazzino magazzino[], unsigned int record_da_eliminare)
{
	/**
	 * \var esito
	 * Esito dell'operazione
	 */
	unsigned int esito = 1;
	/**
	 * \var indice_array
	 * indice per scorrere l'array
	 */
	unsigned int indice_array;
	/**
	 * \var nome_vuoto[30]
	 * stringa usata per cancellare un nome
	 */
	char nome_vuoto[30] = " ";

	indice_array = 0;
	while(indice_array < DIMENISIONEMAGAZZINO){
		if(magazzino[indice_array].record == record_da_eliminare){
			strcpy(magazzino[indice_array].nomeProdotto, nome_vuoto);
			magazzino[indice_array].quantita = 0;
			magazzino[indice_array].prezzo = 0;
			magazzino[indice_array].record = 0;
			esito = 0;
		}
		indice_array++;
	}

	return (esito);
}

/**
 * \fn unsigned int modifica_prezzo_record(tab_magazzino magazzino[], unsigned int record_da_modificare_prezzo, float nuovo_prezzo)
 * Funzione utilizzata per modificare il prezzo di un record
 * \param magazzino[] Giacenza di magazzino
 * \param record_da_modificare_prezzo valore corrispondente al record da modificare
 * \param nuovo_prezzo valore contenente il nuovo prezzo da assegnare al prodotto
 * \return ritorna l'esito dell'operazione, 0 successo, 1 fallita
 */
unsigned int modifica_prezzo_record(tab_magazzino magazzino[], unsigned int record_da_modificare_prezzo, float nuovo_prezzo)
{
	/**
	 * \var esito
	 * esito dell'operazione
	 */
	unsigned int esito = 1;
	/**
	 * \var indice_array
	 * indice usato per scorrere l'array
	 */
	unsigned int indice_array;

	indice_array = 0;
	while(indice_array < DIMENISIONEMAGAZZINO){
		if(magazzino[indice_array].record == record_da_modificare_prezzo){
			magazzino[indice_array].prezzo = nuovo_prezzo;
			esito = 0;
		}
		indice_array++;
	}

	return (esito);
}

/**
 * \fn unsigned int modifica_quantita_record(tab_magazzino magazzino[], unsigned int record_da_modificare_quantita, float nuova_quantita)
 * Funzione usata per modificare la quantità di un prodotto in base al suo record
 * \param magazzino[] contiene la giacenza di magazzino
 * \param record_da_modificare_quantita contiene la nuova quantita'
 * \return ritorna l'esito dell'operazione, 0 successo, 1 fallita
 */
unsigned int modifica_quantita_record(tab_magazzino magazzino[], unsigned int record_da_modificare_quantita, float nuova_quantita)
{
	unsigned int esito = 1;
	unsigned int indice_array;

	indice_array = 0;
	while(indice_array < DIMENISIONEMAGAZZINO){
		if(magazzino[indice_array].record == record_da_modificare_quantita){
			magazzino[indice_array].quantita = nuova_quantita;
			esito = 0;
		}
		indice_array++;
	}

	return (esito);
}
