/** \file elaborazione.c
 * \brief A Documented file.
 * File contenente le variabili globali.
 * \section License
 * Rilasciato sotto licenza GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 04.2015
 */

#ifndef HEADERS_DATI_GLOBALI_H_
#define HEADERS_DATI_GLOBALI_H_

/** \def MAX_RIGHE
 * Numero massimo di righe consentite nell'array
 */
#define MAX_RIGHE 5

/** \def MAX_COLONNE
 * Numero massimo di colonne consentite nell'array
 */
#define MAX_COLONNE 5

/** \def INIZIALIZZATORE
 * Valore utilizzato per inizializzare l'array
 */
#define INIZIALIZZATORE 0

/** \def CASELLA_PIENA
 * Valore usato nell'array per indicare la casella piena
 */
#define CASELLA_PIENA 1

/** \def CASELLA_VUOTA
 * Valore usato nell'array per indicare la casella vuota
 */
#define CASELLA_VUOTA 0


/** \def CASELLA_PIENA
 * Valore usato nell'array per indicare la casella piena
 */

/** \var world[MAX_RIGHE][MAX_COLONNE]
 * Array contenente il mondo di gioco
 */
int world[MAX_RIGHE][MAX_COLONNE];

/** \var world_temp[MAX_RIGHE][MAX_COLONNE]
 * Array contenente il mondo di gioco temporaneo
 */
int world_temp[MAX_RIGHE][MAX_COLONNE];

#endif /* HEADERS_DATI_GLOBALI_H_ */
