#ifndef CONTACTINFO_H_
#define CONTACTINFO_H_

#include <string>
#include <iostream>

class ContactInfo{
public:

	
	ContactInfo();//default constructor

	void getName(std::string text);
	void getParty(std::string text);
	void getHomeAddress(std::string text);
	void getBusinessAddress(std::string text);
	void getHomeNumber(std::string text);
	void getBusinessNumber(std::string text);
	void getRegion(std::string text);
	void printContactInfo(std::string file);
	virtual ~ContactInfo();//deconstructor
};


#endif /* CONTACTINFO_H_ */