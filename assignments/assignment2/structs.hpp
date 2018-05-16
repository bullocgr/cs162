#include <iostream>

#ifndef STRUCTS_HEADER
#define STRUCTS_HEADER

using namespace std;

struct employee {
	string id;
	string first_name;
	string last_name;
	string password;
};

struct hours {
	string day;
	string open_hour;
	string close_hour;
};

struct order {
	string first_name;
	string last_name;
	string card;
	string address;
	string phone;
	string pizza;
};

#endif