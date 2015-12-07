/**
 * \file main.c
 * File contenente le funzioni di main
 * \author Luciano faretra
 * \date 2015
 * \ver 1.0
 */

#include <stdlib.h>
#include <stdio.h>
#include "inputOutput.h"
#include "elaborazione.h"
#include "CUnit/Basic.h"

/**
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */

void test_trova_targhet (void) {

	int j = 2;
	int targhet = 4;

	stampa_targhet(trova_targhet(lettura_file_testo(), j, targhet));
	CU_ASSERT_EQUAL(trova_targhet(lettura_file_testo(), j, targhet), 2);

	/*j = 1;
	targhet = 2;

	CU_ASSERT_EQUAL(trova_targhet(lettura_file_testo(), j, targhet), 1);

	j = 1;
	targhet = 6;

	CU_ASSERT_EQUAL(trova_targhet(lettura_file_testo(), j, targhet), 3);

	j = 2;
	targhet = 0;

	CU_ASSERT_EQUAL(trova_targhet(lettura_file_testo(), j, targhet), 4);

	j = 4;
	targhet = 7;

	CU_ASSERT_EQUAL(trova_targhet(lettura_file_testo(), j, targhet), 3);*/
}

int init_suite_default(void)
{
return (0); //Tutto svolto correttamente
}


int init_suite_clean_default(void)
{
return (0); //Tutto apposto a ferragosto
}

int main (void)
{
	CU_initialize_registry();

	/*Aggiunta di test alla suite registry*/
	CU_pSuite pSuite_A = CU_add_suite("Suite_A", init_suite_default, init_suite_clean_default);

	CU_add_test(pSuite_A, "test cancellazione record esistente", test_trova_targhet);

	/*Esegui tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	CU_cleanup_registry();

return (CU_get_error());
}

