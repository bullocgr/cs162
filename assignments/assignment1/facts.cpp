#include "facts.h"

using namespace std;

/*Function: is_valid_argument
Description: this function will read in the command line argument and say whether or not it is an int if it is it will return true and convert it to an int
Parameters: read in command line and an int and return a bool
Pre-conditions: there must be a command line
Post-conditions: an int must be returned
*/

bool is_valid_argument(char** argv) {
	int length = 5;
	for (int i = 0; i < length; i++) {
		if (!strcmp(argv[i], "-f")) {
			for (int j = 0; j < length; j++) {
				if (!strcmp(argv[j], "-s")) {
					return true;
				}
			}
		}
		if (!strcmp(argv[i], "-s")) {
			for (int j = 0; j < length; j++) {
				if (!strcmp(argv[j], "-f")) {
					return true;
				}
			}
		}
	}
	cout << "Please run the program again." << endl;
	return false;
}

/*Function: name_file
Description: this makes it the name that the file will pass through
*/

string name_file(char** argv) {
	if(strcmp("-f", argv[1]) == 0) {
		return string(argv[2]);
	} else {
		return string(argv[4]);
	}
}

/*Description: this will read in the num and output the int
*/

int states_num(char** argv) {
	if (strcmp(argv[1], "-s") == 0) {
		return atoi(argv[2]);
	} else {
		return atoi(argv[4]);
	}
}

/*Function: create_states
Description: create an array of structs that will later be filled
Parameters: a number must be passed in in order to make an array of that size
Pre-conditions: must read in an int and there must be a struct
Post-conditions: an array of structs must be created
*/

state* create_states(int num) {
	state* state_arr = new state[num];
	return state_arr;
}

/*Function: get_state_data
Description: this will fill the array of x size with the data from each state in a separate file
Parameters: a file must be provided as well as a number in order to run
Pre-conditions: use info from another file and use an array from before
Post-conditions: the array must be filled with the info from each struct
*/

void get_state_data(state * state_arr, int num, fstream & file) {
	for (int i = 0; i < num; i++) {
		file >> state_arr[i].name_state;
		// cout << state_arr[i]. name_state << endl;
		file >> state_arr[i].population_state;
		// cout << state_arr[i].population_state << endl;
		file >> state_arr[i].counties;
		// cout << state_arr[i].counties << endl;
		state_arr[i].c = create_counties(state_arr[i].counties); //at the index we create a new array of shit that holds the county data
		get_county_data(state_arr[i].c, state_arr[i].counties, file); //this one fills the array with the data
	}

	// cout << endl;
}

/*Function: create_counties
Description: create an array of structs that will later be filled
Parameters: a number must be passed in in order to make an array of that size
Pre-conditions: must read in an int and there must be a struct
Post-conditions: an array of structs must be created
*/

county* create_counties(int x) {
	county* county_arr = new county[x];
	return county_arr;
}

/*Function: get_county_data
Description: this will fill the array of x size with the data from each state in a separate file
Parameters: a file must be provided as well as a number in order to run
Pre-conditions: use info from another file and use an array from before
Post-conditions: the array must be filled with the info from each struct
*/

void get_county_data(county * county_arr, int x, fstream & file) {
	for (int i = 0; i < x; i++) {
		file >> county_arr[i].name_county;
		// cout << county_arr[i].name_county << endl;
		file >> county_arr[i].population_counties;
		// cout << county_arr[i].population_counties << endl;
		file >> county_arr[i].avg_income;
		// cout << county_arr[i].avg_income << endl;
		file >> county_arr[i].avg_house;
		// cout << county_arr[i].avg_house << endl;
		file >> county_arr[i].cities;
		// cout << county_arr[i].cities << endl;

		county_arr[i].city = new string[county_arr[i].cities];
		for (int j = 0; j < county_arr[i].cities; j++) {
			file >> county_arr[i].city[j]; //loops through the city array and the one before goes through the county array
			// cout << county_arr[i].city[j] << endl;
		}
	}
}

/*Function: largest_pop
Description: this checks for the largest population and prints it to the screen
Parameters: the array must be passed through and the population must be compared
Pre-conditions: population and file must be open and in an array
Post-conditions: the array will be sorted
*/

void largest_pop_state(state * state_arr, int num) {
	int max_pop_state = 0;
	int index = 0;
	for (int i = 0; i < num; i++) {
		if (state_arr[i].population_state > max_pop_state) {
			max_pop_state = state_arr[i].population_state;
			index = i;
			cout << state_arr[i].name_state << " has the max state population with " << max_pop_state << " people." << endl;
		}

		
	}
}

void largest_pop_county(state* state_arr, int num) {
	int max_pop_county = 0;
	int index_county = 0;
	int index_state = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < state_arr[i].counties; j++) {
			if (state_arr[i].c[j].population_counties > max_pop_county) {
				max_pop_county = state_arr[i].c[j].population_counties;
				index_state = i;
				index_county = j;
				cout << state_arr[i].c[j].name_county << " has the max county popoulation with " << max_pop_county << " people." << endl;
			}

			
		}
	}
}

