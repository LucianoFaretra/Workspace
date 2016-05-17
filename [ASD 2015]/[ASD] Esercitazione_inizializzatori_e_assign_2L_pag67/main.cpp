#include <iostream>
#include <vector>
#include "Zoo.h"

int main()
{
    Zoo zoo_puglia;
    //Zoo zoo_italia;
    std::string nameTemp;
    unsigned int numberTemp;

    std::cout << "Prego inserire il nome dell'animale >: ";
    std::cin >> nameTemp;
    zoo_puglia.setAnimalName(nameTemp);
    std::cout << "Prego inserire il numero di animali >: ";
    std::cin >> numberTemp;
    zoo_puglia.setAnimalNumber(numberTemp);

    std::cout << "Inizio tentativo di copia in zoo_italia " << std::endl;
    Zoo zoo_italia(zoo_puglia);
    std::cout << "Stampa zoo_italia nome animale: " << zoo_italia.getAnimalName() << std::endl;
    std::cout << "Stampa zoo_italia numero animali: " << zoo_italia.getAnimalNumber() << std::endl;
    std::cout << "Stampa il vector test di zoo_italia: " << zoo_italia.getVector() << std::endl;


return 0;
}
