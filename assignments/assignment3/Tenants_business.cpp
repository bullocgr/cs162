#include "Tenants_business.hpp"

using namespace std;

void Tenants_business::set_small(bool s){this->small = s;}
void Tenants_business::set_medium(bool m){this->medium = m;} 
void Tenants_business::set_large(bool l){this->large = l;}
void Tenants_business::set_budget(int b){this->budget = b;}

bool Tenants_business::get_small() {return small;}
bool Tenants_business::get_medium() {return medium;}
bool Tenants_business::get_large() {return large;}
int Tenants_business::get_budget() {return budget;}

Tenants_business::Tenants_business() {
	small = false;
	medium = false;
	large = false;
	this->budget = (((rand()%800)+200)*10);
}

Tenants_business::Tenants_business(const Tenants_business& copy) {
	small = copy.small;
	medium = copy.medium;
	large = copy.large;
	budget = copy.budget;
}