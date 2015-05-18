/** \file elaborazione_dati.h
 * \brief File contenente tutte le manipolazioni sui dati, logiche e aritmetiche
 * \section License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "dati_globali.h"
#include "elaborazione_dati.h"
#include "accesso_dati.h"

/** \fn int** alloca_matrice(int numero_righe, int numero_colonne)
 * 	Funzione di allocazione memoria per la matrice bidimensionale
 * \param numero_righe numero righe di cui è composta la matrice
 * \param numero_colonne numero colonne di cui è composta la matrice
 * \return matrice con la memoria allocata
 */

int** alloca_matrice(int numero_righe, int numero_colonne)
{
	/** \var indice_rige
	 * Variabile utilizzata come contatore per scandire le righe
	*/
	int indice_righe;
	/** \var **matrice
	 * puntatore a matrice con relativa allocazione
	*/
	int **matrice = malloc(numero_righe * sizeof(int*)); //Alloca tot righe alla matrice

	indice_righe = 0;
	while(indice_righe < numero_righe){//Analizza tutte le righe che compongono la matrice
		matrice[indice_righe] = malloc(numero_colonne * sizeof(int)); //Alloca lo spazio per ogni riga della matrice
		indice_righe++; //Incrementa contatore di uno
	}

	return (matrice);//Restituisci la matrice con la memoria allocata
}

/** \fn int controllo_matrice_nulla(int **matrice)
 * 	Funzione di controllo, se la matrice e nulla restituisce 0 ed un messaggio d'errore, altrimenti 1
 * \param **matrice matrice da controllare
 * \return esito_booleano_allocazione 0 se negativo, 1 se positivo
 */

int controllo_matrice_nulla(int **matrice)
{
	/** \var esito_booleano_allocazione
	 * variabile booleana esito allocazione
	*/
	int esito_booleano_allocazione = 1;//Di default la matrice e' allocata
	if(matrice == NULL){//Se la matrice non e' allocata
		printf("Attenzione, non è stato possibile allocare lo spazio in memoria per la matrice!"); //Stampa messaggio d'errore
		esito_booleano_allocazione = 0;//Imposta l'esito a fallimento
	}
	return (esito_booleano_allocazione);//Restituisce l'esito del controllo, 1 positivo 0 negativo
}

/** \fn void composizione_matrice(int **matrice, int numero_righe, int numero_colonne)
 * 	La funzione riempie la matrice di dati
 * \param **matrice matrice da riempire
 * \param numero_righe numero righe di cui è composta la matrice
 * \param numero_colonne numero colonne di cui è composta la matrice
 */

void composizione_matrice(int **matrice, int numero_righe, int numero_colonne)
{
	/** \var indice_righe
	 * Indice righe utilizzato per scandire le righe dell'array
	 */
	int indice_righe;
	/** \var indice_colonne
	 * Indice colonne utilizzato per scandire le colonne dell'array
	 */
	int indice_colonne;

	indice_righe = 0; //Inizializza indice a zero
	while(indice_righe < numero_righe){
		indice_colonne = 0; //Inizializza indice a zero
		while(indice_colonne < numero_colonne){
			scrittura_matrice(matrice, indice_righe, indice_colonne, genera_numero_random()); //Scrive il numero random restituito dall'apposita funzione alla coordinata attuale
			indice_colonne++;
		}
		indice_righe++;
	}
	return;
}

/** \fn int genera_numero_random(void)
 * 	La funzione genera e restituisce un numero random compreso tra 0 e MAX_CASUALE
 * 	\return numero casuale generato
 */


int genera_numero_random(void)
{
	return (rand() % MAX_CASUALE); //Genera un numero casiale tra 0 e MAX_CASUALE e lo restituisce alla funzione chiamante
}

/** \fn int somma_sub_matrice(int **matrice, int numero_righe, int numero_colonne, int coordinata_righe, int coordinata_colonne)
 * 	La funzione analizza e restituisce la somma dei dati della submatrice
 * \param **matrice matrice da analizzare
 * \param numero_righe numero righe di cui è composta la matrice
 * \param numero_colonne numero colonne di cui è composta la matrice
 * \param coordinata_righe coordinata X del punto su cui analizzare la submatrice periferica
 * \param coordinata_colonne coordinata Y del punto su cui analizzare la submatrice periferica
 * \return la somma della submatrice
 */

