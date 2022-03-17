#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include "./Factorial.cpp"
#include "./CombinedNumbers.cpp"

using namespace std;

long long get_num(string prompt){
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

void get_nums(string prompt){
    cout<<prompt<<endl;
    bool again = false;
    while (again != false){
        long int n, r;
        cin >> n >> r;
        cout<<"Factorial Fun "<<n<<" "<<r<<endl;
        if (isdigit(n)==true&isdigit(r)==true){
            auto start = chrono::steady_clock::now();
            //long int g = cn.combined(n,r);
            auto end = chrono::steady_clock::now();
            chrono::duration<double> diff_in_seconds = end-start;
            //cout<<g<<endl;
            cout<<"Time for processing "<< diff_in_seconds.count() <<" seconds"<<endl;
            again = false;
        }
        else{
            cout<<prompt<<endl;
        }
    }
}

bool isNumber(string s){
    for (int i = 0; i<s.length(); i++){
        if (isdigit(s[i]) == false){
            return false;
        }
    }
    return true;
}

string get_string(string prompt){
    cout<<prompt<<endl;
    while(true){
        string line;
        getline(cin, line);
        if (isNumber(line)==false){
            return line;
        }
        else{
            cout<<prompt<<endl;
        }
    }
}

void print(long long n){
    cout<<"Factorial Fun "<<n<<endl;
}

int main(){

    Factorial g;

    string response = get_string("Please enter F for Factorial. Please enter C for Combinational");
    if (response == "F"||response=="f"){
        long long ans = get_num("Please type a postive integer");
        print(ans);
        auto start = chrono::steady_clock::now();
        long long factorial = g.factorial(ans);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> diff_in_seconds = end-start;
        if(factorial==ans){
            cout<<"n cannot be higher than 20"<<endl;
        }
        else if (factorial==-1){
            cout<<"please don't enter a negative number"<<endl;
        }
        else{
            cout<<factorial<<endl;
            cout<<"Time for processing "<< diff_in_seconds.count() <<" seconds"<<endl;
        }
        
    }
    else if (response=="C"||response=="c"){
        CombinedNumbers cn;
        cout<<"Please type two integers"<<endl;
        bool again = true;
        while (again != false){
        long long n,r;
            n = get_num("Please type in n");
            r = get_num("Please type in r");
            if (n>20){
                cout<<"n cannot be higher than 20"<<endl;
            }
            else if(n<r||r<0){
                cout<<"input error please try again"<<endl;
            }
            else{
                auto start = chrono::steady_clock::now();
                long long g = cn.combined(n,r);
                auto end = chrono::steady_clock::now();
                chrono::duration<double> diff_in_seconds = end-start;
                if (g == 1||g==-1){
                    g = 1;
                    cout<<"Factorial Fun "<<n<<" "<<r<<endl;
                    cout<<g<<endl;
                    cout<<"Time for processing "<< diff_in_seconds.count() <<" seconds"<<endl;
                    again = false;
                }
                else{
                    cout<<"Factorial Fun "<<n<<" "<<r<<endl;
                    cout<<g<<endl;
                    cout<<"Time for processing "<< diff_in_seconds.count() <<" seconds"<<endl;
                    again = false;
                }

            }
        }
    }
    else{
        cout<<"Sorry try something else"<<endl;
    }
}