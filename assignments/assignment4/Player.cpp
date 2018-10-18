#include "Player.hpp"

using namespace std;

void Player::setFood(int food) {this->food = food;}

int Player::getFood() {return this->food;}

/*Function: add ant
Description: this will add an ant to the board when the player wants to
*/

void Player::addAnt(vector<vector<Insect*> > &board) {
	string buy;
	string input;
	string placeInput;
	int place;
	cout << "Would you like to buy an ant(y/n): ";
	getline(cin, buy);
	if (buy == "n" || buy == "no") {
		return;
	}

	if (buy == "yes" || buy == "y") {
		cout << "The ants are:\nBodyguard\nFire\nHarvester\nLong Thrower\nNinja\nShort Thrower\nThrower\nWall\n";
		cout << "What ant would you like to put on the board: ";
		getline(cin, input);
		cout << "Where would you like to place the ant: ";
		getline(cin, placeInput);
		place = atoi(placeInput.c_str());

		if (input == "Bodyguard" || input == "bodyguard") {
			board[place].push_back(new Bodyguard);
			setFood(getFood() - 4);
		}
		if (input == "Fire" || input == "fire") {
			board[place].push_back(new Fire);
			setFood(getFood() - 4);
		}
		if (input == "Harvester" || input == "harvester") {
			board[place].push_back(new Harvester);
			setFood(getFood() - 2);
		}
		if (input == "LongThrower" || input == "longthrower" || input == "Long Thrower" || input == "long thrower") {
			board[place].push_back(new LongThrower);
			setFood(getFood() - 3);
		}
		if (input == "Ninja" || input == "ninja") {
			board[place].push_back(new Ninja);
			setFood(getFood() - 6);
		}
		if (input == "ShortThrower" || input == "shortthrower" || input == "Short Thrower" || input == "short thrower") {
			board[place].push_back(new ShortThrower);
			setFood(getFood() - 3);
		}
		if (input == "Thrower" || input == "thrower") {
			board[place].push_back(new Thrower);
			setFood(getFood() - 4);
		}
		if (input == "Wall" || input == "wall") {
			board[place].push_back(new Wall);
			setFood(getFood() - 4);
			// cout << getFood() << endl;
		}
	}
}

/*Function: print board
Description: this will print the board
*/

void Player::printBoard(vector<vector<Insect*> > &board) {
	int size = 10;
	int temp = 0;
	for (int i = 0; i < board.size(); i++) {
		if (board[i].size() > temp) {
			temp = board[i].size();
		}
		else {
			continue;
		}
	}

	cout << "Food bank: " << getFood() << endl;
	cout << endl;
	for (int j = 0; j < temp; j++) {
		for (int i = 0; i < size; i++) {
			if ( j < board[i].size()) {
				if (i == size - 1) {
					cout << "| " << board[i][j]->getName() << ": " << board[i][j]->getArmor() << " |";
				}
				else {
					cout << "| " << board[i][j]->getName() << ": " << board[i][j]->getArmor() << "  ";
				}
			}
			else {
				if (i == size - 1) {
					cout << "|  " << " " << "  |";
				}
				else {
					cout << "|  " << " " << "  ";
				}
			}
		}
		cout << endl;
	}
}

/*Function: turn
Description: this function will run through the whole game and is called in main
*/

void Player::runGame(vector<vector<Insect*> > &board) {
	int numBees;
	bool end;
	for(int i = 0; i < 3; i++) {// do {
		addBee(board);
		printBoard(board);
		addAnt(board);
		turn(board);
		harvester(board);
		removeDead(board);
		// numBees = beeCounter(board);
		// end = endGame(board, numBees);
		// if(end == false)
		// 	break;
	}// } while (true);

	deleteBoard(board);
}

/*Function: add bee
description: this will add a bee to the board
*/

void Player::addBee(vector<vector<Insect*> > &board) {
	board[9].push_back(new Bee);
}


/*Function: turn
Description: this will run each turn for the ant or bee
*/

void Player::turn(vector<vector<Insect*> > &board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			board[i][j]->turn(board, i);
		}
	}
}

/*Function: harvester
Description: this will return 1 food to the food bank
*/

void Player::harvester(vector<vector<Insect*> > &board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); i++) {
			if (board[i][j]->getName() == "Harvester") {
				setFood(getFood() + 1);
			}
		}
	}
}

/*Function: remove dead
Description: this will remove the dead things off of the board
*/

void Player::removeDead(vector<vector<Insect*> > &board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j]->getArmor() == 0 || board[i][j]->getArmor() < 0) {
				delete [] board[i][j];
				board[i].erase(board[i].begin() + j);
			}
		}
	}
}

/*Function: delete board
Description: this will delete the vector
*/

void Player::deleteBoard(vector<vector<Insect*> > &board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			board.erase(board.begin() + i);
		}
	}
}

/*Function: bee counter
Description: this will tell if the game ends
*/

int Player::beeCounter(vector<vector<Insect*> > &board) {
	int numBees, temp;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j]->getName() == "Bee")
				temp++;
			numBees = temp;
		}
	}
	return numBees;
}

bool Player::endGame(vector<vector<Insect*> > &board, int numBees) {
	if (numBees == 0) {
		cout << "You won!!" << endl;
		return false;
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[0][j]->getName() == "Bee") {
				cout << "You lost!!" << endl;
				return false;
			}
		}
	}
	return true;
}

Player::Player() {
	this->food = 50;
}