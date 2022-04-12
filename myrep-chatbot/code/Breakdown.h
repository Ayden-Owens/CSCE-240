#ifndef BREAKDOWN_H_
#define BREAKDOWN_H_

#include "./Keywords.h"

#include <string>

class Breakdown{
public:
Breakdown();
~Breakdown();
std::string split(std::string question);
};

#endif /* BREAKDOWN_H_ */