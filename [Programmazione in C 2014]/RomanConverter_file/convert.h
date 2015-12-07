/**\file convert.h
 * \brief File header contenente i prototipi del file convert.c
 * \author Luciano Faretra
 * \version 0.1 Alpha
 * \date 2015
 */

#ifndef CONVERT_H_
#define CONVERT_H_
#include "globale.h"

string convert(int numero);
void convert_unita(int* numero, string* numero_romano, unsigned int* contatore_stringa, int unita, char simbolo);
#endif /* CONVERT_H_ */
