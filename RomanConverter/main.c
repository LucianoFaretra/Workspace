/*
 * main.c
 *
 *  Created on: 27/mar/2015
 *      Author: ibanez89
 */

#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "output.h"
#include "globale.h"
#include "convert.h"

int main(void)
{
	int numero_da_convertire;

	string numero_convertito;

	numero_da_convertire = lettura_numero();            //Assegna alla variabile numero_da_convertire il valore inserito nello stdio
	numero_convertito = convert(numero_da_convertire);  //Viene passato il numero_da_convertire alla funzione convert, il risultato viene salvato in numero_convertito
	stampa(numero_convertito, numero_da_convertire);    //Invia in stampa sia il numero in decimale che il numero convertito in romano
return 0;
}
