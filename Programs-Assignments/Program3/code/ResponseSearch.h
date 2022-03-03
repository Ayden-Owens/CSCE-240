#ifndef RESPONSESEARCH_H_
#define RESPONSESEARCH_H_

#include "./ContactInfo.h"
#include "./PersonalInfo.h"
#include "./CommitteeAssignments.h"
#include <string>
#include <iostream>

class ResponseSearch{
public:
    ResponseSearch();
    void contact(std::string answer, std::string text, std::string file);
    virtual ~ResponseSearch();
};

#endif // RESPONSESEARCH 