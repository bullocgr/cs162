#include "Ninja.hpp"

using namespace std;

void Ninja::setSeen(bool seen) {this->seen = seen;}

bool Ninja::getSeen() {return this->seen;}

Ninja::Ninja(){
	this->armor = 1;
	this->foodCost = 6;
	this->damage = 1;
	this->seen = false; //if this is true then the bee will attack the ninja although that can never happen
	this->name = "Ninja";
}