#ifndef FACTORIAL_H_
#define FACTORIAL_H_

#include <iostream>
#include <string>

class Factorial{
public:
    virtual ~Factorial();
    Factorial();
    long long factorial(long long n);
};

#endif /* FACTORIAL_H_ */
