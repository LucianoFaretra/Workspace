/**\file output.c
 * \brief File contenente le funzioni di output
 * \author Luciano Faretra
 * \version 0.1 Alpha
 * \date 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include "globale.h"

/** \fn void stampa ( string numero_romano, int numero_decimale )
 * Funzione di stampa del numero decimale ed il numero convertito in romano
 * \param numero_romano Stringa contenente il numero decimale convertito in Romano
 * \param numero_decimale Variabile intera contenente l'intero da convertire in romano
 * \return void La funzione non restituisce nulla
 */
void stampa(string numero_romano, int numero_decimale)
{
	if(numero_romano.numero[0] != '\0') //Esegui se il primo carattere dell'arrai e' diverso da !
		printf("Il numero decimale \"%d\" equivale a \"%s\" in romano semplificato.", numero_decimale, numero_romano.numero);
	else //Altrimenti stampa messaggio d'errore
		puts("Errore nella conversione del numero da decimale a romano.\n"
			"Sono accettati solo numeri interi compresi tra 0 e 5000 estremi esclusi.");

return;
}
