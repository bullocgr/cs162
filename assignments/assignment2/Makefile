CC = g++ -g
exe_file = assignment2

$(exe_file): menu.o pizza.o restaurant.o driver.o
	$(CC) menu.o pizza.o restaurant.o driver.o -o $(exe_file)
menu.o: menu.cpp
	$(CC) -c menu.cpp
pizza.o: pizza.cpp
	$(CC) -c pizza.cpp
restaurant.o: restaurant.cpp
	$(CC) -c restaurant.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o $(exe_file)