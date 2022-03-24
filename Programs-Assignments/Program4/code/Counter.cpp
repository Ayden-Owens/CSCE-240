#include "./Counter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>
using namespace std;

Counter ::~Counter(){};

Counter ::Counter(){}

string Counter::counter(std::string words, std::string str)
{
    float denom = 0;
    float nummer = 0;
    float total = 0;
    for (char i : words)
    {
        denom++;
    }
    for (int a = 0, j = 0; a < denom; a++, j++)
    {
        if (words[a] == str[j])
        {
            nummer++;
        }
    }
    total = nummer / denom;
    if (total >= 0.65)
    {
        return words;
    }
    else if (total >= 1.0)
    {
        return words;
    }
    else
    {
        return str;
    }
}