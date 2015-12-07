/** \file main.h
 * 	\author Luciano Faretra
 * 	\date 2015
 * 	\version 0.1
 */

#include <stdlib.h>
#include <stdio.h>
#include "inputOutput.h"
#include "elaborazione.h"
#include "dati_globali.h"

int main(void)
{
	tab_magazzino magazzino_ferramenta[DIMENISIONEMAGAZZINO] = {{0, "", 0, 0}};
	/** \var scelta_effettuata
	 * scelta del menu effettuata dall'utente
	 */
	unsigned int scelta_effettuata = EXIT;
	/** \var progressivo_attuale
	 * numero progressivo di record attuale
	 */
	unsigned int progressivo_attuale;
	/** \var record_da_eliminare
	 * numero di record da eliminare
	 */
	unsigned int record_da_eliminare;
	/** \var record_da_modificare_quantita
	 * numero di record cui modificare la quantita
	 */
	unsigned int record_da_modificare_quantita;
	/** \var nuova_quantita
	 * nuova quantita del record
	 */
	unsigned int nuova_quantita;
	/** \var record_da_modificare_prezzo
	 * record a cui modificare il prezzo
	 */
	unsigned int record_da_modificare_prezzo;
	/** \var nuovo_prezzo
	 * nuovo prezzo del prodotto
	 */
	float nuovo_prezzo;

	scelta_effettuata = inizializzazione();

	if(scelta_effettuata == 0){
		if( lettura_magazzino(magazzino_ferramenta) == 0 ){
		stampa_magazzino(magazzino_ferramenta);
		stampa_operazione_avvenuta();
		}
		else{
			stampa_operazione_errore();
			puts("Errore lettura magazzino");
		}
	}
	else if(scelta_effettuata == 1){
		progressivo_attuale = lettura_progressivo();
		if( lettura_magazzino(magazzino_ferramenta) == 0 ){
			if( creazione_articolo(&progressivo_attuale, magazzino_ferramenta) == 0 ){
				if( scrittura_progressivo(progressivo_attuale) == 0 ){
					if( scrittura_magazzino(magazzino_ferramenta) == 0 ){
						stampa_operazione_avvenuta();
					}
					else{
						stampa_operazione_errore();
						puts("Errore scrittura magazzino");
					}
				}
				else{
					stampa_operazione_errore();
					puts("Errore scrittura progressivo");
				}
			}
			else{
				stampa_operazione_errore();
				puts("Errore creazione articolo");
			}
		}
		else{
			stampa_operazione_errore();
			puts("Errore lettura magazzino");
		}
	}
	else if(scelta_effettuata == 2){
		lettura_magazzino(magazzino_ferramenta);
		printf("Inserire numero record da eliminare; \n ->: ");
		record_da_eliminare = lettura_intero();
		if(elimina_record(magazzino_ferramenta, record_da_eliminare) == 0){
			scrittura_magazzino(magazzino_ferramenta);
			stampa_operazione_avvenuta();
		}
		else{
			stampa_operazione_errore();
			puts("Errore eliminazione articolo");
		}
	}
	else if(scelta_effettuata == 3){
		lettura_magazzino(magazzino_ferramenta);
		printf("Inserire numero record cui modificare la quantita' in giacenza; \n ->: ");
		record_da_modificare_quantita = lettura_intero();
		printf("Inserire la nuova quantita' per il record selezionato; \n ->: ");
		nuova_quantita = lettura_intero();
		if(modifica_quantita_record(magazzino_ferramenta, record_da_modificare_quantita, nuova_quantita) == 0 ){
			scrittura_magazzino(magazzino_ferramenta);
			stampa_operazione_avvenuta();
		}
		else{
			stampa_operazione_errore();
			puts("Errore modifica quantita' articolo");
		}
	}
	else if(scelta_effettuata == 4){
		lettura_magazzino(magazzino_ferramenta);
		printf("Inserire numero record cui modificare il prezzo; \n ->: ");
		record_da_modificare_prezzo = lettura_intero();
		printf("Inserire nuovo prezzo per il record selezionato; \n ->: ");
		nuovo_prezzo = lettura_float();
		if(modifica_prezzo_record(magazzino_ferramenta, record_da_modificare_prezzo, nuovo_prezzo) == 0 ){
			scrittura_magazzino(magazzino_ferramenta);
			stampa_operazione_avvenuta();
		}
		else{
			stampa_operazione_errore();
			puts("Errore modifica prezzo articolo");
		}
	}
	else if(scelta_effettuata == EXIT){
		puts("Grazie e arrivederci!");
	}

return (0);
}
