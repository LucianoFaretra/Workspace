/** \file main.h
 * 	\author Luciano Faretra
 * 	\date 2015
 * 	\version 0.1
 */
#include <stdlib.h>
#include <stdio.h>
#include "inputOutput.h"
#include "elaborazione.h"
#include "dati_globali.h"
#include "string.h"
#include "CUnit/Basic.h"

/**
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */
void test_elimina_record_esistente (void) {
	tab_magazzino magazzino[DIMENISIONEMAGAZZINO] = {{0, " ", 0, 0}};
	char numeroprod[30] = "casa";

	magazzino[1].record = 30;
	strcpy(magazzino[1].nomeProdotto, numeroprod);
	magazzino[1].quantita = 20;
	magazzino[1].prezzo = 45.60;

	elimina_record(magazzino, 30);
	CU_ASSERT_EQUAL(magazzino[1].record, 0);
}
void test_elimina_record_non_esistente (void) {
	tab_magazzino magazzino[DIMENISIONEMAGAZZINO] = {{0, " ", 0, 0}};
	char numeroprod[30] = "casa";

	magazzino[1].record = 30;
	strcpy(magazzino[1].nomeProdotto, numeroprod);
	magazzino[1].quantita = 20;
	magazzino[1].prezzo = 45.60;

	elimina_record(magazzino, 20);
	CU_ASSERT_EQUAL(magazzino[1].record, 30);
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
	CU_pSuite pSuite_B = CU_add_suite("Suite_B", init_suite_default, init_suite_clean_default);

	CU_add_test(pSuite_A, "test cancellazione record esistente", test_elimina_record_esistente);
	CU_add_test(pSuite_B, "test cancellazione record non esistente", test_elimina_record_non_esistente);

	/*Esegui tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	CU_cleanup_registry();

return (CU_get_error());
}
