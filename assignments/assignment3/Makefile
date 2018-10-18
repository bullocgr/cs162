CC = g++ -g
exe_file = assign

$(exe_file): driver.o Attributes.o House.o Apartment.o Business.o Tenants_business.o Tenants_other.o driver_functions.o Player.o
	$(CC) driver.o Attributes.o House.o Apartment.o Business.o Tenants_business.o Tenants_other.o driver_functions.o Player.o -o $(exe_file)
Attributes.o: Attributes.cpp
	$(CC) -c Attributes.cpp
House.o: House.cpp
	$(CC) -c House.cpp
Apartment.o: Apartment.cpp
	$(CC) -c Apartment.cpp
Business.o: Business.cpp
	$(CC) -c Business.cpp
Tenants_business.o: Tenants_business.cpp
	$(CC) -c Tenants_business.cpp
Tenants_other.o: Tenants_other.cpp
	$(CC) -c Tenants_other.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
driver_functions.o: driver_functions.cpp
	$(CC) -c driver_functions.cpp
Player.o: Player.cpp
	$(CC) -c Player.cpp

clean:
	rm -f *.out *.o $(exe_file)
