#include <stdlib.h>
#include <stdio.h>
#include "datiGlobali.h"
#include "inputOutput.h"
#include "elaborazione.h"
#include "CUnit/Basic.h"

/**
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */
void test_elimina_record_esistente (void) {

	int giorno;
	int mese;
	int anno;
	int giorni;

	giorno = 10;
	mese = 3;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);

	CU_ASSERT_EQUAL(giorni, 69);

	//CASO 2
	giorno = 10;
	mese = 3;
	anno = 2000;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, 70);

	//CASO 3
	giorno = 1;
	mese = 1;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, 1);

	//CASO 4
	giorno = 31;
	mese = 12;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, 365);

	//CASO 5
	giorno = 31;
	mese = 12;
	anno = 2000;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, 366);

	//CASO 6
	giorno = 29;
	mese = 2;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, 0);

	//CASO 7
	giorno = 30;
	mese = 2;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, -4);

	//CASO 8
	giorno = 31;
	mese = 2;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, -4);

	//CASO 9
	giorno = 31;
	mese = 4;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, -4);

	//CASO 10
	giorno = 31;
	mese = 6;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, -4);

	//CASO 11
	giorno = 31;
	mese = 9;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, -4);

	//CASO 12
	giorno = 31;
	mese = 11;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, -4);

	//CASO 13
	giorno = 0;
	mese = 2;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, -1);

	//CASO 14
	giorno = 2;
	mese = 0;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, -2);

	//CASO 15
	giorno = 2;
	mese = 13;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, -2);

	//CASO 16
	giorno = 2;
	mese = 12;
	anno = -1;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, -3);

	//CASO 17
	giorno = 29;
	mese = 2;
	anno = 2015;

	giorni = giorni_trascorsi(giorno, mese, anno);
	CU_ASSERT_EQUAL(giorni, 0);
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

	CU_add_test(pSuite_A, "test funzionalita calcolo giorni", test_elimina_record_esistente);

	/*Esegui tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	CU_cleanup_registry();

return (CU_get_error());
}
