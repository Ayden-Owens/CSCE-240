#ifndef KEYWORDS_H_
#define KEYWORDS_H_

#include <string>
#include "./Counter.h"

class Keywords{
public:
~Keywords();
Keywords();
std::string compare(std::string question);
protected:
std::string name = "name";
std::string about = "about";
std::string quit = "quit";
std::string q = "q";
std::string representative = "representative";
std::string where = "where";
std::string repo = "repo";
std::string rep = "rep";
std::string contact = "contact";
std::string committees = "committees";
std::string committee = "committee";
std::string married = "married";
std::string child = "child";
std::string children = "children";
std::string kid = "kid";
std::string kids = "kids";
std::string born = "born";
std::string birthday = "birthday";
std::string birthdate = "birthdate";
std::string parents = "parents";
std::string parent = "parent";
std::string voting = "voting";
std::string vote = "vote";
std::string sponsored = "sponsored";
std::string bills = "bills";
std::string whole = "whole";
std::string everything = "everything";
std::string all = "all";
std::string entire = "entire";
std::string example = "example";
std::string summary = "summary";
};


#endif /* KEYWORDS_H_ */