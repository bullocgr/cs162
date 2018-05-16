#ifndef TENANTS_BUSINESS_HPP
#define TENANTS_BUSINESS_HPP

#include "Attributes.hpp"

using namespace std;

class Tenants_business{
private:
	bool small;
	bool medium;
	bool large;
	int budget;

public:
	void set_small(bool s);
	void set_medium(bool m);
	void set_large(bool l);
	void set_budget(int b);

	bool get_small();
	bool get_medium();
	bool get_large();
	int get_budget();

	Tenants_business();
	Tenants_business(const Tenants_business& copy);
};

#endif