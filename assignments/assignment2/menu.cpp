#include "Menu.hpp"
#include "structs.hpp"

using namespace std;

Menu::Menu() {
	this->num_pizzas = 0;
	this->capacity_pizzas = 0;
	this->pizzas = NULL;
}
Menu::~Menu() {
	if (pizzas != NULL) delete[] pizzas;
}

Menu::Menu(Menu& copy) {
	num_pizzas = copy.num_pizzas;
	for (int i = 0; i < num_pizzas; i++) {
		pizzas[i] = copy.pizzas[i];
	}
}

Menu& Menu::operator=(Menu& copy) {
	num_pizzas = copy.num_pizzas;
	if (pizzas != NULL)
		delete[] pizzas;
	if (num_pizzas == 0) {
		pizzas = NULL;
	}
	else {
		pizzas = new Pizza[num_pizzas];
		for (int i = 0; i < num_pizzas; i++) {
			pizzas[i] = copy.pizzas[i];
		}
	}

	return *this;
}
//accessors

int Menu::get_num_pizzas() {
	return num_pizzas;
}

//mutators
void Menu::set_num_pizzas(int n) {
	num_pizzas = n;
}

/*Function: load_data
Description: this reads in the data from a file
Parameters: N/A
Pre-conditions: don't pass in anything
Post-conditions: loads in data but doesn't return anything
*/

void Menu::load_data() {
	string name;
	int small, medium, large, num_ingredients;
	fstream f;
	open_and_verify(f, MENUFILE);
	//this clarifies that a certain variable is from the object you're working in
	this->num_pizzas = num_lines(f);
	this->capacity_pizzas = num_pizzas;
	this->pizzas = new Pizza[num_pizzas]; //this creates an array of classes
	for (int i = 0; i < this->num_pizzas; i++) {
		f >> name >> small >> medium >> large >> num_ingredients;
		pizzas[i].set_name(name); pizzas[i].set_small_cost(small);
		pizzas[i].set_medium_cost(medium); pizzas[i].set_large_cost(large);
		pizzas[i].set_num_ingredients(num_ingredients);
		string * arr = new string[num_ingredients];
		pizzas[i].set_ingredients(num_ingredients);

		for (int j = 0; j < num_ingredients; j++) {
			f >> arr[j];
		}

		pizzas[i].fill_ingredients_array(arr, num_ingredients);
		delete[] arr;
	}

}

/*Function: view_menu
Description: this will allow everyone to view the menu
*/

void Menu::view_menu() {
	for (int i = 0; i < num_pizzas; i++) {
		cout << pizzas[i].get_name() << " " << pizzas[i].get_small_cost() << " " << pizzas[i].get_medium_cost() << " " << pizzas[i].get_large_cost() << " " << pizzas[i].get_num_ingredients() << endl;
		print_ingredients(i);
	}

}

/*Function: print ingredients
Description: this will print out the ingredients
*/

void Menu::print_ingredients(int j) {
	string* arr = pizzas[j].get_ingredients();
	for (int i = 0; i < pizzas[j].get_num_ingredients(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}

/*Function: get size cost
Description: this will return the cost of the pizza they want
*/

int Menu::get_size_cost(int i, string pizza_size) {
	for (int i = 0; i < num_pizzas; i++) {
		if (pizza_size == "small")
			return pizzas[i].get_small_cost();
		if (pizza_size == "medium")
			return pizzas[i].get_medium_cost();
		if (pizza_size == "large")
			return pizzas[i].get_large_cost();
	}
}

/*Function: search pizza by cost
Description: this will allow the Restaurant class to access the pizza class array
*/

Menu Menu::search_pizza_by_cost(int upper_bound, string size) {
	Menu copy;
	copy = *this;
	for (int i = 0; i < this->num_pizzas; i++) {
		if (copy.get_size_cost(i, size) > upper_bound) { //this doesn't work
			cout << "i am here " << endl;
			copy.remove_item(i);
			i - 1;
		}
	}
	return copy;
}

void Menu::remove_item(int j) {
	for (int i = j; i < this->num_pizzas; i++) {
		if (i + 1 == num_pizzas) {
			continue;
		}
		else
			pizzas[i] = pizzas[i + 1];
	}
	num_pizzas--;
}

void Menu::add_pizza_to_menu() {
	Pizza p;
	string name = "";
	string price = "";
	string* ingredients;
	int num_ingredients, price_small, price_medium, price_large;
	cout << "What's the name of the new pizza: ";
	getline(cin, name);
	p.set_name(name);

	cout << "What's the price for a small: ";
	cin >> price_small;
	p.set_small_cost(price_small);

	cout << "What's the price for a medium: ";
	cin >> price_medium;
	p.set_medium_cost(price_medium);

	cout << "What's the price for a large: ";
	cin >> price_large;
	p.set_medium_cost(price_large);

	cout << "How many ingredients are there: ";
	cin >> num_ingredients;
	p.set_num_ingredients(num_ingredients);
	p.set_ingredients(num_ingredients);
	string* arr = new string[num_ingredients];
	string temp;
	getline(cin, temp);
	for (int i = 0; i < num_ingredients; i++) {
		cout << "Enter an ingredient: ";
		getline(cin, arr[i]);
	}

	p.fill_ingredients_array(arr, num_ingredients);
	//pizzas[num_pizzas-1] = p; //this is so that we have the length of the original array
	if (num_pizzas >= capacity_pizzas) {
		set_pizza_arr_size(num_pizzas * 2);
	}
	pizzas[num_pizzas] = p;
	num_pizzas++;
}


void Menu::set_pizza_arr_size(int new_cap) {
	Pizza* temp = new Pizza[new_cap];
	for (int i = 0; i < num_pizzas; i++) {
		temp[i] = pizzas[i];
	}
	delete[] pizzas;
	this->pizzas = temp;
	this->capacity_pizzas = new_cap;
}

order* Menu::place_order() {
	string first_name;
	string last_name;
	string card;
	string address;
	string phone;
	string pizza;
	fstream f;
	f.open(ORDERS);
	order* arr = new order[256];
	for (int i = 0; i < 1; i++) {
		cout << "What is your first name: ";
		getline(cin, first_name);
		arr[i].first_name;
		f << first_name << " ";
		cout << "What is your last name: ";
		getline(cin, last_name);
		arr[i].last_name;
		f << last_name << " ";
		cout << "Enter your card number: ";
		getline(cin, card);
		arr[i].card;
		f << card << " ";
		cout << "Enter your address: ";
		getline(cin, address);
		arr[i].address;
		f << address << " ";
		cout << "Enter your phone number: ";
		getline(cin, phone);
		arr[i].phone;
		f << phone << " ";
		cout << "What pizza would you like to order: ";
		getline(cin, pizza);
		arr[i].pizza;
		f << pizza << endl;
	}
	f.close();
	cout << "Your order has been placed." << endl;
}