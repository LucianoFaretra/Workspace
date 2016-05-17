/*
 * TestMatrice.cpp
 *
 *  Created on: 30/ott/2015
 *      Author: studente
 */

#include <iostream>
#include "matrice.h"

int main(void) {
	using namespace std;

	int numero_righe = 2;
	int numero_colonne = 2;
	tipoelem scalare;
	matrice A(numero_righe, numero_colonne);
	matrice T(numero_colonne, numero_righe);
	matrice M(numero_righe, numero_colonne);

	//srand(time(NULL));//inizializza il seme per i numeri generati speudo-casuali

	cout << "stampa matrice A" << endl;
	A.generaRandom();
	A.stampa();

	cout << "inserisci uno scalare: ";
	cin >> scalare;
	cout << "stampa matrice per uno scalare:" << scalare << endl;
	A.prodottoScalare(scalare);
	A.stampa();

	cout << "stampa la matrice trasposta:" << endl;
	T = A.matriceTrasposta();
	T.stampa();

	cout << "stampa matrice A" << endl;
	A.stampa();
	cout << "stampa matrice M" << endl;
	M.generaRandom();
	M.stampa();
	cout << "stampa la matrice prodotto:" << endl;
	A.matriceProdotto(M);
	A.stampa();

	return (0);
}
