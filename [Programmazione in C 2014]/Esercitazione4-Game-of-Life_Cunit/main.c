/** \file main.c
 * \brief A Documented file.
 * File contenente le istruzioni per eseguire il ciclo del programma.
 * \section License
 * Rilasciato sotto licenza GNU v3
 * \author Luciano Faretra
 * \version 0.1
 * \date 04.2015
 */

#include <stdlib.h>
#include <stdio.h>
#include "dati_globali.h"
#include "output.h"
#include "elaborazione.h"
#include "input.h"
#include "CUnit/Basic.h"

void test_game (void) {

	/**
	 * Test Case 1: Caso limite-> Input numero 0 (numero non valido)
	 */
	pulitura_array(world);
	pulitura(world_temp);
	struttura_contenente_numero_romano = convert(0);
	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO, info per debugging, contenuto finale \0

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO; //Pulisce struttura_contenente_numero_romano
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST; //Pulisce struttura_comparativa_di_test

	/**
	 * Test Case 2: Caso limite -> Input numero 5000
	 */
	struttura_contenente_numero_romano = convert(5000);
	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO, info per debugging, contenuto finale \0

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

}

int init_suite_default(void)
{
return (0); //Tutto svolto correttamente
}

int init_suite_clean_default(void)
{
return (0); //Tutto apposto a ferragosto
}

/**
 * \fn void pulitura_strutture(string* dirty_data)
 * La funzione pulisce l'array di dimensione "grandezza" ricevuto in input
 */

void pulitura_array(int matrice[][MAX_COLONNE])
{
	size_t indice_righe;
	size_t indice_colonne;

	indice_righe = 0;
	while(indice_righe < MAX_RIGHE){
		indice_colonne = 0;
		while(indice_colonne < MAX_COLONNE){
			matrice[indice_righe][indice_colonne] = '\0';
			indice_colonne++;
		}
		indice_righe++;
	}
return;
}

int main(void)
{
	CU_initialize_registry();

	/*Aggiunta di test alla suite registry*/
	CU_pSuite pSuite_A = CU_add_suite("Suite_A", init_suite_default, init_suite_clean_default);

	CU_add_test(pSuite_A, "test output convert()", test_game);

	/*Esegui tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	CU_cleanup_registry();

	getchar();//Blocca la console fino alla pressione di un tasto
	getchar();

}
