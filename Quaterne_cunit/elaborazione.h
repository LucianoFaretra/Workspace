#ifndef ELABORAZIONE_H_
#define ELABORAZIONE_H_

int genera_numero_casuale(void);
void alloca_matrice(dati_matrice *matrice);
int controllo_matrice(int **matrice);
void riempi_matrice(dati_matrice *matrice);
int media_elementi_vettore(dati_matrice matrice);
int genera_quaterna(dati_matrice matrice, int quaterna[]);
int arrotondamento(int subtotale, unsigned int numero_elementi);
int prodotto_quaterna(int quaterna[]);
int stampa_quaterna_se_idonea(int quaterna[], int prodotto_quaterna, int media_elementi_vettore);

#endif /* ELABORAZIONE_H_ */
