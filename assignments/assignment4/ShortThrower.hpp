#ifndef SHORT_THROWER_HPP
#define SHORT_THROWER_HPP

#include "Insect.hpp"

using namespace std;

class ShortThrower: public Insect {
private:
	int length;

public:
	void setLength(int length);

	int getLength();
	void turn(vector<vector<Insect*> > &board, int x);

	ShortThrower();
};

#endif