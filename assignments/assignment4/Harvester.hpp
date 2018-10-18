#ifndef HARVESTER_HPP
#define HARVESTER_HPP

#include "Insect.hpp"

using namespace std;

class Harvester:public Insect {
public:
	void turn(vector<vector <Insect*> >& board, int x);
	
	Harvester();
	~Harvester();
};

#endif