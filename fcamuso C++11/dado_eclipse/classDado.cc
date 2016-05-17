#include "classDado.hh"
#include <cstdlib>
#include <ctime>
#include <iostream>

const int facceStandard = 6;
const int dataQuantity = 10;
int Dado::numeroDadi = 0;

Dado::Dado(int nFacce){
    srand(static_cast<unsigned int>(time(0)));
    if(nFacce > 0)
        Dado::numeroFacce = nFacce;
    else
        Dado::numeroFacce = facceStandard;
    Dado::numeroDadi++;
    valoreDado = lancioDado();
    dati = new int[dataQuantity];
    //std::cout << "Puntatore dado con " << numeroFacce << " facce: " << dati << std::endl;
    for(int i = 0;i!=dataQuantity;i++) dati[i] = i;
}

Dado::~Dado(){
    numeroDadi--;
    //std::cout << "Chiamo delete sul puntatore " << dati << std::endl;
    delete[] dati;
    dati = nullptr;
}

Dado::Dado(const Dado& d){//Copy constructor
	numeroFacce = d.numeroFacce;
	valoreDado = d.valoreDado;
	dati = new int[dataQuantity];
	for(int i = 0;i!=dataQuantity;i++) dati[i] = d.dati[i];
	Dado::numeroDadi++;
}

Dado::Dado() : Dado::Dado(6) { } //Costruttore delegato al dado

int Dado::lancioDado(){
		valoreDado = (rand() % numeroFacce) + 1;
return valoreDado;
}

void Dado::setValoreDado(int nuovoValore){
    if(nuovoValore >= 0 && nuovoValore <= numeroFacce)
        valoreDado = nuovoValore;
    return;
}

Dado* Dado::Clona(){
    Dado* copia = new Dado(numeroFacce);
    copia->setValoreDado(valoreDado);

    return copia;
}

void Dado::stampaDati(){
	for(int i=0;i!=dataQuantity;i++) std::cout << dati[i] << std::endl;
}

/*Dado& Dado::operator=(const Dado& original){

	Dado temp(original);
	std::swap(temp.numeroFacce, numeroFacce);
	std::swap(temp.valoreDado, valoreDado);
	std::swap(temp.dati, dati);

	return (*this);
}
*/
Dado& Dado::operator=(const Dado& original){

	if(this == &original) return *this;
	numeroFacce = original.numeroFacce;
	valoreDado = original.valoreDado;
	for(int i=0;i!=dataQuantity;i++) dati[i]= original.dati[i];

	return (*this);
}
