#ifndef DATI_GLOBALI_H_
#define DATI_GLOBALI_H_

#define RANGE_NUMERI_CASUALI 200
#define QUATERNA 4

#define INSERIRE_RIGA 0
#define INSERIRE_COLONNA 1
#define INPUT_ERRATO 2
#define IMPOSSIBILE_ALLOCARE 3
#define MESSAGGIO_QUATERNA 4
#define NESSUNA_QUATERNA 5

typedef struct{
	int **matrice;
	unsigned int numero_righe;
	unsigned int numero_colonne;
}dati_matrice;

#endif /* DATI_GLOBALI_H_ */
