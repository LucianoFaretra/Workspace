/*
 * matrice.h
 *
 *  Created on: 19 dic 2015
 *      Author: ibanez89
 */

#ifndef MATRICE_H_
#define MATRICE_H_

typedef double tipoelem;

class matrice {
  public:
    matrice(int, int, tipoelem inizializzatore = 0); /* costruttore */
    ~matrice(void);
    tipoelem leggiMatrice(int, int);
    void scriviMatrice(int, int, tipoelem);
    void prodottoScalare(tipoelem);
    matrice matriceTrasposta(void);
    matrice matriceProdotto(matrice& M);
    matrice& operator=(const matrice&);
    void rand(void);
    void stampa(void);
  private:
    int righe;
    int colonne;
    tipoelem **elementi;
};

#endif /* MATRICE_H_ */
