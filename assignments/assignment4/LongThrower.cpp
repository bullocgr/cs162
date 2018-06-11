#include "LongThrower.hpp"

using namespace std;

void LongThrower::setLength(int length) {this->length = length;}

int LongThrower::getLength() {return this->length;}

void LongThrower::turn(vector<vector<Insect*> > &board, int x) {
	for (int j = x + 4; j < board.size(); j++) {
		if (board[j].size() != 0) {
			for (int i = 0; i < board[j].size(); i++) {
				if (board[j][i]->getName() == "Bee" && board[j][i]->getArmor() > 0) {
					board[j][i]->changeArmor(-1);
				}
			}
		}
	}
}


LongThrower::LongThrower() {
	this->armor = 1;
	this->damage = 1;
	this->foodCost = 3;
	this->length = 4; //this is how far the ant can do damage
	this->name = "Long Thrower";
}