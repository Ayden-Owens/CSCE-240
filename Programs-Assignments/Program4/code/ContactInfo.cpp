#include "./ContactInfo.h"
#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

ContactInfo :: ~ContactInfo(){};//destructor

ContactInfo :: ContactInfo(){};

void ContactInfo :: getName(string txt){
	smatch m;
    regex name ("Representative.+");
	if(regex_search(txt, m, name)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find name!"<<endl;
	}
};

void ContactInfo :: getParty(string txt){
	smatch m;
    regex party ("Democrat|Republican|Independent|Green|Libertarian|Peace and Freedom");
	if(regex_search(txt, m, party)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void ContactInfo :: getHomeAddress(string txt){
	smatch m;
    regex homeAdd("Columbia Address[\r\n]+.+Columbia [0-9]{5}");
	if(regex_search(txt, m, homeAdd)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void ContactInfo :: getBusinessAddress(string txt){
	smatch m;
    regex businessAdd("Home Address[\r\n]+.+");
	if(regex_search(txt, m, businessAdd)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void ContactInfo :: getHomeNumber(string txt){
	smatch m;
    regex homeNumber ("Home Phone.+");
	if(regex_search(txt, m, homeNumber)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void ContactInfo :: getBusinessNumber(string txt){
	smatch m;
    regex businesNumber ("Business Phone.+");
	if(regex_search(txt, m, businesNumber)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void ContactInfo :: getRegion (string txt){
	smatch m;
    regex region ("District.+");
	if(regex_search(txt, m, region)){
		for (auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
	}
};

void ContactInfo :: printContactInfo(string inputfile){
	string newLine;
	string words;
	bool partEnd;
	string section;
	string holder;
	ifstream inFile;
	inFile.open(inputfile);
	if (inFile.fail())
	{
		cout << "Sorry could not print out contact info" << endl;
	}
	else
	{
		while (getline(inFile, newLine))
		{ // gets lines
			if (newLine.empty())
			{
				continue; // sends back if line is empty
			}
			else
			{
				stringstream series(newLine);
				while (series >> words)
				{ // takes in line as string
					if (partEnd != true)
					{
						if (holder == newLine)
						{
							continue;
						}
						else if (newLine == "Personal Information")
						{
							partEnd = true;
							continue;
						}
						else
						{
							section += newLine;
							section += "\n";
							holder = newLine;
						}
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	cout << section << endl;
	inFile.close();
};