#ifndef NINJA_HPP
#define NINJA_HPP

#include "Insect.hpp"

using namespace std;

class Ninja:public Insect{
private:
	bool seen;

public:
	void setSeen(bool seen);

	bool getSeen();

	Ninja();
};

#endif