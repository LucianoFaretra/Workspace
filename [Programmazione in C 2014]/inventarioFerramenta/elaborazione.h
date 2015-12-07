/*
 * elaborazione.h
 *
 *  Created on: 10/lug/2015
 *      Author: ibanez89
 */

#ifndef ELABORAZIONE_H_
#define ELABORAZIONE_H_

#include "dati_globali.h"


unsigned int creazione_articolo(unsigned int *progressivo_attuale, tab_magazzino magazzino[]);
unsigned int elimina_record(tab_magazzino magazzino[], unsigned int record_da_eliminare);
unsigned int modifica_prezzo_record(tab_magazzino magazzino[], unsigned int record_da_modificare_prezzo, float nuovo_prezzo);
unsigned int modifica_quantita_record(tab_magazzino magazzino[], unsigned int record_da_modificare_quantita, float nuova_quantita);

#endif /* ELABORAZIONE_H_ */
