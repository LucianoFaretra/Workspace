/** \file dati_globali.h
 * \brief File contenente le variabili dichiarate globalmente
 * \section License
 * GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 2015
 */

#ifndef DATI_GLOBALI_H_
#define DATI_GLOBALI_H_

/** \def DIMENSIONE_SUBMATRICE 3
 * Dimensione della submatrice da calcolare
 */
#define DIMENSIONE_SUBMATRICE 3

/** \def MAX_CASUALE 100
 * Massimo numero random resituito dalla funzione rand
 */
#define MAX_CASUALE 100

/** \def INSERIMENTO_RIGHE 0
 * Semplice alias, INSERIMENTO_RIGHE corrisponde a 0
 */
#define INSERIMENTO_RIGHE 0

/** \def INSERIMENTO_COLONNE 1
 * Semplice alias, INSERIMENTO_COLONNE corrisponde a 1
 */
#define INSERIMENTO_COLONNE 1

/** \typedef struct dati_submatrice
 * crea un tipo di dato stutturato dati_submatrice
 */

/** \struct dati_submatrice
 * Crea una struttura contenente i dati del reticolo piu grande, quali coordinata X e Y piu la somma dei numeri contenuti
 */
typedef struct{
	/// Coordinata X
	int riga;
	/// Coordinata Y
	int colonna;
	/// Somma dei numeri contenuti
	int somma_valori;
}dati_submatrice;

#endif /* DATI_GLOBALI_H_ */
