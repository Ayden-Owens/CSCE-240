#ifndef CONVERSATIONSAVER_H_
#define CONVERSATIONSAVER_H_

#include <string>
#include <chrono>

class ConversationSaver{
public:
ConversationSaver();
~ConversationSaver();
void saver(std::string time, std::string utter);
void timeStart();
void timeEnd(std::string time, int user_num, int cpu_num);
public: 
int cpu = 0;
int user = 0;
std::chrono::_V2::steady_clock::time_point start = std::chrono::steady_clock::now();
};

#endif /* CONVERSATIONSAVER_H_ */