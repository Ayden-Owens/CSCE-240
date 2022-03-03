#include "SponsoredBills.h"
#include <iostream>
#include <string>

using namespace std;

SponsoredBills :: SponsoredBills(){};

SponsoredBills :: ~SponsoredBills(){};

void SponsoredBills :: error(){
    cout<<"Couldn't find the sponsored bills for your district, Sorry!"<<endl;
}
