#include <string>

#ifndef CLASSDADO_H_INCLUDED
#define CLASSDADO_H_INCLUDED

class Dado
{
    //Dati privati
    private:
        int numeroFacce = 6;
        int valoreDado = 0;
        static int numeroDadi;

    //Metodi pubblici
    public:
        Dado(int nFacce);
        Dado();
        int lancioDado();
        Dado* Clona();
        static std::string Help();

    //Metodi getter/setter
        int getValoreDado();
        void setValoreDado(int nuovoValore);
        static int getNumeroDadi();

    //Distruttore
        ~Dado();
};

class DadoTruccato : public Dado
{
    int facciaTruccata;
};

#endif // CLASSDADO_H_INCLUDED
