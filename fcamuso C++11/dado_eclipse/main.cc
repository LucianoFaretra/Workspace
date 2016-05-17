#include <iostream>
#include "DadoTruccato.h"
#include "classDado.hh"
#include "gioco.hh"
#include <time.h>

using namespace std;

int main()
{

	DadoTruccato dadoTruccato1;

	cout << "il dado truccato ha " << dadoTruccato1.getNumeroFacce() << " facce" << endl;

/*
	Dado dado1;
	dado1.setValoreDado(1);

	Dado dado2(7);
	dado2.setValoreDado(2);


	clock_t start,end;
	double tempo;
	start=clock();
	//

	for(int i=0;i<1000;i++){
	dado1 = dado2;
	}
	//
	end=clock();
	tempo=((double)(end-start))/CLOCKS_PER_SEC;
	cout << tempo << endl;
	//
	*/
/*
    Gioco g1("Gioco dell'oca", 14.5, 4, dado1, dado2);
    dado1.stampaDati();

    cout << "Ecco il primo lancio primo dado" << " " << dado1.lancioDado() << endl;
    cout << "Ecco il primo lancio secondo dado" << " " << dado2.lancioDado() << endl;

    cout << "Numero dadi online" << " " << Dado::getNumeroDadi() <<endl;

    cout << "Ecco il secondo lancio primo dado" << " " << dado1.lancioDado() << endl;
    cout << "Ecco il secondo lancio secondo dado" << " " << dado2.lancioDado() << endl;

    cout << "Test di clonazione, il contenudo del dado da clonare e':" << " " << dado1.getValoreDado() << endl;

    Dado* dado4 = dado1.Clona();

    cout << "Valore dado clonato:" << " " << dado4->getValoreDado() << endl;
    delete dado4;

	dado1 = dado2;

	std::cout << "Valore dado1: " << dado1.getValoreDado() << std::endl;
	std::cout << "Valore dado2: " << dado2.getValoreDado() << std::endl;

	dado1.dati[0] = 666;

	std::cout << "Valore primo dato dado1: " << dado1.dati[0] << std::endl;
	std::cout << "Valore primo dato dado2: " << dado2.dati[0] << std::endl;

*/
    return (0);
}
