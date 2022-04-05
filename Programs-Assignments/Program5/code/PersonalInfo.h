#ifndef PERSONALINFO_H_
#define PERSONALINFO_H_

#include <string>
#include <iostream>
#include "./ConversationSaver.h"

class PersonalInfo{
public:
    PersonalInfo();
    ~PersonalInfo();
    void getBirthday(std::string time, std::string text);
    void getMaritialStatus(std::string time, std::string text);
	void getChildren(std::string time, std::string text);
    void getOfs(std::string time, std::string text);
    void printInfo(std::string time, std::string input);
};



#endif /* PERSONALINFO_H_ */