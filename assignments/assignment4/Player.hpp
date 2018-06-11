#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Insect.hpp"
#include "Bee.hpp"
#include "Bodyguard.hpp"
#include "Fire.hpp"
#include "Harvester.hpp"
#include "LongThrower.hpp"
#include "Ninja.hpp"
#include "ShortThrower.hpp"
#include "Thrower.hpp"
#include "Wall.hpp"

using namespace std;

class Player {
private:
	int food;

public:
	void setFood(int food);

	int getFood();

	void addAnt(vector<vector<Insect*> > &board);
	void printBoard(vector<vector<Insect*> > &board);
	void runGame(vector<vector<Insect*> > &board);
	void addBee(vector<vector<Insect*> > &board);
	void turn(vector<vector<Insect*> > &board);
	void harvester(vector<vector<Insect*> > &board);
	void removeDead(vector<vector<Insect*> > &board);
	void deleteBoard(vector<vector<Insect*> > &board);
	int beeCounter(vector<vector<Insect*> > &board);
	bool endGame(vector<vector<Insect*> > &board, int numBees);

	Player();
};

#endif