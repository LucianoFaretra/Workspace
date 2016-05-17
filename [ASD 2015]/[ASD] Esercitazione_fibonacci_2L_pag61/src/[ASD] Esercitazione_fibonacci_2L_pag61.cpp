#include <iostream>
#include <vector>
#include "Fibonacci.h"

int main()
{
    Fibonacci f;
    unsigned int numero;
    std::cout << "inserisci il numero di fibonacci da generare >: ";
    std::cin >> numero;


    std::cout << std::endl << "ecco il numero cercato >: " << f.value(numero) << std::endl;

    return 0;
}
