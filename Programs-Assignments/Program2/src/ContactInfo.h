/*
 * ContactInfo.h
 *
 *  Created on: Feb 15, 2022
 *      Author: Aweso
 */

#ifndef CONTACTINFO_H_
#define CONTACTINFO_H_

#include <string>
#include <iostream>

class ContactInfo{
public:
	ContactInfo();//default constructor
	~ContactInfo();//deconstructor
	void getName(std::string inputfile);
	void getParty(std::string text);
	void getHomeAddress(std::string text);
	void getBusinessAddress(std::string text);
	void getHomeNumber(std::string text);
	void getBusinessNumber(std::string text);
	void getRegion(std::string text);
	void ErrorMessage(std::string inputfile);
	void printContactInfo(std::string file);
};


#endif /* CONTACTINFO_H_ */
