/*
 * TestMatrice.cpp
 *
 *  Created on: 19 dic 2015
 *      Author: ibanez89
 */

#include <iostream>
#include "matrice.h"

int main(void){

	matrice A(5,5) = {{0,1,0,1,0},{0,0,0,0,1},{1,1,0,0,0},{0,0,0,0,1},{0,0,0,0,0}};
	matrice T(5,5) = {{0,1,0,1,0},{0,0,0,0,1},{1,1,0,0,0},{0,0,0,0,1},{0,0,0,0,0}};

	/*
	A.rand();
	std::cout <<"Stampa A" << std::endl;
	A.stampa();
	std::cout << "Stampa Trasposta T" << std::endl;
	T = A.matriceTrasposta();
	T.stampa();

	std::cout << std::endl;

    std::cout << "Stampa B" << std::endl;
	matrice B(4,4);
	B.stampa();
	std::cout << "Stampa copia t in b" << std::endl;
	B = T;
	B.stampa();
	*/
	return (0);
}

