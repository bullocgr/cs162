#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Attributes.hpp"
#include "driver.hpp"


using namespace std;

class Player {
private:
	int account;
	int prop_owned;
	int num_properties;

public:
	void set_account(int a);
	void set_prop_owned(int p);

	int get_account();
	int get_prop_owned();
	int get_num_properties();

	void add_account(int money);

	Player();
	Player(const Player& copy);
};

#endif