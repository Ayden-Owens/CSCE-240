#ifndef CONTACTINFO_H_
#define CONTACTINFO_H_

#include <string>
#include <iostream>
#include "./ConversationSaver.h"

class ContactInfo{
public:

	
	ContactInfo();//default constructor

	void getDistrict(std::string time, std::string text);
	void getName(std::string time, std::string text);
	void getParty(std::string time, std::string text);
	void getHomeAddress(std::string time, std::string text);
	void getBusinessAddress(std::string time, std::string text);
	void getHomeNumber(std::string time, std::string text);
	void getBusinessNumber(std::string time, std::string text);
	void getRegion(std::string time, std::string text);
	void printContactInfo(std::string time, std::string file);
	virtual ~ContactInfo();//deconstructor
};


#endif /* CONTACTINFO_H_ */