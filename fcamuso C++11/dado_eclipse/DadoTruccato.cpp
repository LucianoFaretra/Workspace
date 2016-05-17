/*
 * DadoTruccato.cpp
 *
 *  Created on: 26 gen 2016
 *      Author: ibanez89
 */

#include "DadoTruccato.h"

DadoTruccato::DadoTruccato() {
	//livelloTrucco = 0;
	//facciaTruccata = 0;

}

DadoTruccato::DadoTruccato(int numeroFacce, int facciaDaTruccare,int livelloTrucco) : Dado(numeroFacce)
//E' necessatio ereditare il costruttore dalla classe se non esiste un costruttore vuoto di default
{


}


DadoTruccato::~DadoTruccato() {

}

DadoTruccato& DadoTruccato::operator=(const DadoTruccato& rhs){

	if(this==&rhs) return *(this);

	return (*this);
}

