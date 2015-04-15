#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dati_globali.h"
#include "input.h"
#include "elaborazione.h"

int main(void)
{
	string stringhe_input[MAX_STRINGHE] = {'\0'};
	string key[LEN_STRINGA];
	unsigned int contatore_numero_stringhe;

	printf("Per cortesia inserire %d stringhe (inserire 0 per terminare): \n", STRINGHE_DA_LEGGERE);

	contatore_numero_stringhe = 0;
	do{
		printf("%d>", contatore_numero_stringhe);
		lettura_stringa(stringhe_input, contatore_numero_stringhe);
		contatore_numero_stringhe++;
	}while(contatore_numero_stringhe <= STRINGHE_DA_LEGGERE);

	printf("%s", "Per cortesia inserire la key da cercare: ");
	lettura_stringa(key, 0);

	FibonacciSearcher(stringhe_input);

	return 0;
}
