#include "header.h"
using namespace std;

int main(int argc, char** argv) {
	int rows = atoi(argv[1]);
	int cols = atoi(argv[2]);

	reprompt(rows, cols);

	math** table = create_table(rows, cols);

	set_mult(table, rows, cols);
	set_div(table, rows, cols);

	delete_arr(table, rows);
}

