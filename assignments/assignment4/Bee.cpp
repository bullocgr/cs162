#include "Bee.hpp"

using namespace std;

void Bee::setMove(int move) {this->move = move;}
void Bee::setAtQueen(bool atQueen) {this->atQueen = atQueen;}
void Bee::setCanMove(bool canMove) {this->canMove = canMove;}

int Bee::getMove() {return this->move;}
bool Bee::getAtQueen() {return this->atQueen;}
bool Bee::getCanMove() {return this->canMove;}

void Bee::turn(vector<vector<Insect*> > &board, int x) {
	bool moved = true;
	for (int j = 0; j < board[x].size(); j++) {
		if (board[x][j]->getName() == "Bee" || board[x][j]->getName() == "Ninja" || board[x][j]->getArmor() <= 0) {
			continue;
		}
		if (board[x][j]->getName() == "Bodyguard") {
			board[x][j]->changeArmor(-1);
			moved = false;
		}
		board[x][j]->changeArmor(-1);
		moved = false;
	}

	if (moved == true) {
		for (int j = 0; j < board[x].size(); j++) {

			if (board[x][j]->getName() == "Bee") {
				board[x - 1].push_back(board[x][j]);
				delete [] board[x][j];
				board[x].erase(board[x].begin() + j);
				break;
			}
		}
	}
}

Bee::Bee() {
	this->move = 0;
	this->atQueen = false;
	this->canMove = false;
	this->armor = 3;
	this->damage = 1;
	this->name = "Bee";
}