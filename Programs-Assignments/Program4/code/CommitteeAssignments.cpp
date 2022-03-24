#include "./CommitteeAssignments.h"
#include <string>
#include <iostream>
#include <regex>

using namespace std;

CommitteeAssignments :: CommitteeAssignments(){};
CommitteeAssignments :: ~CommitteeAssignments(){};
void CommitteeAssignments :: commitee(string text){
    smatch m;
    regex assign("Committee Assignments[\r\n]+.+");
        if (regex_search(text, m, assign)){
		for(auto x : m){
			cout<<x<<endl;
		}
	}
    else{
        cout<<"couldn't find what your looking for try typing something else"<<endl;
    }
};