#include "./ContactInfo.h"
#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

ContactInfo :: ~ContactInfo(){};//destructor

ContactInfo :: ContactInfo(){};

void ContactInfo :: getName(string time, string txt){
	ConversationSaver cs;
	smatch m;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
    regex name ("Representative.+");
	if(regex_search(txt, m, name)){
		for (auto x : m){
			cout<<x<<endl;
			message1 += x;
			cs.saver(time, message1);
			cs.cpu++;
		}
	}
	else{
		cout<<"couldn't find name!"<<endl;
		message2 += "couldn't find name!";
		cs.saver(time, message2);
		cs.cpu++;
	}
};

void ContactInfo :: getParty(string time, string txt){
	ConversationSaver cs;
	smatch m;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
    regex party ("Democrat|Republican|Independent|Green|Libertarian|Peace and Freedom");
	if(regex_search(txt, m, party)){
		for (auto x : m){
			cout<<x<<endl;
			message1 += x;
			cs.saver(time, message1);
			cs.cpu++;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
		message2 += "couldn't find!";
		cs.saver(time, message2);
		cs.cpu++;
	}
};

void ContactInfo :: getHomeAddress(string time, string txt){
	ConversationSaver cs;
	smatch m;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
    regex homeAdd("Columbia Address[\r\n]+.+Columbia [0-9]{5}");
	if(regex_search(txt, m, homeAdd)){
		for (auto x : m){
			cout<<x<<endl;
			message1 += x;
			cs.saver(time, message1);
			cs.cpu++;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
		message2 += "couldn't find!";
		cs.saver(time, message2);
		cs.cpu++;
	}
};

void ContactInfo :: getBusinessAddress(string time, string txt){
	ConversationSaver cs;
	smatch m;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
    regex businessAdd("Home Address[\r\n]+.+");
	if(regex_search(txt, m, businessAdd)){
		for (auto x : m){
			cout<<x<<endl;
			message1 += x;
			cs.saver(time, message1);
			cs.cpu++;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
		message2 += "couldn't find!";
		cs.saver(time, message2);
		cs.cpu++;
	}
};

void ContactInfo :: getHomeNumber(string time, string txt){
	ConversationSaver cs;
	smatch m;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
    regex homeNumber ("Home Phone.+");
	if(regex_search(txt, m, homeNumber)){
		for (auto x : m){
			cout<<x<<endl;
			message1 += x;
			cs.saver(time, message1);
			cs.cpu++;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
		message2 += "couldn't find!";
		cs.saver(time, message2);
		cs.cpu++;
	}
};

void ContactInfo :: getBusinessNumber(string time, string txt){
	ConversationSaver cs;
	smatch m;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
    regex businesNumber ("Business Phone.+");
	if(regex_search(txt, m, businesNumber)){
		for (auto x : m){
			cout<<x<<endl;
			message1 += x;
			cs.saver(time, message1);
			cs.cpu++;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
		message2 += "couldn't find!";
		cs.saver(time, message2);
		cs.cpu++;
	}
};

void ContactInfo :: getRegion (string time, string txt){
	ConversationSaver cs;
	smatch m;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
    regex region ("District.+");
	if(regex_search(txt, m, region)){
		for (auto x : m){
			cout<<x<<endl;
			message1 += x;
			cs.saver(time, message1);
			cs.cpu++;
		}
	}
	else{
		cout<<"couldn't find!"<<endl;
		message2 += "couldn't find!";
		cs.saver(time, message2);
		cs.cpu++;
	}
};

void ContactInfo :: printContactInfo(string time, string inputfile){
	ConversationSaver cs;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
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
		message1 =+ "Sorry could not print out contact info";
		cs.saver(time, message1);
		cs.cpu++;
		
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
	message2 += section;
	cs.saver(time, message2);
	cs.cpu++;
	inFile.close();
};