#ifndef BUSINESS_HPP
#define BUSINESS_HPP
#include "Attributes.hpp"
#include "Tenants_business.hpp"

using namespace std;

class Business:public Attributes {
private:
	Tenants_business* tenants;

public:
	//accessors
	Tenants_business& get_tenants(int i);

	Business();
	Business(const Business& copy);
	~Business();

};
#endif