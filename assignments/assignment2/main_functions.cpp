#include "main.hpp"
#include <fstream>
#include <iostream>

int num_lines(fstream & f){
	int count = 0;
	string temp;
	while(!f.eof()){
		getline(f, temp);
		count ++;
	}
	f.clear();
	f.seekg(0, ios::beg); //this sets you to the beginning of the file
	return count;
}

void open_and_verify(fstream &f, string filename){
	do {
		f.open(filename);
		if(f.is_open()) {
			return;
		}
		cout << "Please enter a valid file name: ";
		getline(cin, filename);
	}while(true);
}

void customer_or_employee() {
	string input;
	cout << "Please enter if you are an employee (E), a customer (C), or if you would like to exit (literally anything else): ";
	getline(cin, input);
	if(input == "E") {
		//run the employee functions
	}
	if(input == "C") {
		//run the customer functions
	}
	else {
		return;
	}
}