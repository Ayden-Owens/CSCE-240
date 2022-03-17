#include "./CombinedNumbers.h"
#include <iostream>
#include <string>

using namespace std;

CombinedNumbers::CombinedNumbers(){};

CombinedNumbers::~CombinedNumbers(){};

long long CombinedNumbers::combined(long long n, long long r){
    long long x;
    long long y;
    long long w;
    long long c;
    long long z;
    Factorial f;
    if(n == 0&&r ==0){
        return -1;
    }
    else if(n == r){
        return 1;
    }
    else{
        x = f.factorial(n);
        y = f.factorial(r);
        z = n-r;
        w = f.factorial(z);
        c = (x)/(y*w);
    }
    return c;
}