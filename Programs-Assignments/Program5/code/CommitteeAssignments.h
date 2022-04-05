#ifndef COMMITTEEASSIGNMENTS_H_
#define COMMITTEEASSIGNMENTS_H_

#include <string>
#include <iostream>
#include "./ConversationSaver.h"

class CommitteeAssignments{
public:
	CommitteeAssignments();
	~CommitteeAssignments();
   	void commitee(std::string time, std::string text);
};




#endif /* COMMITTEEASSIGNMENTS_H_ */