#ifndef INITIALIZR_H_
#define INITIALIZR_H_

#include <iostream>
#include <vector>

class Topo{
    public:
        Topo();
        unsigned int getGambeNormali();
        unsigned int getGambeAttuali();
    private:
        const unsigned int gambeNormali;
        unsigned int gambeAttuali;
};

#endif /* INITIALIZR_H_ */
