/*
 * inputOutput.h
 *
 *  Created on: 10/lug/2015
 *      Author: ibanez89
 */
#include "dati_globali.h"

#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_

unsigned int inizializzazione(void);
unsigned int lettura_intero(void);
float lettura_float(void);
unsigned int lettura_progressivo(void);
unsigned int scrittura_progressivo(unsigned int progressivo_attuale);
unsigned int lettura_magazzino(tab_magazzino magazzino[]);
unsigned int scrittura_magazzino(tab_magazzino magazzino[]);
void stampa_operazione_avvenuta(void);
void stampa_operazione_errore(void);
void stampa_magazzino(tab_magazzino magazzino[]);

#endif /* INPUTOUTPUT_H_ */
