#include <stdio.h>
#include <stdlib.h>
#include "dati_globali.h"
#include "accesso_dati.h"
#include "elaborazione.h"
#include "output.h"

int genera_numero_casuale(void)
{
	return (rand() % RANGE_NUMERI_CASUALI);
}

void alloca_matrice(dati_matrice *matrice)
{
	int indice_righe;

	matrice->matrice = malloc(matrice->numero_righe * sizeof(int*));
	indice_righe = 0;
	while(indice_righe < matrice->numero_righe){
		matrice->matrice[indice_righe] = malloc(matrice->numero_colonne * sizeof(int));
		indice_righe++;
	}

	return;
}


int controllo_matrice(int **matrice)
{
	int esito_controllo;

	if(matrice == NULL){
		messaggi(IMPOSSIBILE_ALLOCARE);
		esito_controllo = 0;
	}
	else
		esito_controllo = 1;

	return (esito_controllo);
}

void riempi_matrice(dati_matrice *matrice)
{
	size_t indice_righe;
	size_t indice_colonne;

	indice_righe = 0;
	while(indice_righe < matrice->numero_righe){
		indice_colonne = 0;
		while(indice_colonne < matrice->numero_colonne){
			scrittura_matrice_doppia(matrice->matrice, indice_righe, indice_colonne, genera_numero_casuale());
			indice_colonne++;
		}
	indice_righe++;
	}

	return;
}

int media_elementi_vettore(dati_matrice matrice)
{
	int media_aritmetica;
	int subtotale = 0;
	size_t indice_righe;
	size_t indice_colonne;

	indice_righe = 0;
	while(indice_righe < matrice.numero_righe){
		indice_colonne = 0;
		while(indice_colonne < matrice.numero_colonne){
			subtotale += lettura_matrice_doppia(matrice.matrice, indice_righe, indice_colonne);
			indice_colonne++;
		}
	indice_righe++;
	}

	media_aritmetica = arrotondamento(subtotale, (matrice.numero_righe * matrice.numero_colonne));

	return (media_aritmetica);
}

int arrotondamento(int subtotale, unsigned int numero_elementi)
{
	int media_aritmetica;
	float new_subtotal;

	new_subtotal = (subtotale / numero_elementi);
	subtotale = (subtotale % numero_elementi);
	if(subtotale >= 0.5)
		media_aritmetica = ((new_subtotal -= subtotale) + 1);
	else
		media_aritmetica = (new_subtotal -= subtotale);

	return (media_aritmetica);
}

int genera_quaterna(dati_matrice matrice, int quaterna[])
{
	size_t indice_righe;
	size_t indice_colonne;
	size_t indice_quaterna = 0;
	unsigned int quaterne_valide = 0;

	indice_righe = 0;
	while(indice_righe < matrice.numero_righe){
		indice_colonne = 0;
		while(indice_colonne < matrice.numero_colonne){
			scrittura_matrice(quaterna, indice_quaterna, lettura_matrice_doppia(matrice.matrice, indice_righe, indice_colonne));
			if(indice_quaterna == QUATERNA){
				if(1 == stampa_quaterna_se_idonea(quaterna, prodotto_quaterna(quaterna), media_elementi_vettore(matrice))){
					quaterne_valide++;
				}
				indice_quaterna = 0;
			}
			indice_colonne++;
			indice_quaterna++;
		}
	indice_righe++;
	}

	return (quaterne_valide);
}

int prodotto_quaterna(int quaterna[])
{
	int prodotto = 0;
	size_t indice_quaterna;

	indice_quaterna = 0;
	while(indice_quaterna < QUATERNA){
		prodotto += quaterna[indice_quaterna];
		indice_quaterna++;
	}
	return (prodotto);
}

int stampa_quaterna_se_idonea(int quaterna[], int prodotto_quaterna, int media_elementi_vettore)
{
	int esito = 0;

	if(prodotto_quaterna < media_elementi_vettore){
		messaggi(MESSAGGIO_QUATERNA);
		stampa_quaterne(quaterna);
		esito = 1;
	}
	return(esito);
}
