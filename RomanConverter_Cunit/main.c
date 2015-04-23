/**\file main.c
 * \brief File main contenente i casi di test
 * \section License
 * Rilasciato sotto licenza GNUv3
 * \author Luciano Faretra
 * \version 0.1 Alpha
 * \date 2015
 */

#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "output.h"
#include "globale.h"
#include "convert.h"
#include "CUnit/Basic.h"

/**
 * Prototipo funzione pulitura_strutture
 */
void pulitura_strutture(string* dirty_data, unsigned int grandezza);

/**
 * Aggiungere tutti i metodi di test per le funzioni da testare
 */
void test_init_world(void) {

	int matrice_campo;

	size_t contatore_stringa = 0;

	/**
	 * Test Case 1: init_value = 0;
	 */
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

	/**
	 * Test Case 3: Numero random -> Input numero 69
	 */
	struttura_contenente_numero_romano = convert(69);

		struttura_comparativa_di_test.numero[contatore_stringa] = 'L';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'X';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'V';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';

		contatore_stringa = 0; //Azzera contatore

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 4: test unita' -> Input numero 1
	 */
	struttura_contenente_numero_romano = convert(1);

		struttura_comparativa_di_test.numero[contatore_stringa] = 'I';

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 5: Numero cinquine -> Input numero 5
	 */
	struttura_contenente_numero_romano = convert(5);

		struttura_comparativa_di_test.numero[contatore_stringa] = 'V';

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 6: Numero decine -> Input numero 10
	 */
	struttura_contenente_numero_romano = convert(10);

		struttura_comparativa_di_test.numero[contatore_stringa] = 'X';

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 7: Numero cinquantine -> Input numero 50
	 */
	struttura_contenente_numero_romano = convert(50);

		struttura_comparativa_di_test.numero[contatore_stringa] = 'L';

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 8: Numero centinaia -> Input numero 100
	 */
	struttura_contenente_numero_romano = convert(100);

		struttura_comparativa_di_test.numero[0] = 'C';

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 9: Numero cinquecentine -> Input numero 500
	 */
	struttura_contenente_numero_romano = convert(500);

		struttura_comparativa_di_test.numero[0] = 'D';

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 10: Numero migliaia -> Input numero 1000
	 */
	struttura_contenente_numero_romano = convert(1000);

		struttura_comparativa_di_test.numero[0] = 'M';

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 11: Caso tipico -> Input numero 4
	 */
	struttura_contenente_numero_romano = convert(4);

		struttura_comparativa_di_test.numero[contatore_stringa] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';

		contatore_stringa = 0; //Azzera contatore

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 12: Caso tipico -> Input numero 9
	 */
	struttura_contenente_numero_romano = convert(9);

		struttura_comparativa_di_test.numero[contatore_stringa] = 'V';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';

		contatore_stringa = 0; //Azzera contatore

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 13: Caso tipico -> Input numero 14
	 */
	struttura_contenente_numero_romano = convert(14);

		struttura_comparativa_di_test.numero[contatore_stringa] = 'X';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';

		contatore_stringa = 0; //Azzera contatore

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 14: Caso tipico -> Input numero 19
	 */
	struttura_contenente_numero_romano = convert(19);

		struttura_comparativa_di_test.numero[contatore_stringa] = 'X';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'V';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';

		contatore_stringa = 0; //Azzera indice

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

	CLEAN_STRUTTURA_CONTENENTE_NUMERO_ROMANO;
	CLEAN_STRUTTURA_COMPARATIVA_DI_TEST;

	/**
	 * Test Case 15: Caso sublimite -> Input numero 4999
	 */
	struttura_contenente_numero_romano = convert(4999);

		struttura_comparativa_di_test.numero[contatore_stringa] = 'M';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'M';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'M';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'M';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'D';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'C';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'C';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'C';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'C';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'L';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'X';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'X';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'X';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'X';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'V';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';
		struttura_comparativa_di_test.numero[contatore_stringa += 1] = 'I';

	CU_ASSERT_STRING_EQUAL( struttura_contenente_numero_romano.numero,
							struttura_comparativa_di_test.numero );
	//Il test confronta le due stringhe e deve avere esito POSITIVO

}

int init_suite_default(void)
{
return 0; //Tutto svolto correttamente
}

int init_suite_clean_default(void)
{
return 0; //Tutto apposto a ferragosto
}

/**
 * \fn void pulitura_strutture(string* dirty_data)
 * La funzione pulisce l'array di dimensione "grandezza" ricevuto in input
 */

void pulitura_strutture(string* dirty_data, unsigned int grandezza)
{
	size_t indice_array = 0;

	do{
		dirty_data->numero[indice_array] = '\0';
		indice_array++;
	}while(indice_array != grandezza);

return;
}

int main (void)
{
	CU_initialize_registry();

	/*Aggiunta di test alla suite registry*/
	CU_pSuite pSuite_A = CU_add_suite("Suite_A", init_suite_default, init_suite_clean_default);

	CU_add_test(pSuite_A, "test output convert()", test_convert);

	/*Esegui tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	CU_cleanup_registry();

	getchar();//Blocca la console fino alla pressione di un tasto
	getchar();

return CU_get_error();
}
