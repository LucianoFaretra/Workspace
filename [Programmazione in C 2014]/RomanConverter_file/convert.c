/**\file convert.c
 * \brief File contenente la funzione di trasformazione da decimale a romano
 * \author Luciano Faretra
 * \version 0.1 Alpha
 * \date 2015
 */

/**
 * INPUT									DESCRIZIONE											DOMINIO
 * numero									Numero decimale da converitre in romano				0 < numero < 5000
 *
 * OUTPUT									DESCRIZIONE											DOMINIO
 * numero_romano							Struttura contenente l'array numero					Struttura dati
 * .numero[ESTENSIONE_MAX_NUMERO_ROMANO]	Array contenuto nella struttura numero_romano
 * 											contenente il numero convertito in romano semolice	Stringa di caratteri
 *
 * 	DATI DI LAVORO							DESCRIZIONE											DOMINIO
 * 	ESTENSIONE_MAX_NUMERO_ROMANO			Estensione massima in lettere del numero romano		> 0
 *	MAX_CONVERTIBILE						Numero decimale massimo convertibile in romano		4999
 *	MIN_CONVERTIBILE						Numero decimale piu piccolo converitibile in romano	1
 *
 *
 *	Funzione Convert:
 *
 *	Se il numero rispetta i voncoli
 *		Allora
 *			Esegui
 *				Se il numero e' maggiore di MIN_CONVERTIBILE
 *					Allora
 *						chiama la funzione di conversione delle migliaia in romano
 *						chiama la funzione di conversione delle cinquecentine in romano
 *						chiama la funzione di conversione delle centinaia in romano
 *						chiama la funzione di conversione delle cinquantine in romano
 *						chiama la funzione di conversione delle decine in romano
 *						chiama la funzione di conversione delle cinquine in romano
 *						chiama la funzione di conversione delle unita' in romano
 *					Altrimenti
 *						porta il contatore_stringa a fine stringa in modo da uscire dal ciclo
 *				Fine
 *			Finche' il contatore_stringa non ha raggiunto ESTENSIONE_MAX_NUMERO_ROMANO
 *		Fine
 *	restituisci numero_romano
 *
 *	Prototipo generico funzione di conversione unita numerica:
 *
 *	INPUT									DESCRIZIONE											DOMINIO
 * 	*numero									Indirizzo Numero decimale da converitre in romano	0 < numero < limite funzione
 * 	*numero_romano							indirizzo Struttura contenente l'array numero		Struttura dati
 * 	->numero[ESTENSIONE_MAX_NUMERO_ROMANO]	Array contenuto nella struttura numero_romano
 * 	unita									Unita' che s'intende elaborare						> 0 <= 1000
 * 	simbolo									Sibolo corrispettivo all'unita in romano			char
 * 	*contatore_stringa						Contatore per scorrere l'array passato x indirizzo	>= 0 <= ESTENSIONE_MAX_NUMERO_ROMANO
 *
 * 	OUTPUT									DESCRIZIONE											DOMINIO
 *
 * 	DATI DI LAVORO							DESCRIZIONE											DOMINIO
 * 	ESTENSIONE_MAX_NUMERO_ROMANO			Estensione massima in lettere del numero romano		> 0
 *
 * 	Mentre il *numero e' >= unita
 * 		sottrai dal numero unita
 * 		*numero_romano->numero[ESTENSIONE_MAX_NUMERO_ROMANO] = simbolo
 * 		incrementa *contatore_stringa di 1
 * 	Fine
 */


#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include "globale.h"
#include "output.h"
#include "input.h"

/** \fn string convert ( int numero )
 * La funzione converte un numero decimale in romano semplice
 * \param numero variabile contenente il numero da convertire
 * \return la funzione restituisce una struttura contenente una stringa in modo da poterla passare alla funzione chiamante per valore
 */
string convert(int numero)
{
/**
 * \var config_massimo_numero_calcolabile
 * Puntatore al file config_massimo_numero_calcolabile.txt
 */
FILE* config_massimo_numero_calcolabile;
/**
 * \var tabella_conversione
 * Puntatore al file tabella_conversione.txt
 */
FILE* tabella_conversione;

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

	/**
	 * \var max_convertibile
	 * la variabile contiene il valore del numero massimo convertibile letto dal file di configurazione
	 */
	unsigned int max_convertibile;


	/**
	 * \var chiave_di_conversione
	 * la variabile contiene la tabella di conversione deii simboli
	 */
	tab_conversione chiave_di_conversione;

	if((config_massimo_numero_calcolabile = fopen("config_massimo_numero_calcolabile.txt", "r")) == NULL ) {//Se il puntatore a file e' nulla
			puts("Impossibile aprire il file config_massimo_numero_calcolabile.txt");//Stampa messaggio d'errore
		}
		else{//Altrimenti

			max_convertibile = lettura_massimo_numero_calcolabile( config_massimo_numero_calcolabile );//Importa il numero massimo convertibile

			if((tabella_conversione = fopen("tabella_conversione.txt", "r")) == NULL ) {//Se il puntatore a file e' nulla
				puts("Impossibile aprire il file tabella_conversione.txt");//Allora stampa messaggio d'errore
			}
			else{//Altrimenti

				chiave_di_conversione = lettura_tabella_conversione( tabella_conversione );//Importa tabella di conversione

				do{//Esegui
					if( ( numero <= max_convertibile ) && ( numero >= MIN_CONVERTIBILE  ) ){ //Se il numero rispetta i vincoli esegui
						convert_unita( &numero, &numero_romano, &contatore_stringa, chiave_di_conversione.unita[chiave_di_conversione.num_simboli], chiave_di_conversione.simbolo[chiave_di_conversione.num_simboli]);
						//Passa alla funzione i parametri desiderati
						chiave_di_conversione.num_simboli -= 1;//Passa a posizione array successiva
					}
					else{//Esegui se il numero e' < di MIN_CONVERTIBILE
						contatore_stringa = ESTENSIONE_MAX_NUMERO_ROMANO;//Incrementa il contatore del vettore in modo da uscire dal ciclo
					}//Altrimenti restituisci la stringa vuota
				}while((contatore_stringa != ESTENSIONE_MAX_NUMERO_ROMANO) && (chiave_di_conversione.unita >= 0) );//Fnche' il contatore_stringa e' diverso dall'ESTENSIONE_MAX_NUMERO_ROMANO
			}
		}

return numero_romano;//Ritorna una struttura contenente una stringa di caratteri
}

/** \fn void convert_unita ( int* numero, string* numero_romano, unsigned int* contatore_stringa, int unita, char simbolo )
 * La funzione converte un numero decimale in romano semplice
 * \param *numero indirizzo della variabile contenente il numero da convertire
 * \param *numero_romano indirizzo della struttura contenente la stringa dove salvare il numero romano convertito
 * \param *contatore_stringa indirizzo della variabile contenente il contatore utilizzato per scorrere l'array
 * \param unita unita' da operare
 * \param simbolo simbolo da inserire nell'array relativo a questa unita'
 */
void convert_unita(int* numero, string* numero_romano, unsigned int* contatore_stringa, int unita, char simbolo)
{
	while(*numero >= unita){ //Mentre numero >= di unita'
		*numero -= unita; //Sottrai unita' al numero
		numero_romano->numero[*contatore_stringa] = simbolo; //Assegna all'array nella posizione contatore_stringa il valore romano
		*contatore_stringa += 1; //Incrementa il contatore della stringa di uno
	};
return;
}
