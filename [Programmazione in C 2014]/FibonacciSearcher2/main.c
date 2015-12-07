#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dati_globali.h"
#include "input.h"
#include "elaborazione.h"

int main(void)
{
	string stringhe_input[MAX_STRINGHE];
	string key;
	unsigned int contatore_numero_stringhe;

	printf("Per cortesia inserire %d stringhe (inserire 0 per terminare): \n", STRINGHE_DA_LEGGERE);

	memset(stringhe, 0, 101);
	memset(stringhe_input, 0, 101);
	memset(key, 0, 101);
	contatore_numero_stringhe = 0;
	do{
		printf("%d>", contatore_numero_stringhe);
		lettura_stringhe(stringhe_input, contatore_numero_stringhe);
		contatore_numero_stringhe++;
	}while(contatore_numero_stringhe <= STRINGHE_DA_LEGGERE);

	printf("%s", "Per cortesia inserire la key da cercare: ");
	lettura_stringa(key);

	FibonacciSearcher(stringhe_input);
	printf("%d :ciao", lookFor(key));

	return 0;
}
