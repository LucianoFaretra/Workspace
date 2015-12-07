//============================================================================
// Name        : Esercitazione_ASD_LAB1_16_Ott_15.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * Funzione greaterThan:
 *
 * INPUT						DESCRIZIONE											DOMINIO
 * A							Array di interi										int non vuoto
 * k							elemento da confrontare								int non nullo
 *
 * OUTPUT						DESCRIZIONE											DOMINIO
 * numElementi					Numero di elementi piu grandi di k presenti in A	int >= 0
 *
 * Se l'array A non è null
 *	 Allora
 *	 	Inizializza numElementi a 0
 *	 	Mentre l'array non è terminato
 * 			Se k e' più grande dell'elemento attuale dell'array
 * 				Allora
 * 					incrementa numElenenti di uno
 * 				Altrimenti
 * 					passa ad elemento successivo
 * 			Fine Se
 * 		Fine Mentre
 * 	Altrimenti
 * 		Spampa messaggio d'errore
 * Fine Se
 *
 * Ritorna numElenenti
 *
 *
 * *************************************
 * * Funzione member:
 *
 * INPUT		DESCRIZIONE															DOMINIO
 * A			Array di interi														int non vuoto
 * k			elemento da trovare													int non nullo
 *
 * OUTPUT		DESCRIZIONE															DOMINIO
 * Bool			Restituisce booleano true se trova elemento, falso se non lo trova	Booleano, True o falso
 *
 * Se l'array A non è null
 *	 Allora
 *	 	Inizializza numElementi a 0 * Inizializza Bool a False
 * 			Mentre l'array non è terminato
 *				Se k è diverso dell'elemento attuale dell'array
 *			  		Allora
 *			  			imposta Bool come True
 *			  			Termina il ciclo
 *			 	Fine Se
 *			 Fine Mentre
 *
 *	 Altrimenti
 *	 	Spamta messaggio d'errore
 *	Fine Se
 *
 * Ritorna Bool
 *
 *
 *  * *************************************
 * * Funzione bigger:
 *
 * INPUT		DESCRIZIONE															DOMINIO
 * A			Array di interi														int non vuoto
 *
 *
 * OUTPUT		DESCRIZIONE															DOMINIO
 * A			Array di interi														int non vuoto
 *
 * Se l'array A non è null
 *	 Allora
 *		Inizializza piuGrande al primo elemento dell'array
 * 		Mentre l'array non è terminato
 *	  	Se piuGrande è più piccolo dell'elemento attuale dell'array
 *	  		Allora
 *	  			assegna a piuGrande l'elemento attuale dell'array
 *	  		Altrimenti
 *	  			Passa ad elemento successivo
 *	  	Fine Se
 *	  Fine Mentre
 *	 Altrimenti
 *	 	Spamta messaggio d'errore
 *	Fine Se
 *
 * Ritorna piuGrande
 *
 *
 *  *  * *************************************
 * * Funzione remove:
 *
 * INPUT		DESCRIZIONE															DOMINIO
 * A			Array di interi														int non vuoto
 * k			intero da eliminare dall'array										intero
 *
 * OUTPUT		DESCRIZIONE															DOMINIO
 * A			Array di interi senza elemento k									int non vuoto
 *
 * Se l'array A non è null
 *	 Allora
 *	  Mentre l'array non è terminato
 *	  	Se k è diverso dell'elemento attuale dell'array
 *	  		Allora
 *	  			Passa ad elemento successivo
 *	  		Altrimenti
 *	  			assegna all'elemento del vettore attuale l'elemento (attuale+1)
 *	  			passa ad elemento successivo
 *	  			mentre l'array non arriva al penultimo elemento
 *	  				assegna all'elemento del vettore attuale l'elemento (attuale+1)
 *	  				passa ad elemento successivo
 *	  			Fine mentre
 *	  			assegna all'elemento del vettore attuale il valore 0
 *	  	Fine Se
 *	  Fine Mentre
 *	 Altrimenti
 *	 	Spamta messaggio d'errore
 *	Fine Se
 * Ritorna piuGrande
 *
 * *  *  * *************************************
 * * Funzione odering:
 *
 * INPUT		DESCRIZIONE																DOMINIO
 * A			Array di interi															int non vuoto
 *
 * OUTPUT		DESCRIZIONE																DOMINIO
 * Stampa		Restituisce se crescente, decrescente, costante, non ordinato			stringa di caratteri
 *
 * Se l'array A non è null
 *	 Allora
 *	  Mentre l'array non è terminato
 *	  	Se l'elemento attuale è diverso dell'elemento successivo dell'array
 *	  		Allora
 *	  			Stampa: l'array non e' costante
 *	  			Torna all'elemento 0 dell'array
 *	  			Mentre l'array non è terminato
 *	  				Se l'elemento attuale è più piccolo dell'elemento successivo dell'array
 *	  					Allora
 *	  						passa ad elemento successivo
 *	  						Se l'array e' terminato
 *	  							Allora
 *	  								Stampa: l'array è in ordine crescente
 *	  						Fine Se
 *	  					Altrimenti
 *	  						Stampa: l'array non è in ordine crescente
 *	  						Torna all'elemento 0 dell'array
 *	  							Se l'elemento attuale e' più grande dell'elemento successivo dell'array
 *	  								Allora
 *	  									passa all'elemento successivo
 *	  									Se l'array è terminato
 *	  										Allora
 *	  											Stampa: l'array è in ordine decrescente
 *	  									Fine Se
 *	  								Altrimenti
 *	  									Stampa: l'array non è in ordine decrescente
 *	  							Fine Se
 *	  				Fine Se
 *	  			Fine Mentre
 *	  	Altrimenti
 *	  	Passa all'elemento successivo
 *	  	---
 *
 *
 */


