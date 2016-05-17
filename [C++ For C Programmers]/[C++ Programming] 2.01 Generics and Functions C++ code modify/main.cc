#include <iostream>
#include "datiGlobali.hh"

int main(void)
{
	using namespace std;

	cout << "template of sum()" << endl;
	int a[] = {1,2,3};
	double b[] = {2.1, 2.2, 2.3};
	cout << sottrazione(a, 3) << endl;
	cout << sottrazione(b, 3) << endl;
	stampaArray(a, 3);
	stampaArray(b, 3);

}

template <class T>
T sottrazione(T array[], size_t dimensione, T baseSomma){
	for(size_t indice = 0; indice < dimensione; indice++)
			baseSomma -= array[indice];
	return baseSomma;
}

template <class T>
void stampaArray(T array[], size_t dimensione){
	for(size_t indice = 0; indice < dimensione; indice++)
		std::cout << array[indice] << std::endl;
}


