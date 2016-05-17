/*
 * Zoo.h
 *
 *  Created on: 16 mag 2016
 *      Author: ibanez89
 */

#ifndef ZOO_H_
#define ZOO_H_


#include <iostream>
#include <vector>
#include <string>

class Zoo{
    public:
        Zoo();
        std::string getAnimalName();
        unsigned int getAnimalNumber();
        unsigned int getVector();
        void setAnimalName(std::string setName);
        void setAnimalNumber(unsigned int setNumber);
        //~Zoo();
    private:
        std::string name;
        unsigned int number;
        std::vector<int> test;
};



#endif /* ZOO_H_ */
