#ifndef FIRE_HPP
#define FIRE_HPP

#include "Insect.hpp"

using namespace std;

class Fire:public Insect {
private:
	bool sharedSquareBee;

public:
	void setSharedSquareBee(bool sharedSquare);

	bool getSharedSquareBee();

	void turn(vector<vector<Insect*> > &board, int x);

	Fire();
};

#endif