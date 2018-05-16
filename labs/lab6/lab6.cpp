#include <iostream>
#include <string.h>

using namespace std;

int main() {
	string input;
	#ifdef DEBUG
	cout << "Hello world" << endl;
	#endif

	#ifdef DEBUG
	cout << "I think this is debugging" << endl;
	#endif

	#ifdef DEBUG
	cout << "Put in some input" << endl;
	#endif

	#ifdef DEBUG
	getline(cin, input);
	#endif

	#ifdef DEBUG
	cout << "Your input was: " << input << endl;
	#endif


}