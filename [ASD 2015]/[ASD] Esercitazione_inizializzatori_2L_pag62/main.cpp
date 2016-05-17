#include <iostream>
#include <vector>
#include "Initializr.h"

int main()
{
    Topo rattoDiCampagna;

    std::cout << "Un ratto di campagna ha un numero normale di " << rattoDiCampagna.getGambeNormali()
              << " gambe, come possiamo vedere il nostro jhon però ne ha " << rattoDiCampagna.getGambeAttuali()
              << " probabilmente ne ha persa una in seguito ad un incidente!" << std::endl;
    return 0;
}
