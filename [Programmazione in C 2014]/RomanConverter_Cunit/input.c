/**\file input.c
 * \brief File contenente la funzione di input
 * \author Luciano Faretra
 * \version 0.1 Alpha
 * \date 2015
 */

#include <stdlib.h>
#include <stdio.h>

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
