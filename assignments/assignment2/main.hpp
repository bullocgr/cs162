#ifndef MAIN
#define MAIN

#include <fstream>
#include <stdlib.h>

#define MENUFILE "menu.txt"
#define EMPLOYEEFILE "employee.txt"
#define HOURS "restaurant.txt"
#define ORDERS "order.txt"

int num_lines(fstream & f);
void open_and_verify(fstream &f, string filename);


#endif