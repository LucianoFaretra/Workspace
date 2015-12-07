
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIDES 6
#define R_SIDE (rand() % SIDES + 1)
#define n_dice 2 //Numero di dadi in gioco

int main(void) {
	int trials; //Numero tentativi
	int contatoreJ;
	unsigned int outcomes[n_dice * SIDES+1] = {0}; //Storico risultati usciti per ogni faccia
	unsigned int d1; //Variabile per il dado 1
	unsigned int d2; //Variabile per il dado 2

	srand(time(NULL));
	printf("%s", "\nInserisci il numero di tentativi: ");
	scanf("%d", &trials);

	contatoreJ = 0;
	while(contatoreJ < trials){
		outcomes[(d1 = R_SIDE)+(d2 = R_SIDE)]++;
		contatoreJ++;
	}
	printf("probabilita'\n");
	contatoreJ = 2;
	while(contatoreJ < n_dice * SIDES + 1){
		printf("giocata = %d p = %lf\n", contatoreJ, (double)outcomes[contatoreJ]/trials);
		contatoreJ++;
	}

	return (EXIT_SUCCESS);
}
