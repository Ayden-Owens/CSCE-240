/*
 * PersonalInfo.h
 *
 *  Created on: Feb 21, 2022
 *      Author: Aweso
 */

#ifndef PERSONALINFO_H_
#define PERSONALINFO_H_

#include <string>
#include <iostream>

class PersonalInfo{
public:
	PersonalInfo();//default constructor
	~PersonalInfo();//deconstructor
	void printPersonalInfo(std::string inputfile);
	void getMaritialStatus(std::string text);
	void getChildren(std::string text);
	void getBirthday(std::string text);
	void getEducation(std::string text);
	void ErrorMessage(std::string inputfile);
};



#endif /* PERSONALINFO_H_ */
