#include "./ResponseSearch.h"
#include <string>
#include <regex>
#include <iostream>

using namespace std;

ResponseSearch::ResponseSearch(){};
ResponseSearch::~ResponseSearch(){};

void ResponseSearch :: contact(string answer, string text, string filename){
    ContactInfo c;
    PersonalInfo p;
    CommitteeAssignments a;

    smatch m;
    //general info
    regex personal ("tell me about the (repo|rep|resentative)*");
    regex contact ("how do i contact my (rep|repo|representative)");
    regex everything("tell me everything");

    //vote record
    regex vote ("(.*)(vote record)(.*)");

    //SponsoredBills
    regex sponsored ("(rep|repo|representative|rep's|repo's|representative's)* sponsored bills");

    //service info
    regex service3 ("service.+ (rep|repo|representative|rep's|repo's|representative's)*in office");
    regex service2 ("service in office");
    regex service1 (".+(rep|repo|representative|rep's|repo's|representative's)* service in office");

    //committee info
    regex committee3 ("(rep|repo|representative|rep's|repo's|representative's) committee (assignments|info|information)");
    regex committee2 ("(info|information).+(rep|repo|representative|rep's|repo's|representative's)* committee");
    regex committee1 ("what committe[e|es]* is my (rep|repo|representative) on");

    //personal info
    regex child3 ("does.+ (rep|repo|representative) have a (child|kid)");
    regex child2 ("does.+ (rep|repo|representative) have (children|kids)");
    regex child1 ("how many (kids|children) does.* (rep|repo|representative) have");

    regex parents2 ("(parent's|parents).+(rep|repo|representative|rep's|repo's|representative's)");
    regex parents1 ("who.+ the* (rep|repo|representative|rep's|repo's|representative's)* parents*");

    regex birth3 ("when.+(rep|repo|representative|rep's|repo's|representative's)* born");
    regex birth2 (".*(rep|repo|representative|rep's|repo's|representative's)* date of birth");
    regex birth1 ("when.+ (rep|repo|representative|rep's|repo's|representative's)* (birthday|birthdate)");

    regex marry3 (".*(rep|repo|representative|rep's|repo's|representative's)* marital status");
    regex marry2 (".*(rep|repo|representative|rep's|repo's|representative's)+ single");
    regex marry1 (".*(rep|repo|representative|rep's|repo's|representative's)* married");

    //check for conjunctions
    regex check (".*( and | if | except | also | as well as | include | plus | but | or ).*");
    
    //contact info stuff
    regex party1 (".+(rep|repo|representative|rep's|repo's|representative's)* party");
    regex party2 ("party.+(rep|repo|representative)*");

    regex region3 (".*(rep|repo|representative|rep's|repo's|representative's).+district");
    regex region2 ("district.+(rep|repo|representative)*");
    regex region1 (".*(rep|repo|representative|rep's|repo's|representative's)* region");

    regex hAddress4 (".*(h|home) address.*(rep|repo|representative)*");
    regex hAddress3 (".*(rep's|repo's|representative's|rep|repo|representative)* (h|home) address");
    regex hAddress2 ("where* do(es)* (they|he|she|the).* (live|stay)*");
    regex hAddress1 ("where does (representative|repo|rep)* (live|stay|stay at)*");
    
    regex bAddress2 ("(business|b) address.*(rep|repo|representative)*");
    regex bAddress1 ("(rep|repo|representative|rep's|repo's|representative's)* (business|b) address");
    
    regex bnum2 (".+ (rep|repo|representative|rep's|repo's|representative's)* [business|b]+ phone number");
    regex bnum1 ("[business|b]+ phone number.+(rep|repo|representative)*");
    
    regex home2num ("[h|home]* phone number.+(rep|repo|representative)*");
    regex home1num (".+(rep|repo|representative|rep's|repo's|representative's)* [h|home]* phone number");
    
    regex name3 (".+(repo|rep|representative|rep's|repo's|representative's).*(name)+");
    regex name1 (".+(repo|rep|representative|rep's|repo's|representative's).*name");
    regex name2 ("name.*(rep|repo|representative)");

    if (regex_match(answer, check)){
        cout<<answer<<" - I do not know this information"<<endl;
        cout<<"Please do not use and, or, plus and etc. in your answers."<<" Ask only one question at a time for example: rep's name "<<endl;
    }
    else{
        if (regex_match(answer, name1)){
            c.getName(text);
        }
        else if (regex_match(answer, name3)){
            c.getName(text);
        }
        else if (regex_match(answer, name2)){
            c.getName(text);
        }
        else if (regex_match(answer, home1num)){
            c.getHomeNumber(text);
        }
        else if (regex_match(answer, home2num)){
            c.getHomeNumber(text);
        }
        else if (regex_match(answer, bnum1)){
            c.getBusinessNumber(text);
        }
        else if (regex_match(answer, bnum2)){
            c.getBusinessNumber(text);
        }
        else if (regex_match(answer, bAddress1)){
            c.getBusinessAddress(text);
        }
        else if (regex_match(answer, bAddress2)){
            c.getBusinessAddress(text);
        }
        else if (regex_match(answer, hAddress1)){
            c.getHomeAddress(text);
        }
        else if (regex_match(answer, hAddress2)){
            c.getHomeAddress(text);
        }
        else if (regex_match(answer, hAddress3)){
            c.getHomeAddress(text);
        }
        else if (regex_match(answer, hAddress4)){
            c.getHomeAddress(text);
        }
        else if (regex_match(answer, region1)){
            c.getRegion(text);
        }
        else if (regex_match(answer, region1)){
            c.getRegion(text);
        }
        else if (regex_match(answer, region2)){
            c.getRegion(text);
        }
        else if (regex_match(answer, region3)){
            c.getRegion(text);
        }
        else if (regex_match(answer, party1)){
            c.getParty(text);
        }
        else if (regex_match(answer, party2)){
            c.getParty(text);
        }
        //start of personal questions
        else if (regex_match(answer, marry1)){
            p.getMaritialStatus(text);
        }
        else if (regex_match(answer, marry2)){
            p.getMaritialStatus(text);
        }
        else if (regex_match(answer, marry3)){
            p.getMaritialStatus(text);
        }
        else if (regex_match(answer, birth1)){
            p.getBirthday(text);
        }
        else if (regex_match(answer, birth2)){
            p.getBirthday(text);
        }
        else if (regex_match(answer, birth3)){
            p.getBirthday(text);
        }
        else if (regex_match(answer, parents1)){
            p.getOfs(text);
        }
        else if (regex_match(answer, parents2)){
            p.getOfs(text);
        }
        else if (regex_match(answer, child1)){
            p.getChildren(text);
        }
        else if (regex_match(answer, child2)){
            p.getChildren(text);
        }
        else if (regex_match(answer, child3)){
            p.getChildren(text);
        }
        //committee questions
        else if (regex_match(answer, committee1)){
            a.commitee(text);
        }
        else if (regex_match(answer, committee2)){
            a.commitee(text);
        }
        else if (regex_match(answer, committee3)){
            a.commitee(text);
        }
        else if (regex_match(answer, service1)){
            cout<<answer<<" - I do not know this information"<<endl;
        }
        else if (regex_match(answer, service2)){
            cout<<answer<<" - I do not know this information"<<endl;
        }
        else if (regex_match(answer, service3)){
            cout<<answer<<" - I do not know this information"<<endl;
        }
        else if (regex_match(answer, sponsored)){
            cout<<answer<<" - I do not know this information"<<endl;
        }
        else if (regex_match(answer, sponsored)){
            cout<<answer<<" - I do not know this information"<<endl;
        }
        else if (regex_match(answer, everything)){
            cout<<text<<endl;
        }
        else if (regex_match(answer, contact)){
            c.printContactInfo(filename);
        }
        else if (regex_match(answer, personal)){
            p.printInfo(filename);
        }
        else{
           cout<<answer<<" - I do not know this information"<<endl; 
        }
    }
    
}