#include "./CommitteeAssignments.h"
#include <string>
#include <iostream>
#include <regex>

using namespace std;



CommitteeAssignments :: CommitteeAssignments(){};
CommitteeAssignments :: ~CommitteeAssignments(){};
void CommitteeAssignments :: commitee(string time, string text){
    ConversationSaver cs;
    smatch m;
    string message1 = "cpu: ";
	string message2 = "cpu: ";
    regex assign("Committee Assignments[\r\n]+.+");
        if (regex_search(text, m, assign)){
		for(auto x : m){
			cout<<x<<endl;
            message1 += x;
            cs.saver(time, message1);
            cs.cpu++;
		}
	}
    else{
        cout<<"couldn't find what your looking for try typing something else"<<endl;
        message2 += "couldn't find what your looking for try typing something else";
        cs.saver(time, message2); 
        cs.cpu++;   
    }
};