#include "./ConversationSaver.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <sstream>
#include <vector>

using namespace std;

ConversationSaver :: ConversationSaver(){};

ConversationSaver :: ~ConversationSaver(){};

void ConversationSaver :: saver(string time, string utter){
    string header = time +".txt";
    string file = "../../myrep-chatbot/data/chat_sessions/";
    file+= header;
    ofstream ofile;
    ofile.open(file, ios::app);
    ofile<<utter<<endl;
    ofile.close();
};

void ConversationSaver :: timeStart()
{
    start;
}

void ConversationSaver :: timeEnd(string time, int user_num, int cpu_num)
{
    ofstream statfile;
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = end - start;
    std::chrono::duration<double> diff_in_seconds = end - start;
    
    
    statfile.open("../../myrep-chatbot/data/chat_sessions/chat_stats.csv", fstream::app);
    
    string message = std::to_string(diff_in_seconds.count()) + "sec";
    string stating = time;
    stating += ",";
    stating += std::to_string(user_num);
    stating += ",";
    stating += std::to_string(cpu_num);
    stating += ",";
    stating += std::to_string(diff_in_seconds.count());
    statfile << stating << endl;;
    statfile.close();

}

void ConversationSaver :: summary()
{
    string cname = "../../myrep-chatbot/data/chat_sessions/chat_stats.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    int usersess = 0;
    int cpuess = 0;
    int d_time;
    int inputnum = 0;

    fstream file(cname, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();
            inputnum++;
            stringstream str(line);

            while (getline(str, word, ','))
            row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";

    for (int i = 0; i < content.size(); i++)
    {
        for (int j = 0; j < content[i].size(); j++)
        {
            cout << content[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 1, j = 1; i < content.size(); i++)
    {
        int convert = stoi(content[i][j]);
        usersess = usersess + convert;
    }
    for(int i = 1, j = 2; i < content.size(); i++)
    {
        int convert1 = stoi(content[i][j]);
        cpuess = cpuess + convert1;
    }
    for(int i = 1, j = 3; i < content.size(); i++)
    {
        int convert2 = stoi(content[i][j]);
        d_time = d_time + convert2;
    }
    file.close();
    inputnum--;
    cout<<inputnum<<endl;
    cout << "Would you like a summary enter 1, showchat summary enter 2, showchat enter 3, or exit enter 4" << endl;
    cin >> outputnum;
    if(outputnum == 1){
        cout << "Total number of chats sessions is: " << inputnum << endl;
        cout << "Total number of user responses is: " << usersess << endl;
        cout << "Total number of cpu responses is: " << cpuess << endl;
        cout << "Total duration: " << d_time << endl; 
        summary();
    }
    if (outputnum == 2)
    {

        cout << "Which chat log would you like to see? Note the limit is: " << inputnum << "." << endl;
        cin >> outputnum;
        if (outputnum > inputnum)
        {
            cout << "Error, there are only " << inputnum << " chats." << endl;
            summary();
        }
        else if (outputnum == 0)
        {
            cout << "Error, that is the title line." << endl;
            summary();
        }
        else
        {
            for (int i = 0; i < 1; i++)
            {
                for (int j = 0; j < content[i].size(); j++)
                {
                    cout << content[outputnum][j] << " ";
                }
                cout << "\n";
            }

            cout<< "chat session is "<< content[outputnum][0]<<endl;
            cout<< "number of user utterances "<< content[outputnum][1]<<endl;
            cout<< "number of cpu utterances "<< content[outputnum][2]<<endl;
            cout<< "It lasted " << content[outputnum][3] << "seconds" << endl;
            summary();
        }
    }
    else if (outputnum == 3)
    {

        cout << "Which chat summary would you like to see? Note the limit is " << inputnum << "." << endl;
        cin >> outputnum;
        if (outputnum > inputnum)
        {
            cout << "Error, there are only " << inputnum << " chats." << endl;
            summary();
        }
        else if (outputnum == 0)
        {
            cout << "Error, that is the title line." << endl;
            summary();
        }
        else
        {
            checking = content[outputnum][0];
            printer(checking);
            summary();
        }

    }
    else if (outputnum == 4)
    {

        cout << "Thank you, Bye" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Sorry we don't understand, bye!" << endl;
        exit(EXIT_FAILURE);
    }
}

void ConversationSaver :: printer(string inputfile)
{
    {

        ifstream inFile;
        string path = "../../Program6/data/chat_sessions/";
        string extension = ".txt";
        path += inputfile;
        path += extension;
        inFile.open(path);
        if (inFile.fail())
        {
            cout << "failed" << endl;
        }
        else
        {
            while (getline(inFile, newLine))
            {
                if (newLine.empty())
                {
                    continue;
                }
                else
                {
                    stringstream series(newLine);
                    while (series >> words)
                    {
                        if (holder == newLine)
                        {
                            continue;
                        }
                        else
                        {
                            std::cout << newLine << endl;
                            holder = newLine;
                        }
                    }
                }
            }
            inFile.close();
        }
    }
}


