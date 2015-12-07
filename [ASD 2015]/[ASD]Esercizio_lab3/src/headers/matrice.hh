/*
 * matrice.h
 *
 *  Created on: 30/ott/2015
 *      Author: studente
 */

#ifndef MATRICE_HH_
#define MATRICE_HH_

class matrice {
  public:
	typedef double tipoelem;
    matrice(int, int,tipoelem inizializzatore=0); /* costruttore */
    ~matrice();
    tipoelem leggimatrice(int, int);
    void scrivimatrice(int, int, tipoelem);
    void stampa(void);
    void prodottoScalare(tipoelem scalare);
    matrice matriceTrasposta();
    void matriceProdotto(matrice M);
    void generaRandom();
    matrice& operator=(const matrice &m);
    int indice_righe;
    int indice_colonne;
  private:
    int righe;
    int colonne;
    tipoelem **elementi;
};



#endif /* MATRICE_H_ */
