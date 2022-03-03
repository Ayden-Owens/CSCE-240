#ifndef PERSONALINFO_H_
#define PERSONALINFO_H_

#include <string>
#include <iostream>

class PersonalInfo{
public:
    PersonalInfo();
    ~PersonalInfo();
    void getBirthday(std::string text);
    void getMaritialStatus(std::string text);
	void getChildren(std::string text);
    void getOfs(std::string text);
    void printInfo(std::string input);
};



#endif /* PERSONALINFO_H_ */