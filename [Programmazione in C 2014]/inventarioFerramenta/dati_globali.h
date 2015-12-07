/**
 * \file dati_globali.h
 * File contenente i dati globali del programma
 */

#ifndef DATI_GLOBALI_H_
#define DATI_GLOBALI_H_

/**
 * \def EXIT 5
 * alias per il valore EXIT
 */
#define EXIT 5
/**
 * \def MINIMOPROGRESSIVO
 * numero minimo progressivo accettato
 */
#define MINIMOPROGRESSIVO 1
/**
 * \def DIMENISIONEMAGAZZINO
 * diensione massima magazzino
 */
#define DIMENISIONEMAGAZZINO 100

/**
 * \typedef struct tab_magazzino
 * crea un tipo di nome tab_magazzino
 */

/**
 * \struct tab_magazzino
 * Struttura contenente le informazioni di un record del magazzino
 */
typedef struct{
	unsigned int record;
	char nomeProdotto[30];
	unsigned int quantita;
	float prezzo;
}tab_magazzino;


#endif /* DATI_GLOBALI_H_ */
