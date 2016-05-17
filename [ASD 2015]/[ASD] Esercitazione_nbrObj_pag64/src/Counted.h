/*
 * Counted.h
 *
 *  Created on: 12 mag 2016
 *      Author: ibanez89
 */

#ifndef COUNTED_H_
#define COUNTED_H_

#include <iostream>
#include <vector>

class Counted{
    public:
        Counted() {++nbrObj;}
        ~Counted() {--nbrObj;}
        static unsigned int getNbrObj(){return nbrObj;}
    private:
        static unsigned int nbrObj;
};
    unsigned int Counted::nbrObj = 0;
#endif /* COUNTED_H_ */
