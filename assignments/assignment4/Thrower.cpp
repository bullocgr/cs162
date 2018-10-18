#include "Thrower.hpp"

using namespace std;

void Thrower::setSharedSquare(bool sharedSquare) {this->sharedSquare = sharedSquare;}

bool Thrower::getSharedSquare() {return this->sharedSquare;}

void Thrower::turn(vector<vector<Insect*> > &board, int x) {
	for(int j = 0; j < board[x].size(); j++) {
		if(board[x][j]->getName() == "Bee" && board[x][j]->getArmor() > 0) {
			board[x][j]->changeArmor(-1);
		}
	}
}

Thrower::Thrower(){
	this->armor = 1;
	this->damage = 1;
	this->foodCost = 4;
	this->sharedSquare = false;
	this->name = "Thrower";
}