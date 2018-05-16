#ifndef CLASS_HPP
#define CLASS_HPP
#include "Attributes.hpp"
#include "Tenants_other.hpp"

using namespace std;

class House:public Attributes {
private:
	int num_tenants;
	Tenants_other* tenants;

public:
	Tenants_other& get_tenants(int i);

	House();
	House(const House& copy);
	~House();
};

#endif