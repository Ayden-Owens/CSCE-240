#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <algorithm>
#include "./ContactInfo.cpp"
#include "./PersonalInfo.cpp"
#include "./CommitteeAssignments.cpp"
#include "./ServiceInOffice.cpp"
#include "./ResponseSearch.cpp"

using namespace std;

bool check_number(string str){
    for (int i = 0; i <str.length(); i++){
        if (isdigit(str[i]) == false){
            return false;
        }
        else{
            return true;
        }
    }
}

string toLower(string input){
    for_each(input.begin(), input.end(), [](char &c)
        { c = ::tolower(c); });
    return input;
}

int main(){
    ContactInfo c;
    PersonalInfo p;
    ResponseSearch r;
    string text;
    string fullFilename;
    bool restart = false;
    cout << "If you need to exit for any reaseon please type q or quit"<<"\n"<<endl;
    cout <<"Please enter district, then the district number, and .txt"<<endl;
    string file;
    while(restart != true){
        string inputfile;
        getline(cin,inputfile);
        fullFilename = toLower(inputfile);
        file = "../../Program3/data/";
        file += fullFilename;
        //opening file up
        if(fullFilename == "q"||fullFilename == "quit"){
            cout<<"farwell!"<<endl;
            exit(0);
        }
        else{
            ifstream infile;
            infile.open(file, ios::in);
            if (infile.is_open()){
                string line;
                while(getline(infile, line)){
                    text+=line;
                    text+="\n";
                }
                infile.close();
                restart = true;
            }
            else{
                cout<<"Please enter district, then the district number, and .txt"<<endl;
                cout<<"Your response should look like this: district77.txt"<<endl;
                infile.close();
                restart = false;
            }
        }

    }
    cout<<"\n"<<"\n"<<"\n"<<"\n"<<endl;
    bool again = false;
    string ans;
    cout<<"Hi, Welcome my name is Mandy I'm your chatbot!"<<endl;
    cout<<"##############################################################################"<<endl;
    while (again != true){
            cout<<"Please type a question"<<endl;
            cout<<"if you'd like an example question just type example"<<endl;
            getline(cin, ans);
            string lower = toLower(ans);
            if (lower == "q"||lower == "quit"){
                    cout<<"Goodbye!"<<endl;
                    exit(0);
            }
            else if (lower == fullFilename|| lower == file){
                cout<<"##############################################################################"<<endl;
                cout<<"Please don't enter file name"<<"\n"<<lower<<" - I don't know the information"<<endl;
                cout<<"##############################################################################"<<endl;

            }
            else if (check_number(lower) == true){
                cout<<"##############################################################################"<<endl;
                cout<<"Please do not enter any numbers"<<"\n"<<lower<<" - I don't know the information"<<endl;
            }
            else if (lower == "example"){
                cout<<"##############################################################################"<<endl;
                cout<<"tell me everything"<<"\n"<<"where does the rep live"<<"\n"<<"How do I contact rep"<<"\n"<<"tell about the representative"<<endl;
                cout<<"##############################################################################"<<endl;
            }
            else{
                cout<<"##############################################################################"<<endl;
                r.contact(lower, text, file);
                cout<<"##############################################################################"<<endl;
            }
    }
}
