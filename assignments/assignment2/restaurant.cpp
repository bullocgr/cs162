#include "Restaurant.hpp"


//a getter gets the number and returns the value or is an accessor
//a setter mutates the value
using namespace std;


Restaurant &Restaurant::operator=(Restaurant &copy) {
	delete [] employees;
	for (int i = 0; i < num_employees; i++) {
		employees[i] = copy.employees[i];
	}

	delete [] week;
	for (int i = 0; i < 7; i++) {
		week[i] = copy.week[i];
	}

	name = copy.name;
	phone = copy.phone;
	address = copy.address;
	num_days = copy.num_days;
	num_employees = copy.num_employees;
	return *this;
}

Restaurant::Restaurant() {
	employees = NULL;
	week = NULL;
	name = "No Name";
	phone = "No Number";
	address = "No Address";
	num_days = 0;
	num_employees = 0;
}

Restaurant::Restaurant(Restaurant &copy) {
	for (int i = 0; i < num_employees; i++) {
		employees[i] = copy.employees[i];
	}
	for (int i = 0; i < 7; i++) {
		week[i] = copy.week[i];
	}
	name = copy.name;
	phone = copy.phone;
	address = copy.address;
	num_days = copy.num_days;
	num_employees = copy.num_employees;
}


Restaurant::~Restaurant() {
	if (employees != NULL) delete[] employees;
	if (week != NULL) delete[] week;
}

//mutators
void Restaurant::set_hours(hours* w)  {
	week = w;
}

void Restaurant::set_name(string n)  {
	name = n;
}

void Restaurant::set_phone(string p)  {
	phone = p;
}

void Restaurant::set_address(string a)  {
	address = a;
}

void Restaurant::set_num_days(int d) {
	num_days = d;
}

void Restaurant::set_num_emp(int e) {
	num_employees = e;
}

//accessors
// void Restaurant::set_employees(employee* e)  {
// 	*employees = e;
// }

employee* Restaurant::get_employees() {
	return employees;
}

hours* Restaurant::get_hours() {
	return week;
}

string Restaurant::get_name() {
	return name;
}

string Restaurant::get_phone() {
	return phone;
}

string Restaurant::get_address() {
	return address;
}

int Restaurant::get_num_days() {
	return num_days;
}

int Restaurant::get_num_emp() {
	return num_employees;
}

//end of accessors and mutators

/*Function: view_menu
Description: this will allow everyone to view the menu
*/

void Restaurant::view_menu() {
	menu.view_menu();
}

void Restaurant::view_address() {
	cout << get_address() << endl;
}

void Restaurant::view_phone() {
	cout << get_phone() << endl;
}

void Restaurant::view_hours() {
	for (int i = 0; i < 7; i++) {
		cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << " " << endl;
	}
}

void Restaurant::read_in_emp(fstream& f) {
	for (int i = 0; i < num_employees; i++) {
		f >> employees[i].id >> employees[i].first_name >> employees[i].last_name >> employees[i].password;
	}
}

void Restaurant::load_data() {
	fstream f;
	open_and_verify(f, HOURS);
	getline(f, name);
	getline(f, phone);
	getline(f, address);
	f >> num_days;
	week = new hours[num_days];
	for (int i = 0; i < num_days; i++) {
		f >> week[i].day >> week[i].open_hour >> week[i].close_hour;
	}

	f.close();
	//this closes the file so that we can open a new one
	open_and_verify(f, EMPLOYEEFILE);
	this->num_employees = num_lines(f);
	employees = new employee[num_employees];
	read_in_emp(f);
	menu.load_data(); //this accesses the load data function from the menu class
}

bool Restaurant::login(string id, string password) {
	string input_id = "";
	string input_password = "";
	cout << "Id number: ";
	do {
		getline(cin, input_id);
		if (employees->id == input_id) {
			break;
		}
		cout << "Please enter a valid username: ";
	} while (true);

	cout << "Password: ";

	do {
		getline(cin, input_password);
		if (employees->password == input_password) {
			break;
		}
		cout << "Please enter a valid password: ";
	} while (true);

	return true;
}

void Restaurant::search_menu_by_price() {
	string size = "";
	string cost = "";
	int pizza_price;
	cout << "What size pizza would are you looking for: ";
	do {
		getline(cin, size);
		if (size == "small" || size == "medium" || size == "large")
			break;
		cout << "We don't seem to have that size.\nWhat size would you like: ";
	} while (true);
	cout << "What is the max price you want to pay: ";

	do {
		getline(cin, cost);
		if (is_int(cost) == true) {
			pizza_price = atoi(cost.c_str());
			break;
		}
	} while (true);
	cout << "sorry this doesn't work either" << endl;
	menu.search_pizza_by_cost(pizza_price, size);

}

bool Restaurant::is_int(string input) {
	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 48 && input[i] <= 57) {
			return true;
		}
	}
	return false;
}

void Restaurant::add_to_menu() {
	menu.add_pizza_to_menu();
}

void Restaurant::place_order() {
	menu.place_order();
}

void Restaurant::view_orders() {
	fstream f;
	f.open(ORDERS);
	order* arr = new order[256];
	for (int i = 0; i < num_lines(f); i++)
		f << arr[i].first_name << " " << arr[i].last_name << " " << arr[i].card << " " << arr[i].address << " " << arr[i].phone << " " << arr[i].pizza << endl;
	f.close();
}

void Restaurant::change_hours() {
	string input;
	string day;
	string open_hour;
	string close_hour;
	int index = 0;
	view_hours();
	cout << "Would you like to change the hours(yes or no): ";
	getline(cin, input);
	if (input == "yes") {
		cout << "What day would you like to change: ";
		getline(cin, day);
		get_day(day);
		cout << "when should we open: ";
		getline(cin, open_hour);
		week[index].open_hour = open_hour;
		cout << "When should we close: ";
		getline(cin, close_hour);
		week[index].close_hour = close_hour;
		return;
	}

	if (input == "no")
		return;
}

int Restaurant::get_day(string input) {
	int index = 0;
	for (int i = 0; i < num_days; i++) {
		if (week[i].day == input) {
			index = i;
		}
	}
	return index;
}