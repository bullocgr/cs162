#ifndef MENU_HEAD
#define MENU_HEAD

#include <iostream>

#include "Pizza.hpp"
#include "main.hpp"
#include "structs.hpp"

using namespace std;

class Menu {
private:
	int num_pizzas;
	int capacity_pizzas;
	Pizza * pizzas;
	order* arr;

public:
	void set_num_pizzas(int n);
	int get_num_pizzas();
	void load_data();
	void view_menu();
	void print_ingredients(int j);

	int get_size_cost(int i, string pizza_size);
	Menu search_pizza_by_cost(int upper_bound, string size);
	void remove_item(int j);
	// menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
	// menu search_pizza_by_ingredients_to_exlude(string* ingredients, int num_ingredients);
	void add_pizza_to_menu();
	void set_pizza_arr_size(int new_cap);
	order* place_order();
	// void remove_from_menu(int index_of_pizza_on_menu);
	Menu(Menu &copy);
	Menu& operator=(Menu& copy);
	Menu();
	~Menu();
};

#endif