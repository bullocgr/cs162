#include "Apartment.hpp"

using namespace std;

//accessors
Tenants_other& Apartment::get_tenants(int i) {return tenants[i];}

Apartment::Apartment() {
	this->property_val = ((rand()%200)+400)*100;
	this->num_tenants = (rand()%7)+4;
	this->name = "Apartment";
	this->rent = ((rand()%500) + 100);
	this->tenants = new Tenants_other[this->num_tenants];
	for (int i = 0; i < num_tenants; i++) {
		this->tenants[i] = Tenants_other();
	}
}

Apartment::Apartment(const Apartment& copy) {
	this->property_val = copy.property_val;
	this->name = copy.name;
	this->num_tenants = copy.num_tenants;
	this->rent = copy.rent;
	for(int i = 0; i < this->num_tenants; i++) {
		this->tenants[i] = copy.tenants[i];
	}
}
Apartment::~Apartment() {
	if(tenants != NULL) delete [] tenants;
}