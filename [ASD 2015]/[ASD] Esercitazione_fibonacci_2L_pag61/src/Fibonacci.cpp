#include <iostream>
#include "Fibonacci.h"

Fibonacci::Fibonacci() {
	Fibonacci::values.push_back(0);
	Fibonacci::values.push_back(1);
	Fibonacci::values.push_back(1);
}

unsigned int Fibonacci::value(unsigned int n) const{
    if(n >= values.size()){
        for(size_t i=values.size(); i <= n; ++i)
            values.push_back(values[i - 2] + values[i - 1]);
    }
    return values[n];
}
