#include "PersonalInfo.h"
#include <string>
#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

PersonalInfo :: PersonalInfo(){
};

PersonalInfo :: ~PersonalInfo(){};

void PersonalInfo :: getBirthday(string text){
smatch m;
regex bday ("Born.+");
    if (regex_search(text, m, bday)){
		for(auto x : m){
			cout<<x<<endl;
		}
	}
    else{
        cout<<"couldn't find what your looking for try typing something else"<<endl;
    }
};

void PersonalInfo :: getOfs(string text){
smatch m;
regex ofs ("[Son|Daughter]+ of.+[ ]");
    if (regex_search(text, m, ofs)){
		for(auto x : m){
			cout<<x<<endl;
		}
	}
	else{
		cout<<"couldn't find what your looking for try typing something else"<<endl;
	}
};
    
void PersonalInfo :: getMaritialStatus(string text){
	regex pattern1 ("married");
    smatch m;
	if (regex_search(text, m, pattern1)){
		for(auto x : m){
			cout<<x<<endl;
		}
	}
    else{
        cout<<"single"<<endl;
    }
};
	
void PersonalInfo :: getChildren(string text){
    regex children ("[0-9]+ chil[d|ren]");
        smatch m;
	if (regex_search(text, m, children)){
		for(auto x : m){
			cout<<x<<endl;
		}
	}
    else{
        cout<<"couldn't find what your looking for try typing something else"<<endl;
    }
};

void PersonalInfo :: printInfo(string inputfile){
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
	inFile.close();
};