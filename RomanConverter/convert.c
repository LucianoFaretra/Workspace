/**\file convert.c
 * \brief File contenente la funzione di trasformazione da decimale a romano
 * \author Luciano Faretra
 * \version 0.1 Alpha
 * \date 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include "globale.h"
#include "output.h"

/** \fn string convert ( int numero )
 * La funzione converte un numero decimale in romano semplice
 * \param numero variabile contenente il numero da convertire
 * \return la funzione restituisce una struttura contenente una stringa in modo da poterla passare alla funzione chiamante per valore
 */
string convert(int numero)
{
	/**
	 * \var numero_romano
	 * La variabile numero_romano consiste di una struttura contenente una stringa la quale contiene il numero convertito in romano
	 */
	string numero_romano = {{'\0'}};
	/**
	 * \var contatore_stringa
	 * La variabile contatore_stringa di tipo unsigned int e' un intero utilizzato come indice
	 */
	unsigned int contatore_stringa = 0;

	if( ( numero <= MAX_CONVERTIBILE ) && ( numero >= MIN_CONVERTIBILE  ) ){
		do{//Esegui
			if( numero >= 1000 ){
				convert_1000( &numero, &numero_romano, &contatore_stringa);
				convert_500(&numero, &numero_romano, &contatore_stringa);
				convert_100(&numero, &numero_romano, &contatore_stringa);
				convert_50(&numero, &numero_romano, &contatore_stringa);
				convert_10(&numero, &numero_romano, &contatore_stringa);
				convert_5(&numero, &numero_romano, &contatore_stringa);
				convert_1(&numero, &numero_romano, &contatore_stringa);
			}
			else if( numero >= 500 ){
				convert_500(&numero, &numero_romano, &contatore_stringa);
				convert_100(&numero, &numero_romano, &contatore_stringa);
				convert_50(&numero, &numero_romano, &contatore_stringa);
				convert_10(&numero, &numero_romano, &contatore_stringa);
				convert_5(&numero, &numero_romano, &contatore_stringa);
				convert_1(&numero, &numero_romano, &contatore_stringa);
			}
			else if( numero >= 100 ){
				convert_100(&numero, &numero_romano, &contatore_stringa);
				convert_50(&numero, &numero_romano, &contatore_stringa);
				convert_10(&numero, &numero_romano, &contatore_stringa);
				convert_5(&numero, &numero_romano, &contatore_stringa);
				convert_1(&numero, &numero_romano, &contatore_stringa);
			}
			else if( numero >= 50 ){
				convert_50(&numero, &numero_romano, &contatore_stringa);
				convert_10(&numero, &numero_romano, &contatore_stringa);
				convert_5(&numero, &numero_romano, &contatore_stringa);
				convert_1(&numero, &numero_romano, &contatore_stringa);
			}
			else if( numero >= 10 ){
				convert_10(&numero, &numero_romano, &contatore_stringa);
				convert_5(&numero, &numero_romano, &contatore_stringa);
				convert_1(&numero, &numero_romano, &contatore_stringa);
			}
			else if( numero >= 5 ){
				convert_5(&numero, &numero_romano, &contatore_stringa);
				convert_1(&numero, &numero_romano, &contatore_stringa);
			}
			else if( numero >= 1 ){
				convert_1(&numero, &numero_romano, &contatore_stringa);
			}
			else{//Esegui se il numero e' 0
				contatore_stringa = ESTENSIONE_MAX_NUMERO_ROMANO;//Incrementa il contatore dell'arrai di uno
			}
		}while(contatore_stringa != ESTENSIONE_MAX_NUMERO_ROMANO);
	}

return numero_romano;//Ritorna una struttura contenente una stringa di caratteri
}

void convert_1000(int* numero, string* numero_romano, unsigned int* contatore_stringa)
{
	while(*numero >= 1000){
		*numero -= 1000;
		numero_romano->numero[*contatore_stringa] = 'M';//Assegna all'array nella posizione contatore_stringa il valore 'H'
		*contatore_stringa += 1;
	};
return;
}

void convert_500(int* numero, string* numero_romano, unsigned int* contatore_stringa)
{
	while( *numero >= 500){
		*numero -= 500;
		numero_romano->numero[*contatore_stringa] = 'D';
		*contatore_stringa += 1;
	};
return;
}

void convert_100(int* numero, string* numero_romano, unsigned int* contatore_stringa)
{
	while( *numero >= 100 ){
		*numero -= 100;
		numero_romano->numero[*contatore_stringa] = 'C';
		*contatore_stringa += 1;
	};
return;
}

void convert_50(int* numero, string* numero_romano, unsigned int* contatore_stringa)
{
	while( *numero >= 50 ){
		*numero -= 50;
		numero_romano->numero[*contatore_stringa] = 'L';
		*contatore_stringa += 1;
	};
return;
}

void convert_10(int* numero, string* numero_romano, unsigned int* contatore_stringa)
{
	while( *numero >= 10 ){
		*numero -= 10;
		numero_romano->numero[*contatore_stringa] = 'X';
		*contatore_stringa += 1;
	};
return;
}

void convert_5(int* numero, string* numero_romano, unsigned int* contatore_stringa)
{
	while( *numero >= 5 ){
		*numero -= 5;
		numero_romano->numero[ *contatore_stringa] = 'V';
		*contatore_stringa += 1;
	};
return;
}

void convert_1(int* numero, string* numero_romano, unsigned int* contatore_stringa)
{
	while( *numero >= 1){
		*numero -= 1;
		numero_romano->numero[*contatore_stringa] = 'I';
		*contatore_stringa += 1;
	};
return;
}
