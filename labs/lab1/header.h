#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct math {
	int mult;
	float div;
};

bool check_zero(int num);
void reprompt(int rows, int cols);
math** create_table(int i, int j);
void set_mult(math** table, int rows, int cols);
void set_div(math** table, int rows, int cols);
void delete_arr(math** table, int rows);