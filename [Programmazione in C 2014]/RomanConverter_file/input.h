/*
 * input.h
 *
 *  Created on: 27/mar/2015
 *      Author: ibanez89
 */

#ifndef INPUT_H_
#define INPUT_H_
#include "globale.h"

int lettura_numero(void);

tab_conversione lettura_tabella_conversione( FILE* tabella_conversione );
unsigned int lettura_massimo_numero_calcolabile( FILE* massimo_numero_calcolabile );


#endif /* INPUT_H_ */
