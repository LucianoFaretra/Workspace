#ifndef GIOCO_HH_INCLUDED
#define GIOCO_HH_INCLUDED

#include <string>
#include "classDado.hh"

class Gioco
{
	std::string nome;
	double costo;
	int etaMinimaConsigliata;

	Dado d1;
	Dado d2;

	public:
		Gioco(std::string _nome, double _costo, int _etaMinimaConsigliata);
		Gioco(std::string _nome, double _costo, int _etaMinimaConsigliata, Dado primoDado, Dado secondoDado);


};


#endif // GIOCO_HH_INCLUDED
