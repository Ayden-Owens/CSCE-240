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
    string file = "../../Program5/data/chat_sessions/";
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
    
    
    statfile.open("../../Program5/data/chat_sessions/chat_statistics.csv", fstream::app);
    
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
    string cname = "../../Program5/data/chat_sessions/chat_statistics.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

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
    inputnum--;
    cout << "Number of lines is: " << inputnum << endl;
    cout << "Would you like to showchat, showchat summary or end? Press 1, 2 or 3" << endl;
    cin >> outputnum;
    if (outputnum == 1)
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
            exit(0);
        }
    }
    else if (outputnum == 2)
    {

        cout << "Which chat summary would you like to see? Note the limit is " << inputnum << "." << endl;
        cin >> outputnum;
        if (outputnum > inputnum)
        {
            cout << "Error, there are only " << inputnum << " chats." << endl;
        }
        else if (outputnum == 0)
        {
            cout << "Error, that is the title line." << endl;
        }
        else
        {
            checking = content[outputnum][0];
            printer(checking);
            exit(0);
        }

    }
    else if (outputnum == 3)
    {

        cout << "Thank you, Bye" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Sorry there was an error, we will assume you mean stop" << endl;
        exit(0);
    }
}

void ConversationSaver :: printer(string inputfile)
{
    {

        ifstream inFile;
        string path = "../../Program5/data/chat_sessions/";
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
        }
    }
}


