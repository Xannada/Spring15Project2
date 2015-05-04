#ifndef PROJECT_02_H_
#define PROJECT_02_H_

using namespace std;

#include <fstream>
#include <iostream>
#include <string>

struct stadiumNode
{
	string stadiumName;
	string teamName;
	string address1;
	string address2;
	string phone;
	string opening;
	string capacity;
	bool fieldType; // 0 for grass
	bool league;    // 0 for American

	stadiumNode *next;
	stadiumNode *prev;
};

#include "Binary Search Tree.h"
#include "stadium.h"

//#include "Graph.h"
//#include "Stadium.h"

#endif /* PROJECT_02_H_ */
