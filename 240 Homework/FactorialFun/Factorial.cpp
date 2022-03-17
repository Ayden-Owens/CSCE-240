#include "./Factorial.h"
#include <iostream>
#include <string>

using namespace std;

Factorial :: ~Factorial(){}

Factorial :: Factorial(){}

long long Factorial :: factorial(long long n){
    long long a = 1.0;
    if (n==0||n==1){
        a = 1;
    }
    else if (n<0){
        return -1;
    }
    else if (n>20){
        return n;
    }
    else{
        for(int i = 1; i <= n; ++i){
            a *= i;
        }
    }
    return a;
}