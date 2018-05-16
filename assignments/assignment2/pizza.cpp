#include "Pizza.hpp"

using namespace std;


Pizza::Pizza(Pizza &copy) {
	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	for (int i = 0; i < num_ingredients; i++) {
		ingredients[i] = copy.ingredients[i];
	}
}

Pizza& Pizza::operator=(const Pizza& copy) {
	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	if (ingredients != NULL) delete [] ingredients;
	
	if(num_ingredients == 0) {
		ingredients = NULL;
	}

	else {
		ingredients = new string[this-> num_ingredients];
		for(int i = 0; i < num_ingredients; i++) {
			ingredients[i] = copy.ingredients[i];
		}
	}
	return *this;
}

//constructor
Pizza::Pizza() { //this is not working
	name = "Brad";
	small_cost = 0;
	medium_cost = 0;
	large_cost = 0;
	num_ingredients = 0;
	ingredients = NULL;

}

Pizza::~Pizza() {
	if (ingredients != NULL) delete [] ingredients;
}

//accessors
string Pizza::get_name() {
	return name;
}

int Pizza::get_small_cost() {
	return small_cost;
}

int Pizza::get_medium_cost() {
	return medium_cost;
}

int Pizza::get_large_cost() {
	return large_cost;
}

int Pizza::get_num_ingredients() {
	return num_ingredients;
}

string* Pizza::get_ingredients() {
	return ingredients;
}

//mutators
void Pizza::set_name(string n) {
	name = n;
}

void Pizza::set_small_cost(int x)  {
	small_cost = x;
}

void Pizza::set_medium_cost(int x) {
	medium_cost = x;
}

void Pizza::set_large_cost(int x) {
	large_cost = x;
}

void Pizza::set_num_ingredients(int x) {
	num_ingredients = x;
}

void Pizza::set_ingredients( int x) {
	this->ingredients = new string[x];
}

//end of the stuff

void Pizza::fill_ingredients_array(string* arr, int num) {
	for (int i = 0; i < num; i++) {
		this->ingredients[i] = arr[i];
	}
}

