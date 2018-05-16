#include "Attributes.hpp"
#include "driver.hpp"

using namespace std;

/*Function: set_array
Description: this will create an array of different classes
Parameters: pass in the num of properties
Post-conditions: return the arr
*/

Attributes** set_array(const int& num_properties) {
	Attributes** arr =  new Attributes*[num_properties];
	for (int i = 0; i < num_properties; i++) {
		arr[i] = new House();
		arr[++i] = new Apartment();
		arr[++i] = new Business();
	}
	return arr;
}

/*Function: print properties
Description: this will print everything the board has to offer
*/

void print_properties(Attributes** arr, const int num_properties, bool care_about_ownership) {
	cout << "Care: " << care_about_ownership << " num prop " << num_properties << endl;
	if (care_about_ownership == true) {
		for (int i = 0; i < num_properties; i++) {
			if (arr[i]->get_owned()) { //Check if the property is owned
				cout << i << "Your property is a: " << arr[i]->get_name() << endl;
				cout << "\tThe value is: " << arr[i]->get_prop_val() << endl;
				cout << "\tThe rent is: " << arr[i]->get_rent() << endl;
				// cout << "\t"; get_rent(arr, arr[i]->get_rent(), p);
			}
		}
	}


	else if (care_about_ownership == false) {
		for (int i = 0; i < num_properties; i++) {
			cout << i << "Your property is a: " << arr[i]->get_name() << endl;
			cout << "\tThe value is: " << arr[i]->get_prop_val() << endl;
			cout << "\tThe rent is: " << arr[i]->get_rent() << endl;
			// cout << "\t"; get_rent(arr, arr[i]->get_rent(), p);
		}
	}

}




/*Function: get rent
Description: this will collect the rent from each of the complexes
*/

int get_rent(Attributes** arr, int rent, Player & p) {
	for (int i = 0; i < p.get_prop_owned(); i++) {
		if (arr[i]->get_owned() == true) {
			for (int j = 0; j < arr[i] -> get_num_tenants(); j++) {
				if (arr[i]->get_tenant_b(j).get_budget() >= arr[i]->get_rent())
					rent += arr[i]->get_rent();
			}
		}
	}
	cout << "THE RENT COLLECTED IS: " << rent << endl;
	return rent;
}

/*Function: buy property
Description: this will allow the user to buy properties
*/

void buy_prop(Attributes** arr, Player & p) {
	string input;
	string property;
	int prop1 = rand() % p.get_num_properties();
	int prop2 = rand() % p.get_num_properties();
	int prop3 = rand() % p.get_num_properties();

	cout << "These are the properties you can buy\n";
	cout << "1: "; print_properties(&(arr[prop1]), 1, false);
	cout << "2: "; print_properties(&(arr[prop2]), 1, false);
	cout << "3: "; print_properties(&(arr[prop3]), 1, false);

	cout << "Which property would you like to buy: ";
	getline(cin, property);
	if (property == "1")
		arr[prop1]->set_owned(true);
	if (property == "2")
		arr[prop2]->set_owned(true);
	if (property == "3")
		arr[prop3]->set_owned(true);


	for (int i = 0; i < p.get_num_properties(); i++) {
		if (arr[i]->get_owned() == true) {
			int prop_val = arr[i]->get_prop_val();
			p.add_account(-prop_val);
		}
	}
}


/*Function: turn
Description: this will keep track of the players turns
*/

void turn(Attributes** arr, Player & p) {
	int account;
	int rent;
	int prop_val;
	string input;
	do {
		cout << "You have " << p.get_account() << " in your account.\n";
		cout << "Would you like to buy or sell a property (or n for neither): ";
		getline(cin, input);
		if (input == "buy" || input == "b") {
			buy_prop(arr, p);
		}
		if (input == "sell" || input == "s") {
			sell_property(arr, p);
		}
		if (input == "n")
			continue;
		for (int i = 0; i < p.get_num_properties(); i++) {
			if (arr[i]->get_owned() == true) {
				prop_val = arr[i]->get_prop_val();
				rent = get_rent(arr, arr[i]->get_rent(), p);
			}
		}
		random_events(arr, p);
		p.add_account(rent);
		print_properties(arr, 9, true); //this isn't printing
		change_rent(arr, p);
	} while (p.get_account() != 0 && p.get_account() != 1000000);
}

