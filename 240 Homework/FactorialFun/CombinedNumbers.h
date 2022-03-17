#ifndef COMBINEDNUMBERS_H_
#define COMBINEDNUMBERS_H_

#include "./Factorial.h"
#include <iostream>
#include <string>

class CombinedNumbers{
    public:
    virtual ~CombinedNumbers();
    CombinedNumbers();
    long long combined(long long n, long long r);
};

#endif /* COMBINEDNUMBERS_H_ */