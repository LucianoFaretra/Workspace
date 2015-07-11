/** \file main.c
 * \brief File contenente il main del programma
 * Il seguente file contiene le chiamate necessare all'esecuzione del programma
 * \section  License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "input.h"
#include "dati_globali.h"
#include "output.h"
#include "elaborazione_dati.h"

int main(void)
{
	matrice m;//Crea una matrice
	int quadrato_magico = 0;
	long long int numero_tentativi = 0;

	srand(time(NULL));//Inizializza il seme del generatore di numeri casuali

	controllo_matrice_quadrata(&m);//Controlla che la matrice sia quadrata altrimenti fa reinserire i dati
	alloca_matrice(&m);//Alloca la matrice a seconda dei dati inseriti
	if(controllo_matrice_void(m) == 1){//Se la matrice non e' void
		do{
			riempi_matrice(&m);//Riempi la matrice di numeri casuali
			quadrato_magico = controlla_quadrato_magico(m);
			if(0 == quadrato_magico){//Se matrice non magica
				stampa_messaggi(MATRICE_NON_MAGICA);//Stampa questo messaggio
				numero_tentativi++;
			}
			else{//Altrimenti
				stampa_messaggi(MATRICE_MAGICA);
				stampa_messaggi(STAMPA_MATRICE);//Stampa messaggio d'avviso
				stampa_matrice(m);//Stampa la matrice
				stampa_messaggi(TENTATIVI);
				printf("%lld", numero_tentativi);
			}
		}while(quadrato_magico != 1);
	}
	else{//Altrimenti stampa messaggio d'errore
		stampa_messaggi(ERRORE_ALLOCAZIONE);
	}

	return (0);
}
