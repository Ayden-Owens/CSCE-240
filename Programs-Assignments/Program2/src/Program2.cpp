/*
 * Program2.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: Aweso
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <regex>
#include "ContactInfo.h"
#include "PersonalInfo.h"
#include "CommitteeAssignments.h"
#include "ServiceInoffice.h"

using namespace std;

string readInputFile(string filename){
	ifstream input;
	input.open(filename, ios::in);

	//error handling
	if (input.is_open()){
		cout<<"File successfully opened"<<endl;
	}
	else{
		cout<<"File did not open sorry!"<<endl;
	}
	//loop through each line and concatenate
	string line;
	string text;
	while(getline(input, line)){
		text+=line;
	}
	input.close();
	return text;
}

int main(){
	string inputfile;
	cout<<"Please enter District name and .txt"<<endl;
	cin >> inputfile;

	string newinputfile;
	newinputfile = "../Program2/data/";
	newinputfile += inputfile;
	cout<<newinputfile<<endl;

	string text;
	text = readInputFile(newinputfile);
	//cout<<text<<endl;

	ContactInfo c;
	PersonalInfo p;

    cout<<"Please type contactinfo for contact information about the district representative"<<endl;

	cout<<"Please type personalinfo for personal information about the district representative"<<endl;

	cout<<"Please type commassignments for information about the district representative's committee assignments"<<endl;

	cout<<"Please type sponsoredbills in House to see information about district representative's sponsored bills"<<endl;

	cout<<"Please type voterecord for the district representative's voting record"<<endl;

	cout<<"Please type serviceinoffice for to see information about the district representative's service in public office"<<endl;

	string response;
	cin >> response;

	if (response=="contactinfo"){
		cout<<"Please retype contactinfo to display all of the representative's content information"<<endl;
		cout<<"Please type contactinfo:name for the name of the representative"<<endl;
		cout<<"Please type contactinfo:region for the region the representative represents"<<endl;
		cout<<"Please type contactinfo:hphone for the home phone number of the representative"<<endl;
		cout<<"Please type contactinfo:bphone for the business phone number of the representative"<<endl;
		cout<<"Please type contactinfo:haddress for the home address of the representative"<<endl;
		cout<<"Please type contactinfo:baddress for the business address of the representative"<<endl;
		cout<<"Please type contactinfo:party for the party of the representative"<<endl;
		//get input
		string ciresponse;
		cin >>ciresponse;
		//get particular answer
		if(ciresponse=="contactinfo:name"){
			c.getName(newinputfile);
		}
		else if (ciresponse=="contactinfo:region"){
			c.getRegion(text);
		}
		else if (ciresponse=="contactinfo:hphone"){
			c.getHomeNumber(text);
		}
		else if (ciresponse=="contactinfo:bphone"){
			c.getBusinessNumber(text);
		}
		else if (ciresponse=="contactinfo:haddress"){
			c.getHomeAddress(text);
		}
		else if (ciresponse=="contactinfo:baddress"){
			c.getBusinessAddress(text);
		}
		else if (ciresponse=="contactinfo:party"){
			c.getParty(text);
		}
		else {
			c.ErrorMessage(newinputfile);
		}
	}//end of contact info
	else if (response=="personalinfo"){
		cout<<"Please retype personalinfo to display the all the personal information of the representative"<<endl;
		cout<<"Please type personalinfo:birth to get the birthday of the representative"<<endl;
		cout<<"Please type personalinfo:maritalstatus to get the marital status of the representative"<<endl;
		cout<<"Please type personalinfo:children to get the number children the representative"<<endl;
		cout<<"Please type personalinfo:education to get the number children the representative"<<endl;
		string presponse;
		cin>>presponse;
		if(presponse=="personalinfo"){
			p.printPersonalInfo(newinputfile);
		}
		else if(presponse=="personalinfo:birth"){
			p.getBirthday(text);
		}
		else if(presponse=="personalinfo:maritalstatus"){
			p.getMaritialStatus(text);
		}
		else if(presponse=="personalinfo:children"){
			p.getChildren(text);
		}
		else if(presponse=="personalinfo:education"){
			p.getEducation(text);
		}
		else{
			p.ErrorMessage(newinputfile);
		}
	}//end of if
	else if(response=="commassignments"){
		cout<<"Please retype commassignments to display the representatives committee assignments"<<endl;
		string caresponse;
		if (caresponse=="commassignments"){
			cout<<"we can't currently print the committee assignments"<<endl;
		}

	}
	else if(response=="sponsoredbills"){
		cout<<"we can't currently print the sponsored bills"<<endl;
	}
	else if(response=="voterecord"){
		cout<<"we can't currently  print the vote record"<<endl;
	}
	else if(response=="serviceinoffice"){
		cout<<"we can't currently  print the service in public office"<<endl;
	}
	else{
		cout<<"Sorry we couldn't find what your looking for"<<endl;
	}








}

//district77.txt
//Contact:name





