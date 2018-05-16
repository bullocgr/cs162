#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include "Tenants_business.hpp"
#include "Tenants_other.hpp"
#include <stdlib.h>
#include <string>

using namespace std;
class Tenants_business;
class Tenants_other;

class Attributes{
protected:
	float property_val;
	string name;
	float mortgage;
	int rent;
	static const float property_tax = 0.015; //always set at 1.5
	int num_tenants;
	bool owned;

public:
	//mutators
	void set_prop_val(float v);
	void set_name(string l);
	void set_mortgage(float m);
	void set_rent(int r);
	void set_num_tenants(int n);
	void set_owned(bool o);
	virtual Tenants_business& get_tenant_b(int i){};
	virtual Tenants_other& get_tenant_o(int i){};

	//accessors
	float get_prop_val();
	string get_name();
	float get_mortgage();
	int get_rent();
	int get_num_tenants();
	bool get_owned();

	//default constructor
	Attributes();

	//destructor
	virtual ~Attributes(){};

	//copy constructor
	Attributes(const Attributes& copy);

	//AOO
	Attributes& operator=(const Attributes& copy);
};
#endif