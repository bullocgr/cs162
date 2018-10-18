#ifndef WALL_HPP
#define WALL_HPP

#include "Insect.hpp"

using namespace std;

class Wall:public Insect {
private:
	bool block;

public:
	void setBlock(bool block);

	bool getBlock();

	void turn(vector<vector<Insect*> > &board, int x);

	Wall();
};

#endif