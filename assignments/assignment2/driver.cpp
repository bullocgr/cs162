#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "structs.hpp"
#include "main.hpp"
#include "Menu.hpp"
#include "Pizza.hpp"
#include "Restaurant.hpp"
#include "main.hpp"


int num_lines(fstream & f);
void open_and_verify(fstream &f, string filename);
void customer_or_employee(Restaurant& r);
int print_employee_options();
void employee_options(Restaurant& r);
int print_customer_options();
void customer_options(Restaurant& r);

int main() {
	Restaurant r;
	r.load_data();
	customer_or_employee(r);
}

int num_lines(fstream & f) {
	int count = 0;
	string temp;
	while (!f.eof()) {
		getline(f, temp);
		count ++;
	}

	f.clear();
	f.seekg(0, ios::beg); //this sets you to the beginning of the file
	return count;
}


void customer_or_employee(Restaurant& r) {
	string input;
	do {
		cout << "Please enter if you are an employee (E), a customer (C), or if you would like to exit (literally anything else): ";
		getline(cin, input);
		if (input == "E") {
			//run the login shit right here
			employee_options(r);
		}

		if (input == "C") {
			customer_options(r);
		}
		else {
			return;
		}
		cout << "Would you like to keep the program open (yes or no): ";
		getline(cin, input);
	} while (input == "yes");
}


void employee_options(Restaurant& r) {
	string id, password;
	r.login(id, password);
	int x = print_employee_options();
	if (x > 9) {
		cout << "You have been logged out" << endl;
	}
	switch (x) {
	case 1: r.change_hours();
		break;
	case 2: r.view_orders();
		break;
	case 3: cout << "This does not work" << endl;
		break;
	case 4: r.add_to_menu();
		break;
	case 5: cout << "this does not work" << endl;
		break;
	case 6: r.view_menu();
		break;
	case 7: r.view_hours();
		break;
	case 8: r.view_address();
		break;
	case 9: r.view_phone();
		break;
	}


}

void customer_options(Restaurant& r) {
	int x = print_customer_options();
	if (x > 7) {
		cout << "You have been logged out" << endl;
	}
	switch (x) {
	case 1: r.view_menu();
		break;
	case 2: r.search_menu_by_price();
		break;
	case 3: cout << "This does not work" << endl;
		break;
	case 4: r.place_order();
		break;
	case 5: r.view_hours();
		break;
	case 6: r.view_address();
		break;
	case 7: r.view_phone();
		break;
	}
}

/*Function: employee options
Description: this menu displays what each option are
*/

int print_employee_options() {
	string input;
	cout << "What would you like to do?" << endl;
	cout << "1. Change hours" << endl;
	cout << "2. View orders" << endl;
	cout << "3. Remove orders" << endl;
	cout << "4. Add item to menu" << endl;
	cout << "5. Remove item from menu" << endl;
	cout << "6. View menu" << endl;
	cout << "7. View hours" << endl;
	cout << "8. View address" << endl;
	cout << "9. View phone" << endl;
	cout << "10. Log out" << endl;
	getline(cin, input);
	int x = atoi(input.c_str());
	return x;
}

int print_customer_options() {
	string input;
	cout << "1. View menu" << endl;
	cout << "2. Search by cost" << endl;
	cout << "3. Search by ingredients" << endl;
	cout << "4. Place order" << endl;
	cout << "5. View hours" << endl;
	cout << "6. View address" << endl;
	cout << "7. View phone" << endl;
	cout << "8. Log out" << endl;
	getline(cin, input);
	int x = atoi(input.c_str());
	return x;
}


void open_and_verify(fstream &f, string file) {
	do {
		f.open(file.c_str());
		if (f.is_open()) {
			return;
		}
		cout << "Please enter a valid file name: ";
		getline(cin, file);
	} while (true);
}

