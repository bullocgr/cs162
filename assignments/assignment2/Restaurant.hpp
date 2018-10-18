#include <iostream>
#include <string>
#include <fstream>

#ifndef RESTAURANT_HEAD
#define RESTAURANT_HEAD

#include "Menu.hpp"
#include "Pizza.hpp"
#include "structs.hpp"
using namespace std;

class Restaurant {
private:
		Menu menu;
		employee* employees;
		hours* week;
		string name;
		string phone;
		string address;
		int num_days;
		int num_employees;

	public:
		void set_employees(employee* e) ;
		employee* get_employees();
		void set_hours(hours* w) ;
		hours* get_hours();
		void set_name(string n);
		string get_name();
		void set_phone(string p) ;
		string get_phone();
		void set_address(string a) ;
		string get_address();
		void set_num_days(int d);
		int get_num_days();
		void set_num_emp(int e);
		int get_num_emp();

		bool login(string id, string password);
		void read_in_emp(fstream& f);
		void view_menu();
		void view_hours();
		void view_address();
		void view_phone();
		void search_menu_by_price(); //i'm not doing this
		void search_menu_by_ingredients(); //i'm not doing this
		void place_order();
		void change_hours();
		void add_to_menu();
		void remove_from_menu();//not doing this
		void view_orders();
		void remove_orders();
		void load_data();
		int get_day(string input);
		bool is_int(string input);
		~Restaurant();
		Restaurant();
		Restaurant& operator=(Restaurant &copy);
		Restaurant(Restaurant &copy);
};

#endif