/*Function: order_state_pop
Description: this will put the states in order of population
*/

void order_state_pop(state* state_arr, int num) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (state_arr[j].population_state < state_arr[j + 1].population_state) {
				swap(state_arr[j], state_arr[j + 1]);
				cout << "The states ordered by population: " << state_arr[j].population_state << endl;
			}
		}
	}
}

/*Function: order_county_pop
descriptiion: this will put the counties in order by population
*/

void order_county_pop(state* state_arr, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < state_arr[i].counties - 1; j++) {
			for (int k = 0; k < state_arr[i].counties - j - 1; k++) {
				if (state_arr[i].c[k].population_counties < state_arr[i].c[k + 1].population_counties) {
					swap(state_arr[i].c[k], state_arr[i].c[k + 1]);
				}
			}
		}
	}
}

/*Function: income
Description:  this function will print out the counties with an income higher than what the user input
Parameters: must be counties and have a file
Pre-conditions: file must be open
Post-conditions: counties will print to the screen
*/

void income(state * state_arr, int num) {
	int income;
	cout << "Input an income: ";
	cin >> income;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < state_arr[i].counties; j++) {
			if (state_arr[i].c[j].avg_income >= income) {
				cout << state_arr[i].c[j].name_county << " has an income higher than the one you input.\nTheir income is " << state_arr[i].c[j].avg_income << endl;
			}
		}
	}
}

/*Function: state_order_name
Description:  this function will sort the states by name
Parameters: must be states and have a file
Pre-conditions: file must be open
Post-conditions: states will print to the screen sorted
*/

void state_order_name(state * state_arr, int num) {
	int temp = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (state_arr[j].name_state > state_arr[j + 1].name_state) {
				swap(state_arr[j], state_arr[j + 1]);
			}
		}
		cout << state_arr[i].name_state << endl;
	}
}

/*Function: county_order_name
Description:  this function will sort the counties by name
Parameters: must be counties and have a file
Pre-conditions: file must be open
Post-conditions: counties will print to the screen sorted
*/

void county_order_name(state * state_arr, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < state_arr[i].counties - 1; j++) {
			for (int k = 0; k < state_arr[i].counties - j - 1; k++) {
				if (state_arr[i].c[k].name_county > state_arr[i].c[k + 1].name_county) {
					swap(state_arr[i].c[k], state_arr[i].c[k + 1]);
				}
			}
			for (int j = 0; j < state_arr[i].counties; j++) {
				cout << state_arr[i].c[j].name_county << endl;
			}

		}
	}
}

/*Function: avg_household_cost
Description: this prints out the average household cost of each county in each state
Parameters: fild must be open
Pre-conditions: file must be open
Post-conditions: info will be printed out
I'm a little confused on what this function is supposed to do
*/

void avg_household_cost(state* state_arr, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < state_arr[i].counties; j++) {
			cout << "The average household cost for " << state_arr[i].c[j].name_county << " is " << state_arr[i].c[j].avg_house << endl;
		}
	}
}


/*Function: operation
Description: this will decide what the user chooses to display to the screen
Parameters: the argv must already be decided and the file name
Pre-conditions: the user will input what number they want
Post-conditions: the program will run based on their number
*/

void operation(state* state_arr, int num) {
	int option;
	cout << "which information would you like to display: " << endl;
	cout << "1: The state with the largest population\n2: The county with the largest population\n3. The counties with an income above a specific amount\n4. The average household cost for all counties in each state\n";
	cout << "5. The states sorted by name\n6. The states ordered by population\n7. The counties ordered by population\n8. The counties ordered by name\n";
	cin >> option;
	if (option == 1) {
		largest_pop_state(state_arr, num);
	}

	if (option == 2) {
		largest_pop_county(state_arr, num);
	}

	if (option == 3) {
		income(state_arr, num);
	}

	if (option == 4) {
		avg_household_cost(state_arr, num);
	}

	if (option == 5) {
		state_order_name(state_arr, num);
	}

	if (option == 6) {
		order_state_pop(state_arr, num);
	}

	if (option == 7) {
		order_county_pop(state_arr, num);
	}

	if (option == 8) {
		county_order_name(state_arr, num);
	}

	if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6 || option != 7 || option != 8) {
		cout << "You chose a wrong number." << endl;
	}
}

/*Function: delete info
*/

void delete_info(state** state_arr, int num) {
	if(state_arr == NULL) return;
	for(int i = 0; i < num; i++) {
		for(int j = 0; j < (*state_arr)[i].counties; j++) {
			delete[] (*state_arr)[i].c[j].city;
		}
		delete[] (*state_arr)[i].c;
	}
	delete[] (*state_arr);
	state_arr = NULL;
}