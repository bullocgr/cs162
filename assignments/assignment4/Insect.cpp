#include "Insect.hpp"

using namespace std;

void Insect::setArmor(int armor) {this->armor = armor;}
void Insect::setDamage(int damage) {this->damage = damage;}
void Insect::setFoodCost(int foodCost) {this->foodCost = foodCost;}
void Insect::setName(string name) {this->name = name;}

int Insect::getArmor() {return this->armor;}
int Insect::getDamage() {return this->damage;}
int Insect::getFoodCost() {return this->foodCost;}
string Insect::getName() {return this->name;}

void Insect::changeArmor(int x) {
	armor += x;
}


Insect::Insect() {
	this-> armor = 0;
	this-> damage = 0;
	this->foodCost = 0;
	this->name = "";
}



