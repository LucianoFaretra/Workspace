/*
 * Fibonacci.h
 *
 *  Created on: 12 mag 2016
 *      Author: ibanez89
 */
#include <vector>

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

class Fibonacci{
    public:
        Fibonacci();
        unsigned int value(unsigned int n) const;
    private:
        mutable std::vector<unsigned int> values;
};

#endif /* FIBONACCI_H_ */
