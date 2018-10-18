#include "ShortThrower.hpp"

using namespace std;

void ShortThrower::setLength(int length) {this->length = length;}

int ShortThrower::getLength() {return this->length;}

void ShortThrower::turn(vector<vector<Insect*> > &board, int x) {
	for (int j = x + 2; j < board.size(); j++) {
		if (board[j].size() != 0) {
			for (int i = 0; i < board[j].size(); i++) {
				if (board[j][i]->getName() == "Bee" && board[j][i]->getArmor() > 0) {
					board[j][i]->changeArmor(-1);
				}
			}
		}
	}
}

ShortThrower::ShortThrower () {
	this->armor = 1;
	this->damage = 1;
	this->foodCost = 3;
	this->length = 2; //same idea as the long thrower but only 2 squares away
	this->name = "Short Thrower";
}