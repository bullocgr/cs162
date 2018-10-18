#include "House.hpp"

using namespace std;

Tenants_other& House::get_tenants(int i) {return tenants[i];}

House::House() {
	this->num_tenants = 1;
	this->name = "House";
	this->property_val = ((rand()%500)+100)*100;
	this->rent = ((rand()%500) + 100);
	this->tenants = new Tenants_other[this->num_tenants];
	for (int i = 0; i < num_tenants; i++) {
		this->tenants[i] = Tenants_other();
	}
}

House::House(const House& copy) {
	this->num_tenants = copy.num_tenants;
	this->name = copy.name;
	this->property_val = copy.property_val;
	this->rent = copy.rent;
	for (int i = 0; i < this->num_tenants; i++) {
		this->tenants[i] = copy.tenants[i];
	}
}

House::~House() {
	if (tenants != NULL) delete [] tenants;
}