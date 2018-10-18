#ifndef BODYGUARD_HPP
#define BODYGUARD_HPP

#include "Insect.hpp"

using namespace std;

class Bodyguard:public Insect {
private:
	bool sharedSquareAnt;

public:
	void setSharedSquareAnt(bool sharedSquareAnt);

	bool getSharedSquareAnt();

	void turn(vector<vector<Insect*> > &board, int x);
	
	Bodyguard();
};

#endif