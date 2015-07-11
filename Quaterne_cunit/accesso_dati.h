#ifndef ACCESSO_DATI_H_
#define ACCESSO_DATI_H_

int lettura_matrice_doppia(int **matrice, unsigned int numero_riga, unsigned int numero_colonna);
void scrittura_matrice_doppia(int **matrice, unsigned int numero_riga, unsigned int numero_colonna, int valore);
int lettura_matrice(int matrice[], unsigned int numero_posizione);
void scrittura_matrice(int *matrice, unsigned int numero_posizione, int valore);

#endif /* ACCESSO_DATI_H_ */
