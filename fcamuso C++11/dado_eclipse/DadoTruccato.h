/*
 * DadoTruccato.h
 *
 *  Created on: 26 gen 2016
 *      Author: ibanez89
 */

#ifndef DADOTRUCCATO_H_
#define DADOTRUCCATO_H_

#include "classDado.hh"

class DadoTruccato: public Dado {
public:
	DadoTruccato();
	DadoTruccato(int numeroFacce, int facciaDaTruccare,int livelloTrucco);
	~DadoTruccato();
	DadoTruccato(const DadoTruccato& other);
	DadoTruccato& operator=(const DadoTruccato& other);
	int GetfacciaTruccata() {return facciaTruccata;}
	void SetfacciaTruccata(int val) {facciaTruccata = val;}
	int GetlivelloTrucco() {return livelloTrucco;}
	void SetlivelloTrucco(int val) {livelloTrucco = val;}

private:
	int facciaTruccata;
	int livelloTrucco;
};

#endif /* DADOTRUCCATO_H_ */
