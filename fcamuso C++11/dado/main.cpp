#include <iostream>
#include "classDado.h"

using namespace std;

int main()
{
    Dado::Dado dado1;
    Dado::Dado dado2(1);
    DadoTruccato::Dado dado3;

    cout << "Ecco il primo lancio primo dado" << " " << dado1.lancioDado() << endl;
    cout << "Ecco il primo lancio secondo dado" << " " << dado2.lancioDado() << endl;

    cout << "Numero dadi online" << " " << Dado::getNumeroDadi() <<endl;

    cout << "Ecco il secondo lancio primo dado" << " " << dado1.lancioDado() << endl;
    cout << "Ecco il secondo lancio secondo dado" << " " << dado2.lancioDado() << endl;

    cout << "Test di clonazione, il contenudo del dado da clonare e':" << " " << dado1.getValoreDado() << endl;

    Dado::Dado* dado4 = dado1.Clona();

    delete dado4;
    cout << "Valore dado clonato:" << " " << dado4->getValoreDado() << endl;

    return 0;
}