/*Function: random events
Description: this will allow a random even to occur every turn
*/

void random_events(Attributes** arr, Player & p) {
	int event = rand() % 6;
	float temp = 0.0;
	if (event == 0) {
		cout << "A hurricane occured!! All property value is decreased by 50%\n";
		for (int i = 0; i < p.get_num_properties(); i++) {
			arr[i]->set_prop_val(arr[i]->get_prop_val() * 0.5);
			// cout << arr[i]->get_prop_val() << endl; //this prints out the new value
		}
	}

	if (event == 1) {
		cout << "A tornado occured!! All property value went down by 30%\n";
		for (int i = 0; i < p.get_num_properties(); i++) {
			arr[i]->set_prop_val(arr[i]->get_prop_val() * 0.3);
			// cout << arr[i]->get_prop_val() << endl;
		}
	}

	if (event == 2) {
		cout << "An earthquake happened!! All property value went down to 10%\n";
		for (int i = 0; i < p.get_num_properties(); i++) {
			arr[i]->set_prop_val(arr[i]->get_prop_val() * 0.1);
			// cout << arr[i]->get_prop_val() << endl;
		}
	}

	if (event == 3) {
		cout << "A wildfire!! All property decrease by 25%\n";
		for (int i = 0; i < p.get_num_properties(); i++) {
			arr[i]->set_prop_val(arr[i]->get_prop_val() * 0.25);
			// cout << arr[i]->get_prop_val() << endl;
		}
	}

	if (event == 4) {
		cout << "Stock market crash!! All property goes down by 30%\n";
		for (int i = 0; i < p.get_num_properties(); i++) {
			arr[i]->set_prop_val(arr[i]->get_prop_val() * 0.3);
			// cout << arr[i]->get_prop_val() << endl;
		}
	}

	if (event == 5) {
		cout << "You got lucky!! All property increase by 20%\n";
		for (int i = 0; i < p.get_num_properties(); i++) {
			arr[i]->set_prop_val(arr[i]->get_prop_val() / (.2));
			// cout << arr[i]->get_prop_val() << endl; //this prints out the new value
		}
	}
}

/*Function: change rent
Description: this will change the rent for one property
*/

void change_rent(Attributes** arr, Player & p) {
	string input;
	string change;
	string change_num;
	int property;
	int new_rent;
	cout << "Would you like to change rent(y/n)? ";
	getline(cin, input);
	if (input == "y" || input == "yes") {
		print_properties(arr, p.get_prop_owned(), true);
		cout << "Which property would you like to change the rent on: ";
		getline(cin, change);
		property = atoi(change.c_str()) - 1;
		cout << "What would you like to change the rent to: ";
		getline(cin, change_num);
		new_rent = atoi(change_num.c_str());
		for (int i = 0; i < arr[property]->get_num_tenants(); i++) {
			if (arr[property]->get_owned() == true) {
				arr[property]->set_rent(new_rent);
				tenant_leave(arr, p);
			}
		}
	}
}

void sell_property(Attributes** arr, Player& p) {
	string input;
	print_properties(arr, p.get_num_properties(), true);
	cout << "what property would you like to sell: ";
	getline(cin, input);
	int i = atoi(input.c_str());
	int money = arr[i]->get_prop_val();

	p.add_account(money);
	arr[i]->set_owned(false);
}

void tenant_leave(Attributes** arr, Player& p) {
	for (int i = 0; i < p.get_num_properties(); i++) {
		if (arr[i]->get_owned() == true) {
			for (int j = 0; j < p.get_num_properties(); j++) {
				if (arr[i]->get_rent() > arr[i]->get_tenant_b(j).get_budget() || arr[i]->get_rent() > arr[i]->get_tenant_o(j).get_budget())
					arr[i]->set_num_tenants(0);
			}
		}
	}
	cout << "OH NO!! Your tenant left!!" << endl;
}