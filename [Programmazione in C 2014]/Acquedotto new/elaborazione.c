/*
 * elaborazione.c
 *
 *  Created on: 31 ago 2015
 *      Author: ibanez89
 */

#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"

/**
 * INPUT			DESCRIZIONE													DOMINIO
 * numero_unita		numero di unita totali che compongolo il modulo				intero senza segno >0 && <= MAX_NUM_UNITA
 * unita			unita da calcolare											intero senza segno >0 && <= MAX_NUM_UNITA
 * consumi_unita[]	array contenente i consumi di ogni unita abitativa letta	float >= 0
 *
 * OUTPUT			DESCRIZIONE													DOMINIO
 * importo_unita	Importo da pagare per l'unita presa in considerazione		float >= 0
 *
 *
 * imposta a 0 il valore di importo_unita;
 * sottrai 1 a unita in modo da far coincidere il numero unita con la posizione in array
 *
 * Se i consumi dell'unita corrispondolo alla fascia agevolata
 * 		Allora
 * 			assegna ad importo_unita il risultato dei consumi dell'unita per la fascia di prezzo
 * 		Altrimenti Se i consumi dell'unita corrispondolo alla fascia base
 * 			Allora
 * 				assegna ad importo_unita il risultato dei consumi dell'unita per la fascia di prezzo
 * 		 Altrimenti Se i consumi dell'unita corrispondolo alla prima fascia
 * 			Allora
 * 				assegna ad importo_unita il risultato dei consumi dell'unita per la fascia di prezzo
 * 		 Altrimenti Se i consumi dell'unita corrispondolo alla seconda fascia
 * 			Allora
 * 				assegna ad importo_unita il risultato dei consumi dell'unita per la fascia di prezzo
 * 		 Altrimenti Se i consumi dell'unita corrispondolo alla terza fascia
 * 			Allora
 * 				assegna ad importo_unita il risultato dei consumi dell'unita per la fascia di prezzo
 * 			Fine Se
 * File Se
 *
 * Aggiungi ad importo_unita la quota fissa dell'unita immobiliare
 * Aggiungi ad importo_unita la quota del modulo contrattuale diviso il numero di unita totali
 * Aggiungi ad importo_unita le spese di fognatura pari ai consumi idtici per il costo del servizio fognatura
 * Aggiungi ad importo_unita le spese di depurazione pari ai consumi idrici per il costo di depurazione
 *
 * ritorna l'importo_unita
 *
 *
 */
float calcolo(float consumi_unita[], unsigned int numero_unita, unsigned int unita)
{
	float importo_unita = 0;

	unita -= 1;//In modod a rispecchiare il numero in array
	if(consumi_unita[unita] >= AGEVOLATA_MIN && consumi_unita[unita] <= AGEVOLATA_MAX){
		importo_unita = (consumi_unita[unita] * AGEVOLATA_PREZZO);
	}
	else if(consumi_unita[unita] >= BASE_MIN && consumi_unita[unita] <= BASE_MAX){
		importo_unita = (consumi_unita[unita] * BASE_PREZZO);
	}
	else if(consumi_unita[unita] >= PRIMA_MIN && consumi_unita[unita] <= PRIMA_MAX){
		importo_unita = (consumi_unita[unita] * PRIMA_PREZZO);
	}
	else if(consumi_unita[unita] >= SECONDA_MIN && consumi_unita[unita] <= SECONDA_MAX){
		importo_unita = (consumi_unita[unita] * SECONDA_PREZZO);
	}
	else{
		importo_unita = (consumi_unita[unita] * TERZA_PREZZO);
	}

	importo_unita += QUOTA_UNITA;
	importo_unita += (QUOTA_MODULO / numero_unita);
	importo_unita += (FOGNATURA * consumi_unita[unita]);
	importo_unita += (DEPURAZIONE * consumi_unita[unita]);

	return (importo_unita);
}
