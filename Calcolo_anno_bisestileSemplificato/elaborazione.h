/*
 * elaborazione.h
 *
 *  Created on: 15/lug/2015
 *      Author: studente
 */

#ifndef ELABORAZIONE_H_
#define ELABORAZIONE_H_

int giorni_trascorsi(int giorno, int mese, int anno);
int giorno_non_valido(int giorno);
int mese_non_valido(int mese);
int anno_non_valido(int anno);
int date_inesistenti(int giorno, int mese, int anno);
int anno_bisestile(int giorno, int mese, int anno);
int conta_giorni(int giorno, int mese, int anno, int calendario[]);

#endif /* ELABORAZIONE_H_ */
