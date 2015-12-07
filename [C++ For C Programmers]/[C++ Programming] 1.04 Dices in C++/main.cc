
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int sides = 6;
inline int r_side(){return (rand() % sides + 1);}

int main(void) {

	const int n_dice = 2; //Numero di dadi in gioco
	unsigned int d1; //Variabile per il dado 1
	unsigned int d2; //Variabile per il dado 2

	srand(time(NULL));
	cout << "\nInserisci il numero di tentativi: ";
	unsigned int trials; //Numero tentativi
	cin >> trials;

	unsigned int* outcomes = new unsigned int[n_dice * sides + 1]; //Storico risultati usciti

	size_t contatoreJ = 0;
	while(contatoreJ < trials){
		outcomes[(d1 = r_side())+(d2 = r_side())]++;
		contatoreJ++;
	}
	cout << "probabilita'\n";
	contatoreJ = 2;
	while(contatoreJ < n_dice * sides + 1){
		cout << "giocata = " << contatoreJ
			 << "p = " << static_cast<double>(outcomes[contatoreJ])/trials
			 << endl;
		contatoreJ++;
	}

	return (EXIT_SUCCESS);
}
