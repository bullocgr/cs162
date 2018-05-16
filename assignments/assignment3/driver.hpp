#ifndef DRIVER_HPP
#define DRIVER_HPP

class Player;
#include "Attributes.hpp"
#include "House.hpp"
#include "Apartment.hpp"
#include "Business.hpp"
#include "Tenants_business.hpp"
#include "Tenants_other.hpp"
#include "Player.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

Attributes** set_array(const int& num_properties);
void print_properties(Attributes** arr, const int num_properties, bool owned, Player& p);
int get_rent(Attributes** arr, int rent, Player& p);
void buy_prop(Attributes** arr, Player& p);
void turn(Attributes** arr, Player& p);
void random_events(Attributes** arr, Player& p);
void change_rent(Attributes** arr, Player& p);
void sell_property(Attributes** arr, Player& p);
void tenant_leave(Attributes** arr, Player& p);

#endif
