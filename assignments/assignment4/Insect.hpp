#ifndef INSECT_HPP
#define INSECT_HPP
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Insect {
protected:
	int armor;
	int damage;
	int foodCost;
	string name;

public:
	void setArmor(int armor);
	void setDamage(int damage);
	void setFoodCost(int foodCost);
	void setName(string name);

	int getArmor();
	int getDamage();
	int getFoodCost();
	string getName();
	
	void changeArmor(int x);

	virtual void turn(vector<vector<Insect*> > &board, int x){};

	Insect();
	// virtual ~Insect();
	//operator overload

};

#endif