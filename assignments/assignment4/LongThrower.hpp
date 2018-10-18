#ifndef LONG_THROWER_HPP
#define LONG_THROWER_HPP

#include "Insect.hpp"

using namespace std;

class LongThrower:public Insect {
private:
	int length;

public:
	void setLength(int length);

	int getLength();

	void turn(vector<vector<Insect*> > &board, int x);
	

	LongThrower();
};

#endif