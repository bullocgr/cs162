#include "Fire.hpp"

using namespace std;

void Fire::setSharedSquareBee(bool sharedSquareBee) {this->sharedSquareBee = sharedSquareBee;}

bool Fire::getSharedSquareBee() {return this->sharedSquareBee;}

void Fire::turn(vector<vector<Insect*> > &board, int x) {
	if (this->armor <= 0) {
		for (int j = 0; j < board[x].size(); j++) {
			if (board[x][j]->getName() == "Bee") {
				board[x][j]->setArmor(0);
			}
		}
	}
}

Fire::Fire() {
	this->armor = 1;
	this->foodCost = 4;
	this->sharedSquareBee = false;
	this->name = "Fire";
}