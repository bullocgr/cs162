#include <stdlib.h>
#include <string.h>
#include "Attributes.hpp"

using namespace std;

//mutators
void Attributes::set_prop_val(float v) {property_val = v;}
void Attributes::set_name(string l) {name = l;}
void Attributes::set_mortgage(float m) {mortgage = m;}
void Attributes::set_rent(int r) {rent = r;}
void Attributes::set_num_tenants(int n) {num_tenants = n;}
void Attributes::set_owned(bool o) {owned = o;}

//accessors
float Attributes::get_prop_val() {return property_val;}
string Attributes::get_name() {return name;}
float Attributes::get_mortgage() {return mortgage;}
int Attributes::get_rent() {return rent;}
int Attributes::get_num_tenants() {return num_tenants;}
bool Attributes::get_owned() {return owned;}

//defalt constructor
Attributes::Attributes() {
	property_val = 0.0;
	name = "";
	mortgage = ((rand()%400)+10)*10;
	rent = 0;
	num_tenants = 0;
	owned = false;
}

//copy constructor
Attributes::Attributes(const Attributes& copy) {
	property_val = copy.property_val;
	name = copy.name;
	mortgage = copy.mortgage;
	rent = copy.rent;
	num_tenants = copy.num_tenants;
	owned = copy.owned;
}

//aoo
Attributes& Attributes::operator=(const Attributes& copy) {
	property_val = copy.property_val;
	name = copy.name;
	mortgage = copy.mortgage;
	rent = copy.rent;
	num_tenants = copy.num_tenants;
	owned = copy.owned;
	return *this;
}

