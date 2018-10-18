#include "Tenants_other.hpp"

using namespace std;

void Tenants_other::set_in_house(bool x) {this->in_house = x;}
void Tenants_other::set_in_apartment(bool x) {this->in_apartment = x;}
void Tenants_other::set_budget(int r) {this->budget = r;}

bool Tenants_other::get_in_house() {return in_house;}
bool Tenants_other::get_in_apartment() {return in_apartment;}
int Tenants_other::get_budget() {return budget;}

Tenants_other::Tenants_other() {
	in_house = false;
	in_apartment = false;
	this->budget = (((rand()%450)+50)*10);
}

Tenants_other::Tenants_other(const Tenants_other& copy) {
	this->in_house = copy.in_house;
	this->in_apartment = copy.in_apartment;
	this->budget = copy.budget;
}