/**\file globale.h
 * \brief File header conentenente le dichiarazioni globali
 * \author Luciano Faretra
 * \version 0.1 Alpha
 * \date 2015
 */

#ifndef GLOBALE_H_
#define GLOBALE_H_

/** \def ESTENSIONE_MAX_NUMERO_ROMANO
 * Lunghezza massima di caratteri per l'array di ti caratteri
 */
#define ESTENSIONE_MAX_NUMERO_ROMANO 20

/** \def MIN_CONVERTIBILE
 * Numero decimale più piccolo convertibile in Romano semplice
 */
#define MIN_CONVERTIBILE 1

/** \def NUMERO_MAX_SIMBOLI_INPUT
 * Numero di inserimenti massimi nella tabella di conversione
 */
#define NUMERO_MAX_SIMBOLI_INPUT 15

/** \def CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO
 * Crea un alias per facilitare la comprensione del codice
 */
#define CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO pulitura_strutture(&struttura_contenente_numero_romano, ESTENSIONE_MAX_NUMERO_ROMANO)

/** \def CLEAN_STRUTTURA_COMPARATIVA_DI_TEST
 * Crea un alias per facilitare la comprensione del codice
 */
#define CLEAN_STRUTTURA_COMPARATIVA_DI_TEST pulitura_strutture(&struttura_comparativa_di_test, ESTENSIONE_MAX_NUMERO_ROMANO)

/** \typedef char stringa[DIM]
 * 	Crea un alias per il tipo char stringa[DIM]
 * 	Il tipo stringa consiste in una stringa di massimo 20 caratteri
 */
typedef char stringa[ESTENSIONE_MAX_NUMERO_ROMANO];


/** \struct string
 * Struttura contente una stringa
 * E' risultato necessario dichiarare una struttura contenente una struinga,
 * in modo da poter passare la stringa 'array di caratteri' per valore,
 * non per indirizzo
 */
typedef struct{
	stringa numero; //Per poter accedere alla stringa di caratteri e' necessario accedere tramite il descritto numero
}string;

/** \tab_conversione
 * La tabella contiene il simbolo decimale "unita"
 * il simbolo tradotto "simbolo"
 * e quanti simboli sono presenti in tabella
 */
typedef struct{
	unsigned int unita[NUMERO_MAX_SIMBOLI_INPUT];
	char simbolo[NUMERO_MAX_SIMBOLI_INPUT];
	unsigned int num_simboli;
}tab_conversione;

#endif /* GLOBALE_H_ */
