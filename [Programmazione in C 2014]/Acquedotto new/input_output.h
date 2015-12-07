/*
 * input_output.h
 *
 *  Created on: 31 ago 2015
 *      Author: ibanez89
 */

#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

unsigned int lettura_dati(FILE *file_dati, float consumi_unita[]);
void totale_unita_abitative(float consumi_unita[], unsigned int numero_unita);

#endif /* INPUT_OUTPUT_H_ */