int somma_sub_matrice(int **matrice, int numero_righe, int numero_colonne, int coordinata_righe, int coordinata_colonne)
{
	/** \var indice_sub_righe
	 * Indice_sub_righe utilizzato per analizzare la submatrice, consente la scansione della griglia
	 */
	int indice_sub_righe;
	/** \var indice_sub_colonne
	 * indice_sub_colonne utilizzato per analizzare la submatrice, consente la scansione della griglia
	 */
	int	indice_sub_colonne;
	/** \var somma_matrice
	 * Valore contenente la somma dei valori della submatrice
	 */
	int somma_matrice = 0; //Inizializza la il valore somma della matrice a 0

	if(coordinata_righe > 0 && coordinata_colonne > 0 &&
	   coordinata_righe < (numero_righe - 1) && coordinata_colonne < (numero_colonne -1)){ //Se la submatrice non esce dai vincoli allora procedi altrimenti non fare nulla e restituisci 0
		indice_sub_righe = -1; //Inizializza la subriga a -1 in modo da cominciar il controllo dalla coordinata riga meno 1
		while(indice_sub_righe < 2){
			indice_sub_colonne = -1; //Inizializza la subcolonna a -1 in modo da cominciar il controllo dalla coordinata colonna meno 1
			while(indice_sub_colonne < 2){
				somma_matrice += lettura_matrice(matrice, (coordinata_righe + indice_sub_righe), (coordinata_colonne + indice_sub_colonne)); //Invia alla funzione di lettura la coordinata del valore da leggere e salvalo nell'apposita variabile sommando al valore presente
				indice_sub_colonne++;
			}
			indice_sub_righe++;
		}
	}
	return (somma_matrice); //Restituisce il valore totale della subriga
}

/** \fn dati_submatrice trova_submatrice_maggiore(int **matrice, int numero_righe, int numero_colonne)
 * 	La funzione analizza tutte le submatrici e restituisce i dati di quella più grande
 * \param **matrice matrice da analizzare
 * \param numero_righe numero righe di cui è composta la matrice
 * \param numero_colonne numero colonne di cui è composta la matrice
 * \return dati_submatrice struttura contenente i dati della matrice piu grande
 */

dati_submatrice trova_submatrice_maggiore(int **matrice, int numero_righe, int numero_colonne)
{
	dati_submatrice reticolo_piu_grande = {0, 0, 0};
	/** \var indice_righe
	 * Indice righe utilizzato per scandire le righe dell'array
	 */
	int indice_righe;
	/** \var indice_colonne
	 * Indice colonne utilizzato per scandire le colonne dell'array
	 */
	int indice_colonne;
	/** \var somma_submatrice_attuale
	 * Valore contenente la somma della submatrice che si sta analizzando
	 */
	int somma_submatrice_attuale;
	/** \var massimo_submatrice
	 * Valore contentente la somma della submatrice piu grande fin'ora analizzata
	 */
	int massimo_submatrice = 0;

	indice_righe = 0;
	while(indice_righe < numero_righe){
		indice_colonne = 0;
		while(indice_colonne < numero_colonne){
			somma_submatrice_attuale = somma_sub_matrice(matrice, numero_righe, numero_colonne, indice_righe, indice_colonne);// La somma della submatrice attuale viene restituita dalla funzione di calcolo del valore della submatrice che si sta analizzando
			if(massimo_submatrice < somma_submatrice_attuale){// Se l'attuale massimo e' piu piccolo del valore appena analizzato, allora sostituisci il valore massimo con il nuovo
				massimo_submatrice = somma_submatrice_attuale;
				reticolo_piu_grande.riga = indice_righe; //Salva nella struttura la coordinata X della matrice piu grande
				reticolo_piu_grande.colonna = indice_colonne; //Salva nella struttura la coordinata Y della matrice piu grande
				reticolo_piu_grande.somma_valori = massimo_submatrice; //Salva nella struttura la somma della submatrice
			}
			indice_colonne++;
		}
		indice_righe++;
	}
	return (reticolo_piu_grande); //Restituisci la struttura con i dati della submatrice piu grande
}
