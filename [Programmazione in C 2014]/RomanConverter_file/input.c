/**\file input.c
 * \brief File contenente la funzione di input
 * \author Luciano Faretra
 * \version 0.1 Alpha
 * \date 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include "globale.h"

/** \fn int lettura_numero ( void )
 * Funzione di lettura dallo standard input
 * \return l'intero numero_input, il valore letto dallo stdio
 */
int lettura_numero(void)
{
	/**
	 * \var numero_input
	 * Variabile di tipo intero contenente il valore letto dallo stdio
	 */
	int numero_input;

	/** \var esito_scanf
	 * Variabile di tipo intero senza segno contenente il risultato dell'esito di lettura della funzione scanf
	 */
	unsigned int esito_scanf = 0;

	do{//Esegui
		printf("%s", "Inserisci un numero intero da convertire: "); //Stampa indicazioni per l'utente
		esito_scanf = scanf("%d", &numero_input); //Assegna il valore letto alla variabile numero_input e salva l'esito di lettura in esito_scanf
			if(0 == esito_scanf){ //Se la lettura non ha avuto esito positivo
				scanf("%*[^\n]"); //svutola il buffer di scanf
				puts("Input non valido"); //Stampa mesasggio d'errore per l'utente
			}
	}while(0 == esito_scanf);//Finchè non viene effettuata una lettura corretta

return numero_input; //Valore restituito dalla funzione di lettura
}

/** \fn unsigned int lettura_massimo_numero_calcolabile( FILE* massimo_numero_calcolabile )
 * \param massimo_numero_calcolabile puntatore al file config_massimo_numero_calcolabile.txt
 * Funzione di lettura configurazioni per massimo numero calcolabile
 * \return l'intero numero_input, il valore letto dallo stdio
 */
unsigned int lettura_massimo_numero_calcolabile( FILE* massimo_numero_calcolabile )
{
	/** \var max_convertibile
	 * Variabile di tipo intero senza segno contenente il massimo numero convertibile eltto da file
	 */
	unsigned int max_convertibile;

	fscanf(massimo_numero_calcolabile, "%*[^\n]\n", NULL); //Elimina la prima riga del file contenente le istruzioni per la compilazione
	while(!feof(massimo_numero_calcolabile)){//Leggi finchè non si raggiunge la fine del file, se vuoto non legge nulla
		fscanf(massimo_numero_calcolabile, "%u", &max_convertibile); //Assegna il valore letto alla variabile max_convertibile
	}

return max_convertibile;
}

/** \fn tab_conversione lettura_tabella_conversione( FILE* tabella_conversione )
 * \tabella_conversione puntatore al file tabella_conversione.txt
 * Legge la tabella di conversione presente sul file e la restituisce alla funzione chiamante
 * \return tabella del file di testo caricata in memoria
 */
tab_conversione lettura_tabella_conversione( FILE* tabella_conversione )
{
	/** \var romano_semplice
	 * Crea una tabella di conversione vuota per ospitare i dati letti dal file di configurazione
	 */
	tab_conversione romano_semplice;

	fscanf(tabella_conversione, "%*[^\n]\n", NULL); //Elimina la prima riga del file contenente le istruzioni per la compilazione
	while((!feof(tabella_conversione)) && (romano_semplice.num_simboli <= NUMERO_MAX_SIMBOLI_INPUT)){ //Continua lettura se file non e' vuoto o non si e' raggiunta la dimensione massima di conversioni salvabili
		fscanf(tabella_conversione, "%u %2s", &romano_semplice.unita[romano_semplice.num_simboli], &romano_semplice.simbolo[romano_semplice.num_simboli]);//popola la tabella
		romano_semplice.num_simboli += 1;//Passa a posizione array successiva
	}
	romano_semplice.num_simboli -= 1; //Elimina EOF
return romano_semplice;
}
