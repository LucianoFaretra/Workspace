#include <string>
#include "gioco.hh"

Gioco::Gioco(std::string _nome, double _costo, int _etaMinimaConsigliata) : nome (_nome),
							costo (_costo), etaMinimaConsigliata (_etaMinimaConsigliata)
							//Lista d'inizializzazione
{
}

Gioco::Gioco(std::string _nome, double _costo, int _etaMinimaConsigliata, Dado primoDado, Dado secondoDado) :
							nome (_nome), costo (_costo), etaMinimaConsigliata (_etaMinimaConsigliata),
							d1(primoDado), d2(secondoDado)
							//Lista d'inizializzazione
{
	d1.stampaDati();
}
