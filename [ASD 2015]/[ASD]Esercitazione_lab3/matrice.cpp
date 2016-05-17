/*
 * matrice.cpp
 *
 *  Created on: 19 dic 2015
 *      Author: ibanez89
 */

#include "matrice.h"
#include <stdlib.h>
#include <iostream>
// costruttore
matrice::matrice(int r, int c, tipoelem inizializzatore){
  this->colonne = c;
  this->righe = r;

  // allocazione dinamica della matrice
  elementi = new tipoelem*[righe];
  for (auto i=0; i!=righe; i++)
	  this->elementi[i] = new tipoelem[colonne];

  // inizializzazione degli elementi
  for (auto i=0; i!=righe; i++)
	  for(auto j=0; j!=colonne; j++)
		  this->elementi[i][j] = inizializzatore;
}

matrice::~matrice(void){
	for(auto j=0;j<righe;++j){
		delete[] this->elementi[j];
	}
	delete[] this->elementi;
}

tipoelem matrice::leggiMatrice(int i, int j){
	return elementi[i][j];
}

void matrice::scriviMatrice(int i, int j, tipoelem scrittura){
	elementi[i][j] = scrittura;
	return;
}

void matrice::prodottoScalare(tipoelem scalare){
	for(auto i = 0; i<righe;i++)
		for(auto j = 0; j<colonne;j++)
			elementi[i][j]=elementi[i][j]*scalare;
	return;
}

matrice matrice::matriceTrasposta(void){
	matrice trasposta(colonne, righe);

	for(auto i=0; i<righe;i++)
		for(auto j=0; j<colonne;j++)
			trasposta.scriviMatrice(j,i,leggiMatrice(i,j));
	return trasposta;
}

matrice matrice::matriceProdotto(matrice& M){
	matrice prodotto(righe, colonne);

	for(auto i=0; i<righe;i++)
		for(auto j=0; j<colonne;j++)
			prodotto.scriviMatrice(i,j,(matrice::leggiMatrice(i,j)*M.leggiMatrice(i,j)));
	return prodotto;
}

matrice& matrice::operator=(const matrice &m){
	if(this != &m){
		if(colonne != m.colonne || righe != m.righe){
		//his->~matrice();
		matrice temp(m);
		std::swap(temp.righe, righe);
		std::swap(temp.colonne, colonne);
		std::swap(temp.elementi, elementi);
		}
	}
	return *this;
	/*
	if(this != &m){
		if(colonne != m.colonne || righe != m.righe){
			this->~matrice();
			this->righe = m.righe;
			this->colonne = m.colonne;
			matrice(righe,colonne);
		}
		for(auto i=0;i!=righe;i++)
			for(auto j=0;j!=colonne;j++)
				elementi[i][j] = m.elementi[i][j];
	}
	return (*this);*/

}

void matrice::rand(void){
	for(auto i=0; i<righe;i++)
		for(auto j=0;j<colonne;j++)
			matrice::scriviMatrice(i,j,(random() % 100));
	return;
}

void matrice::stampa(void){
	for(auto i=0; i<righe;i++){
		for(auto j=0; j<colonne;j++)
			std::cout << elementi[i][j] << " ";
	std::cout << std::endl;
	}
}
