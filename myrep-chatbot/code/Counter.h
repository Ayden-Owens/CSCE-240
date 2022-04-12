#ifndef COUNTER_H_
#define COUNTER_H_

#include <string>
#include <iostream>
#include <fstream>

class Counter
{
public:
    Counter(); // default
    std::string counter(std::string input, std::string comparision);
    virtual ~Counter();

};

#endif
