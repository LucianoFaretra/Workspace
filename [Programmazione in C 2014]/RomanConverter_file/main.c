/**\file main.c
 * \brief File main contenente le chiamate a funzioni
 * \section License
 * Rilasciato sotto licenza GNUv3
 * \author Luciano Faretra
 * \version 0.1 Alpha
 * \date 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "output.h"
#include "globale.h"
#include "convert.h"

int main(void)
{

	/**
	 * \var numero_da_convertire
	 * Numero decimale acquisito dalla funzione di input
	 */
	int numero_da_convertire;

	/**
	 * \var numero_convertito
	 * Numero convertito in romano semplice
	 */
	string numero_convertito;

	numero_da_convertire = lettura_numero();            //Assegna alla variabile numero_da_convertire il valore inserito nello stdio
	numero_convertito = convert(numero_da_convertire);  //Viene passato il numero_da_convertire alla funzione convert, il risultato viene salvato in numero_convertito
	stampa(numero_convertito, numero_da_convertire);    //Invia in stampa sia il numero in decimale che il numero convertito in romano


	getchar();//Blocca la console fino alla pressione di un tasto
	getchar();

return 0;
}
