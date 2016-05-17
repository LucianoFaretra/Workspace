//============================================================================
// Name        : [ASD].cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>


using namespace std;
int main(int argc, char* argv[])
{
    vector<int> matrice;
    int numero_letto;
    size_t numero_inserimenti;
    size_t counter;

    counter = 0;
    cout << "definisci il numero d'inserimenti >:";
    cin >> numero_inserimenti;
    while(counter <= numero_inserimenti){
    	cout << "inserisci una parola >: ";
    	cin >> numero_letto;
    	matrice.push_back(numero_letto);
    	counter++;
    }

    cout << "ecco la matrice inserita >:";
    counter = 0;
    while(counter <= numero_inserimenti){
    	cout << matrice[counter];
    	counter++;
    }
return(0);
}

