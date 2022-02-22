/*
 * ServiceInoffice.cpp
 *
 *  Created on: Feb 22, 2022
 *      Author: Aweso
 */

#include "ServiceInoffice.h"

#include "ContactInfo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

ServiceInoffice :: ServiceInoffice(){

}

ServiceInoffice :: ~ServiceInoffice(){

}

void ServiceInoffice :: printService(string inputfile){
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
		ofstream ofile;
		ofile.open("../Program2/doc/text_output.txt");
		regex pattern ("Service In Public Office[\a-zA-Z]+[L]");
			if(regex_search(text, m, pattern)){
				for (auto x : m){
					cout<<x<<endl;
					ofile<<x<<endl;
				}
				ofile.close();
			}

}




