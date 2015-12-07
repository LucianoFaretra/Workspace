/*
 * matrice.cpp
 *
 *  Created on: 30/ott/2015
 *      Author: studente
 */

#include <iostream>
#include <stdlib.h>
#include "headers/matrice.hh"
using namespace std;

	// costruttore
	matrice::matrice(int r, int c, tipoelem inizializzatore) {
	colonne = c;
	righe = r;
	// allocazione dinamica della matrice
	int indice_righe = 0;
	int indice_colonne = 0;
	elementi = new matrice::tipoelem*[righe];
	for (indice_righe = 0; indice_righe < righe; indice_righe++)
		elementi[indice_righe] = new tipoelem[colonne];

	// inizializzazione degli elementi
	indice_righe = 0;
	while (indice_righe < righe) {
		indice_colonne = 0;
		while (indice_colonne < colonne) {
			scrivimatrice(indice_righe, indice_colonne, inizializzatore);
			indice_colonne++;
		}
		indice_righe++;
	}
}

void matrice::scrivimatrice(int righe, int colonne, tipoelem valore){

	elementi[righe][colonne] = valore;

return;
}

matrice::tipoelem matrice::leggimatrice(int righe, int colonne){
	return (matrice::elementi[righe][colonne]);
}

matrice::~matrice(void) {
	delete elementi;
}

void matrice::stampa(){
	indice_righe = 0;
	while(indice_righe < righe){
		indice_colonne = 0;
		while(indice_colonne < colonne){
			cout << matrice::leggimatrice(indice_righe, indice_colonne) << " ";
			indice_colonne++;
		}
		cout << endl;
		indice_righe++;
	}

	return;
}

void matrice::prodottoScalare(matrice::tipoelem scalare){

	indice_righe = 0;
	while(indice_righe < righe){
		indice_colonne = 0;
		while(indice_colonne < colonne){
			matrice::scrivimatrice(indice_righe, indice_colonne, (matrice::leggimatrice(indice_righe, indice_colonne) * scalare));
			indice_colonne++;
		}
		indice_righe++;
	}
	return;
}

matrice matrice::matriceTrasposta(){
	matrice T(colonne, righe);

	indice_righe = 0;
	while(indice_righe < righe){
		indice_colonne = 0;
		while(indice_colonne < colonne){
			T.scrivimatrice(indice_righe, indice_colonne, matrice::leggimatrice(indice_colonne, indice_righe));
			indice_colonne++;
		}
		indice_righe++;
	}

	return (T);
}

void matrice::matriceProdotto(matrice M){

	if(righe == colonne){
		indice_righe = 0;
		while(indice_righe < righe){
			indice_colonne = 0;
			while(indice_colonne < colonne){
				matrice::scrivimatrice(indice_righe, indice_colonne, (matrice::leggimatrice(indice_righe, indice_colonne) * M.leggimatrice(indice_righe, indice_colonne)));
				indice_colonne++;
			}
			indice_righe++;
		}
	}
	else{
		cout << "Attenzione, non è possibile moltiplicare una matrice con numero di righe e colonne diverso" << endl;
	}
	return;
}

void matrice::generaRandom(){
	indice_righe = 0;
	while(indice_righe < righe){
		indice_colonne = 0;
		while(indice_colonne < colonne){
			matrice::scrivimatrice(indice_righe, indice_colonne, (random() % 100));
			indice_colonne++;
		}
		indice_righe++;
	}
	return;
}

/* Copiato*/
matrice &matrice::operator=(const matrice &m){
	// evita gli auto assegnamenti
	if (this != &m){
		int i,j;
		if (colonne != m.colonne || righe != m.righe){
			this->~matrice();
			colonne = m.colonne;
			righe = m.righe;
			elementi = new tipoelem* [righe];
			for (i=0; i < righe; i++)
				elementi[i] = new tipoelem[colonne];
		}
		for (i=0;i<righe;i++)
			for (j=0;j<colonne;j++)
				elementi[i][j] = m.elementi[i][j];
	}
	return (*this);
}
/* Copiato*/
