#include "Initializr.h"

#include <iostream>
#include <vector>

Topo::Topo() : gambeNormali(4), gambeAttuali(3){}
//Topo::Topo():gambeNormali(4) { gambeAttuali = 3;}


unsigned int Topo::getGambeAttuali(){ return gambeAttuali; }
unsigned int Topo::getGambeNormali(){ return gambeNormali; }
