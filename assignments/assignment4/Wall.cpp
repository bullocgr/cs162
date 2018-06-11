#include "Wall.hpp"

using namespace std;

void Wall::setBlock(bool block) {this->block = block;}

bool Wall::getBlock() {return this->block;}

void Wall::turn(vector<vector<Insect*> > &board, int x) {
	// bool block = true;
	// if(block == true) {
	// 	for (int j = 0; j < board.size(); j++) {
	// 		if(board[x][j]->getName() == "Wall" && board[x][j+1]->getName() == "Bee" || board[x][j]->getName() == "Bee" && board[x][j+1]->getName() == "Wall") {
	// 			board[x][j]
	// 		}
	// 	}
	// }
}

Wall::Wall() {
	this->armor = 4;
	this->foodCost = 4;
	this->block = true; //you can assume this is true because the player will only put this next to bees
	this->name = "Wall";
	this->damage = 0;
}