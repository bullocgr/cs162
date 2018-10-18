#include "Business.hpp"

using namespace std;

//accessors
Tenants_business& Business::get_tenants(int i) {return tenants[i];}

Business::Business() {
	this->num_tenants = (rand()%5)+1;
	this->name = "Business complex";
	this->property_val = ((rand()%200)+400)*100;
	this->rent = (((rand()%800)+200)*10);
	this->tenants = new Tenants_business[this->num_tenants];
	for(int i = 0; i < num_tenants; i++) {
		this->tenants[i] = Tenants_business();
	}
}

Business::Business(const Business& copy) {
	this->num_tenants = copy.num_tenants;
	this->name = copy.name;
	this->property_val = copy.property_val;
	this->rent = copy.rent;
	for(int i = 0; i < num_tenants; i++) {
		tenants[i] = copy.tenants[i];
	}
}

Business::~Business() {
	if(tenants != NULL) delete [] tenants;
}