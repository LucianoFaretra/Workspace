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
void convert_1000(int* numero, string* numero_romano, unsigned int* contatore_stringa);
void convert_500(int* numero, string* numero_romano, unsigned int* contatore_stringa);
void convert_100(int* numero, string* numero_romano, unsigned int* contatore_stringa);
void convert_50(int* numero, string* numero_romano, unsigned int* contatore_stringa);
void convert_10(int* numero, string* numero_romano, unsigned int* contatore_stringa);
void convert_5(int* numero, string* numero_romano, unsigned int* contatore_stringa);
void convert_1(int* numero, string* numero_romano, unsigned int* contatore_stringa);

#endif /* CONVERT_H_ */
