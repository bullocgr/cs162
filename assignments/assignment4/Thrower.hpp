#ifndef THROWER_HPP
#define THROWER_HPP

#include "Insect.hpp"

using namespace std;

class Thrower:public Insect {
private:
	bool sharedSquare;

public:
	void setSharedSquare(bool sharedSquare);

	bool getSharedSquare();

	void turn(vector<vector<Insect*> > &board, int x);

	Thrower();
};

#endif