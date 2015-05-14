#ifndef PROJECT_02_H_
#define PROJECT_02_H_

using namespace std;

#include <iomanip>
#include <limits>
#include <fstream>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <vector>

// Used in the priority queue to output stadiums
// alpha by name
struct stadiumCompare
{
	string stadiumName;
	string teamName;
	string address1;
	string address2;
	string phone;
	string opening;
	string capacity;
	bool league;    // 0 for American
	bool fieldType; // 0 for grass

    bool operator<(const stadiumCompare& test) const
    {
        return stadiumName > test.stadiumName;
    }
};

// Used in the priority queue to output teams
// alpha by name
struct teamCompare
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

    bool operator<(const teamCompare& test) const
    {
        return teamName > test.teamName;
    }
};

// Used in the priority queue to output stadiums
// in chrono order
struct openingCompare
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

    bool operator<(const openingCompare& test) const
    {
    	const int first = opening.size() - 4;
    	const int second = test.opening.size() - 4;
        return opening.substr(first, 4) > test.opening.substr(second, 4);
    }
};

// Used in the priority queue to output stadiums
// by seating capacity
struct seatingCompare
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

    bool operator<(const seatingCompare& test) const
    {
        return capacity > test.capacity;
    }
};

// possible states for the vertices and edges
enum State{
	UNEXPLORED,
	VISITED
};

struct Vertex;

// contains information for an edge
struct Edge{
	Vertex* start;
	Vertex* end;
	int weight;
	Edge(int w, Vertex* s, Vertex* e){
		weight = w;
		start  = s;
		end    = e;
	}
};

// contains information for a vertex
struct Vertex{
	string name;
	vector<Edge> edges;
	vector<Vertex*> verticesTo;
	State state;
	int weightTo;

	Vertex(string n, int l = 0){
		name = n;
		weightTo = std::numeric_limits<int>::max();
		state = UNEXPLORED;
	}
	void add(Edge e){
		edges.push_back(e);
	}
};

#include "stadium.h"

#endif /* PROJECT_02_H_ */
