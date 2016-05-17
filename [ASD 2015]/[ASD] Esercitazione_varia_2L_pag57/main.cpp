/*
 * main.cpp
 *
 *  Created on: 10 mag 2016
 *      Author: ibanez89
 */

/* Trovare il primo numero negativo nella seconda metà dell'index e se presente ne stampa la5 coordinata

    INPUT            DESCRIZIONE                                                            DOMINIO
    index            vettore conentente i numeri da analizzare                              numeri interi
    it               iteratore del vettore index                                            >= 0

    OUTPUT           DESCRIZIONE                                                            DOMINIO
    esito_positivo   stringa contenente il messaggio di successo della computazione         stringa di caratteri non vuota
    esito_negativo   stringa contenente il messaggio di fallimmento della computazione      stringa di caratteri non vuota

*/
#include <iostream>
#include <vector>


using namespace std;
int main(int argc, char* argv[])
{
    vector<int> index = {0, 4, 5, 7, -2, 5, -3};
    auto it = index.begin() + index.size() / 2;
    string esito_positivo = "Il numero negativo è stato trovato nella coordinata >: ";
    string esito_negativo = "Il numero negativo non è stato trovato!";

    while(it != index.end() && *it >= 0)
        it++;
    if(it != index.end())
        cout << esito_positivo << it - index.begin() << endl;
    else
        cout << esito_negativo << endl;

return(0);
}




