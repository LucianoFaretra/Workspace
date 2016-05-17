#include <iostream>

using namespace std;

template <class sommabile>
inline sommabile sommaNumeri(sommabile arrayDaSommare[], size_t numeroElementi){

	size_t arrayIndex = 0;
	sommabile somma = 0;

	while(arrayIndex < numeroElementi){
		somma += arrayDaSommare[arrayIndex];
		arrayIndex++;
	}

	return (somma);
}

int main(void)
{
	const int grandezzaArray = 10;
	double arrayDaSommare[grandezzaArray] = {1.4,2,3.45,4,5,6,7,8,9,10};

	cout << sommaNumeri(arrayDaSommare, grandezzaArray);
	return (0);
}
