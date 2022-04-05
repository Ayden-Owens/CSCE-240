#include "./ConversationSaver.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

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


