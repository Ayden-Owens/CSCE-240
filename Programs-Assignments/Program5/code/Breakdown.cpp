#include "./Breakdown.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Breakdown :: Breakdown(){};

Breakdown :: ~Breakdown(){};

string Breakdown :: split(string question){
    stringstream ss(question);
    string words;
    Keywords k;
    while (ss>>words){
        words = k.compare(words);
        if (words == "name" || words == "contact" || words == "address" || words == "number" || words == "phone" || words == "message" || words == "party" || words == "live")
        {
            return words;
        }
        else if (words == "committee" || words == "committees")
        {
            return words;
        }
        else if (words == "sponsored" || words == "bills" || words == "voting"|| words == "vote")
        {
            return words;
        }
        else if (words == "service")
        {
            return words;
        }
        else if (words == "example")
        {
            return words;
        }
        else if (words == "whole" || words == "entire" || words == "all" || words == "everything")
        {
            cout << "For the" << words << " thing, you can select the print whole document option." << endl;
            return words;
        }
        else if (words == "married" || words == "personal" || words == "birthday" || words == "born" || words == "birthdate" || words == "children" || words == "parents" || words == "kids" || words == "kid" || words == "child" || words == "parents" || words == "parent"|| words == "about")
        {
            
            return words;
        }
        else if (words == "quit" || words == "q")
        {
            return words;
        }
        else{}
    }
    return question;
};

