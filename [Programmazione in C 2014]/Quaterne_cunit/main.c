#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dati_globali.h"
#include "output.h"
#include "elaborazione.h"
#include "input.h"
#include "CUnit/Basic.h"

void test_media(void);
int init_suite_default(void);
int init_suite_clean_default(void);


void test_media(void){
	dati_matrice matrice;
	float media;
	matrice.numero_righe = 4;
	matrice.numero_colonne = 4;
	alloca_matrice(&matrice);

	int matrice2[4][4] = {	{1, 2, 2, 2},
							{2, 2, 2, 2},
							{2, 2, 2, 2},
							{2, 2, 2, 3}
											};
	size_t indice_righe;
	size_t indice_colonne;




	if(controllo_matrice(matrice.matrice) != 0){
		indice_righe = 0;
		while(indice_righe < matrice.numero_righe){
			indice_colonne = 0;
			while(indice_colonne < matrice.numero_colonne){
				matrice.matrice[indice_righe][indice_colonne] = matrice2[indice_righe][indice_colonne];
				indice_colonne++;
			}
			indice_righe++;
		}
	}

		media = media_elementi_vettore(matrice);

		CU_ASSERT_EQUAL(media, 2);

return;
}

void test_matrice_allocata(void)
{
	dati_matrice matrice;
	matrice.numero_righe = 4;
	matrice.numero_colonne = 4;
	int indice_righe;
	int indice_colonne;
	alloca_matrice(&matrice);

	indice_righe = 0;
	while(indice_righe < matrice.numero_righe){
		indice_colonne = 0;
		while(indice_colonne < matrice.numero_colonne){
			CU_ASSERT_PTR_NOT_NULL(&matrice.matrice[indice_righe][indice_colonne]);
			indice_colonne++;
		}
		indice_righe++;
	}

return;
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

	CU_add_test(pSuite_A, "test output convert()", test_media);
	CU_add_test(pSuite_B, "test allocazione matrice", test_matrice_allocata);


	/*Esegui tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	CU_cleanup_registry();

return (CU_get_error());
}

