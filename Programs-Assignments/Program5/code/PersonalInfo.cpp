#include "PersonalInfo.h"
#include <string>
#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

PersonalInfo :: PersonalInfo(){};

PersonalInfo :: ~PersonalInfo(){};

void PersonalInfo :: getBirthday(string time, string text){
	ConversationSaver cs;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
	smatch m;
	regex bday ("Born.+");
    if (regex_search(text, m, bday)){
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

void PersonalInfo :: getOfs(std::string time, string text){
	ConversationSaver cs;
	smatch m;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
	regex ofs ("[Son|Daughter]+ of.+[ ]");
    if (regex_search(text, m, ofs)){
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
    
void PersonalInfo :: getMaritialStatus(std::string time, string text){
	ConversationSaver cs;
	regex pattern1 ("married");
    smatch m;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
	if (regex_search(text, m, pattern1)){
		for(auto x : m){
			cout<<x<<endl;
			message1 += x;
			cs.saver(time, message1);
			cs.cpu++;
		}
	}
    else{
        cout<<"single"<<endl;
		message2 += "single";
		cs.saver(time, message2);
		cs.cpu++;
    }
};
	
void PersonalInfo :: getChildren(std::string time, string text){
    ConversationSaver cs;
	regex children ("[0-9]+ chil[d|ren]");
    smatch m;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
	if (regex_search(text, m, children)){
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

void PersonalInfo :: printInfo(std::string time, string inputfile){
	ConversationSaver cs;
	string message1 = "cpu: ";
	string message2 = "cpu: ";
	string newLine;
	string words;
	ifstream inFile;
	bool partEnd;
	bool parting;
	string holder;
	string section;

	inFile.open(inputfile);
	if (inFile.fail())
	{
		cout << "Sorry could not print out personal info" << endl;
		message1 += "Sorry could not print out personal info";
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
						else if (words == "Personal")
						{
							parting = true;
						}
						else if (newLine == "Committee Assignments")
						{
							partEnd = true;
							continue;
						}
						else
						{
							if (parting != true)
							{
								holder = newLine;
							}
							else
							{
								section += newLine;
								section += "\n";
								holder = newLine;
							}
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