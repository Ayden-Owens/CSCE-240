#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


int main(){
    
    fstream file;
    int line_count=0;
    int word_count=0;
    int char_count=0;//spaces
    string filename;

    cout<<"Please enter District name and .txt"<<endl;
    cin>>filename;
    //convert string to lower case
    
    file.open(filename, ios::in);
    //Handles if the file file is open
    if (file.is_open()){
        cout<<"File successfully opened"<<endl;
    }
    else{
        cout<<"File did not open sorry!"<<endl;
    }
    int cout_emptyline;
    string word;
    string line; //making line variable
    //prints reads the file line by line
    while ( getline(file, line)){
        line_count++;
        //cout<<line<<endl;//prints out each line of the txt in the terminal
        //read word by word from the line
        
        if(line.empty()){//checks to see if the line is empty
            cout_emptyline++;
        }
        else{
            //breaks down the string into smaller strings
            stringstream ss(line);

            while(ss>>word){
                word_count++;
                for (int i = 0;i<word.length();i++){
                char a = word[i];
                    if(a != ' '){
                    char_count++;
                    }

                }
            }

        }
        

    }
    file.close();
    //send data to an output file
    ofstream ofile;
    ofile.open("output.txt", ios::out);
    ofile<<"number of lines "<<line_count<<endl;
    ofile<<"number of empty lines "<<cout_emptyline<<endl;
    ofile<<"words count "<<word_count<<endl;
    ofile<<"characters with no spaces "<<char_count<<endl;
    ofile.close();
}