#include <iostream>
#include <vector>
#define FINELISTA 0
using namespace std;
typedef vector<int> vettore;

int greaterThan(const vector<int> A, const int k);
int member(const vector<int> A, const int k);
int bigger(const vector<int> A);
void remove(vector<int>& A, const int k);


int main() {

    vettore A = {0, 2, 4, 6, 8};
    const int k = 2;
    auto iterator = A.begin();


	cout << "numero elementi trovati: " << greaterThan(A, k) << endl << endl;

	cout << "se il numero e' stato trovato nell'array A il risultato e' 1 altrimenti 0: " << member(A, k) << endl << endl;

   	cout << "l'elemento piu grande dell'array A e': " << bigger(A) << endl << endl;

   	//**************************************************************************************//

    iterator = A.begin();								//Stampa array iniziale
    cout << "l'array originale A e':" << endl << "{";
    while(iterator != A.end()){
        cout << *iterator << " ";
        iterator++;
    }
    cout << "}" << endl << endl;

    iterator = A.begin();								//Stampa array finale
    cout << "l'array modificato A e':" << endl << "{";
    remove(A, k);
    while(iterator != A.end()){
        cout << *iterator << " ";
        iterator++;
    }
    cout << "}" << endl << endl;


   	//**************************************************************************************//



	return (0);
}


int greaterThan(const vector<int> A, int k)
{
	int numElementi;
	auto iteratore = A.begin();

	numElementi = 0;
	while(iteratore != A.end()){
        if(*iteratore > k){
            numElementi++;
	  	}
    iteratore++;
	}

	return (numElementi);
}

int member(const vector<int> A, const int k)
{
    int numElementi;
    auto iteratore = A.begin();
    bool booleano;

    booleano = false;
    numElementi = 0;

    while(iteratore != A.end()){
        if(k == *iteratore){
            booleano = true;
        }
        iteratore++;
    }

    return (booleano);
}

int bigger(const vector<int> A )
{
    auto iteratore = A.begin();
    int piuGrande;

    piuGrande = *iteratore;
    while(iteratore != A.end()){
        if(piuGrande < *iteratore)
            piuGrande = *iteratore;
    iteratore++;
    }

    return (piuGrande);
}

void remove(vector<int>& A, const int k)
{

	auto iteratore = A.begin();

	while(iteratore != A.end()){
		if(k != *iteratore){
			iteratore++;
		}
		else{
			while(iteratore != (A.end()-1)){//Scala a sinistra fino al penultimo elemento
				*iteratore = *(iteratore+1);
				iteratore++;
			}
			*iteratore = FINELISTA; //Assegna il valore finelista all'ultimo elemento
		}
	}

	return;
}

void ordering(vector<int>& A)
{

	return;
}

/* Se l'array A non è null
 *	 Allora
 *	  Mentre l'array non è terminato
 *	  	Se l'elemento attuale è diverso dell'elemento successivo dell'array
 *	  		Allora
 *	  			Stampa: l'array non e' costante
 *	  			Torna all'elemento 0 dell'array
 *	  			Mentre l'array non è terminato
 *	  				Se l'elemento attuale è più piccolo dell'elemento successivo dell'array
 *	  					Allora
 *	  						passa ad elemento successivo
 *	  						Se l'array e' terminato
 *	  							Allora
 *	  								Stampa: l'array è in ordine crescente
 *	  						Fine Se
 *	  					Altrimenti
 *	  						Stampa: l'array non è in ordine crescente
 *	  						Torna all'elemento 0 dell'array
 *	  							Se l'elemento attuale e' più grande dell'elemento successivo dell'array
 *	  								Allora
 *	  									passa all'elemento successivo
 *	  									Se l'array è terminato
 *	  										Allora
 *	  											Stampa: l'array è in ordine decrescente
 *	  									Fine Se
 *	  								Altrimenti
 *	  									Stampa: l'array non è in ordine decrescente
 *	  							Fine Se
 *	  				Fine Se
 *	  			Fine Mentre
 *	  	Altrimenti
 *	  	Passa all'elemento successivo
 *	  	---
 *
 *
*/
