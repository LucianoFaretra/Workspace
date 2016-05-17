#include <iostream>
#include <vector>
#include <string>
#include "Zoo.h"

Zoo::Zoo() : test(1,1), number(0), name("none") {}
void Zoo::setAnimalName(std::string setName){Zoo::name = setName;}
void Zoo::setAnimalNumber(unsigned int setNumber) {Zoo::number = setNumber;}

std::string Zoo::getAnimalName() {return Zoo::name;}
unsigned int Zoo::getAnimalNumber() {return Zoo::number;}
unsigned int Zoo::getVector(){return Zoo::test[0];};
