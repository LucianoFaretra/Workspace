#include "classDado.h"
#include <cstdlib>
#include <ctime>

const int facceStandard = 6;
int Dado::numeroDadi = 0;

Dado::Dado(int nFacce){
    srand(static_cast<unsigned int>(time(0)));
    if(nFacce > 0)
        Dado::numeroFacce = nFacce;
    else
        Dado::numeroFacce = facceStandard;
    Dado::numeroDadi++;
    valoreDado = lancioDado();
}

Dado::~Dado(){
    numeroDadi--;
}

Dado::Dado() : Dado::Dado(6) { } //Costruttore delegato al dado

int Dado::lancioDado(){
    valoreDado = (rand() % numeroFacce) + 1;
return valoreDado;
}

int Dado::getValoreDado(){
    return valoreDado;
}

void Dado::setValoreDado(int nuovoValore){
    if(nuovoValore >= 0 && nuovoValore <= numeroFacce)
        valoreDado = nuovoValore;
    return;
}

int Dado::getNumeroDadi(){
    return numeroDadi;
}

Dado* Dado::Clona(){
    Dado* copia = new Dado(numeroFacce);
    copia->setValoreDado(valoreDado);

    return copia;
}
