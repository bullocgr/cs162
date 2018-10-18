#include "facts.h"

using namespace std;

int main(int argc, char** argv) {
	fstream file;
	string user_file;
	user_file = name_file(argv);
	int num;
	num = states_num(argv);

	file.open(user_file.c_str());

	if (file.good()) {
		state* state_arr = create_states(num);
		get_state_data(state_arr, num, file);
		operation(state_arr, num);

		file.close();

		delete_info(&state_arr, num);
	}
	else {
		cout << "Error opening file." << endl;
	}
	return 0;
}

