#ifndef APARTMENT_HPP
#define APARTMENT_HPP

#include "Attributes.hpp"
#include "Tenants_other.hpp"

using namespace std;

class Apartment:public Attributes {
private:
	Tenants_other* tenants;

public:
	//accessor
	Tenants_other& get_tenants(int i);

	Apartment();
	Apartment(const Apartment& copy);
	~Apartment();

};

#endif