#include "Player.hpp"

using namespace std;

void Player::set_account(int a) {account = a;}
void Player::set_prop_owned(int p) {prop_owned = p;}

int Player::get_account() {return account;}
int Player::get_prop_owned() {return prop_owned;}
int Player::get_num_properties(){return num_properties;}

void Player::add_account(int money) {account += money;}

Player::Player() {
	account = 500000;
	prop_owned = 0;
	this->num_properties = 9;
}

Player::Player(const Player& copy) {
	account = copy.account;
	prop_owned =  copy.prop_owned;
	num_properties = copy.num_properties;
}