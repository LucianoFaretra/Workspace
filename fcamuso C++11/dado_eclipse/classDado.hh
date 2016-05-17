#ifndef CLASSDADO_H_INCLUDED
#define CLASSDADO_H_INCLUDED

#include <string>


class Dado
{
    //Dati privati
    private:
        int numeroFacce = 6;
        int valoreDado = 0;
        static int numeroDadi;

    //Metodi pubblici
    public:

        int* dati; //Eventuali informazioni aggiuntive

        Dado(int nFacce);
        Dado();
        int lancioDado();
        Dado* Clona();
        static std::string Help();
        void stampaDati();

    //Metodi getter/setter
        int getValoreDado() {return valoreDado;}
        void setValoreDado(int nuovoValore);
        static int getNumeroDadi() {return numeroDadi;}
        int getNumeroFacce() {return numeroFacce;};

    //Distructor
        ~Dado();

    //Copy constructor
        Dado(const Dado& d); //Si passa un dado per reference di tipo const immutabile
   //Assignment overload
        Dado& operator=(const Dado& original);
};

/*class DadoTruccato : public Dado
{
    int facciaTruccata;
};
*/
#endif // CLASSDADO_H_INCLUDED
