#include <iostream>
#include <string>
#include "ServiceInOffice.h"

using namespace std;

ServiceInOffice :: ServiceInOffice(){};
ServiceInOffice :: ~ServiceInOffice(){};
void ServiceInOffice :: error(){
    cout<<"We couldn't find the anything about the service your representatives did in office, Sorry!"<<endl;
};