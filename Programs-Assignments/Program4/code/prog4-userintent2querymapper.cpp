#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "./Counter.cpp"
#include "./Keywords.cpp"
#include "./Breakdown.cpp"
#include "./ContactInfo.cpp"
#include "./PersonalInfo.cpp"
#include "./CommitteeAssignments.cpp"


using namespace std;

string toLower(string input){
    for_each(input.begin(), input.end(), [](char &c)
        { c = ::tolower(c); });
    return input;
}

bool isNumber(string s){
    for (int i = 0; i<s.length(); i++){
        if (isdigit(s[i]) == false){
            return false;
        }
    }
    return true;
}

int get_num(string prompt){
    cout<<prompt<<endl;
    while(true){
        string line;
        getline(cin, line);
        try{
            long long num =stoi(line);
            return num;
        }
        catch(invalid_argument e){
            cout<<prompt<<endl;
        }
    }
}

int main(){
    Breakdown k;
    string text;
    string fullFilename;
    bool restart = false;
    cout << "If you need to exit for any reason please type q or quit"<<"\n"<<endl;
    cout <<"Please enter district, then the district number, and .txt"<<endl;
    string file;
    while(restart != true){
        string inputfile;
        getline(cin,inputfile);
        fullFilename = toLower(inputfile);
        file = "../../Program4/data/";
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
        if (isNumber(lower) == true){
            cout<<"##############################################################################"<<endl;
            cout<<"Please do not enter any numbers"<<"\n"<<lower<<" - I don't know the information"<<endl;
        }//end of if
        else{
            cout<<"##############################################################################"<<endl;
            string reply = k.split(lower);
            int option;
            ContactInfo c;
            PersonalInfo p;
            CommitteeAssignments a;
            if (reply == "name"){
                cout<<"I assume you mean the name of the representative"<<endl;
                c.getName(text);
            }//end of if
            else if (reply == "live"||reply == "address"){
                cout<<"I assume you mean where the representative's lives"<<endl;
                //checks if response is a number
                option = get_num ("Type 1 for his business address or type 2 for his columbia address or if you didn't want either just type any number");
                if (option == 1){
                    c.getBusinessAddress(text);
                }
                else if (option == 2){
                    c.getHomeAddress(text);
                }
                else {
                    cout<<"Sorry, I assumed you wanted to know the address"<<endl;
                }
            }
            else if (reply == "party"){
                c.getParty(text);
            }
            else if(reply == "contact"){
                cout<<"I assume you want all of the contact information so here you go"<<endl;
                option = get_num ("Type 1 for yes or type any number for no");
                if(option == 1){
                    c.printContactInfo(file);
                }
            }
            else if(reply == "number"|| reply == "phone"){
                cout<<"I assume you want the representative's number"<<endl;
                option = get_num("Type 1 for his business number or type 2 for his cell number");
                if(option == 1){
                    c.getBusinessNumber(text);
                }
                 else if (option == 2){
                     c.getHomeNumber(text);
                 }
            }
            //personal info
            else if(reply == "married"){
                cout<<"I assume you want the representative's martial status"<<endl;
                p.getMaritialStatus(text);
            }
            else if(reply == "children"||reply == "child"|| reply == "kid"|| reply == "kids"){
                cout<<"I assume you want to know if the representative has children"<<endl;
                p.getChildren(text);
            }
             else if (reply == "birth"||reply == "birthdate"|| reply == "birthday"){
                cout<<"I assume you want the representative's birthday"<<endl;
                p.getBirthday(text);
            }
            else if (reply == "parents"|| reply == "parent" ){
                cout<<"I assume you want the representative's parents"<<endl;
                 p.getOfs(text);
            }
            else if (reply == "personal"|| reply == "about"){
                cout<<"I assume you want all of the representative's personal info"<<endl;
                option = get_num("Type 1 for yes or type any number for no");
                if (option == 1){
                    p.printInfo(file);
                }
            }
                //committee assignments
            else if (reply == "committee"||reply == "committees"){
                cout<<"I assume you want information regarding the representative's committee assignments"<<endl;
                a.commitee(text);
            }
                //vote record/sponsored bills
            else if (reply == "bills"||reply == "sponsored"){
                cout <<"I assume you want to know about the representative's sponsored bills however we can't provide that type of information, Sorry"<<endl;
            }
            else if (reply == "vote" || reply == "voting"){
                cout<<"I assume you want to know about the representative's voting record however we can't provide that type of information, Sorry"<<endl;
            }
            else if (reply == "service"){
                cout<<"I assume you want to know about the representative's service in office however we can't provide that information, Sorry"<<endl;
            }
            //print the document
            else if(reply == "whole"||reply == "everything"||reply == "all"){
                cout<<text<<endl;
            }
            else if(reply == "q"|| reply == "quit"){
                cout<<"I assume you mean quit so I'm shutting down, Goodbye!"<<endl;
                exit(EXIT_FAILURE);
            }
            else if (reply == "example"){
                cout<<"##############################################################################"<<endl;
                cout<<"Here are some example questions"<<endl;
                cout<<"tell me everything"<<"\n"<<"where does the rep live"<<"\n"<<"How do I contact rep"<<"\n"<<"tell about the representative"<<endl;
                cout<<"##############################################################################"<<endl;
            }
            else{
                cout<<"Can you please retype or rephase your question we don't understand"<<endl;
            }
        }//end of num else
    }//end of while
            

}//end of main