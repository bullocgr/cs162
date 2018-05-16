#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct county {
	string name_county;
	string* city;
	int cities;
	int population_counties;
	float avg_income;
	float avg_house;
};

struct state {
	string name_state;
	struct county* c;
	int counties;
	int population_state;
};

state* create_states(int num);
void get_state_data(state * state_arr, int num, fstream & file);
county* create_counties(int x);
void get_county_data(county * county_arr, int x, fstream & file);
void largest_pop_state(state * state_arr, int num);
void largest_pop_county(state* state_arr, int num);
void order_state_pop(state* state_arr, int num);
void order_county_pop(state* state_arr, int num);
void income(state * state_arr, int num);
void state_order_name(state * state_arr, int num);
void county_order_name(state * state_arr, int num);
void avg_household_cost(state* state_arr, int num);
void operation(state* state_arr, int num);
string name_file(char** argv);
int states_num(char** argv);
void delete_info(state** state_arr, int num);