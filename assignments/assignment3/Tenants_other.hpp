#ifndef TENANTS_OTHER_HPP
#define TENANTS_OTHER_HPP
#include "Attributes.hpp"

using namespace std;

class Tenants_other{
private:
	bool in_house;
	bool in_apartment;
	int budget;

public:
	void set_in_house(bool x);
	void set_in_apartment(bool x);
	void set_budget(int r);

	bool get_in_house();
	bool get_in_apartment();
	int get_budget();

	Tenants_other();
	Tenants_other(const Tenants_other& copy);
};

#endif