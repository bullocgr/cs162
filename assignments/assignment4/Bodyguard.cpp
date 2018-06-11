#include "Bodyguard.hpp"

using namespace std;

void Bodyguard::setSharedSquareAnt(bool sharedSquareAnt) {this->sharedSquareAnt = sharedSquareAnt;}

bool Bodyguard::getSharedSquareAnt() {return this-> sharedSquareAnt;}

void Bodyguard::turn(vector<vector<Insect*> > &board, int x) {
	for (int j = 0; j < board[x].size(); j++) {
		if (board[x][j]->getName() == "Bee" && board[x][j]->getArmor() > 0) {
			board[x][j-1]->changeArmor(-1);
		}
	}
}

Bodyguard::Bodyguard() {
	this->armor = 2;
	this->foodCost = 4;
	this->sharedSquareAnt = true; //can assume that the user will put it on a square with an ant but check for that later
	this->name = "Bodyguard";
}