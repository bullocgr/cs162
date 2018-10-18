#include "header.h"
using namespace std;

bool check_zero(int num) {
	if (num == 0)
		return false;
	return true;
}

void reprompt(int rows, int cols) {
	do {
		if (check_zero(rows) == true) {
			break;
		}
		cout << "Please input a valid row: ";
		cin >> rows;
	} while (true);

	do {
		if (check_zero(cols) == true) {
			break;
		}
		cout << "Please input a valid col: ";
		cin >> cols;
	} while (true);
}

// making the array of structs
math** create_table(int rows, int cols) {
	math** table = new math* [rows];
	for (int i = 0; i < cols; i++) {
		table[i] = new math[cols];
	}

	return table;
}

void set_mult(math** table, int rows, int cols) {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			table[i][j].mult = (i+1) * (j+1);
			cout << table[i][j].mult << " ";
		}

		cout << endl;
	}
}

void set_div(math** table, int rows, int cols) {
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++) {
			table[i][j].div = (i+1.0) / (j+1.0);
			cout << table[i][j].div << " ";
		}

		cout << endl;
	}
}

void delete_arr(math** table, int rows) {
	for(int i = 0; i < rows; i++)
		delete[] table[i];
	delete[] table;
}