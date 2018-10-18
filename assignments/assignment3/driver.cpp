#include "Attributes.hpp"
#include "driver.hpp"


#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	srand(time(NULL));

	Attributes** arr;

	Player p;
	arr = set_array(p.get_num_properties());
	turn(arr, p);

	for(int i = 0; i < p.get_num_properties(); i++) {
		delete arr[i];
	}
	delete [] arr;
}