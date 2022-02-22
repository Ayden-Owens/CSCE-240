/*
 * PersonalInfo.cpp
 *
 *  Created on: Feb 21, 2022
 *      Author: Aweso
 */

#include "PersonalInfo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

PersonalInfo :: PersonalInfo(){

}

PersonalInfo :: ~PersonalInfo(){

}

void PersonalInfo :: printPersonalInfo(string inputfile){
	ifstream file;
	string line;
	file.open(inputfile, ios::in);
	if (file.is_open()){
		cout<<"File successfully opened"<<endl;
	}
	else{
		cout<<"File did not open sorry!"<<endl;
	}


	smatch m;
	string text;

	while(getline(file, line)){
		text += line;
		text += "\n";
	}
	file.close();
	ofstream ofile{"../Program2/doc/text_output.txt"};
	regex pattern ("Personal Information[\a-zA-Z]+[C]");
	if(regex_search(text, m, pattern)){
		for (auto x : m){
			cout<<x<<endl;
			ofile<<x<<endl;
		}
		ofile.close();
	}
}//end of method

void PersonalInfo :: getBirthday(string text){
	regex bdaypattern ("[a-zA-Z]+ [0-9]*[,] [0-9]{4}");
	smatch m;
	ofstream ofile{"../Program2/doc/text_output.txt"};
	if(regex_search(text, m, bdaypattern)){
		for(auto x : m){
			cout<< x <<endl;
			ofile<< x <<endl;
		}
	}
	ofile.close();
}

void PersonalInfo :: getMaritialStatus(string text){
	regex pattern1 ("married");
	regex pattern2 ("single");
	smatch m;
	ofstream ofile{"./Program2/doc/text_output.txt"};
	if (regex_search(text, m, pattern1)){
		for(auto x : m){
			cout<<x<<endl;
			ofile<<x<<endl;
		}
	}
	if (regex_search(text, m, pattern2)){
		for(auto x : m){
			cout<<x<<endl;
			ofile<<x<<endl;
		}
	}
	ofile.close();
}

void PersonalInfo :: getChildren(std::string text){
	regex pattern1 ("[0-1] child");
	regex pattern2 ("[0-9]+ children");
	smatch m;
	ofstream ofile{"../Program2/doc/text_output.txt"};
	if (regex_search(text, m, pattern1)){
		for(auto x : m){
			cout<<x<<endl;
			ofile<<x<<endl;
		}
	}
	if (regex_search(text, m, pattern2)){
		for(auto x : m){
			cout<<x<<endl;
			ofile<<x<<endl;
		}
	}
	ofile.close();
}

void PersonalInfo :: getEducation(string text){
	regex pattern1("[a-zA-Z_0-9]+ University, [a-zA-Z]+[.][a-zA-Z]+., [0-9]{4}");
	regex pattern2("[a-zA-Z]+ [a-zA-Z]+ University, [a-zA-Z]+[.][a-zA-Z]+., [0-9]{4}");
	regex pattern3("University [\a-zA-Z]+, [a-zA-Z]+[.][a-zA-Z]+., [0-9]{4}");
	ofstream ofile{"../Program2/doc/text_output.txt"};
	smatch m;
	if(regex_search(text, m, pattern1)){
		for (auto x : m){
			cout << x << endl;
			ofile<< x << endl;
		}
	}
	if(regex_search(text, m, pattern2)){
		for (auto x : m){
			cout << x << endl;
			ofile<< x << endl;
		}
	}
	if(regex_search(text, m, pattern3)){
		for (auto x : m){
			cout << x << endl;
			ofile<< x << endl;
		}
	}
	else{
		cout<<"couldn't find"<<endl;
	}
	ofile.close();
}

void PersonalInfo :: ErrorMessage(string inputfile){
	cout<<"Sorry but we could not find what your looking for."<<"\n"<< "Please take a look at personal information from the district you wanted to search for to see what we missed."<<endl;
	printPersonalInfo(inputfile);
}
