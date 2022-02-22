/*
 * ContactInfo.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: Aweso
 */
#include "ContactInfo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

ContactInfo :: ContactInfo(){//default

};

ContactInfo :: ~ContactInfo(){//destructor

};

void ContactInfo :: printContactInfo(string inputfile){
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
		regex pattern ("Representative[\a-zA-Z]+Pe");
		if(regex_search(text, m, pattern)){
			for (auto x : m){
				cout<<x<<endl;
				ofile<<x<<endl;
			}
		}
		else{
			cout<<"couldn't find"<<endl;
		}
		ofile.close();


}//end of method
void ContactInfo :: getRegion(string text){
	regex pattern1("[a-zA-Z]+ County");
	regex pattern2("[a-zA-Z]+ [&] [a-zA-Z]+ Counties");
	smatch m;
	ofstream ofile{"../Program2/doc/text_output.txt"};
	if(regex_search(text, m, pattern1)){
		for (auto x : m){
			cout<< x << endl;
			ofile<< x <<endl;
		}
	}
	if(regex_search(text, m, pattern2)){
		for (auto x : m){
			cout<< x << endl;
			ofile<< x <<endl;
		}
	}
}

void ContactInfo :: getHomeNumber(string text){
	regex pattern ("Home Phone [(][0-9]*[)] [0-9]*[-]*[0-9]*");
	smatch m;
	ofstream ofile;
	ofile.open("../Program2/doc/text_output.txt");
	if(regex_search(text, m, pattern)){
		for (auto x : m){
			cout<< x << endl;
			ofile<< x <<endl;
		}
	}
	ofile.close();
};

void ContactInfo :: getBusinessNumber(string text){
	regex pattern ("Business Phone [(][0-9]*[)] [0-9]*[-]*[0-9]*");
	smatch m;
	ofstream ofile{"../Program2/doc/text_output.txt"};
	if(regex_search(text, m, pattern)){
		for (auto x : m){
			cout<< x << endl;
			ofile<< x <<endl;
		}

	}
	else{
			cout<<"couldn't find"<<endl;
	}
	ofile.close();
}

void ContactInfo :: getParty(string text){
	regex pattern ("Democrat|Republican|Independent|Green|Libertarian|Peace and Freedom");
	smatch m;
	ofstream ofile{"../Program2/doc/text_output.txt"};
	if(regex_search(text, m, pattern)){
		for (auto x : m){
			cout<< x << endl;
			ofile<< x <<endl;
		}
	}
	else{
			cout<<"couldn't find"<<endl;
	}
	ofile.close();
}

void ContactInfo :: getHomeAddress(string text){
	regex pattern ("Home [\a-zA-Z_0-9]+ [0-9]{5}");
	smatch m;
	ofstream ofile{"../Program2/doc/text_output.txt"};
	if (regex_search(text,m, pattern)){
		for(auto x: m){
			cout<<x<<endl;
			ofile<< x <<endl;
		}
	}
	else{
			cout<<"couldn't find"<<endl;
	}
	ofile.close();
}

void ContactInfo :: getBusinessAddress(string text){
	regex hapattern ("Columbia Address[a-zA-Z_0-9]+ [a-zA-Z_0-9]+ [a-zA-Z_0-9]+[.]+ Columbia [0-9]{5}");
	smatch m;
	ofstream ofile{"../Program2/doc/text_output.txt"};
	if (regex_search(text,m,hapattern)){
		for(auto x: m){
			cout<<x<<endl;
			ofile<< x <<endl;
		}
	}
	else{
			cout<<"couldn't find"<<endl;
	}
	ofile.close();
}

void ContactInfo :: getName(string inputfile){
	ifstream file;
	string line;
	string word;
	string result;
	bool error = false;
	file.open(inputfile, ios::in);
	if (file.is_open()){
	cout<<"File successfully opened"<<endl;
	}
	else{
		cout<<"File did not open sorry!"<<endl;
	}
	while(getline(file, line)){
		stringstream ss(line);
		while(ss>>word){
			if (error != true){
				if (word == "Representative"){
					result = line;
					error = true;
				}
				else{
					continue;
				}
			}
			else {
			continue;
			}
		}
	}
	file.close();
	cout<<result<<endl;
	ofstream ofile{"../Program2/doc/text_output.txt"};
	ofile<<result<<endl;
	ofile.close();
}

void ContactInfo :: ErrorMessage(string inputfile){
	cout<<"Sorry but we could not find what your looking for."<<"\n"<< "Please take a look at contact information from the district you wanted to search for to see what we missed."<<endl;
	//send each line of contact information
	printContactInfo(inputfile);

}





