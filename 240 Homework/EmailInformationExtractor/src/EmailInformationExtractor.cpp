/*
 * EmailInformationExtractor.cpp
 *
 *  Created on: Feb 25, 2022
 *      Author: Aweso
 */
#include "./BaseEmailHeaderType.cpp"
#include "./GmailHeaderType.cpp"
#include "./OutlookHeaderType.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

string readinputFile(string inputfile){
	ifstream input;
	input.open(inputfile, ios::in);
	//error handling
	if (input.is_open()){
		cout<<"File successfully opened"<<endl;
	}
	else{
		cout<<"File did not open sorry!"<<endl;
		exit(0);
	}
	//loop through each line and concatenate
	string line;
	string text;
	while(getline(input, line)){
		text+=line;
		text+="\n";
	}
	input.close();
	return text;
}

int main(){

	BaseEmailHeaderType b;
	GmailHeaderType g;
	OutlookHeaderType o;

	//first take in email
	cout<<"enter email"<<endl;
	//take input
	string inputfile;
	cin>>inputfile;
	string txt;

	//read in file
	txt = readinputFile(inputfile);

	//get the header
	cout<<"Please enter header name "<<endl;
	string header;
	cin>>header;
	if (header == "gmail"){
		//part name section
		cout<<"Please enter part name: delivered-to, reply, mime, content-transfer, source, CC, received, to, from, date, subject, and content-type "<<endl;
		string pn;
		cin>>pn;
		if (pn == "date"){
			b.getDate(txt);
		}
		else if (pn == "subject"){
			b.getSubject(txt);
		}
		else if (pn == "content-type"){
			b.getContentType(txt);
		}
		else if (pn == "from"){
			b.getFrom(txt);
		}
		else if (pn == "to"){
			g.getTo(txt);
		}
		else if (pn == "received"){
			b.getReceived(txt);
		}
		else if (pn == "CC"||pn == "cc"){
			b.getCC(txt);
		}
		else if (pn == "source"){
			g.getsource(txt);
		}
		else if (pn == "content-transfer"){
			g.encoding(txt);
		}
		else if (pn == "mime"){
			g.mime(txt);
		}
		else if (pn == "reply"){
			g.replyTo(txt);
		}
		else if (pn == "delivered-to"){
			g.deliverTo(txt);
		}
		else{
			cout<<"Could not find the part name"<<endl;
		}
	}
	else if (header == "microsoft"){
		//part name section
		cout<<"Please enter part name: authenication or auth, language, ms-attach, ms-exchange, message-id, thread, CC, received, to, from, content-type, subject, and date"<<endl;
		string pn;
		cin>>pn;
		if (pn == "date"){
			b.getDate(txt);
		}
		else if (pn == "subject"){
			b.getSubject(txt);
		}
		else if (pn == "content-type"){
			b.getContentType(txt);
		}
		else if (pn == "from"){
			b.getFrom(txt);
		}
		else if (pn == "to"){
			b.getTo(txt);
		}
		else if (pn == "received"){
			b.getReceived(txt);
		}
		else if (pn == "CC"||pn == "cc"){
			b.getCC(txt);
		}
		else if (pn == "Thread"|| pn == "thread"){
			o.getThread(txt);
		}
		else if (pn == "message-id"){
			b.getMessage(txt);
		}
		else if (pn == "ms-exchange"){
			o.MS_Exchange(txt);
		}
		else if (pn == "ms-attach"){
			o.MS_Attach(txt);
		}
		else if (pn == "language"){
			o.language(txt);
		}
		else if (pn == "auth"||pn == "authenication"){
			o.authenication(txt);
		}
		else{
			cout<<"Could not find the part name"<<endl;
		}
	}
	else{
		cout<<"Please type gmail or microsoft for the header!"<<endl;
	}
}




