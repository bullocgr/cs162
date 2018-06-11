#ifndef BEE_HPP
#define BEE_HPP
#include "Insect.hpp"

class Bee:public Insect {
private:
	int move;
	bool atQueen;
	bool canMove;

public:
	void setMove(int move);
	void setAtQueen(bool atQueen);
	void setCanMove(bool canMove);

	int getMove();
	bool getAtQueen();
	bool getCanMove();

	void turn(vector<vector<Insect*> > &board, int x);

	Bee();
	~Bee();
	//operator overload
};

#endif