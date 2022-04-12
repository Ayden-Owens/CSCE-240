#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include "./Counter.cpp"
#include "./ConversationSaver.cpp"
#include "./Keywords.cpp"
#include "./Breakdown.cpp"
#include "./ContactInfo.cpp"
#include "./PersonalInfo.cpp"
#include "./CommitteeAssignments.cpp"


using namespace std;

ConversationSaver cs;

string toLower(string input){
    for_each(input.begin(), input.end(), [](char &c)
        { c = ::tolower(c); });
    return input;
}

int get_num(string time, string prompt){
    cout<<prompt<<endl;

    cs.saver(time, "cpu: "+prompt);
    cs.cpu++;
    
    while(true){
        string line;
        getline(cin, line);
        cs.user++;
        
        try{
            long long num =stoi(line);
            return num;
        }
        catch(invalid_argument e){
            cout<<prompt<<endl;
            cs.saver(time, "cpu: "+prompt);
            cs.cpu++;
        }
    }
}

int main(){

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%m-%d-%Y %H-%M-%S");
    auto str = oss.str();

    //start time
    auto start = chrono::steady_clock::now();

    Breakdown k;
    string text;
    string district;
    string name;
    bool restart = false;
    cout << "If you need to exit for any reason please type q or quit"<<endl;
    cout << "Please enter district number"<<endl;
    cout << "Then type in a question"<<endl;
    cs.saver(str, "cpu: If you need to exit for any reason please type q or quit");
    cs.saver(str, "cpu: Please enter district number ");
    cs.cpu++;
    cs.cpu++;

    string file;
    while(restart != true){
        string ans;
        string fullFilename;
        getline(cin,ans);//get user input
        cs.saver(str, "user: " + ans);
        cs.user++;
        string input = toLower(ans);
        string reply = k.split(input);
        int option;
        ContactInfo c;
        PersonalInfo p;
        CommitteeAssignments a;

        if (reply == "77"){//opening file up
            fullFilename = "district" + input;
            string name = fullFilename+".txt";
            file = "../../myrep-chatbot/data/";
            file += name;
            ifstream infile;
            infile.open(file, ios::in);
            if (infile.is_open()){
                string line;
                while(getline(infile, line)){
                    text+=line;
                    text+="\n";
                }
                infile.close();
                cout<<"Hi, Welcome my name is Mandy I'm your chatbot!"<<endl;
                cout<<"##############################################################################"<<endl;
                cout<<"if you'd like an example question just type example"<<endl;
                cout<<"If you want to look at chat statistics just type summary"<<endl;
            }
            else{
                cout<<"couldn't open file"<<endl;
                cs.saver(str, "cpu: couldn't open file");
                cs.cpu++;
            }
    
            cs.saver(str, "cpu: Hi, Welcome my name is Mandy I'm your chatbot!");
            cs.cpu++;
            cs.saver(str, "cpu: ##############################################################################");
            cs.cpu++;
            cs.saver(str, "if you'd like an example question just type example");
            cs.cpu++;
            cs.saver(str, "If you want to look at chat statistics just type summary");
            cs.cpu++;
        }
        else if (reply == "name"){
                cout<<"I assume you mean the name of the representative"<<endl;
                cs.saver(str, "cpu: I assume you mean the name of the representative");
                cs.cpu++;
                c.getName(str, text);

        }//end of if
        else if (reply == "live"||reply == "address"){
                cout<<"I assume you mean where the representative's lives"<<endl;
                cs.saver(str, "cpu: I assume you mean where the representative's lives");
    
                //checks if response is a number
                option = get_num (str, "Type 1 for his business address or type 2 for his columbia address or if you didn't want either just type any number");
            if (option == 1){
                    c.getBusinessAddress(str, text);
        
            }
            else if (option == 2){
                    c.getHomeAddress(str, text);
            }
            else {
                    cout<<"Sorry, I assumed you wanted to know the address"<<endl;
                    cs.saver(str, "cpu: Sorry, I assumed you wanted to know the address");
            }
        }
        else if (reply == "party"){
                c.getParty(str, text);

        }
        else if(reply == "contact"){
                cout<<"I assume you want all of the contact information so here you go"<<endl;
                cs.saver(str, "cpu: I assume you want all of the contact information so here you go");
                option = get_num(str, "Type 1 for yes or type any other number for no");
            if(option == 1){
                   c.printContactInfo(str, file);
            }

        }
        else if(reply == "number"|| reply == "phone"){
                cout<<"I assume you want the representative's number"<<endl;
                
                cs.saver(str, "cpu: I assume you want the representative's number");
                cs.cpu++;
                option = get_num(str, "Type 1 for his business number or type 2 for his cell number");
                
            if(option == 1){
                c.getBusinessNumber(str, text);
            }
            else if (option == 2){
                    c.getHomeNumber(str, text);
            }
        }
            //personal info
        else if(reply == "married"){
                cout<<"I assume you want the representative's martial status"<<endl;
                cs.saver(str, "cpu: I assume you want the representative's martial status");
                cs.cpu++;
                p.getMaritialStatus(str, text);
        }
        else if(reply == "children"||reply == "child"|| reply == "kid"|| reply == "kids"){
                cout<<"I assume you want to know if the representative has children"<<endl;
                cs.saver(str, "cpu: I assume you want to know if the representative has children");
                cs.cpu++;
               p.getChildren(str, text);
        }
        else if (reply == "birth"||reply == "birthdate"|| reply == "birthday"){
                cout<<"I assume you want the representative's birthday"<<endl;
                cs.saver(str, "cpu: I assume you want the representative's birthday");
                cs.cpu++;
                p.getBirthday(str, text);
        }
        else if (reply == "parents"|| reply == "parent" ){
                cout<<"I assume you want the representative's parents"<<endl;
                cs.saver(str, "cpu: I assume you want the representative's parents");
                cs.cpu++;
                p.getOfs(str, text);
        }
        else if (reply == "personal"|| reply == "about"){
            cout<<"I assume you want all of the representative's personal info"<<endl;
            cs.saver(str, "cpu: I assume you want all of the representative's personal info");
            cs.cpu++;
            option = get_num(str, "Type 1 for yes or type any number for no");
            if (option == 1){
                p.printInfo(str, file);
            }
        }
            //committee assignments
        else if (reply == "committee"||reply == "committees"){
            cout<<"I assume you want information regarding the representative's committee assignments"<<endl;
            cs.saver(str, "cpu: I assume you want information regarding the representative's committee assignments");
            cs.cpu++;
            a.commitee(str, text);
        }
            //vote record/sponsored bills
        else if (reply == "bills"||reply == "sponsored"){
            cout <<"I assume you want to know about the representative's sponsored bills however we can't provide that type of information, Sorry"<<endl;
            cs.cpu++;
            cs.saver(str, "cpu: I assume you want to know about the representative's sponsored bills however we can't provide that type of information, Sorry");
        }
        else if (reply == "vote" || reply == "voting"){
            cout<<"I assume you want to know about the representative's voting record however we can't provide that type of information, Sorry"<<endl;
            cs.cpu++;
            cs.saver(str, "cpu: I assume you want to know about the representative's voting record however we can't provide that type of information, Sorry");
        }
        else if (reply == "service"){
            cout<<"I assume you want to know about the representative's service in office however we can't provide that information, Sorry"<<endl;
            cs.cpu++;
            cs.saver(str, "cpu: I assume you want to know about the representative's service in office however we can't provide that information, Sorry");
        }
        //print the document
        else if(reply == "whole"||reply == "everything"||reply == "all"){
            cout<<text<<endl;
            cs.cpu++;
            cs.saver(str, "cpu: "+text);
        }
        else if(reply == "q"|| reply == "quit"){
            cout<<"I assume you mean quit so I'm shutting down, Goodbye!"<<endl;
            cs.saver(str, "cpu: I assume you mean quit so I'm shutting down, Goodbye!");
            auto end = chrono::steady_clock::now();
            auto elaspedtime = chrono::duration_cast<chrono::seconds>(end - start).count();
            cs.cpu++;
            int us = cs.user;
            int cu = cs.cpu;
            cs.timeEnd(str, us, cu);
            exit(EXIT_FAILURE);
        }
        else if (reply == "example"){
            cout<<"##############################################################################"<<endl;
            cout<<"Here are some example questions"<<endl;
            cout<<"tell me everything"<<"\n"<<"where does the rep live"<<"\n"<<"How do I contact rep"<<"\n"<<"tell about the representative"<<endl;
            cout<<"##############################################################################"<<endl;
             
            cs.saver(str, "cpu: ##############################################################################");
            cs.cpu++;
            cs.saver(str, "cpu: Here are some example questions");
            cs.cpu++;
            cs.saver(str, "cpu: where does the rep live");
            cs.cpu++;
            cs.saver(str, "cpu: How do I contact rep");
            cs.cpu++;
            cs.saver(str, "cpu: tell about the representative");
            cs.cpu++;
           cs.saver(str, "cpu: ##############################################################################");
            cs.cpu++;
        }
        else if (reply == "summary"){
                cout<<"This is separate from main so to quit just hit 3"<<endl;
                cs.summary();
        }
        else if (reply == "support"){
            cout<<"Supports district77"<<endl;
            cs.saver(str, "cpu: Supports district77");
            cs.cpu++;
        }
        else{
            cout<<"Can you please retype or rephase your response we don't understand"<<endl;
            cs.saver(str, "cpu: Can you please retype or rephase your response we don't understand");
            cs.cpu++;
        }
    

    }
}//end of main