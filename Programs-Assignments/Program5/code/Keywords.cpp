#include "./Keywords.h"
#include <string>
#include <iostream>

using namespace std;

Keywords :: Keywords(){}

Keywords :: ~Keywords(){}

string Keywords :: compare(string question){
    Counter c;
    question = c.counter(name, question);
    question = c.counter(quit, question);
    question = c.counter(q, question);
    question = c.counter(about, question);
    question = c.counter(representative, question);
    question = c.counter(where, question);
    question = c.counter(rep, question);
    question = c.counter(repo, question);
    question = c.counter(contact, question);
    question = c.counter(committees, question);
    question = c.counter(committee, question);
    question = c.counter(everything, question);
    question = c.counter(married, question);
    question = c.counter(kids, question);
    question = c.counter(children, question);
    question = c.counter(born, question);
    question = c.counter(birthday, question);
    question = c.counter(birthdate, question);
    question = c.counter(parents, question);
    question = c.counter(voting, question);
    question = c.counter(vote, question);
    question = c.counter(sponsored, question);
    question = c.counter(bills, question);
    question = c.counter(whole, question);
    question = c.counter(all, question);
    question = c.counter(everything, question);
    question = c.counter(entire, question);
    question = c.counter(example, question);
    question = c.counter(summary, question);
    return question;
}

