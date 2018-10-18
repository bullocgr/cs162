#include <iostream>

#ifndef PIZZA_HEAD
#define PIZZA_HEAD

//this pizza class works
//use this to fix all the errors in the other function cpps

using namespace std;

class Pizza {
private:
	string name;
	int small_cost;
	int medium_cost;
	int large_cost;
	int num_ingredients;
	string* ingredients;

public:
	void set_name(string n);
	string get_name();

	void set_small_cost(int x);
	int get_small_cost();

	void set_medium_cost(int x);
	int get_medium_cost();

	void set_large_cost(int x);
	int get_large_cost();

	void set_num_ingredients(int x);
	int get_num_ingredients();

	void set_ingredients(int x);
	void input_ingredients(int index, string ingredient);
	string* get_ingredients();

	void fill_ingredients_array(string* arr, int num);


	Pizza();
	~Pizza();
	//destructor will delete the dynamic memory
	Pizza(Pizza &copy);
	Pizza& operator=(const Pizza& copy);
};

#endif